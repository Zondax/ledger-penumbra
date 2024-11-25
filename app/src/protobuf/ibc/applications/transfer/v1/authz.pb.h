/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_IBC_APPLICATIONS_TRANSFER_V1_IBC_APPLICATIONS_TRANSFER_V1_AUTHZ_PB_H_INCLUDED
#define PB_IBC_APPLICATIONS_TRANSFER_V1_IBC_APPLICATIONS_TRANSFER_V1_AUTHZ_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Allocation defines the spend limit for a particular port and channel */
typedef struct _ibc_applications_transfer_v1_Allocation {
    /* the port on which the packet will be sent */
    pb_callback_t source_port;
    /* the channel by which the packet will be sent */
    pb_callback_t source_channel;
    /* spend limitation on the channel */
    pb_callback_t spend_limit;
    /* allow list of receivers, an empty allow list permits any receiver address */
    pb_callback_t allow_list;
} ibc_applications_transfer_v1_Allocation;

/* TransferAuthorization allows the grantee to spend up to spend_limit coins from
 the granter's account for ibc transfer on a specific channel */
typedef struct _ibc_applications_transfer_v1_TransferAuthorization {
    /* port and channel amounts */
    pb_callback_t allocations;
} ibc_applications_transfer_v1_TransferAuthorization;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define ibc_applications_transfer_v1_Allocation_init_default             \
    {                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define ibc_applications_transfer_v1_TransferAuthorization_init_default \
    {                                                                   \
        { {NULL}, NULL }                                                \
    }
#define ibc_applications_transfer_v1_Allocation_init_zero                \
    {                                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define ibc_applications_transfer_v1_TransferAuthorization_init_zero \
    {                                                                \
        { {NULL}, NULL }                                             \
    }

/* Field tags (for use in manual encoding/decoding) */
#define ibc_applications_transfer_v1_Allocation_source_port_tag 1
#define ibc_applications_transfer_v1_Allocation_source_channel_tag 2
#define ibc_applications_transfer_v1_Allocation_spend_limit_tag 3
#define ibc_applications_transfer_v1_Allocation_allow_list_tag 4
#define ibc_applications_transfer_v1_TransferAuthorization_allocations_tag 1

/* Struct field encoding specification for nanopb */
#define ibc_applications_transfer_v1_Allocation_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, source_port, 1)            \
    X(a, CALLBACK, SINGULAR, STRING, source_channel, 2)         \
    X(a, CALLBACK, REPEATED, MESSAGE, spend_limit, 3)           \
    X(a, CALLBACK, REPEATED, STRING, allow_list, 4)
#define ibc_applications_transfer_v1_Allocation_CALLBACK pb_default_field_callback
#define ibc_applications_transfer_v1_Allocation_DEFAULT NULL
#define ibc_applications_transfer_v1_Allocation_spend_limit_MSGTYPE cosmos_base_v1beta1_Coin

#define ibc_applications_transfer_v1_TransferAuthorization_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, MESSAGE, allocations, 1)
#define ibc_applications_transfer_v1_TransferAuthorization_CALLBACK pb_default_field_callback
#define ibc_applications_transfer_v1_TransferAuthorization_DEFAULT NULL
#define ibc_applications_transfer_v1_TransferAuthorization_allocations_MSGTYPE ibc_applications_transfer_v1_Allocation

extern const pb_msgdesc_t ibc_applications_transfer_v1_Allocation_msg;
extern const pb_msgdesc_t ibc_applications_transfer_v1_TransferAuthorization_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define ibc_applications_transfer_v1_Allocation_fields &ibc_applications_transfer_v1_Allocation_msg
#define ibc_applications_transfer_v1_TransferAuthorization_fields &ibc_applications_transfer_v1_TransferAuthorization_msg

/* Maximum encoded size of messages (where known) */
/* ibc_applications_transfer_v1_Allocation_size depends on runtime parameters */
/* ibc_applications_transfer_v1_TransferAuthorization_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
