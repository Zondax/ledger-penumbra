/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_SLASHING_V1BETA1_COSMOS_SLASHING_V1BETA1_GENESIS_PB_H_INCLUDED
#define PB_COSMOS_SLASHING_V1BETA1_COSMOS_SLASHING_V1BETA1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/slashing/v1beta1/slashing.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* GenesisState defines the slashing module's genesis state. */
typedef struct _cosmos_slashing_v1beta1_GenesisState {
    /* params defines all the parameters of the module. */
    bool has_params;
    cosmos_slashing_v1beta1_Params params;
    /* signing_infos represents a map between validator addresses and their
 signing infos. */
    pb_callback_t signing_infos;
    /* missed_blocks represents a map between validator addresses and their
 missed blocks. */
    pb_callback_t missed_blocks;
} cosmos_slashing_v1beta1_GenesisState;

/* SigningInfo stores validator signing info of corresponding address. */
typedef struct _cosmos_slashing_v1beta1_SigningInfo {
    /* address is the validator address. */
    pb_callback_t address;
    /* validator_signing_info represents the signing info of this validator. */
    bool has_validator_signing_info;
    cosmos_slashing_v1beta1_ValidatorSigningInfo validator_signing_info;
} cosmos_slashing_v1beta1_SigningInfo;

/* ValidatorMissedBlocks contains array of missed blocks of corresponding
 address. */
typedef struct _cosmos_slashing_v1beta1_ValidatorMissedBlocks {
    /* address is the validator address. */
    pb_callback_t address;
    /* missed_blocks is an array of missed blocks by the validator. */
    pb_callback_t missed_blocks;
} cosmos_slashing_v1beta1_ValidatorMissedBlocks;

/* MissedBlock contains height and missed status as boolean. */
typedef struct _cosmos_slashing_v1beta1_MissedBlock {
    /* index is the height at which the block was missed. */
    int64_t index;
    /* missed is the missed status. */
    bool missed;
} cosmos_slashing_v1beta1_MissedBlock;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_slashing_v1beta1_GenesisState_init_default                                    \
    {                                                                                        \
        false, cosmos_slashing_v1beta1_Params_init_default, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_slashing_v1beta1_SigningInfo_init_default \
    { {{NULL}, NULL}, false, cosmos_slashing_v1beta1_ValidatorSigningInfo_init_default }
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_init_default \
    {                                                              \
        {{NULL}, NULL}, { {NULL}, NULL }                           \
    }
#define cosmos_slashing_v1beta1_MissedBlock_init_default \
    { 0, 0 }
#define cosmos_slashing_v1beta1_GenesisState_init_zero                                    \
    {                                                                                     \
        false, cosmos_slashing_v1beta1_Params_init_zero, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_slashing_v1beta1_SigningInfo_init_zero \
    { {{NULL}, NULL}, false, cosmos_slashing_v1beta1_ValidatorSigningInfo_init_zero }
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_init_zero \
    {                                                           \
        {{NULL}, NULL}, { {NULL}, NULL }                        \
    }
#define cosmos_slashing_v1beta1_MissedBlock_init_zero \
    { 0, 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_slashing_v1beta1_GenesisState_params_tag 1
#define cosmos_slashing_v1beta1_GenesisState_signing_infos_tag 2
#define cosmos_slashing_v1beta1_GenesisState_missed_blocks_tag 3
#define cosmos_slashing_v1beta1_SigningInfo_address_tag 1
#define cosmos_slashing_v1beta1_SigningInfo_validator_signing_info_tag 2
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_address_tag 1
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_missed_blocks_tag 2
#define cosmos_slashing_v1beta1_MissedBlock_index_tag 1
#define cosmos_slashing_v1beta1_MissedBlock_missed_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_slashing_v1beta1_GenesisState_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 1)               \
    X(a, CALLBACK, REPEATED, MESSAGE, signing_infos, 2)      \
    X(a, CALLBACK, REPEATED, MESSAGE, missed_blocks, 3)
#define cosmos_slashing_v1beta1_GenesisState_CALLBACK pb_default_field_callback
#define cosmos_slashing_v1beta1_GenesisState_DEFAULT NULL
#define cosmos_slashing_v1beta1_GenesisState_params_MSGTYPE cosmos_slashing_v1beta1_Params
#define cosmos_slashing_v1beta1_GenesisState_signing_infos_MSGTYPE cosmos_slashing_v1beta1_SigningInfo
#define cosmos_slashing_v1beta1_GenesisState_missed_blocks_MSGTYPE cosmos_slashing_v1beta1_ValidatorMissedBlocks

#define cosmos_slashing_v1beta1_SigningInfo_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)            \
    X(a, STATIC, OPTIONAL, MESSAGE, validator_signing_info, 2)
#define cosmos_slashing_v1beta1_SigningInfo_CALLBACK pb_default_field_callback
#define cosmos_slashing_v1beta1_SigningInfo_DEFAULT NULL
#define cosmos_slashing_v1beta1_SigningInfo_validator_signing_info_MSGTYPE cosmos_slashing_v1beta1_ValidatorSigningInfo

#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)                      \
    X(a, CALLBACK, REPEATED, MESSAGE, missed_blocks, 2)
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_CALLBACK pb_default_field_callback
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_DEFAULT NULL
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_missed_blocks_MSGTYPE cosmos_slashing_v1beta1_MissedBlock

#define cosmos_slashing_v1beta1_MissedBlock_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, INT64, index, 1)                 \
    X(a, STATIC, SINGULAR, BOOL, missed, 2)
#define cosmos_slashing_v1beta1_MissedBlock_CALLBACK NULL
#define cosmos_slashing_v1beta1_MissedBlock_DEFAULT NULL

extern const pb_msgdesc_t cosmos_slashing_v1beta1_GenesisState_msg;
extern const pb_msgdesc_t cosmos_slashing_v1beta1_SigningInfo_msg;
extern const pb_msgdesc_t cosmos_slashing_v1beta1_ValidatorMissedBlocks_msg;
extern const pb_msgdesc_t cosmos_slashing_v1beta1_MissedBlock_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_slashing_v1beta1_GenesisState_fields &cosmos_slashing_v1beta1_GenesisState_msg
#define cosmos_slashing_v1beta1_SigningInfo_fields &cosmos_slashing_v1beta1_SigningInfo_msg
#define cosmos_slashing_v1beta1_ValidatorMissedBlocks_fields &cosmos_slashing_v1beta1_ValidatorMissedBlocks_msg
#define cosmos_slashing_v1beta1_MissedBlock_fields &cosmos_slashing_v1beta1_MissedBlock_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_slashing_v1beta1_GenesisState_size depends on runtime parameters */
/* cosmos_slashing_v1beta1_SigningInfo_size depends on runtime parameters */
/* cosmos_slashing_v1beta1_ValidatorMissedBlocks_size depends on runtime parameters */
#define COSMOS_SLASHING_V1BETA1_COSMOS_SLASHING_V1BETA1_GENESIS_PB_H_MAX_SIZE cosmos_slashing_v1beta1_MissedBlock_size
#define cosmos_slashing_v1beta1_MissedBlock_size 13

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif