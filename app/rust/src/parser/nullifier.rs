use decaf377::Fq;
use poseidon377::hash_3;
use crate::keys::nk::NullifierKey;
pub struct Nullifier(pub Fq);

impl Nullifier {
    pub const LEN: usize = 32; 
    pub const PROTO_LEN: usize = Self::LEN + 4;

    /// Derive the [`Nullifier`] for a positioned note or swap given its [`merkle::Position`]
    /// and [`Commitment`].
    pub fn derive(
        nk: &NullifierKey,
        pos: u64,
        state_commitment: &Fq,
    ) -> Nullifier {
        Nullifier(hash_3(
            &Self::nullifier_domain_sep(),
            (nk.0, *state_commitment, (u64::from(pos)).into()),
        ))
    }

    fn nullifier_domain_sep() -> Fq {
        Fq::from_le_bytes_mod_order(blake2b_simd::blake2b(b"penumbra.nullifier").as_bytes())
    }

    pub fn to_proto(&self) -> [u8; Self::PROTO_LEN] {
        let mut proto = [0u8; Self::PROTO_LEN];
        proto[0..4].copy_from_slice(&[0x32, 0x22, 0x0a, 0x20]);
        proto[4..].copy_from_slice(&self.0.to_bytes());
        proto
    }
}
