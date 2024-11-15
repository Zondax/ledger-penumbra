use crate::effect_hash::{create_personalized_state, EffectHash};
use crate::keys::FullViewingKey;
use crate::parser::{
    bytes::BytesC,
    note::{Note, NoteC},
    commitment::Commitment,
    nullifier::Nullifier,
    value::{Sign, Value},
};
use crate::ParserError;
use decaf377::Fr;
use decaf377_rdsa::{SpendAuth, VerificationKey};

pub struct Body {
    pub balance_commitment: Commitment,
    pub nullifier: Nullifier,
    pub rk: VerificationKey<SpendAuth>,
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

            state.update(&body.balance_commitment.to_proto_spend());

            state.update(&[0x22, 0x22, 0x0a, 0x20]);
            state.update(&body.rk.to_bytes());

            state.update(&body.nullifier.to_proto());

            let hash = state.finalize();
            Ok(EffectHash(*hash.as_array()))
        } else {
            Err(ParserError::InvalidLength)
        }
    }

    pub fn body(&self, fvk: &FullViewingKey) -> Result<Body, ParserError> {
        Ok(Body {
            balance_commitment: self
                .balance()?
                .commit(self.get_value_blinding_fr()?, Sign::Provided)?,
            nullifier: self.nullifier(fvk)?,
            rk: self.rk(fvk)?,
        })
    }

    pub fn balance(&self) -> Result<Value, ParserError> {
        // We should return a Balance struct here, but since we are currently managing only one value, it isn’t necessary for now
        let value = Value::try_from(self.note.value.clone())?;
        Ok(value)
    }

    pub fn nullifier(&self, fvk: &FullViewingKey) -> Result<Nullifier, ParserError> {
        let nk = fvk.nullifier_key();
        let note = Note::try_from(self.note.clone())?;
        let nullifier = Nullifier::derive(&nk, self.position, &note.commit()?.0);
        Ok(nullifier)
    }

    pub fn rk(&self, fvk: &FullViewingKey) -> Result<VerificationKey<SpendAuth>, ParserError> {
        Ok(fvk
            .spend_verification_key()
            .randomize(&self.get_randomizer_fr()?))
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
