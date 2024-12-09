#include "note.h"

#include "constants.h"
#include "known_assets.h"
#include "tx_metadata.h"
#include "ui_utils.h"
#include "zxformat.h"

parser_error_t printValue(const parser_context_t *ctx, const value_t *value, const bytes_t *chain_id, char *outVal, uint16_t outValLen) {
    if (ctx == NULL || value == NULL || outVal == NULL || chain_id == NULL) {
        return parser_no_data;
    }

    if (outValLen < VALUE_DISPLAY_MAX_LEN) {
        return parser_unexpected_buffer_end;
    }

    MEMZERO(outVal, outValLen);

    char amount_str[U128_STR_MAX_LEN] = {0};

    // convert to string note.amount
    CHECK_ERROR(uint128_to_str(amount_str, U128_STR_MAX_LEN, value->amount.hi, value->amount.lo))

    // lookup at asset table
    uint8_t chain_id_local[100] = {0};
    MEMCPY(chain_id_local, chain_id->ptr, chain_id->len);
    const asset_info_t *known_asset = NULL;
    if (chain_id->ptr != NULL && chain_id->len != 0) {
        known_asset = asset_info_from_table(chain_id_local);
    }

    // There are three cases:
    // Case 1: Known assets (decimal + space + symbol)
    // Case 2: Base denom (integer + space + denom) taken from transaction
    // Case 3: Bech32 fallback (integer + space + bech32 of asset_id)
    // where asset_id is unknown and not metadata was provided for it

    // Case 1: Known assets
    if (known_asset != NULL) {
        uint8_t decimals = (uint8_t)known_asset->decimals;
        uint8_t err = fpstr_to_str(outVal, outValLen, amount_str, decimals);
        // Check we are not out of bounds
        if (err != 0) {
            return parser_unexpected_buffer_end;
        }
        size_t fpstr_len = strlen(outVal);
        // copy space
        outVal[fpstr_len] = ' ';
        // now copy symbol
        snprintf(outVal + fpstr_len + 1, outValLen - fpstr_len - 1, "%s", known_asset->symbol);

        return parser_ok;
    }

    // Case 2: Base denom (integer + space + denom) taken from transaction
    // for this we use the parser_context_t to access the transaction metadata
    // if not found, we default to case 3
    char denom[MAX_DENOM_LEN + 1] = {0};

    uint8_t trace_len = 0;
    if (value->asset_id.inner.ptr != NULL && value->asset_id.inner.len != 0) {
        trace_len = metadata_getDenom(&ctx->tx_metadata[0], MAX_TX_METADATA_LEN, &value->asset_id.inner, denom, MAX_DENOM_LEN + 1);
    }

    if (trace_len != 0) {
        // We found denom trace in provided transaction metadata
        int written = snprintf(outVal, outValLen - 1, "%s", amount_str);
        if (written < 0 || written >= outValLen - 1) {
            return parser_unexpected_buffer_end;
        }

        // Space
        outVal[written] = ' ';
        written += 1;
        // check we have space for denomination path
        if (written + trace_len >= outValLen - 1) {
            return parser_unexpected_buffer_end;
        }

        MEMCPY(&outVal[written], denom, trace_len);
        written += trace_len;
        outVal[written] = '\0';

        return parser_ok;
    }

    // Case 3: Bech32 fallback (integer + space + bech32 of asset_id)
    int written = snprintf(outVal, outValLen - 1, "%s", amount_str);
    if (written < 0 || written >= outValLen - 1) {
        return parser_unexpected_buffer_end;
    }
    // Space
    outVal[written] = ' ';
    written += 1;

    bytes_t asset_id_local = {0};
    if (value->asset_id.inner.ptr != NULL && value->asset_id.inner.len != 0) {
        asset_id_local = value->asset_id.inner;
    } else {
        static const uint8_t default_asset_id[ASSET_ID_LEN] = STAKING_TOKEN_ASSET_ID_BYTES;
        asset_id_local.ptr = default_asset_id;
        asset_id_local.len = ASSET_ID_LEN;
    }

    CHECK_ERROR(printAssetId(asset_id_local.ptr, asset_id_local.len, outVal + written, outValLen - written - 1));

    return parser_ok;
}
