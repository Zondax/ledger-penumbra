/*******************************************************************************
 *   (c) 2018 - 2023 Zondax AG
 *   (c) 2016 Ledger
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

#include <os.h>
#include <os_io_seproxyhal.h>
#include <string.h>
#include <ux.h>

#include "actions.h"
#include "addr.h"
#include "app_main.h"
#include "coin.h"
#include "crypto.h"
#include "parser_common.h"
#include "tx.h"
#include "view.h"
#include "view_internal.h"
#include "zxformat.h"
#include "zxmacros.h"

static bool tx_initialized = false;

void extractHDPath(uint32_t rx, uint32_t offset) {
    tx_initialized = false;

    if ((rx - offset) < sizeof(uint32_t) * HDPATH_LEN_DEFAULT) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }
    memcpy(hdPath, G_io_apdu_buffer + offset, sizeof(uint32_t) * HDPATH_LEN_DEFAULT);

    // #{TODO} --> testnet necessary?
    const bool mainnet = hdPath[0] == HDPATH_0_DEFAULT && hdPath[1] == HDPATH_1_DEFAULT;

    if (!mainnet) {
        THROW(APDU_CODE_DATA_INVALID);
    }
}

__Z_INLINE bool process_chunk(__Z_UNUSED volatile uint32_t *tx, uint32_t rx) {
    const uint8_t payloadType = G_io_apdu_buffer[OFFSET_PAYLOAD_TYPE];
    if (rx < OFFSET_DATA) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }
    uint32_t added;
    switch (payloadType) {
        case P1_INIT:
            tx_initialize();
            tx_reset();
            extractHDPath(rx, OFFSET_DATA);
            tx_initialized = true;
            return false;
        case P1_ADD:
            if (!tx_initialized) {
                THROW(APDU_CODE_TX_NOT_INITIALIZED);
            }
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            if (added != rx - OFFSET_DATA) {
                tx_initialized = false;
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            return false;
        case P1_LAST:
            if (!tx_initialized) {
                THROW(APDU_CODE_TX_NOT_INITIALIZED);
            }
            added = tx_append(&(G_io_apdu_buffer[OFFSET_DATA]), rx - OFFSET_DATA);
            tx_initialized = false;
            if (added != rx - OFFSET_DATA) {
                tx_initialized = false;
                THROW(APDU_CODE_OUTPUT_BUFFER_TOO_SMALL);
            }
            tx_initialized = false;
            return true;
    }

    THROW(APDU_CODE_INVALIDP1P2);
}

__Z_INLINE void handleGetAddr(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleGetAddr\n");

    // TODO: Check size for nanos
#if defined(TARGET_NANOS)
    *tx = 0;
    THROW(APDU_CODE_DATA_INVALID);
#endif

    extractHDPath(rx, OFFSET_DATA);

    const uint8_t requireConfirmation = G_io_apdu_buffer[OFFSET_P1];

    // go to the account + randomizer data
    uint32_t account_offset = OFFSET_DATA + sizeof(uint32_t) * HDPATH_LEN_DEFAULT;
    uint32_t rand_offset = account_offset + sizeof(uint32_t);

    uint32_t account = 0;

    // check for account data
    if (rx < account_offset || (rx - account_offset) < sizeof(uint32_t)) {
        THROW(APDU_CODE_WRONG_LENGTH);
    }

    U32_BE(&G_io_apdu_buffer[account_offset], account);

    uint8_t *randomizer = NULL;
    uint8_t rand_data[ADDR_RANDOMIZER_LEN] = {0};

    // check if we received the randomizer, if so check also we received
    // the expected amount of bytes for it.
    if (rx > rand_offset && (rx - rand_offset) >= ADDR_RANDOMIZER_LEN) {
        memcpy(rand_data, &G_io_apdu_buffer[rand_offset], ADDR_RANDOMIZER_LEN);
        randomizer = &rand_data[0];
    }

    // TODO: I have to send 0 instead of account to get the same result as penumbra repo
    zxerr_t zxerr = app_fill_address(0, randomizer);

    if (zxerr != zxerr_ok) {
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }

    if (requireConfirmation) {
        view_review_init(addr_getItem, addr_getNumItems, app_reply_address);
        view_review_show(REVIEW_ADDRESS);
        *flags |= IO_ASYNCH_REPLY;
        return;
    }

    *tx = cmdResponseLen;
    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleGetFVK(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleGetFVK\n");

    // TODO: Check size for nanos
#if defined(TARGET_NANOS)
    *tx = 0;
    THROW(APDU_CODE_DATA_INVALID);
#endif

    extractHDPath(rx, OFFSET_DATA);

    zxerr_t zxerr = app_fill_keys();
    *tx = cmdResponseLen;

    if (zxerr != zxerr_ok) {
        *tx = 0;
        THROW(APDU_CODE_DATA_INVALID);
    }

    THROW(APDU_CODE_OK);
}

__Z_INLINE void handleSign(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleSign\n");

    if (!process_chunk(tx, rx)) {
        THROW(APDU_CODE_OK);
    }

    __Z_UNUSED const char *error_msg = tx_parse();
    CHECK_APP_CANARY()
    // if (error_msg != NULL) {
    //     const int error_msg_length = strnlen(error_msg, sizeof(G_io_apdu_buffer));
    //     memcpy(G_io_apdu_buffer, error_msg, error_msg_length);
    //     *tx += (error_msg_length);
    //     THROW(APDU_CODE_DATA_INVALID);
    // }

    // view_review_init(tx_getItem, tx_getNumItems, app_sign);
    // view_review_show(REVIEW_TXN);
    // *flags |= IO_ASYNCH_REPLY;
}

__Z_INLINE void handle_getversion(__Z_UNUSED volatile uint32_t *flags, volatile uint32_t *tx) {
    G_io_apdu_buffer[0] = 0;

#if defined(APP_TESTING)
    G_io_apdu_buffer[0] = 0x01;
#endif

    G_io_apdu_buffer[1] = (LEDGER_MAJOR_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[2] = (LEDGER_MAJOR_VERSION >> 0) & 0xFF;

    G_io_apdu_buffer[3] = (LEDGER_MINOR_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[4] = (LEDGER_MINOR_VERSION >> 0) & 0xFF;

    G_io_apdu_buffer[5] = (LEDGER_PATCH_VERSION >> 8) & 0xFF;
    G_io_apdu_buffer[6] = (LEDGER_PATCH_VERSION >> 0) & 0xFF;

    G_io_apdu_buffer[7] = !IS_UX_ALLOWED;

    G_io_apdu_buffer[8] = (TARGET_ID >> 24) & 0xFF;
    G_io_apdu_buffer[9] = (TARGET_ID >> 16) & 0xFF;
    G_io_apdu_buffer[10] = (TARGET_ID >> 8) & 0xFF;
    G_io_apdu_buffer[11] = (TARGET_ID >> 0) & 0xFF;

    *tx += 12;
    THROW(APDU_CODE_OK);
}

#if defined(APP_TESTING)
void handleTest(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) { THROW(APDU_CODE_OK); }
#endif

void handleApdu(volatile uint32_t *flags, volatile uint32_t *tx, uint32_t rx) {
    zemu_log("handleApdu\n");
    volatile uint16_t sw = 0;

    BEGIN_TRY {
        TRY {
            if (G_io_apdu_buffer[OFFSET_CLA] != CLA) {
                zemu_log("CLA not supported\n");
                THROW(APDU_CODE_CLA_NOT_SUPPORTED);
            }

            if (rx < APDU_MIN_LENGTH) {
                THROW(APDU_CODE_WRONG_LENGTH);
            }

            switch (G_io_apdu_buffer[OFFSET_INS]) {
                case INS_GET_VERSION: {
                    handle_getversion(flags, tx);
                    break;
                }

                case INS_GET_ADDR: {
                    CHECK_PIN_VALIDATED()
                    handleGetAddr(flags, tx, rx);
                    break;
                }

                case INS_GET_FVK: {
                    CHECK_PIN_VALIDATED()
                    handleGetFVK(flags, tx, rx);
                    break;
                }

                case INS_SIGN: {
                    CHECK_PIN_VALIDATED()
                    handleSign(flags, tx, rx);
                    break;
                }

#if defined(APP_TESTING)
                case INS_TEST: {
                    handleTest(flags, tx, rx);
                    THROW(APDU_CODE_OK);
                    break;
                }
#endif
                default:
                    zemu_log("ins_not_supported**\n");
                    THROW(APDU_CODE_INS_NOT_SUPPORTED);
            }
        }
        CATCH(EXCEPTION_IO_RESET) { THROW(EXCEPTION_IO_RESET); }
        CATCH_OTHER(e) {
            switch (e & 0xF000) {
                case 0x6000:
                case APDU_CODE_OK:
                    sw = e;
                    break;
                default:
                    sw = 0x6800 | (e & 0x7FF);
                    break;
            }
            G_io_apdu_buffer[*tx] = sw >> 8;
            G_io_apdu_buffer[*tx + 1] = sw & 0xFF;
            *tx += 2;
        }
        FINALLY {}
    }
    END_TRY;
}
