/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-1.0.0-dev */

#include "cosmos/orm/v1alpha1/schema.pb.h"
#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

PB_BIND(cosmos_orm_v1alpha1_ModuleSchemaDescriptor, cosmos_orm_v1alpha1_ModuleSchemaDescriptor, AUTO)

PB_BIND(cosmos_orm_v1alpha1_ModuleSchemaDescriptor_FileEntry, cosmos_orm_v1alpha1_ModuleSchemaDescriptor_FileEntry, AUTO)

/* Definition for extension field cosmos_orm_v1alpha1_module_schema */
typedef struct _cosmos_orm_v1alpha1_module_schema_extmsg {
    cosmos_orm_v1alpha1_ModuleSchemaDescriptor module_schema;
} cosmos_orm_v1alpha1_module_schema_extmsg;
#define cosmos_orm_v1alpha1_module_schema_extmsg_FIELDLIST(X, a) X(a, STATIC, REQUIRED, MESSAGE, module_schema, 1234)
#define cosmos_orm_v1alpha1_module_schema_extmsg_CALLBACK NULL
#define cosmos_orm_v1alpha1_module_schema_extmsg_DEFAULT NULL
#define cosmos_orm_v1alpha1_module_schema_extmsg_module_schema_MSGTYPE cosmos_orm_v1alpha1_ModuleSchemaDescriptor
pb_byte_t cosmos_orm_v1alpha1_module_schema_extmsg_default[] = {0x00};
PB_BIND(cosmos_orm_v1alpha1_module_schema_extmsg, cosmos_orm_v1alpha1_module_schema_extmsg, 4)
const pb_extension_type_t cosmos_orm_v1alpha1_module_schema = {NULL, NULL, &cosmos_orm_v1alpha1_module_schema_extmsg_msg};
