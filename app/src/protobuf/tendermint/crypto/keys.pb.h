/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_TENDERMINT_CRYPTO_TENDERMINT_CRYPTO_KEYS_PB_H_INCLUDED
#define PB_TENDERMINT_CRYPTO_TENDERMINT_CRYPTO_KEYS_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* PublicKey defines the keys available for use with Validators */
typedef struct _tendermint_crypto_PublicKey {
    pb_size_t which_sum;
    union {
        pb_callback_t ed25519;
        pb_callback_t secp256k1;
    } sum;
} tendermint_crypto_PublicKey;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define tendermint_crypto_PublicKey_init_default \
    {                                            \
        0, {                                     \
            { {NULL}, NULL }                     \
        }                                        \
    }
#define tendermint_crypto_PublicKey_init_zero \
    {                                         \
        0, {                                  \
            { {NULL}, NULL }                  \
        }                                     \
    }

/* Field tags (for use in manual encoding/decoding) */
#define tendermint_crypto_PublicKey_ed25519_tag 1
#define tendermint_crypto_PublicKey_secp256k1_tag 2

/* Struct field encoding specification for nanopb */
#define tendermint_crypto_PublicKey_FIELDLIST(X, a)              \
    X(a, CALLBACK, ONEOF, BYTES, (sum, ed25519, sum.ed25519), 1) \
    X(a, CALLBACK, ONEOF, BYTES, (sum, secp256k1, sum.secp256k1), 2)
#define tendermint_crypto_PublicKey_CALLBACK pb_default_field_callback
#define tendermint_crypto_PublicKey_DEFAULT NULL

extern const pb_msgdesc_t tendermint_crypto_PublicKey_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define tendermint_crypto_PublicKey_fields &tendermint_crypto_PublicKey_msg

/* Maximum encoded size of messages (where known) */
/* tendermint_crypto_PublicKey_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
