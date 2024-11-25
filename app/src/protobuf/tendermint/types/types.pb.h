/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_TENDERMINT_TYPES_TENDERMINT_TYPES_TYPES_PB_H_INCLUDED
#define PB_TENDERMINT_TYPES_TENDERMINT_TYPES_TYPES_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"
#include "google/protobuf/timestamp.pb.h"
#include "tendermint/crypto/proof.pb.h"
#include "tendermint/types/validator.pb.h"
#include "tendermint/version/types.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* BlockIdFlag indicates which BlcokID the signature is for */
typedef enum _tendermint_types_BlockIDFlag {
    tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_UNKNOWN = 0,
    tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_ABSENT = 1,
    tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_COMMIT = 2,
    tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_NIL = 3
} tendermint_types_BlockIDFlag;

/* SignedMsgType is a type of signed message in the consensus. */
typedef enum _tendermint_types_SignedMsgType {
    tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_UNKNOWN = 0,
    /* Votes */
    tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_PREVOTE = 1,
    tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_PRECOMMIT = 2,
    /* Proposals */
    tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_PROPOSAL = 32
} tendermint_types_SignedMsgType;

/* Struct definitions */
/* PartsetHeader */
typedef struct _tendermint_types_PartSetHeader {
    uint32_t total;
    pb_callback_t hash;
} tendermint_types_PartSetHeader;

typedef struct _tendermint_types_Part {
    uint32_t index;
    pb_callback_t bytes;
    bool has_proof;
    tendermint_crypto_Proof proof;
} tendermint_types_Part;

/* BlockID */
typedef struct _tendermint_types_BlockID {
    pb_callback_t hash;
    bool has_part_set_header;
    tendermint_types_PartSetHeader part_set_header;
} tendermint_types_BlockID;

/* Header defines the structure of a block header. */
typedef struct _tendermint_types_Header {
    /* basic block info */
    bool has_version;
    tendermint_version_Consensus version;
    pb_callback_t chain_id;
    int64_t height;
    bool has_time;
    google_protobuf_Timestamp time;
    /* prev block info */
    bool has_last_block_id;
    tendermint_types_BlockID last_block_id;
    /* hashes of block data */
    pb_callback_t last_commit_hash; /* commit from validators from the last block */
    pb_callback_t data_hash;        /* transactions */
    /* hashes from the app output from the prev block */
    pb_callback_t validators_hash;      /* validators for the current block */
    pb_callback_t next_validators_hash; /* validators for the next block */
    pb_callback_t consensus_hash;       /* consensus params for current block */
    pb_callback_t app_hash;             /* state after txs from the previous block */
    pb_callback_t last_results_hash;    /* root hash of all results from the txs from the previous block */
    /* consensus info */
    pb_callback_t evidence_hash;    /* evidence included in the block */
    pb_callback_t proposer_address; /* original proposer of the block */
} tendermint_types_Header;

/* Data contains the set of transactions included in the block */
typedef struct _tendermint_types_Data {
    /* Txs that will be applied by state @ block.Height+1.
 NOTE: not all txs here are valid.  We're just agreeing on the order first.
 This means that block.AppHash does not include these txs. */
    pb_callback_t txs;
} tendermint_types_Data;

/* Vote represents a prevote, precommit, or commit vote from validators for
 consensus. */
typedef struct _tendermint_types_Vote {
    tendermint_types_SignedMsgType type;
    int64_t height;
    int32_t round;
    bool has_block_id;
    tendermint_types_BlockID block_id; /* zero if vote is nil. */
    bool has_timestamp;
    google_protobuf_Timestamp timestamp;
    pb_callback_t validator_address;
    int32_t validator_index;
    pb_callback_t signature;
} tendermint_types_Vote;

/* Commit contains the evidence that a block was committed by a set of validators. */
typedef struct _tendermint_types_Commit {
    int64_t height;
    int32_t round;
    bool has_block_id;
    tendermint_types_BlockID block_id;
    pb_callback_t signatures;
} tendermint_types_Commit;

/* CommitSig is a part of the Vote included in a Commit. */
typedef struct _tendermint_types_CommitSig {
    tendermint_types_BlockIDFlag block_id_flag;
    pb_callback_t validator_address;
    bool has_timestamp;
    google_protobuf_Timestamp timestamp;
    pb_callback_t signature;
} tendermint_types_CommitSig;

typedef struct _tendermint_types_Proposal {
    tendermint_types_SignedMsgType type;
    int64_t height;
    int32_t round;
    int32_t pol_round;
    bool has_block_id;
    tendermint_types_BlockID block_id;
    bool has_timestamp;
    google_protobuf_Timestamp timestamp;
    pb_callback_t signature;
} tendermint_types_Proposal;

typedef struct _tendermint_types_SignedHeader {
    bool has_header;
    tendermint_types_Header header;
    bool has_commit;
    tendermint_types_Commit commit;
} tendermint_types_SignedHeader;

typedef struct _tendermint_types_LightBlock {
    bool has_signed_header;
    tendermint_types_SignedHeader signed_header;
    bool has_validator_set;
    tendermint_types_ValidatorSet validator_set;
} tendermint_types_LightBlock;

typedef struct _tendermint_types_BlockMeta {
    bool has_block_id;
    tendermint_types_BlockID block_id;
    int64_t block_size;
    bool has_header;
    tendermint_types_Header header;
    int64_t num_txs;
} tendermint_types_BlockMeta;

/* TxProof represents a Merkle proof of the presence of a transaction in the Merkle tree. */
typedef struct _tendermint_types_TxProof {
    pb_callback_t root_hash;
    pb_callback_t data;
    bool has_proof;
    tendermint_crypto_Proof proof;
} tendermint_types_TxProof;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _tendermint_types_BlockIDFlag_MIN tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_UNKNOWN
#define _tendermint_types_BlockIDFlag_MAX tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_NIL
#define _tendermint_types_BlockIDFlag_ARRAYSIZE \
    ((tendermint_types_BlockIDFlag)(tendermint_types_BlockIDFlag_BLOCK_ID_FLAG_NIL + 1))

#define _tendermint_types_SignedMsgType_MIN tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_UNKNOWN
#define _tendermint_types_SignedMsgType_MAX tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_PROPOSAL
#define _tendermint_types_SignedMsgType_ARRAYSIZE \
    ((tendermint_types_SignedMsgType)(tendermint_types_SignedMsgType_SIGNED_MSG_TYPE_PROPOSAL + 1))

#define tendermint_types_Vote_type_ENUMTYPE tendermint_types_SignedMsgType

#define tendermint_types_CommitSig_block_id_flag_ENUMTYPE tendermint_types_BlockIDFlag

#define tendermint_types_Proposal_type_ENUMTYPE tendermint_types_SignedMsgType

/* Initializer values for message structs */
#define tendermint_types_PartSetHeader_init_default \
    {                                               \
        0, { {NULL}, NULL }                         \
    }
#define tendermint_types_Part_init_default \
    { 0, {{NULL}, NULL}, false, tendermint_crypto_Proof_init_default }
#define tendermint_types_BlockID_init_default \
    { {{NULL}, NULL}, false, tendermint_types_PartSetHeader_init_default }
#define tendermint_types_Header_init_default                                                                                \
    {                                                                                                                       \
        false, tendermint_version_Consensus_init_default, {{NULL}, NULL}, 0, false, google_protobuf_Timestamp_init_default, \
            false, tendermint_types_BlockID_init_default, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL},   \
            {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {                                               \
            {NULL}, NULL                                                                                                    \
        }                                                                                                                   \
    }
#define tendermint_types_Data_init_default \
    {                                      \
        { {NULL}, NULL }                   \
    }
#define tendermint_types_Vote_init_default                                                              \
    {                                                                                                   \
        _tendermint_types_SignedMsgType_MIN, 0, 0, false, tendermint_types_BlockID_init_default, false, \
            google_protobuf_Timestamp_init_default, {{NULL}, NULL}, 0, {                                \
            {NULL}, NULL                                                                                \
        }                                                                                               \
    }
#define tendermint_types_Commit_init_default                                 \
    {                                                                        \
        0, 0, false, tendermint_types_BlockID_init_default, { {NULL}, NULL } \
    }
#define tendermint_types_CommitSig_init_default                                                                            \
    {                                                                                                                      \
        _tendermint_types_BlockIDFlag_MIN, {{NULL}, NULL}, false, google_protobuf_Timestamp_init_default, { {NULL}, NULL } \
    }
#define tendermint_types_Proposal_init_default                                                             \
    {                                                                                                      \
        _tendermint_types_SignedMsgType_MIN, 0, 0, 0, false, tendermint_types_BlockID_init_default, false, \
            google_protobuf_Timestamp_init_default, {                                                      \
            {NULL}, NULL                                                                                   \
        }                                                                                                  \
    }
#define tendermint_types_SignedHeader_init_default \
    { false, tendermint_types_Header_init_default, false, tendermint_types_Commit_init_default }
#define tendermint_types_LightBlock_init_default \
    { false, tendermint_types_SignedHeader_init_default, false, tendermint_types_ValidatorSet_init_default }
#define tendermint_types_BlockMeta_init_default \
    { false, tendermint_types_BlockID_init_default, 0, false, tendermint_types_Header_init_default, 0 }
#define tendermint_types_TxProof_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, tendermint_crypto_Proof_init_default }
#define tendermint_types_PartSetHeader_init_zero \
    {                                            \
        0, { {NULL}, NULL }                      \
    }
#define tendermint_types_Part_init_zero \
    { 0, {{NULL}, NULL}, false, tendermint_crypto_Proof_init_zero }
#define tendermint_types_BlockID_init_zero \
    { {{NULL}, NULL}, false, tendermint_types_PartSetHeader_init_zero }
#define tendermint_types_Header_init_zero                                                                              \
    {                                                                                                                  \
        false, tendermint_version_Consensus_init_zero, {{NULL}, NULL}, 0, false, google_protobuf_Timestamp_init_zero,  \
            false, tendermint_types_BlockID_init_zero, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, \
            {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {                                          \
            {NULL}, NULL                                                                                               \
        }                                                                                                              \
    }
#define tendermint_types_Data_init_zero \
    {                                   \
        { {NULL}, NULL }                \
    }
#define tendermint_types_Vote_init_zero                                                              \
    {                                                                                                \
        _tendermint_types_SignedMsgType_MIN, 0, 0, false, tendermint_types_BlockID_init_zero, false, \
            google_protobuf_Timestamp_init_zero, {{NULL}, NULL}, 0, {                                \
            {NULL}, NULL                                                                             \
        }                                                                                            \
    }
#define tendermint_types_Commit_init_zero                                 \
    {                                                                     \
        0, 0, false, tendermint_types_BlockID_init_zero, { {NULL}, NULL } \
    }
#define tendermint_types_CommitSig_init_zero                                                                            \
    {                                                                                                                   \
        _tendermint_types_BlockIDFlag_MIN, {{NULL}, NULL}, false, google_protobuf_Timestamp_init_zero, { {NULL}, NULL } \
    }
#define tendermint_types_Proposal_init_zero                                                             \
    {                                                                                                   \
        _tendermint_types_SignedMsgType_MIN, 0, 0, 0, false, tendermint_types_BlockID_init_zero, false, \
            google_protobuf_Timestamp_init_zero, {                                                      \
            {NULL}, NULL                                                                                \
        }                                                                                               \
    }
#define tendermint_types_SignedHeader_init_zero \
    { false, tendermint_types_Header_init_zero, false, tendermint_types_Commit_init_zero }
#define tendermint_types_LightBlock_init_zero \
    { false, tendermint_types_SignedHeader_init_zero, false, tendermint_types_ValidatorSet_init_zero }
#define tendermint_types_BlockMeta_init_zero \
    { false, tendermint_types_BlockID_init_zero, 0, false, tendermint_types_Header_init_zero, 0 }
#define tendermint_types_TxProof_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, tendermint_crypto_Proof_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define tendermint_types_PartSetHeader_total_tag 1
#define tendermint_types_PartSetHeader_hash_tag 2
#define tendermint_types_Part_index_tag 1
#define tendermint_types_Part_bytes_tag 2
#define tendermint_types_Part_proof_tag 3
#define tendermint_types_BlockID_hash_tag 1
#define tendermint_types_BlockID_part_set_header_tag 2
#define tendermint_types_Header_version_tag 1
#define tendermint_types_Header_chain_id_tag 2
#define tendermint_types_Header_height_tag 3
#define tendermint_types_Header_time_tag 4
#define tendermint_types_Header_last_block_id_tag 5
#define tendermint_types_Header_last_commit_hash_tag 6
#define tendermint_types_Header_data_hash_tag 7
#define tendermint_types_Header_validators_hash_tag 8
#define tendermint_types_Header_next_validators_hash_tag 9
#define tendermint_types_Header_consensus_hash_tag 10
#define tendermint_types_Header_app_hash_tag 11
#define tendermint_types_Header_last_results_hash_tag 12
#define tendermint_types_Header_evidence_hash_tag 13
#define tendermint_types_Header_proposer_address_tag 14
#define tendermint_types_Data_txs_tag 1
#define tendermint_types_Vote_type_tag 1
#define tendermint_types_Vote_height_tag 2
#define tendermint_types_Vote_round_tag 3
#define tendermint_types_Vote_block_id_tag 4
#define tendermint_types_Vote_timestamp_tag 5
#define tendermint_types_Vote_validator_address_tag 6
#define tendermint_types_Vote_validator_index_tag 7
#define tendermint_types_Vote_signature_tag 8
#define tendermint_types_Commit_height_tag 1
#define tendermint_types_Commit_round_tag 2
#define tendermint_types_Commit_block_id_tag 3
#define tendermint_types_Commit_signatures_tag 4
#define tendermint_types_CommitSig_block_id_flag_tag 1
#define tendermint_types_CommitSig_validator_address_tag 2
#define tendermint_types_CommitSig_timestamp_tag 3
#define tendermint_types_CommitSig_signature_tag 4
#define tendermint_types_Proposal_type_tag 1
#define tendermint_types_Proposal_height_tag 2
#define tendermint_types_Proposal_round_tag 3
#define tendermint_types_Proposal_pol_round_tag 4
#define tendermint_types_Proposal_block_id_tag 5
#define tendermint_types_Proposal_timestamp_tag 6
#define tendermint_types_Proposal_signature_tag 7
#define tendermint_types_SignedHeader_header_tag 1
#define tendermint_types_SignedHeader_commit_tag 2
#define tendermint_types_LightBlock_signed_header_tag 1
#define tendermint_types_LightBlock_validator_set_tag 2
#define tendermint_types_BlockMeta_block_id_tag 1
#define tendermint_types_BlockMeta_block_size_tag 2
#define tendermint_types_BlockMeta_header_tag 3
#define tendermint_types_BlockMeta_num_txs_tag 4
#define tendermint_types_TxProof_root_hash_tag 1
#define tendermint_types_TxProof_data_tag 2
#define tendermint_types_TxProof_proof_tag 3

/* Struct field encoding specification for nanopb */
#define tendermint_types_PartSetHeader_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT32, total, 1)           \
    X(a, CALLBACK, SINGULAR, BYTES, hash, 2)
#define tendermint_types_PartSetHeader_CALLBACK pb_default_field_callback
#define tendermint_types_PartSetHeader_DEFAULT NULL

#define tendermint_types_Part_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT32, index, 1)  \
    X(a, CALLBACK, SINGULAR, BYTES, bytes, 2) \
    X(a, STATIC, OPTIONAL, MESSAGE, proof, 3)
#define tendermint_types_Part_CALLBACK pb_default_field_callback
#define tendermint_types_Part_DEFAULT NULL
#define tendermint_types_Part_proof_MSGTYPE tendermint_crypto_Proof

#define tendermint_types_BlockID_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, hash, 1)     \
    X(a, STATIC, OPTIONAL, MESSAGE, part_set_header, 2)
#define tendermint_types_BlockID_CALLBACK pb_default_field_callback
#define tendermint_types_BlockID_DEFAULT NULL
#define tendermint_types_BlockID_part_set_header_MSGTYPE tendermint_types_PartSetHeader

#define tendermint_types_Header_FIELDLIST(X, a)              \
    X(a, STATIC, OPTIONAL, MESSAGE, version, 1)              \
    X(a, CALLBACK, SINGULAR, STRING, chain_id, 2)            \
    X(a, STATIC, SINGULAR, INT64, height, 3)                 \
    X(a, STATIC, OPTIONAL, MESSAGE, time, 4)                 \
    X(a, STATIC, OPTIONAL, MESSAGE, last_block_id, 5)        \
    X(a, CALLBACK, SINGULAR, BYTES, last_commit_hash, 6)     \
    X(a, CALLBACK, SINGULAR, BYTES, data_hash, 7)            \
    X(a, CALLBACK, SINGULAR, BYTES, validators_hash, 8)      \
    X(a, CALLBACK, SINGULAR, BYTES, next_validators_hash, 9) \
    X(a, CALLBACK, SINGULAR, BYTES, consensus_hash, 10)      \
    X(a, CALLBACK, SINGULAR, BYTES, app_hash, 11)            \
    X(a, CALLBACK, SINGULAR, BYTES, last_results_hash, 12)   \
    X(a, CALLBACK, SINGULAR, BYTES, evidence_hash, 13)       \
    X(a, CALLBACK, SINGULAR, BYTES, proposer_address, 14)
#define tendermint_types_Header_CALLBACK pb_default_field_callback
#define tendermint_types_Header_DEFAULT NULL
#define tendermint_types_Header_version_MSGTYPE tendermint_version_Consensus
#define tendermint_types_Header_time_MSGTYPE google_protobuf_Timestamp
#define tendermint_types_Header_last_block_id_MSGTYPE tendermint_types_BlockID

#define tendermint_types_Data_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, BYTES, txs, 1)
#define tendermint_types_Data_CALLBACK pb_default_field_callback
#define tendermint_types_Data_DEFAULT NULL

#define tendermint_types_Vote_FIELDLIST(X, a)             \
    X(a, STATIC, SINGULAR, UENUM, type, 1)                \
    X(a, STATIC, SINGULAR, INT64, height, 2)              \
    X(a, STATIC, SINGULAR, INT32, round, 3)               \
    X(a, STATIC, OPTIONAL, MESSAGE, block_id, 4)          \
    X(a, STATIC, OPTIONAL, MESSAGE, timestamp, 5)         \
    X(a, CALLBACK, SINGULAR, BYTES, validator_address, 6) \
    X(a, STATIC, SINGULAR, INT32, validator_index, 7)     \
    X(a, CALLBACK, SINGULAR, BYTES, signature, 8)
#define tendermint_types_Vote_CALLBACK pb_default_field_callback
#define tendermint_types_Vote_DEFAULT NULL
#define tendermint_types_Vote_block_id_MSGTYPE tendermint_types_BlockID
#define tendermint_types_Vote_timestamp_MSGTYPE google_protobuf_Timestamp

#define tendermint_types_Commit_FIELDLIST(X, a)  \
    X(a, STATIC, SINGULAR, INT64, height, 1)     \
    X(a, STATIC, SINGULAR, INT32, round, 2)      \
    X(a, STATIC, OPTIONAL, MESSAGE, block_id, 3) \
    X(a, CALLBACK, REPEATED, MESSAGE, signatures, 4)
#define tendermint_types_Commit_CALLBACK pb_default_field_callback
#define tendermint_types_Commit_DEFAULT NULL
#define tendermint_types_Commit_block_id_MSGTYPE tendermint_types_BlockID
#define tendermint_types_Commit_signatures_MSGTYPE tendermint_types_CommitSig

#define tendermint_types_CommitSig_FIELDLIST(X, a)        \
    X(a, STATIC, SINGULAR, UENUM, block_id_flag, 1)       \
    X(a, CALLBACK, SINGULAR, BYTES, validator_address, 2) \
    X(a, STATIC, OPTIONAL, MESSAGE, timestamp, 3)         \
    X(a, CALLBACK, SINGULAR, BYTES, signature, 4)
#define tendermint_types_CommitSig_CALLBACK pb_default_field_callback
#define tendermint_types_CommitSig_DEFAULT NULL
#define tendermint_types_CommitSig_timestamp_MSGTYPE google_protobuf_Timestamp

#define tendermint_types_Proposal_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UENUM, type, 1)        \
    X(a, STATIC, SINGULAR, INT64, height, 2)      \
    X(a, STATIC, SINGULAR, INT32, round, 3)       \
    X(a, STATIC, SINGULAR, INT32, pol_round, 4)   \
    X(a, STATIC, OPTIONAL, MESSAGE, block_id, 5)  \
    X(a, STATIC, OPTIONAL, MESSAGE, timestamp, 6) \
    X(a, CALLBACK, SINGULAR, BYTES, signature, 7)
#define tendermint_types_Proposal_CALLBACK pb_default_field_callback
#define tendermint_types_Proposal_DEFAULT NULL
#define tendermint_types_Proposal_block_id_MSGTYPE tendermint_types_BlockID
#define tendermint_types_Proposal_timestamp_MSGTYPE google_protobuf_Timestamp

#define tendermint_types_SignedHeader_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, header, 1)        \
    X(a, STATIC, OPTIONAL, MESSAGE, commit, 2)
#define tendermint_types_SignedHeader_CALLBACK NULL
#define tendermint_types_SignedHeader_DEFAULT NULL
#define tendermint_types_SignedHeader_header_MSGTYPE tendermint_types_Header
#define tendermint_types_SignedHeader_commit_MSGTYPE tendermint_types_Commit

#define tendermint_types_LightBlock_FIELDLIST(X, a)   \
    X(a, STATIC, OPTIONAL, MESSAGE, signed_header, 1) \
    X(a, STATIC, OPTIONAL, MESSAGE, validator_set, 2)
#define tendermint_types_LightBlock_CALLBACK NULL
#define tendermint_types_LightBlock_DEFAULT NULL
#define tendermint_types_LightBlock_signed_header_MSGTYPE tendermint_types_SignedHeader
#define tendermint_types_LightBlock_validator_set_MSGTYPE tendermint_types_ValidatorSet

#define tendermint_types_BlockMeta_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, block_id, 1)   \
    X(a, STATIC, SINGULAR, INT64, block_size, 2)   \
    X(a, STATIC, OPTIONAL, MESSAGE, header, 3)     \
    X(a, STATIC, SINGULAR, INT64, num_txs, 4)
#define tendermint_types_BlockMeta_CALLBACK NULL
#define tendermint_types_BlockMeta_DEFAULT NULL
#define tendermint_types_BlockMeta_block_id_MSGTYPE tendermint_types_BlockID
#define tendermint_types_BlockMeta_header_MSGTYPE tendermint_types_Header

#define tendermint_types_TxProof_FIELDLIST(X, a)  \
    X(a, CALLBACK, SINGULAR, BYTES, root_hash, 1) \
    X(a, CALLBACK, SINGULAR, BYTES, data, 2)      \
    X(a, STATIC, OPTIONAL, MESSAGE, proof, 3)
#define tendermint_types_TxProof_CALLBACK pb_default_field_callback
#define tendermint_types_TxProof_DEFAULT NULL
#define tendermint_types_TxProof_proof_MSGTYPE tendermint_crypto_Proof

extern const pb_msgdesc_t tendermint_types_PartSetHeader_msg;
extern const pb_msgdesc_t tendermint_types_Part_msg;
extern const pb_msgdesc_t tendermint_types_BlockID_msg;
extern const pb_msgdesc_t tendermint_types_Header_msg;
extern const pb_msgdesc_t tendermint_types_Data_msg;
extern const pb_msgdesc_t tendermint_types_Vote_msg;
extern const pb_msgdesc_t tendermint_types_Commit_msg;
extern const pb_msgdesc_t tendermint_types_CommitSig_msg;
extern const pb_msgdesc_t tendermint_types_Proposal_msg;
extern const pb_msgdesc_t tendermint_types_SignedHeader_msg;
extern const pb_msgdesc_t tendermint_types_LightBlock_msg;
extern const pb_msgdesc_t tendermint_types_BlockMeta_msg;
extern const pb_msgdesc_t tendermint_types_TxProof_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define tendermint_types_PartSetHeader_fields &tendermint_types_PartSetHeader_msg
#define tendermint_types_Part_fields &tendermint_types_Part_msg
#define tendermint_types_BlockID_fields &tendermint_types_BlockID_msg
#define tendermint_types_Header_fields &tendermint_types_Header_msg
#define tendermint_types_Data_fields &tendermint_types_Data_msg
#define tendermint_types_Vote_fields &tendermint_types_Vote_msg
#define tendermint_types_Commit_fields &tendermint_types_Commit_msg
#define tendermint_types_CommitSig_fields &tendermint_types_CommitSig_msg
#define tendermint_types_Proposal_fields &tendermint_types_Proposal_msg
#define tendermint_types_SignedHeader_fields &tendermint_types_SignedHeader_msg
#define tendermint_types_LightBlock_fields &tendermint_types_LightBlock_msg
#define tendermint_types_BlockMeta_fields &tendermint_types_BlockMeta_msg
#define tendermint_types_TxProof_fields &tendermint_types_TxProof_msg

/* Maximum encoded size of messages (where known) */
/* tendermint_types_PartSetHeader_size depends on runtime parameters */
/* tendermint_types_Part_size depends on runtime parameters */
/* tendermint_types_BlockID_size depends on runtime parameters */
/* tendermint_types_Header_size depends on runtime parameters */
/* tendermint_types_Data_size depends on runtime parameters */
/* tendermint_types_Vote_size depends on runtime parameters */
/* tendermint_types_Commit_size depends on runtime parameters */
/* tendermint_types_CommitSig_size depends on runtime parameters */
/* tendermint_types_Proposal_size depends on runtime parameters */
/* tendermint_types_SignedHeader_size depends on runtime parameters */
/* tendermint_types_LightBlock_size depends on runtime parameters */
/* tendermint_types_BlockMeta_size depends on runtime parameters */
/* tendermint_types_TxProof_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
