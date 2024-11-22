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

#include <zxmacros.h>
#include <stdbool.h>

#include "parser_common.h"
#include "parser_txdef.h"
#include "zxtypes.h"

#include "pb_common.h"
#include "pb_decode.h"
#include "protobuf/penumbra/core/transaction/v1/transaction.pb.h"

typedef struct {
    Bytes_t *bytes;
    uint16_t expected_size;
    bool check_size;
} fixed_size_field_t;

// Callback to parse binding fields in spend plans. all those fields are just
// 32-bytes data array that later in rust can be converted into
// Fq, Fr types
bool decode_fixed_field(pb_istream_t *stream, const pb_field_t *field, void **arg);

void setup_decode_fixed_field(pb_callback_t *callback, fixed_size_field_t *arg, Bytes_t *bytes, uint16_t expected_size, bool check_size);


#ifdef __cplusplus
}
#endif

