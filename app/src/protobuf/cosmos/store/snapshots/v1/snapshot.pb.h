/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_STORE_SNAPSHOTS_V1_COSMOS_STORE_SNAPSHOTS_V1_SNAPSHOT_PB_H_INCLUDED
#define PB_COSMOS_STORE_SNAPSHOTS_V1_COSMOS_STORE_SNAPSHOTS_V1_SNAPSHOT_PB_H_INCLUDED
#include <pb.h>

#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* Metadata contains SDK-specific snapshot metadata. */
typedef struct _cosmos_store_snapshots_v1_Metadata {
    pb_callback_t chunk_hashes; /* SHA-256 chunk hashes */
} cosmos_store_snapshots_v1_Metadata;

/* Snapshot contains Tendermint state sync snapshot info. */
typedef struct _cosmos_store_snapshots_v1_Snapshot {
    uint64_t height;
    uint32_t format;
    uint32_t chunks;
    pb_callback_t hash;
    bool has_metadata;
    cosmos_store_snapshots_v1_Metadata metadata;
} cosmos_store_snapshots_v1_Snapshot;

/* SnapshotStoreItem contains metadata about a snapshotted store.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_store_snapshots_v1_SnapshotStoreItem {
    pb_callback_t name;
} cosmos_store_snapshots_v1_SnapshotStoreItem;

/* SnapshotIAVLItem is an exported IAVL node.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_store_snapshots_v1_SnapshotIAVLItem {
    pb_callback_t key;
    pb_callback_t value;
    /* version is block height */
    int64_t version;
    /* height is depth of the tree. */
    int32_t height;
} cosmos_store_snapshots_v1_SnapshotIAVLItem;

/* SnapshotExtensionMeta contains metadata about an external snapshotter.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_store_snapshots_v1_SnapshotExtensionMeta {
    pb_callback_t name;
    uint32_t format;
} cosmos_store_snapshots_v1_SnapshotExtensionMeta;

/* SnapshotExtensionPayload contains payloads of an external snapshotter.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_store_snapshots_v1_SnapshotExtensionPayload {
    pb_callback_t payload;
} cosmos_store_snapshots_v1_SnapshotExtensionPayload;

/* SnapshotItem is an item contained in a rootmulti.Store snapshot.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_store_snapshots_v1_SnapshotItem {
    pb_size_t which_item;
    union {
        cosmos_store_snapshots_v1_SnapshotStoreItem store;
        cosmos_store_snapshots_v1_SnapshotIAVLItem iavl;
        cosmos_store_snapshots_v1_SnapshotExtensionMeta extension;
        cosmos_store_snapshots_v1_SnapshotExtensionPayload extension_payload;
    } item;
} cosmos_store_snapshots_v1_SnapshotItem;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_store_snapshots_v1_Snapshot_init_default \
    { 0, 0, 0, {{NULL}, NULL}, false, cosmos_store_snapshots_v1_Metadata_init_default }
#define cosmos_store_snapshots_v1_Metadata_init_default \
    {                                                   \
        { {NULL}, NULL }                                \
    }
#define cosmos_store_snapshots_v1_SnapshotItem_init_default             \
    {                                                                   \
        0, { cosmos_store_snapshots_v1_SnapshotStoreItem_init_default } \
    }
#define cosmos_store_snapshots_v1_SnapshotStoreItem_init_default \
    {                                                            \
        { {NULL}, NULL }                                         \
    }
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, 0, 0 }
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_init_default \
    { {{NULL}, NULL}, 0 }
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_init_default \
    {                                                                   \
        { {NULL}, NULL }                                                \
    }
#define cosmos_store_snapshots_v1_Snapshot_init_zero \
    { 0, 0, 0, {{NULL}, NULL}, false, cosmos_store_snapshots_v1_Metadata_init_zero }
#define cosmos_store_snapshots_v1_Metadata_init_zero \
    {                                                \
        { {NULL}, NULL }                             \
    }
#define cosmos_store_snapshots_v1_SnapshotItem_init_zero             \
    {                                                                \
        0, { cosmos_store_snapshots_v1_SnapshotStoreItem_init_zero } \
    }
#define cosmos_store_snapshots_v1_SnapshotStoreItem_init_zero \
    {                                                         \
        { {NULL}, NULL }                                      \
    }
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, 0, 0 }
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_init_zero \
    { {{NULL}, NULL}, 0 }
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_init_zero \
    {                                                                \
        { {NULL}, NULL }                                             \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_store_snapshots_v1_Metadata_chunk_hashes_tag 1
#define cosmos_store_snapshots_v1_Snapshot_height_tag 1
#define cosmos_store_snapshots_v1_Snapshot_format_tag 2
#define cosmos_store_snapshots_v1_Snapshot_chunks_tag 3
#define cosmos_store_snapshots_v1_Snapshot_hash_tag 4
#define cosmos_store_snapshots_v1_Snapshot_metadata_tag 5
#define cosmos_store_snapshots_v1_SnapshotStoreItem_name_tag 1
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_key_tag 1
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_value_tag 2
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_version_tag 3
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_height_tag 4
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_name_tag 1
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_format_tag 2
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_payload_tag 1
#define cosmos_store_snapshots_v1_SnapshotItem_store_tag 1
#define cosmos_store_snapshots_v1_SnapshotItem_iavl_tag 2
#define cosmos_store_snapshots_v1_SnapshotItem_extension_tag 3
#define cosmos_store_snapshots_v1_SnapshotItem_extension_payload_tag 4

/* Struct field encoding specification for nanopb */
#define cosmos_store_snapshots_v1_Snapshot_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, height, 1)              \
    X(a, STATIC, SINGULAR, UINT32, format, 2)              \
    X(a, STATIC, SINGULAR, UINT32, chunks, 3)              \
    X(a, CALLBACK, SINGULAR, BYTES, hash, 4)               \
    X(a, STATIC, OPTIONAL, MESSAGE, metadata, 5)
#define cosmos_store_snapshots_v1_Snapshot_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_Snapshot_DEFAULT NULL
#define cosmos_store_snapshots_v1_Snapshot_metadata_MSGTYPE cosmos_store_snapshots_v1_Metadata

#define cosmos_store_snapshots_v1_Metadata_FIELDLIST(X, a) X(a, CALLBACK, REPEATED, BYTES, chunk_hashes, 1)
#define cosmos_store_snapshots_v1_Metadata_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_Metadata_DEFAULT NULL

#define cosmos_store_snapshots_v1_SnapshotItem_FIELDLIST(X, a)         \
    X(a, STATIC, ONEOF, MESSAGE, (item, store, item.store), 1)         \
    X(a, STATIC, ONEOF, MESSAGE, (item, iavl, item.iavl), 2)           \
    X(a, STATIC, ONEOF, MESSAGE, (item, extension, item.extension), 3) \
    X(a, STATIC, ONEOF, MESSAGE, (item, extension_payload, item.extension_payload), 4)
#define cosmos_store_snapshots_v1_SnapshotItem_CALLBACK NULL
#define cosmos_store_snapshots_v1_SnapshotItem_DEFAULT NULL
#define cosmos_store_snapshots_v1_SnapshotItem_item_store_MSGTYPE cosmos_store_snapshots_v1_SnapshotStoreItem
#define cosmos_store_snapshots_v1_SnapshotItem_item_iavl_MSGTYPE cosmos_store_snapshots_v1_SnapshotIAVLItem
#define cosmos_store_snapshots_v1_SnapshotItem_item_extension_MSGTYPE cosmos_store_snapshots_v1_SnapshotExtensionMeta
#define cosmos_store_snapshots_v1_SnapshotItem_item_extension_payload_MSGTYPE \
    cosmos_store_snapshots_v1_SnapshotExtensionPayload

#define cosmos_store_snapshots_v1_SnapshotStoreItem_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, name, 1)
#define cosmos_store_snapshots_v1_SnapshotStoreItem_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_SnapshotStoreItem_DEFAULT NULL

#define cosmos_store_snapshots_v1_SnapshotIAVLItem_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, BYTES, key, 1)                        \
    X(a, CALLBACK, SINGULAR, BYTES, value, 2)                      \
    X(a, STATIC, SINGULAR, INT64, version, 3)                      \
    X(a, STATIC, SINGULAR, INT32, height, 4)
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_DEFAULT NULL

#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, name, 1)                           \
    X(a, STATIC, SINGULAR, UINT32, format, 2)
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_DEFAULT NULL

#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, BYTES, payload, 1)
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_CALLBACK pb_default_field_callback
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_DEFAULT NULL

extern const pb_msgdesc_t cosmos_store_snapshots_v1_Snapshot_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_Metadata_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_SnapshotItem_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_SnapshotStoreItem_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_SnapshotIAVLItem_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_SnapshotExtensionMeta_msg;
extern const pb_msgdesc_t cosmos_store_snapshots_v1_SnapshotExtensionPayload_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_store_snapshots_v1_Snapshot_fields &cosmos_store_snapshots_v1_Snapshot_msg
#define cosmos_store_snapshots_v1_Metadata_fields &cosmos_store_snapshots_v1_Metadata_msg
#define cosmos_store_snapshots_v1_SnapshotItem_fields &cosmos_store_snapshots_v1_SnapshotItem_msg
#define cosmos_store_snapshots_v1_SnapshotStoreItem_fields &cosmos_store_snapshots_v1_SnapshotStoreItem_msg
#define cosmos_store_snapshots_v1_SnapshotIAVLItem_fields &cosmos_store_snapshots_v1_SnapshotIAVLItem_msg
#define cosmos_store_snapshots_v1_SnapshotExtensionMeta_fields &cosmos_store_snapshots_v1_SnapshotExtensionMeta_msg
#define cosmos_store_snapshots_v1_SnapshotExtensionPayload_fields &cosmos_store_snapshots_v1_SnapshotExtensionPayload_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_store_snapshots_v1_Snapshot_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_Metadata_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_SnapshotItem_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_SnapshotStoreItem_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_SnapshotIAVLItem_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_SnapshotExtensionMeta_size depends on runtime parameters */
/* cosmos_store_snapshots_v1_SnapshotExtensionPayload_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
