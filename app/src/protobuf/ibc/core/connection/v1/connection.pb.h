/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_CORE_CONNECTION_V1_IBC_CORE_CONNECTION_V1_CONNECTION_PB_H_INCLUDED
#define PB_IBC_CORE_CONNECTION_V1_IBC_CORE_CONNECTION_V1_CONNECTION_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "ibc/core/commitment/v1/commitment.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* State defines if a connection is in one of the following states:
 INIT, TRYOPEN, OPEN or UNINITIALIZED. */
typedef enum _ibc_core_connection_v1_State {
    /* Default State */
    ibc_core_connection_v1_State_STATE_UNINITIALIZED_UNSPECIFIED = 0,
    /* A connection end has just started the opening handshake. */
    ibc_core_connection_v1_State_STATE_INIT = 1,
    /* A connection end has acknowledged the handshake step on the counterparty
 chain. */
    ibc_core_connection_v1_State_STATE_TRYOPEN = 2,
    /* A connection end has completed the handshake. */
    ibc_core_connection_v1_State_STATE_OPEN = 3
} ibc_core_connection_v1_State;

/* Struct definitions */
/* Counterparty defines the counterparty chain associated with a connection end. */
typedef struct _ibc_core_connection_v1_Counterparty {
    /* identifies the client on the counterparty chain associated with a given
 connection. */
    pb_callback_t client_id;
    /* identifies the connection end on the counterparty chain associated with a
 given connection. */
    pb_callback_t connection_id;
    /* commitment merkle prefix of the counterparty chain. */
    bool has_prefix;
    ibc_core_commitment_v1_MerklePrefix prefix;
} ibc_core_connection_v1_Counterparty;

/* ConnectionEnd defines a stateful object on a chain connected to another
 separate one.
 NOTE: there must only be 2 defined ConnectionEnds to establish
 a connection between two chains. */
typedef struct _ibc_core_connection_v1_ConnectionEnd {
    /* client associated with this connection. */
    pb_callback_t client_id;
    /* IBC version which can be utilised to determine encodings or protocols for
 channels or packets utilising this connection. */
    pb_callback_t versions;
    /* current state of the connection end. */
    ibc_core_connection_v1_State state;
    /* counterparty chain associated with this connection. */
    bool has_counterparty;
    ibc_core_connection_v1_Counterparty counterparty;
    /* delay period that must pass before a consensus state can be used for
 packet-verification NOTE: delay period logic is only implemented by some
 clients. */
    uint64_t delay_period;
} ibc_core_connection_v1_ConnectionEnd;

/* IdentifiedConnection defines a connection with additional connection
 identifier field. */
typedef struct _ibc_core_connection_v1_IdentifiedConnection {
    /* connection identifier. */
    pb_callback_t id;
    /* client associated with this connection. */
    pb_callback_t client_id;
    /* IBC version which can be utilised to determine encodings or protocols for
 channels or packets utilising this connection */
    pb_callback_t versions;
    /* current state of the connection end. */
    ibc_core_connection_v1_State state;
    /* counterparty chain associated with this connection. */
    bool has_counterparty;
    ibc_core_connection_v1_Counterparty counterparty;
    /* delay period associated with this connection. */
    uint64_t delay_period;
} ibc_core_connection_v1_IdentifiedConnection;

/* ClientPaths define all the connection paths for a client state. */
typedef struct _ibc_core_connection_v1_ClientPaths {
    /* list of connection paths */
    pb_callback_t paths;
} ibc_core_connection_v1_ClientPaths;

/* ConnectionPaths define all the connection paths for a given client state. */
typedef struct _ibc_core_connection_v1_ConnectionPaths {
    /* client state unique identifier */
    pb_callback_t client_id;
    /* list of connection paths */
    pb_callback_t paths;
} ibc_core_connection_v1_ConnectionPaths;

/* Version defines the versioning scheme used to negotiate the IBC verison in
 the connection handshake. */
typedef struct _ibc_core_connection_v1_Version {
    /* unique version identifier */
    pb_callback_t identifier;
    /* list of features compatible with the specified identifier */
    pb_callback_t features;
} ibc_core_connection_v1_Version;

/* Params defines the set of Connection parameters. */
typedef struct _ibc_core_connection_v1_Params {
    /* maximum expected time per block (in nanoseconds), used to enforce block delay. This parameter should reflect the
 largest amount of time that the chain might reasonably take to produce the next block under normal operating
 conditions. A safe choice is 3-5x the expected time per block. */
    uint64_t max_expected_time_per_block;
} ibc_core_connection_v1_Params;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _ibc_core_connection_v1_State_MIN ibc_core_connection_v1_State_STATE_UNINITIALIZED_UNSPECIFIED
#define _ibc_core_connection_v1_State_MAX ibc_core_connection_v1_State_STATE_OPEN
#define _ibc_core_connection_v1_State_ARRAYSIZE ((ibc_core_connection_v1_State)(ibc_core_connection_v1_State_STATE_OPEN + 1))

#define ibc_core_connection_v1_ConnectionEnd_state_ENUMTYPE ibc_core_connection_v1_State

#define ibc_core_connection_v1_IdentifiedConnection_state_ENUMTYPE ibc_core_connection_v1_State

/* Initializer values for message structs */
#define ibc_core_connection_v1_ConnectionEnd_init_default                         \
    {                                                                             \
        {{NULL}, NULL}, {{NULL}, NULL}, _ibc_core_connection_v1_State_MIN, false, \
            ibc_core_connection_v1_Counterparty_init_default, 0                   \
    }
#define ibc_core_connection_v1_IdentifiedConnection_init_default                                  \
    {                                                                                             \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, _ibc_core_connection_v1_State_MIN, false, \
            ibc_core_connection_v1_Counterparty_init_default, 0                                   \
    }
#define ibc_core_connection_v1_Counterparty_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, ibc_core_commitment_v1_MerklePrefix_init_default }
#define ibc_core_connection_v1_ClientPaths_init_default \
    {                                                   \
        { {NULL}, NULL }                                \
    }
#define ibc_core_connection_v1_ConnectionPaths_init_default \
    {                                                       \
        {{NULL}, NULL}, { {NULL}, NULL }                    \
    }
#define ibc_core_connection_v1_Version_init_default \
    {                                               \
        {{NULL}, NULL}, { {NULL}, NULL }            \
    }
#define ibc_core_connection_v1_Params_init_default \
    { 0 }
#define ibc_core_connection_v1_ConnectionEnd_init_zero                            \
    {                                                                             \
        {{NULL}, NULL}, {{NULL}, NULL}, _ibc_core_connection_v1_State_MIN, false, \
            ibc_core_connection_v1_Counterparty_init_zero, 0                      \
    }
#define ibc_core_connection_v1_IdentifiedConnection_init_zero                                     \
    {                                                                                             \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, _ibc_core_connection_v1_State_MIN, false, \
            ibc_core_connection_v1_Counterparty_init_zero, 0                                      \
    }
#define ibc_core_connection_v1_Counterparty_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, ibc_core_commitment_v1_MerklePrefix_init_zero }
#define ibc_core_connection_v1_ClientPaths_init_zero \
    {                                                \
        { {NULL}, NULL }                             \
    }
#define ibc_core_connection_v1_ConnectionPaths_init_zero \
    {                                                    \
        {{NULL}, NULL}, { {NULL}, NULL }                 \
    }
#define ibc_core_connection_v1_Version_init_zero \
    {                                            \
        {{NULL}, NULL}, { {NULL}, NULL }         \
    }
#define ibc_core_connection_v1_Params_init_zero \
    { 0 }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_core_connection_v1_Counterparty_client_id_tag 1
#define ibc_core_connection_v1_Counterparty_connection_id_tag 2
#define ibc_core_connection_v1_Counterparty_prefix_tag 3
#define ibc_core_connection_v1_ConnectionEnd_client_id_tag 1
#define ibc_core_connection_v1_ConnectionEnd_versions_tag 2
#define ibc_core_connection_v1_ConnectionEnd_state_tag 3
#define ibc_core_connection_v1_ConnectionEnd_counterparty_tag 4
#define ibc_core_connection_v1_ConnectionEnd_delay_period_tag 5
#define ibc_core_connection_v1_IdentifiedConnection_id_tag 1
#define ibc_core_connection_v1_IdentifiedConnection_client_id_tag 2
#define ibc_core_connection_v1_IdentifiedConnection_versions_tag 3
#define ibc_core_connection_v1_IdentifiedConnection_state_tag 4
#define ibc_core_connection_v1_IdentifiedConnection_counterparty_tag 5
#define ibc_core_connection_v1_IdentifiedConnection_delay_period_tag 6
#define ibc_core_connection_v1_ClientPaths_paths_tag 1
#define ibc_core_connection_v1_ConnectionPaths_client_id_tag 1
#define ibc_core_connection_v1_ConnectionPaths_paths_tag 2
#define ibc_core_connection_v1_Version_identifier_tag 1
#define ibc_core_connection_v1_Version_features_tag 2
#define ibc_core_connection_v1_Params_max_expected_time_per_block_tag 1

/* Struct field encoding specification for nanopb */
#define ibc_core_connection_v1_ConnectionEnd_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)           \
    X(a, CALLBACK, REPEATED, MESSAGE, versions, 2)           \
    X(a, STATIC, SINGULAR, UENUM, state, 3)                  \
    X(a, STATIC, OPTIONAL, MESSAGE, counterparty, 4)         \
    X(a, STATIC, SINGULAR, UINT64, delay_period, 5)
#define ibc_core_connection_v1_ConnectionEnd_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_ConnectionEnd_DEFAULT NULL
#define ibc_core_connection_v1_ConnectionEnd_versions_MSGTYPE ibc_core_connection_v1_Version
#define ibc_core_connection_v1_ConnectionEnd_counterparty_MSGTYPE ibc_core_connection_v1_Counterparty

#define ibc_core_connection_v1_IdentifiedConnection_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, id, 1)                         \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 2)                  \
    X(a, CALLBACK, REPEATED, MESSAGE, versions, 3)                  \
    X(a, STATIC, SINGULAR, UENUM, state, 4)                         \
    X(a, STATIC, OPTIONAL, MESSAGE, counterparty, 5)                \
    X(a, STATIC, SINGULAR, UINT64, delay_period, 6)
#define ibc_core_connection_v1_IdentifiedConnection_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_IdentifiedConnection_DEFAULT NULL
#define ibc_core_connection_v1_IdentifiedConnection_versions_MSGTYPE ibc_core_connection_v1_Version
#define ibc_core_connection_v1_IdentifiedConnection_counterparty_MSGTYPE ibc_core_connection_v1_Counterparty

#define ibc_core_connection_v1_Counterparty_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)          \
    X(a, CALLBACK, SINGULAR, STRING, connection_id, 2)      \
    X(a, STATIC, OPTIONAL, MESSAGE, prefix, 3)
#define ibc_core_connection_v1_Counterparty_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_Counterparty_DEFAULT NULL
#define ibc_core_connection_v1_Counterparty_prefix_MSGTYPE ibc_core_commitment_v1_MerklePrefix

#define ibc_core_connection_v1_ClientPaths_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, STRING, paths, 1)
#define ibc_core_connection_v1_ClientPaths_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_ClientPaths_DEFAULT NULL

#define ibc_core_connection_v1_ConnectionPaths_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)             \
    X(a, CALLBACK, REPEATED, STRING, paths, 2)
#define ibc_core_connection_v1_ConnectionPaths_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_ConnectionPaths_DEFAULT NULL

#define ibc_core_connection_v1_Version_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, identifier, 1)    \
    X(a, CALLBACK, REPEATED, STRING, features, 2)
#define ibc_core_connection_v1_Version_CALLBACK pb_default_field_callback
#define ibc_core_connection_v1_Version_DEFAULT NULL

#define ibc_core_connection_v1_Params_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UINT64, max_expected_time_per_block, 1)
#define ibc_core_connection_v1_Params_CALLBACK NULL
#define ibc_core_connection_v1_Params_DEFAULT NULL

extern const pb_msgdesc_t ibc_core_connection_v1_ConnectionEnd_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_IdentifiedConnection_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_Counterparty_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_ClientPaths_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_ConnectionPaths_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_Version_msg;
extern const pb_msgdesc_t ibc_core_connection_v1_Params_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_core_connection_v1_ConnectionEnd_fields &ibc_core_connection_v1_ConnectionEnd_msg
#define ibc_core_connection_v1_IdentifiedConnection_fields &ibc_core_connection_v1_IdentifiedConnection_msg
#define ibc_core_connection_v1_Counterparty_fields &ibc_core_connection_v1_Counterparty_msg
#define ibc_core_connection_v1_ClientPaths_fields &ibc_core_connection_v1_ClientPaths_msg
#define ibc_core_connection_v1_ConnectionPaths_fields &ibc_core_connection_v1_ConnectionPaths_msg
#define ibc_core_connection_v1_Version_fields &ibc_core_connection_v1_Version_msg
#define ibc_core_connection_v1_Params_fields &ibc_core_connection_v1_Params_msg

/* Maximum encoded size of messages (where known) */
/* ibc_core_connection_v1_ConnectionEnd_size depends on runtime parameters */
/* ibc_core_connection_v1_IdentifiedConnection_size depends on runtime parameters */
/* ibc_core_connection_v1_Counterparty_size depends on runtime parameters */
/* ibc_core_connection_v1_ClientPaths_size depends on runtime parameters */
/* ibc_core_connection_v1_ConnectionPaths_size depends on runtime parameters */
/* ibc_core_connection_v1_Version_size depends on runtime parameters */
#define IBC_CORE_CONNECTION_V1_IBC_CORE_CONNECTION_V1_CONNECTION_PB_H_MAX_SIZE ibc_core_connection_v1_Params_size
#define ibc_core_connection_v1_Params_size 11

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif