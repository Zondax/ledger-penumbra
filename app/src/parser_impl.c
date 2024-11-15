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
#include "spend_plan.h"
#include "zxformat.h"

static bool decode_action(pb_istream_t *stream, const pb_field_t *field, void **arg);
static bool decode_detection_data(pb_istream_t *stream, const pb_field_t *field, void **arg);

static uint16_t actions_qty = 0;
static uint16_t detection_data_qty = 0;

void print_buffer(bytes_t *buffer, const char *title) {
#if defined(LEDGER_SPECIFIC)
    ZEMU_LOGF(50, "%s\n", title);
    char print[1000] = {0};
    array_to_hexstr(print, sizeof(print), buffer->ptr, buffer->len);
    ZEMU_LOGF(1000, "%s\n", print);
#else
    printf("%s %d: ", title, buffer->len);
    for (uint16_t i = 0; i < buffer->len; i++) {
        printf("%02x", buffer->ptr[i]);
    }
    printf("\n");
#endif
}

void print_string(const char *str) {
#if defined(LEDGER_SPECIFIC)
    ZEMU_LOGF(100, "%s\n", str);
#else
    printf("%s\n", str);
#endif
}

parser_error_t decode_output_plan(const bytes_t *data, output_plan_t *output) {
    penumbra_core_component_shielded_pool_v1_OutputPlan output_plan =
        penumbra_core_component_shielded_pool_v1_OutputPlan_init_default;

    pb_istream_t spend_stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t rseed_arg, value_blinding_arg, proof_blinding_r_arg, proof_blinding_s_arg;

    setup_decode_fixed_field(&output_plan.rseed, &rseed_arg, &output->rseed, RSEED_LEN);
    setup_decode_fixed_field(&output_plan.value_blinding, &value_blinding_arg, &output->value_blinding, 32);
    setup_decode_fixed_field(&output_plan.proof_blinding_r, &proof_blinding_r_arg, &output->proof_blinding_r, 32);
    setup_decode_fixed_field(&output_plan.proof_blinding_s, &proof_blinding_s_arg, &output->proof_blinding_s, 32);

    // asset_id in value
    fixed_size_field_t asset_id_arg;
    setup_decode_fixed_field(&output_plan.value.asset_id.inner, &asset_id_arg, &output->value.asset_id.inner, ASSET_ID_LEN);

    // inner in dest_address
    fixed_size_field_t dest_address_inner_arg;
    setup_decode_fixed_field(&output_plan.dest_address.inner, &dest_address_inner_arg, &output->dest_address.inner, 80);

    if (!pb_decode(&spend_stream, penumbra_core_component_shielded_pool_v1_OutputPlan_fields, &output_plan)) {
        return parser_output_plan_error;
    }

    output->value.amount.lo = output_plan.value.amount.lo;
    output->value.amount.hi = output_plan.value.amount.hi;

    return parser_ok;
}

parser_error_t decode_delegate_plan(const bytes_t *data, delegate_plan_t *delegate) {
    penumbra_core_component_stake_v1_Delegate delegate_plan =
        penumbra_core_component_stake_v1_Delegate_init_default;

    pb_istream_t spend_stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t validator_identity_arg;
    setup_decode_fixed_field(&delegate_plan.validator_identity.ik, &validator_identity_arg, &delegate->validator_identity.ik, 32);

    if (!pb_decode(&spend_stream, penumbra_core_component_stake_v1_Delegate_fields, &delegate_plan)) {
        return parser_delegate_plan_error;
    }

    delegate->has_validator_identity = delegate_plan.has_validator_identity;
    delegate->epoch_index = delegate_plan.epoch_index;
    if (delegate_plan.has_unbonded_amount) {
        delegate->unbonded_amount.lo = delegate_plan.unbonded_amount.lo;
        delegate->unbonded_amount.hi = delegate_plan.unbonded_amount.hi;
    }
    if (delegate_plan.has_delegation_amount) {
        delegate->delegation_amount.lo = delegate_plan.delegation_amount.lo;
        delegate->delegation_amount.hi = delegate_plan.delegation_amount.hi;
    }

    return parser_ok;
}

parser_error_t decode_undelegate_plan(const bytes_t *data, undelegate_plan_t *undelegate) {
    penumbra_core_component_stake_v1_Undelegate undelegate_plan =
        penumbra_core_component_stake_v1_Undelegate_init_default;

    pb_istream_t spend_stream = pb_istream_from_buffer(data->ptr, data->len);
    CHECK_APP_CANARY()

    // Set up fixed size fields
    fixed_size_field_t validator_identity_arg;
    setup_decode_fixed_field(&undelegate_plan.validator_identity.ik, &validator_identity_arg, &undelegate->validator_identity.ik, 32);

    if (!pb_decode(&spend_stream, penumbra_core_component_stake_v1_Undelegate_fields, &undelegate_plan)) {
        return parser_undelegate_plan_error;
    }

    undelegate->has_validator_identity = undelegate_plan.has_validator_identity;
    undelegate->start_epoch_index = undelegate_plan.start_epoch_index;
    if (undelegate_plan.has_unbonded_amount) {
        undelegate->unbonded_amount.lo = undelegate_plan.unbonded_amount.lo;
        undelegate->unbonded_amount.hi = undelegate_plan.unbonded_amount.hi;
    }
    if (undelegate_plan.has_delegation_amount) {
        undelegate->delegation_amount.lo = undelegate_plan.delegation_amount.lo;
        undelegate->delegation_amount.hi = undelegate_plan.delegation_amount.hi;
    }
    if (undelegate_plan.has_from_epoch) {
        undelegate->from_epoch.index = undelegate_plan.from_epoch.index;
        undelegate->from_epoch.start_height = undelegate_plan.from_epoch.start_height;
    }

    return parser_ok;
}

bool decode_action(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    penumbra_core_transaction_v1_ActionPlan action = penumbra_core_transaction_v1_ActionPlan_init_default;

    action_t *decode_arg = (action_t *)*arg;
    if (decode_arg == NULL) {
        return false;
    }

    if (actions_qty >= ACTIONS_QTY) {
        return false;
    }

    bytes_t action_data;
    action_data.ptr = stream->state + 3;
    action_data.len = stream->bytes_left - 3;

    if (!pb_decode(stream, penumbra_core_transaction_v1_ActionPlan_fields, &action)) {
        return false;
    }
    decode_arg[actions_qty].action_type = action.which_action;
    switch (action.which_action) {
        case penumbra_core_transaction_v1_ActionPlan_spend_tag:
            CHECK_ERROR(decode_spend_plan(&action_data, &decode_arg[actions_qty].action.spend));
            print_string("Spend action detected\n");
            break;
        case penumbra_core_transaction_v1_ActionPlan_output_tag:
            CHECK_ERROR(decode_output_plan(&action_data, &decode_arg[actions_qty].action.output));
            print_string("Output action detected\n");
            break;
        case penumbra_core_transaction_v1_ActionPlan_delegate_tag:
            CHECK_ERROR(decode_delegate_plan(&action_data, &decode_arg[actions_qty].action.delegate));
            print_string("Delegate action detected\n");
            break;
        case penumbra_core_transaction_v1_ActionPlan_undelegate_tag:
            CHECK_ERROR(decode_undelegate_plan(&action_data, &decode_arg[actions_qty].action.undelegate));
            print_string("Undelegate action detected\n");
            break;
        default:
            print_string("Unknown action detected\n");
            return false;
    }
    actions_qty++;

    return true;
}

bool decode_detection_data(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    if (stream->bytes_left == 0 || arg == NULL) return false;

    if (detection_data_qty >= DETECTION_DATA_QTY) {
        return false;
    }

    penumbra_core_transaction_v1_CluePlan cluePlan = penumbra_core_transaction_v1_CluePlan_init_default;
    fixed_size_field_t rseed_arg, address_inner_arg;
    variable_size_field_t address_alt_bech32m_arg;
    clue_plan_t *clue_plan_arg = (clue_plan_t *)*arg;

    setup_decode_fixed_field(&cluePlan.rseed, &rseed_arg, &clue_plan_arg[detection_data_qty].rseed, RSEED_SIZE);
    setup_decode_fixed_field(&cluePlan.address.inner, &address_inner_arg, &clue_plan_arg[detection_data_qty].address.inner,
                             MEMO_ADDRESS_INNER_SIZE);
    setup_decode_variable_field(&cluePlan.address.alt_bech32m, &address_alt_bech32m_arg,
                                &clue_plan_arg[detection_data_qty].address.alt_bech32m);

    if (!pb_decode(stream, penumbra_core_transaction_v1_CluePlan_fields, &cluePlan)) {
        return false;
    }

    clue_plan_arg[detection_data_qty].precision_bits = cluePlan.precision_bits;

    detection_data_qty++;
    return true;
}

parser_error_t _read(parser_context_t *c, parser_tx_t *v) {
    bytes_t data;
    action_t actions_plan[ACTIONS_QTY];
    data.ptr = c->buffer;
    data.len = c->bufferLen;
    actions_qty = 0;
    detection_data_qty = 0;

    penumbra_core_transaction_v1_TransactionPlan request = penumbra_core_transaction_v1_TransactionPlan_init_default;
    fixed_size_field_t memo_key_arg, memo_return_address_inner_arg;
    variable_size_field_t memo_text_arg, memo_return_address_alt_bech32m_arg;

    // memo callbacks
    setup_decode_fixed_field(&request.memo.key, &memo_key_arg, &v->plan.memo.key, MEMO_KEY_SIZE);
    setup_decode_variable_field(&request.memo.plaintext.text, &memo_text_arg, &v->plan.memo.plaintext.text);
    setup_decode_fixed_field(&request.memo.plaintext.return_address.inner, &memo_return_address_inner_arg,
                             &v->plan.memo.plaintext.return_address.inner, MEMO_ADDRESS_INNER_SIZE);
    setup_decode_variable_field(&request.memo.plaintext.return_address.alt_bech32m, &memo_return_address_alt_bech32m_arg,
                                &v->plan.memo.plaintext.return_address.alt_bech32m);

    // actions callbacks
    request.actions.funcs.decode = &decode_action;
    request.actions.arg = &actions_plan;

    // detection data callbacks
    request.detection_data.clue_plans.funcs.decode = &decode_detection_data;
    request.detection_data.clue_plans.arg = &v->plan.detection_data.clue_plans;

    pb_istream_t stream = pb_istream_from_buffer(c->buffer, c->bufferLen);
    CHECK_APP_CANARY()
    const bool status = pb_decode(&stream, penumbra_core_transaction_v1_TransactionPlan_fields, &request);
    if (!status) {
        // TODO: improve handling errors from callbacks
        if (actions_qty == ACTIONS_QTY) {
            return parser_actions_overflow;
        }
        if (detection_data_qty == DETECTION_DATA_QTY) {
            return parser_detection_data_overflow;
        }
        return parser_unexpected_error;
    }

    // get transaction parameters
    extract_data_from_tag(&data, &v->plan.transaction_parameters.parameters,
                          penumbra_core_transaction_v1_TransactionPlan_transaction_parameters_tag);
    print_buffer(&v->plan.transaction_parameters.parameters, "real transaction parameters");

    // print actions
    for (uint16_t i = 0; i < ACTIONS_QTY; i++) {
        switch (actions_plan[i].action_type) {
            case penumbra_core_transaction_v1_ActionPlan_spend_tag:
                print_buffer(&actions_plan[i].action.spend.note.address.inner, "real spend action note address inner");
                print_buffer(&actions_plan[i].action.spend.note.value.asset_id.inner, "real spend action note value asset id inner");
                print_buffer(&actions_plan[i].action.spend.note.rseed, "real spend action note rseed");
                print_buffer(&actions_plan[i].action.spend.randomizer, "real spend action proof randomizer");
                print_buffer(&actions_plan[i].action.spend.value_blinding, "real spend action proof value_blinding");
                print_buffer(&actions_plan[i].action.spend.proof_blinding_r, "real spend action proof proof_blinding_r");
                print_buffer(&actions_plan[i].action.spend.proof_blinding_s, "real spend action proof proof_blinding_s");

                // printf("position: %lu\n", actions_plan[i].action.spend.position);
                // printf("amount hi: %lu\n", actions_plan[i].action.spend.note.value.amount.hi);
                // printf("amount lo: %lu\n", actions_plan[i].action.spend.note.value.amount.lo);
                break;
            case penumbra_core_transaction_v1_ActionPlan_output_tag:
                print_buffer(&actions_plan[i].action.output.value.asset_id.inner, "real output action note value asset id inner");
                // printf("output value amount hi: %lu\n", actions_plan[i].action.output.value.amount.hi);
                // printf("output value amount lo: %lu\n", actions_plan[i].action.output.value.amount.lo);
                print_buffer(&actions_plan[i].action.output.dest_address.inner, "real output action note dest address inner");
                print_buffer(&actions_plan[i].action.output.rseed, "real output action note rseed");
                print_buffer(&actions_plan[i].action.output.value_blinding, "real output action note value_blinding");
                print_buffer(&actions_plan[i].action.output.proof_blinding_r, "real output action note proof_blinding_r");
                print_buffer(&actions_plan[i].action.output.proof_blinding_s, "real output action note proof_blinding_s");
                break;
        }
    }

    // print memo
    print_buffer(&v->plan.memo.key, "real memo key");
    print_buffer(&v->plan.memo.plaintext.text, "real memo plaintext text");
    print_buffer(&v->plan.memo.plaintext.return_address.inner, "real memo return address inner");
    print_buffer(&v->plan.memo.plaintext.return_address.alt_bech32m, "real memo return address alt bech32m");

    for (uint16_t i = 0; i < actions_qty; i++) {
        compute_action_hash(&actions_plan[i].action.spend, actions_plan[i].action_type, &v->plan.actions.hashes[i]);
    }
    v->plan.actions.qty = actions_qty;

    compute_transaction_plan(&v->plan, v->effect_hash, sizeof(v->effect_hash));

    // TODO: only for testing
    bytes_t effect_hash;
    effect_hash.ptr = v->effect_hash;
    effect_hash.len = sizeof(v->effect_hash);
    print_buffer(&effect_hash, "effect_hash");

    return parser_ok;
}

const char *parser_getErrorDescription(parser_error_t err) {
    switch (err) {
        case parser_ok:
            return "No error";
        case parser_no_data:
            return "No more data";
        case parser_init_context_empty:
            return "Initialized empty context";
        case parser_unexpected_buffer_end:
            return "Unexpected buffer end";
        case parser_unexpected_version:
            return "Unexpected version";
        case parser_unexpected_characters:
            return "Unexpected characters";
        case parser_unexpected_field:
            return "Unexpected field";
        case parser_duplicated_field:
            return "Unexpected duplicated field";
        case parser_value_out_of_range:
            return "Value out of range";
        case parser_unexpected_chain:
            return "Unexpected chain";
        case parser_missing_field:
            return "missing field";

        case parser_display_idx_out_of_range:
            return "display index out of range";
        case parser_display_page_out_of_range:
            return "display page out of range";
        case parser_actions_overflow:
            return "actions overflow";
        case parser_detection_data_overflow:
            return "detection data overflow";

        default:
            return "Unrecognized error code";
    }
}
