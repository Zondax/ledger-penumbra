/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_PENUMBRA_TOOLS_SUMMONING_V1_PENUMBRA_TOOLS_SUMMONING_V1_SUMMONING_PB_H_INCLUDED
#define PB_PENUMBRA_TOOLS_SUMMONING_V1_PENUMBRA_TOOLS_SUMMONING_V1_SUMMONING_PB_H_INCLUDED
#include <pb.h>

#include "penumbra/core/keys/v1/keys.pb.h"
#include "penumbra/core/num/v1/num.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Sent at the beginning of the connection to identify the participant. */
typedef struct _penumbra_tools_summoning_v1_ParticipateRequest_Identify {
    bool has_address;
    penumbra_core_keys_v1_Address address;
} penumbra_tools_summoning_v1_ParticipateRequest_Identify;

typedef struct _penumbra_tools_summoning_v1_CeremonyCrs {
    pb_callback_t spend;
    pb_callback_t output;
    pb_callback_t delegator_vote;
    pb_callback_t undelegate_claim;
    pb_callback_t swap;
    pb_callback_t swap_claim;
    pb_callback_t nullifer_derivation_crs;
} penumbra_tools_summoning_v1_CeremonyCrs;

typedef struct _penumbra_tools_summoning_v1_CeremonyLinkingProof {
    pb_callback_t spend;
    pb_callback_t output;
    pb_callback_t delegator_vote;
    pb_callback_t undelegate_claim;
    pb_callback_t swap;
    pb_callback_t swap_claim;
    pb_callback_t nullifer_derivation_crs;
} penumbra_tools_summoning_v1_CeremonyLinkingProof;

typedef struct _penumbra_tools_summoning_v1_CeremonyParentHashes {
    pb_callback_t spend;
    pb_callback_t output;
    pb_callback_t delegator_vote;
    pb_callback_t undelegate_claim;
    pb_callback_t swap;
    pb_callback_t swap_claim;
    pb_callback_t nullifer_derivation_crs;
} penumbra_tools_summoning_v1_CeremonyParentHashes;

/* Sent by the participant after getting a `ContributeNow` message. */
typedef struct _penumbra_tools_summoning_v1_ParticipateRequest_Contribution {
    bool has_updated;
    penumbra_tools_summoning_v1_CeremonyCrs updated;
    bool has_update_proofs;
    penumbra_tools_summoning_v1_CeremonyLinkingProof update_proofs;
    bool has_parent_hashes;
    penumbra_tools_summoning_v1_CeremonyParentHashes parent_hashes;
} penumbra_tools_summoning_v1_ParticipateRequest_Contribution;

typedef struct _penumbra_tools_summoning_v1_ParticipateRequest {
    pb_size_t which_msg;
    union {
        penumbra_tools_summoning_v1_ParticipateRequest_Identify identify;
        penumbra_tools_summoning_v1_ParticipateRequest_Contribution contribution;
    } msg;
} penumbra_tools_summoning_v1_ParticipateRequest;

/* Streamed to the participant to inform them of their position in the queue. */
typedef struct _penumbra_tools_summoning_v1_ParticipateResponse_Position {
    /* The position of the participant in the queue. */
    uint32_t position;
    /* The total number of participants in the queue. */
    uint32_t connected_participants;
    /* The bid for the most recently executed contribution slot. */
    bool has_last_slot_bid;
    penumbra_core_num_v1_Amount last_slot_bid;
    /* The participant's current bid. */
    bool has_your_bid;
    penumbra_core_num_v1_Amount your_bid;
} penumbra_tools_summoning_v1_ParticipateResponse_Position;

/* Sent to the participant to inform them that they should contribute now. */
typedef struct _penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow {
    /* The most recent CRS, which the participant should update. */
    bool has_parent;
    penumbra_tools_summoning_v1_CeremonyCrs parent;
} penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow;

/* Sent to the participant to confim their contribution was accepted. */
typedef struct _penumbra_tools_summoning_v1_ParticipateResponse_Confirm {
    uint64_t slot;
} penumbra_tools_summoning_v1_ParticipateResponse_Confirm;

typedef struct _penumbra_tools_summoning_v1_ParticipateResponse {
    pb_size_t which_msg;
    union {
        penumbra_tools_summoning_v1_ParticipateResponse_Position position;
        penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow contribute_now;
        penumbra_tools_summoning_v1_ParticipateResponse_Confirm confirm;
    } msg;
} penumbra_tools_summoning_v1_ParticipateResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define penumbra_tools_summoning_v1_ParticipateRequest_init_default                 \
    {                                                                               \
        0, { penumbra_tools_summoning_v1_ParticipateRequest_Identify_init_default } \
    }
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_init_default \
    { false, penumbra_core_keys_v1_Address_init_default }
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_init_default  \
    {                                                                             \
        false, penumbra_tools_summoning_v1_CeremonyCrs_init_default, false,       \
            penumbra_tools_summoning_v1_CeremonyLinkingProof_init_default, false, \
            penumbra_tools_summoning_v1_CeremonyParentHashes_init_default         \
    }
#define penumbra_tools_summoning_v1_CeremonyCrs_init_default                                                             \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_init_default                                                    \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_CeremonyParentHashes_init_default                                                    \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_ParticipateResponse_init_default                 \
    {                                                                                \
        0, { penumbra_tools_summoning_v1_ParticipateResponse_Position_init_default } \
    }
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_init_default \
    { 0, 0, false, penumbra_core_num_v1_Amount_init_default, false, penumbra_core_num_v1_Amount_init_default }
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_init_default \
    { false, penumbra_tools_summoning_v1_CeremonyCrs_init_default }
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_init_default \
    { 0 }
#define penumbra_tools_summoning_v1_ParticipateRequest_init_zero                 \
    {                                                                            \
        0, { penumbra_tools_summoning_v1_ParticipateRequest_Identify_init_zero } \
    }
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_init_zero \
    { false, penumbra_core_keys_v1_Address_init_zero }
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_init_zero  \
    {                                                                          \
        false, penumbra_tools_summoning_v1_CeremonyCrs_init_zero, false,       \
            penumbra_tools_summoning_v1_CeremonyLinkingProof_init_zero, false, \
            penumbra_tools_summoning_v1_CeremonyParentHashes_init_zero         \
    }
#define penumbra_tools_summoning_v1_CeremonyCrs_init_zero                                                                \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_init_zero                                                       \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_CeremonyParentHashes_init_zero                                                       \
    {                                                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define penumbra_tools_summoning_v1_ParticipateResponse_init_zero                 \
    {                                                                             \
        0, { penumbra_tools_summoning_v1_ParticipateResponse_Position_init_zero } \
    }
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_init_zero \
    { 0, 0, false, penumbra_core_num_v1_Amount_init_zero, false, penumbra_core_num_v1_Amount_init_zero }
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_init_zero \
    { false, penumbra_tools_summoning_v1_CeremonyCrs_init_zero }
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_address_tag 1
#define penumbra_tools_summoning_v1_CeremonyCrs_spend_tag 100
#define penumbra_tools_summoning_v1_CeremonyCrs_output_tag 101
#define penumbra_tools_summoning_v1_CeremonyCrs_delegator_vote_tag 102
#define penumbra_tools_summoning_v1_CeremonyCrs_undelegate_claim_tag 103
#define penumbra_tools_summoning_v1_CeremonyCrs_swap_tag 104
#define penumbra_tools_summoning_v1_CeremonyCrs_swap_claim_tag 105
#define penumbra_tools_summoning_v1_CeremonyCrs_nullifer_derivation_crs_tag 106
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_spend_tag 100
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_output_tag 101
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_delegator_vote_tag 102
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_undelegate_claim_tag 103
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_swap_tag 104
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_swap_claim_tag 105
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_nullifer_derivation_crs_tag 106
#define penumbra_tools_summoning_v1_CeremonyParentHashes_spend_tag 100
#define penumbra_tools_summoning_v1_CeremonyParentHashes_output_tag 101
#define penumbra_tools_summoning_v1_CeremonyParentHashes_delegator_vote_tag 102
#define penumbra_tools_summoning_v1_CeremonyParentHashes_undelegate_claim_tag 103
#define penumbra_tools_summoning_v1_CeremonyParentHashes_swap_tag 104
#define penumbra_tools_summoning_v1_CeremonyParentHashes_swap_claim_tag 105
#define penumbra_tools_summoning_v1_CeremonyParentHashes_nullifer_derivation_crs_tag 106
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_updated_tag 1
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_update_proofs_tag 2
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_parent_hashes_tag 3
#define penumbra_tools_summoning_v1_ParticipateRequest_identify_tag 1
#define penumbra_tools_summoning_v1_ParticipateRequest_contribution_tag 2
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_position_tag 1
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_connected_participants_tag 2
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_last_slot_bid_tag 3
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_your_bid_tag 4
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_parent_tag 1
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_slot_tag 1
#define penumbra_tools_summoning_v1_ParticipateResponse_position_tag 1
#define penumbra_tools_summoning_v1_ParticipateResponse_contribute_now_tag 2
#define penumbra_tools_summoning_v1_ParticipateResponse_confirm_tag 3

/* Struct field encoding specification for nanopb */
#define penumbra_tools_summoning_v1_ParticipateRequest_FIELDLIST(X, a) \
    X(a, STATIC, ONEOF, MESSAGE, (msg, identify, msg.identify), 1)     \
    X(a, STATIC, ONEOF, MESSAGE, (msg, contribution, msg.contribution), 2)
#define penumbra_tools_summoning_v1_ParticipateRequest_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_msg_identify_MSGTYPE \
    penumbra_tools_summoning_v1_ParticipateRequest_Identify
#define penumbra_tools_summoning_v1_ParticipateRequest_msg_contribution_MSGTYPE \
    penumbra_tools_summoning_v1_ParticipateRequest_Contribution

#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, address, 1)
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_address_MSGTYPE penumbra_core_keys_v1_Address

#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, updated, 1)                                     \
    X(a, STATIC, OPTIONAL, MESSAGE, update_proofs, 2)                               \
    X(a, STATIC, OPTIONAL, MESSAGE, parent_hashes, 3)
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_updated_MSGTYPE penumbra_tools_summoning_v1_CeremonyCrs
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_update_proofs_MSGTYPE \
    penumbra_tools_summoning_v1_CeremonyLinkingProof
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_parent_hashes_MSGTYPE \
    penumbra_tools_summoning_v1_CeremonyParentHashes

#define penumbra_tools_summoning_v1_CeremonyCrs_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, spend, 100)                 \
    X(a, CALLBACK, SINGULAR, BYTES, output, 101)                \
    X(a, CALLBACK, SINGULAR, BYTES, delegator_vote, 102)        \
    X(a, CALLBACK, SINGULAR, BYTES, undelegate_claim, 103)      \
    X(a, CALLBACK, SINGULAR, BYTES, swap, 104)                  \
    X(a, CALLBACK, SINGULAR, BYTES, swap_claim, 105)            \
    X(a, CALLBACK, SINGULAR, BYTES, nullifer_derivation_crs, 106)
#define penumbra_tools_summoning_v1_CeremonyCrs_CALLBACK pb_default_field_callback
#define penumbra_tools_summoning_v1_CeremonyCrs_DEFAULT NULL

#define penumbra_tools_summoning_v1_CeremonyLinkingProof_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, spend, 100)                          \
    X(a, CALLBACK, SINGULAR, BYTES, output, 101)                         \
    X(a, CALLBACK, SINGULAR, BYTES, delegator_vote, 102)                 \
    X(a, CALLBACK, SINGULAR, BYTES, undelegate_claim, 103)               \
    X(a, CALLBACK, SINGULAR, BYTES, swap, 104)                           \
    X(a, CALLBACK, SINGULAR, BYTES, swap_claim, 105)                     \
    X(a, CALLBACK, SINGULAR, BYTES, nullifer_derivation_crs, 106)
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_CALLBACK pb_default_field_callback
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_DEFAULT NULL

#define penumbra_tools_summoning_v1_CeremonyParentHashes_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, spend, 100)                          \
    X(a, CALLBACK, SINGULAR, BYTES, output, 101)                         \
    X(a, CALLBACK, SINGULAR, BYTES, delegator_vote, 102)                 \
    X(a, CALLBACK, SINGULAR, BYTES, undelegate_claim, 103)               \
    X(a, CALLBACK, SINGULAR, BYTES, swap, 104)                           \
    X(a, CALLBACK, SINGULAR, BYTES, swap_claim, 105)                     \
    X(a, CALLBACK, SINGULAR, BYTES, nullifer_derivation_crs, 106)
#define penumbra_tools_summoning_v1_CeremonyParentHashes_CALLBACK pb_default_field_callback
#define penumbra_tools_summoning_v1_CeremonyParentHashes_DEFAULT NULL

#define penumbra_tools_summoning_v1_ParticipateResponse_FIELDLIST(X, a)        \
    X(a, STATIC, ONEOF, MESSAGE, (msg, position, msg.position), 1)             \
    X(a, STATIC, ONEOF, MESSAGE, (msg, contribute_now, msg.contribute_now), 2) \
    X(a, STATIC, ONEOF, MESSAGE, (msg, confirm, msg.confirm), 3)
#define penumbra_tools_summoning_v1_ParticipateResponse_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_msg_position_MSGTYPE \
    penumbra_tools_summoning_v1_ParticipateResponse_Position
#define penumbra_tools_summoning_v1_ParticipateResponse_msg_contribute_now_MSGTYPE \
    penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow
#define penumbra_tools_summoning_v1_ParticipateResponse_msg_confirm_MSGTYPE \
    penumbra_tools_summoning_v1_ParticipateResponse_Confirm

#define penumbra_tools_summoning_v1_ParticipateResponse_Position_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT32, position, 1)                                  \
    X(a, STATIC, SINGULAR, UINT32, connected_participants, 2)                    \
    X(a, STATIC, OPTIONAL, MESSAGE, last_slot_bid, 3)                            \
    X(a, STATIC, OPTIONAL, MESSAGE, your_bid, 4)
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_last_slot_bid_MSGTYPE penumbra_core_num_v1_Amount
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_your_bid_MSGTYPE penumbra_core_num_v1_Amount

#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, parent, 1)
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_DEFAULT NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_parent_MSGTYPE penumbra_tools_summoning_v1_CeremonyCrs

#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UINT64, slot, 1)
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_CALLBACK NULL
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_DEFAULT NULL

extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateRequest_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateRequest_Identify_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateRequest_Contribution_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_CeremonyCrs_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_CeremonyLinkingProof_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_CeremonyParentHashes_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateResponse_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateResponse_Position_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_msg;
extern const pb_msgdesc_t penumbra_tools_summoning_v1_ParticipateResponse_Confirm_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define penumbra_tools_summoning_v1_ParticipateRequest_fields &penumbra_tools_summoning_v1_ParticipateRequest_msg
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_fields \
    &penumbra_tools_summoning_v1_ParticipateRequest_Identify_msg
#define penumbra_tools_summoning_v1_ParticipateRequest_Contribution_fields \
    &penumbra_tools_summoning_v1_ParticipateRequest_Contribution_msg
#define penumbra_tools_summoning_v1_CeremonyCrs_fields &penumbra_tools_summoning_v1_CeremonyCrs_msg
#define penumbra_tools_summoning_v1_CeremonyLinkingProof_fields &penumbra_tools_summoning_v1_CeremonyLinkingProof_msg
#define penumbra_tools_summoning_v1_CeremonyParentHashes_fields &penumbra_tools_summoning_v1_CeremonyParentHashes_msg
#define penumbra_tools_summoning_v1_ParticipateResponse_fields &penumbra_tools_summoning_v1_ParticipateResponse_msg
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_fields \
    &penumbra_tools_summoning_v1_ParticipateResponse_Position_msg
#define penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_fields \
    &penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_msg
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_fields \
    &penumbra_tools_summoning_v1_ParticipateResponse_Confirm_msg

/* Maximum encoded size of messages (where known) */
/* penumbra_tools_summoning_v1_ParticipateRequest_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_ParticipateRequest_Contribution_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_CeremonyCrs_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_CeremonyLinkingProof_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_CeremonyParentHashes_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_ParticipateResponse_size depends on runtime parameters */
/* penumbra_tools_summoning_v1_ParticipateResponse_ContributeNow_size depends on runtime parameters */
#if defined(penumbra_core_keys_v1_Address_size)
#define penumbra_tools_summoning_v1_ParticipateRequest_Identify_size (6 + penumbra_core_keys_v1_Address_size)
#endif
#define PENUMBRA_TOOLS_SUMMONING_V1_PENUMBRA_TOOLS_SUMMONING_V1_SUMMONING_PB_H_MAX_SIZE \
    penumbra_tools_summoning_v1_ParticipateResponse_Position_size
#define penumbra_tools_summoning_v1_ParticipateResponse_Confirm_size 11
#define penumbra_tools_summoning_v1_ParticipateResponse_Position_size 60

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif