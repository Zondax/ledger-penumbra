/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_APP_V1ALPHA1_COSMOS_APP_V1ALPHA1_CONFIG_PB_H_INCLUDED
#define PB_COSMOS_APP_V1ALPHA1_COSMOS_APP_V1ALPHA1_CONFIG_PB_H_INCLUDED
#include <pb.h>

#include "google/protobuf/any.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Config represents the configuration for a Cosmos SDK ABCI app.
 It is intended that all state machine logic including the version of
 baseapp and tx handlers (and possibly even Tendermint) that an app needs
 can be described in a config object. For compatibility, the framework should
 allow a mixture of declarative and imperative app wiring, however, apps
 that strive for the maximum ease of maintainability should be able to describe
 their state machine with a config object alone. */
typedef struct _cosmos_app_v1alpha1_Config {
    /* modules are the module configurations for the app. */
    pb_callback_t modules;
    /* golang_bindings specifies explicit interface to implementation type bindings which
 depinject uses to resolve interface inputs to provider functions.  The scope of this
 field's configuration is global (not module specific). */
    pb_callback_t golang_bindings;
} cosmos_app_v1alpha1_Config;

/* ModuleConfig is a module configuration for an app. */
typedef struct _cosmos_app_v1alpha1_ModuleConfig {
    /* name is the unique name of the module within the app. It should be a name
 that persists between different versions of a module so that modules
 can be smoothly upgraded to new versions.

 For example, for the module cosmos.bank.module.v1.Module, we may chose
 to simply name the module "bank" in the app. When we upgrade to
 cosmos.bank.module.v2.Module, the app-specific name "bank" stays the same
 and the framework knows that the v2 module should receive all the same state
 that the v1 module had. Note: modules should provide info on which versions
 they can migrate from in the ModuleDescriptor.can_migration_from field. */
    pb_callback_t name;
    /* config is the config object for the module. Module config messages should
 define a ModuleDescriptor using the cosmos.app.v1alpha1.is_module extension. */
    bool has_config;
    google_protobuf_Any config;
    /* golang_bindings specifies explicit interface to implementation type bindings which
 depinject uses to resolve interface inputs to provider functions.  The scope of this
 field's configuration is module specific. */
    pb_callback_t golang_bindings;
} cosmos_app_v1alpha1_ModuleConfig;

/* GolangBinding is an explicit interface type to implementing type binding for dependency injection. */
typedef struct _cosmos_app_v1alpha1_GolangBinding {
    /* interface_type is the interface type which will be bound to a specific implementation type */
    pb_callback_t interface_type;
    /* implementation is the implementing type which will be supplied when an input of type interface is requested */
    pb_callback_t implementation;
} cosmos_app_v1alpha1_GolangBinding;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_app_v1alpha1_Config_init_default \
    {                                           \
        {{NULL}, NULL}, { {NULL}, NULL }        \
    }
#define cosmos_app_v1alpha1_ModuleConfig_init_default                             \
    {                                                                             \
        {{NULL}, NULL}, false, google_protobuf_Any_init_default, { {NULL}, NULL } \
    }
#define cosmos_app_v1alpha1_GolangBinding_init_default \
    {                                                  \
        {{NULL}, NULL}, { {NULL}, NULL }               \
    }
#define cosmos_app_v1alpha1_Config_init_zero \
    {                                        \
        {{NULL}, NULL}, { {NULL}, NULL }     \
    }
#define cosmos_app_v1alpha1_ModuleConfig_init_zero                             \
    {                                                                          \
        {{NULL}, NULL}, false, google_protobuf_Any_init_zero, { {NULL}, NULL } \
    }
#define cosmos_app_v1alpha1_GolangBinding_init_zero \
    {                                               \
        {{NULL}, NULL}, { {NULL}, NULL }            \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_app_v1alpha1_Config_modules_tag 1
#define cosmos_app_v1alpha1_Config_golang_bindings_tag 2
#define cosmos_app_v1alpha1_ModuleConfig_name_tag 1
#define cosmos_app_v1alpha1_ModuleConfig_config_tag 2
#define cosmos_app_v1alpha1_ModuleConfig_golang_bindings_tag 3
#define cosmos_app_v1alpha1_GolangBinding_interface_type_tag 1
#define cosmos_app_v1alpha1_GolangBinding_implementation_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_app_v1alpha1_Config_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, modules, 1)  \
    X(a, CALLBACK, REPEATED, MESSAGE, golang_bindings, 2)
#define cosmos_app_v1alpha1_Config_CALLBACK pb_default_field_callback
#define cosmos_app_v1alpha1_Config_DEFAULT NULL
#define cosmos_app_v1alpha1_Config_modules_MSGTYPE cosmos_app_v1alpha1_ModuleConfig
#define cosmos_app_v1alpha1_Config_golang_bindings_MSGTYPE cosmos_app_v1alpha1_GolangBinding

#define cosmos_app_v1alpha1_ModuleConfig_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)            \
    X(a, STATIC, OPTIONAL, MESSAGE, config, 2)           \
    X(a, CALLBACK, REPEATED, MESSAGE, golang_bindings, 3)
#define cosmos_app_v1alpha1_ModuleConfig_CALLBACK pb_default_field_callback
#define cosmos_app_v1alpha1_ModuleConfig_DEFAULT NULL
#define cosmos_app_v1alpha1_ModuleConfig_config_MSGTYPE google_protobuf_Any
#define cosmos_app_v1alpha1_ModuleConfig_golang_bindings_MSGTYPE cosmos_app_v1alpha1_GolangBinding

#define cosmos_app_v1alpha1_GolangBinding_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, interface_type, 1)   \
    X(a, CALLBACK, SINGULAR, STRING, implementation, 2)
#define cosmos_app_v1alpha1_GolangBinding_CALLBACK pb_default_field_callback
#define cosmos_app_v1alpha1_GolangBinding_DEFAULT NULL

extern const pb_msgdesc_t cosmos_app_v1alpha1_Config_msg;
extern const pb_msgdesc_t cosmos_app_v1alpha1_ModuleConfig_msg;
extern const pb_msgdesc_t cosmos_app_v1alpha1_GolangBinding_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_app_v1alpha1_Config_fields &cosmos_app_v1alpha1_Config_msg
#define cosmos_app_v1alpha1_ModuleConfig_fields &cosmos_app_v1alpha1_ModuleConfig_msg
#define cosmos_app_v1alpha1_GolangBinding_fields &cosmos_app_v1alpha1_GolangBinding_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_app_v1alpha1_Config_size depends on runtime parameters */
/* cosmos_app_v1alpha1_ModuleConfig_size depends on runtime parameters */
/* cosmos_app_v1alpha1_GolangBinding_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif