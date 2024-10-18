/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_LIGHTCLIENTS_SOLOMACHINE_V2_IBC_LIGHTCLIENTS_SOLOMACHINE_V2_SOLOMACHINE_PB_H_INCLUDED
#define PB_IBC_LIGHTCLIENTS_SOLOMACHINE_V2_IBC_LIGHTCLIENTS_SOLOMACHINE_V2_SOLOMACHINE_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "google/protobuf/any.pb.h"
#include "ibc/core/channel/v1/channel.pb.h"
#include "ibc/core/connection/v1/connection.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* DataType defines the type of solo machine proof being created. This is done
 to preserve uniqueness of different data sign byte encodings. */
typedef enum _ibc_lightclients_solomachine_v2_DataType {
    /* Default State */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_UNINITIALIZED_UNSPECIFIED = 0,
    /* Data type for client state verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_CLIENT_STATE = 1,
    /* Data type for consensus state verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_CONSENSUS_STATE = 2,
    /* Data type for connection state verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_CONNECTION_STATE = 3,
    /* Data type for channel state verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_CHANNEL_STATE = 4,
    /* Data type for packet commitment verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_PACKET_COMMITMENT = 5,
    /* Data type for packet acknowledgement verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_PACKET_ACKNOWLEDGEMENT = 6,
    /* Data type for packet receipt absence verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_PACKET_RECEIPT_ABSENCE = 7,
    /* Data type for next sequence recv verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_NEXT_SEQUENCE_RECV = 8,
    /* Data type for header verification */
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_HEADER = 9
} ibc_lightclients_solomachine_v2_DataType;

/* Struct definitions */
/* ConsensusState defines a solo machine consensus state. The sequence of a
 consensus state is contained in the "height" key used in storing the
 consensus state. */
typedef struct _ibc_lightclients_solomachine_v2_ConsensusState {
    /* public key of the solo machine */
    bool has_public_key;
    google_protobuf_Any public_key;
    /* diversifier allows the same public key to be re-used across different solo
 machine clients (potentially on different chains) without being considered
 misbehaviour. */
    pb_callback_t diversifier;
    uint64_t timestamp;
} ibc_lightclients_solomachine_v2_ConsensusState;

/* ClientState defines a solo machine client that tracks the current consensus
 state and if the client is frozen. */
typedef struct _ibc_lightclients_solomachine_v2_ClientState {
    /* latest sequence of the client state */
    uint64_t sequence;
    /* frozen sequence of the solo machine */
    bool is_frozen;
    bool has_consensus_state;
    ibc_lightclients_solomachine_v2_ConsensusState consensus_state;
    /* when set to true, will allow governance to update a solo machine client.
 The client will be unfrozen if it is frozen. */
    bool allow_update_after_proposal;
} ibc_lightclients_solomachine_v2_ClientState;

/* Header defines a solo machine consensus header */
typedef struct _ibc_lightclients_solomachine_v2_Header {
    /* sequence to update solo machine public key at */
    uint64_t sequence;
    uint64_t timestamp;
    pb_callback_t signature;
    bool has_new_public_key;
    google_protobuf_Any new_public_key;
    pb_callback_t new_diversifier;
} ibc_lightclients_solomachine_v2_Header;

/* SignatureAndData contains a signature and the data signed over to create that
 signature. */
typedef struct _ibc_lightclients_solomachine_v2_SignatureAndData {
    pb_callback_t signature;
    ibc_lightclients_solomachine_v2_DataType data_type;
    pb_callback_t data;
    uint64_t timestamp;
} ibc_lightclients_solomachine_v2_SignatureAndData;

/* Misbehaviour defines misbehaviour for a solo machine which consists
 of a sequence and two signatures over different messages at that sequence. */
typedef struct _ibc_lightclients_solomachine_v2_Misbehaviour {
    pb_callback_t client_id;
    uint64_t sequence;
    bool has_signature_one;
    ibc_lightclients_solomachine_v2_SignatureAndData signature_one;
    bool has_signature_two;
    ibc_lightclients_solomachine_v2_SignatureAndData signature_two;
} ibc_lightclients_solomachine_v2_Misbehaviour;

/* TimestampedSignatureData contains the signature data and the timestamp of the
 signature. */
typedef struct _ibc_lightclients_solomachine_v2_TimestampedSignatureData {
    pb_callback_t signature_data;
    uint64_t timestamp;
} ibc_lightclients_solomachine_v2_TimestampedSignatureData;

/* SignBytes defines the signed bytes used for signature verification. */
typedef struct _ibc_lightclients_solomachine_v2_SignBytes {
    uint64_t sequence;
    uint64_t timestamp;
    pb_callback_t diversifier;
    /* type of the data used */
    ibc_lightclients_solomachine_v2_DataType data_type;
    /* marshaled data */
    pb_callback_t data;
} ibc_lightclients_solomachine_v2_SignBytes;

/* HeaderData returns the SignBytes data for update verification. */
typedef struct _ibc_lightclients_solomachine_v2_HeaderData {
    /* header public key */
    bool has_new_pub_key;
    google_protobuf_Any new_pub_key;
    /* header diversifier */
    pb_callback_t new_diversifier;
} ibc_lightclients_solomachine_v2_HeaderData;

/* ClientStateData returns the SignBytes data for client state verification. */
typedef struct _ibc_lightclients_solomachine_v2_ClientStateData {
    pb_callback_t path;
    bool has_client_state;
    google_protobuf_Any client_state;
} ibc_lightclients_solomachine_v2_ClientStateData;

/* ConsensusStateData returns the SignBytes data for consensus state
 verification. */
typedef struct _ibc_lightclients_solomachine_v2_ConsensusStateData {
    pb_callback_t path;
    bool has_consensus_state;
    google_protobuf_Any consensus_state;
} ibc_lightclients_solomachine_v2_ConsensusStateData;

/* ConnectionStateData returns the SignBytes data for connection state
 verification. */
typedef struct _ibc_lightclients_solomachine_v2_ConnectionStateData {
    pb_callback_t path;
    bool has_connection;
    ibc_core_connection_v1_ConnectionEnd connection;
} ibc_lightclients_solomachine_v2_ConnectionStateData;

/* ChannelStateData returns the SignBytes data for channel state
 verification. */
typedef struct _ibc_lightclients_solomachine_v2_ChannelStateData {
    pb_callback_t path;
    bool has_channel;
    ibc_core_channel_v1_Channel channel;
} ibc_lightclients_solomachine_v2_ChannelStateData;

/* PacketCommitmentData returns the SignBytes data for packet commitment
 verification. */
typedef struct _ibc_lightclients_solomachine_v2_PacketCommitmentData {
    pb_callback_t path;
    pb_callback_t commitment;
} ibc_lightclients_solomachine_v2_PacketCommitmentData;

/* PacketAcknowledgementData returns the SignBytes data for acknowledgement
 verification. */
typedef struct _ibc_lightclients_solomachine_v2_PacketAcknowledgementData {
    pb_callback_t path;
    pb_callback_t acknowledgement;
} ibc_lightclients_solomachine_v2_PacketAcknowledgementData;

/* PacketReceiptAbsenceData returns the SignBytes data for
 packet receipt absence verification. */
typedef struct _ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData {
    pb_callback_t path;
} ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData;

/* NextSequenceRecvData returns the SignBytes data for verification of the next
 sequence to be received. */
typedef struct _ibc_lightclients_solomachine_v2_NextSequenceRecvData {
    pb_callback_t path;
    uint64_t next_seq_recv;
} ibc_lightclients_solomachine_v2_NextSequenceRecvData;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _ibc_lightclients_solomachine_v2_DataType_MIN \
    ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_UNINITIALIZED_UNSPECIFIED
#define _ibc_lightclients_solomachine_v2_DataType_MAX ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_HEADER
#define _ibc_lightclients_solomachine_v2_DataType_ARRAYSIZE \
    ((ibc_lightclients_solomachine_v2_DataType)(ibc_lightclients_solomachine_v2_DataType_DATA_TYPE_HEADER + 1))

#define ibc_lightclients_solomachine_v2_SignatureAndData_data_type_ENUMTYPE ibc_lightclients_solomachine_v2_DataType

#define ibc_lightclients_solomachine_v2_SignBytes_data_type_ENUMTYPE ibc_lightclients_solomachine_v2_DataType

/* Initializer values for message structs */
#define ibc_lightclients_solomachine_v2_ClientState_init_default \
    { 0, 0, false, ibc_lightclients_solomachine_v2_ConsensusState_init_default, 0 }
#define ibc_lightclients_solomachine_v2_ConsensusState_init_default \
    { false, google_protobuf_Any_init_default, {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_Header_init_default                             \
    {                                                                                   \
        0, 0, {{NULL}, NULL}, false, google_protobuf_Any_init_default, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_Misbehaviour_init_default                                       \
    {                                                                                                   \
        {{NULL}, NULL}, 0, false, ibc_lightclients_solomachine_v2_SignatureAndData_init_default, false, \
            ibc_lightclients_solomachine_v2_SignatureAndData_init_default                               \
    }
#define ibc_lightclients_solomachine_v2_SignatureAndData_init_default \
    { {{NULL}, NULL}, _ibc_lightclients_solomachine_v2_DataType_MIN, {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_init_default \
    { {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_SignBytes_init_default                                \
    {                                                                                         \
        0, 0, {{NULL}, NULL}, _ibc_lightclients_solomachine_v2_DataType_MIN, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_HeaderData_init_default   \
    {                                                             \
        false, google_protobuf_Any_init_default, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_ClientStateData_init_default \
    { {{NULL}, NULL}, false, google_protobuf_Any_init_default }
#define ibc_lightclients_solomachine_v2_ConsensusStateData_init_default \
    { {{NULL}, NULL}, false, google_protobuf_Any_init_default }
#define ibc_lightclients_solomachine_v2_ConnectionStateData_init_default \
    { {{NULL}, NULL}, false, ibc_core_connection_v1_ConnectionEnd_init_default }
#define ibc_lightclients_solomachine_v2_ChannelStateData_init_default \
    { {{NULL}, NULL}, false, ibc_core_channel_v1_Channel_init_default }
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_init_default \
    {                                                                     \
        {{NULL}, NULL}, { {NULL}, NULL }                                  \
    }
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_init_default \
    {                                                                          \
        {{NULL}, NULL}, { {NULL}, NULL }                                       \
    }
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_init_default \
    {                                                                         \
        { {NULL}, NULL }                                                      \
    }
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_init_default \
    { {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_ClientState_init_zero \
    { 0, 0, false, ibc_lightclients_solomachine_v2_ConsensusState_init_zero, 0 }
#define ibc_lightclients_solomachine_v2_ConsensusState_init_zero \
    { false, google_protobuf_Any_init_zero, {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_Header_init_zero                             \
    {                                                                                \
        0, 0, {{NULL}, NULL}, false, google_protobuf_Any_init_zero, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_Misbehaviour_init_zero                                       \
    {                                                                                                \
        {{NULL}, NULL}, 0, false, ibc_lightclients_solomachine_v2_SignatureAndData_init_zero, false, \
            ibc_lightclients_solomachine_v2_SignatureAndData_init_zero                               \
    }
#define ibc_lightclients_solomachine_v2_SignatureAndData_init_zero \
    { {{NULL}, NULL}, _ibc_lightclients_solomachine_v2_DataType_MIN, {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_init_zero \
    { {{NULL}, NULL}, 0 }
#define ibc_lightclients_solomachine_v2_SignBytes_init_zero                                   \
    {                                                                                         \
        0, 0, {{NULL}, NULL}, _ibc_lightclients_solomachine_v2_DataType_MIN, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_HeaderData_init_zero   \
    {                                                          \
        false, google_protobuf_Any_init_zero, { {NULL}, NULL } \
    }
#define ibc_lightclients_solomachine_v2_ClientStateData_init_zero \
    { {{NULL}, NULL}, false, google_protobuf_Any_init_zero }
#define ibc_lightclients_solomachine_v2_ConsensusStateData_init_zero \
    { {{NULL}, NULL}, false, google_protobuf_Any_init_zero }
#define ibc_lightclients_solomachine_v2_ConnectionStateData_init_zero \
    { {{NULL}, NULL}, false, ibc_core_connection_v1_ConnectionEnd_init_zero }
#define ibc_lightclients_solomachine_v2_ChannelStateData_init_zero \
    { {{NULL}, NULL}, false, ibc_core_channel_v1_Channel_init_zero }
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_init_zero \
    {                                                                  \
        {{NULL}, NULL}, { {NULL}, NULL }                               \
    }
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_init_zero \
    {                                                                       \
        {{NULL}, NULL}, { {NULL}, NULL }                                    \
    }
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_init_zero \
    {                                                                      \
        { {NULL}, NULL }                                                   \
    }
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_init_zero \
    { {{NULL}, NULL}, 0 }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_lightclients_solomachine_v2_ConsensusState_public_key_tag 1
#define ibc_lightclients_solomachine_v2_ConsensusState_diversifier_tag 2
#define ibc_lightclients_solomachine_v2_ConsensusState_timestamp_tag 3
#define ibc_lightclients_solomachine_v2_ClientState_sequence_tag 1
#define ibc_lightclients_solomachine_v2_ClientState_is_frozen_tag 2
#define ibc_lightclients_solomachine_v2_ClientState_consensus_state_tag 3
#define ibc_lightclients_solomachine_v2_ClientState_allow_update_after_proposal_tag 4
#define ibc_lightclients_solomachine_v2_Header_sequence_tag 1
#define ibc_lightclients_solomachine_v2_Header_timestamp_tag 2
#define ibc_lightclients_solomachine_v2_Header_signature_tag 3
#define ibc_lightclients_solomachine_v2_Header_new_public_key_tag 4
#define ibc_lightclients_solomachine_v2_Header_new_diversifier_tag 5
#define ibc_lightclients_solomachine_v2_SignatureAndData_signature_tag 1
#define ibc_lightclients_solomachine_v2_SignatureAndData_data_type_tag 2
#define ibc_lightclients_solomachine_v2_SignatureAndData_data_tag 3
#define ibc_lightclients_solomachine_v2_SignatureAndData_timestamp_tag 4
#define ibc_lightclients_solomachine_v2_Misbehaviour_client_id_tag 1
#define ibc_lightclients_solomachine_v2_Misbehaviour_sequence_tag 2
#define ibc_lightclients_solomachine_v2_Misbehaviour_signature_one_tag 3
#define ibc_lightclients_solomachine_v2_Misbehaviour_signature_two_tag 4
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_signature_data_tag 1
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_timestamp_tag 2
#define ibc_lightclients_solomachine_v2_SignBytes_sequence_tag 1
#define ibc_lightclients_solomachine_v2_SignBytes_timestamp_tag 2
#define ibc_lightclients_solomachine_v2_SignBytes_diversifier_tag 3
#define ibc_lightclients_solomachine_v2_SignBytes_data_type_tag 4
#define ibc_lightclients_solomachine_v2_SignBytes_data_tag 5
#define ibc_lightclients_solomachine_v2_HeaderData_new_pub_key_tag 1
#define ibc_lightclients_solomachine_v2_HeaderData_new_diversifier_tag 2
#define ibc_lightclients_solomachine_v2_ClientStateData_path_tag 1
#define ibc_lightclients_solomachine_v2_ClientStateData_client_state_tag 2
#define ibc_lightclients_solomachine_v2_ConsensusStateData_path_tag 1
#define ibc_lightclients_solomachine_v2_ConsensusStateData_consensus_state_tag 2
#define ibc_lightclients_solomachine_v2_ConnectionStateData_path_tag 1
#define ibc_lightclients_solomachine_v2_ConnectionStateData_connection_tag 2
#define ibc_lightclients_solomachine_v2_ChannelStateData_path_tag 1
#define ibc_lightclients_solomachine_v2_ChannelStateData_channel_tag 2
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_path_tag 1
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_commitment_tag 2
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_path_tag 1
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_acknowledgement_tag 2
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_path_tag 1
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_path_tag 1
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_next_seq_recv_tag 2

/* Struct field encoding specification for nanopb */
#define ibc_lightclients_solomachine_v2_ClientState_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, sequence, 1)                     \
    X(a, STATIC, SINGULAR, BOOL, is_frozen, 2)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, consensus_state, 3)             \
    X(a, STATIC, SINGULAR, BOOL, allow_update_after_proposal, 4)
#define ibc_lightclients_solomachine_v2_ClientState_CALLBACK NULL
#define ibc_lightclients_solomachine_v2_ClientState_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ClientState_consensus_state_MSGTYPE ibc_lightclients_solomachine_v2_ConsensusState

#define ibc_lightclients_solomachine_v2_ConsensusState_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, public_key, 1)                     \
    X(a, CALLBACK, SINGULAR, STRING, diversifier, 2)                   \
    X(a, STATIC, SINGULAR, UINT64, timestamp, 3)
#define ibc_lightclients_solomachine_v2_ConsensusState_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_ConsensusState_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ConsensusState_public_key_MSGTYPE google_protobuf_Any

#define ibc_lightclients_solomachine_v2_Header_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, sequence, 1)                \
    X(a, STATIC, SINGULAR, UINT64, timestamp, 2)               \
    X(a, CALLBACK, SINGULAR, BYTES, signature, 3)              \
    X(a, STATIC, OPTIONAL, MESSAGE, new_public_key, 4)         \
    X(a, CALLBACK, SINGULAR, STRING, new_diversifier, 5)
#define ibc_lightclients_solomachine_v2_Header_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_Header_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_Header_new_public_key_MSGTYPE google_protobuf_Any

#define ibc_lightclients_solomachine_v2_Misbehaviour_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, client_id, 1)                   \
    X(a, STATIC, SINGULAR, UINT64, sequence, 2)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, signature_one, 3)                \
    X(a, STATIC, OPTIONAL, MESSAGE, signature_two, 4)
#define ibc_lightclients_solomachine_v2_Misbehaviour_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_Misbehaviour_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_Misbehaviour_signature_one_MSGTYPE ibc_lightclients_solomachine_v2_SignatureAndData
#define ibc_lightclients_solomachine_v2_Misbehaviour_signature_two_MSGTYPE ibc_lightclients_solomachine_v2_SignatureAndData

#define ibc_lightclients_solomachine_v2_SignatureAndData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, signature, 1)                        \
    X(a, STATIC, SINGULAR, UENUM, data_type, 2)                          \
    X(a, CALLBACK, SINGULAR, BYTES, data, 3)                             \
    X(a, STATIC, SINGULAR, UINT64, timestamp, 4)
#define ibc_lightclients_solomachine_v2_SignatureAndData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_SignatureAndData_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, signature_data, 1)                           \
    X(a, STATIC, SINGULAR, UINT64, timestamp, 2)
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_SignBytes_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, sequence, 1)                   \
    X(a, STATIC, SINGULAR, UINT64, timestamp, 2)                  \
    X(a, CALLBACK, SINGULAR, STRING, diversifier, 3)              \
    X(a, STATIC, SINGULAR, UENUM, data_type, 4)                   \
    X(a, CALLBACK, SINGULAR, BYTES, data, 5)
#define ibc_lightclients_solomachine_v2_SignBytes_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_SignBytes_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_HeaderData_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, new_pub_key, 1)                \
    X(a, CALLBACK, SINGULAR, STRING, new_diversifier, 2)
#define ibc_lightclients_solomachine_v2_HeaderData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_HeaderData_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_HeaderData_new_pub_key_MSGTYPE google_protobuf_Any

#define ibc_lightclients_solomachine_v2_ClientStateData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                            \
    X(a, STATIC, OPTIONAL, MESSAGE, client_state, 2)
#define ibc_lightclients_solomachine_v2_ClientStateData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_ClientStateData_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ClientStateData_client_state_MSGTYPE google_protobuf_Any

#define ibc_lightclients_solomachine_v2_ConsensusStateData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                               \
    X(a, STATIC, OPTIONAL, MESSAGE, consensus_state, 2)
#define ibc_lightclients_solomachine_v2_ConsensusStateData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_ConsensusStateData_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ConsensusStateData_consensus_state_MSGTYPE google_protobuf_Any

#define ibc_lightclients_solomachine_v2_ConnectionStateData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                                \
    X(a, STATIC, OPTIONAL, MESSAGE, connection, 2)
#define ibc_lightclients_solomachine_v2_ConnectionStateData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_ConnectionStateData_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ConnectionStateData_connection_MSGTYPE ibc_core_connection_v1_ConnectionEnd

#define ibc_lightclients_solomachine_v2_ChannelStateData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                             \
    X(a, STATIC, OPTIONAL, MESSAGE, channel, 2)
#define ibc_lightclients_solomachine_v2_ChannelStateData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_ChannelStateData_DEFAULT NULL
#define ibc_lightclients_solomachine_v2_ChannelStateData_channel_MSGTYPE ibc_core_channel_v1_Channel

#define ibc_lightclients_solomachine_v2_PacketCommitmentData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                                 \
    X(a, CALLBACK, SINGULAR, BYTES, commitment, 2)
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                                      \
    X(a, CALLBACK, SINGULAR, BYTES, acknowledgement, 2)
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, path, 1)
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_DEFAULT NULL

#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, path, 1)                                 \
    X(a, STATIC, SINGULAR, UINT64, next_seq_recv, 2)
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_CALLBACK pb_default_field_callback
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_DEFAULT NULL

extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ClientState_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ConsensusState_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_Header_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_Misbehaviour_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_SignatureAndData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_TimestampedSignatureData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_SignBytes_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_HeaderData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ClientStateData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ConsensusStateData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ConnectionStateData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_ChannelStateData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_PacketCommitmentData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_PacketAcknowledgementData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_msg;
extern const pb_msgdesc_t ibc_lightclients_solomachine_v2_NextSequenceRecvData_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_lightclients_solomachine_v2_ClientState_fields &ibc_lightclients_solomachine_v2_ClientState_msg
#define ibc_lightclients_solomachine_v2_ConsensusState_fields &ibc_lightclients_solomachine_v2_ConsensusState_msg
#define ibc_lightclients_solomachine_v2_Header_fields &ibc_lightclients_solomachine_v2_Header_msg
#define ibc_lightclients_solomachine_v2_Misbehaviour_fields &ibc_lightclients_solomachine_v2_Misbehaviour_msg
#define ibc_lightclients_solomachine_v2_SignatureAndData_fields &ibc_lightclients_solomachine_v2_SignatureAndData_msg
#define ibc_lightclients_solomachine_v2_TimestampedSignatureData_fields \
    &ibc_lightclients_solomachine_v2_TimestampedSignatureData_msg
#define ibc_lightclients_solomachine_v2_SignBytes_fields &ibc_lightclients_solomachine_v2_SignBytes_msg
#define ibc_lightclients_solomachine_v2_HeaderData_fields &ibc_lightclients_solomachine_v2_HeaderData_msg
#define ibc_lightclients_solomachine_v2_ClientStateData_fields &ibc_lightclients_solomachine_v2_ClientStateData_msg
#define ibc_lightclients_solomachine_v2_ConsensusStateData_fields &ibc_lightclients_solomachine_v2_ConsensusStateData_msg
#define ibc_lightclients_solomachine_v2_ConnectionStateData_fields &ibc_lightclients_solomachine_v2_ConnectionStateData_msg
#define ibc_lightclients_solomachine_v2_ChannelStateData_fields &ibc_lightclients_solomachine_v2_ChannelStateData_msg
#define ibc_lightclients_solomachine_v2_PacketCommitmentData_fields &ibc_lightclients_solomachine_v2_PacketCommitmentData_msg
#define ibc_lightclients_solomachine_v2_PacketAcknowledgementData_fields \
    &ibc_lightclients_solomachine_v2_PacketAcknowledgementData_msg
#define ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_fields \
    &ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_msg
#define ibc_lightclients_solomachine_v2_NextSequenceRecvData_fields &ibc_lightclients_solomachine_v2_NextSequenceRecvData_msg

/* Maximum encoded size of messages (where known) */
/* ibc_lightclients_solomachine_v2_ClientState_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_ConsensusState_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_Header_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_Misbehaviour_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_SignatureAndData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_TimestampedSignatureData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_SignBytes_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_HeaderData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_ClientStateData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_ConsensusStateData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_ConnectionStateData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_ChannelStateData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_PacketCommitmentData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_PacketAcknowledgementData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_PacketReceiptAbsenceData_size depends on runtime parameters */
/* ibc_lightclients_solomachine_v2_NextSequenceRecvData_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
