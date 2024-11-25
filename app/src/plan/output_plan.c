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
