/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_CORE_CONNECTION_V1_IBC_CORE_CONNECTION_V1_GENESIS_PB_H_INCLUDED
#define PB_IBC_CORE_CONNECTION_V1_IBC_CORE_CONNECTION_V1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "ibc/core/connection/v1/connection.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* GenesisState defines the ibc connection submodule's genesis state. */
typedef struct _ibc_core_connection_v1_GenesisState {
    pb_callback_t connections;
    pb_callback_t client_connection_paths;
    /* the sequence for the next generated connection identifier */
    uint64_t next_connection_sequence;
    bool has_params;
    ibc_core_connection_v1_Params params;
} ibc_core_connection_v1_GenesisState;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ibc_core_connection_v1_GenesisState_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, 0, false, ibc_core_connection_v1_Params_init_default }
#define ibc_core_connection_v1_GenesisState_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, 0, false, ibc_core_connection_v1_Params_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_core_connection_v1_GenesisState_connections_tag 1
#define ibc_core_connection_v1_GenesisState_client_connection_paths_tag 2
#define ibc_core_connection_v1_GenesisState_next_connection_sequence_tag 3
#define ibc_core_connection_v1_GenesisState_params_tag 4

/* Struct field encoding specification for nanopb */
#define ibc_core_connection_v1_GenesisState_FIELDLIST(X, a)       \
    X(a, CALLBACK, REPEATED, MESSAGE, connections, 1)             \
    X(a, CALLBACK, REPEATED, MESSAGE, client_connection_paths, 2) \
    X(a, STATIC, SINGULAR, UINT64, next_connection_sequence, 3)   \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 4)
#define ibc_core_connection_v1_GenesisState_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_GenesisState_DEFAULT NULL
#define ibc_core_connection_v1_GenesisState_connections_MSGTYPE ibc_core_connection_v1_IdentifiedConnection
#define ibc_core_connection_v1_GenesisState_client_connection_paths_MSGTYPE ibc_core_connection_v1_ConnectionPaths
#define ibc_core_connection_v1_GenesisState_params_MSGTYPE ibc_core_connection_v1_Params

extern const pb_msgdesc_t ibc_core_connection_v1_GenesisState_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_core_connection_v1_GenesisState_fields &ibc_core_connection_v1_GenesisState_msg

/* Maximum encoded size of messages (where known) */
/* ibc_core_connection_v1_GenesisState_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
