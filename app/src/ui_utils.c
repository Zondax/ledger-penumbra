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
#include "rslib.h"
#include "zxerror.h"
#include "zxformat.h"
#include "zxmacros.h"
#include "constants.h"


parser_error_t printBech32Encoded(const char *prefix, uint16_t prefix_len, uint8_t *data,
                                         uint16_t data_len, uint16_t expected_len,
                                         char *out, uint16_t out_len) {
    if (data == NULL) {
        return parser_unexpected_error;
    }
    if (data_len != expected_len) {
        return parser_invalid_address;
    }

    // Check we have space for the null terminator
    if (out_len < prefix_len + ((data_len * 8 + 4) / 5) + CHECKSUM_LENGTH + 1) {
        return parser_display_idx_out_of_range;
    }

    MEMZERO(out, out_len);

    int32_t ret = rs_bech32_encode((const uint8_t *)prefix, prefix_len, data,
                                   data_len, (uint8_t *)out, out_len);

    if (ret < 0) {
        return parser_unexpected_error;
    }

    return parser_ok;
}


parser_error_t printAddress(uint8_t *address, uint16_t address_len, char *out, uint16_t out_len) {
    return printBech32Encoded(ADDR_BECH32_PREFIX, sizeof(ADDR_BECH32_PREFIX) - 1,
                              address, address_len, ADDRESS_LEN_BYTES,
                              out, out_len);
}

parser_error_t printAssetId(uint8_t *asset, uint16_t asset_len, char *out, uint16_t out_len) {
    return printBech32Encoded(ASSET_BECH32_PREFIX, sizeof(ASSET_BECH32_PREFIX) - 1,
                              asset, asset_len, ASSET_ID_LEN,
                              out, out_len);
}
