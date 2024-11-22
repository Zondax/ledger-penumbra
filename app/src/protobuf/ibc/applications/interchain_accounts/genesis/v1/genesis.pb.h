/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_APPLICATIONS_INTERCHAIN_ACCOUNTS_GENESIS_V1_IBC_APPLICATIONS_INTERCHAIN_ACCOUNTS_GENESIS_V1_GENESIS_PB_H_INCLUDED
#define PB_IBC_APPLICATIONS_INTERCHAIN_ACCOUNTS_GENESIS_V1_IBC_APPLICATIONS_INTERCHAIN_ACCOUNTS_GENESIS_V1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "ibc/applications/interchain_accounts/controller/v1/controller.pb.h"
#include "ibc/applications/interchain_accounts/host/v1/host.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* ControllerGenesisState defines the interchain accounts controller genesis state */
typedef struct _ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState {
    pb_callback_t active_channels;
    pb_callback_t interchain_accounts;
    pb_callback_t ports;
    bool has_params;
    ibc_applications_interchain_accounts_controller_v1_Params params;
} ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState;

/* HostGenesisState defines the interchain accounts host genesis state */
typedef struct _ibc_applications_interchain_accounts_genesis_v1_HostGenesisState {
    pb_callback_t active_channels;
    pb_callback_t interchain_accounts;
    pb_callback_t port;
    bool has_params;
    ibc_applications_interchain_accounts_host_v1_Params params;
} ibc_applications_interchain_accounts_genesis_v1_HostGenesisState;

/* GenesisState defines the interchain accounts genesis state */
typedef struct _ibc_applications_interchain_accounts_genesis_v1_GenesisState {
    bool has_controller_genesis_state;
    ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState controller_genesis_state;
    bool has_host_genesis_state;
    ibc_applications_interchain_accounts_genesis_v1_HostGenesisState host_genesis_state;
} ibc_applications_interchain_accounts_genesis_v1_GenesisState;

/* ActiveChannel contains a connection ID, port ID and associated active channel ID, as well as a boolean flag to
 indicate if the channel is middleware enabled */
typedef struct _ibc_applications_interchain_accounts_genesis_v1_ActiveChannel {
    pb_callback_t connection_id;
    pb_callback_t port_id;
    pb_callback_t channel_id;
    bool is_middleware_enabled;
} ibc_applications_interchain_accounts_genesis_v1_ActiveChannel;

/* RegisteredInterchainAccount contains a connection ID, port ID and associated interchain account address */
typedef struct _ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount {
    pb_callback_t connection_id;
    pb_callback_t port_id;
    pb_callback_t account_address;
} ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_init_default                          \
    {                                                                                                      \
        false, ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_init_default, false, \
            ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_init_default                  \
    }
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_init_default \
    {                                                                                       \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false,                              \
            ibc_applications_interchain_accounts_controller_v1_Params_init_default          \
    }
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_init_default \
    {                                                                                 \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false,                        \
            ibc_applications_interchain_accounts_host_v1_Params_init_default          \
    }
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0 }
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_init_default \
    {                                                                                            \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }                                         \
    }
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_init_zero                          \
    {                                                                                                   \
        false, ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_init_zero, false, \
            ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_init_zero                  \
    }
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_init_zero \
    {                                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false,                           \
            ibc_applications_interchain_accounts_controller_v1_Params_init_zero          \
    }
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, false, ibc_applications_interchain_accounts_host_v1_Params_init_zero }
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0 }
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_init_zero \
    {                                                                                         \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL }                                      \
    }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_active_channels_tag 1
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_interchain_accounts_tag 2
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_ports_tag 3
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_params_tag 4
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_active_channels_tag 1
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_interchain_accounts_tag 2
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_port_tag 3
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_params_tag 4
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_controller_genesis_state_tag 1
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_host_genesis_state_tag 2
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_connection_id_tag 1
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_port_id_tag 2
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_channel_id_tag 3
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_is_middleware_enabled_tag 4
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_connection_id_tag 1
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_port_id_tag 2
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_account_address_tag 3

/* Struct field encoding specification for nanopb */
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, controller_genesis_state, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, host_genesis_state, 2)
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_CALLBACK NULL
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_DEFAULT NULL
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_controller_genesis_state_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_host_genesis_state_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_HostGenesisState

#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, active_channels, 1)                                      \
    X(a, CALLBACK, REPEATED, MESSAGE, interchain_accounts, 2)                                  \
    X(a, CALLBACK, REPEATED, STRING, ports, 3)                                                 \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 4)
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_CALLBACK pb_default_field_callback
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_DEFAULT NULL
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_active_channels_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_ActiveChannel
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_interchain_accounts_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_params_MSGTYPE \
    ibc_applications_interchain_accounts_controller_v1_Params

#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, active_channels, 1)                                \
    X(a, CALLBACK, REPEATED, MESSAGE, interchain_accounts, 2)                            \
    X(a, CALLBACK, SINGULAR, STRING, port, 3)                                            \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 4)
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_CALLBACK pb_default_field_callback
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_DEFAULT NULL
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_active_channels_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_ActiveChannel
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_interchain_accounts_MSGTYPE \
    ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_params_MSGTYPE \
    ibc_applications_interchain_accounts_host_v1_Params

#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, connection_id, 1)                                \
    X(a, CALLBACK, SINGULAR, STRING, port_id, 2)                                      \
    X(a, CALLBACK, SINGULAR, STRING, channel_id, 3)                                   \
    X(a, STATIC, SINGULAR, BOOL, is_middleware_enabled, 4)
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_CALLBACK pb_default_field_callback
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_DEFAULT NULL

#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, connection_id, 1)                                              \
    X(a, CALLBACK, SINGULAR, STRING, port_id, 2)                                                    \
    X(a, CALLBACK, SINGULAR, STRING, account_address, 3)
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_CALLBACK pb_default_field_callback
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_DEFAULT NULL

extern const pb_msgdesc_t ibc_applications_interchain_accounts_genesis_v1_GenesisState_msg;
extern const pb_msgdesc_t ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_msg;
extern const pb_msgdesc_t ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_msg;
extern const pb_msgdesc_t ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_msg;
extern const pb_msgdesc_t ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_applications_interchain_accounts_genesis_v1_GenesisState_fields \
    &ibc_applications_interchain_accounts_genesis_v1_GenesisState_msg
#define ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_fields \
    &ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_msg
#define ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_fields \
    &ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_msg
#define ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_fields \
    &ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_msg
#define ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_fields \
    &ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_msg

/* Maximum encoded size of messages (where known) */
/* ibc_applications_interchain_accounts_genesis_v1_GenesisState_size depends on runtime parameters */
/* ibc_applications_interchain_accounts_genesis_v1_ControllerGenesisState_size depends on runtime parameters */
/* ibc_applications_interchain_accounts_genesis_v1_HostGenesisState_size depends on runtime parameters */
/* ibc_applications_interchain_accounts_genesis_v1_ActiveChannel_size depends on runtime parameters */
/* ibc_applications_interchain_accounts_genesis_v1_RegisteredInterchainAccount_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif