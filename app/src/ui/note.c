#include "parser_common.h"
#include "zxformat.h"
#include "known_assets.h"
#include "note.h"
#include "constants.h"
#include "ui_utils.h"

parser_error_t printValue(const parser_context_t *ctx, const value_t *value,
                          char *outVal, uint16_t outValLen) {

    parser_error_t err = parser_no_data;

    if (ctx == NULL || value == NULL || outVal == NULL ) {
        return err;
    }

    if (outValLen < VALUE_DISPLAY_MAX_LEN) {
        return parser_unexpected_buffer_end;
    }

    MEMZERO(outVal, outValLen);

    char amount_str[U128_STR_MAX_LEN] = {0};

    // convert to string note.amount
    CHECK_ERROR(uint128_to_str(amount_str, U128_STR_MAX_LEN, value->amount.hi, value->amount.lo))

    // lookup at asset table
    const asset_info_t *known_asset = asset_info_from_table(value->asset_id.inner.ptr);

    // There are three cases:
    // Case 1: Known assets (decimal + space + symbol)
    // Case 2: Base denom (integer + space + denom) taken from transaction
    // Case 3: Bech32 fallback (integer + space + bech32 of asset_id)
    // where asset_id is unknown and not metadata was provided for it

    // Case 1: Known assets
    if (known_asset != NULL) {
        uint8_t decimals = (uint8_t)known_asset->decimals;
        uint8_t fpstr_len = fpstr_to_str(outVal, outValLen, amount_str, decimals);
        // Check we are not out of bounds
        if (fpstr_len > VALUE_DISPLAY_MAX_LEN - 1) {
            return parser_unexpected_buffer_end;
        }
        // copy space
        outVal[fpstr_len] = ' ';
        // now copy symbol
        snprintf(outVal + fpstr_len + 1, outValLen - fpstr_len - 1, "%s", known_asset->symbol);

        return parser_ok;
    }

    // TODO: Case 2: Base denom (integer + space + denom) taken from transaction
    // for this we use the parser_context_t to access the transaction metadata
    // here it is likely we need to call rust to compute the asset id
    // and check it matches spend.note.asset_id, otherwise a fallback(case3) is used



    // Case 3: Bech32 fallback (integer + space + bech32 of asset_id)
    int written = snprintf(outVal, outValLen - 1, "%s", amount_str);
    if (written < 0 || written >= outValLen - 1) {
        return parser_unexpected_buffer_end;
    }
    // Space
    outVal[written] = ' ';

    CHECK_ERROR(printAssetId(value->asset_id.inner.ptr, value->asset_id.inner.len, outVal + written + 1, outValLen - written - 1));

    return err;
}
