use crate::{keys::spend_key::SpendKeyBytes, zxerror::ZxErr};

extern "C" {
    pub fn crypto_getSpendKeyBytes(sk: *mut u8, len: u16) -> ZxErr;
}

pub fn c_spend_key_bytes() -> Result<SpendKeyBytes, ZxErr> {
    unsafe {
        let mut skb = [0u8; SpendKeyBytes::LEN];
        let err = crypto_getSpendKeyBytes(skb.as_mut_ptr(), skb.len() as u16);
        match err {
            ZxErr::Ok => Ok(SpendKeyBytes::from(skb)),
            _ => Err(err),
        }
    }
}
