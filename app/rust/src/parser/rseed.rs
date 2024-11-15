use decaf377::{Fq, Fr};
use crate::{ParserError, utils::prf};
use crate::parser::bytes::BytesC;
use crate::keys::ka;
use crate::constants::RSEED_LEN_BYTES;
pub struct Rseed(pub [u8; 32]);

impl Rseed {
    pub const LEN: usize = RSEED_LEN_BYTES;

    /// Derive the ephemeral secret key from the rseed.
    pub fn derive_esk(&self) ->  Result<ka::Secret, ParserError> {
        let hash_result = prf::expand(b"Penumbra_DeriEsk", &self.0, &[4u8])?;
        Ok( ka::Secret::new_from_field(Fr::from_le_bytes_mod_order(&hash_result)))
    }

    /// Derive note commitment randomness from the rseed.
    pub fn derive_note_blinding(&self) -> Result<Fq, ParserError> {
        let hash_result = prf::expand(b"Penumbra_DeriRcm", &self.0, &[5u8])?;
        Ok(Fq::from_le_bytes_mod_order(&hash_result))
    }

    pub fn to_bytes(&self) -> Result<[u8; Self::LEN], ParserError> {
        let mut bytes = [0; Self::LEN];
        bytes.copy_from_slice(&self.0);
        Ok(bytes)
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
