/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_BASE_NODE_V1BETA1_COSMOS_BASE_NODE_V1BETA1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_BASE_NODE_V1BETA1_COSMOS_BASE_NODE_V1BETA1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "google/api/annotations.pb.h"
#include "google/protobuf/timestamp.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* ConfigRequest defines the request structure for the Config gRPC query. */
typedef struct _cosmos_base_node_v1beta1_ConfigRequest {
    char dummy_field;
} cosmos_base_node_v1beta1_ConfigRequest;

/* ConfigResponse defines the response structure for the Config gRPC query. */
typedef struct _cosmos_base_node_v1beta1_ConfigResponse {
    pb_callback_t minimum_gas_price;
    /* pruning settings */
    pb_callback_t pruning_keep_recent;
    pb_callback_t pruning_interval;
} cosmos_base_node_v1beta1_ConfigResponse;

/* StateRequest defines the request structure for the status of a node. */
typedef struct _cosmos_base_node_v1beta1_StatusRequest {
    char dummy_field;
} cosmos_base_node_v1beta1_StatusRequest;

/* StateResponse defines the response structure for the status of a node. */
typedef struct _cosmos_base_node_v1beta1_StatusResponse {
    uint64_t earliest_store_height; /* earliest block height available in the store */
    uint64_t height;                /* current block height */
    bool has_timestamp;
    google_protobuf_Timestamp timestamp; /* block height timestamp */
    pb_callback_t app_hash;              /* app hash of the current block */
    pb_callback_t validator_hash;        /* validator hash provided by the consensus header */
} cosmos_base_node_v1beta1_StatusResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_base_node_v1beta1_ConfigRequest_init_default \
    { 0 }
#define cosmos_base_node_v1beta1_ConfigResponse_init_default \
    {                                                        \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }     \
    }
#define cosmos_base_node_v1beta1_StatusRequest_init_default \
    { 0 }
#define cosmos_base_node_v1beta1_StatusResponse_init_default                                  \
    {                                                                                         \
        0, 0, false, google_protobuf_Timestamp_init_default, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_base_node_v1beta1_ConfigRequest_init_zero \
    { 0 }
#define cosmos_base_node_v1beta1_ConfigResponse_init_zero \
    {                                                     \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }  \
    }
#define cosmos_base_node_v1beta1_StatusRequest_init_zero \
    { 0 }
#define cosmos_base_node_v1beta1_StatusResponse_init_zero                                  \
    {                                                                                      \
        0, 0, false, google_protobuf_Timestamp_init_zero, {{NULL}, NULL}, { {NULL}, NULL } \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_base_node_v1beta1_ConfigResponse_minimum_gas_price_tag 1
#define cosmos_base_node_v1beta1_ConfigResponse_pruning_keep_recent_tag 2
#define cosmos_base_node_v1beta1_ConfigResponse_pruning_interval_tag 3
#define cosmos_base_node_v1beta1_StatusResponse_earliest_store_height_tag 1
#define cosmos_base_node_v1beta1_StatusResponse_height_tag 2
#define cosmos_base_node_v1beta1_StatusResponse_timestamp_tag 3
#define cosmos_base_node_v1beta1_StatusResponse_app_hash_tag 4
#define cosmos_base_node_v1beta1_StatusResponse_validator_hash_tag 5

/* Struct field encoding specification for nanopb */
#define cosmos_base_node_v1beta1_ConfigRequest_FIELDLIST(X, a)

#define cosmos_base_node_v1beta1_ConfigRequest_CALLBACK NULL
#define cosmos_base_node_v1beta1_ConfigRequest_DEFAULT NULL

#define cosmos_base_node_v1beta1_ConfigResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, minimum_gas_price, 1)      \
    X(a, CALLBACK, SINGULAR, STRING, pruning_keep_recent, 2)    \
    X(a, CALLBACK, SINGULAR, STRING, pruning_interval, 3)
#define cosmos_base_node_v1beta1_ConfigResponse_CALLBACK pb_default_field_callback
#define cosmos_base_node_v1beta1_ConfigResponse_DEFAULT NULL

#define cosmos_base_node_v1beta1_StatusRequest_FIELDLIST(X, a)

#define cosmos_base_node_v1beta1_StatusRequest_CALLBACK NULL
#define cosmos_base_node_v1beta1_StatusRequest_DEFAULT NULL

#define cosmos_base_node_v1beta1_StatusResponse_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, earliest_store_height, 1)    \
    X(a, STATIC, SINGULAR, UINT64, height, 2)                   \
    X(a, STATIC, OPTIONAL, MESSAGE, timestamp, 3)               \
    X(a, CALLBACK, SINGULAR, BYTES, app_hash, 4)                \
    X(a, CALLBACK, SINGULAR, BYTES, validator_hash, 5)
#define cosmos_base_node_v1beta1_StatusResponse_CALLBACK pb_default_field_callback
#define cosmos_base_node_v1beta1_StatusResponse_DEFAULT NULL
#define cosmos_base_node_v1beta1_StatusResponse_timestamp_MSGTYPE google_protobuf_Timestamp

extern const pb_msgdesc_t cosmos_base_node_v1beta1_ConfigRequest_msg;
extern const pb_msgdesc_t cosmos_base_node_v1beta1_ConfigResponse_msg;
extern const pb_msgdesc_t cosmos_base_node_v1beta1_StatusRequest_msg;
extern const pb_msgdesc_t cosmos_base_node_v1beta1_StatusResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_base_node_v1beta1_ConfigRequest_fields &cosmos_base_node_v1beta1_ConfigRequest_msg
#define cosmos_base_node_v1beta1_ConfigResponse_fields &cosmos_base_node_v1beta1_ConfigResponse_msg
#define cosmos_base_node_v1beta1_StatusRequest_fields &cosmos_base_node_v1beta1_StatusRequest_msg
#define cosmos_base_node_v1beta1_StatusResponse_fields &cosmos_base_node_v1beta1_StatusResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_base_node_v1beta1_ConfigResponse_size depends on runtime parameters */
/* cosmos_base_node_v1beta1_StatusResponse_size depends on runtime parameters */
#define COSMOS_BASE_NODE_V1BETA1_COSMOS_BASE_NODE_V1BETA1_QUERY_PB_H_MAX_SIZE cosmos_base_node_v1beta1_ConfigRequest_size
#define cosmos_base_node_v1beta1_ConfigRequest_size 0
#define cosmos_base_node_v1beta1_StatusRequest_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
