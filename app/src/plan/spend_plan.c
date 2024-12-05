/*******************************************************************************
 *  (c) 2018 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include "parser_impl.h"
#include "parser_interface.h"
#include "parser_pb_utils.h"
#include "pb_common.h"
#include "pb_decode.h"
#include "protobuf/penumbra/core/transaction/v1/transaction.pb.h"
#include "zxformat.h"
#include "known_assets.h"
#include "note.h"
#include "crypto_helper.h"
#include "ui_utils.h"

parser_error_t decode_spend_plan(const bytes_t *data, spend_plan_t *output) {
    penumbra_core_component_shielded_pool_v1_SpendPlan spend_plan =
        penumbra_core_component_shielded_pool_v1_SpendPlan_init_default;

    pb_istream_t spend_stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t randomizer_arg, value_blinding_arg, proof_blinding_r_arg, proof_blinding_s_arg;

    setup_decode_fixed_field(&spend_plan.randomizer, &randomizer_arg, &output->randomizer, 32);
    setup_decode_fixed_field(&spend_plan.value_blinding, &value_blinding_arg, &output->value_blinding, 32);
    setup_decode_fixed_field(&spend_plan.proof_blinding_r, &proof_blinding_r_arg, &output->proof_blinding_r, 32);
    setup_decode_fixed_field(&spend_plan.proof_blinding_s, &proof_blinding_s_arg, &output->proof_blinding_s, 32);

    // inner in address
    fixed_size_field_t address_inner_arg;
    setup_decode_fixed_field(&spend_plan.note.address.inner, &address_inner_arg, &output->note.address.inner, 80);

    // asset_id in Note
    fixed_size_field_t asset_id_arg;
    setup_decode_fixed_field(&spend_plan.note.value.asset_id.inner, &asset_id_arg, &output->note.value.asset_id.inner,
                             ASSET_ID_LEN);
    // rseed in Note
    fixed_size_field_t rseed_arg;
    setup_decode_fixed_field(&spend_plan.note.rseed, &rseed_arg, &output->note.rseed, RSEED_LEN);

    if (!pb_decode(&spend_stream, penumbra_core_component_shielded_pool_v1_SpendPlan_fields, &spend_plan)) {
        return parser_spend_plan_error;
    }

    output->note.value.amount.lo = spend_plan.note.value.amount.lo;
    output->note.value.amount.hi = spend_plan.note.value.amount.hi;
    output->position = spend_plan.position;

    return parser_ok;
}

parser_error_t spend_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
    UNUSED(ctx);
    // from spends we display only two items:
    // - Spend 100 USDC
    // - From Main Account
    *num_items = 2;
    return parser_ok;
}

parser_error_t spend_getItem(const parser_context_t *ctx, const spend_plan_t *spend,
                             uint8_t displayIdx, char *outKey, uint16_t outKeyLen,
                             char *outVal, uint16_t outValLen, uint8_t pageIdx,
                             uint8_t *pageCount) {

    parser_error_t err = parser_no_data;
    if (spend == NULL || outKey == NULL || outVal == NULL || outKeyLen == 0 || outValLen == 0) {
        return err;
    }

    zxerr_t error = zxerr_invalid_crypto_settings;
    keys_t keys = {0};

    switch ( displayIdx ) {
        case 0:
            snprintf(outKey, outKeyLen, "Spend");
            char value[VALUE_DISPLAY_MAX_LEN] = {0};
            CHECK_ERROR(printValue(ctx, &spend->note.value, value, VALUE_DISPLAY_MAX_LEN));

            pageString(outVal, outValLen, value, pageIdx, pageCount);

            return parser_ok;
        case 1:
            snprintf(outKey, outKeyLen, "From");
            // Worse scenario where address is not controlled by the user
            char addr_ui[ENCODED_ADDR_LEN] = {0};
            uint8_t randomizer[ADDR_RANDOMIZER_LEN] = {0};
            if (ctx->address_index.has_randomizer) {
                MEMCPY(randomizer, ctx->address_index.randomizer, ADDR_RANDOMIZER_LEN);
            }

            CATCH_ZX_ERROR(compute_keys(&keys));
            CATCH_ZX_ERROR(compute_address(&keys, ctx->address_index.account, randomizer));

            // compare the addresses
            if (MEMCMP(keys.address, spend->note.address.inner.ptr, ADDRESS_LEN_BYTES) == 0 ) {
                if (ctx->address_index.account == 0) {
                    snprintf(outVal, outValLen, "Main-Account");
                } else {
                    // We can use %d, because account is an uint32_t
                    // otherwise u64_to_str or any other alternative
                    // must be used
                    snprintf(addr_ui, ENCODED_ADDR_LEN, "Sub-Account %d", ctx->address_index.account);
                    pageString(outVal, outValLen, addr_ui, pageIdx, pageCount);
                }
            } else {
                // render encoded address in shorter form
                if (printShortAddress(&keys.address[0], ADDRESS_LEN_BYTES, addr_ui, ENCODED_ADDR_LEN) != parser_ok) {
                    MEMZERO(&keys, sizeof(keys));
                    return parser_no_data;
                }
                pageString(outVal, outValLen, addr_ui, pageIdx, pageCount);
            }
            return parser_ok;
        default:
            return parser_no_data;
    }

catch_zx_error:
    MEMZERO(&keys, sizeof(keys));

    return parser_no_data;
}
