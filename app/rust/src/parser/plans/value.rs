use crate::parser::{
    plans::amount::{Amount, AmountC},
    plans::commitment::Commitment,
    plans::id::{Id, IdC},
    ParserError,
};
use decaf377::Fr;

#[derive(Clone, Debug)]
pub struct Value {
    pub amount: Amount,
    // The asset ID. 256 bits.
    pub asset_id: Id,
}

impl Value {
    // this should be implemented in the Balance, but since we are currently managing only one value, it isn’t necessary for now
    pub fn commit(&self, blinding_factor: Fr) -> Result<[u8; 32], ParserError> {
        let mut commitment = decaf377::Element::IDENTITY;
        let g_v = self.asset_id.value_generator();
        let amount_fr: Fr = Into::into(self.amount.clone());
        commitment += g_v * amount_fr;

        let value_blinding_generator = Commitment::value_blinding_generator();
        commitment += blinding_factor * value_blinding_generator;

        let mut balance_commitment = [0u8; 32];
        balance_commitment.copy_from_slice(&commitment.vartime_compress().0);

        Ok(balance_commitment)
    }
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct ValueC {
    pub amount: AmountC,
    pub asset_id: IdC,
}

impl TryFrom<ValueC> for Value {
    type Error = ParserError;

    fn try_from(value: ValueC) -> Result<Self, Self::Error> {
        Ok(Value {
            amount: value.amount.try_into()?,
            asset_id: value.asset_id.try_into()?,
        })
    }
}
