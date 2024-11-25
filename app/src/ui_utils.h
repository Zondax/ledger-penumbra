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

/**
 * @brief Encodes binary data into a Bech32 format string with a specified prefix.
 *
 * This function generates a Bech32-encoded string from the input data, appending a checksum.
 * It verifies that the input data has the expected length and that the output buffer
 * is large enough to accommodate the resulting string.
 *
 * @param[in] prefix        The human-readable part (HRP) of the Bech32 string.
 * @param[in] prefix_len    The length of the prefix, excluding the null terminator.
 * @param[in] data          Pointer to the binary data to encode.
 * @param[in] data_len      Length of the binary data to encode.
 * @param[in] expected_len  Expected length of the binary data (for validation).
 * @param[out] out          Buffer to store the resulting Bech32-encoded string.
 * @param[in] out_len       Length of the output buffer.
 *
 * @return parser_ok on success, or an appropriate error code:
 *         - `parser_unexpected_error` if encoding fails or the input data is NULL.
 *         - `parser_invalid_address` if the length of the input data does not match the expected length.
 *         - `parser_display_idx_out_of_range` if the output buffer is too small.
 */
parser_error_t printBech32Encoded(const char *prefix, uint16_t prefix_len, uint8_t *data,
                                         uint16_t data_len, uint16_t expected_len,
                                         char *out, uint16_t out_len);

parser_error_t printAddress(uint8_t *address, uint16_t address_len, char *out, uint16_t out_len);
parser_error_t printAssetId(uint8_t *asset, uint16_t asset_len, char *out, uint16_t out_len);
