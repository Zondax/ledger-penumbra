/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_GENESIS_PB_H_INCLUDED
#define PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/gov/v1beta1/gov.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* GenesisState defines the gov module's genesis state. */
typedef struct _cosmos_gov_v1beta1_GenesisState {
    /* starting_proposal_id is the ID of the starting proposal. */
    uint64_t starting_proposal_id;
    /* deposits defines all the deposits present at genesis. */
    pb_callback_t deposits;
    /* votes defines all the votes present at genesis. */
    pb_callback_t votes;
    /* proposals defines all the proposals present at genesis. */
    pb_callback_t proposals;
    /* params defines all the parameters of related to deposit. */
    bool has_deposit_params;
    cosmos_gov_v1beta1_DepositParams deposit_params;
    /* params defines all the parameters of related to voting. */
    bool has_voting_params;
    cosmos_gov_v1beta1_VotingParams voting_params;
    /* params defines all the parameters of related to tally. */
    bool has_tally_params;
    cosmos_gov_v1beta1_TallyParams tally_params;
} cosmos_gov_v1beta1_GenesisState;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_gov_v1beta1_GenesisState_init_default                                                                    \
    {                                                                                                                   \
        0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_gov_v1beta1_DepositParams_init_default, false, \
            cosmos_gov_v1beta1_VotingParams_init_default, false, cosmos_gov_v1beta1_TallyParams_init_default            \
    }
#define cosmos_gov_v1beta1_GenesisState_init_zero                                                                    \
    {                                                                                                                \
        0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_gov_v1beta1_DepositParams_init_zero, false, \
            cosmos_gov_v1beta1_VotingParams_init_zero, false, cosmos_gov_v1beta1_TallyParams_init_zero               \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_gov_v1beta1_GenesisState_starting_proposal_id_tag 1
#define cosmos_gov_v1beta1_GenesisState_deposits_tag 2
#define cosmos_gov_v1beta1_GenesisState_votes_tag 3
#define cosmos_gov_v1beta1_GenesisState_proposals_tag 4
#define cosmos_gov_v1beta1_GenesisState_deposit_params_tag 5
#define cosmos_gov_v1beta1_GenesisState_voting_params_tag 6
#define cosmos_gov_v1beta1_GenesisState_tally_params_tag 7

/* Struct field encoding specification for nanopb */
#define cosmos_gov_v1beta1_GenesisState_FIELDLIST(X, a)     \
    X(a, STATIC, SINGULAR, UINT64, starting_proposal_id, 1) \
    X(a, CALLBACK, REPEATED, MESSAGE, deposits, 2)          \
    X(a, CALLBACK, REPEATED, MESSAGE, votes, 3)             \
    X(a, CALLBACK, REPEATED, MESSAGE, proposals, 4)         \
    X(a, STATIC, OPTIONAL, MESSAGE, deposit_params, 5)      \
    X(a, STATIC, OPTIONAL, MESSAGE, voting_params, 6)       \
    X(a, STATIC, OPTIONAL, MESSAGE, tally_params, 7)
#define cosmos_gov_v1beta1_GenesisState_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_GenesisState_DEFAULT NULL
#define cosmos_gov_v1beta1_GenesisState_deposits_MSGTYPE cosmos_gov_v1beta1_Deposit
#define cosmos_gov_v1beta1_GenesisState_votes_MSGTYPE cosmos_gov_v1beta1_Vote
#define cosmos_gov_v1beta1_GenesisState_proposals_MSGTYPE cosmos_gov_v1beta1_Proposal
#define cosmos_gov_v1beta1_GenesisState_deposit_params_MSGTYPE cosmos_gov_v1beta1_DepositParams
#define cosmos_gov_v1beta1_GenesisState_voting_params_MSGTYPE cosmos_gov_v1beta1_VotingParams
#define cosmos_gov_v1beta1_GenesisState_tally_params_MSGTYPE cosmos_gov_v1beta1_TallyParams

extern const pb_msgdesc_t cosmos_gov_v1beta1_GenesisState_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_gov_v1beta1_GenesisState_fields &cosmos_gov_v1beta1_GenesisState_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_gov_v1beta1_GenesisState_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
