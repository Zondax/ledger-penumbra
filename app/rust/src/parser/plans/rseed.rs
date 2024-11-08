use decaf377::Fq;
use crate::{ParserError, utils::prf};
use crate::parser::bytes::BytesC;

pub struct Rseed(pub [u8; 32]);

impl Rseed {
    /// Derive note commitment randomness from the rseed.
    pub fn derive_note_blinding(&self) -> Result<Fq, ParserError> {
        let hash_result = prf::expand(b"Penumbra_DeriRcm", &self.0, &[5u8])?;
        Ok(Fq::from_le_bytes_mod_order(&hash_result))
    }
}

impl TryFrom<BytesC> for Rseed {
    type Error = ParserError;

    fn try_from(value: BytesC) -> Result<Self, Self::Error> {
        assert_eq!(value.len, 32, "Invalid rseed length");
        let mut rseed = [0u8; 32];
        rseed.copy_from_slice(value.get_bytes()?);
        Ok(Rseed(rseed))
    }
}
