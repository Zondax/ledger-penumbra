/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_CORE_CLIENT_V1_IBC_CORE_CLIENT_V1_QUERY_PB_H_INCLUDED
#define PB_IBC_CORE_CLIENT_V1_IBC_CORE_CLIENT_V1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/base/query/v1beta1/pagination.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/api/annotations.pb.h"
#include "google/protobuf/any.pb.h"
#include "ibc/core/client/v1/client.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* QueryClientStateRequest is the request type for the Query/ClientState RPC
 method */
typedef struct _ibc_core_client_v1_QueryClientStateRequest {
    /* client state unique identifier */
    pb_callback_t client_id;
} ibc_core_client_v1_QueryClientStateRequest;

/* QueryClientStateResponse is the response type for the Query/ClientState RPC
 method. Besides the client state, it includes a proof and the height from
 which the proof was retrieved. */
typedef struct _ibc_core_client_v1_QueryClientStateResponse {
    /* client state associated with the request identifier */
    bool has_client_state;
    google_protobuf_Any client_state;
    /* merkle proof of existence */
    pb_callback_t proof;
    /* height at which the proof was retrieved */
    bool has_proof_height;
    ibc_core_client_v1_Height proof_height;
} ibc_core_client_v1_QueryClientStateResponse;

/* QueryClientStatesRequest is the request type for the Query/ClientStates RPC
 method */
typedef struct _ibc_core_client_v1_QueryClientStatesRequest {
    /* pagination request */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} ibc_core_client_v1_QueryClientStatesRequest;

/* QueryClientStatesResponse is the response type for the Query/ClientStates RPC
 method. */
typedef struct _ibc_core_client_v1_QueryClientStatesResponse {
    /* list of stored ClientStates of the chain. */
    pb_callback_t client_states;
    /* pagination response */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} ibc_core_client_v1_QueryClientStatesResponse;

/* QueryConsensusStateRequest is the request type for the Query/ConsensusState
 RPC method. Besides the consensus state, it includes a proof and the height
 from which the proof was retrieved. */
typedef struct _ibc_core_client_v1_QueryConsensusStateRequest {
    /* client identifier */
    pb_callback_t client_id;
    /* consensus state revision number */
    uint64_t revision_number;
    /* consensus state revision height */
    uint64_t revision_height;
    /* latest_height overrrides the height field and queries the latest stored
 ConsensusState */
    bool latest_height;
} ibc_core_client_v1_QueryConsensusStateRequest;

/* QueryConsensusStateResponse is the response type for the Query/ConsensusState
 RPC method */
typedef struct _ibc_core_client_v1_QueryConsensusStateResponse {
    /* consensus state associated with the client identifier at the given height */
    bool has_consensus_state;
    google_protobuf_Any consensus_state;
    /* merkle proof of existence */
    pb_callback_t proof;
    /* height at which the proof was retrieved */
    bool has_proof_height;
    ibc_core_client_v1_Height proof_height;
} ibc_core_client_v1_QueryConsensusStateResponse;

/* QueryConsensusStatesRequest is the request type for the Query/ConsensusStates
 RPC method. */
typedef struct _ibc_core_client_v1_QueryConsensusStatesRequest {
    /* client identifier */
    pb_callback_t client_id;
    /* pagination request */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} ibc_core_client_v1_QueryConsensusStatesRequest;

/* QueryConsensusStatesResponse is the response type for the
 Query/ConsensusStates RPC method */
typedef struct _ibc_core_client_v1_QueryConsensusStatesResponse {
    /* consensus states associated with the identifier */
    pb_callback_t consensus_states;
    /* pagination response */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} ibc_core_client_v1_QueryConsensusStatesResponse;

/* QueryConsensusStateHeightsRequest is the request type for Query/ConsensusStateHeights
 RPC method. */
typedef struct _ibc_core_client_v1_QueryConsensusStateHeightsRequest {
    /* client identifier */
    pb_callback_t client_id;
    /* pagination request */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} ibc_core_client_v1_QueryConsensusStateHeightsRequest;

/* QueryConsensusStateHeightsResponse is the response type for the
 Query/ConsensusStateHeights RPC method */
typedef struct _ibc_core_client_v1_QueryConsensusStateHeightsResponse {
    /* consensus state heights */
    pb_callback_t consensus_state_heights;
    /* pagination response */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} ibc_core_client_v1_QueryConsensusStateHeightsResponse;

/* QueryClientStatusRequest is the request type for the Query/ClientStatus RPC
 method */
typedef struct _ibc_core_client_v1_QueryClientStatusRequest {
    /* client unique identifier */
    pb_callback_t client_id;
} ibc_core_client_v1_QueryClientStatusRequest;

/* QueryClientStatusResponse is the response type for the Query/ClientStatus RPC
 method. It returns the current status of the IBC client. */
typedef struct _ibc_core_client_v1_QueryClientStatusResponse {
    pb_callback_t status;
} ibc_core_client_v1_QueryClientStatusResponse;

/* QueryClientParamsRequest is the request type for the Query/ClientParams RPC
 method. */
typedef struct _ibc_core_client_v1_QueryClientParamsRequest {
    char dummy_field;
} ibc_core_client_v1_QueryClientParamsRequest;

/* QueryClientParamsResponse is the response type for the Query/ClientParams RPC
 method. */
typedef struct _ibc_core_client_v1_QueryClientParamsResponse {
    /* params defines the parameters of the module. */
    bool has_params;
    ibc_core_client_v1_Params params;
} ibc_core_client_v1_QueryClientParamsResponse;

/* QueryUpgradedClientStateRequest is the request type for the
 Query/UpgradedClientState RPC method */
typedef struct _ibc_core_client_v1_QueryUpgradedClientStateRequest {
    char dummy_field;
} ibc_core_client_v1_QueryUpgradedClientStateRequest;

/* QueryUpgradedClientStateResponse is the response type for the
 Query/UpgradedClientState RPC method. */
typedef struct _ibc_core_client_v1_QueryUpgradedClientStateResponse {
    /* client state associated with the request identifier */
    bool has_upgraded_client_state;
    google_protobuf_Any upgraded_client_state;
} ibc_core_client_v1_QueryUpgradedClientStateResponse;

/* QueryUpgradedConsensusStateRequest is the request type for the
 Query/UpgradedConsensusState RPC method */
typedef struct _ibc_core_client_v1_QueryUpgradedConsensusStateRequest {
    char dummy_field;
} ibc_core_client_v1_QueryUpgradedConsensusStateRequest;

/* QueryUpgradedConsensusStateResponse is the response type for the
 Query/UpgradedConsensusState RPC method. */
typedef struct _ibc_core_client_v1_QueryUpgradedConsensusStateResponse {
    /* Consensus state associated with the request identifier */
    bool has_upgraded_consensus_state;
    google_protobuf_Any upgraded_consensus_state;
} ibc_core_client_v1_QueryUpgradedConsensusStateResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ibc_core_client_v1_QueryClientStateRequest_init_default \
    {                                                           \
        { {NULL}, NULL }                                        \
    }
#define ibc_core_client_v1_QueryClientStateResponse_init_default \
    { false, google_protobuf_Any_init_default, {{NULL}, NULL}, false, ibc_core_client_v1_Height_init_default }
#define ibc_core_client_v1_QueryClientStatesRequest_init_default \
    { false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define ibc_core_client_v1_QueryClientStatesResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define ibc_core_client_v1_QueryConsensusStateRequest_init_default \
    { {{NULL}, NULL}, 0, 0, 0 }
#define ibc_core_client_v1_QueryConsensusStateResponse_init_default \
    { false, google_protobuf_Any_init_default, {{NULL}, NULL}, false, ibc_core_client_v1_Height_init_default }
#define ibc_core_client_v1_QueryConsensusStatesRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define ibc_core_client_v1_QueryConsensusStatesResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define ibc_core_client_v1_QueryClientStatusRequest_init_default \
    {                                                            \
        { {NULL}, NULL }                                         \
    }
#define ibc_core_client_v1_QueryClientStatusResponse_init_default \
    {                                                             \
        { {NULL}, NULL }                                          \
    }
#define ibc_core_client_v1_QueryClientParamsRequest_init_default \
    { 0 }
#define ibc_core_client_v1_QueryClientParamsResponse_init_default \
    { false, ibc_core_client_v1_Params_init_default }
#define ibc_core_client_v1_QueryUpgradedClientStateRequest_init_default \
    { 0 }
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_init_default \
    { false, google_protobuf_Any_init_default }
#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_init_default \
    { 0 }
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_init_default \
    { false, google_protobuf_Any_init_default }
#define ibc_core_client_v1_QueryClientStateRequest_init_zero \
    {                                                        \
        { {NULL}, NULL }                                     \
    }
#define ibc_core_client_v1_QueryClientStateResponse_init_zero \
    { false, google_protobuf_Any_init_zero, {{NULL}, NULL}, false, ibc_core_client_v1_Height_init_zero }
#define ibc_core_client_v1_QueryClientStatesRequest_init_zero \
    { false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define ibc_core_client_v1_QueryClientStatesResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define ibc_core_client_v1_QueryConsensusStateRequest_init_zero \
    { {{NULL}, NULL}, 0, 0, 0 }
#define ibc_core_client_v1_QueryConsensusStateResponse_init_zero \
    { false, google_protobuf_Any_init_zero, {{NULL}, NULL}, false, ibc_core_client_v1_Height_init_zero }
#define ibc_core_client_v1_QueryConsensusStatesRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define ibc_core_client_v1_QueryConsensusStatesResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define ibc_core_client_v1_QueryClientStatusRequest_init_zero \
    {                                                         \
        { {NULL}, NULL }                                      \
    }
#define ibc_core_client_v1_QueryClientStatusResponse_init_zero \
    {                                                          \
        { {NULL}, NULL }                                       \
    }
#define ibc_core_client_v1_QueryClientParamsRequest_init_zero \
    { 0 }
#define ibc_core_client_v1_QueryClientParamsResponse_init_zero \
    { false, ibc_core_client_v1_Params_init_zero }
#define ibc_core_client_v1_QueryUpgradedClientStateRequest_init_zero \
    { 0 }
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_init_zero \
    { false, google_protobuf_Any_init_zero }
#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_init_zero \
    { 0 }
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_init_zero \
    { false, google_protobuf_Any_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_core_client_v1_QueryClientStateRequest_client_id_tag 1
#define ibc_core_client_v1_QueryClientStateResponse_client_state_tag 1
#define ibc_core_client_v1_QueryClientStateResponse_proof_tag 2
#define ibc_core_client_v1_QueryClientStateResponse_proof_height_tag 3
#define ibc_core_client_v1_QueryClientStatesRequest_pagination_tag 1
#define ibc_core_client_v1_QueryClientStatesResponse_client_states_tag 1
#define ibc_core_client_v1_QueryClientStatesResponse_pagination_tag 2
#define ibc_core_client_v1_QueryConsensusStateRequest_client_id_tag 1
#define ibc_core_client_v1_QueryConsensusStateRequest_revision_number_tag 2
#define ibc_core_client_v1_QueryConsensusStateRequest_revision_height_tag 3
#define ibc_core_client_v1_QueryConsensusStateRequest_latest_height_tag 4
#define ibc_core_client_v1_QueryConsensusStateResponse_consensus_state_tag 1
#define ibc_core_client_v1_QueryConsensusStateResponse_proof_tag 2
#define ibc_core_client_v1_QueryConsensusStateResponse_proof_height_tag 3
#define ibc_core_client_v1_QueryConsensusStatesRequest_client_id_tag 1
#define ibc_core_client_v1_QueryConsensusStatesRequest_pagination_tag 2
#define ibc_core_client_v1_QueryConsensusStatesResponse_consensus_states_tag 1
#define ibc_core_client_v1_QueryConsensusStatesResponse_pagination_tag 2
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_client_id_tag 1
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_pagination_tag 2
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_consensus_state_heights_tag 1
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_pagination_tag 2
#define ibc_core_client_v1_QueryClientStatusRequest_client_id_tag 1
#define ibc_core_client_v1_QueryClientStatusResponse_status_tag 1
#define ibc_core_client_v1_QueryClientParamsResponse_params_tag 1
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_upgraded_client_state_tag 1
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_upgraded_consensus_state_tag 1

/* Struct field encoding specification for nanopb */
#define ibc_core_client_v1_QueryClientStateRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, client_id, 1)
#define ibc_core_client_v1_QueryClientStateRequest_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryClientStateRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryClientStateResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, client_state, 1)                \
    X(a, CALLBACK, SINGULAR, BYTES, proof, 2)                       \
    X(a, STATIC, OPTIONAL, MESSAGE, proof_height, 3)
#define ibc_core_client_v1_QueryClientStateResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryClientStateResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryClientStateResponse_client_state_MSGTYPE google_protobuf_Any
#define ibc_core_client_v1_QueryClientStateResponse_proof_height_MSGTYPE ibc_core_client_v1_Height

#define ibc_core_client_v1_QueryClientStatesRequest_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, pagination, 1)
#define ibc_core_client_v1_QueryClientStatesRequest_CALLBACK NULL
#define ibc_core_client_v1_QueryClientStatesRequest_DEFAULT NULL
#define ibc_core_client_v1_QueryClientStatesRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define ibc_core_client_v1_QueryClientStatesResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, client_states, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define ibc_core_client_v1_QueryClientStatesResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryClientStatesResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryClientStatesResponse_client_states_MSGTYPE ibc_core_client_v1_IdentifiedClientState
#define ibc_core_client_v1_QueryClientStatesResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define ibc_core_client_v1_QueryConsensusStateRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)                    \
    X(a, STATIC, SINGULAR, UINT64, revision_number, 2)                \
    X(a, STATIC, SINGULAR, UINT64, revision_height, 3)                \
    X(a, STATIC, SINGULAR, BOOL, latest_height, 4)
#define ibc_core_client_v1_QueryConsensusStateRequest_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStateRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryConsensusStateResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, consensus_state, 1)                \
    X(a, CALLBACK, SINGULAR, BYTES, proof, 2)                          \
    X(a, STATIC, OPTIONAL, MESSAGE, proof_height, 3)
#define ibc_core_client_v1_QueryConsensusStateResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStateResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryConsensusStateResponse_consensus_state_MSGTYPE google_protobuf_Any
#define ibc_core_client_v1_QueryConsensusStateResponse_proof_height_MSGTYPE ibc_core_client_v1_Height

#define ibc_core_client_v1_QueryConsensusStatesRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define ibc_core_client_v1_QueryConsensusStatesRequest_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStatesRequest_DEFAULT NULL
#define ibc_core_client_v1_QueryConsensusStatesRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define ibc_core_client_v1_QueryConsensusStatesResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, consensus_states, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define ibc_core_client_v1_QueryConsensusStatesResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStatesResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryConsensusStatesResponse_consensus_states_MSGTYPE ibc_core_client_v1_ConsensusStateWithHeight
#define ibc_core_client_v1_QueryConsensusStatesResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)                           \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_DEFAULT NULL
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, consensus_state_heights, 1)             \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_consensus_state_heights_MSGTYPE ibc_core_client_v1_Height
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define ibc_core_client_v1_QueryClientStatusRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, client_id, 1)
#define ibc_core_client_v1_QueryClientStatusRequest_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryClientStatusRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryClientStatusResponse_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, status, 1)
#define ibc_core_client_v1_QueryClientStatusResponse_CALLBACK pb_default_field_callback
#define ibc_core_client_v1_QueryClientStatusResponse_DEFAULT NULL

#define ibc_core_client_v1_QueryClientParamsRequest_FIELDLIST(X, a)

#define ibc_core_client_v1_QueryClientParamsRequest_CALLBACK NULL
#define ibc_core_client_v1_QueryClientParamsRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryClientParamsResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, params, 1)
#define ibc_core_client_v1_QueryClientParamsResponse_CALLBACK NULL
#define ibc_core_client_v1_QueryClientParamsResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryClientParamsResponse_params_MSGTYPE ibc_core_client_v1_Params

#define ibc_core_client_v1_QueryUpgradedClientStateRequest_FIELDLIST(X, a)

#define ibc_core_client_v1_QueryUpgradedClientStateRequest_CALLBACK NULL
#define ibc_core_client_v1_QueryUpgradedClientStateRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryUpgradedClientStateResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, upgraded_client_state, 1)
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_CALLBACK NULL
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_upgraded_client_state_MSGTYPE google_protobuf_Any

#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_FIELDLIST(X, a)

#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_CALLBACK NULL
#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_DEFAULT NULL

#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, upgraded_consensus_state, 1)
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_CALLBACK NULL
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_DEFAULT NULL
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_upgraded_consensus_state_MSGTYPE google_protobuf_Any

extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStateRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStateResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStatesRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStatesResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStateRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStateResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStatesRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStatesResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStateHeightsRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryConsensusStateHeightsResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStatusRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientStatusResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientParamsRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryClientParamsResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryUpgradedClientStateRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryUpgradedClientStateResponse_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryUpgradedConsensusStateRequest_msg;
extern const pb_msgdesc_t ibc_core_client_v1_QueryUpgradedConsensusStateResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_core_client_v1_QueryClientStateRequest_fields &ibc_core_client_v1_QueryClientStateRequest_msg
#define ibc_core_client_v1_QueryClientStateResponse_fields &ibc_core_client_v1_QueryClientStateResponse_msg
#define ibc_core_client_v1_QueryClientStatesRequest_fields &ibc_core_client_v1_QueryClientStatesRequest_msg
#define ibc_core_client_v1_QueryClientStatesResponse_fields &ibc_core_client_v1_QueryClientStatesResponse_msg
#define ibc_core_client_v1_QueryConsensusStateRequest_fields &ibc_core_client_v1_QueryConsensusStateRequest_msg
#define ibc_core_client_v1_QueryConsensusStateResponse_fields &ibc_core_client_v1_QueryConsensusStateResponse_msg
#define ibc_core_client_v1_QueryConsensusStatesRequest_fields &ibc_core_client_v1_QueryConsensusStatesRequest_msg
#define ibc_core_client_v1_QueryConsensusStatesResponse_fields &ibc_core_client_v1_QueryConsensusStatesResponse_msg
#define ibc_core_client_v1_QueryConsensusStateHeightsRequest_fields &ibc_core_client_v1_QueryConsensusStateHeightsRequest_msg
#define ibc_core_client_v1_QueryConsensusStateHeightsResponse_fields \
    &ibc_core_client_v1_QueryConsensusStateHeightsResponse_msg
#define ibc_core_client_v1_QueryClientStatusRequest_fields &ibc_core_client_v1_QueryClientStatusRequest_msg
#define ibc_core_client_v1_QueryClientStatusResponse_fields &ibc_core_client_v1_QueryClientStatusResponse_msg
#define ibc_core_client_v1_QueryClientParamsRequest_fields &ibc_core_client_v1_QueryClientParamsRequest_msg
#define ibc_core_client_v1_QueryClientParamsResponse_fields &ibc_core_client_v1_QueryClientParamsResponse_msg
#define ibc_core_client_v1_QueryUpgradedClientStateRequest_fields &ibc_core_client_v1_QueryUpgradedClientStateRequest_msg
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_fields &ibc_core_client_v1_QueryUpgradedClientStateResponse_msg
#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_fields \
    &ibc_core_client_v1_QueryUpgradedConsensusStateRequest_msg
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_fields \
    &ibc_core_client_v1_QueryUpgradedConsensusStateResponse_msg

/* Maximum encoded size of messages (where known) */
/* ibc_core_client_v1_QueryClientStateRequest_size depends on runtime parameters */
/* ibc_core_client_v1_QueryClientStateResponse_size depends on runtime parameters */
/* ibc_core_client_v1_QueryClientStatesResponse_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStateRequest_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStateResponse_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStatesRequest_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStatesResponse_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStateHeightsRequest_size depends on runtime parameters */
/* ibc_core_client_v1_QueryConsensusStateHeightsResponse_size depends on runtime parameters */
/* ibc_core_client_v1_QueryClientStatusRequest_size depends on runtime parameters */
/* ibc_core_client_v1_QueryClientStatusResponse_size depends on runtime parameters */
#if defined(cosmos_base_query_v1beta1_PageRequest_size)
#define IBC_CORE_CLIENT_V1_IBC_CORE_CLIENT_V1_QUERY_PB_H_MAX_SIZE ibc_core_client_v1_QueryClientStatesRequest_size
#define ibc_core_client_v1_QueryClientStatesRequest_size (6 + cosmos_base_query_v1beta1_PageRequest_size)
#endif
#define ibc_core_client_v1_QueryClientParamsRequest_size 0
#define ibc_core_client_v1_QueryUpgradedClientStateRequest_size 0
#define ibc_core_client_v1_QueryUpgradedConsensusStateRequest_size 0
#if defined(ibc_core_client_v1_Params_size)
#define ibc_core_client_v1_QueryClientParamsResponse_size (6 + ibc_core_client_v1_Params_size)
#endif
#if defined(google_protobuf_Any_size)
#define ibc_core_client_v1_QueryUpgradedClientStateResponse_size (6 + google_protobuf_Any_size)
#define ibc_core_client_v1_QueryUpgradedConsensusStateResponse_size (6 + google_protobuf_Any_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
