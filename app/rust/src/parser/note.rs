use crate::address::Address;
use crate::parser::{
    address::AddressC,
    bytes::BytesC,
    plans::{rseed::Rseed, value::{Value, ValueC}},
};
use crate::ParserError;
use decaf377::Fq;

pub struct Note {
    /// The typed value recorded by this note.
    value: Value,
    /// A uniformly random 32-byte sequence used to derive an ephemeral secret key
    /// and note blinding factor.
    rseed: Rseed,
    /// The address controlling this note.
    address: Address,
    /// The s-component of the transmission key of the destination address.
    /// We store this separately to ensure that every `Note` is constructed
    /// with a valid transmission key (the `ka::Public` does not validate
    /// the curve point until it is used, since validation is not free).
    transmission_key_s: Fq,
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct NoteC {
    pub value: ValueC,
    pub rseed: BytesC,
    pub address: AddressC,
}

impl TryFrom<NoteC> for Note {
    type Error = ParserError;

    fn try_from(note_c: NoteC) -> Result<Self, Self::Error> {
        let value = Value::try_from(note_c.value)?;
        let rseed = Rseed::try_from(note_c.rseed)?;
        let address = Address::try_from(note_c.address.inner.get_bytes()?)?;
        let transmission_key_s = Fq::from_bytes_checked(&address.transmission_key().0).map_err(|_| ParserError::InvalidFvk).unwrap();
    
        Ok(Note {
            value,
            rseed,
            address,
            transmission_key_s,
        })
    }
}

impl Note {
    pub fn commit(&self) -> Result<Fq, ParserError> {
        let commit = poseidon377::hash_6(
            &Self::notecommit_domain_sep(),
            (
                self.note_blinding()?,
                self.value.amount.clone().into(),
                self.value.asset_id.0,
                self.diversified_generator()?,
                self.transmission_key_s,
                self.clue_key()?,
            ),
        );
        Ok(commit)
    }

    pub fn note_blinding(&self) -> Result<Fq, ParserError> {
        let rseed = self.rseed.derive_note_blinding()?;
        Ok(rseed)
    }

    pub fn diversified_generator(&self) -> Result<Fq, ParserError> {
        let diversifier_generator = self.address.diversifier().diversified_generator().vartime_compress_to_field();
        Ok(diversifier_generator)
    }

    pub fn clue_key(&self) -> Result<Fq, ParserError> {
        let clue_key = self.address.clue_key();
        Ok(Fq::from_le_bytes_mod_order(&clue_key.0[..]))
    }

    pub fn notecommit_domain_sep() -> Fq {
        Fq::from_le_bytes_mod_order(blake2b_simd::blake2b(b"penumbra.notecommit").as_bytes())
    }
}
