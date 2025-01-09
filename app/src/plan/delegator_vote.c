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

#include "delegator_vote.h"

#include "note.h"
#include "parser_pb_utils.h"
#include "rslib.h"
#include "ui_utils.h"
#include "zxformat.h"

parser_error_t decode_delegator_vote_plan(const bytes_t *data, delegator_vote_plan_t *delegator_vote) {
    penumbra_core_component_governance_v1_DelegatorVotePlan delegator_vote_plan = penumbra_core_component_governance_v1_DelegatorVotePlan_init_default;

    pb_istream_t spend_stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t randomizer_arg, value_blinding_arg, proof_blinding_r_arg, proof_blinding_s_arg;
    setup_decode_fixed_field(&delegator_vote_plan.randomizer, &randomizer_arg, &delegator_vote->randomizer, 32);
    setup_decode_fixed_field(&delegator_vote_plan.proof_blinding_r, &proof_blinding_r_arg, &delegator_vote->proof_blinding_r, 32);
    setup_decode_fixed_field(&delegator_vote_plan.proof_blinding_s, &proof_blinding_s_arg, &delegator_vote->proof_blinding_s, 32);

    // staked_note
    fixed_size_field_t address_inner_arg, asset_id_arg, rseed_arg;
    setup_decode_fixed_field(&delegator_vote_plan.staked_note.address.inner, &address_inner_arg, &delegator_vote->staked_note.address.inner, 80);
    setup_decode_fixed_field(&delegator_vote_plan.staked_note.value.asset_id.inner, &asset_id_arg, &delegator_vote->staked_note.value.asset_id.inner, ASSET_ID_LEN);
    setup_decode_fixed_field(&delegator_vote_plan.staked_note.rseed, &rseed_arg, &delegator_vote->staked_note.rseed, RSEED_LEN);

    if (!pb_decode(&spend_stream, penumbra_core_component_governance_v1_DelegatorVotePlan_fields, &delegator_vote_plan)) {
        return parser_delegate_plan_error;
    }

    delegator_vote->proposal = delegator_vote_plan.proposal;
    delegator_vote->start_position = delegator_vote_plan.start_position;
    delegator_vote->has_vote = delegator_vote_plan.has_vote;
    if (delegator_vote_plan.has_vote) {
        delegator_vote->vote = delegator_vote_plan.vote.vote;
    }
    delegator_vote->has_staked_note = delegator_vote_plan.has_staked_note;
    if (delegator_vote_plan.has_staked_note) {
        delegator_vote->staked_note.has_value = delegator_vote_plan.staked_note.has_value;
        if (delegator_vote_plan.staked_note.has_value) {
            delegator_vote->staked_note.value.has_amount = delegator_vote_plan.staked_note.value.has_amount;
            if (delegator_vote_plan.staked_note.value.has_amount) {
                delegator_vote->staked_note.value.amount.lo = delegator_vote_plan.staked_note.value.amount.lo;
                delegator_vote->staked_note.value.amount.hi = delegator_vote_plan.staked_note.value.amount.hi;
            }
            delegator_vote->staked_note.value.has_asset_id = delegator_vote_plan.staked_note.value.has_asset_id;
        }
        delegator_vote->staked_note.has_address = delegator_vote_plan.staked_note.has_address;
    }

    delegator_vote->staked_note_position = delegator_vote_plan.staked_note_position;

    delegator_vote->has_unbonded_amount = delegator_vote_plan.has_unbonded_amount;
    if (delegator_vote_plan.has_unbonded_amount) {
        delegator_vote->unbonded_amount.lo = delegator_vote_plan.unbonded_amount.lo;
        delegator_vote->unbonded_amount.hi = delegator_vote_plan.unbonded_amount.hi;
    }

    return parser_ok;
}

// parser_error_t delegate_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
//     UNUSED(ctx);
//     *num_items = 1;
//     return parser_ok;
// }

// parser_error_t delegate_getItem(const parser_context_t *ctx, const delegate_plan_t *delegate, uint8_t actionIdx, char *outKey,
//                                uint16_t outKeyLen, char *outVal, uint16_t outValLen, uint8_t pageIdx, uint8_t *pageCount) {
//     parser_error_t err = parser_no_data;
//     if (delegate == NULL || outKey == NULL || outVal == NULL || outKeyLen == 0 || outValLen == 0) {
//         return err;
//     }

//     char bufferUI[DELEGATE_DISPLAY_MAX_LEN] = {0};

//     snprintf(outKey, outKeyLen, "Action_%d", actionIdx);
//     CHECK_ERROR(delegate_printValue(ctx, delegate, bufferUI, sizeof(bufferUI)));
//     pageString(outVal, outValLen, bufferUI, pageIdx, pageCount);

//     return parser_ok;
// }

// parser_error_t delegate_printValue(const parser_context_t *ctx, const delegate_plan_t *delegate, char *outVal,
//                                    uint16_t outValLen) {
//     if (ctx == NULL || delegate == NULL || outVal == NULL) {
//         return parser_no_data;
//     }

//     if (outValLen < DELEGATE_DISPLAY_MAX_LEN) {
//         return parser_unexpected_buffer_end;
//     }

//     MEMZERO(outVal, outValLen);

//     // add action title
//     snprintf(outVal, outValLen, "Delegate To ");
//     uint16_t written_value = strlen(outVal);

//     // add validator identity
//     CHECK_ERROR(encodeIdentityKey(delegate->validator_identity.ik.ptr, delegate->validator_identity.ik.len, outVal + written_value, outValLen - written_value));
//     written_value = strlen(outVal);

//     // add "Input"
//     snprintf(outVal + written_value, outValLen - written_value, " Input ");
//     written_value = strlen(outVal);

//     // add unbonded amount
//     value_t local_value = {0};
//     static const uint8_t default_asset_id[ASSET_ID_LEN] = STAKING_TOKEN_ASSET_ID_BYTES;
//     local_value.amount.hi = delegate->unbonded_amount.hi;
//     local_value.amount.lo = delegate->unbonded_amount.lo;
//     local_value.asset_id.inner.ptr = default_asset_id;
//     local_value.asset_id.inner.len = ASSET_ID_LEN;
//     local_value.has_amount = true;
//     local_value.has_asset_id = true;
//     CHECK_ERROR(printValue(ctx, &local_value, &ctx->tx_obj->parameters_plan.chain_id, outVal + written_value, outValLen - written_value));

//     return parser_ok;
// }