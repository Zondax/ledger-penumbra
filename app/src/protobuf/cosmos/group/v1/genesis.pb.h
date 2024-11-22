/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_GROUP_V1_COSMOS_GROUP_V1_GENESIS_PB_H_INCLUDED
#define PB_COSMOS_GROUP_V1_COSMOS_GROUP_V1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/group/v1/types.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* GenesisState defines the group module's genesis state. */
typedef struct _cosmos_group_v1_GenesisState {
    /* group_seq is the group table orm.Sequence,
 it is used to get the next group ID. */
    uint64_t group_seq;
    /* groups is the list of groups info. */
    pb_callback_t groups;
    /* group_members is the list of groups members. */
    pb_callback_t group_members;
    /* group_policy_seq is the group policy table orm.Sequence,
 it is used to generate the next group policy account address. */
    uint64_t group_policy_seq;
    /* group_policies is the list of group policies info. */
    pb_callback_t group_policies;
    /* proposal_seq is the proposal table orm.Sequence,
 it is used to get the next proposal ID. */
    uint64_t proposal_seq;
    /* proposals is the list of proposals. */
    pb_callback_t proposals;
    /* votes is the list of votes. */
    pb_callback_t votes;
} cosmos_group_v1_GenesisState;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_group_v1_GenesisState_init_default                                                 \
    {                                                                                             \
        0, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_group_v1_GenesisState_init_zero                                                    \
    {                                                                                             \
        0, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, 0, {{NULL}, NULL}, { {NULL}, NULL } \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_group_v1_GenesisState_group_seq_tag 1
#define cosmos_group_v1_GenesisState_groups_tag 2
#define cosmos_group_v1_GenesisState_group_members_tag 3
#define cosmos_group_v1_GenesisState_group_policy_seq_tag 4
#define cosmos_group_v1_GenesisState_group_policies_tag 5
#define cosmos_group_v1_GenesisState_proposal_seq_tag 6
#define cosmos_group_v1_GenesisState_proposals_tag 7
#define cosmos_group_v1_GenesisState_votes_tag 8

/* Struct field encoding specification for nanopb */
#define cosmos_group_v1_GenesisState_FIELDLIST(X, a)     \
    X(a, STATIC, SINGULAR, UINT64, group_seq, 1)         \
    X(a, CALLBACK, REPEATED, MESSAGE, groups, 2)         \
    X(a, CALLBACK, REPEATED, MESSAGE, group_members, 3)  \
    X(a, STATIC, SINGULAR, UINT64, group_policy_seq, 4)  \
    X(a, CALLBACK, REPEATED, MESSAGE, group_policies, 5) \
    X(a, STATIC, SINGULAR, UINT64, proposal_seq, 6)      \
    X(a, CALLBACK, REPEATED, MESSAGE, proposals, 7)      \
    X(a, CALLBACK, REPEATED, MESSAGE, votes, 8)
#define cosmos_group_v1_GenesisState_CALLBACK pb_default_field_callback
#define cosmos_group_v1_GenesisState_DEFAULT NULL
#define cosmos_group_v1_GenesisState_groups_MSGTYPE cosmos_group_v1_GroupInfo
#define cosmos_group_v1_GenesisState_group_members_MSGTYPE cosmos_group_v1_GroupMember
#define cosmos_group_v1_GenesisState_group_policies_MSGTYPE cosmos_group_v1_GroupPolicyInfo
#define cosmos_group_v1_GenesisState_proposals_MSGTYPE cosmos_group_v1_Proposal
#define cosmos_group_v1_GenesisState_votes_MSGTYPE cosmos_group_v1_Vote

extern const pb_msgdesc_t cosmos_group_v1_GenesisState_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_group_v1_GenesisState_fields &cosmos_group_v1_GenesisState_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_group_v1_GenesisState_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif