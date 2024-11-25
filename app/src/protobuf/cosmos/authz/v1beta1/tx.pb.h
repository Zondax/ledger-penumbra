/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_AUTHZ_V1BETA1_COSMOS_AUTHZ_V1BETA1_TX_PB_H_INCLUDED
#define PB_COSMOS_AUTHZ_V1BETA1_COSMOS_AUTHZ_V1BETA1_TX_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/authz/v1beta1/authz.pb.h"
#include "cosmos/msg/v1/msg.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/protobuf/any.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* MsgGrant is a request type for Grant method. It declares authorization to the grantee
 on behalf of the granter with the provided expiration time. */
typedef struct _cosmos_authz_v1beta1_MsgGrant {
    pb_callback_t granter;
    pb_callback_t grantee;
    bool has_grant;
    cosmos_authz_v1beta1_Grant grant;
} cosmos_authz_v1beta1_MsgGrant;

/* MsgExecResponse defines the Msg/MsgExecResponse response type. */
typedef struct _cosmos_authz_v1beta1_MsgExecResponse {
    pb_callback_t results;
} cosmos_authz_v1beta1_MsgExecResponse;

/* MsgExec attempts to execute the provided messages using
 authorizations granted to the grantee. Each message should have only
 one signer corresponding to the granter of the authorization. */
typedef struct _cosmos_authz_v1beta1_MsgExec {
    pb_callback_t grantee;
    /* Execute Msg.
 The x/authz will try to find a grant matching (msg.signers[0], grantee, MsgTypeURL(msg))
 triple and validate it. */
    pb_callback_t msgs;
} cosmos_authz_v1beta1_MsgExec;

/* MsgGrantResponse defines the Msg/MsgGrant response type. */
typedef struct _cosmos_authz_v1beta1_MsgGrantResponse {
    char dummy_field;
} cosmos_authz_v1beta1_MsgGrantResponse;

/* MsgRevoke revokes any authorization with the provided sdk.Msg type on the
 granter's account with that has been granted to the grantee. */
typedef struct _cosmos_authz_v1beta1_MsgRevoke {
    pb_callback_t granter;
    pb_callback_t grantee;
    pb_callback_t msg_type_url;
} cosmos_authz_v1beta1_MsgRevoke;

/* MsgRevokeResponse defines the Msg/MsgRevokeResponse response type. */
typedef struct _cosmos_authz_v1beta1_MsgRevokeResponse {
    char dummy_field;
} cosmos_authz_v1beta1_MsgRevokeResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_authz_v1beta1_MsgGrant_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_authz_v1beta1_Grant_init_default }
#define cosmos_authz_v1beta1_MsgExecResponse_init_default \
    {                                                     \
        { {NULL}, NULL }                                  \
    }
#define cosmos_authz_v1beta1_MsgExec_init_default \
    {                                             \
        {{NULL}, NULL}, { {NULL}, NULL }          \
    }
#define cosmos_authz_v1beta1_MsgGrantResponse_init_default \
    { 0 }
#define cosmos_authz_v1beta1_MsgRevoke_init_default      \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_authz_v1beta1_MsgRevokeResponse_init_default \
    { 0 }
#define cosmos_authz_v1beta1_MsgGrant_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_authz_v1beta1_Grant_init_zero }
#define cosmos_authz_v1beta1_MsgExecResponse_init_zero \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define cosmos_authz_v1beta1_MsgExec_init_zero \
    {                                          \
        {{NULL}, NULL}, { {NULL}, NULL }       \
    }
#define cosmos_authz_v1beta1_MsgGrantResponse_init_zero \
    { 0 }
#define cosmos_authz_v1beta1_MsgRevoke_init_zero         \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_authz_v1beta1_MsgRevokeResponse_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_authz_v1beta1_MsgGrant_granter_tag 1
#define cosmos_authz_v1beta1_MsgGrant_grantee_tag 2
#define cosmos_authz_v1beta1_MsgGrant_grant_tag 3
#define cosmos_authz_v1beta1_MsgExecResponse_results_tag 1
#define cosmos_authz_v1beta1_MsgExec_grantee_tag 1
#define cosmos_authz_v1beta1_MsgExec_msgs_tag 2
#define cosmos_authz_v1beta1_MsgRevoke_granter_tag 1
#define cosmos_authz_v1beta1_MsgRevoke_grantee_tag 2
#define cosmos_authz_v1beta1_MsgRevoke_msg_type_url_tag 3

/* Struct field encoding specification for nanopb */
#define cosmos_authz_v1beta1_MsgGrant_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, granter, 1)      \
    X(a, CALLBACK, SINGULAR, STRING, grantee, 2)      \
    X(a, STATIC, OPTIONAL, MESSAGE, grant, 3)
#define cosmos_authz_v1beta1_MsgGrant_CALLBACK pb_default_field_callback
#define cosmos_authz_v1beta1_MsgGrant_DEFAULT NULL
#define cosmos_authz_v1beta1_MsgGrant_grant_MSGTYPE cosmos_authz_v1beta1_Grant

#define cosmos_authz_v1beta1_MsgExecResponse_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, BYTES, results, 1)
#define cosmos_authz_v1beta1_MsgExecResponse_CALLBACK pb_default_field_callback
#define cosmos_authz_v1beta1_MsgExecResponse_DEFAULT NULL

#define cosmos_authz_v1beta1_MsgExec_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, grantee, 1)     \
    X(a, CALLBACK, REPEATED, MESSAGE, msgs, 2)
#define cosmos_authz_v1beta1_MsgExec_CALLBACK pb_default_field_callback
#define cosmos_authz_v1beta1_MsgExec_DEFAULT NULL
#define cosmos_authz_v1beta1_MsgExec_msgs_MSGTYPE google_protobuf_Any

#define cosmos_authz_v1beta1_MsgGrantResponse_FIELDLIST(X, a)

#define cosmos_authz_v1beta1_MsgGrantResponse_CALLBACK NULL
#define cosmos_authz_v1beta1_MsgGrantResponse_DEFAULT NULL

#define cosmos_authz_v1beta1_MsgRevoke_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, granter, 1)       \
    X(a, CALLBACK, SINGULAR, STRING, grantee, 2)       \
    X(a, CALLBACK, SINGULAR, STRING, msg_type_url, 3)
#define cosmos_authz_v1beta1_MsgRevoke_CALLBACK pb_default_field_callback
#define cosmos_authz_v1beta1_MsgRevoke_DEFAULT NULL

#define cosmos_authz_v1beta1_MsgRevokeResponse_FIELDLIST(X, a)

#define cosmos_authz_v1beta1_MsgRevokeResponse_CALLBACK NULL
#define cosmos_authz_v1beta1_MsgRevokeResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgGrant_msg;
extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgExecResponse_msg;
extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgExec_msg;
extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgGrantResponse_msg;
extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgRevoke_msg;
extern const pb_msgdesc_t cosmos_authz_v1beta1_MsgRevokeResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_authz_v1beta1_MsgGrant_fields &cosmos_authz_v1beta1_MsgGrant_msg
#define cosmos_authz_v1beta1_MsgExecResponse_fields &cosmos_authz_v1beta1_MsgExecResponse_msg
#define cosmos_authz_v1beta1_MsgExec_fields &cosmos_authz_v1beta1_MsgExec_msg
#define cosmos_authz_v1beta1_MsgGrantResponse_fields &cosmos_authz_v1beta1_MsgGrantResponse_msg
#define cosmos_authz_v1beta1_MsgRevoke_fields &cosmos_authz_v1beta1_MsgRevoke_msg
#define cosmos_authz_v1beta1_MsgRevokeResponse_fields &cosmos_authz_v1beta1_MsgRevokeResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_authz_v1beta1_MsgGrant_size depends on runtime parameters */
/* cosmos_authz_v1beta1_MsgExecResponse_size depends on runtime parameters */
/* cosmos_authz_v1beta1_MsgExec_size depends on runtime parameters */
/* cosmos_authz_v1beta1_MsgRevoke_size depends on runtime parameters */
#define cosmos_authz_v1beta1_MsgGrantResponse_size 0
#define cosmos_authz_v1beta1_MsgRevokeResponse_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
