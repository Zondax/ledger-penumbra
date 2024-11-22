/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_CAPABILITY_V1_CAPABILITY_V1_CAPABILITY_PB_H_INCLUDED
#define PB_CAPABILITY_V1_CAPABILITY_V1_CAPABILITY_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Capability defines an implementation of an object capability. The index
 provided to a Capability must be globally unique. */
typedef struct _capability_v1_Capability {
    uint64_t index;
} capability_v1_Capability;

/* Owner defines a single capability owner. An owner is defined by the name of
 capability and the module name. */
typedef struct _capability_v1_Owner {
    pb_callback_t module;
    pb_callback_t name;
} capability_v1_Owner;

/* CapabilityOwners defines a set of owners of a single Capability. The set of
 owners must be unique. */
typedef struct _capability_v1_CapabilityOwners {
    pb_callback_t owners;
} capability_v1_CapabilityOwners;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define capability_v1_Capability_init_default \
    { 0 }
#define capability_v1_Owner_init_default \
    {                                    \
        {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define capability_v1_CapabilityOwners_init_default \
    {                                               \
        { {NULL}, NULL }                            \
    }
#define capability_v1_Capability_init_zero \
    { 0 }
#define capability_v1_Owner_init_zero    \
    {                                    \
        {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define capability_v1_CapabilityOwners_init_zero \
    {                                            \
        { {NULL}, NULL }                         \
    }

/* Field tags (for use in manual encoding/decoding) */
#define capability_v1_Capability_index_tag 1
#define capability_v1_Owner_module_tag 1
#define capability_v1_Owner_name_tag 2
#define capability_v1_CapabilityOwners_owners_tag 1

/* Struct field encoding specification for nanopb */
#define capability_v1_Capability_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UINT64, index, 1)
#define capability_v1_Capability_CALLBACK NULL
#define capability_v1_Capability_DEFAULT NULL

#define capability_v1_Owner_FIELDLIST(X, a)     \
    X(a, CALLBACK, SINGULAR, STRING, module, 1) \
    X(a, CALLBACK, SINGULAR, STRING, name, 2)
#define capability_v1_Owner_CALLBACK pb_default_field_callback
#define capability_v1_Owner_DEFAULT NULL

#define capability_v1_CapabilityOwners_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, MESSAGE, owners, 1)
#define capability_v1_CapabilityOwners_CALLBACK pb_default_field_callback
#define capability_v1_CapabilityOwners_DEFAULT NULL
#define capability_v1_CapabilityOwners_owners_MSGTYPE capability_v1_Owner

extern const pb_msgdesc_t capability_v1_Capability_msg;
extern const pb_msgdesc_t capability_v1_Owner_msg;
extern const pb_msgdesc_t capability_v1_CapabilityOwners_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define capability_v1_Capability_fields &capability_v1_Capability_msg
#define capability_v1_Owner_fields &capability_v1_Owner_msg
#define capability_v1_CapabilityOwners_fields &capability_v1_CapabilityOwners_msg

/* Maximum encoded size of messages (where known) */
/* capability_v1_Owner_size depends on runtime parameters */
/* capability_v1_CapabilityOwners_size depends on runtime parameters */
#define CAPABILITY_V1_CAPABILITY_V1_CAPABILITY_PB_H_MAX_SIZE capability_v1_Capability_size
#define capability_v1_Capability_size 11

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif