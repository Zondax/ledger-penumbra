use crate::constants::ID_LEN_BYTES;

use crate::parser::id::ASSET_ID_PERSONAL;
use crate::parser::BytesC;
use crate::utils::prf::expand_fq;
use crate::ParserError;

/// Retrieves the asset ID from the provided metadata.
///
/// # Safety
///
/// This function is `unsafe` because it dereferences raw pointers.
///
/// # Parameters
///
/// - `data`: Reference to `BytesC` containing the metadata.
/// - `out`: Mutable pointer to the output buffer for the asset ID.
/// - `out_len`: Length of the output buffer; must be equal to `ID_LEN_BYTES`.
///
/// # Returns
///
/// A `u32` representing a `ParserError` code.
#[no_mangle]
pub unsafe extern "C" fn rs_get_asset_id_from_metadata(
    data: &BytesC,
    out: *mut u8,
    out_len: u16,
) -> u32 {
    if out_len as usize != ID_LEN_BYTES {
        return ParserError::InvalidLength as u32;
    }
    // let id = Id(Fq::from_le_bytes_mod_order(
    //     // XXX choice of hash function?
    //     blake2b_simd::Params::default()
    //         .personal(b"Penumbra_AssetID")
    //         .hash(base_denom.as_bytes())
    //         .as_bytes(),
    // ));
    let out = core::slice::from_raw_parts_mut(out, out_len as _);
    let s = core::slice::from_raw_parts(data.ptr, data.len as _);

    let Ok(denom) = core::str::from_utf8(s) else {
        return ParserError::InvalidTypeId as u32;
    };
    let Ok(fq) = expand_fq::expand_ff(ASSET_ID_PERSONAL, &[], denom.as_bytes()) else {
        return ParserError::InvalidTypeId as u32;
    };

    out.copy_from_slice(&fq.to_bytes());

    ParserError::Ok as u32
}
