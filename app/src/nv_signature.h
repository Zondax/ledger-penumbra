/*******************************************************************************
 *   (c) 2018 -2022 Zondax AG
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

#include "buffering.h"
#include "coin.h"
#include "keys_def.h"
#include "zxerror.h"

typedef enum SignatureType { Spend, DelegatorVote } signature_type_t;

void nv_signature_init();

void nv_signature_reset();

size_t nv_write_signature(const signature_t signature, signature_type_t type);

size_t nv_get_signature(uint16_t index, signature_t *signature, signature_type_t type);

size_t nv_num_signatures(signature_type_t type);
