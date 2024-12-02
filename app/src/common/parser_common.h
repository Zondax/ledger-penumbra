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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "keys_def.h"
#include "parser_txdef.h"
#include "constants.h"

#define CHECK_ERROR(__CALL)                   \
    {                                         \
        parser_error_t __err = __CALL;        \
        CHECK_APP_CANARY()                    \
        if (__err != parser_ok) return __err; \
    }

// Convert bytes to uint32_t,
// assume data is in BE format
#define U32_BE(buffer, number)                                                                         \
    do {                                                                                               \
        (number) = (uint32_t)((buffer)[0] << 24 | (buffer)[1] << 16 | (buffer)[2] << 8 | (buffer)[3]); \
    } while (0)

typedef enum {
    // Generic errors
    parser_ok = 0,
    parser_no_data,
    parser_init_context_empty,
    parser_display_idx_out_of_range,
    parser_display_page_out_of_range,
    parser_unexpected_error,

    // Coin generic
    parser_unexpected_type,
    parser_unexpected_method,
    parser_unexpected_buffer_end,
    parser_unexpected_value,
    parser_unexpected_number_items,
    parser_unexpected_version,
    parser_unexpected_characters,
    parser_unexpected_field,
    parser_duplicated_field,
    parser_value_out_of_range,
    parser_invalid_address,
    parser_unexpected_chain,
    parser_missing_field,
    paser_unknown_transaction,
    parser_detection_data_overflow,
    parser_actions_overflow,
    parser_spend_plan_error,
    parser_output_plan_error,
    parser_delegate_plan_error,
    parser_undelegate_plan_error,
    parser_ics20_withdrawal_plan_error,
    parser_swap_plan_error,
} parser_error_t;

typedef struct {
    const uint8_t *buffer;
    uint16_t bufferLen;
    uint16_t offset;
    parser_tx_t *tx_obj;
    spend_key_bytes_t *sk_bytes;
    address_index_t address_index;
    tx_metadata_t tx_metadata[MAX_TX_METADATA_LEN]
} parser_context_t;

#ifdef __cplusplus
}
#endif
