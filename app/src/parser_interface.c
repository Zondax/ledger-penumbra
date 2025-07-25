/*******************************************************************************
 *  (c) 2018 - 2024 Zondax AG
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
#include "parser_interface.h"

#include <string.h>

#include "keys_def.h"
#include "protobuf/penumbra/core/transaction/v1/transaction.pb.h"
#include "rslib.h"

parser_error_t compute_effect_hash(transaction_plan_t *plan, uint8_t *effect_hash, uint16_t effect_hash_len) {
    if (plan == NULL || effect_hash == NULL) return parser_unexpected_error;

    parser_error_t err = rs_compute_effect_hash(plan, effect_hash, effect_hash_len);
    if (err != parser_ok) {
        return err;
    }

    return parser_ok;
}

parser_error_t compute_parameters_hash(bytes_t *parameters_bytes, hash_t *output) {
    if (parameters_bytes == NULL || output == NULL) return parser_unexpected_error;

    parser_error_t err = rs_parameter_hash(parameters_bytes, (uint8_t *)output, 64);
    if (err != parser_ok) {
        return err;
    }

    return parser_ok;
}

parser_error_t compute_action_hash(action_t *action, bytes_t *memo_key, hash_t *output) {
    if (action == NULL || output == NULL) return parser_unexpected_error;

    parser_error_t err = parser_unexpected_error;
    switch (action->action_type) {
        case penumbra_core_transaction_v1_ActionPlan_spend_tag:
            err = rs_spend_action_hash(&action->action.spend, (uint8_t *)output, 64);
            break;
        case penumbra_core_transaction_v1_ActionPlan_output_tag:
            err = rs_output_action_hash(&action->action.output, memo_key, (uint8_t *)output, 64);
            break;
#if defined(FULL_APP)
        case penumbra_core_transaction_v1_ActionPlan_swap_tag:
            err = rs_swap_action_hash(&action->action.swap, (uint8_t *)output, 64);
            break;
#endif
        case penumbra_core_transaction_v1_ActionPlan_ics20_withdrawal_tag:
        case penumbra_core_transaction_v1_ActionPlan_delegate_tag:
        case penumbra_core_transaction_v1_ActionPlan_undelegate_tag:
        case penumbra_core_transaction_v1_ActionPlan_position_open_plan_tag:
        case penumbra_core_transaction_v1_ActionPlan_position_close_tag:
        case penumbra_core_transaction_v1_ActionPlan_action_dutch_auction_schedule_tag:
        case penumbra_core_transaction_v1_ActionPlan_action_dutch_auction_end_tag:
            err = rs_generic_action_hash(&action->action_data, action->action_type, (uint8_t *)output, 64);
            break;
        case penumbra_core_transaction_v1_ActionPlan_undelegate_claim_tag:
            err = rs_undelegate_claim_action_hash(&action->action.undelegate_claim, (uint8_t *)output, 64);
            break;
        case penumbra_core_transaction_v1_ActionPlan_delegator_vote_tag:
            err = rs_delegator_vote_action_hash(&action->action.delegator_vote, (uint8_t *)output, 64);
            break;
        case penumbra_core_transaction_v1_ActionPlan_position_withdraw_tag:
            err = rs_position_withdraw_action_hash(&action->action.position_withdraw, (uint8_t *)output, 64);
            break;
        case penumbra_core_transaction_v1_ActionPlan_action_dutch_auction_withdraw_tag:
            err = rs_action_dutch_auction_withdraw_action_hash(&action->action.action_dutch_auction_withdraw,
                                                               (uint8_t *)output, 64);
            break;
        default:
            return parser_invalid_action_type;
    }

    return err;
}
