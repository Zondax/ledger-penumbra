/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_CONSENSUS_V1_COSMOS_CONSENSUS_V1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_CONSENSUS_V1_COSMOS_CONSENSUS_V1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "google/api/annotations.pb.h"
#include "tendermint/types/params.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* QueryParamsRequest defines the request type for querying x/consensus parameters. */
typedef struct _cosmos_consensus_v1_QueryParamsRequest {
    char dummy_field;
} cosmos_consensus_v1_QueryParamsRequest;

/* QueryParamsResponse defines the response type for querying x/consensus parameters. */
typedef struct _cosmos_consensus_v1_QueryParamsResponse {
    /* params are the tendermint consensus params stored in the consensus module.
 Please note that `params.version` is not populated in this response, it is
 tracked separately in the x/upgrade module. */
    bool has_params;
    tendermint_types_ConsensusParams params;
} cosmos_consensus_v1_QueryParamsResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_consensus_v1_QueryParamsRequest_init_default \
    { 0 }
#define cosmos_consensus_v1_QueryParamsResponse_init_default \
    { false, tendermint_types_ConsensusParams_init_default }
#define cosmos_consensus_v1_QueryParamsRequest_init_zero \
    { 0 }
#define cosmos_consensus_v1_QueryParamsResponse_init_zero \
    { false, tendermint_types_ConsensusParams_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_consensus_v1_QueryParamsResponse_params_tag 1

/* Struct field encoding specification for nanopb */
#define cosmos_consensus_v1_QueryParamsRequest_FIELDLIST(X, a)

#define cosmos_consensus_v1_QueryParamsRequest_CALLBACK NULL
#define cosmos_consensus_v1_QueryParamsRequest_DEFAULT NULL

#define cosmos_consensus_v1_QueryParamsResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, params, 1)
#define cosmos_consensus_v1_QueryParamsResponse_CALLBACK NULL
#define cosmos_consensus_v1_QueryParamsResponse_DEFAULT NULL
#define cosmos_consensus_v1_QueryParamsResponse_params_MSGTYPE tendermint_types_ConsensusParams

extern const pb_msgdesc_t cosmos_consensus_v1_QueryParamsRequest_msg;
extern const pb_msgdesc_t cosmos_consensus_v1_QueryParamsResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_consensus_v1_QueryParamsRequest_fields &cosmos_consensus_v1_QueryParamsRequest_msg
#define cosmos_consensus_v1_QueryParamsResponse_fields &cosmos_consensus_v1_QueryParamsResponse_msg

/* Maximum encoded size of messages (where known) */
#define cosmos_consensus_v1_QueryParamsRequest_size 0
#if defined(tendermint_types_ConsensusParams_size)
#define COSMOS_CONSENSUS_V1_COSMOS_CONSENSUS_V1_QUERY_PB_H_MAX_SIZE cosmos_consensus_v1_QueryParamsResponse_size
#define cosmos_consensus_v1_QueryParamsResponse_size (6 + tendermint_types_ConsensusParams_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
