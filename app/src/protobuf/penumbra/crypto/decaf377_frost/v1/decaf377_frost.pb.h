/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_PENUMBRA_CRYPTO_DECAF377_FROST_V1_PENUMBRA_CRYPTO_DECAF377_FROST_V1_DECAF377_FROST_PB_H_INCLUDED
#define PB_PENUMBRA_CRYPTO_DECAF377_FROST_V1_PENUMBRA_CRYPTO_DECAF377_FROST_V1_DECAF377_FROST_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* A commitment to a polynomial, as a list of group elements. */
typedef struct _penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment {
    /* Each of these bytes should be the serialization of a group element. */
    pb_callback_t elements;
} penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment;

/* The public package sent in round 1 of the DKG protocol. */
typedef struct _penumbra_crypto_decaf377_frost_v1_DKGRound1Package {
    /* A commitment to the polynomial for secret sharing. */
    bool has_commitment;
    penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment commitment;
    /* A proof of knowledge of the underlying secret being shared. */
    pb_callback_t proof_of_knowledge;
} penumbra_crypto_decaf377_frost_v1_DKGRound1Package;

/* A share of the final signing key. */
typedef struct _penumbra_crypto_decaf377_frost_v1_SigningShare {
    /* These bytes should be a valid scalar. */
    pb_callback_t scalar;
} penumbra_crypto_decaf377_frost_v1_SigningShare;

/* The per-participant package sent in round 2 of the DKG protocol. */
typedef struct _penumbra_crypto_decaf377_frost_v1_DKGRound2Package {
    /* This is the share we're sending to that participant. */
    bool has_signing_share;
    penumbra_crypto_decaf377_frost_v1_SigningShare signing_share;
} penumbra_crypto_decaf377_frost_v1_DKGRound2Package;

/* Represents a commitment to a nonce value. */
typedef struct _penumbra_crypto_decaf377_frost_v1_NonceCommitment {
    /* These bytes should be a valid group element. */
    pb_callback_t element;
} penumbra_crypto_decaf377_frost_v1_NonceCommitment;

/* Represents the commitments to nonces needed for signing. */
typedef struct _penumbra_crypto_decaf377_frost_v1_SigningCommitments {
    /* One nonce to hide them. */
    bool has_hiding;
    penumbra_crypto_decaf377_frost_v1_NonceCommitment hiding;
    /* Another to bind them. */
    bool has_binding;
    penumbra_crypto_decaf377_frost_v1_NonceCommitment binding;
} penumbra_crypto_decaf377_frost_v1_SigningCommitments;

/* A share of the final signature. These get aggregated to make the actual thing. */
typedef struct _penumbra_crypto_decaf377_frost_v1_SignatureShare {
    /* These bytes should be a valid scalar. */
    pb_callback_t scalar;
} penumbra_crypto_decaf377_frost_v1_SignatureShare;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_init_default \
    {                                                                                    \
        { {NULL}, NULL }                                                                 \
    }
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_init_default                                           \
    {                                                                                                             \
        false, penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_init_default, { {NULL}, NULL } \
    }
#define penumbra_crypto_decaf377_frost_v1_SigningShare_init_default \
    {                                                               \
        { {NULL}, NULL }                                            \
    }
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_init_default \
    { false, penumbra_crypto_decaf377_frost_v1_SigningShare_init_default }
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_default \
    {                                                                  \
        { {NULL}, NULL }                                               \
    }
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_init_default             \
    {                                                                                 \
        false, penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_default, false, \
            penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_default            \
    }
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_init_default \
    {                                                                 \
        { {NULL}, NULL }                                              \
    }
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_init_zero \
    {                                                                                 \
        { {NULL}, NULL }                                                              \
    }
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_init_zero                                           \
    {                                                                                                          \
        false, penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_init_zero, { {NULL}, NULL } \
    }
#define penumbra_crypto_decaf377_frost_v1_SigningShare_init_zero \
    {                                                            \
        { {NULL}, NULL }                                         \
    }
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_init_zero \
    { false, penumbra_crypto_decaf377_frost_v1_SigningShare_init_zero }
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_zero \
    {                                                               \
        { {NULL}, NULL }                                            \
    }
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_init_zero             \
    {                                                                              \
        false, penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_zero, false, \
            penumbra_crypto_decaf377_frost_v1_NonceCommitment_init_zero            \
    }
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_init_zero \
    {                                                              \
        { {NULL}, NULL }                                           \
    }

/* Field tags (for use in manual encoding/decoding) */
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_elements_tag 1
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_commitment_tag 1
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_proof_of_knowledge_tag 2
#define penumbra_crypto_decaf377_frost_v1_SigningShare_scalar_tag 1
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_signing_share_tag 1
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_element_tag 1
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_hiding_tag 1
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_binding_tag 2
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_scalar_tag 1

/* Struct field encoding specification for nanopb */
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, BYTES, elements, 1)
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_CALLBACK pb_default_field_callback
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_DEFAULT NULL

#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, commitment, 1)                         \
    X(a, CALLBACK, SINGULAR, BYTES, proof_of_knowledge, 2)
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_CALLBACK pb_default_field_callback
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_DEFAULT NULL
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_commitment_MSGTYPE \
    penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment

#define penumbra_crypto_decaf377_frost_v1_SigningShare_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, scalar, 1)
#define penumbra_crypto_decaf377_frost_v1_SigningShare_CALLBACK pb_default_field_callback
#define penumbra_crypto_decaf377_frost_v1_SigningShare_DEFAULT NULL

#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, signing_share, 1)
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_CALLBACK NULL
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_DEFAULT NULL
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_signing_share_MSGTYPE \
    penumbra_crypto_decaf377_frost_v1_SigningShare

#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, element, 1)
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_CALLBACK pb_default_field_callback
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_DEFAULT NULL

#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, hiding, 1)                               \
    X(a, STATIC, OPTIONAL, MESSAGE, binding, 2)
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_CALLBACK NULL
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_DEFAULT NULL
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_hiding_MSGTYPE penumbra_crypto_decaf377_frost_v1_NonceCommitment
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_binding_MSGTYPE \
    penumbra_crypto_decaf377_frost_v1_NonceCommitment

#define penumbra_crypto_decaf377_frost_v1_SignatureShare_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, scalar, 1)
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_CALLBACK pb_default_field_callback
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_DEFAULT NULL

extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_DKGRound1Package_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_SigningShare_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_DKGRound2Package_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_NonceCommitment_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_SigningCommitments_msg;
extern const pb_msgdesc_t penumbra_crypto_decaf377_frost_v1_SignatureShare_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_fields \
    &penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_msg
#define penumbra_crypto_decaf377_frost_v1_DKGRound1Package_fields &penumbra_crypto_decaf377_frost_v1_DKGRound1Package_msg
#define penumbra_crypto_decaf377_frost_v1_SigningShare_fields &penumbra_crypto_decaf377_frost_v1_SigningShare_msg
#define penumbra_crypto_decaf377_frost_v1_DKGRound2Package_fields &penumbra_crypto_decaf377_frost_v1_DKGRound2Package_msg
#define penumbra_crypto_decaf377_frost_v1_NonceCommitment_fields &penumbra_crypto_decaf377_frost_v1_NonceCommitment_msg
#define penumbra_crypto_decaf377_frost_v1_SigningCommitments_fields &penumbra_crypto_decaf377_frost_v1_SigningCommitments_msg
#define penumbra_crypto_decaf377_frost_v1_SignatureShare_fields &penumbra_crypto_decaf377_frost_v1_SignatureShare_msg

/* Maximum encoded size of messages (where known) */
/* penumbra_crypto_decaf377_frost_v1_VerifiableSecretSharingCommitment_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_DKGRound1Package_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_SigningShare_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_DKGRound2Package_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_NonceCommitment_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_SigningCommitments_size depends on runtime parameters */
/* penumbra_crypto_decaf377_frost_v1_SignatureShare_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif