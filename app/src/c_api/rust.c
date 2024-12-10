#include "parser_common.h"
#include "zxerror.h"
#include <zxmacros.h>

#if defined(LEDGER_SPECIFIC)
#include <cx.h>
#include <os.h>

#include "crypto.h"
#include "crypto_helper.h"

zxerr_t crypto_extractSpendingKeyBytes(uint8_t *key_bytes, uint32_t key_bytes_len);

// Function to compute BLAKE2b hash with personalization
zxerr_t blake2b_hash_with_personalization(const uint8_t *input, size_t input_len, uint8_t *output, size_t output_len,
                                          const uint8_t *label, size_t label_len) {
    cx_blake2b_t hash_context;

    // unsigned char *salt = NULL;
    // unsigned int salt_len = 0;

    zxerr_t error = zxerr_invalid_crypto_settings;

    // no salt
    CATCH_CXERROR(cx_blake2b_init2_no_throw(&hash_context, output_len * 8, NULL, 0, (uint8_t *)label, label_len));

    CATCH_CXERROR(cx_hash_no_throw(&hash_context.header, CX_LAST, input, input_len, output, output_len));

catch_cx_error:
    return error;
}

zxerr_t crypto_getSpendKeyBytes(uint8_t *sk, uint16_t len) {
    zxerr_t error = zxerr_invalid_crypto_settings;

    if (len != KEY_LEN) {
        return error;
    }

    keys_t keys = {0};
    CATCH_CXERROR(compute_keys(&keys));

    MEMCPY(sk, keys.skb, KEY_LEN);

catch_cx_error:
    return error;
}
#else

// This to support cpp tests
zxerr_t crypto_getSpendKeyBytes(uint8_t *sk, uint16_t len) {
    uint8_t sk_bytes_raw[KEY_LEN] = {0xa1, 0xff, 0xba, 0x0c, 0x37, 0x93, 0x1f, 0x0a, 0x62, 0x61, 0x37,
                                     0x52, 0x0d, 0xa6, 0x50, 0x63, 0x2d, 0x35, 0x85, 0x3b, 0xf5, 0x91,
                                     0xb3, 0x6b, 0xb4, 0x28, 0x63, 0x0a, 0x4d, 0x87, 0xc4, 0xdc};
    MEMCPY(sk, sk_bytes_raw, KEY_LEN);

    return zxerr_ok;
}

#endif