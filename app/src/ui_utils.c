/*******************************************************************************
 *   (c) 2018 - 2023 Zondax AG
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

#include <stdio.h>

#include "parser_common.h"
#include "keys_def.h"
#include "rslib.h"
#include "zxerror.h"
#include "zxformat.h"
#include "zxmacros.h"

parser_error_t printAddress(uint8_t *address, uint16_t address_len, char *out, uint16_t out_len) {
    if (address_len != ADDRESS_LEN_BYTES) {
        return parser_invalid_address;
    }

    // check we have space for the null terminator
    if (out_len < ENCODED_ADDR_BUFFER_SIZE + 1) {
        return parser_display_idx_out_of_range;
    }

    MEMZERO(out, out_len);

    int32_t ret = rs_bech32_encode((const uint8_t *)BECH32_PREFIX, sizeof(BECH32_PREFIX) - 1, address,
                                           address_len, (uint8_t *)out, out_len);

    if (ret < 0) {
        return parser_unexpected_error;
    }

    return parser_ok;
}
