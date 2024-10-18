/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_UPGRADE_V1BETA1_COSMOS_UPGRADE_V1BETA1_UPGRADE_PB_H_INCLUDED
#define PB_COSMOS_UPGRADE_V1BETA1_COSMOS_UPGRADE_V1BETA1_UPGRADE_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/protobuf/any.pb.h"
#include "google/protobuf/timestamp.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Plan specifies information about a planned upgrade and when it should occur. */
typedef struct _cosmos_upgrade_v1beta1_Plan {
    /* Sets the name for the upgrade. This name will be used by the upgraded
 version of the software to apply any special "on-upgrade" commands during
 the first BeginBlock method after the upgrade is applied. It is also used
 to detect whether a software version can handle a given upgrade. If no
 upgrade handler with this name has been set in the software, it will be
 assumed that the software is out-of-date when the upgrade Time or Height is
 reached and the software will exit. */
    pb_callback_t name;
    /* Deprecated: Time based upgrades have been deprecated. Time based upgrade logic
 has been removed from the SDK.
 If this field is not empty, an error will be thrown. */
    bool has_time;
    google_protobuf_Timestamp time;
    /* The height at which the upgrade must be performed. */
    int64_t height;
    /* Any application specific upgrade info to be included on-chain
 such as a git commit that validators could automatically upgrade to */
    pb_callback_t info;
    /* Deprecated: UpgradedClientState field has been deprecated. IBC upgrade logic has been
 moved to the IBC module in the sub module 02-client.
 If this field is not empty, an error will be thrown. */
    bool has_upgraded_client_state;
    google_protobuf_Any upgraded_client_state;
} cosmos_upgrade_v1beta1_Plan;

/* SoftwareUpgradeProposal is a gov Content type for initiating a software
 upgrade.
 Deprecated: This legacy proposal is deprecated in favor of Msg-based gov
 proposals, see MsgSoftwareUpgrade. */
typedef struct _cosmos_upgrade_v1beta1_SoftwareUpgradeProposal {
    /* title of the proposal */
    pb_callback_t title;
    /* description of the proposal */
    pb_callback_t description;
    /* plan of the proposal */
    bool has_plan;
    cosmos_upgrade_v1beta1_Plan plan;
} cosmos_upgrade_v1beta1_SoftwareUpgradeProposal;

/* CancelSoftwareUpgradeProposal is a gov Content type for cancelling a software
 upgrade.
 Deprecated: This legacy proposal is deprecated in favor of Msg-based gov
 proposals, see MsgCancelUpgrade. */
typedef struct _cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal {
    /* title of the proposal */
    pb_callback_t title;
    /* description of the proposal */
    pb_callback_t description;
} cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal;

/* ModuleVersion specifies a module and its consensus version.

 Since: cosmos-sdk 0.43 */
typedef struct _cosmos_upgrade_v1beta1_ModuleVersion {
    /* name of the app module */
    pb_callback_t name;
    /* consensus version of the app module */
    uint64_t version;
} cosmos_upgrade_v1beta1_ModuleVersion;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_upgrade_v1beta1_Plan_init_default                                                 \
    {                                                                                            \
        {{NULL}, NULL}, false, google_protobuf_Timestamp_init_default, 0, {{NULL}, NULL}, false, \
            google_protobuf_Any_init_default                                                     \
    }
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_upgrade_v1beta1_Plan_init_default }
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_init_default \
    {                                                                     \
        {{NULL}, NULL}, { {NULL}, NULL }                                  \
    }
#define cosmos_upgrade_v1beta1_ModuleVersion_init_default \
    { {{NULL}, NULL}, 0 }
#define cosmos_upgrade_v1beta1_Plan_init_zero \
    { {{NULL}, NULL}, false, google_protobuf_Timestamp_init_zero, 0, {{NULL}, NULL}, false, google_protobuf_Any_init_zero }
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_upgrade_v1beta1_Plan_init_zero }
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_init_zero \
    {                                                                  \
        {{NULL}, NULL}, { {NULL}, NULL }                               \
    }
#define cosmos_upgrade_v1beta1_ModuleVersion_init_zero \
    { {{NULL}, NULL}, 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_upgrade_v1beta1_Plan_name_tag 1
#define cosmos_upgrade_v1beta1_Plan_time_tag 2
#define cosmos_upgrade_v1beta1_Plan_height_tag 3
#define cosmos_upgrade_v1beta1_Plan_info_tag 4
#define cosmos_upgrade_v1beta1_Plan_upgraded_client_state_tag 5
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_title_tag 1
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_description_tag 2
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_plan_tag 3
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_title_tag 1
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_description_tag 2
#define cosmos_upgrade_v1beta1_ModuleVersion_name_tag 1
#define cosmos_upgrade_v1beta1_ModuleVersion_version_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_upgrade_v1beta1_Plan_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)       \
    X(a, STATIC, OPTIONAL, MESSAGE, time, 2)        \
    X(a, STATIC, SINGULAR, INT64, height, 3)        \
    X(a, CALLBACK, SINGULAR, STRING, info, 4)       \
    X(a, STATIC, OPTIONAL, MESSAGE, upgraded_client_state, 5)
#define cosmos_upgrade_v1beta1_Plan_CALLBACK pb_default_field_callback
#define cosmos_upgrade_v1beta1_Plan_DEFAULT NULL
#define cosmos_upgrade_v1beta1_Plan_time_MSGTYPE google_protobuf_Timestamp
#define cosmos_upgrade_v1beta1_Plan_upgraded_client_state_MSGTYPE google_protobuf_Any

#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, title, 1)                         \
    X(a, CALLBACK, SINGULAR, STRING, description, 2)                   \
    X(a, STATIC, OPTIONAL, MESSAGE, plan, 3)
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_CALLBACK pb_default_field_callback
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_DEFAULT NULL
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_plan_MSGTYPE cosmos_upgrade_v1beta1_Plan

#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, title, 1)                               \
    X(a, CALLBACK, SINGULAR, STRING, description, 2)
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_CALLBACK pb_default_field_callback
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_DEFAULT NULL

#define cosmos_upgrade_v1beta1_ModuleVersion_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)                \
    X(a, STATIC, SINGULAR, UINT64, version, 2)
#define cosmos_upgrade_v1beta1_ModuleVersion_CALLBACK pb_default_field_callback
#define cosmos_upgrade_v1beta1_ModuleVersion_DEFAULT NULL

extern const pb_msgdesc_t cosmos_upgrade_v1beta1_Plan_msg;
extern const pb_msgdesc_t cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_msg;
extern const pb_msgdesc_t cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_msg;
extern const pb_msgdesc_t cosmos_upgrade_v1beta1_ModuleVersion_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_upgrade_v1beta1_Plan_fields &cosmos_upgrade_v1beta1_Plan_msg
#define cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_fields &cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_msg
#define cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_fields &cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_msg
#define cosmos_upgrade_v1beta1_ModuleVersion_fields &cosmos_upgrade_v1beta1_ModuleVersion_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_upgrade_v1beta1_Plan_size depends on runtime parameters */
/* cosmos_upgrade_v1beta1_SoftwareUpgradeProposal_size depends on runtime parameters */
/* cosmos_upgrade_v1beta1_CancelSoftwareUpgradeProposal_size depends on runtime parameters */
/* cosmos_upgrade_v1beta1_ModuleVersion_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
