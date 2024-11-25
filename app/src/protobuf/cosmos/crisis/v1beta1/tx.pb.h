/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_CRISIS_V1BETA1_COSMOS_CRISIS_V1BETA1_TX_PB_H_INCLUDED
#define PB_COSMOS_CRISIS_V1BETA1_COSMOS_CRISIS_V1BETA1_TX_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos/msg/v1/msg.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* MsgVerifyInvariant represents a message to verify a particular invariance. */
typedef struct _cosmos_crisis_v1beta1_MsgVerifyInvariant {
    /* sender is the account address of private key to send coins to fee collector account. */
    pb_callback_t sender;
    /* name of the invariant module. */
    pb_callback_t invariant_module_name;
    /* invariant_route is the msg's invariant route. */
    pb_callback_t invariant_route;
} cosmos_crisis_v1beta1_MsgVerifyInvariant;

/* MsgVerifyInvariantResponse defines the Msg/VerifyInvariant response type. */
typedef struct _cosmos_crisis_v1beta1_MsgVerifyInvariantResponse {
    char dummy_field;
} cosmos_crisis_v1beta1_MsgVerifyInvariantResponse;

/* MsgUpdateParams is the Msg/UpdateParams request type.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_crisis_v1beta1_MsgUpdateParams {
    /* authority is the address that controls the module (defaults to x/gov unless overwritten). */
    pb_callback_t authority;
    /* constant_fee defines the x/crisis parameter. */
    bool has_constant_fee;
    cosmos_base_v1beta1_Coin constant_fee;
} cosmos_crisis_v1beta1_MsgUpdateParams;

/* MsgUpdateParamsResponse defines the response structure for executing a
 MsgUpdateParams message.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_crisis_v1beta1_MsgUpdateParamsResponse {
    char dummy_field;
} cosmos_crisis_v1beta1_MsgUpdateParamsResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_init_default \
    {                                                         \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }      \
    }
#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_init_default \
    { 0 }
#define cosmos_crisis_v1beta1_MsgUpdateParams_init_default \
    { {{NULL}, NULL}, false, cosmos_base_v1beta1_Coin_init_default }
#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_init_default \
    { 0 }
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_init_zero \
    {                                                      \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }   \
    }
#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_init_zero \
    { 0 }
#define cosmos_crisis_v1beta1_MsgUpdateParams_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_v1beta1_Coin_init_zero }
#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_sender_tag 1
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_invariant_module_name_tag 2
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_invariant_route_tag 3
#define cosmos_crisis_v1beta1_MsgUpdateParams_authority_tag 1
#define cosmos_crisis_v1beta1_MsgUpdateParams_constant_fee_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, sender, 1)                  \
    X(a, CALLBACK, SINGULAR, STRING, invariant_module_name, 2)   \
    X(a, CALLBACK, SINGULAR, STRING, invariant_route, 3)
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_CALLBACK pb_default_field_callback
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_DEFAULT NULL

#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_FIELDLIST(X, a)

#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_CALLBACK NULL
#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_DEFAULT NULL

#define cosmos_crisis_v1beta1_MsgUpdateParams_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 1)            \
    X(a, STATIC, OPTIONAL, MESSAGE, constant_fee, 2)
#define cosmos_crisis_v1beta1_MsgUpdateParams_CALLBACK pb_default_field_callback
#define cosmos_crisis_v1beta1_MsgUpdateParams_DEFAULT NULL
#define cosmos_crisis_v1beta1_MsgUpdateParams_constant_fee_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_FIELDLIST(X, a)

#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_CALLBACK NULL
#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_crisis_v1beta1_MsgVerifyInvariant_msg;
extern const pb_msgdesc_t cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_msg;
extern const pb_msgdesc_t cosmos_crisis_v1beta1_MsgUpdateParams_msg;
extern const pb_msgdesc_t cosmos_crisis_v1beta1_MsgUpdateParamsResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_crisis_v1beta1_MsgVerifyInvariant_fields &cosmos_crisis_v1beta1_MsgVerifyInvariant_msg
#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_fields &cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_msg
#define cosmos_crisis_v1beta1_MsgUpdateParams_fields &cosmos_crisis_v1beta1_MsgUpdateParams_msg
#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_fields &cosmos_crisis_v1beta1_MsgUpdateParamsResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_crisis_v1beta1_MsgVerifyInvariant_size depends on runtime parameters */
/* cosmos_crisis_v1beta1_MsgUpdateParams_size depends on runtime parameters */
#define cosmos_crisis_v1beta1_MsgUpdateParamsResponse_size 0
#define cosmos_crisis_v1beta1_MsgVerifyInvariantResponse_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
