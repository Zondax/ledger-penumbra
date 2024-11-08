use crate::parser::bytes::BytesC;
use crate::ParserError;
use decaf377::Fq;
#[derive(Clone, Debug)]
pub struct Id(pub Fq);

impl Id {
    /// Compute the value generator for this asset, used for computing balance commitments.
    pub fn value_generator(&self) -> decaf377::Element {
        decaf377::Element::encode_to_curve(&poseidon377::hash_1(
            &Self::value_generator_domain_sep(),
            self.0,
        ))
    }

    pub fn value_generator_domain_sep() -> Fq {
        Fq::from_le_bytes_mod_order(blake2b_simd::blake2b(b"penumbra.value.generator").as_bytes())
    }
}

impl Default for Id {
    fn default() -> Self {
        Id(Fq::default())
    }
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct IdC {
    pub inner: BytesC,
}
impl IdC {
    pub fn get_inner(&self) -> Result<&[u8], ParserError> {
        self.inner.get_bytes()
    }
}

impl TryFrom<IdC> for Id {
    type Error = ParserError;

    fn try_from(value: IdC) -> Result<Self, Self::Error> {
        let inner = value.get_inner()?;
        Ok(Id {
            0: Fq::from_le_bytes_mod_order(inner),
        })
    }
}
