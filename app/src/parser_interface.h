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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "keys_def.h"
#include "parser_common.h"
#include "zxerror.h"
#include "zxmacros.h"

parser_error_t compute_transaction_plan(transaction_plan_t *plan, uint8_t *effect_hash, uint16_t effect_hash_len);
parser_error_t compute_action_hash(spend_plan_t *plan, uint8_t action_type, action_hash_t *output);

#ifdef __cplusplus
}
#endif
