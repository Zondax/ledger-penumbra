/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_REFLECTION_V1_COSMOS_REFLECTION_V1_REFLECTION_PB_H_INCLUDED
#define PB_COSMOS_REFLECTION_V1_COSMOS_REFLECTION_V1_REFLECTION_PB_H_INCLUDED
#include <pb.h>

#include "cosmos/query/v1/query.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* FileDescriptorsRequest is the Query/FileDescriptors request type. */
typedef struct _cosmos_reflection_v1_FileDescriptorsRequest {
    char dummy_field;
} cosmos_reflection_v1_FileDescriptorsRequest;

/* FileDescriptorsResponse is the Query/FileDescriptors response type. */
typedef struct _cosmos_reflection_v1_FileDescriptorsResponse {
    /* files is the file descriptors. */
    pb_callback_t files;
} cosmos_reflection_v1_FileDescriptorsResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_reflection_v1_FileDescriptorsRequest_init_default \
    { 0 }
#define cosmos_reflection_v1_FileDescriptorsResponse_init_default \
    {                                                             \
        { {NULL}, NULL }                                          \
    }
#define cosmos_reflection_v1_FileDescriptorsRequest_init_zero \
    { 0 }
#define cosmos_reflection_v1_FileDescriptorsResponse_init_zero \
    {                                                          \
        { {NULL}, NULL }                                       \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_reflection_v1_FileDescriptorsResponse_files_tag 1

/* Struct field encoding specification for nanopb */
#define cosmos_reflection_v1_FileDescriptorsRequest_FIELDLIST(X, a)

#define cosmos_reflection_v1_FileDescriptorsRequest_CALLBACK NULL
#define cosmos_reflection_v1_FileDescriptorsRequest_DEFAULT NULL

#define cosmos_reflection_v1_FileDescriptorsResponse_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, MESSAGE, files, 1)
#define cosmos_reflection_v1_FileDescriptorsResponse_CALLBACK pb_default_field_callback
#define cosmos_reflection_v1_FileDescriptorsResponse_DEFAULT NULL
#define cosmos_reflection_v1_FileDescriptorsResponse_files_MSGTYPE google_protobuf_FileDescriptorProto

extern const pb_msgdesc_t cosmos_reflection_v1_FileDescriptorsRequest_msg;
extern const pb_msgdesc_t cosmos_reflection_v1_FileDescriptorsResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_reflection_v1_FileDescriptorsRequest_fields &cosmos_reflection_v1_FileDescriptorsRequest_msg
#define cosmos_reflection_v1_FileDescriptorsResponse_fields &cosmos_reflection_v1_FileDescriptorsResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_reflection_v1_FileDescriptorsResponse_size depends on runtime parameters */
#define COSMOS_REFLECTION_V1_COSMOS_REFLECTION_V1_REFLECTION_PB_H_MAX_SIZE cosmos_reflection_v1_FileDescriptorsRequest_size
#define cosmos_reflection_v1_FileDescriptorsRequest_size 0

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
