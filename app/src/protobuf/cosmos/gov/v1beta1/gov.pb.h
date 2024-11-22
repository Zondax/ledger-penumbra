/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_GOV_PB_H_INCLUDED
#define PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_GOV_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/duration.pb.h"
#include "google/protobuf/timestamp.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* VoteOption enumerates the valid vote options for a given governance proposal. */
typedef enum _cosmos_gov_v1beta1_VoteOption {
    /* VOTE_OPTION_UNSPECIFIED defines a no-op vote option. */
    cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_UNSPECIFIED = 0,
    /* VOTE_OPTION_YES defines a yes vote option. */
    cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_YES = 1,
    /* VOTE_OPTION_ABSTAIN defines an abstain vote option. */
    cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_ABSTAIN = 2,
    /* VOTE_OPTION_NO defines a no vote option. */
    cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_NO = 3,
    /* VOTE_OPTION_NO_WITH_VETO defines a no with veto vote option. */
    cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_NO_WITH_VETO = 4
} cosmos_gov_v1beta1_VoteOption;

/* ProposalStatus enumerates the valid statuses of a proposal. */
typedef enum _cosmos_gov_v1beta1_ProposalStatus {
    /* PROPOSAL_STATUS_UNSPECIFIED defines the default proposal status. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_UNSPECIFIED = 0,
    /* PROPOSAL_STATUS_DEPOSIT_PERIOD defines a proposal status during the deposit
 period. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_DEPOSIT_PERIOD = 1,
    /* PROPOSAL_STATUS_VOTING_PERIOD defines a proposal status during the voting
 period. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_VOTING_PERIOD = 2,
    /* PROPOSAL_STATUS_PASSED defines a proposal status of a proposal that has
 passed. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_PASSED = 3,
    /* PROPOSAL_STATUS_REJECTED defines a proposal status of a proposal that has
 been rejected. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_REJECTED = 4,
    /* PROPOSAL_STATUS_FAILED defines a proposal status of a proposal that has
 failed. */
    cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_FAILED = 5
} cosmos_gov_v1beta1_ProposalStatus;

/* Struct definitions */
/* WeightedVoteOption defines a unit of vote for vote split.

 Since: cosmos-sdk 0.43 */
typedef struct _cosmos_gov_v1beta1_WeightedVoteOption {
    /* option defines the valid vote options, it must not contain duplicate vote options. */
    cosmos_gov_v1beta1_VoteOption option;
    /* weight is the vote weight associated with the vote option. */
    pb_callback_t weight;
} cosmos_gov_v1beta1_WeightedVoteOption;

/* TextProposal defines a standard text proposal whose changes need to be
 manually updated in case of approval. */
typedef struct _cosmos_gov_v1beta1_TextProposal {
    /* title of the proposal. */
    pb_callback_t title;
    /* description associated with the proposal. */
    pb_callback_t description;
} cosmos_gov_v1beta1_TextProposal;

/* Deposit defines an amount deposited by an account address to an active
 proposal. */
typedef struct _cosmos_gov_v1beta1_Deposit {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* depositor defines the deposit addresses from the proposals. */
    pb_callback_t depositor;
    /* amount to be deposited by depositor. */
    pb_callback_t amount;
} cosmos_gov_v1beta1_Deposit;

/* TallyResult defines a standard tally for a governance proposal. */
typedef struct _cosmos_gov_v1beta1_TallyResult {
    /* yes is the number of yes votes on a proposal. */
    pb_callback_t yes;
    /* abstain is the number of abstain votes on a proposal. */
    pb_callback_t abstain;
    /* no is the number of no votes on a proposal. */
    pb_callback_t no;
    /* no_with_veto is the number of no with veto votes on a proposal. */
    pb_callback_t no_with_veto;
} cosmos_gov_v1beta1_TallyResult;

/* Proposal defines the core field members of a governance proposal. */
typedef struct _cosmos_gov_v1beta1_Proposal {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* content is the proposal's content. */
    bool has_content;
    google_protobuf_Any content;
    /* status defines the proposal status. */
    cosmos_gov_v1beta1_ProposalStatus status;
    /* final_tally_result is the final tally result of the proposal. When
 querying a proposal via gRPC, this field is not populated until the
 proposal's voting period has ended. */
    bool has_final_tally_result;
    cosmos_gov_v1beta1_TallyResult final_tally_result;
    /* submit_time is the time of proposal submission. */
    bool has_submit_time;
    google_protobuf_Timestamp submit_time;
    /* deposit_end_time is the end time for deposition. */
    bool has_deposit_end_time;
    google_protobuf_Timestamp deposit_end_time;
    /* total_deposit is the total deposit on the proposal. */
    pb_callback_t total_deposit;
    /* voting_start_time is the starting time to vote on a proposal. */
    bool has_voting_start_time;
    google_protobuf_Timestamp voting_start_time;
    /* voting_end_time is the end time of voting on a proposal. */
    bool has_voting_end_time;
    google_protobuf_Timestamp voting_end_time;
} cosmos_gov_v1beta1_Proposal;

/* Vote defines a vote on a governance proposal.
 A Vote consists of a proposal ID, the voter, and the vote option. */
typedef struct _cosmos_gov_v1beta1_Vote {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* voter is the voter address of the proposal. */
    pb_callback_t voter;
    /* Deprecated: Prefer to use `options` instead. This field is set in queries
 if and only if `len(options) == 1` and that option has weight 1. In all
 other cases, this field will default to VOTE_OPTION_UNSPECIFIED. */
    cosmos_gov_v1beta1_VoteOption option;
    /* options is the weighted vote options.

 Since: cosmos-sdk 0.43 */
    pb_callback_t options;
} cosmos_gov_v1beta1_Vote;

/* DepositParams defines the params for deposits on governance proposals. */
typedef struct _cosmos_gov_v1beta1_DepositParams {
    /* Minimum deposit for a proposal to enter voting period. */
    pb_callback_t min_deposit;
    /* Maximum period for Atom holders to deposit on a proposal. Initial value: 2
 months. */
    bool has_max_deposit_period;
    google_protobuf_Duration max_deposit_period;
} cosmos_gov_v1beta1_DepositParams;

/* VotingParams defines the params for voting on governance proposals. */
typedef struct _cosmos_gov_v1beta1_VotingParams {
    /* Duration of the voting period. */
    bool has_voting_period;
    google_protobuf_Duration voting_period;
} cosmos_gov_v1beta1_VotingParams;

/* TallyParams defines the params for tallying votes on governance proposals. */
typedef struct _cosmos_gov_v1beta1_TallyParams {
    /* Minimum percentage of total stake needed to vote for a result to be
 considered valid. */
    pb_callback_t quorum;
    /* Minimum proportion of Yes votes for proposal to pass. Default value: 0.5. */
    pb_callback_t threshold;
    /* Minimum value of Veto votes to Total votes ratio for proposal to be
 vetoed. Default value: 1/3. */
    pb_callback_t veto_threshold;
} cosmos_gov_v1beta1_TallyParams;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _cosmos_gov_v1beta1_VoteOption_MIN cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_UNSPECIFIED
#define _cosmos_gov_v1beta1_VoteOption_MAX cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_NO_WITH_VETO
#define _cosmos_gov_v1beta1_VoteOption_ARRAYSIZE \
    ((cosmos_gov_v1beta1_VoteOption)(cosmos_gov_v1beta1_VoteOption_VOTE_OPTION_NO_WITH_VETO + 1))

#define _cosmos_gov_v1beta1_ProposalStatus_MIN cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_UNSPECIFIED
#define _cosmos_gov_v1beta1_ProposalStatus_MAX cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_FAILED
#define _cosmos_gov_v1beta1_ProposalStatus_ARRAYSIZE \
    ((cosmos_gov_v1beta1_ProposalStatus)(cosmos_gov_v1beta1_ProposalStatus_PROPOSAL_STATUS_FAILED + 1))

#define cosmos_gov_v1beta1_WeightedVoteOption_option_ENUMTYPE cosmos_gov_v1beta1_VoteOption

#define cosmos_gov_v1beta1_Proposal_status_ENUMTYPE cosmos_gov_v1beta1_ProposalStatus

#define cosmos_gov_v1beta1_Vote_option_ENUMTYPE cosmos_gov_v1beta1_VoteOption

/* Initializer values for message structs */
#define cosmos_gov_v1beta1_WeightedVoteOption_init_default   \
    {                                                        \
        _cosmos_gov_v1beta1_VoteOption_MIN, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_TextProposal_init_default \
    {                                                \
        {{NULL}, NULL}, { {NULL}, NULL }             \
    }
#define cosmos_gov_v1beta1_Deposit_init_default \
    {                                           \
        0, {{NULL}, NULL}, { {NULL}, NULL }     \
    }
#define cosmos_gov_v1beta1_Proposal_init_default                                                                          \
    {                                                                                                                     \
        0, false, google_protobuf_Any_init_default, _cosmos_gov_v1beta1_ProposalStatus_MIN, false,                        \
            cosmos_gov_v1beta1_TallyResult_init_default, false, google_protobuf_Timestamp_init_default, false,            \
            google_protobuf_Timestamp_init_default, {{NULL}, NULL}, false, google_protobuf_Timestamp_init_default, false, \
            google_protobuf_Timestamp_init_default                                                                        \
    }
#define cosmos_gov_v1beta1_TallyResult_init_default                      \
    {                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_Vote_init_default                                    \
    {                                                                           \
        0, {{NULL}, NULL}, _cosmos_gov_v1beta1_VoteOption_MIN, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_DepositParams_init_default \
    { {{NULL}, NULL}, false, google_protobuf_Duration_init_default }
#define cosmos_gov_v1beta1_VotingParams_init_default \
    { false, google_protobuf_Duration_init_default }
#define cosmos_gov_v1beta1_TallyParams_init_default      \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_WeightedVoteOption_init_zero      \
    {                                                        \
        _cosmos_gov_v1beta1_VoteOption_MIN, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_TextProposal_init_zero \
    {                                             \
        {{NULL}, NULL}, { {NULL}, NULL }          \
    }
#define cosmos_gov_v1beta1_Deposit_init_zero \
    {                                        \
        0, {{NULL}, NULL}, { {NULL}, NULL }  \
    }
#define cosmos_gov_v1beta1_Proposal_init_zero                                                                       \
    {                                                                                                               \
        0, false, google_protobuf_Any_init_zero, _cosmos_gov_v1beta1_ProposalStatus_MIN, false,                     \
            cosmos_gov_v1beta1_TallyResult_init_zero, false, google_protobuf_Timestamp_init_zero, false,            \
            google_protobuf_Timestamp_init_zero, {{NULL}, NULL}, false, google_protobuf_Timestamp_init_zero, false, \
            google_protobuf_Timestamp_init_zero                                                                     \
    }
#define cosmos_gov_v1beta1_TallyResult_init_zero                         \
    {                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_Vote_init_zero                                       \
    {                                                                           \
        0, {{NULL}, NULL}, _cosmos_gov_v1beta1_VoteOption_MIN, { {NULL}, NULL } \
    }
#define cosmos_gov_v1beta1_DepositParams_init_zero \
    { {{NULL}, NULL}, false, google_protobuf_Duration_init_zero }
#define cosmos_gov_v1beta1_VotingParams_init_zero \
    { false, google_protobuf_Duration_init_zero }
#define cosmos_gov_v1beta1_TallyParams_init_zero         \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_gov_v1beta1_WeightedVoteOption_option_tag 1
#define cosmos_gov_v1beta1_WeightedVoteOption_weight_tag 2
#define cosmos_gov_v1beta1_TextProposal_title_tag 1
#define cosmos_gov_v1beta1_TextProposal_description_tag 2
#define cosmos_gov_v1beta1_Deposit_proposal_id_tag 1
#define cosmos_gov_v1beta1_Deposit_depositor_tag 2
#define cosmos_gov_v1beta1_Deposit_amount_tag 3
#define cosmos_gov_v1beta1_TallyResult_yes_tag 1
#define cosmos_gov_v1beta1_TallyResult_abstain_tag 2
#define cosmos_gov_v1beta1_TallyResult_no_tag 3
#define cosmos_gov_v1beta1_TallyResult_no_with_veto_tag 4
#define cosmos_gov_v1beta1_Proposal_proposal_id_tag 1
#define cosmos_gov_v1beta1_Proposal_content_tag 2
#define cosmos_gov_v1beta1_Proposal_status_tag 3
#define cosmos_gov_v1beta1_Proposal_final_tally_result_tag 4
#define cosmos_gov_v1beta1_Proposal_submit_time_tag 5
#define cosmos_gov_v1beta1_Proposal_deposit_end_time_tag 6
#define cosmos_gov_v1beta1_Proposal_total_deposit_tag 7
#define cosmos_gov_v1beta1_Proposal_voting_start_time_tag 8
#define cosmos_gov_v1beta1_Proposal_voting_end_time_tag 9
#define cosmos_gov_v1beta1_Vote_proposal_id_tag 1
#define cosmos_gov_v1beta1_Vote_voter_tag 2
#define cosmos_gov_v1beta1_Vote_option_tag 3
#define cosmos_gov_v1beta1_Vote_options_tag 4
#define cosmos_gov_v1beta1_DepositParams_min_deposit_tag 1
#define cosmos_gov_v1beta1_DepositParams_max_deposit_period_tag 2
#define cosmos_gov_v1beta1_VotingParams_voting_period_tag 1
#define cosmos_gov_v1beta1_TallyParams_quorum_tag 1
#define cosmos_gov_v1beta1_TallyParams_threshold_tag 2
#define cosmos_gov_v1beta1_TallyParams_veto_threshold_tag 3

/* Struct field encoding specification for nanopb */
#define cosmos_gov_v1beta1_WeightedVoteOption_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UENUM, option, 1)                  \
    X(a, CALLBACK, SINGULAR, STRING, weight, 2)
#define cosmos_gov_v1beta1_WeightedVoteOption_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_WeightedVoteOption_DEFAULT NULL

#define cosmos_gov_v1beta1_TextProposal_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, title, 1)          \
    X(a, CALLBACK, SINGULAR, STRING, description, 2)
#define cosmos_gov_v1beta1_TextProposal_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_TextProposal_DEFAULT NULL

#define cosmos_gov_v1beta1_Deposit_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1) \
    X(a, CALLBACK, SINGULAR, STRING, depositor, 2) \
    X(a, CALLBACK, REPEATED, MESSAGE, amount, 3)
#define cosmos_gov_v1beta1_Deposit_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_Deposit_DEFAULT NULL
#define cosmos_gov_v1beta1_Deposit_amount_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_gov_v1beta1_Proposal_FIELDLIST(X, a)        \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)         \
    X(a, STATIC, OPTIONAL, MESSAGE, content, 2)            \
    X(a, STATIC, SINGULAR, UENUM, status, 3)               \
    X(a, STATIC, OPTIONAL, MESSAGE, final_tally_result, 4) \
    X(a, STATIC, OPTIONAL, MESSAGE, submit_time, 5)        \
    X(a, STATIC, OPTIONAL, MESSAGE, deposit_end_time, 6)   \
    X(a, CALLBACK, REPEATED, MESSAGE, total_deposit, 7)    \
    X(a, STATIC, OPTIONAL, MESSAGE, voting_start_time, 8)  \
    X(a, STATIC, OPTIONAL, MESSAGE, voting_end_time, 9)
#define cosmos_gov_v1beta1_Proposal_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_Proposal_DEFAULT NULL
#define cosmos_gov_v1beta1_Proposal_content_MSGTYPE google_protobuf_Any
#define cosmos_gov_v1beta1_Proposal_final_tally_result_MSGTYPE cosmos_gov_v1beta1_TallyResult
#define cosmos_gov_v1beta1_Proposal_submit_time_MSGTYPE google_protobuf_Timestamp
#define cosmos_gov_v1beta1_Proposal_deposit_end_time_MSGTYPE google_protobuf_Timestamp
#define cosmos_gov_v1beta1_Proposal_total_deposit_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_gov_v1beta1_Proposal_voting_start_time_MSGTYPE google_protobuf_Timestamp
#define cosmos_gov_v1beta1_Proposal_voting_end_time_MSGTYPE google_protobuf_Timestamp

#define cosmos_gov_v1beta1_TallyResult_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, yes, 1)           \
    X(a, CALLBACK, SINGULAR, STRING, abstain, 2)       \
    X(a, CALLBACK, SINGULAR, STRING, no, 3)            \
    X(a, CALLBACK, SINGULAR, STRING, no_with_veto, 4)
#define cosmos_gov_v1beta1_TallyResult_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_TallyResult_DEFAULT NULL

#define cosmos_gov_v1beta1_Vote_FIELDLIST(X, a)    \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1) \
    X(a, CALLBACK, SINGULAR, STRING, voter, 2)     \
    X(a, STATIC, SINGULAR, UENUM, option, 3)       \
    X(a, CALLBACK, REPEATED, MESSAGE, options, 4)
#define cosmos_gov_v1beta1_Vote_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_Vote_DEFAULT NULL
#define cosmos_gov_v1beta1_Vote_options_MSGTYPE cosmos_gov_v1beta1_WeightedVoteOption

#define cosmos_gov_v1beta1_DepositParams_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, min_deposit, 1)    \
    X(a, STATIC, OPTIONAL, MESSAGE, max_deposit_period, 2)
#define cosmos_gov_v1beta1_DepositParams_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_DepositParams_DEFAULT NULL
#define cosmos_gov_v1beta1_DepositParams_min_deposit_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_gov_v1beta1_DepositParams_max_deposit_period_MSGTYPE google_protobuf_Duration

#define cosmos_gov_v1beta1_VotingParams_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, voting_period, 1)
#define cosmos_gov_v1beta1_VotingParams_CALLBACK NULL
#define cosmos_gov_v1beta1_VotingParams_DEFAULT NULL
#define cosmos_gov_v1beta1_VotingParams_voting_period_MSGTYPE google_protobuf_Duration

#define cosmos_gov_v1beta1_TallyParams_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, quorum, 1)         \
    X(a, CALLBACK, SINGULAR, BYTES, threshold, 2)      \
    X(a, CALLBACK, SINGULAR, BYTES, veto_threshold, 3)
#define cosmos_gov_v1beta1_TallyParams_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_TallyParams_DEFAULT NULL

extern const pb_msgdesc_t cosmos_gov_v1beta1_WeightedVoteOption_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_TextProposal_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_Deposit_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_Proposal_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_TallyResult_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_Vote_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_DepositParams_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_VotingParams_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_TallyParams_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_gov_v1beta1_WeightedVoteOption_fields &cosmos_gov_v1beta1_WeightedVoteOption_msg
#define cosmos_gov_v1beta1_TextProposal_fields &cosmos_gov_v1beta1_TextProposal_msg
#define cosmos_gov_v1beta1_Deposit_fields &cosmos_gov_v1beta1_Deposit_msg
#define cosmos_gov_v1beta1_Proposal_fields &cosmos_gov_v1beta1_Proposal_msg
#define cosmos_gov_v1beta1_TallyResult_fields &cosmos_gov_v1beta1_TallyResult_msg
#define cosmos_gov_v1beta1_Vote_fields &cosmos_gov_v1beta1_Vote_msg
#define cosmos_gov_v1beta1_DepositParams_fields &cosmos_gov_v1beta1_DepositParams_msg
#define cosmos_gov_v1beta1_VotingParams_fields &cosmos_gov_v1beta1_VotingParams_msg
#define cosmos_gov_v1beta1_TallyParams_fields &cosmos_gov_v1beta1_TallyParams_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_gov_v1beta1_WeightedVoteOption_size depends on runtime parameters */
/* cosmos_gov_v1beta1_TextProposal_size depends on runtime parameters */
/* cosmos_gov_v1beta1_Deposit_size depends on runtime parameters */
/* cosmos_gov_v1beta1_Proposal_size depends on runtime parameters */
/* cosmos_gov_v1beta1_TallyResult_size depends on runtime parameters */
/* cosmos_gov_v1beta1_Vote_size depends on runtime parameters */
/* cosmos_gov_v1beta1_DepositParams_size depends on runtime parameters */
/* cosmos_gov_v1beta1_TallyParams_size depends on runtime parameters */
#define COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_GOV_PB_H_MAX_SIZE cosmos_gov_v1beta1_VotingParams_size
#define cosmos_gov_v1beta1_VotingParams_size 24

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif