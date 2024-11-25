/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_TX_V1BETA1_COSMOS_TX_V1BETA1_SERVICE_PB_H_INCLUDED
#define PB_COSMOS_TX_V1BETA1_COSMOS_TX_V1BETA1_SERVICE_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/base/abci/v1beta1/abci.pb.h"
#include "cosmos/base/query/v1beta1/pagination.pb.h"
#include "cosmos/tx/v1beta1/tx.pb.h"
#include "google/api/annotations.pb.h"
#include "tendermint/types/block.pb.h"
#include "tendermint/types/types.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* OrderBy defines the sorting order */
typedef enum _cosmos_tx_v1beta1_OrderBy {
    /* ORDER_BY_UNSPECIFIED specifies an unknown sorting order. OrderBy defaults
 to ASC in this case. */
    cosmos_tx_v1beta1_OrderBy_ORDER_BY_UNSPECIFIED = 0,
    /* ORDER_BY_ASC defines ascending order */
    cosmos_tx_v1beta1_OrderBy_ORDER_BY_ASC = 1,
    /* ORDER_BY_DESC defines descending order */
    cosmos_tx_v1beta1_OrderBy_ORDER_BY_DESC = 2
} cosmos_tx_v1beta1_OrderBy;

/* BroadcastMode specifies the broadcast mode for the TxService.Broadcast RPC
 method. */
typedef enum _cosmos_tx_v1beta1_BroadcastMode {
    /* zero-value for mode ordering */
    cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_UNSPECIFIED = 0,
    /* DEPRECATED: use BROADCAST_MODE_SYNC instead,
 BROADCAST_MODE_BLOCK is not supported by the SDK from v0.47.x onwards. */
    cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_BLOCK = 1,
    /* BROADCAST_MODE_SYNC defines a tx broadcasting mode where the client waits
 for a CheckTx execution response only. */
    cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_SYNC = 2,
    /* BROADCAST_MODE_ASYNC defines a tx broadcasting mode where the client
 returns immediately. */
    cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_ASYNC = 3
} cosmos_tx_v1beta1_BroadcastMode;

/* Struct definitions */
/* GetTxsEventRequest is the request type for the Service.TxsByEvents
 RPC method. */
typedef struct _cosmos_tx_v1beta1_GetTxsEventRequest {
    /* events is the list of transaction event type.
 Deprecated post v0.47.x: use query instead, which should contain a valid
 events query. */
    pb_callback_t events;
    /* pagination defines a pagination for the request.
 Deprecated post v0.46.x: use page and limit instead. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
    cosmos_tx_v1beta1_OrderBy order_by;
    /* page is the page number to query, starts at 1. If not provided, will
 default to first page. */
    uint64_t page;
    /* limit is the total number of results to be returned in the result page.
 If left empty it will default to a value to be set by each app. */
    uint64_t limit;
    /* query defines the transaction event query that is proxied to Tendermint's
 TxSearch RPC method. The query must be valid.

 Since Cosmos SDK 0.48 */
    pb_callback_t query;
} cosmos_tx_v1beta1_GetTxsEventRequest;

/* GetTxsEventResponse is the response type for the Service.TxsByEvents
 RPC method. */
typedef struct _cosmos_tx_v1beta1_GetTxsEventResponse {
    /* txs is the list of queried transactions. */
    pb_callback_t txs;
    /* tx_responses is the list of queried TxResponses. */
    pb_callback_t tx_responses;
    /* pagination defines a pagination for the response.
 Deprecated post v0.46.x: use total instead. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
    /* total is total number of results available */
    uint64_t total;
} cosmos_tx_v1beta1_GetTxsEventResponse;

/* BroadcastTxRequest is the request type for the Service.BroadcastTxRequest
 RPC method. */
typedef struct _cosmos_tx_v1beta1_BroadcastTxRequest {
    /* tx_bytes is the raw transaction. */
    pb_callback_t tx_bytes;
    cosmos_tx_v1beta1_BroadcastMode mode;
} cosmos_tx_v1beta1_BroadcastTxRequest;

/* BroadcastTxResponse is the response type for the
 Service.BroadcastTx method. */
typedef struct _cosmos_tx_v1beta1_BroadcastTxResponse {
    /* tx_response is the queried TxResponses. */
    bool has_tx_response;
    cosmos_base_abci_v1beta1_TxResponse tx_response;
} cosmos_tx_v1beta1_BroadcastTxResponse;

/* SimulateRequest is the request type for the Service.Simulate
 RPC method. */
typedef struct _cosmos_tx_v1beta1_SimulateRequest {
    /* tx is the transaction to simulate.
 Deprecated. Send raw tx bytes instead. */
    bool has_tx;
    cosmos_tx_v1beta1_Tx tx;
    /* tx_bytes is the raw transaction.

 Since: cosmos-sdk 0.43 */
    pb_callback_t tx_bytes;
} cosmos_tx_v1beta1_SimulateRequest;

/* SimulateResponse is the response type for the
 Service.SimulateRPC method. */
typedef struct _cosmos_tx_v1beta1_SimulateResponse {
    /* gas_info is the information about gas used in the simulation. */
    bool has_gas_info;
    cosmos_base_abci_v1beta1_GasInfo gas_info;
    /* result is the result of the simulation. */
    bool has_result;
    cosmos_base_abci_v1beta1_Result result;
} cosmos_tx_v1beta1_SimulateResponse;

/* GetTxRequest is the request type for the Service.GetTx
 RPC method. */
typedef struct _cosmos_tx_v1beta1_GetTxRequest {
    /* hash is the tx hash to query, encoded as a hex string. */
    pb_callback_t hash;
} cosmos_tx_v1beta1_GetTxRequest;

/* GetTxResponse is the response type for the Service.GetTx method. */
typedef struct _cosmos_tx_v1beta1_GetTxResponse {
    /* tx is the queried transaction. */
    bool has_tx;
    cosmos_tx_v1beta1_Tx tx;
    /* tx_response is the queried TxResponses. */
    bool has_tx_response;
    cosmos_base_abci_v1beta1_TxResponse tx_response;
} cosmos_tx_v1beta1_GetTxResponse;

/* GetBlockWithTxsRequest is the request type for the Service.GetBlockWithTxs
 RPC method.

 Since: cosmos-sdk 0.45.2 */
typedef struct _cosmos_tx_v1beta1_GetBlockWithTxsRequest {
    /* height is the height of the block to query. */
    int64_t height;
    /* pagination defines a pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_tx_v1beta1_GetBlockWithTxsRequest;

/* GetBlockWithTxsResponse is the response type for the Service.GetBlockWithTxs
 method.

 Since: cosmos-sdk 0.45.2 */
typedef struct _cosmos_tx_v1beta1_GetBlockWithTxsResponse {
    /* txs are the transactions in the block. */
    pb_callback_t txs;
    bool has_block_id;
    tendermint_types_BlockID block_id;
    bool has_block;
    tendermint_types_Block block;
    /* pagination defines a pagination for the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_tx_v1beta1_GetBlockWithTxsResponse;

/* TxDecodeRequest is the request type for the Service.TxDecode
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxDecodeRequest {
    /* tx_bytes is the raw transaction. */
    pb_callback_t tx_bytes;
} cosmos_tx_v1beta1_TxDecodeRequest;

/* TxDecodeResponse is the response type for the
 Service.TxDecode method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxDecodeResponse {
    /* tx is the decoded transaction. */
    bool has_tx;
    cosmos_tx_v1beta1_Tx tx;
} cosmos_tx_v1beta1_TxDecodeResponse;

/* TxEncodeRequest is the request type for the Service.TxEncode
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxEncodeRequest {
    /* tx is the transaction to encode. */
    bool has_tx;
    cosmos_tx_v1beta1_Tx tx;
} cosmos_tx_v1beta1_TxEncodeRequest;

/* TxEncodeResponse is the response type for the
 Service.TxEncode method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxEncodeResponse {
    /* tx_bytes is the encoded transaction bytes. */
    pb_callback_t tx_bytes;
} cosmos_tx_v1beta1_TxEncodeResponse;

/* TxEncodeAminoRequest is the request type for the Service.TxEncodeAmino
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxEncodeAminoRequest {
    pb_callback_t amino_json;
} cosmos_tx_v1beta1_TxEncodeAminoRequest;

/* TxEncodeAminoResponse is the response type for the Service.TxEncodeAmino
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxEncodeAminoResponse {
    pb_callback_t amino_binary;
} cosmos_tx_v1beta1_TxEncodeAminoResponse;

/* TxDecodeAminoRequest is the request type for the Service.TxDecodeAmino
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxDecodeAminoRequest {
    pb_callback_t amino_binary;
} cosmos_tx_v1beta1_TxDecodeAminoRequest;

/* TxDecodeAminoResponse is the response type for the Service.TxDecodeAmino
 RPC method.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_tx_v1beta1_TxDecodeAminoResponse {
    pb_callback_t amino_json;
} cosmos_tx_v1beta1_TxDecodeAminoResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _cosmos_tx_v1beta1_OrderBy_MIN cosmos_tx_v1beta1_OrderBy_ORDER_BY_UNSPECIFIED
#define _cosmos_tx_v1beta1_OrderBy_MAX cosmos_tx_v1beta1_OrderBy_ORDER_BY_DESC
#define _cosmos_tx_v1beta1_OrderBy_ARRAYSIZE ((cosmos_tx_v1beta1_OrderBy)(cosmos_tx_v1beta1_OrderBy_ORDER_BY_DESC + 1))

#define _cosmos_tx_v1beta1_BroadcastMode_MIN cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_UNSPECIFIED
#define _cosmos_tx_v1beta1_BroadcastMode_MAX cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_ASYNC
#define _cosmos_tx_v1beta1_BroadcastMode_ARRAYSIZE \
    ((cosmos_tx_v1beta1_BroadcastMode)(cosmos_tx_v1beta1_BroadcastMode_BROADCAST_MODE_ASYNC + 1))

#define cosmos_tx_v1beta1_GetTxsEventRequest_order_by_ENUMTYPE cosmos_tx_v1beta1_OrderBy

#define cosmos_tx_v1beta1_BroadcastTxRequest_mode_ENUMTYPE cosmos_tx_v1beta1_BroadcastMode

/* Initializer values for message structs */
#define cosmos_tx_v1beta1_GetTxsEventRequest_init_default                                                                  \
    {                                                                                                                      \
        {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default, _cosmos_tx_v1beta1_OrderBy_MIN, 0, 0, { \
            {NULL}, NULL                                                                                                   \
        }                                                                                                                  \
    }
#define cosmos_tx_v1beta1_GetTxsEventResponse_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default, 0 }
#define cosmos_tx_v1beta1_BroadcastTxRequest_init_default \
    { {{NULL}, NULL}, _cosmos_tx_v1beta1_BroadcastMode_MIN }
#define cosmos_tx_v1beta1_BroadcastTxResponse_init_default \
    { false, cosmos_base_abci_v1beta1_TxResponse_init_default }
#define cosmos_tx_v1beta1_SimulateRequest_init_default             \
    {                                                              \
        false, cosmos_tx_v1beta1_Tx_init_default, { {NULL}, NULL } \
    }
#define cosmos_tx_v1beta1_SimulateResponse_init_default \
    { false, cosmos_base_abci_v1beta1_GasInfo_init_default, false, cosmos_base_abci_v1beta1_Result_init_default }
#define cosmos_tx_v1beta1_GetTxRequest_init_default \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define cosmos_tx_v1beta1_GetTxResponse_init_default \
    { false, cosmos_tx_v1beta1_Tx_init_default, false, cosmos_base_abci_v1beta1_TxResponse_init_default }
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_init_default \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_init_default                                                           \
    {                                                                                                                    \
        {{NULL}, NULL}, false, tendermint_types_BlockID_init_default, false, tendermint_types_Block_init_default, false, \
            cosmos_base_query_v1beta1_PageResponse_init_default                                                          \
    }
#define cosmos_tx_v1beta1_TxDecodeRequest_init_default \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define cosmos_tx_v1beta1_TxDecodeResponse_init_default \
    { false, cosmos_tx_v1beta1_Tx_init_default }
#define cosmos_tx_v1beta1_TxEncodeRequest_init_default \
    { false, cosmos_tx_v1beta1_Tx_init_default }
#define cosmos_tx_v1beta1_TxEncodeResponse_init_default \
    {                                                   \
        { {NULL}, NULL }                                \
    }
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_init_default \
    {                                                       \
        { {NULL}, NULL }                                    \
    }
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_init_default \
    {                                                        \
        { {NULL}, NULL }                                     \
    }
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_init_default \
    {                                                       \
        { {NULL}, NULL }                                    \
    }
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_init_default \
    {                                                        \
        { {NULL}, NULL }                                     \
    }
#define cosmos_tx_v1beta1_GetTxsEventRequest_init_zero                                                                  \
    {                                                                                                                   \
        {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero, _cosmos_tx_v1beta1_OrderBy_MIN, 0, 0, { \
            {NULL}, NULL                                                                                                \
        }                                                                                                               \
    }
#define cosmos_tx_v1beta1_GetTxsEventResponse_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero, 0 }
#define cosmos_tx_v1beta1_BroadcastTxRequest_init_zero \
    { {{NULL}, NULL}, _cosmos_tx_v1beta1_BroadcastMode_MIN }
#define cosmos_tx_v1beta1_BroadcastTxResponse_init_zero \
    { false, cosmos_base_abci_v1beta1_TxResponse_init_zero }
#define cosmos_tx_v1beta1_SimulateRequest_init_zero             \
    {                                                           \
        false, cosmos_tx_v1beta1_Tx_init_zero, { {NULL}, NULL } \
    }
#define cosmos_tx_v1beta1_SimulateResponse_init_zero \
    { false, cosmos_base_abci_v1beta1_GasInfo_init_zero, false, cosmos_base_abci_v1beta1_Result_init_zero }
#define cosmos_tx_v1beta1_GetTxRequest_init_zero \
    {                                            \
        { {NULL}, NULL }                         \
    }
#define cosmos_tx_v1beta1_GetTxResponse_init_zero \
    { false, cosmos_tx_v1beta1_Tx_init_zero, false, cosmos_base_abci_v1beta1_TxResponse_init_zero }
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_init_zero \
    { 0, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_init_zero                                                        \
    {                                                                                                              \
        {{NULL}, NULL}, false, tendermint_types_BlockID_init_zero, false, tendermint_types_Block_init_zero, false, \
            cosmos_base_query_v1beta1_PageResponse_init_zero                                                       \
    }
#define cosmos_tx_v1beta1_TxDecodeRequest_init_zero \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define cosmos_tx_v1beta1_TxDecodeResponse_init_zero \
    { false, cosmos_tx_v1beta1_Tx_init_zero }
#define cosmos_tx_v1beta1_TxEncodeRequest_init_zero \
    { false, cosmos_tx_v1beta1_Tx_init_zero }
#define cosmos_tx_v1beta1_TxEncodeResponse_init_zero \
    {                                                \
        { {NULL}, NULL }                             \
    }
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_init_zero \
    {                                                    \
        { {NULL}, NULL }                                 \
    }
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_init_zero \
    {                                                     \
        { {NULL}, NULL }                                  \
    }
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_init_zero \
    {                                                    \
        { {NULL}, NULL }                                 \
    }
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_init_zero \
    {                                                     \
        { {NULL}, NULL }                                  \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_tx_v1beta1_GetTxsEventRequest_events_tag 1
#define cosmos_tx_v1beta1_GetTxsEventRequest_pagination_tag 2
#define cosmos_tx_v1beta1_GetTxsEventRequest_order_by_tag 3
#define cosmos_tx_v1beta1_GetTxsEventRequest_page_tag 4
#define cosmos_tx_v1beta1_GetTxsEventRequest_limit_tag 5
#define cosmos_tx_v1beta1_GetTxsEventRequest_query_tag 6
#define cosmos_tx_v1beta1_GetTxsEventResponse_txs_tag 1
#define cosmos_tx_v1beta1_GetTxsEventResponse_tx_responses_tag 2
#define cosmos_tx_v1beta1_GetTxsEventResponse_pagination_tag 3
#define cosmos_tx_v1beta1_GetTxsEventResponse_total_tag 4
#define cosmos_tx_v1beta1_BroadcastTxRequest_tx_bytes_tag 1
#define cosmos_tx_v1beta1_BroadcastTxRequest_mode_tag 2
#define cosmos_tx_v1beta1_BroadcastTxResponse_tx_response_tag 1
#define cosmos_tx_v1beta1_SimulateRequest_tx_tag 1
#define cosmos_tx_v1beta1_SimulateRequest_tx_bytes_tag 2
#define cosmos_tx_v1beta1_SimulateResponse_gas_info_tag 1
#define cosmos_tx_v1beta1_SimulateResponse_result_tag 2
#define cosmos_tx_v1beta1_GetTxRequest_hash_tag 1
#define cosmos_tx_v1beta1_GetTxResponse_tx_tag 1
#define cosmos_tx_v1beta1_GetTxResponse_tx_response_tag 2
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_height_tag 1
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_pagination_tag 2
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_txs_tag 1
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_block_id_tag 2
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_block_tag 3
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_pagination_tag 4
#define cosmos_tx_v1beta1_TxDecodeRequest_tx_bytes_tag 1
#define cosmos_tx_v1beta1_TxDecodeResponse_tx_tag 1
#define cosmos_tx_v1beta1_TxEncodeRequest_tx_tag 1
#define cosmos_tx_v1beta1_TxEncodeResponse_tx_bytes_tag 1
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_amino_json_tag 1
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_amino_binary_tag 1
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_amino_binary_tag 1
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_amino_json_tag 1

/* Struct field encoding specification for nanopb */
#define cosmos_tx_v1beta1_GetTxsEventRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, STRING, events, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)           \
    X(a, STATIC, SINGULAR, UENUM, order_by, 3)               \
    X(a, STATIC, SINGULAR, UINT64, page, 4)                  \
    X(a, STATIC, SINGULAR, UINT64, limit, 5)                 \
    X(a, CALLBACK, SINGULAR, STRING, query, 6)
#define cosmos_tx_v1beta1_GetTxsEventRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_GetTxsEventRequest_DEFAULT NULL
#define cosmos_tx_v1beta1_GetTxsEventRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_tx_v1beta1_GetTxsEventResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, txs, 1)                 \
    X(a, CALLBACK, REPEATED, MESSAGE, tx_responses, 2)        \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 3)            \
    X(a, STATIC, SINGULAR, UINT64, total, 4)
#define cosmos_tx_v1beta1_GetTxsEventResponse_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_GetTxsEventResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_GetTxsEventResponse_txs_MSGTYPE cosmos_tx_v1beta1_Tx
#define cosmos_tx_v1beta1_GetTxsEventResponse_tx_responses_MSGTYPE cosmos_base_abci_v1beta1_TxResponse
#define cosmos_tx_v1beta1_GetTxsEventResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_tx_v1beta1_BroadcastTxRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, tx_bytes, 1)             \
    X(a, STATIC, SINGULAR, UENUM, mode, 2)
#define cosmos_tx_v1beta1_BroadcastTxRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_BroadcastTxRequest_DEFAULT NULL

#define cosmos_tx_v1beta1_BroadcastTxResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, tx_response, 1)
#define cosmos_tx_v1beta1_BroadcastTxResponse_CALLBACK NULL
#define cosmos_tx_v1beta1_BroadcastTxResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_BroadcastTxResponse_tx_response_MSGTYPE cosmos_base_abci_v1beta1_TxResponse

#define cosmos_tx_v1beta1_SimulateRequest_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, tx, 1)                \
    X(a, CALLBACK, SINGULAR, BYTES, tx_bytes, 2)
#define cosmos_tx_v1beta1_SimulateRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_SimulateRequest_DEFAULT NULL
#define cosmos_tx_v1beta1_SimulateRequest_tx_MSGTYPE cosmos_tx_v1beta1_Tx

#define cosmos_tx_v1beta1_SimulateResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, gas_info, 1)           \
    X(a, STATIC, OPTIONAL, MESSAGE, result, 2)
#define cosmos_tx_v1beta1_SimulateResponse_CALLBACK NULL
#define cosmos_tx_v1beta1_SimulateResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_SimulateResponse_gas_info_MSGTYPE cosmos_base_abci_v1beta1_GasInfo
#define cosmos_tx_v1beta1_SimulateResponse_result_MSGTYPE cosmos_base_abci_v1beta1_Result

#define cosmos_tx_v1beta1_GetTxRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, hash, 1)
#define cosmos_tx_v1beta1_GetTxRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_GetTxRequest_DEFAULT NULL

#define cosmos_tx_v1beta1_GetTxResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, tx, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, tx_response, 2)
#define cosmos_tx_v1beta1_GetTxResponse_CALLBACK NULL
#define cosmos_tx_v1beta1_GetTxResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_GetTxResponse_tx_MSGTYPE cosmos_tx_v1beta1_Tx
#define cosmos_tx_v1beta1_GetTxResponse_tx_response_MSGTYPE cosmos_base_abci_v1beta1_TxResponse

#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, INT64, height, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_CALLBACK NULL
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_DEFAULT NULL
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, txs, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, block_id, 2)                  \
    X(a, STATIC, OPTIONAL, MESSAGE, block, 3)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 4)
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_txs_MSGTYPE cosmos_tx_v1beta1_Tx
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_block_id_MSGTYPE tendermint_types_BlockID
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_block_MSGTYPE tendermint_types_Block
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_tx_v1beta1_TxDecodeRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, tx_bytes, 1)
#define cosmos_tx_v1beta1_TxDecodeRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxDecodeRequest_DEFAULT NULL

#define cosmos_tx_v1beta1_TxDecodeResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, tx, 1)
#define cosmos_tx_v1beta1_TxDecodeResponse_CALLBACK NULL
#define cosmos_tx_v1beta1_TxDecodeResponse_DEFAULT NULL
#define cosmos_tx_v1beta1_TxDecodeResponse_tx_MSGTYPE cosmos_tx_v1beta1_Tx

#define cosmos_tx_v1beta1_TxEncodeRequest_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, tx, 1)
#define cosmos_tx_v1beta1_TxEncodeRequest_CALLBACK NULL
#define cosmos_tx_v1beta1_TxEncodeRequest_DEFAULT NULL
#define cosmos_tx_v1beta1_TxEncodeRequest_tx_MSGTYPE cosmos_tx_v1beta1_Tx

#define cosmos_tx_v1beta1_TxEncodeResponse_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, tx_bytes, 1)
#define cosmos_tx_v1beta1_TxEncodeResponse_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxEncodeResponse_DEFAULT NULL

#define cosmos_tx_v1beta1_TxEncodeAminoRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, amino_json, 1)
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_DEFAULT NULL

#define cosmos_tx_v1beta1_TxEncodeAminoResponse_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, amino_binary, 1)
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_DEFAULT NULL

#define cosmos_tx_v1beta1_TxDecodeAminoRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, amino_binary, 1)
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_DEFAULT NULL

#define cosmos_tx_v1beta1_TxDecodeAminoResponse_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, amino_json, 1)
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_CALLBACK pb_default_field_callback
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_tx_v1beta1_GetTxsEventRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_GetTxsEventResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_BroadcastTxRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_BroadcastTxResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_SimulateRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_SimulateResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_GetTxRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_GetTxResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_GetBlockWithTxsRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_GetBlockWithTxsResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxDecodeRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxDecodeResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxEncodeRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxEncodeResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxEncodeAminoRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxEncodeAminoResponse_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxDecodeAminoRequest_msg;
extern const pb_msgdesc_t cosmos_tx_v1beta1_TxDecodeAminoResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_tx_v1beta1_GetTxsEventRequest_fields &cosmos_tx_v1beta1_GetTxsEventRequest_msg
#define cosmos_tx_v1beta1_GetTxsEventResponse_fields &cosmos_tx_v1beta1_GetTxsEventResponse_msg
#define cosmos_tx_v1beta1_BroadcastTxRequest_fields &cosmos_tx_v1beta1_BroadcastTxRequest_msg
#define cosmos_tx_v1beta1_BroadcastTxResponse_fields &cosmos_tx_v1beta1_BroadcastTxResponse_msg
#define cosmos_tx_v1beta1_SimulateRequest_fields &cosmos_tx_v1beta1_SimulateRequest_msg
#define cosmos_tx_v1beta1_SimulateResponse_fields &cosmos_tx_v1beta1_SimulateResponse_msg
#define cosmos_tx_v1beta1_GetTxRequest_fields &cosmos_tx_v1beta1_GetTxRequest_msg
#define cosmos_tx_v1beta1_GetTxResponse_fields &cosmos_tx_v1beta1_GetTxResponse_msg
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_fields &cosmos_tx_v1beta1_GetBlockWithTxsRequest_msg
#define cosmos_tx_v1beta1_GetBlockWithTxsResponse_fields &cosmos_tx_v1beta1_GetBlockWithTxsResponse_msg
#define cosmos_tx_v1beta1_TxDecodeRequest_fields &cosmos_tx_v1beta1_TxDecodeRequest_msg
#define cosmos_tx_v1beta1_TxDecodeResponse_fields &cosmos_tx_v1beta1_TxDecodeResponse_msg
#define cosmos_tx_v1beta1_TxEncodeRequest_fields &cosmos_tx_v1beta1_TxEncodeRequest_msg
#define cosmos_tx_v1beta1_TxEncodeResponse_fields &cosmos_tx_v1beta1_TxEncodeResponse_msg
#define cosmos_tx_v1beta1_TxEncodeAminoRequest_fields &cosmos_tx_v1beta1_TxEncodeAminoRequest_msg
#define cosmos_tx_v1beta1_TxEncodeAminoResponse_fields &cosmos_tx_v1beta1_TxEncodeAminoResponse_msg
#define cosmos_tx_v1beta1_TxDecodeAminoRequest_fields &cosmos_tx_v1beta1_TxDecodeAminoRequest_msg
#define cosmos_tx_v1beta1_TxDecodeAminoResponse_fields &cosmos_tx_v1beta1_TxDecodeAminoResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_tx_v1beta1_GetTxsEventRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_GetTxsEventResponse_size depends on runtime parameters */
/* cosmos_tx_v1beta1_BroadcastTxRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_SimulateRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_GetTxRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_GetBlockWithTxsResponse_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxDecodeRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxEncodeResponse_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxEncodeAminoRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxEncodeAminoResponse_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxDecodeAminoRequest_size depends on runtime parameters */
/* cosmos_tx_v1beta1_TxDecodeAminoResponse_size depends on runtime parameters */
#if defined(cosmos_base_abci_v1beta1_TxResponse_size)
#define cosmos_tx_v1beta1_BroadcastTxResponse_size (6 + cosmos_base_abci_v1beta1_TxResponse_size)
#endif
#if defined(cosmos_base_abci_v1beta1_Result_size)
#define COSMOS_TX_V1BETA1_COSMOS_TX_V1BETA1_SERVICE_PB_H_MAX_SIZE cosmos_tx_v1beta1_SimulateResponse_size
#define cosmos_tx_v1beta1_SimulateResponse_size (30 + cosmos_base_abci_v1beta1_Result_size)
#endif
#if defined(cosmos_tx_v1beta1_Tx_size) && defined(cosmos_base_abci_v1beta1_TxResponse_size)
#define cosmos_tx_v1beta1_GetTxResponse_size (12 + cosmos_tx_v1beta1_Tx_size + cosmos_base_abci_v1beta1_TxResponse_size)
#endif
#if defined(cosmos_base_query_v1beta1_PageRequest_size)
#define cosmos_tx_v1beta1_GetBlockWithTxsRequest_size (17 + cosmos_base_query_v1beta1_PageRequest_size)
#endif
#if defined(cosmos_tx_v1beta1_Tx_size)
#define cosmos_tx_v1beta1_TxDecodeResponse_size (6 + cosmos_tx_v1beta1_Tx_size)
#define cosmos_tx_v1beta1_TxEncodeRequest_size (6 + cosmos_tx_v1beta1_Tx_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
