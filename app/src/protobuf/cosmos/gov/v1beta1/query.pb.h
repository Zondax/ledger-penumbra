/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/base/query/v1beta1/pagination.pb.h"
#include "cosmos/gov/v1beta1/gov.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/api/annotations.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* QueryProposalRequest is the request type for the Query/Proposal RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryProposalRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
} cosmos_gov_v1beta1_QueryProposalRequest;

/* QueryProposalResponse is the response type for the Query/Proposal RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryProposalResponse {
    bool has_proposal;
    cosmos_gov_v1beta1_Proposal proposal;
} cosmos_gov_v1beta1_QueryProposalResponse;

/* QueryProposalsRequest is the request type for the Query/Proposals RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryProposalsRequest {
    /* proposal_status defines the status of the proposals. */
    cosmos_gov_v1beta1_ProposalStatus proposal_status;
    /* voter defines the voter address for the proposals. */
    pb_callback_t voter;
    /* depositor defines the deposit addresses from the proposals. */
    pb_callback_t depositor;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_gov_v1beta1_QueryProposalsRequest;

/* QueryProposalsResponse is the response type for the Query/Proposals RPC
 method. */
typedef struct _cosmos_gov_v1beta1_QueryProposalsResponse {
    /* proposals defines all the requested governance proposals. */
    pb_callback_t proposals;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_gov_v1beta1_QueryProposalsResponse;

/* QueryVoteRequest is the request type for the Query/Vote RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryVoteRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* voter defines the voter address for the proposals. */
    pb_callback_t voter;
} cosmos_gov_v1beta1_QueryVoteRequest;

/* QueryVoteResponse is the response type for the Query/Vote RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryVoteResponse {
    /* vote defines the queried vote. */
    bool has_vote;
    cosmos_gov_v1beta1_Vote vote;
} cosmos_gov_v1beta1_QueryVoteResponse;

/* QueryVotesRequest is the request type for the Query/Votes RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryVotesRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_gov_v1beta1_QueryVotesRequest;

/* QueryVotesResponse is the response type for the Query/Votes RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryVotesResponse {
    /* votes defines the queried votes. */
    pb_callback_t votes;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_gov_v1beta1_QueryVotesResponse;

/* QueryParamsRequest is the request type for the Query/Params RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryParamsRequest {
    /* params_type defines which parameters to query for, can be one of "voting",
 "tallying" or "deposit". */
    pb_callback_t params_type;
} cosmos_gov_v1beta1_QueryParamsRequest;

/* QueryParamsResponse is the response type for the Query/Params RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryParamsResponse {
    /* voting_params defines the parameters related to voting. */
    bool has_voting_params;
    cosmos_gov_v1beta1_VotingParams voting_params;
    /* deposit_params defines the parameters related to deposit. */
    bool has_deposit_params;
    cosmos_gov_v1beta1_DepositParams deposit_params;
    /* tally_params defines the parameters related to tally. */
    bool has_tally_params;
    cosmos_gov_v1beta1_TallyParams tally_params;
} cosmos_gov_v1beta1_QueryParamsResponse;

/* QueryDepositRequest is the request type for the Query/Deposit RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryDepositRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* depositor defines the deposit addresses from the proposals. */
    pb_callback_t depositor;
} cosmos_gov_v1beta1_QueryDepositRequest;

/* QueryDepositResponse is the response type for the Query/Deposit RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryDepositResponse {
    /* deposit defines the requested deposit. */
    bool has_deposit;
    cosmos_gov_v1beta1_Deposit deposit;
} cosmos_gov_v1beta1_QueryDepositResponse;

/* QueryDepositsRequest is the request type for the Query/Deposits RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryDepositsRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_gov_v1beta1_QueryDepositsRequest;

/* QueryDepositsResponse is the response type for the Query/Deposits RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryDepositsResponse {
    /* deposits defines the requested deposits. */
    pb_callback_t deposits;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_gov_v1beta1_QueryDepositsResponse;

/* QueryTallyResultRequest is the request type for the Query/Tally RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryTallyResultRequest {
    /* proposal_id defines the unique id of the proposal. */
    uint64_t proposal_id;
} cosmos_gov_v1beta1_QueryTallyResultRequest;

/* QueryTallyResultResponse is the response type for the Query/Tally RPC method. */
typedef struct _cosmos_gov_v1beta1_QueryTallyResultResponse {
    /* tally defines the requested tally. */
    bool has_tally;
    cosmos_gov_v1beta1_TallyResult tally;
} cosmos_gov_v1beta1_QueryTallyResultResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_gov_v1beta1_QueryProposalRequest_init_default \
    { 0 }
#define cosmos_gov_v1beta1_QueryProposalResponse_init_default \
    { false, cosmos_gov_v1beta1_Proposal_init_default }
#define cosmos_gov_v1beta1_QueryProposalsRequest_init_default                          \
    {                                                                                  \
        _cosmos_gov_v1beta1_ProposalStatus_MIN, {{NULL}, NULL}, {{NULL}, NULL}, false, \
            cosmos_base_query_v1beta1_PageRequest_init_default                         \
    }
#define cosmos_gov_v1beta1_QueryProposalsResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_gov_v1beta1_QueryVoteRequest_init_default \
    {                                                    \
        0, { {NULL}, NULL }                              \
    }
#define cosmos_gov_v1beta1_QueryVoteResponse_init_default \
    { false, cosmos_gov_v1beta1_Vote_init_default }
#define cosmos_gov_v1beta1_QueryVotesRequest_init_default \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_gov_v1beta1_QueryVotesResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_gov_v1beta1_QueryParamsRequest_init_default \
    {                                                      \
        { {NULL}, NULL }                                   \
    }
#define cosmos_gov_v1beta1_QueryParamsResponse_init_default                                                               \
    {                                                                                                                     \
        false, cosmos_gov_v1beta1_VotingParams_init_default, false, cosmos_gov_v1beta1_DepositParams_init_default, false, \
            cosmos_gov_v1beta1_TallyParams_init_default                                                                   \
    }
#define cosmos_gov_v1beta1_QueryDepositRequest_init_default \
    {                                                       \
        0, { {NULL}, NULL }                                 \
    }
#define cosmos_gov_v1beta1_QueryDepositResponse_init_default \
    { false, cosmos_gov_v1beta1_Deposit_init_default }
#define cosmos_gov_v1beta1_QueryDepositsRequest_init_default \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_gov_v1beta1_QueryDepositsResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_gov_v1beta1_QueryTallyResultRequest_init_default \
    { 0 }
#define cosmos_gov_v1beta1_QueryTallyResultResponse_init_default \
    { false, cosmos_gov_v1beta1_TallyResult_init_default }
#define cosmos_gov_v1beta1_QueryProposalRequest_init_zero \
    { 0 }
#define cosmos_gov_v1beta1_QueryProposalResponse_init_zero \
    { false, cosmos_gov_v1beta1_Proposal_init_zero }
#define cosmos_gov_v1beta1_QueryProposalsRequest_init_zero                             \
    {                                                                                  \
        _cosmos_gov_v1beta1_ProposalStatus_MIN, {{NULL}, NULL}, {{NULL}, NULL}, false, \
            cosmos_base_query_v1beta1_PageRequest_init_zero                            \
    }
#define cosmos_gov_v1beta1_QueryProposalsResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_gov_v1beta1_QueryVoteRequest_init_zero \
    {                                                 \
        0, { {NULL}, NULL }                           \
    }
#define cosmos_gov_v1beta1_QueryVoteResponse_init_zero \
    { false, cosmos_gov_v1beta1_Vote_init_zero }
#define cosmos_gov_v1beta1_QueryVotesRequest_init_zero \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_gov_v1beta1_QueryVotesResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_gov_v1beta1_QueryParamsRequest_init_zero \
    {                                                   \
        { {NULL}, NULL }                                \
    }
#define cosmos_gov_v1beta1_QueryParamsResponse_init_zero                                                            \
    {                                                                                                               \
        false, cosmos_gov_v1beta1_VotingParams_init_zero, false, cosmos_gov_v1beta1_DepositParams_init_zero, false, \
            cosmos_gov_v1beta1_TallyParams_init_zero                                                                \
    }
#define cosmos_gov_v1beta1_QueryDepositRequest_init_zero \
    {                                                    \
        0, { {NULL}, NULL }                              \
    }
#define cosmos_gov_v1beta1_QueryDepositResponse_init_zero \
    { false, cosmos_gov_v1beta1_Deposit_init_zero }
#define cosmos_gov_v1beta1_QueryDepositsRequest_init_zero \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_gov_v1beta1_QueryDepositsResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_gov_v1beta1_QueryTallyResultRequest_init_zero \
    { 0 }
#define cosmos_gov_v1beta1_QueryTallyResultResponse_init_zero \
    { false, cosmos_gov_v1beta1_TallyResult_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_gov_v1beta1_QueryProposalRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryProposalResponse_proposal_tag 1
#define cosmos_gov_v1beta1_QueryProposalsRequest_proposal_status_tag 1
#define cosmos_gov_v1beta1_QueryProposalsRequest_voter_tag 2
#define cosmos_gov_v1beta1_QueryProposalsRequest_depositor_tag 3
#define cosmos_gov_v1beta1_QueryProposalsRequest_pagination_tag 4
#define cosmos_gov_v1beta1_QueryProposalsResponse_proposals_tag 1
#define cosmos_gov_v1beta1_QueryProposalsResponse_pagination_tag 2
#define cosmos_gov_v1beta1_QueryVoteRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryVoteRequest_voter_tag 2
#define cosmos_gov_v1beta1_QueryVoteResponse_vote_tag 1
#define cosmos_gov_v1beta1_QueryVotesRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryVotesRequest_pagination_tag 2
#define cosmos_gov_v1beta1_QueryVotesResponse_votes_tag 1
#define cosmos_gov_v1beta1_QueryVotesResponse_pagination_tag 2
#define cosmos_gov_v1beta1_QueryParamsRequest_params_type_tag 1
#define cosmos_gov_v1beta1_QueryParamsResponse_voting_params_tag 1
#define cosmos_gov_v1beta1_QueryParamsResponse_deposit_params_tag 2
#define cosmos_gov_v1beta1_QueryParamsResponse_tally_params_tag 3
#define cosmos_gov_v1beta1_QueryDepositRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryDepositRequest_depositor_tag 2
#define cosmos_gov_v1beta1_QueryDepositResponse_deposit_tag 1
#define cosmos_gov_v1beta1_QueryDepositsRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryDepositsRequest_pagination_tag 2
#define cosmos_gov_v1beta1_QueryDepositsResponse_deposits_tag 1
#define cosmos_gov_v1beta1_QueryDepositsResponse_pagination_tag 2
#define cosmos_gov_v1beta1_QueryTallyResultRequest_proposal_id_tag 1
#define cosmos_gov_v1beta1_QueryTallyResultResponse_tally_tag 1

/* Struct field encoding specification for nanopb */
#define cosmos_gov_v1beta1_QueryProposalRequest_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)
#define cosmos_gov_v1beta1_QueryProposalRequest_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryProposalRequest_DEFAULT NULL

#define cosmos_gov_v1beta1_QueryProposalResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, proposal, 1)
#define cosmos_gov_v1beta1_QueryProposalResponse_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryProposalResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryProposalResponse_proposal_MSGTYPE cosmos_gov_v1beta1_Proposal

#define cosmos_gov_v1beta1_QueryProposalsRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UENUM, proposal_status, 1)            \
    X(a, CALLBACK, SINGULAR, STRING, voter, 2)                   \
    X(a, CALLBACK, SINGULAR, STRING, depositor, 3)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 4)
#define cosmos_gov_v1beta1_QueryProposalsRequest_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryProposalsRequest_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryProposalsRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_gov_v1beta1_QueryProposalsResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, proposals, 1)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_gov_v1beta1_QueryProposalsResponse_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryProposalsResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryProposalsResponse_proposals_MSGTYPE cosmos_gov_v1beta1_Proposal
#define cosmos_gov_v1beta1_QueryProposalsResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_gov_v1beta1_QueryVoteRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)          \
    X(a, CALLBACK, SINGULAR, STRING, voter, 2)
#define cosmos_gov_v1beta1_QueryVoteRequest_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryVoteRequest_DEFAULT NULL

#define cosmos_gov_v1beta1_QueryVoteResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, vote, 1)
#define cosmos_gov_v1beta1_QueryVoteResponse_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryVoteResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryVoteResponse_vote_MSGTYPE cosmos_gov_v1beta1_Vote

#define cosmos_gov_v1beta1_QueryVotesRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)           \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_gov_v1beta1_QueryVotesRequest_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryVotesRequest_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryVotesRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_gov_v1beta1_QueryVotesResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, votes, 1)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_gov_v1beta1_QueryVotesResponse_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryVotesResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryVotesResponse_votes_MSGTYPE cosmos_gov_v1beta1_Vote
#define cosmos_gov_v1beta1_QueryVotesResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_gov_v1beta1_QueryParamsRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, params_type, 1)
#define cosmos_gov_v1beta1_QueryParamsRequest_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryParamsRequest_DEFAULT NULL

#define cosmos_gov_v1beta1_QueryParamsResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, voting_params, 1)          \
    X(a, STATIC, OPTIONAL, MESSAGE, deposit_params, 2)         \
    X(a, STATIC, OPTIONAL, MESSAGE, tally_params, 3)
#define cosmos_gov_v1beta1_QueryParamsResponse_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryParamsResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryParamsResponse_voting_params_MSGTYPE cosmos_gov_v1beta1_VotingParams
#define cosmos_gov_v1beta1_QueryParamsResponse_deposit_params_MSGTYPE cosmos_gov_v1beta1_DepositParams
#define cosmos_gov_v1beta1_QueryParamsResponse_tally_params_MSGTYPE cosmos_gov_v1beta1_TallyParams

#define cosmos_gov_v1beta1_QueryDepositRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)             \
    X(a, CALLBACK, SINGULAR, STRING, depositor, 2)
#define cosmos_gov_v1beta1_QueryDepositRequest_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryDepositRequest_DEFAULT NULL

#define cosmos_gov_v1beta1_QueryDepositResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, deposit, 1)
#define cosmos_gov_v1beta1_QueryDepositResponse_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryDepositResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryDepositResponse_deposit_MSGTYPE cosmos_gov_v1beta1_Deposit

#define cosmos_gov_v1beta1_QueryDepositsRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_gov_v1beta1_QueryDepositsRequest_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryDepositsRequest_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryDepositsRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_gov_v1beta1_QueryDepositsResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, deposits, 1)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_gov_v1beta1_QueryDepositsResponse_CALLBACK pb_default_field_callback
#define cosmos_gov_v1beta1_QueryDepositsResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryDepositsResponse_deposits_MSGTYPE cosmos_gov_v1beta1_Deposit
#define cosmos_gov_v1beta1_QueryDepositsResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_gov_v1beta1_QueryTallyResultRequest_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UINT64, proposal_id, 1)
#define cosmos_gov_v1beta1_QueryTallyResultRequest_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryTallyResultRequest_DEFAULT NULL

#define cosmos_gov_v1beta1_QueryTallyResultResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, tally, 1)
#define cosmos_gov_v1beta1_QueryTallyResultResponse_CALLBACK NULL
#define cosmos_gov_v1beta1_QueryTallyResultResponse_DEFAULT NULL
#define cosmos_gov_v1beta1_QueryTallyResultResponse_tally_MSGTYPE cosmos_gov_v1beta1_TallyResult

extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryProposalRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryProposalResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryProposalsRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryProposalsResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryVoteRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryVoteResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryVotesRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryVotesResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryParamsRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryParamsResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryDepositRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryDepositResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryDepositsRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryDepositsResponse_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryTallyResultRequest_msg;
extern const pb_msgdesc_t cosmos_gov_v1beta1_QueryTallyResultResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_gov_v1beta1_QueryProposalRequest_fields &cosmos_gov_v1beta1_QueryProposalRequest_msg
#define cosmos_gov_v1beta1_QueryProposalResponse_fields &cosmos_gov_v1beta1_QueryProposalResponse_msg
#define cosmos_gov_v1beta1_QueryProposalsRequest_fields &cosmos_gov_v1beta1_QueryProposalsRequest_msg
#define cosmos_gov_v1beta1_QueryProposalsResponse_fields &cosmos_gov_v1beta1_QueryProposalsResponse_msg
#define cosmos_gov_v1beta1_QueryVoteRequest_fields &cosmos_gov_v1beta1_QueryVoteRequest_msg
#define cosmos_gov_v1beta1_QueryVoteResponse_fields &cosmos_gov_v1beta1_QueryVoteResponse_msg
#define cosmos_gov_v1beta1_QueryVotesRequest_fields &cosmos_gov_v1beta1_QueryVotesRequest_msg
#define cosmos_gov_v1beta1_QueryVotesResponse_fields &cosmos_gov_v1beta1_QueryVotesResponse_msg
#define cosmos_gov_v1beta1_QueryParamsRequest_fields &cosmos_gov_v1beta1_QueryParamsRequest_msg
#define cosmos_gov_v1beta1_QueryParamsResponse_fields &cosmos_gov_v1beta1_QueryParamsResponse_msg
#define cosmos_gov_v1beta1_QueryDepositRequest_fields &cosmos_gov_v1beta1_QueryDepositRequest_msg
#define cosmos_gov_v1beta1_QueryDepositResponse_fields &cosmos_gov_v1beta1_QueryDepositResponse_msg
#define cosmos_gov_v1beta1_QueryDepositsRequest_fields &cosmos_gov_v1beta1_QueryDepositsRequest_msg
#define cosmos_gov_v1beta1_QueryDepositsResponse_fields &cosmos_gov_v1beta1_QueryDepositsResponse_msg
#define cosmos_gov_v1beta1_QueryTallyResultRequest_fields &cosmos_gov_v1beta1_QueryTallyResultRequest_msg
#define cosmos_gov_v1beta1_QueryTallyResultResponse_fields &cosmos_gov_v1beta1_QueryTallyResultResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_gov_v1beta1_QueryProposalsRequest_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryProposalsResponse_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryVoteRequest_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryVotesResponse_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryParamsRequest_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryDepositRequest_size depends on runtime parameters */
/* cosmos_gov_v1beta1_QueryDepositsResponse_size depends on runtime parameters */
#define cosmos_gov_v1beta1_QueryProposalRequest_size 11
#define cosmos_gov_v1beta1_QueryTallyResultRequest_size 11
#if defined(cosmos_gov_v1beta1_Proposal_size)
#define cosmos_gov_v1beta1_QueryProposalResponse_size (6 + cosmos_gov_v1beta1_Proposal_size)
#endif
#if defined(cosmos_gov_v1beta1_Vote_size)
#define cosmos_gov_v1beta1_QueryVoteResponse_size (6 + cosmos_gov_v1beta1_Vote_size)
#endif
#if defined(cosmos_base_query_v1beta1_PageRequest_size)
#define cosmos_gov_v1beta1_QueryDepositsRequest_size (17 + cosmos_base_query_v1beta1_PageRequest_size)
#define cosmos_gov_v1beta1_QueryVotesRequest_size (17 + cosmos_base_query_v1beta1_PageRequest_size)
#endif
#if defined(cosmos_gov_v1beta1_DepositParams_size) && defined(cosmos_gov_v1beta1_TallyParams_size)
#define COSMOS_GOV_V1BETA1_COSMOS_GOV_V1BETA1_QUERY_PB_H_MAX_SIZE cosmos_gov_v1beta1_QueryParamsResponse_size
#define cosmos_gov_v1beta1_QueryParamsResponse_size \
    (38 + cosmos_gov_v1beta1_DepositParams_size + cosmos_gov_v1beta1_TallyParams_size)
#endif
#if defined(cosmos_gov_v1beta1_Deposit_size)
#define cosmos_gov_v1beta1_QueryDepositResponse_size (6 + cosmos_gov_v1beta1_Deposit_size)
#endif
#if defined(cosmos_gov_v1beta1_TallyResult_size)
#define cosmos_gov_v1beta1_QueryTallyResultResponse_size (6 + cosmos_gov_v1beta1_TallyResult_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
