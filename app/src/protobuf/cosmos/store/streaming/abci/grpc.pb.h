/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_STORE_STREAMING_ABCI_COSMOS_STORE_STREAMING_ABCI_GRPC_PB_H_INCLUDED
#define PB_COSMOS_STORE_STREAMING_ABCI_COSMOS_STORE_STREAMING_ABCI_GRPC_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/store/v1beta1/listening.pb.h"
#include "tendermint/abci/types.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* ListenBeginBlockRequest is the request type for the ListenBeginBlock RPC method */
typedef struct _cosmos_store_streaming_abci_ListenBeginBlockRequest {
    bool has_req;
    tendermint_abci_RequestBeginBlock req;
    bool has_res;
    tendermint_abci_ResponseBeginBlock res;
} cosmos_store_streaming_abci_ListenBeginBlockRequest;

/* ListenBeginBlockResponse is the response type for the ListenBeginBlock RPC method */
typedef struct _cosmos_store_streaming_abci_ListenBeginBlockResponse {
    char dummy_field;
} cosmos_store_streaming_abci_ListenBeginBlockResponse;

/* ListenEndBlockRequest is the request type for the ListenEndBlock RPC method */
typedef struct _cosmos_store_streaming_abci_ListenEndBlockRequest {
    bool has_req;
    tendermint_abci_RequestEndBlock req;
    bool has_res;
    tendermint_abci_ResponseEndBlock res;
} cosmos_store_streaming_abci_ListenEndBlockRequest;

/* ListenEndBlockResponse is the response type for the ListenEndBlock RPC method */
typedef struct _cosmos_store_streaming_abci_ListenEndBlockResponse {
    char dummy_field;
} cosmos_store_streaming_abci_ListenEndBlockResponse;

/* ListenDeliverTxRequest is the request type for the ListenDeliverTx RPC method */
typedef struct _cosmos_store_streaming_abci_ListenDeliverTxRequest {
    /* explicitly pass in block height as neither RequestDeliverTx or ResponseDeliverTx contain it */
    int64_t block_height;
    bool has_req;
    tendermint_abci_RequestDeliverTx req;
    bool has_res;
    tendermint_abci_ResponseDeliverTx res;
} cosmos_store_streaming_abci_ListenDeliverTxRequest;

/* ListenDeliverTxResponse is the response type for the ListenDeliverTx RPC method */
typedef struct _cosmos_store_streaming_abci_ListenDeliverTxResponse {
    char dummy_field;
} cosmos_store_streaming_abci_ListenDeliverTxResponse;

/* ListenCommitRequest is the request type for the ListenCommit RPC method */
typedef struct _cosmos_store_streaming_abci_ListenCommitRequest {
    /* explicitly pass in block height as ResponseCommit does not contain this info */
    int64_t block_height;
    bool has_res;
    tendermint_abci_ResponseCommit res;
    pb_callback_t change_set;
} cosmos_store_streaming_abci_ListenCommitRequest;

/* ListenCommitResponse is the response type for the ListenCommit RPC method */
typedef struct _cosmos_store_streaming_abci_ListenCommitResponse {
    char dummy_field;
} cosmos_store_streaming_abci_ListenCommitResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_init_default \
    { false, tendermint_abci_RequestBeginBlock_init_default, false, tendermint_abci_ResponseBeginBlock_init_default }
#define cosmos_store_streaming_abci_ListenBeginBlockResponse_init_default \
    { 0 }
#define cosmos_store_streaming_abci_ListenEndBlockRequest_init_default \
    { false, tendermint_abci_RequestEndBlock_init_default, false, tendermint_abci_ResponseEndBlock_init_default }
#define cosmos_store_streaming_abci_ListenEndBlockResponse_init_default \
    { 0 }
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_init_default \
    { 0, false, tendermint_abci_RequestDeliverTx_init_default, false, tendermint_abci_ResponseDeliverTx_init_default }
#define cosmos_store_streaming_abci_ListenDeliverTxResponse_init_default \
    { 0 }
#define cosmos_store_streaming_abci_ListenCommitRequest_init_default            \
    {                                                                           \
        0, false, tendermint_abci_ResponseCommit_init_default, { {NULL}, NULL } \
    }
#define cosmos_store_streaming_abci_ListenCommitResponse_init_default \
    { 0 }
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_init_zero \
    { false, tendermint_abci_RequestBeginBlock_init_zero, false, tendermint_abci_ResponseBeginBlock_init_zero }
#define cosmos_store_streaming_abci_ListenBeginBlockResponse_init_zero \
    { 0 }
#define cosmos_store_streaming_abci_ListenEndBlockRequest_init_zero \
    { false, tendermint_abci_RequestEndBlock_init_zero, false, tendermint_abci_ResponseEndBlock_init_zero }
#define cosmos_store_streaming_abci_ListenEndBlockResponse_init_zero \
    { 0 }
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_init_zero \
    { 0, false, tendermint_abci_RequestDeliverTx_init_zero, false, tendermint_abci_ResponseDeliverTx_init_zero }
#define cosmos_store_streaming_abci_ListenDeliverTxResponse_init_zero \
    { 0 }
#define cosmos_store_streaming_abci_ListenCommitRequest_init_zero            \
    {                                                                        \
        0, false, tendermint_abci_ResponseCommit_init_zero, { {NULL}, NULL } \
    }
#define cosmos_store_streaming_abci_ListenCommitResponse_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_req_tag 1
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_res_tag 2
#define cosmos_store_streaming_abci_ListenEndBlockRequest_req_tag 1
#define cosmos_store_streaming_abci_ListenEndBlockRequest_res_tag 2
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_block_height_tag 1
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_req_tag 2
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_res_tag 3
#define cosmos_store_streaming_abci_ListenCommitRequest_block_height_tag 1
#define cosmos_store_streaming_abci_ListenCommitRequest_res_tag 2
#define cosmos_store_streaming_abci_ListenCommitRequest_change_set_tag 3

/* Struct field encoding specification for nanopb */
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, req, 1)                                 \
    X(a, STATIC, OPTIONAL, MESSAGE, res, 2)
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_DEFAULT NULL
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_req_MSGTYPE tendermint_abci_RequestBeginBlock
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_res_MSGTYPE tendermint_abci_ResponseBeginBlock

#define cosmos_store_streaming_abci_ListenBeginBlockResponse_FIELDLIST(X, a)

#define cosmos_store_streaming_abci_ListenBeginBlockResponse_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenBeginBlockResponse_DEFAULT NULL

#define cosmos_store_streaming_abci_ListenEndBlockRequest_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, req, 1)                               \
    X(a, STATIC, OPTIONAL, MESSAGE, res, 2)
#define cosmos_store_streaming_abci_ListenEndBlockRequest_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenEndBlockRequest_DEFAULT NULL
#define cosmos_store_streaming_abci_ListenEndBlockRequest_req_MSGTYPE tendermint_abci_RequestEndBlock
#define cosmos_store_streaming_abci_ListenEndBlockRequest_res_MSGTYPE tendermint_abci_ResponseEndBlock

#define cosmos_store_streaming_abci_ListenEndBlockResponse_FIELDLIST(X, a)

#define cosmos_store_streaming_abci_ListenEndBlockResponse_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenEndBlockResponse_DEFAULT NULL

#define cosmos_store_streaming_abci_ListenDeliverTxRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, INT64, block_height, 1)                         \
    X(a, STATIC, OPTIONAL, MESSAGE, req, 2)                                \
    X(a, STATIC, OPTIONAL, MESSAGE, res, 3)
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_DEFAULT NULL
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_req_MSGTYPE tendermint_abci_RequestDeliverTx
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_res_MSGTYPE tendermint_abci_ResponseDeliverTx

#define cosmos_store_streaming_abci_ListenDeliverTxResponse_FIELDLIST(X, a)

#define cosmos_store_streaming_abci_ListenDeliverTxResponse_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenDeliverTxResponse_DEFAULT NULL

#define cosmos_store_streaming_abci_ListenCommitRequest_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, INT64, block_height, 1)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, res, 2)                             \
    X(a, CALLBACK, REPEATED, MESSAGE, change_set, 3)
#define cosmos_store_streaming_abci_ListenCommitRequest_CALLBACK pb_default_field_callback
#define cosmos_store_streaming_abci_ListenCommitRequest_DEFAULT NULL
#define cosmos_store_streaming_abci_ListenCommitRequest_res_MSGTYPE tendermint_abci_ResponseCommit
#define cosmos_store_streaming_abci_ListenCommitRequest_change_set_MSGTYPE cosmos_store_v1beta1_StoreKVPair

#define cosmos_store_streaming_abci_ListenCommitResponse_FIELDLIST(X, a)

#define cosmos_store_streaming_abci_ListenCommitResponse_CALLBACK NULL
#define cosmos_store_streaming_abci_ListenCommitResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenBeginBlockRequest_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenBeginBlockResponse_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenEndBlockRequest_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenEndBlockResponse_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenDeliverTxRequest_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenDeliverTxResponse_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenCommitRequest_msg;
extern const pb_msgdesc_t cosmos_store_streaming_abci_ListenCommitResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_fields &cosmos_store_streaming_abci_ListenBeginBlockRequest_msg
#define cosmos_store_streaming_abci_ListenBeginBlockResponse_fields &cosmos_store_streaming_abci_ListenBeginBlockResponse_msg
#define cosmos_store_streaming_abci_ListenEndBlockRequest_fields &cosmos_store_streaming_abci_ListenEndBlockRequest_msg
#define cosmos_store_streaming_abci_ListenEndBlockResponse_fields &cosmos_store_streaming_abci_ListenEndBlockResponse_msg
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_fields &cosmos_store_streaming_abci_ListenDeliverTxRequest_msg
#define cosmos_store_streaming_abci_ListenDeliverTxResponse_fields &cosmos_store_streaming_abci_ListenDeliverTxResponse_msg
#define cosmos_store_streaming_abci_ListenCommitRequest_fields &cosmos_store_streaming_abci_ListenCommitRequest_msg
#define cosmos_store_streaming_abci_ListenCommitResponse_fields &cosmos_store_streaming_abci_ListenCommitResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_store_streaming_abci_ListenCommitRequest_size depends on runtime parameters */
#if defined(tendermint_abci_RequestBeginBlock_size) && defined(tendermint_abci_ResponseBeginBlock_size)
#define cosmos_store_streaming_abci_ListenBeginBlockRequest_size \
    (12 + tendermint_abci_RequestBeginBlock_size + tendermint_abci_ResponseBeginBlock_size)
#endif
#define cosmos_store_streaming_abci_ListenBeginBlockResponse_size 0
#define cosmos_store_streaming_abci_ListenCommitResponse_size 0
#define cosmos_store_streaming_abci_ListenDeliverTxResponse_size 0
#define cosmos_store_streaming_abci_ListenEndBlockResponse_size 0
#if defined(tendermint_abci_ResponseEndBlock_size)
#define cosmos_store_streaming_abci_ListenEndBlockRequest_size (19 + tendermint_abci_ResponseEndBlock_size)
#endif
#if defined(tendermint_abci_RequestDeliverTx_size) && defined(tendermint_abci_ResponseDeliverTx_size)
#define COSMOS_STORE_STREAMING_ABCI_COSMOS_STORE_STREAMING_ABCI_GRPC_PB_H_MAX_SIZE \
    cosmos_store_streaming_abci_ListenDeliverTxRequest_size
#define cosmos_store_streaming_abci_ListenDeliverTxRequest_size \
    (23 + tendermint_abci_RequestDeliverTx_size + tendermint_abci_ResponseDeliverTx_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
