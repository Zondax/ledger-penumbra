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

#include "address_display.h"
#include "crypto_helper.h"
#include "constants.h"
#include "ui_utils.h"

parser_error_t print_addressWithOwnership(const address_index_t* address_index, const uint8_t* address, uint16_t addressLen, char* out, uint16_t outLen) {
    if (address_index == NULL || outLen != ENCODED_ADDR_LEN || addressLen != ADDRESS_LEN_BYTES) {
        return parser_no_data;
    }
    uint8_t randomizer[ADDR_RANDOMIZER_LEN] = {0};
    address_t local_addr = {0};

    if (address_index->has_randomizer) {
        MEMCPY(randomizer, address_index->randomizer, ADDR_RANDOMIZER_LEN);
    }

    if (compute_local_address(address_index->account, randomizer, local_addr) != zxerr_ok) {
        return parser_unexpected_error;
    }

    // compare the addresses
    if (MEMCMP(local_addr, address, ADDRESS_LEN_BYTES) == 0 ) {
        if (address_index->account == 0) {
            snprintf(out, outLen, "Main-Account");
        } else {
            // We can use %d, because account is an uint32_t
            // otherwise u64_to_str or any other alternative
            // must be used
            snprintf(out, ENCODED_ADDR_LEN, "Sub-Account %d", address_index->account);
        }
    } else {
        // render encoded address in shorter form
// printShortAddress(uint8_t *address, uint16_t address_len, char *out, uint16_t out_len);
        if (printShortAddress(address, ADDRESS_LEN_BYTES, out, ENCODED_ADDR_LEN) != parser_ok) {
            return parser_no_data;
        }
    }

    return parser_ok;
}
