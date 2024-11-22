/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_ORM_QUERY_V1ALPHA1_COSMOS_ORM_QUERY_V1ALPHA1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_ORM_QUERY_V1ALPHA1_COSMOS_ORM_QUERY_V1ALPHA1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/base/query/v1beta1/pagination.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/duration.pb.h"
#include "google/protobuf/timestamp.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* GetRequest is the Query/Get request type. */
typedef struct _cosmos_orm_query_v1alpha1_GetRequest {
    /* message_name is the fully-qualified message name of the ORM table being queried. */
    pb_callback_t message_name;
    /* index is the index fields expression used in orm definitions. If it
 is empty, the table's primary key is assumed. If it is non-empty, it must
 refer to an unique index. */
    pb_callback_t index;
    /* values are the values of the fields corresponding to the requested index.
 There must be as many values provided as there are fields in the index and
 these values must correspond to the index field types. */
    pb_callback_t values;
} cosmos_orm_query_v1alpha1_GetRequest;

/* GetResponse is the Query/Get response type. */
typedef struct _cosmos_orm_query_v1alpha1_GetResponse {
    /* result is the result of the get query. If no value is found, the gRPC
 status code NOT_FOUND will be returned. */
    bool has_result;
    google_protobuf_Any result;
} cosmos_orm_query_v1alpha1_GetResponse;

/* Prefix specifies the arguments to a prefix query. */
typedef struct _cosmos_orm_query_v1alpha1_ListRequest_Prefix {
    /* values specifies the index values for the prefix query.
 It is valid to special a partial prefix with fewer values than
 the number of fields in the index. */
    pb_callback_t values;
} cosmos_orm_query_v1alpha1_ListRequest_Prefix;

/* Range specifies the arguments to a range query. */
typedef struct _cosmos_orm_query_v1alpha1_ListRequest_Range {
    /* start specifies the starting index values for the range query.
 It is valid to provide fewer values than the number of fields in the
 index. */
    pb_callback_t start;
    /* end specifies the inclusive ending index values for the range query.
 It is valid to provide fewer values than the number of fields in the
 index. */
    pb_callback_t end;
} cosmos_orm_query_v1alpha1_ListRequest_Range;

/* ListRequest is the Query/List request type. */
typedef struct _cosmos_orm_query_v1alpha1_ListRequest {
    /* message_name is the fully-qualified message name of the ORM table being queried. */
    pb_callback_t message_name;
    /* index is the index fields expression used in orm definitions. If it
 is empty, the table's primary key is assumed. */
    pb_callback_t index;
    pb_size_t which_query;
    union {
        /* prefix defines a prefix query. */
        cosmos_orm_query_v1alpha1_ListRequest_Prefix prefix;
        /* range defines a range query. */
        cosmos_orm_query_v1alpha1_ListRequest_Range range;
    } query;
    /* pagination is the pagination request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_orm_query_v1alpha1_ListRequest;

/* ListResponse is the Query/List response type. */
typedef struct _cosmos_orm_query_v1alpha1_ListResponse {
    /* results are the results of the query. */
    pb_callback_t results;
    /* pagination is the pagination response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_orm_query_v1alpha1_ListResponse;

/* IndexValue represents the value of a field in an ORM index expression. */
typedef struct _cosmos_orm_query_v1alpha1_IndexValue {
    pb_size_t which_value;
    union {
        /* uint specifies a value for an uint32, fixed32, uint64, or fixed64
     index field. */
        uint64_t uint;
        /* int64 specifies a value for an int32, sfixed32, int64, or sfixed64
     index field. */
        int64_t int_;
        /* str specifies a value for a string index field. */
        pb_callback_t str;
        /* bytes specifies a value for a bytes index field. */
        pb_callback_t bytes;
        /* enum specifies a value for an enum index field. */
        pb_callback_t enum_;
        /* bool specifies a value for a bool index field. */
        bool bool_;
        /* timestamp specifies a value for a timestamp index field. */
        google_protobuf_Timestamp timestamp;
        /* duration specifies a value for a duration index field. */
        google_protobuf_Duration duration;
    } value;
} cosmos_orm_query_v1alpha1_IndexValue;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_orm_query_v1alpha1_GetRequest_init_default \
    {                                                     \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }  \
    }
#define cosmos_orm_query_v1alpha1_GetResponse_init_default \
    { false, google_protobuf_Any_init_default }
#define cosmos_orm_query_v1alpha1_ListRequest_init_default                                                     \
    {                                                                                                          \
        {{NULL}, NULL}, {{NULL}, NULL}, 0, {cosmos_orm_query_v1alpha1_ListRequest_Prefix_init_default}, false, \
            cosmos_base_query_v1beta1_PageRequest_init_default                                                 \
    }
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_init_default \
    {                                                             \
        { {NULL}, NULL }                                          \
    }
#define cosmos_orm_query_v1alpha1_ListRequest_Range_init_default \
    {                                                            \
        {{NULL}, NULL}, { {NULL}, NULL }                         \
    }
#define cosmos_orm_query_v1alpha1_ListResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_orm_query_v1alpha1_IndexValue_init_default \
    {                                                     \
        0, { 0 }                                          \
    }
#define cosmos_orm_query_v1alpha1_GetRequest_init_zero   \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_orm_query_v1alpha1_GetResponse_init_zero \
    { false, google_protobuf_Any_init_zero }
#define cosmos_orm_query_v1alpha1_ListRequest_init_zero                                                     \
    {                                                                                                       \
        {{NULL}, NULL}, {{NULL}, NULL}, 0, {cosmos_orm_query_v1alpha1_ListRequest_Prefix_init_zero}, false, \
            cosmos_base_query_v1beta1_PageRequest_init_zero                                                 \
    }
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_init_zero \
    {                                                          \
        { {NULL}, NULL }                                       \
    }
#define cosmos_orm_query_v1alpha1_ListRequest_Range_init_zero \
    {                                                         \
        {{NULL}, NULL}, { {NULL}, NULL }                      \
    }
#define cosmos_orm_query_v1alpha1_ListResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_orm_query_v1alpha1_IndexValue_init_zero \
    {                                                  \
        0, { 0 }                                       \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_orm_query_v1alpha1_GetRequest_message_name_tag 1
#define cosmos_orm_query_v1alpha1_GetRequest_index_tag 2
#define cosmos_orm_query_v1alpha1_GetRequest_values_tag 3
#define cosmos_orm_query_v1alpha1_GetResponse_result_tag 1
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_values_tag 1
#define cosmos_orm_query_v1alpha1_ListRequest_Range_start_tag 1
#define cosmos_orm_query_v1alpha1_ListRequest_Range_end_tag 2
#define cosmos_orm_query_v1alpha1_ListRequest_message_name_tag 1
#define cosmos_orm_query_v1alpha1_ListRequest_index_tag 2
#define cosmos_orm_query_v1alpha1_ListRequest_prefix_tag 3
#define cosmos_orm_query_v1alpha1_ListRequest_range_tag 4
#define cosmos_orm_query_v1alpha1_ListRequest_pagination_tag 5
#define cosmos_orm_query_v1alpha1_ListResponse_results_tag 1
#define cosmos_orm_query_v1alpha1_ListResponse_pagination_tag 5
#define cosmos_orm_query_v1alpha1_IndexValue_uint_tag 1
#define cosmos_orm_query_v1alpha1_IndexValue_int__tag 2
#define cosmos_orm_query_v1alpha1_IndexValue_str_tag 3
#define cosmos_orm_query_v1alpha1_IndexValue_bytes_tag 4
#define cosmos_orm_query_v1alpha1_IndexValue_enum__tag 5
#define cosmos_orm_query_v1alpha1_IndexValue_bool__tag 6
#define cosmos_orm_query_v1alpha1_IndexValue_timestamp_tag 7
#define cosmos_orm_query_v1alpha1_IndexValue_duration_tag 8

/* Struct field encoding specification for nanopb */
#define cosmos_orm_query_v1alpha1_GetRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, message_name, 1)        \
    X(a, CALLBACK, SINGULAR, STRING, index, 2)               \
    X(a, CALLBACK, REPEATED, MESSAGE, values, 3)
#define cosmos_orm_query_v1alpha1_GetRequest_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_GetRequest_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_GetRequest_values_MSGTYPE cosmos_orm_query_v1alpha1_IndexValue

#define cosmos_orm_query_v1alpha1_GetResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, result, 1)
#define cosmos_orm_query_v1alpha1_GetResponse_CALLBACK NULL
#define cosmos_orm_query_v1alpha1_GetResponse_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_GetResponse_result_MSGTYPE google_protobuf_Any

#define cosmos_orm_query_v1alpha1_ListRequest_FIELDLIST(X, a)      \
    X(a, CALLBACK, SINGULAR, STRING, message_name, 1)              \
    X(a, CALLBACK, SINGULAR, STRING, index, 2)                     \
    X(a, STATIC, ONEOF, MESSAGE, (query, prefix, query.prefix), 3) \
    X(a, STATIC, ONEOF, MESSAGE, (query, range, query.range), 4)   \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 5)
#define cosmos_orm_query_v1alpha1_ListRequest_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_ListRequest_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_ListRequest_query_prefix_MSGTYPE cosmos_orm_query_v1alpha1_ListRequest_Prefix
#define cosmos_orm_query_v1alpha1_ListRequest_query_range_MSGTYPE cosmos_orm_query_v1alpha1_ListRequest_Range
#define cosmos_orm_query_v1alpha1_ListRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, MESSAGE, values, 1)
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_values_MSGTYPE cosmos_orm_query_v1alpha1_IndexValue

#define cosmos_orm_query_v1alpha1_ListRequest_Range_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, start, 1)                     \
    X(a, CALLBACK, REPEATED, MESSAGE, end, 2)
#define cosmos_orm_query_v1alpha1_ListRequest_Range_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_ListRequest_Range_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_ListRequest_Range_start_MSGTYPE cosmos_orm_query_v1alpha1_IndexValue
#define cosmos_orm_query_v1alpha1_ListRequest_Range_end_MSGTYPE cosmos_orm_query_v1alpha1_IndexValue

#define cosmos_orm_query_v1alpha1_ListResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, results, 1)              \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 5)
#define cosmos_orm_query_v1alpha1_ListResponse_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_ListResponse_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_ListResponse_results_MSGTYPE google_protobuf_Any
#define cosmos_orm_query_v1alpha1_ListResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_orm_query_v1alpha1_IndexValue_FIELDLIST(X, a)             \
    X(a, STATIC, ONEOF, UINT64, (value, uint, value.uint), 1)            \
    X(a, STATIC, ONEOF, INT64, (value, int_, value.int_), 2)             \
    X(a, CALLBACK, ONEOF, STRING, (value, str, value.str), 3)            \
    X(a, CALLBACK, ONEOF, BYTES, (value, bytes, value.bytes), 4)         \
    X(a, CALLBACK, ONEOF, STRING, (value, enum_, value.enum_), 5)        \
    X(a, STATIC, ONEOF, BOOL, (value, bool_, value.bool_), 6)            \
    X(a, STATIC, ONEOF, MESSAGE, (value, timestamp, value.timestamp), 7) \
    X(a, STATIC, ONEOF, MESSAGE, (value, duration, value.duration), 8)
#define cosmos_orm_query_v1alpha1_IndexValue_CALLBACK pb_default_field_callback
#define cosmos_orm_query_v1alpha1_IndexValue_DEFAULT NULL
#define cosmos_orm_query_v1alpha1_IndexValue_value_timestamp_MSGTYPE google_protobuf_Timestamp
#define cosmos_orm_query_v1alpha1_IndexValue_value_duration_MSGTYPE google_protobuf_Duration

extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_GetRequest_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_GetResponse_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_ListRequest_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_ListRequest_Prefix_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_ListRequest_Range_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_ListResponse_msg;
extern const pb_msgdesc_t cosmos_orm_query_v1alpha1_IndexValue_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_orm_query_v1alpha1_GetRequest_fields &cosmos_orm_query_v1alpha1_GetRequest_msg
#define cosmos_orm_query_v1alpha1_GetResponse_fields &cosmos_orm_query_v1alpha1_GetResponse_msg
#define cosmos_orm_query_v1alpha1_ListRequest_fields &cosmos_orm_query_v1alpha1_ListRequest_msg
#define cosmos_orm_query_v1alpha1_ListRequest_Prefix_fields &cosmos_orm_query_v1alpha1_ListRequest_Prefix_msg
#define cosmos_orm_query_v1alpha1_ListRequest_Range_fields &cosmos_orm_query_v1alpha1_ListRequest_Range_msg
#define cosmos_orm_query_v1alpha1_ListResponse_fields &cosmos_orm_query_v1alpha1_ListResponse_msg
#define cosmos_orm_query_v1alpha1_IndexValue_fields &cosmos_orm_query_v1alpha1_IndexValue_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_orm_query_v1alpha1_GetRequest_size depends on runtime parameters */
/* cosmos_orm_query_v1alpha1_ListRequest_size depends on runtime parameters */
/* cosmos_orm_query_v1alpha1_ListRequest_Prefix_size depends on runtime parameters */
/* cosmos_orm_query_v1alpha1_ListRequest_Range_size depends on runtime parameters */
/* cosmos_orm_query_v1alpha1_ListResponse_size depends on runtime parameters */
/* cosmos_orm_query_v1alpha1_IndexValue_size depends on runtime parameters */
#if defined(google_protobuf_Any_size)
#define COSMOS_ORM_QUERY_V1ALPHA1_COSMOS_ORM_QUERY_V1ALPHA1_QUERY_PB_H_MAX_SIZE cosmos_orm_query_v1alpha1_GetResponse_size
#define cosmos_orm_query_v1alpha1_GetResponse_size (6 + google_protobuf_Any_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif