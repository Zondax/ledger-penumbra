/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_BANK_V1BETA1_COSMOS_BANK_V1BETA1_TX_PB_H_INCLUDED
#define PB_COSMOS_BANK_V1BETA1_COSMOS_BANK_V1BETA1_TX_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/bank/v1beta1/bank.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos/msg/v1/msg.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* MsgSend represents a message to send coins from one account to another. */
typedef struct _cosmos_bank_v1beta1_MsgSend {
    pb_callback_t from_address;
    pb_callback_t to_address;
    pb_callback_t amount;
} cosmos_bank_v1beta1_MsgSend;

/* MsgSendResponse defines the Msg/Send response type. */
typedef struct _cosmos_bank_v1beta1_MsgSendResponse {
    char dummy_field;
} cosmos_bank_v1beta1_MsgSendResponse;

/* MsgMultiSend represents an arbitrary multi-in, multi-out send message. */
typedef struct _cosmos_bank_v1beta1_MsgMultiSend {
    /* Inputs, despite being `repeated`, only allows one sender input. This is
 checked in MsgMultiSend's ValidateBasic. */
    pb_callback_t inputs;
    pb_callback_t outputs;
} cosmos_bank_v1beta1_MsgMultiSend;

/* MsgMultiSendResponse defines the Msg/MultiSend response type. */
typedef struct _cosmos_bank_v1beta1_MsgMultiSendResponse {
    char dummy_field;
} cosmos_bank_v1beta1_MsgMultiSendResponse;

/* MsgUpdateParams is the Msg/UpdateParams request type.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_MsgUpdateParams {
    /* authority is the address that controls the module (defaults to x/gov unless overwritten). */
    pb_callback_t authority;
    /* params defines the x/bank parameters to update.

 NOTE: All parameters must be supplied. */
    bool has_params;
    cosmos_bank_v1beta1_Params params;
} cosmos_bank_v1beta1_MsgUpdateParams;

/* MsgUpdateParamsResponse defines the response structure for executing a
 MsgUpdateParams message.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_MsgUpdateParamsResponse {
    char dummy_field;
} cosmos_bank_v1beta1_MsgUpdateParamsResponse;

/* MsgSetSendEnabled is the Msg/SetSendEnabled request type.

 Only entries to add/update/delete need to be included.
 Existing SendEnabled entries that are not included in this
 message are left unchanged.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_MsgSetSendEnabled {
    pb_callback_t authority;
    /* send_enabled is the list of entries to add or update. */
    pb_callback_t send_enabled;
    /* use_default_for is a list of denoms that should use the params.default_send_enabled value.
 Denoms listed here will have their SendEnabled entries deleted.
 If a denom is included that doesn't have a SendEnabled entry,
 it will be ignored. */
    pb_callback_t use_default_for;
} cosmos_bank_v1beta1_MsgSetSendEnabled;

/* MsgSetSendEnabledResponse defines the Msg/SetSendEnabled response type.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_MsgSetSendEnabledResponse {
    char dummy_field;
} cosmos_bank_v1beta1_MsgSetSendEnabledResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_bank_v1beta1_MsgSend_init_default         \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_bank_v1beta1_MsgSendResponse_init_default \
    { 0 }
#define cosmos_bank_v1beta1_MsgMultiSend_init_default \
    {                                                 \
        {{NULL}, NULL}, { {NULL}, NULL }              \
    }
#define cosmos_bank_v1beta1_MsgMultiSendResponse_init_default \
    { 0 }
#define cosmos_bank_v1beta1_MsgUpdateParams_init_default \
    { {{NULL}, NULL}, false, cosmos_bank_v1beta1_Params_init_default }
#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_init_default \
    { 0 }
#define cosmos_bank_v1beta1_MsgSetSendEnabled_init_default \
    {                                                      \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }   \
    }
#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_init_default \
    { 0 }
#define cosmos_bank_v1beta1_MsgSend_init_zero            \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_bank_v1beta1_MsgSendResponse_init_zero \
    { 0 }
#define cosmos_bank_v1beta1_MsgMultiSend_init_zero \
    {                                              \
        {{NULL}, NULL}, { {NULL}, NULL }           \
    }
#define cosmos_bank_v1beta1_MsgMultiSendResponse_init_zero \
    { 0 }
#define cosmos_bank_v1beta1_MsgUpdateParams_init_zero \
    { {{NULL}, NULL}, false, cosmos_bank_v1beta1_Params_init_zero }
#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_init_zero \
    { 0 }
#define cosmos_bank_v1beta1_MsgSetSendEnabled_init_zero  \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_bank_v1beta1_MsgSend_from_address_tag 1
#define cosmos_bank_v1beta1_MsgSend_to_address_tag 2
#define cosmos_bank_v1beta1_MsgSend_amount_tag 3
#define cosmos_bank_v1beta1_MsgMultiSend_inputs_tag 1
#define cosmos_bank_v1beta1_MsgMultiSend_outputs_tag 2
#define cosmos_bank_v1beta1_MsgUpdateParams_authority_tag 1
#define cosmos_bank_v1beta1_MsgUpdateParams_params_tag 2
#define cosmos_bank_v1beta1_MsgSetSendEnabled_authority_tag 1
#define cosmos_bank_v1beta1_MsgSetSendEnabled_send_enabled_tag 2
#define cosmos_bank_v1beta1_MsgSetSendEnabled_use_default_for_tag 3

/* Struct field encoding specification for nanopb */
#define cosmos_bank_v1beta1_MsgSend_FIELDLIST(X, a)   \
    X(a, CALLBACK, SINGULAR, STRING, from_address, 1) \
    X(a, CALLBACK, SINGULAR, STRING, to_address, 2)   \
    X(a, CALLBACK, REPEATED, MESSAGE, amount, 3)
#define cosmos_bank_v1beta1_MsgSend_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_MsgSend_DEFAULT NULL
#define cosmos_bank_v1beta1_MsgSend_amount_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_bank_v1beta1_MsgSendResponse_FIELDLIST(X, a)

#define cosmos_bank_v1beta1_MsgSendResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_MsgSendResponse_DEFAULT NULL

#define cosmos_bank_v1beta1_MsgMultiSend_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, inputs, 1)         \
    X(a, CALLBACK, REPEATED, MESSAGE, outputs, 2)
#define cosmos_bank_v1beta1_MsgMultiSend_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_MsgMultiSend_DEFAULT NULL
#define cosmos_bank_v1beta1_MsgMultiSend_inputs_MSGTYPE cosmos_bank_v1beta1_Input
#define cosmos_bank_v1beta1_MsgMultiSend_outputs_MSGTYPE cosmos_bank_v1beta1_Output

#define cosmos_bank_v1beta1_MsgMultiSendResponse_FIELDLIST(X, a)

#define cosmos_bank_v1beta1_MsgMultiSendResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_MsgMultiSendResponse_DEFAULT NULL

#define cosmos_bank_v1beta1_MsgUpdateParams_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 1)          \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 2)
#define cosmos_bank_v1beta1_MsgUpdateParams_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_MsgUpdateParams_DEFAULT NULL
#define cosmos_bank_v1beta1_MsgUpdateParams_params_MSGTYPE cosmos_bank_v1beta1_Params

#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_FIELDLIST(X, a)

#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_DEFAULT NULL

#define cosmos_bank_v1beta1_MsgSetSendEnabled_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 1)            \
    X(a, CALLBACK, REPEATED, MESSAGE, send_enabled, 2)        \
    X(a, CALLBACK, REPEATED, STRING, use_default_for, 3)
#define cosmos_bank_v1beta1_MsgSetSendEnabled_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_MsgSetSendEnabled_DEFAULT NULL
#define cosmos_bank_v1beta1_MsgSetSendEnabled_send_enabled_MSGTYPE cosmos_bank_v1beta1_SendEnabled

#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_FIELDLIST(X, a)

#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_DEFAULT NULL

extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgSend_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgSendResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgMultiSend_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgMultiSendResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgUpdateParams_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgUpdateParamsResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgSetSendEnabled_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_MsgSetSendEnabledResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_bank_v1beta1_MsgSend_fields &cosmos_bank_v1beta1_MsgSend_msg
#define cosmos_bank_v1beta1_MsgSendResponse_fields &cosmos_bank_v1beta1_MsgSendResponse_msg
#define cosmos_bank_v1beta1_MsgMultiSend_fields &cosmos_bank_v1beta1_MsgMultiSend_msg
#define cosmos_bank_v1beta1_MsgMultiSendResponse_fields &cosmos_bank_v1beta1_MsgMultiSendResponse_msg
#define cosmos_bank_v1beta1_MsgUpdateParams_fields &cosmos_bank_v1beta1_MsgUpdateParams_msg
#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_fields &cosmos_bank_v1beta1_MsgUpdateParamsResponse_msg
#define cosmos_bank_v1beta1_MsgSetSendEnabled_fields &cosmos_bank_v1beta1_MsgSetSendEnabled_msg
#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_fields &cosmos_bank_v1beta1_MsgSetSendEnabledResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_bank_v1beta1_MsgSend_size depends on runtime parameters */
/* cosmos_bank_v1beta1_MsgMultiSend_size depends on runtime parameters */
/* cosmos_bank_v1beta1_MsgUpdateParams_size depends on runtime parameters */
/* cosmos_bank_v1beta1_MsgSetSendEnabled_size depends on runtime parameters */
#define cosmos_bank_v1beta1_MsgMultiSendResponse_size 0
#define cosmos_bank_v1beta1_MsgSendResponse_size 0
#define cosmos_bank_v1beta1_MsgSetSendEnabledResponse_size 0
#define cosmos_bank_v1beta1_MsgUpdateParamsResponse_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
