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
#pragma once

#include <os_io_seproxyhal.h>
#include <stdint.h>

#include "addr.h"
#include "apdu_codes.h"
#include "coin.h"
#include "crypto.h"
#include "parser_interface.h"
#include "tx.h"
#include "zxerror.h"
#include "zxformat.h"

extern uint16_t cmdResponseLen;
extern uint32_t address_idx_account;

__Z_INLINE zxerr_t app_fill_address(address_index_t address_index) {
    check_app_canary();
    // Put data directly in the apdu buffer
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);

    cmdResponseLen = 0;

    zxerr_t error = crypto_fillAddress(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 2, &cmdResponseLen, address_index.account,
                                       address_index.randomizer);

    if (error != zxerr_ok || cmdResponseLen == 0) {
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    // Set flag to show in case of requireConfirmation
    // that the address is indeed being randomized
    is_randomized = false;
    for (uint8_t i = 0; i < ADDR_RANDOMIZER_LEN; i++) {
        if (address_index.randomizer[i] != 0) {
            is_randomized = true;
            break;
        }
    }

    // Set the account in used to show it to the user
    // in case a review is enabled
    address_idx_account = address_index.account;

    return error;
}

__Z_INLINE zxerr_t app_fill_keys() {
    // Put data directly in the apdu buffer
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);

    cmdResponseLen = 0;

    zxerr_t err = crypto_fillKeys(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE - 2, &cmdResponseLen);

    if (err != zxerr_ok || cmdResponseLen == 0) {
        THROW(APDU_CODE_EXECUTION_ERROR);
    }

    return zxerr_ok;
}

__Z_INLINE void app_sign() {
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);

    parser_tx_t *tx = tx_get_txObject();

    // TODO: Only for testing. The section from here to check_app_canary will be removed
    zxerr_t err = zxerr_ok;

    // compute parameters hash
    compute_parameters_hash(&tx->parameters_plan.data_bytes, &tx->plan.parameters_hash);

    // compute action hashes
    for (uint16_t i = 0; i < tx->plan.actions.qty; i++) {
        compute_action_hash(&tx->actions_plan[i], &tx->plan.memo.key, &tx->plan.actions.hashes[i]);
    }

    // compute effect hash
    compute_effect_hash(&tx->plan, tx->effect_hash, sizeof(tx->effect_hash));

    MEMCPY(G_io_apdu_buffer, tx->effect_hash, EFFECT_HASH_LEN);

    check_app_canary();

    if (err != zxerr_ok) {
        set_code(G_io_apdu_buffer, 0, APDU_CODE_SIGN_VERIFY_ERROR);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
    } else {
        set_code(G_io_apdu_buffer, EFFECT_HASH_LEN, APDU_CODE_OK);
        io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, EFFECT_HASH_LEN + 2);
    }
}

__Z_INLINE void app_reject() {
    MEMZERO(G_io_apdu_buffer, IO_APDU_BUFFER_SIZE);
    set_code(G_io_apdu_buffer, 0, APDU_CODE_COMMAND_NOT_ALLOWED);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}

__Z_INLINE void app_reply_address() {
    set_code(G_io_apdu_buffer, cmdResponseLen, APDU_CODE_OK);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, cmdResponseLen + 2);
}

__Z_INLINE void app_reply_error() {
    set_code(G_io_apdu_buffer, 0, APDU_CODE_DATA_INVALID);
    io_exchange(CHANNEL_APDU | IO_RETURN_AFTER_TX, 2);
}
