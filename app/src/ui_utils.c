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

#include "ui_utils.h"
#include "parser_common.h"
#include "rslib.h"
#include "zxerror.h"
#include "zxformat.h"
#include "zxmacros.h"
#include "constants.h"
#include "crypto_helper.h"


parser_error_t printBech32Encoded(const char *prefix, uint16_t prefix_len, const uint8_t *data,
                                         uint16_t data_len, char *out, uint16_t out_len) {
    if (data == NULL) {
        return parser_unexpected_error;
    }

    // Check we have space for the null terminator
    if (out_len < prefix_len + ((data_len * 8 + 4) / 5) + CHECKSUM_LENGTH + 1) {
        return parser_unexpected_buffer_end;
    }

    MEMZERO(out, out_len);

    int32_t ret = rs_bech32_encode((const uint8_t *)prefix, prefix_len, data,
                                   data_len, (uint8_t *)out, out_len);

    if (ret < 0) {
        return parser_unexpected_error;
    }

    return parser_ok;
}

parser_error_t printAddress(const spend_key_bytes_t *sk, const bytes_t *address, char *out, uint16_t out_len){
    if (out == NULL || out_len == 0 || address == NULL) {
        return parser_no_data;
    }

    // Validate input length
    if (address->len != ADDRESS_LEN_BYTES) {
        return parser_invalid_address;
    }

    bool is_visible = false;
    uint32_t index = 0;
    int32_t ret = rs_is_address_visible(sk, address, &is_visible, &index);
    if (ret < 0) {
        return parser_unexpected_error;
    }

    if (is_visible) {
        if (index == 0) {
            snprintf(out, out_len, "Main Account");
        } else {
            // We can use %d, because account is an uint32_t
            // otherwise u64_to_str or any other alternative
            // must be used
            snprintf(out, out_len, "Sub-account #%d", index);
        }
    } else {
        if (printShortAddress(address->ptr, address->len, out, out_len) != parser_ok) {
            return parser_no_data;
        }
    }

    return parser_ok;
}

parser_error_t encodeAddress(const uint8_t *address, uint16_t address_len, char *out, uint16_t out_len) {
    // Validate input length
    if (address_len != ADDRESS_LEN_BYTES) {
        return parser_invalid_address;
    }
// printBech32Encoded(const char *prefix, uint16_t prefix_len, const uint8_t *data,
//                                          uint16_t data_len, uint16_t expected_len,
//                                          char *out, uint16_t out_len);
    return printBech32Encoded(ADDR_BECH32_PREFIX, sizeof(ADDR_BECH32_PREFIX) - 1,
                              address, address_len,
                              out, out_len);
}

parser_error_t printShortAddress(const uint8_t *address, uint16_t address_len, char *out, uint16_t out_len) {
    // First get the full address encoded
    char full_address[ENCODED_ADDR_BUFFER_SIZE] = {0};
    parser_error_t err = encodeAddress(address, address_len, full_address, (uint16_t)sizeof(full_address));
    if (err != parser_ok) {
        return err;
    }
    
    // Calculate required length for short form
    uint16_t prefix_and_sep_len = sizeof(ADDR_BECH32_PREFIX); // prefix + separator
    uint16_t required_len = prefix_and_sep_len + SHORT_ADDRESS_VISIBLE_CHARS;

    // + ellipsis + null
    if (out_len < required_len + sizeof(ELLIPSIS)) {
        return parser_unexpected_buffer_end;
    }

    // Copy prefix + separator + visible chars
    uint16_t truncate_pos = prefix_and_sep_len + SHORT_ADDRESS_VISIBLE_CHARS;
    MEMZERO(out, out_len);
    MEMCPY(out, full_address, truncate_pos);

    // Add ellipsis but omit the null character
    MEMCPY(out + truncate_pos, ELLIPSIS, sizeof(ELLIPSIS) - 1);

    return parser_ok;
}


parser_error_t printAssetId(const uint8_t *asset, uint16_t asset_len, char *out, uint16_t out_len) {
    if (asset_len != ASSET_ID_LEN) {
        return parser_unexpected_buffer_end;
    }

    return printBech32Encoded(ASSET_BECH32_PREFIX, sizeof(ASSET_BECH32_PREFIX) - 1,
                              asset, asset_len, out, out_len);
}

parser_error_t uint128_to_str(char *data, int dataLen, uint64_t high, uint64_t low) {
    if (data == NULL) return parser_no_data;
    if (dataLen < U128_STR_MAX_LEN) return parser_value_out_of_range;

    MEMZERO(data, dataLen);
    char *p = data;

    if (high == 0 && low == 0) {
        *(p++) = '0';
        return parser_ok;
    }

    uint64_t temp_high = high;
    uint64_t temp_low = low;

    while (temp_high != 0 || temp_low != 0) {
        if (p - data >= (dataLen - 1)) return parser_value_out_of_range;

        uint64_t quotient_high = 0;
        uint64_t quotient_low = 0;
        uint64_t remainder = 0;
        uint64_t current;

        current = temp_high;
        quotient_high = current / 10;
        remainder = current % 10;

        current = (remainder << 32) | (temp_low >> 32);
        uint64_t q = current / 10;
        remainder = current % 10;
        quotient_low = (q << 32);

        current = (remainder << 32) | (temp_low & 0xFFFFFFFF);
        q = current / 10;
        remainder = current % 10;
        quotient_low |= q;

        *(p++) = (char)('0' + remainder);
        temp_high = quotient_high;
        temp_low = quotient_low;
    }

    while (p > data) {
        p--;
        char z = *data;
        *data = *p;
        *p = z;
        data++;
    }

    return parser_ok;
}
