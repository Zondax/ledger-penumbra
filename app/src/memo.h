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

#include "parser_common.h"

#ifdef __cplusplus
extern "C" {
#endif

parser_error_t memo_getNumItems(const parser_context_t *ctx, uint8_t *num_items);
parser_error_t memo_getItem(const parser_context_t *ctx, uint8_t displayIdx, char *outKey, uint16_t outKeyLen, char *outVal,
                            uint16_t outValLen, uint8_t pageIdx, uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
