/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_PROTO_COSMOS_PROTO_COSMOS_PB_H_INCLUDED
#define PB_COSMOS_PROTO_COSMOS_PROTO_COSMOS_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _cosmos_proto_ScalarType {
    cosmos_proto_ScalarType_SCALAR_TYPE_UNSPECIFIED = 0,
    cosmos_proto_ScalarType_SCALAR_TYPE_STRING = 1,
    cosmos_proto_ScalarType_SCALAR_TYPE_BYTES = 2
} cosmos_proto_ScalarType;

/* Struct definitions */
/* InterfaceDescriptor describes an interface type to be used with
 accepts_interface and implements_interface and declared by declare_interface. */
typedef struct _cosmos_proto_InterfaceDescriptor {
    /* name is the name of the interface. It should be a short-name (without
 a period) such that the fully qualified name of the interface will be
 package.name, ex. for the package a.b and interface named C, the
 fully-qualified name will be a.b.C. */
    pb_callback_t name;
    /* description is a human-readable description of the interface and its
 purpose. */
    pb_callback_t description;
} cosmos_proto_InterfaceDescriptor;

/* ScalarDescriptor describes an scalar type to be used with
 the scalar field option and declared by declare_scalar.
 Scalars extend simple protobuf built-in types with additional
 syntax and semantics, for instance to represent big integers.
 Scalars should ideally define an encoding such that there is only one
 valid syntactical representation for a given semantic meaning,
 i.e. the encoding should be deterministic. */
typedef struct _cosmos_proto_ScalarDescriptor {
    /* name is the name of the scalar. It should be a short-name (without
 a period) such that the fully qualified name of the scalar will be
 package.name, ex. for the package a.b and scalar named C, the
 fully-qualified name will be a.b.C. */
    pb_callback_t name;
    /* description is a human-readable description of the scalar and its
 encoding format. For instance a big integer or decimal scalar should
 specify precisely the expected encoding format. */
    pb_callback_t description;
    /* field_type is the type of field with which this scalar can be used.
 Scalars can be used with one and only one type of field so that
 encoding standards and simple and clear. Currently only string and
 bytes fields are supported for scalars. */
    pb_callback_t field_type;
} cosmos_proto_ScalarDescriptor;

/* Extensions */
/* Extension field cosmos_proto_implements_interface was skipped because only "optional"
   type of extension fields is currently supported. */
/* Extension field cosmos_proto_accepts_interface was skipped because only "optional"
   type of extension fields is currently supported. */
/* Extension field cosmos_proto_scalar was skipped because only "optional"
   type of extension fields is currently supported. */
/* Extension field cosmos_proto_declare_interface was skipped because only "optional"
   type of extension fields is currently supported. */
/* Extension field cosmos_proto_declare_scalar was skipped because only "optional"
   type of extension fields is currently supported. */

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _cosmos_proto_ScalarType_MIN cosmos_proto_ScalarType_SCALAR_TYPE_UNSPECIFIED
#define _cosmos_proto_ScalarType_MAX cosmos_proto_ScalarType_SCALAR_TYPE_BYTES
#define _cosmos_proto_ScalarType_ARRAYSIZE ((cosmos_proto_ScalarType)(cosmos_proto_ScalarType_SCALAR_TYPE_BYTES + 1))

#define cosmos_proto_ScalarDescriptor_field_type_ENUMTYPE cosmos_proto_ScalarType

/* Initializer values for message structs */
#define cosmos_proto_InterfaceDescriptor_init_default \
    {                                                 \
        {{NULL}, NULL}, { {NULL}, NULL }              \
    }
#define cosmos_proto_ScalarDescriptor_init_default       \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }
#define cosmos_proto_InterfaceDescriptor_init_zero \
    {                                              \
        {{NULL}, NULL}, { {NULL}, NULL }           \
    }
#define cosmos_proto_ScalarDescriptor_init_zero          \
    {                                                    \
        {{NULL}, NULL}, {{NULL}, NULL}, { {NULL}, NULL } \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_proto_InterfaceDescriptor_name_tag 1
#define cosmos_proto_InterfaceDescriptor_description_tag 2
#define cosmos_proto_ScalarDescriptor_name_tag 1
#define cosmos_proto_ScalarDescriptor_description_tag 2
#define cosmos_proto_ScalarDescriptor_field_type_tag 3
#define cosmos_proto_implements_interface_tag 93001
#define cosmos_proto_accepts_interface_tag 93001
#define cosmos_proto_scalar_tag 93002
#define cosmos_proto_declare_interface_tag 793021
#define cosmos_proto_declare_scalar_tag 793022

/* Struct field encoding specification for nanopb */
#define cosmos_proto_InterfaceDescriptor_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)            \
    X(a, CALLBACK, SINGULAR, STRING, description, 2)
#define cosmos_proto_InterfaceDescriptor_CALLBACK pb_default_field_callback
#define cosmos_proto_InterfaceDescriptor_DEFAULT NULL

#define cosmos_proto_ScalarDescriptor_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)         \
    X(a, CALLBACK, SINGULAR, STRING, description, 2)  \
    X(a, CALLBACK, REPEATED, UENUM, field_type, 3)
#define cosmos_proto_ScalarDescriptor_CALLBACK pb_default_field_callback
#define cosmos_proto_ScalarDescriptor_DEFAULT NULL

extern const pb_msgdesc_t cosmos_proto_InterfaceDescriptor_msg;
extern const pb_msgdesc_t cosmos_proto_ScalarDescriptor_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_proto_InterfaceDescriptor_fields &cosmos_proto_InterfaceDescriptor_msg
#define cosmos_proto_ScalarDescriptor_fields &cosmos_proto_ScalarDescriptor_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_proto_InterfaceDescriptor_size depends on runtime parameters */
/* cosmos_proto_ScalarDescriptor_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
