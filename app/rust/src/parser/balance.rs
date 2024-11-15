use std::num::NonZeroU128;
use crate::ParserError;
use crate::parser::id::Id;
use crate::parser::value::Value;

// Define a constant for the maximum number of assets
const MAX_ASSETS: usize = 10;

pub struct Balance {
    negated: bool,
    ids: [Id; MAX_ASSETS],
    balances: [NonZeroU128; MAX_ASSETS],
}

impl TryFrom<Value> for Balance {
    type Error = ParserError;

    fn try_from(value: Value) -> Result<Self, Self::Error> {
        let negated = false;
        let mut ids = core::array::from_fn(|_| Id::default());
        ids[0] = value.asset_id;

        let balances = core::array::from_fn(|_| NonZeroU128::new(value.amount.inner).unwrap());

        Ok(Balance { negated, ids, balances })
    }
}

