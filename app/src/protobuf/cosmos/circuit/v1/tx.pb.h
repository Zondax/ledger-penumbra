/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_CIRCUIT_V1_COSMOS_CIRCUIT_V1_TX_PB_H_INCLUDED
#define PB_COSMOS_CIRCUIT_V1_COSMOS_CIRCUIT_V1_TX_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/circuit/v1/types.pb.h"
#include "cosmos/msg/v1/msg.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* MsgAuthorizeCircuitBreaker defines the Msg/AuthorizeCircuitBreaker request type. */
typedef struct _cosmos_circuit_v1_MsgAuthorizeCircuitBreaker {
    /* granter is the granter of the circuit breaker permissions and must have
 LEVEL_SUPER_ADMIN. */
    pb_callback_t granter;
    /* grantee is the account authorized with the provided permissions. */
    pb_callback_t grantee;
    /* permissions are the circuit breaker permissions that the grantee receives.
 These will overwrite any existing permissions. LEVEL_NONE_UNSPECIFIED can
 be specified to revoke all permissions. */
    bool has_permissions;
    cosmos_circuit_v1_Permissions permissions;
} cosmos_circuit_v1_MsgAuthorizeCircuitBreaker;

/* MsgAuthorizeCircuitBreaker defines the Msg/AuthorizeCircuitBreaker response type. */
typedef struct _cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse {
    bool success;
} cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse;

/* MsgTripCircuitBreaker defines the Msg/TripCircuitBreaker request type. */
typedef struct _cosmos_circuit_v1_MsgTripCircuitBreaker {
    /* authority is the account authorized to trip the circuit breaker. */
    pb_callback_t authority;
    /* msg_type_urls specifies a list of type URLs to immediately stop processing.
 IF IT IS LEFT EMPTY, ALL MSG PROCESSING WILL STOP IMMEDIATELY.
 This value is validated against the authority's permissions and if the
 authority does not have permissions to trip the specified msg type URLs
 (or all URLs), the operation will fail. */
    pb_callback_t msg_type_urls;
} cosmos_circuit_v1_MsgTripCircuitBreaker;

/* MsgTripCircuitBreaker defines the Msg/TripCircuitBreaker response type. */
typedef struct _cosmos_circuit_v1_MsgTripCircuitBreakerResponse {
    bool success;
} cosmos_circuit_v1_MsgTripCircuitBreakerResponse;

/* MsgResetCircuitBreaker defines the Msg/ResetCircuitBreaker request type. */
typedef struct _cosmos_circuit_v1_MsgResetCircuitBreaker {
    /* authority is the account authorized to trip or reset the circuit breaker. */
    pb_callback_t authority;
    /* msg_type_urls specifies a list of Msg type URLs to resume processing. If
 it is left empty all Msg processing for type URLs that the account is
 authorized to trip will resume. */
    pb_callback_t msg_type_urls;
} cosmos_circuit_v1_MsgResetCircuitBreaker;

/* MsgResetCircuitBreakerResponse defines the Msg/ResetCircuitBreaker response type. */
typedef struct _cosmos_circuit_v1_MsgResetCircuitBreakerResponse {
    bool success;
} cosmos_circuit_v1_MsgResetCircuitBreakerResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_circuit_v1_Permissions_init_default }
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_init_default \
    { 0 }
#define cosmos_circuit_v1_MsgTripCircuitBreaker_init_default \
    {                                                        \
        {{NULL}, NULL}, { {NULL}, NULL }                     \
    }
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_init_default \
    { 0 }
#define cosmos_circuit_v1_MsgResetCircuitBreaker_init_default \
    {                                                         \
        {{NULL}, NULL}, { {NULL}, NULL }                      \
    }
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_init_default \
    { 0 }
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_circuit_v1_Permissions_init_zero }
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_init_zero \
    { 0 }
#define cosmos_circuit_v1_MsgTripCircuitBreaker_init_zero \
    {                                                     \
        {{NULL}, NULL}, { {NULL}, NULL }                  \
    }
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_init_zero \
    { 0 }
#define cosmos_circuit_v1_MsgResetCircuitBreaker_init_zero \
    {                                                      \
        {{NULL}, NULL}, { {NULL}, NULL }                   \
    }
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_granter_tag 1
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_grantee_tag 2
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_permissions_tag 3
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_success_tag 1
#define cosmos_circuit_v1_MsgTripCircuitBreaker_authority_tag 1
#define cosmos_circuit_v1_MsgTripCircuitBreaker_msg_type_urls_tag 2
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_success_tag 1
#define cosmos_circuit_v1_MsgResetCircuitBreaker_authority_tag 1
#define cosmos_circuit_v1_MsgResetCircuitBreaker_msg_type_urls_tag 3
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_success_tag 1

/* Struct field encoding specification for nanopb */
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, granter, 1)                     \
    X(a, CALLBACK, SINGULAR, STRING, grantee, 2)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, permissions, 3)
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_CALLBACK pb_default_field_callback
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_DEFAULT NULL
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_permissions_MSGTYPE cosmos_circuit_v1_Permissions

#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_FIELDLIST(X, a) X(a, STATIC, SINGULAR, BOOL, success, 1)
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_CALLBACK NULL
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_DEFAULT NULL

#define cosmos_circuit_v1_MsgTripCircuitBreaker_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 1)              \
    X(a, CALLBACK, REPEATED, STRING, msg_type_urls, 2)
#define cosmos_circuit_v1_MsgTripCircuitBreaker_CALLBACK pb_default_field_callback
#define cosmos_circuit_v1_MsgTripCircuitBreaker_DEFAULT NULL

#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_FIELDLIST(X, a) X(a, STATIC, SINGULAR, BOOL, success, 1)
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_CALLBACK NULL
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_DEFAULT NULL

#define cosmos_circuit_v1_MsgResetCircuitBreaker_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 1)               \
    X(a, CALLBACK, REPEATED, STRING, msg_type_urls, 3)
#define cosmos_circuit_v1_MsgResetCircuitBreaker_CALLBACK pb_default_field_callback
#define cosmos_circuit_v1_MsgResetCircuitBreaker_DEFAULT NULL

#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_FIELDLIST(X, a) X(a, STATIC, SINGULAR, BOOL, success, 1)
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_CALLBACK NULL
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_msg;
extern const pb_msgdesc_t cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_msg;
extern const pb_msgdesc_t cosmos_circuit_v1_MsgTripCircuitBreaker_msg;
extern const pb_msgdesc_t cosmos_circuit_v1_MsgTripCircuitBreakerResponse_msg;
extern const pb_msgdesc_t cosmos_circuit_v1_MsgResetCircuitBreaker_msg;
extern const pb_msgdesc_t cosmos_circuit_v1_MsgResetCircuitBreakerResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_fields &cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_msg
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_fields &cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_msg
#define cosmos_circuit_v1_MsgTripCircuitBreaker_fields &cosmos_circuit_v1_MsgTripCircuitBreaker_msg
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_fields &cosmos_circuit_v1_MsgTripCircuitBreakerResponse_msg
#define cosmos_circuit_v1_MsgResetCircuitBreaker_fields &cosmos_circuit_v1_MsgResetCircuitBreaker_msg
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_fields &cosmos_circuit_v1_MsgResetCircuitBreakerResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_circuit_v1_MsgAuthorizeCircuitBreaker_size depends on runtime parameters */
/* cosmos_circuit_v1_MsgTripCircuitBreaker_size depends on runtime parameters */
/* cosmos_circuit_v1_MsgResetCircuitBreaker_size depends on runtime parameters */
#define COSMOS_CIRCUIT_V1_COSMOS_CIRCUIT_V1_TX_PB_H_MAX_SIZE cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_size
#define cosmos_circuit_v1_MsgAuthorizeCircuitBreakerResponse_size 2
#define cosmos_circuit_v1_MsgResetCircuitBreakerResponse_size 2
#define cosmos_circuit_v1_MsgTripCircuitBreakerResponse_size 2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif