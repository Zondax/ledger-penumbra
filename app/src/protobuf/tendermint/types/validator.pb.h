/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_TENDERMINT_TYPES_TENDERMINT_TYPES_VALIDATOR_PB_H_INCLUDED
#define PB_TENDERMINT_TYPES_TENDERMINT_TYPES_VALIDATOR_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "tendermint/crypto/keys.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _tendermint_types_Validator {
    pb_callback_t address;
    bool has_pub_key;
    tendermint_crypto_PublicKey pub_key;
    int64_t voting_power;
    int64_t proposer_priority;
} tendermint_types_Validator;

typedef struct _tendermint_types_ValidatorSet {
    pb_callback_t validators;
    bool has_proposer;
    tendermint_types_Validator proposer;
    int64_t total_voting_power;
} tendermint_types_ValidatorSet;

typedef struct _tendermint_types_SimpleValidator {
    bool has_pub_key;
    tendermint_crypto_PublicKey pub_key;
    int64_t voting_power;
} tendermint_types_SimpleValidator;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define tendermint_types_ValidatorSet_init_default \
    { {{NULL}, NULL}, false, tendermint_types_Validator_init_default, 0 }
#define tendermint_types_Validator_init_default \
    { {{NULL}, NULL}, false, tendermint_crypto_PublicKey_init_default, 0, 0 }
#define tendermint_types_SimpleValidator_init_default \
    { false, tendermint_crypto_PublicKey_init_default, 0 }
#define tendermint_types_ValidatorSet_init_zero \
    { {{NULL}, NULL}, false, tendermint_types_Validator_init_zero, 0 }
#define tendermint_types_Validator_init_zero \
    { {{NULL}, NULL}, false, tendermint_crypto_PublicKey_init_zero, 0, 0 }
#define tendermint_types_SimpleValidator_init_zero \
    { false, tendermint_crypto_PublicKey_init_zero, 0 }

/* Field tags (for use in manual encoding/decoding) */
#define tendermint_types_Validator_address_tag 1
#define tendermint_types_Validator_pub_key_tag 2
#define tendermint_types_Validator_voting_power_tag 3
#define tendermint_types_Validator_proposer_priority_tag 4
#define tendermint_types_ValidatorSet_validators_tag 1
#define tendermint_types_ValidatorSet_proposer_tag 2
#define tendermint_types_ValidatorSet_total_voting_power_tag 3
#define tendermint_types_SimpleValidator_pub_key_tag 1
#define tendermint_types_SimpleValidator_voting_power_tag 2

/* Struct field encoding specification for nanopb */
#define tendermint_types_ValidatorSet_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, validators, 1)  \
    X(a, STATIC, OPTIONAL, MESSAGE, proposer, 2)      \
    X(a, STATIC, SINGULAR, INT64, total_voting_power, 3)
#define tendermint_types_ValidatorSet_CALLBACK pb_default_field_callback
#define tendermint_types_ValidatorSet_DEFAULT NULL
#define tendermint_types_ValidatorSet_validators_MSGTYPE tendermint_types_Validator
#define tendermint_types_ValidatorSet_proposer_MSGTYPE tendermint_types_Validator

#define tendermint_types_Validator_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, address, 1)    \
    X(a, STATIC, OPTIONAL, MESSAGE, pub_key, 2)    \
    X(a, STATIC, SINGULAR, INT64, voting_power, 3) \
    X(a, STATIC, SINGULAR, INT64, proposer_priority, 4)
#define tendermint_types_Validator_CALLBACK pb_default_field_callback
#define tendermint_types_Validator_DEFAULT NULL
#define tendermint_types_Validator_pub_key_MSGTYPE tendermint_crypto_PublicKey

#define tendermint_types_SimpleValidator_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, pub_key, 1)          \
    X(a, STATIC, SINGULAR, INT64, voting_power, 2)
#define tendermint_types_SimpleValidator_CALLBACK NULL
#define tendermint_types_SimpleValidator_DEFAULT NULL
#define tendermint_types_SimpleValidator_pub_key_MSGTYPE tendermint_crypto_PublicKey

extern const pb_msgdesc_t tendermint_types_ValidatorSet_msg;
extern const pb_msgdesc_t tendermint_types_Validator_msg;
extern const pb_msgdesc_t tendermint_types_SimpleValidator_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define tendermint_types_ValidatorSet_fields &tendermint_types_ValidatorSet_msg
#define tendermint_types_Validator_fields &tendermint_types_Validator_msg
#define tendermint_types_SimpleValidator_fields &tendermint_types_SimpleValidator_msg

/* Maximum encoded size of messages (where known) */
/* tendermint_types_ValidatorSet_size depends on runtime parameters */
/* tendermint_types_Validator_size depends on runtime parameters */
#if defined(tendermint_crypto_PublicKey_size)
#define TENDERMINT_TYPES_TENDERMINT_TYPES_VALIDATOR_PB_H_MAX_SIZE tendermint_types_SimpleValidator_size
#define tendermint_types_SimpleValidator_size (17 + tendermint_crypto_PublicKey_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
