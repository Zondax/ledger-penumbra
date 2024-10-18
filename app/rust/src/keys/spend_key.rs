use crate::utils::prf::expand_fr::expand_ff;
use crate::ParserError;

use decaf377_rdsa::SigningKey;
use decaf377_rdsa::{SpendAuth, VerificationKey};
use zeroize::{Zeroize, ZeroizeOnDrop};

use super::dk::DiversifierKey;
use super::signing_key::Sk;
use super::{nk, FullViewingKey, Ivk};

/// The Signing key
#[repr(C)]
#[derive(Clone)]
pub struct SpendKey {
    seed: SpendKeyBytes,
    ask: SigningKey<SpendAuth>,
    fvk: FullViewingKey,
}

impl SpendKey {
    /// Takes ownership of the spend_key_bytes
    pub fn derive_from(seed: SpendKeyBytes) -> Result<Self, ParserError> {
        let ask = SigningKey::new_from_field(expand_ff(b"Penumbra_ExpndSd", &seed.0, &[0; 1])?);
        let fvk = seed.fvk()?;
        Ok(Self { seed, ask, fvk })
    }
}

/// The raw keep generated by the device.
/// raw data is comming from C, it is not kept
/// in memory and gets zeroized after use.
#[repr(C)]
#[derive(Debug, Clone, Zeroize, ZeroizeOnDrop)]
pub struct SpendKeyBytes([u8; SpendKeyBytes::LEN]);

impl SpendKeyBytes {
    pub const LEN: usize = 32;
}

impl From<[u8; Self::LEN]> for SpendKeyBytes {
    fn from(bytes: [u8; Self::LEN]) -> SpendKeyBytes {
        SpendKeyBytes(bytes)
    }
}

impl TryFrom<&[u8]> for SpendKeyBytes {
    type Error = ParserError;

    fn try_from(bytes: &[u8]) -> Result<Self, Self::Error> {
        if bytes.len() == Self::LEN {
            let mut bytes32 = [0u8; Self::LEN];
            bytes32.copy_from_slice(bytes);
            Ok(Self::from(bytes32))
        } else {
            Err(ParserError::InvalidLength)
        }
    }
}

impl SpendKeyBytes {
    /// Returns a full signing key composed of ask and ak
    pub fn signing_key(&self) -> Result<Sk, ParserError> {
        Sk::derive_from(self)
    }

    /// Returns a verification key(ak)
    /// using default domain `SpendAuth`
    pub fn verification_key(&self) -> Result<VerificationKey<SpendAuth>, ParserError> {
        // error should not happen as len is right
        let ask = SigningKey::new_from_field(expand_ff(b"Penumbra_ExpndSd", &self.0, &[0; 1])?);
        let vk: VerificationKey<SpendAuth> = ask.into();
        Ok(vk)
    }

    pub fn key_bytes(&self) -> &[u8; Self::LEN] {
        &self.0
    }

    /// Returns the full viewing key
    pub fn fvk(&self) -> Result<FullViewingKey, ParserError> {
        self.try_into()
    }

    pub fn diversifier_key(&self) -> Result<DiversifierKey, ParserError> {
        DiversifierKey::derive_from(self)
    }

    pub fn nullifier_key(&self) -> Result<nk::NullifierKey, ParserError> {
        nk::NullifierKey::derive_from(self)
    }

    pub fn ivk(&self) -> Result<Ivk, ParserError> {
        Ivk::derive_from(self)
    }

    pub fn spend_key(self) -> Result<SpendKey, ParserError> {
        SpendKey::derive_from(self)
    }
}
