/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_PENUMBRA_CORE_KEYS_V1_PENUMBRA_CORE_KEYS_V1_KEYS_PB_H_INCLUDED
#define PB_PENUMBRA_CORE_KEYS_V1_PENUMBRA_CORE_KEYS_V1_KEYS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* A Penumbra address. An address in Penumbra is a Bech32m-encoded
 string, with the human-readable prefix (HRP) `penumbrav2t`. */
typedef struct _penumbra_core_keys_v1_Address {
    /* The bytes of the address. Must be represented as a series of
 `uint8` (i.e. values 0 through 255), with a length of 80 elements. */
    pb_callback_t inner;
    /* Alternatively, a Bech32m-encoded string representation of the `inner`
 bytes.

 NOTE: implementations are not required to support parsing this field.
 Implementations should prefer to encode the bytes in all messages they
 produce. Implementations must not accept messages with both `inner` and
 `alt_bech32m` set. */
    pb_callback_t alt_bech32m;
} penumbra_core_keys_v1_Address;

/* An opaque address, with no information about the address index or wallet ID visible. */
typedef struct _penumbra_core_keys_v1_AddressView_Opaque {
    bool has_address;
    penumbra_core_keys_v1_Address address;
} penumbra_core_keys_v1_AddressView_Opaque;

typedef struct _penumbra_core_keys_v1_PayloadKey {
    pb_callback_t inner;
} penumbra_core_keys_v1_PayloadKey;

typedef struct _penumbra_core_keys_v1_SpendKey {
    pb_callback_t inner;
} penumbra_core_keys_v1_SpendKey;

typedef struct _penumbra_core_keys_v1_FullViewingKey {
    pb_callback_t inner;
} penumbra_core_keys_v1_FullViewingKey;

typedef struct _penumbra_core_keys_v1_WalletId {
    pb_callback_t inner;
} penumbra_core_keys_v1_WalletId;

typedef struct _penumbra_core_keys_v1_Diversifier {
    pb_callback_t inner;
} penumbra_core_keys_v1_Diversifier;

typedef struct _penumbra_core_keys_v1_AddressIndex {
    uint32_t account;
    pb_callback_t randomizer;
} penumbra_core_keys_v1_AddressIndex;

/* A decoded address, with information about the address index and wallet ID visible. */
typedef struct _penumbra_core_keys_v1_AddressView_Decoded {
    bool has_address;
    penumbra_core_keys_v1_Address address;
    bool has_index;
    penumbra_core_keys_v1_AddressIndex index;
    bool has_wallet_id;
    penumbra_core_keys_v1_WalletId wallet_id;
} penumbra_core_keys_v1_AddressView_Decoded;

typedef struct _penumbra_core_keys_v1_AddressView {
    pb_size_t which_address_view;
    union {
        penumbra_core_keys_v1_AddressView_Decoded decoded;
        penumbra_core_keys_v1_AddressView_Opaque opaque;
    } address_view;
} penumbra_core_keys_v1_AddressView;

/* A validator's identity key (decaf377-rdsa spendauth verification key). */
typedef struct _penumbra_core_keys_v1_IdentityKey {
    pb_callback_t ik;
} penumbra_core_keys_v1_IdentityKey;

/* A validator's governance key (decaf377-rdsa spendauth verification key). */
typedef struct _penumbra_core_keys_v1_GovernanceKey {
    pb_callback_t gk;
} penumbra_core_keys_v1_GovernanceKey;

typedef struct _penumbra_core_keys_v1_ConsensusKey {
    pb_callback_t inner;
} penumbra_core_keys_v1_ConsensusKey;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define penumbra_core_keys_v1_Address_init_default \
    {                                              \
        {{NULL}, NULL}, { {NULL}, NULL }           \
    }
#define penumbra_core_keys_v1_AddressView_init_default                \
    {                                                                 \
        0, { penumbra_core_keys_v1_AddressView_Decoded_init_default } \
    }
#define penumbra_core_keys_v1_AddressView_Decoded_init_default                                                            \
    {                                                                                                                     \
        false, penumbra_core_keys_v1_Address_init_default, false, penumbra_core_keys_v1_AddressIndex_init_default, false, \
            penumbra_core_keys_v1_WalletId_init_default                                                                   \
    }
#define penumbra_core_keys_v1_AddressView_Opaque_init_default \
    { false, penumbra_core_keys_v1_Address_init_default }
#define penumbra_core_keys_v1_PayloadKey_init_default \
    {                                                 \
        { {NULL}, NULL }                              \
    }
#define penumbra_core_keys_v1_SpendKey_init_default \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define penumbra_core_keys_v1_FullViewingKey_init_default \
    {                                                     \
        { {NULL}, NULL }                                  \
    }
#define penumbra_core_keys_v1_WalletId_init_default \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define penumbra_core_keys_v1_Diversifier_init_default \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define penumbra_core_keys_v1_AddressIndex_init_default \
    {                                                   \
        0, { {NULL}, NULL }                             \
    }
#define penumbra_core_keys_v1_IdentityKey_init_default \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define penumbra_core_keys_v1_GovernanceKey_init_default \
    {                                                    \
        { {NULL}, NULL }                                 \
    }
#define penumbra_core_keys_v1_ConsensusKey_init_default \
    {                                                   \
        { {NULL}, NULL }                                \
    }
#define penumbra_core_keys_v1_Address_init_zero \
    {                                           \
        {{NULL}, NULL}, { {NULL}, NULL }        \
    }
#define penumbra_core_keys_v1_AddressView_init_zero                \
    {                                                              \
        0, { penumbra_core_keys_v1_AddressView_Decoded_init_zero } \
    }
#define penumbra_core_keys_v1_AddressView_Decoded_init_zero                                                         \
    {                                                                                                               \
        false, penumbra_core_keys_v1_Address_init_zero, false, penumbra_core_keys_v1_AddressIndex_init_zero, false, \
            penumbra_core_keys_v1_WalletId_init_zero                                                                \
    }
#define penumbra_core_keys_v1_AddressView_Opaque_init_zero \
    { false, penumbra_core_keys_v1_Address_init_zero }
#define penumbra_core_keys_v1_PayloadKey_init_zero \
    {                                              \
        { {NULL}, NULL }                           \
    }
#define penumbra_core_keys_v1_SpendKey_init_zero \
    {                                            \
        { {NULL}, NULL }                         \
    }
#define penumbra_core_keys_v1_FullViewingKey_init_zero \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define penumbra_core_keys_v1_WalletId_init_zero \
    {                                            \
        { {NULL}, NULL }                         \
    }
#define penumbra_core_keys_v1_Diversifier_init_zero \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define penumbra_core_keys_v1_AddressIndex_init_zero \
    {                                                \
        0, { {NULL}, NULL }                          \
    }
#define penumbra_core_keys_v1_IdentityKey_init_zero \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define penumbra_core_keys_v1_GovernanceKey_init_zero \
    {                                                 \
        { {NULL}, NULL }                              \
    }
#define penumbra_core_keys_v1_ConsensusKey_init_zero \
    {                                                \
        { {NULL}, NULL }                             \
    }

/* Field tags (for use in manual encoding/decoding) */
#define penumbra_core_keys_v1_Address_inner_tag 1
#define penumbra_core_keys_v1_Address_alt_bech32m_tag 2
#define penumbra_core_keys_v1_AddressView_Opaque_address_tag 1
#define penumbra_core_keys_v1_PayloadKey_inner_tag 1
#define penumbra_core_keys_v1_SpendKey_inner_tag 1
#define penumbra_core_keys_v1_FullViewingKey_inner_tag 1
#define penumbra_core_keys_v1_WalletId_inner_tag 1
#define penumbra_core_keys_v1_Diversifier_inner_tag 1
#define penumbra_core_keys_v1_AddressIndex_account_tag 2
#define penumbra_core_keys_v1_AddressIndex_randomizer_tag 3
#define penumbra_core_keys_v1_AddressView_Decoded_address_tag 1
#define penumbra_core_keys_v1_AddressView_Decoded_index_tag 2
#define penumbra_core_keys_v1_AddressView_Decoded_wallet_id_tag 3
#define penumbra_core_keys_v1_AddressView_decoded_tag 1
#define penumbra_core_keys_v1_AddressView_opaque_tag 2
#define penumbra_core_keys_v1_IdentityKey_ik_tag 1
#define penumbra_core_keys_v1_GovernanceKey_gk_tag 1
#define penumbra_core_keys_v1_ConsensusKey_inner_tag 1

/* Struct field encoding specification for nanopb */
#define penumbra_core_keys_v1_Address_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, inner, 1)         \
    X(a, CALLBACK, SINGULAR, STRING, alt_bech32m, 2)
#define penumbra_core_keys_v1_Address_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_Address_DEFAULT NULL

#define penumbra_core_keys_v1_AddressView_FIELDLIST(X, a)                          \
    X(a, STATIC, ONEOF, MESSAGE, (address_view, decoded, address_view.decoded), 1) \
    X(a, STATIC, ONEOF, MESSAGE, (address_view, opaque, address_view.opaque), 2)
#define penumbra_core_keys_v1_AddressView_CALLBACK NULL
#define penumbra_core_keys_v1_AddressView_DEFAULT NULL
#define penumbra_core_keys_v1_AddressView_address_view_decoded_MSGTYPE penumbra_core_keys_v1_AddressView_Decoded
#define penumbra_core_keys_v1_AddressView_address_view_opaque_MSGTYPE penumbra_core_keys_v1_AddressView_Opaque

#define penumbra_core_keys_v1_AddressView_Decoded_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, address, 1)                   \
    X(a, STATIC, OPTIONAL, MESSAGE, index, 2)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, wallet_id, 3)
#define penumbra_core_keys_v1_AddressView_Decoded_CALLBACK NULL
#define penumbra_core_keys_v1_AddressView_Decoded_DEFAULT NULL
#define penumbra_core_keys_v1_AddressView_Decoded_address_MSGTYPE penumbra_core_keys_v1_Address
#define penumbra_core_keys_v1_AddressView_Decoded_index_MSGTYPE penumbra_core_keys_v1_AddressIndex
#define penumbra_core_keys_v1_AddressView_Decoded_wallet_id_MSGTYPE penumbra_core_keys_v1_WalletId

#define penumbra_core_keys_v1_AddressView_Opaque_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, address, 1)
#define penumbra_core_keys_v1_AddressView_Opaque_CALLBACK NULL
#define penumbra_core_keys_v1_AddressView_Opaque_DEFAULT NULL
#define penumbra_core_keys_v1_AddressView_Opaque_address_MSGTYPE penumbra_core_keys_v1_Address

#define penumbra_core_keys_v1_PayloadKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_PayloadKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_PayloadKey_DEFAULT NULL

#define penumbra_core_keys_v1_SpendKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_SpendKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_SpendKey_DEFAULT NULL

#define penumbra_core_keys_v1_FullViewingKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_FullViewingKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_FullViewingKey_DEFAULT NULL

#define penumbra_core_keys_v1_WalletId_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_WalletId_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_WalletId_DEFAULT NULL

#define penumbra_core_keys_v1_Diversifier_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_Diversifier_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_Diversifier_DEFAULT NULL

#define penumbra_core_keys_v1_AddressIndex_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT32, account, 2)             \
    X(a, CALLBACK, SINGULAR, BYTES, randomizer, 3)
#define penumbra_core_keys_v1_AddressIndex_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_AddressIndex_DEFAULT NULL

#define penumbra_core_keys_v1_IdentityKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, ik, 1)
#define penumbra_core_keys_v1_IdentityKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_IdentityKey_DEFAULT NULL

#define penumbra_core_keys_v1_GovernanceKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, gk, 1)
#define penumbra_core_keys_v1_GovernanceKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_GovernanceKey_DEFAULT NULL

#define penumbra_core_keys_v1_ConsensusKey_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, inner, 1)
#define penumbra_core_keys_v1_ConsensusKey_CALLBACK pb_default_field_callback
#define penumbra_core_keys_v1_ConsensusKey_DEFAULT NULL

extern const pb_msgdesc_t penumbra_core_keys_v1_Address_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_AddressView_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_AddressView_Decoded_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_AddressView_Opaque_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_PayloadKey_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_SpendKey_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_FullViewingKey_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_WalletId_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_Diversifier_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_AddressIndex_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_IdentityKey_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_GovernanceKey_msg;
extern const pb_msgdesc_t penumbra_core_keys_v1_ConsensusKey_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define penumbra_core_keys_v1_Address_fields &penumbra_core_keys_v1_Address_msg
#define penumbra_core_keys_v1_AddressView_fields &penumbra_core_keys_v1_AddressView_msg
#define penumbra_core_keys_v1_AddressView_Decoded_fields &penumbra_core_keys_v1_AddressView_Decoded_msg
#define penumbra_core_keys_v1_AddressView_Opaque_fields &penumbra_core_keys_v1_AddressView_Opaque_msg
#define penumbra_core_keys_v1_PayloadKey_fields &penumbra_core_keys_v1_PayloadKey_msg
#define penumbra_core_keys_v1_SpendKey_fields &penumbra_core_keys_v1_SpendKey_msg
#define penumbra_core_keys_v1_FullViewingKey_fields &penumbra_core_keys_v1_FullViewingKey_msg
#define penumbra_core_keys_v1_WalletId_fields &penumbra_core_keys_v1_WalletId_msg
#define penumbra_core_keys_v1_Diversifier_fields &penumbra_core_keys_v1_Diversifier_msg
#define penumbra_core_keys_v1_AddressIndex_fields &penumbra_core_keys_v1_AddressIndex_msg
#define penumbra_core_keys_v1_IdentityKey_fields &penumbra_core_keys_v1_IdentityKey_msg
#define penumbra_core_keys_v1_GovernanceKey_fields &penumbra_core_keys_v1_GovernanceKey_msg
#define penumbra_core_keys_v1_ConsensusKey_fields &penumbra_core_keys_v1_ConsensusKey_msg

/* Maximum encoded size of messages (where known) */
/* penumbra_core_keys_v1_Address_size depends on runtime parameters */
/* penumbra_core_keys_v1_AddressView_size depends on runtime parameters */
/* penumbra_core_keys_v1_AddressView_Decoded_size depends on runtime parameters */
/* penumbra_core_keys_v1_AddressView_Opaque_size depends on runtime parameters */
/* penumbra_core_keys_v1_PayloadKey_size depends on runtime parameters */
/* penumbra_core_keys_v1_SpendKey_size depends on runtime parameters */
/* penumbra_core_keys_v1_FullViewingKey_size depends on runtime parameters */
/* penumbra_core_keys_v1_WalletId_size depends on runtime parameters */
/* penumbra_core_keys_v1_Diversifier_size depends on runtime parameters */
/* penumbra_core_keys_v1_AddressIndex_size depends on runtime parameters */
/* penumbra_core_keys_v1_IdentityKey_size depends on runtime parameters */
/* penumbra_core_keys_v1_GovernanceKey_size depends on runtime parameters */
/* penumbra_core_keys_v1_ConsensusKey_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
