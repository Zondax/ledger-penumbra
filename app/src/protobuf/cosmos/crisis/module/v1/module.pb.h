/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_CRISIS_MODULE_V1_COSMOS_CRISIS_MODULE_V1_MODULE_PB_H_INCLUDED
#define PB_COSMOS_CRISIS_MODULE_V1_COSMOS_CRISIS_MODULE_V1_MODULE_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/app/v1alpha1/module.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Module is the config object of the crisis module. */
typedef struct _cosmos_crisis_module_v1_Module {
    /* fee_collector_name is the name of the FeeCollector ModuleAccount. */
    pb_callback_t fee_collector_name;
    /* authority defines the custom module authority. If not set, defaults to the governance module. */
    pb_callback_t authority;
} cosmos_crisis_module_v1_Module;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_crisis_module_v1_Module_init_default \
    {                                               \
        {{NULL}, NULL}, { {NULL}, NULL }            \
    }
#define cosmos_crisis_module_v1_Module_init_zero \
    {                                            \
        {{NULL}, NULL}, { {NULL}, NULL }         \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_crisis_module_v1_Module_fee_collector_name_tag 1
#define cosmos_crisis_module_v1_Module_authority_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_crisis_module_v1_Module_FIELDLIST(X, a)      \
    X(a, CALLBACK, SINGULAR, STRING, fee_collector_name, 1) \
    X(a, CALLBACK, SINGULAR, STRING, authority, 2)
#define cosmos_crisis_module_v1_Module_CALLBACK pb_default_field_callback
#define cosmos_crisis_module_v1_Module_DEFAULT NULL

extern const pb_msgdesc_t cosmos_crisis_module_v1_Module_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_crisis_module_v1_Module_fields &cosmos_crisis_module_v1_Module_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_crisis_module_v1_Module_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
