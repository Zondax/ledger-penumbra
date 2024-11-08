use decaf377::{Element, Fq};

pub struct Commitment(pub Element);

impl Commitment {
    pub fn value_blinding_generator() -> decaf377::Element {
        let s = Fq::from_le_bytes_mod_order(blake2b_simd::blake2b(b"decaf377-rdsa-binding").as_bytes());
        decaf377::Element::encode_to_curve(&s)
    }
}
