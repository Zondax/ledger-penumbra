/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_STAKING_V1BETA1_COSMOS_STAKING_V1BETA1_AUTHZ_PB_H_INCLUDED
#define PB_COSMOS_STAKING_V1BETA1_COSMOS_STAKING_V1BETA1_AUTHZ_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* AuthorizationType defines the type of staking module authorization type

 Since: cosmos-sdk 0.43 */
typedef enum _cosmos_staking_v1beta1_AuthorizationType {
    /* AUTHORIZATION_TYPE_UNSPECIFIED specifies an unknown authorization type */
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_UNSPECIFIED = 0,
    /* AUTHORIZATION_TYPE_DELEGATE defines an authorization type for Msg/Delegate */
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_DELEGATE = 1,
    /* AUTHORIZATION_TYPE_UNDELEGATE defines an authorization type for Msg/Undelegate */
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_UNDELEGATE = 2,
    /* AUTHORIZATION_TYPE_REDELEGATE defines an authorization type for Msg/BeginRedelegate */
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_REDELEGATE = 3,
    /* AUTHORIZATION_TYPE_CANCEL_UNBONDING_DELEGATION defines an authorization type for Msg/MsgCancelUnbondingDelegation */
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_CANCEL_UNBONDING_DELEGATION = 4
} cosmos_staking_v1beta1_AuthorizationType;

/* Struct definitions */
/* Validators defines list of validator addresses. */
typedef struct _cosmos_staking_v1beta1_StakeAuthorization_Validators {
    pb_callback_t address;
} cosmos_staking_v1beta1_StakeAuthorization_Validators;

/* StakeAuthorization defines authorization for delegate/undelegate/redelegate.

 Since: cosmos-sdk 0.43 */
typedef struct _cosmos_staking_v1beta1_StakeAuthorization {
    /* max_tokens specifies the maximum amount of tokens can be delegate to a validator. If it is
 empty, there is no spend limit and any amount of coins can be delegated. */
    bool has_max_tokens;
    cosmos_base_v1beta1_Coin max_tokens;
    pb_size_t which_validators;
    union {
        /* allow_list specifies list of validator addresses to whom grantee can delegate tokens on behalf of granter's
     account. */
        cosmos_staking_v1beta1_StakeAuthorization_Validators allow_list;
        /* deny_list specifies list of validator addresses to whom grantee can not delegate tokens. */
        cosmos_staking_v1beta1_StakeAuthorization_Validators deny_list;
    } validators;
    /* authorization_type defines one of AuthorizationType. */
    cosmos_staking_v1beta1_AuthorizationType authorization_type;
} cosmos_staking_v1beta1_StakeAuthorization;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _cosmos_staking_v1beta1_AuthorizationType_MIN cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_UNSPECIFIED
#define _cosmos_staking_v1beta1_AuthorizationType_MAX \
    cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_CANCEL_UNBONDING_DELEGATION
#define _cosmos_staking_v1beta1_AuthorizationType_ARRAYSIZE                                                                               \
    ((cosmos_staking_v1beta1_AuthorizationType)(cosmos_staking_v1beta1_AuthorizationType_AUTHORIZATION_TYPE_CANCEL_UNBONDING_DELEGATION + \
                                                1))

#define cosmos_staking_v1beta1_StakeAuthorization_authorization_type_ENUMTYPE cosmos_staking_v1beta1_AuthorizationType

/* Initializer values for message structs */
#define cosmos_staking_v1beta1_StakeAuthorization_init_default                   \
    {                                                                            \
        false, cosmos_base_v1beta1_Coin_init_default, 0,                         \
            {cosmos_staking_v1beta1_StakeAuthorization_Validators_init_default}, \
            _cosmos_staking_v1beta1_AuthorizationType_MIN                        \
    }
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_init_default \
    {                                                                     \
        { {NULL}, NULL }                                                  \
    }
#define cosmos_staking_v1beta1_StakeAuthorization_init_zero                                                             \
    {                                                                                                                   \
        false, cosmos_base_v1beta1_Coin_init_zero, 0, {cosmos_staking_v1beta1_StakeAuthorization_Validators_init_zero}, \
            _cosmos_staking_v1beta1_AuthorizationType_MIN                                                               \
    }
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_init_zero \
    {                                                                  \
        { {NULL}, NULL }                                               \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_address_tag 1
#define cosmos_staking_v1beta1_StakeAuthorization_max_tokens_tag 1
#define cosmos_staking_v1beta1_StakeAuthorization_allow_list_tag 2
#define cosmos_staking_v1beta1_StakeAuthorization_deny_list_tag 3
#define cosmos_staking_v1beta1_StakeAuthorization_authorization_type_tag 4

/* Struct field encoding specification for nanopb */
#define cosmos_staking_v1beta1_StakeAuthorization_FIELDLIST(X, a)                    \
    X(a, STATIC, OPTIONAL, MESSAGE, max_tokens, 1)                                   \
    X(a, STATIC, ONEOF, MESSAGE, (validators, allow_list, validators.allow_list), 2) \
    X(a, STATIC, ONEOF, MESSAGE, (validators, deny_list, validators.deny_list), 3)   \
    X(a, STATIC, SINGULAR, UENUM, authorization_type, 4)
#define cosmos_staking_v1beta1_StakeAuthorization_CALLBACK NULL
#define cosmos_staking_v1beta1_StakeAuthorization_DEFAULT NULL
#define cosmos_staking_v1beta1_StakeAuthorization_max_tokens_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_staking_v1beta1_StakeAuthorization_validators_allow_list_MSGTYPE \
    cosmos_staking_v1beta1_StakeAuthorization_Validators
#define cosmos_staking_v1beta1_StakeAuthorization_validators_deny_list_MSGTYPE \
    cosmos_staking_v1beta1_StakeAuthorization_Validators

#define cosmos_staking_v1beta1_StakeAuthorization_Validators_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, STRING, address, 1)
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_CALLBACK pb_default_field_callback
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_DEFAULT NULL

extern const pb_msgdesc_t cosmos_staking_v1beta1_StakeAuthorization_msg;
extern const pb_msgdesc_t cosmos_staking_v1beta1_StakeAuthorization_Validators_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_staking_v1beta1_StakeAuthorization_fields &cosmos_staking_v1beta1_StakeAuthorization_msg
#define cosmos_staking_v1beta1_StakeAuthorization_Validators_fields &cosmos_staking_v1beta1_StakeAuthorization_Validators_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_staking_v1beta1_StakeAuthorization_size depends on runtime parameters */
/* cosmos_staking_v1beta1_StakeAuthorization_Validators_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
