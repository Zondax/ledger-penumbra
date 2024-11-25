/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_STORE_V1BETA1_COSMOS_STORE_V1BETA1_LISTENING_PB_H_INCLUDED
#define PB_COSMOS_STORE_V1BETA1_COSMOS_STORE_V1BETA1_LISTENING_PB_H_INCLUDED
#include <pb.h>

#include "tendermint/abci/types.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* StoreKVPair is a KVStore KVPair used for listening to state changes (Sets and Deletes)
 It optionally includes the StoreKey for the originating KVStore and a Boolean flag to distinguish between Sets and
 Deletes

 Since: cosmos-sdk 0.43 */
typedef struct _cosmos_store_v1beta1_StoreKVPair {
    pb_callback_t store_key; /* the store key for the KVStore this pair originates from */
    bool delete;             /* true indicates a delete operation, false indicates a set operation */
    pb_callback_t key;
    pb_callback_t value;
} cosmos_store_v1beta1_StoreKVPair;

/* BlockMetadata contains all the abci event data of a block
 the file streamer dump them into files together with the state changes. */
typedef struct _cosmos_store_v1beta1_BlockMetadata {
    bool has_request_begin_block;
    tendermint_abci_RequestBeginBlock request_begin_block;
    bool has_response_begin_block;
    tendermint_abci_ResponseBeginBlock response_begin_block;
    pb_callback_t deliver_txs;
    bool has_request_end_block;
    tendermint_abci_RequestEndBlock request_end_block;
    bool has_response_end_block;
    tendermint_abci_ResponseEndBlock response_end_block;
    bool has_response_commit;
    tendermint_abci_ResponseCommit response_commit;
} cosmos_store_v1beta1_BlockMetadata;

/* DeliverTx encapulate deliver tx request and response. */
typedef struct _cosmos_store_v1beta1_BlockMetadata_DeliverTx {
    bool has_request;
    tendermint_abci_RequestDeliverTx request;
    bool has_response;
    tendermint_abci_ResponseDeliverTx response;
} cosmos_store_v1beta1_BlockMetadata_DeliverTx;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_store_v1beta1_StoreKVPair_init_default       \
    {                                                       \
        {{NULL}, NULL}, 0, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_store_v1beta1_BlockMetadata_init_default                                                                \
    {                                                                                                                  \
        false, tendermint_abci_RequestBeginBlock_init_default, false, tendermint_abci_ResponseBeginBlock_init_default, \
            {{NULL}, NULL}, false, tendermint_abci_RequestEndBlock_init_default, false,                                \
            tendermint_abci_ResponseEndBlock_init_default, false, tendermint_abci_ResponseCommit_init_default          \
    }
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_init_default \
    { false, tendermint_abci_RequestDeliverTx_init_default, false, tendermint_abci_ResponseDeliverTx_init_default }
#define cosmos_store_v1beta1_StoreKVPair_init_zero          \
    {                                                       \
        {{NULL}, NULL}, 0, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_store_v1beta1_BlockMetadata_init_zero                                                             \
    {                                                                                                            \
        false, tendermint_abci_RequestBeginBlock_init_zero, false, tendermint_abci_ResponseBeginBlock_init_zero, \
            {{NULL}, NULL}, false, tendermint_abci_RequestEndBlock_init_zero, false,                             \
            tendermint_abci_ResponseEndBlock_init_zero, false, tendermint_abci_ResponseCommit_init_zero          \
    }
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_init_zero \
    { false, tendermint_abci_RequestDeliverTx_init_zero, false, tendermint_abci_ResponseDeliverTx_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_store_v1beta1_StoreKVPair_store_key_tag 1
#define cosmos_store_v1beta1_StoreKVPair_delete_tag 2
#define cosmos_store_v1beta1_StoreKVPair_key_tag 3
#define cosmos_store_v1beta1_StoreKVPair_value_tag 4
#define cosmos_store_v1beta1_BlockMetadata_request_begin_block_tag 1
#define cosmos_store_v1beta1_BlockMetadata_response_begin_block_tag 2
#define cosmos_store_v1beta1_BlockMetadata_deliver_txs_tag 3
#define cosmos_store_v1beta1_BlockMetadata_request_end_block_tag 4
#define cosmos_store_v1beta1_BlockMetadata_response_end_block_tag 5
#define cosmos_store_v1beta1_BlockMetadata_response_commit_tag 6
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_request_tag 1
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_response_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_store_v1beta1_StoreKVPair_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, store_key, 1)       \
    X(a, STATIC, SINGULAR, BOOL, delete, 2)              \
    X(a, CALLBACK, SINGULAR, BYTES, key, 3)              \
    X(a, CALLBACK, SINGULAR, BYTES, value, 4)
#define cosmos_store_v1beta1_StoreKVPair_CALLBACK pb_default_field_callback
#define cosmos_store_v1beta1_StoreKVPair_DEFAULT NULL

#define cosmos_store_v1beta1_BlockMetadata_FIELDLIST(X, a)   \
    X(a, STATIC, OPTIONAL, MESSAGE, request_begin_block, 1)  \
    X(a, STATIC, OPTIONAL, MESSAGE, response_begin_block, 2) \
    X(a, CALLBACK, REPEATED, MESSAGE, deliver_txs, 3)        \
    X(a, STATIC, OPTIONAL, MESSAGE, request_end_block, 4)    \
    X(a, STATIC, OPTIONAL, MESSAGE, response_end_block, 5)   \
    X(a, STATIC, OPTIONAL, MESSAGE, response_commit, 6)
#define cosmos_store_v1beta1_BlockMetadata_CALLBACK pb_default_field_callback
#define cosmos_store_v1beta1_BlockMetadata_DEFAULT NULL
#define cosmos_store_v1beta1_BlockMetadata_request_begin_block_MSGTYPE tendermint_abci_RequestBeginBlock
#define cosmos_store_v1beta1_BlockMetadata_response_begin_block_MSGTYPE tendermint_abci_ResponseBeginBlock
#define cosmos_store_v1beta1_BlockMetadata_deliver_txs_MSGTYPE cosmos_store_v1beta1_BlockMetadata_DeliverTx
#define cosmos_store_v1beta1_BlockMetadata_request_end_block_MSGTYPE tendermint_abci_RequestEndBlock
#define cosmos_store_v1beta1_BlockMetadata_response_end_block_MSGTYPE tendermint_abci_ResponseEndBlock
#define cosmos_store_v1beta1_BlockMetadata_response_commit_MSGTYPE tendermint_abci_ResponseCommit

#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, request, 1)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, response, 2)
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_CALLBACK NULL
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_DEFAULT NULL
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_request_MSGTYPE tendermint_abci_RequestDeliverTx
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_response_MSGTYPE tendermint_abci_ResponseDeliverTx

extern const pb_msgdesc_t cosmos_store_v1beta1_StoreKVPair_msg;
extern const pb_msgdesc_t cosmos_store_v1beta1_BlockMetadata_msg;
extern const pb_msgdesc_t cosmos_store_v1beta1_BlockMetadata_DeliverTx_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_store_v1beta1_StoreKVPair_fields &cosmos_store_v1beta1_StoreKVPair_msg
#define cosmos_store_v1beta1_BlockMetadata_fields &cosmos_store_v1beta1_BlockMetadata_msg
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_fields &cosmos_store_v1beta1_BlockMetadata_DeliverTx_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_store_v1beta1_StoreKVPair_size depends on runtime parameters */
/* cosmos_store_v1beta1_BlockMetadata_size depends on runtime parameters */
#if defined(tendermint_abci_RequestDeliverTx_size) && defined(tendermint_abci_ResponseDeliverTx_size)
#define COSMOS_STORE_V1BETA1_COSMOS_STORE_V1BETA1_LISTENING_PB_H_MAX_SIZE cosmos_store_v1beta1_BlockMetadata_DeliverTx_size
#define cosmos_store_v1beta1_BlockMetadata_DeliverTx_size \
    (12 + tendermint_abci_RequestDeliverTx_size + tendermint_abci_ResponseDeliverTx_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
