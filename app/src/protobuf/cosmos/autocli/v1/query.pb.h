/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_AUTOCLI_V1_COSMOS_AUTOCLI_V1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_AUTOCLI_V1_COSMOS_AUTOCLI_V1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/autocli/v1/options.pb.h"
#include "cosmos/query/v1/query.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* AppOptionsRequest is the RemoteInfoService/AppOptions request type. */
typedef struct _cosmos_autocli_v1_AppOptionsRequest {
    char dummy_field;
} cosmos_autocli_v1_AppOptionsRequest;

/* AppOptionsResponse is the RemoteInfoService/AppOptions response type. */
typedef struct _cosmos_autocli_v1_AppOptionsResponse {
    /* module_options is a map of module name to autocli module options. */
    pb_callback_t module_options;
} cosmos_autocli_v1_AppOptionsResponse;

typedef struct _cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry {
    pb_callback_t key;
    bool has_value;
    cosmos_autocli_v1_ModuleOptions value;
} cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_autocli_v1_AppOptionsRequest_init_default \
    { 0 }
#define cosmos_autocli_v1_AppOptionsResponse_init_default \
    {                                                     \
        { {NULL}, NULL }                                  \
    }
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_init_default \
    { {{NULL}, NULL}, false, cosmos_autocli_v1_ModuleOptions_init_default }
#define cosmos_autocli_v1_AppOptionsRequest_init_zero \
    { 0 }
#define cosmos_autocli_v1_AppOptionsResponse_init_zero \
    {                                                  \
        { {NULL}, NULL }                               \
    }
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_init_zero \
    { {{NULL}, NULL}, false, cosmos_autocli_v1_ModuleOptions_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_autocli_v1_AppOptionsResponse_module_options_tag 1
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_key_tag 1
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_value_tag 2

/* Struct field encoding specification for nanopb */
#define cosmos_autocli_v1_AppOptionsRequest_FIELDLIST(X, a)

#define cosmos_autocli_v1_AppOptionsRequest_CALLBACK NULL
#define cosmos_autocli_v1_AppOptionsRequest_DEFAULT NULL

#define cosmos_autocli_v1_AppOptionsResponse_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, MESSAGE, module_options, 1)
#define cosmos_autocli_v1_AppOptionsResponse_CALLBACK pb_default_field_callback
#define cosmos_autocli_v1_AppOptionsResponse_DEFAULT NULL
#define cosmos_autocli_v1_AppOptionsResponse_module_options_MSGTYPE cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry

#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, key, 1)                                    \
    X(a, STATIC, OPTIONAL, MESSAGE, value, 2)
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_CALLBACK pb_default_field_callback
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_DEFAULT NULL
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_value_MSGTYPE cosmos_autocli_v1_ModuleOptions

extern const pb_msgdesc_t cosmos_autocli_v1_AppOptionsRequest_msg;
extern const pb_msgdesc_t cosmos_autocli_v1_AppOptionsResponse_msg;
extern const pb_msgdesc_t cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_autocli_v1_AppOptionsRequest_fields &cosmos_autocli_v1_AppOptionsRequest_msg
#define cosmos_autocli_v1_AppOptionsResponse_fields &cosmos_autocli_v1_AppOptionsResponse_msg
#define cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_fields \
    &cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_autocli_v1_AppOptionsResponse_size depends on runtime parameters */
/* cosmos_autocli_v1_AppOptionsResponse_ModuleOptionsEntry_size depends on runtime parameters */
#define COSMOS_AUTOCLI_V1_COSMOS_AUTOCLI_V1_QUERY_PB_H_MAX_SIZE cosmos_autocli_v1_AppOptionsRequest_size
#define cosmos_autocli_v1_AppOptionsRequest_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
