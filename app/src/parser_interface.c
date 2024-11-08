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
#include "rslib.h"
#include "zxformat.h"

void print_buffer_interface(uint8_t *buffer, size_t len, const char *title) {
#if defined(LEDGER_SPECIFIC)
    ZEMU_LOGF(50, "%s\n", title);
    char print[700] = {0};
    array_to_hexstr(print, sizeof(print), buffer, len);
    ZEMU_LOGF(700, "%s\n", print);
#else
    printf("%s: ", title);
    for (size_t i = 0; i < len; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
#endif
}

parser_error_t compute_transaction_plan(transaction_plan_t *plan) {
    if (plan == NULL) return parser_unexpected_error;

    uint8_t output[300] = {0};
    if (rs_compute_transaction_plan(plan, output, sizeof(output)) != parser_ok) {
        return parser_unexpected_error;
    }

    // TODO: only for testing
    print_buffer_interface(output, 300, "output_bytes");

    return parser_ok;
}

parser_error_t compute_spend_action_hash(spend_plan_t *plan, action_hash_t *output) {
    if (plan == NULL || output == NULL) 
        return parser_unexpected_error;

    // TODO: we need to get the spend key
    spend_key_bytes_t sk_bytes = {
        0xa1, 0xff, 0xba, 0x0c, 0x37, 0x93, 0x1f, 0x0a, 0x62, 0x61, 0x37, 0x52, 0x0d, 0xa6, 0x50, 0x63,
        0x2d, 0x35, 0x85, 0x3b, 0xf5, 0x91, 0xb3, 0x6b, 0xb4, 0x28, 0x63, 0x0a, 0x4d, 0x87, 0xc4, 0xdc
    };

    if (rs_spend_action_hash(&sk_bytes, plan, (uint8_t *)output, 64) != parser_ok) {
        return parser_unexpected_error;
    }

    // TODO: only for testing
    print_buffer_interface((uint8_t *)output, 64, "spend action hash");

    return parser_ok;
}
