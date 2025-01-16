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
#include "note.h"
#include "output.h"
#include "parser_pb_utils.h"
#include "ui_utils.h"
#include "zxformat.h"

parser_error_t decode_position_open_plan(const bytes_t *data, position_open_plan_t *position_open) {
    penumbra_core_component_dex_v1_PositionOpen position_open_pb = penumbra_core_component_dex_v1_PositionOpen_init_default;

    pb_istream_t stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t nonce_arg, pair_asset_1, pair_asset_2;

    setup_decode_fixed_field(&position_open_pb.position.nonce, &nonce_arg, &position_open->position.nonce, 32);
    setup_decode_fixed_field((pb_callback_t*)&position_open_pb.position.phi.pair.asset_1, &pair_asset_1,
                             &position_open->position.phi.pair.asset_1, ASSET_ID_LEN);
    setup_decode_fixed_field((pb_callback_t*)&position_open_pb.position.phi.pair.asset_2, &pair_asset_2,
                             &position_open->position.phi.pair.asset_2, ASSET_ID_LEN);

    if (!pb_decode(&stream, penumbra_core_component_dex_v1_PositionOpen_fields, &position_open_pb)) {
        return parser_output_plan_error;
    }

    position_open->has_position = position_open_pb.has_position;
    if (position_open_pb.has_position) {
        position_open->position.has_phi = position_open_pb.position.has_phi;
        if (position_open_pb.position.has_phi) {
            position_open->position.phi.has_component = position_open_pb.position.phi.has_component;
            if (position_open_pb.position.phi.has_component) {
                position_open->position.phi.component.fee = position_open_pb.position.phi.component.fee;
                position_open->position.phi.component.has_p = position_open_pb.position.phi.component.has_p;
                if (position_open_pb.position.phi.component.has_p) {
                    position_open->position.phi.component.p.hi = position_open_pb.position.phi.component.p.hi;
                    position_open->position.phi.component.p.lo = position_open_pb.position.phi.component.p.lo;
                }
                position_open->position.phi.component.has_q = position_open_pb.position.phi.component.has_q;
                if (position_open_pb.position.phi.component.has_q) {
                    position_open->position.phi.component.q.hi = position_open_pb.position.phi.component.q.hi;
                    position_open->position.phi.component.q.lo = position_open_pb.position.phi.component.q.lo;
                }
            }
            position_open->position.phi.has_pair = position_open_pb.position.phi.has_pair;
            if (position_open_pb.position.phi.has_pair) {
                position_open->position.phi.pair.has_asset_1 = position_open_pb.position.phi.pair.has_asset_1;
                position_open->position.phi.pair.has_asset_2 = position_open_pb.position.phi.pair.has_asset_2;
            }
        }

        position_open->position.has_state = position_open_pb.position.has_state;
        if (position_open_pb.position.has_state) {
            position_open->position.state.state = (position_state_enum_t)position_open_pb.position.state.state;
            position_open->position.state.sequence = position_open_pb.position.state.sequence;
        }

        position_open->position.has_reserves = position_open_pb.position.has_reserves;
        if (position_open_pb.position.has_reserves) {
            position_open->position.reserves.has_r1 = position_open_pb.position.reserves.has_r1;
            if (position_open_pb.position.reserves.has_r1) {
                position_open->position.reserves.r1.hi = position_open_pb.position.reserves.r1.hi;
                position_open->position.reserves.r1.lo = position_open_pb.position.reserves.r1.lo;
            }
            position_open->position.reserves.has_r2 = position_open_pb.position.reserves.has_r2;
            if (position_open_pb.position.reserves.has_r2) {
                position_open->position.reserves.r2.hi = position_open_pb.position.reserves.r2.hi;
                position_open->position.reserves.r2.lo = position_open_pb.position.reserves.r2.lo;
            }
        }

        position_open->position.close_on_fill = position_open_pb.position.close_on_fill;
    }

    return parser_ok;
}

// parser_error_t position_open_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
//     UNUSED(ctx);
//     // from spends we display only two items:
//     // - Output 100 USDC
//     // - To Main Account
//     *num_items = 1;
//     return parser_ok;
// }

// parser_error_t position_open_getItem(const parser_context_t *ctx, const position_open_t *output, uint8_t actionIdx, char
// *outKey,
//                               uint16_t outKeyLen, char *outVal, uint16_t outValLen, uint8_t pageIdx, uint8_t *pageCount) {
//     parser_error_t err = parser_no_data;
//     if (output == NULL || outKey == NULL || outVal == NULL || outKeyLen == 0 || outValLen == 0) {
//         return err;
//     }

//     char bufferUI[OUTPUT_DISPLAY_MAX_LEN] = {0};

//     snprintf(outKey, outKeyLen, "Action_%d", actionIdx);
//     CHECK_ERROR(output_printValue(ctx, output, bufferUI, sizeof(bufferUI)));
//     pageString(outVal, outValLen, bufferUI, pageIdx, pageCount);

//     return parser_ok;
// }

// parser_error_t position_open_printValue(const parser_context_t *ctx, const position_open_t *output, char *outVal,
//                                  uint16_t outValLen) {
//     if (ctx == NULL || output == NULL || outVal == NULL) {
//         return parser_no_data;
//     }

//     if (outValLen < OUTPUT_DISPLAY_MAX_LEN) {
//         return parser_unexpected_buffer_end;
//     }

//     MEMZERO(outVal, outValLen);

//     // example: Output 100 USDC to penumbra1k0zzug62gpz60sejdvu9q7mq…

//     // add action title
//     snprintf(outVal, outValLen, "Output ");
//     uint16_t written_value = strlen(outVal);

//     // add value
//     CHECK_ERROR(printValue(ctx, &output->value, &ctx->tx_obj->parameters_plan.chain_id, outVal + written_value,
//                            outValLen - written_value));
//     written_value = strlen(outVal);

//     // add "to"
//     snprintf(outVal + written_value, outValLen - written_value, " to ");
//     written_value = strlen(outVal);

//     // add address
//     CHECK_ERROR(printTxAddress(&output->dest_address.inner, outVal + written_value, outValLen - written_value));

//     return parser_ok;
// }
