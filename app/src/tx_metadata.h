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
#include "parser_common.h"

#ifdef __cplusplus
extern "C" {
#endif

parser_error_t metadata_parse(const uint8_t *data, size_t dataLen, tx_metadata_t *metadata, uint8_t metadataLen);

parser_error_t metadata_toAssetId(const tx_metadata_t *metadata, uint8_t *assetId, uint16_t assetIdLen);


#ifdef __cplusplus
}
#endif
