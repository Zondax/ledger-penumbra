use crate::effect_hash::{create_personalized_state, EffectHash};
use crate::keys::FullViewingKey;
use crate::parser::{
    bytes::BytesC,
    note::{Note, NoteC},
    plans::{nullifier::Nullifier, value::Value},
};
use crate::ParserError;
use decaf377::{Fq, Fr};

// proto:
// message SpendPlan {
//   // The plaintext note we plan to spend.
//   Note note = 1;
//   // The position of the note we plan to spend.
//   uint64 position = 2;
//   // The randomizer to use for the spend.
//   bytes randomizer = 3;
//   // The blinding factor to use for the value commitment.
//   bytes value_blinding = 4;
//   // The first blinding factor to use for the ZK spend proof.
//   bytes proof_blinding_r = 5;
//   // The second blinding factor to use for the ZK spend proof.
//   bytes proof_blinding_s = 6;
// }
#[cfg_attr(test, derive(Debug))]
#[derive(Copy, PartialEq, Eq, Clone)]
// pub struct SpendPlan<'a> {
//     pub note: Note<'a>,
//     pub position: Position,
//     pub randomizer: Fr<'a>,
//     pub value_blinding: Fr<'a>,
//     pub proof_blinding_r: Fq<'a>,
//     pub proof_blinding_s: Fq<'a>,
// }

// impl<'b> FromBytes<'b> for SpendPlan<'b> {
//     fn from_bytes_into(
//         input: &'b [u8],
//         out: &mut MaybeUninit<Self>,
//     ) -> Result<&'b [u8], nom::Err<ParserError>> {
//         let output = out.as_mut_ptr();

//         // Parsing each field sequentially
//         // Parse `note`
//         let note = unsafe { &mut *addr_of_mut!((*output).note).cast() };
//         let input = Note::from_bytes_into(input, note)?;

//         // Parse `position`
//         let position = unsafe { &mut *addr_of_mut!((*output).position).cast() };
//         let input = Position::from_bytes_into(input, position)?;

//         // Parse `randomizer`
//         let randomizer = unsafe { &mut *addr_of_mut!((*output).randomizer).cast() };
//         let input = Fr::from_bytes_into(input, randomizer)?;

//         // Parse `value_blinding`
//         let value = unsafe { &mut *addr_of_mut!((*output).value_blinding).cast() };
//         let input = Fr::from_bytes_into(input, value)?;

//         // Parse `proof_blinding_r`
//         let proof = unsafe { &mut *addr_of_mut!((*output).proof_blinding_r).cast() };
//         let input = Fq::from_bytes_into(input, proof)?;

//         // Parse `proof_blinding_s`
//         let proof = unsafe { &mut *addr_of_mut!((*output).proof_blinding_s).cast() };
//         let input = Fq::from_bytes_into(input, proof)?;

//         Ok(input)
//     }
// }

pub struct Body {
    pub balance_commitment: [u8; 32],
    pub nullifier: [u8; 32],
    pub rk: [u8; 32],
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct SpendPlanC {
    pub note: NoteC,
    pub position: u64,
    pub randomizer: BytesC,
    pub value_blinding: BytesC,
    pub proof_blinding_r: BytesC,
    pub proof_blinding_s: BytesC,
}

impl SpendPlanC {
    pub fn effect_hash(&self, fvk: &FullViewingKey) -> Result<EffectHash, ParserError> {
        let body = self.body(fvk);

        if let Ok(body) = body {
            let mut state =
                create_personalized_state("/penumbra.core.component.shielded_pool.v1.SpendBody");

            let mut proto_header = [0x0a, 0x22, 0x0a, 0x20];
            state.update(&proto_header);
            state.update(&body.balance_commitment);

            proto_header[0] = 0x22;
            state.update(&proto_header);
            state.update(&body.rk);

            proto_header[0] = 0x32;
            state.update(&proto_header);
            state.update(&body.nullifier);

            let hash = state.finalize();
            Ok(EffectHash(*hash.as_array()))
        } else {
            Err(ParserError::InvalidLength)
        }
    }

    pub fn body(&self, fvk: &FullViewingKey) -> Result<Body, ParserError> {
        let value = self.balance()?;
        let balance_commitment = value.commit(self.get_value_blinding_fr()?)?;

        Ok(Body {
            balance_commitment,
            nullifier: self.nullifier(fvk)?,
            rk: self.rk(fvk)?,
        })
    }

    pub fn balance(&self) -> Result<Value, ParserError> {
        // We should return a Balance struct here, but since we are currently managing only one value, it isn’t necessary for now
        let value = Value::try_from(self.note.value.clone())?;
        Ok(value)
    }

    pub fn nullifier(&self, fvk: &FullViewingKey) -> Result<[u8; 32], ParserError> {
        let nk = fvk.nullifier_key();
        let note = Note::try_from(self.note.clone())?;
        let nullifier = Nullifier::derive(&nk, self.position, &note.commit()?);
        Ok(nullifier.0.to_bytes())
    }

    pub fn rk(&self, fvk: &FullViewingKey) -> Result<[u8; 32], ParserError> {
        let randomizer_fr = self.get_randomizer_fr()?;
        let rk_bytes = fvk
            .spend_verification_key()
            .randomize(&randomizer_fr)
            .to_bytes();
        Ok(rk_bytes.try_into().expect("Expected 32 bytes for rk"))
    }

    pub fn get_randomizer(&self) -> Result<&[u8], ParserError> {
        self.randomizer.get_bytes()
    }

    pub fn get_randomizer_fr(&self) -> Result<Fr, ParserError> {
        let randomizer_bytes = self.get_randomizer()?;
        Ok(Fr::from_le_bytes_mod_order(randomizer_bytes))
    }

    pub fn get_value_blinding(&self) -> Result<&[u8], ParserError> {
        self.value_blinding.get_bytes()
    }

    pub fn get_value_blinding_fr(&self) -> Result<Fr, ParserError> {
        let value_blinding_bytes = self.get_value_blinding()?;
        Ok(Fr::from_le_bytes_mod_order(value_blinding_bytes))
    }
}
