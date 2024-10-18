/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_TX_CONFIG_V1_COSMOS_TX_CONFIG_V1_CONFIG_PB_H_INCLUDED
#define PB_COSMOS_TX_CONFIG_V1_COSMOS_TX_CONFIG_V1_CONFIG_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/app/v1alpha1/module.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Config is the config object of the x/auth/tx package. */
typedef struct _cosmos_tx_config_v1_Config {
    /* skip_ante_handler defines whether the ante handler registration should be skipped in case an app wants to override
 this functionality. */
    bool skip_ante_handler;
    /* skip_post_handler defines whether the post handler registration should be skipped in case an app wants to override
 this functionality. */
    bool skip_post_handler;
} cosmos_tx_config_v1_Config;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_tx_config_v1_Config_init_default \
    { 0, 0 }
#define cosmos_tx_config_v1_Config_init_zero \
    { 0, 0 }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_tx_config_v1_Config_skip_ante_handler_tag 1
#define cosmos_tx_config_v1_Config_skip_post_handler_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_tx_config_v1_Config_FIELDLIST(X, a)     \
    X(a, STATIC, SINGULAR, BOOL, skip_ante_handler, 1) \
    X(a, STATIC, SINGULAR, BOOL, skip_post_handler, 2)
#define cosmos_tx_config_v1_Config_CALLBACK NULL
#define cosmos_tx_config_v1_Config_DEFAULT NULL

extern const pb_msgdesc_t cosmos_tx_config_v1_Config_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_tx_config_v1_Config_fields &cosmos_tx_config_v1_Config_msg

/* Maximum encoded size of messages (where known) */
#define COSMOS_TX_CONFIG_V1_COSMOS_TX_CONFIG_V1_CONFIG_PB_H_MAX_SIZE cosmos_tx_config_v1_Config_size
#define cosmos_tx_config_v1_Config_size 4

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
