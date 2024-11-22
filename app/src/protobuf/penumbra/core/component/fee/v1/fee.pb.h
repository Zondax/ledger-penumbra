/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_PENUMBRA_CORE_COMPONENT_FEE_V1_PENUMBRA_CORE_COMPONENT_FEE_V1_FEE_PB_H_INCLUDED
#define PB_PENUMBRA_CORE_COMPONENT_FEE_V1_PENUMBRA_CORE_COMPONENT_FEE_V1_FEE_PB_H_INCLUDED
#include <pb.h>

#include "penumbra/core/asset/v1/asset.pb.h"
#include "penumbra/core/num/v1/num.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
/* The tier for the fee. */
typedef enum _penumbra_core_component_fee_v1_FeeTier_Tier {
    penumbra_core_component_fee_v1_FeeTier_Tier_TIER_UNSPECIFIED = 0,
    penumbra_core_component_fee_v1_FeeTier_Tier_TIER_LOW = 1,
    penumbra_core_component_fee_v1_FeeTier_Tier_TIER_MEDIUM = 2,
    penumbra_core_component_fee_v1_FeeTier_Tier_TIER_HIGH = 3
} penumbra_core_component_fee_v1_FeeTier_Tier;

/* Struct definitions */
/* Specifies fees paid by a transaction. */
typedef struct _penumbra_core_component_fee_v1_Fee {
    /* The amount of the token used to pay fees. */
    bool has_amount;
    penumbra_core_num_v1_Amount amount;
    /* If present, the asset ID of the token used to pay fees.
 If absent, specifies the staking token implicitly. */
    bool has_asset_id;
    penumbra_core_asset_v1_AssetId asset_id;
} penumbra_core_component_fee_v1_Fee;

/* Gas usage for a transaction.

 Gas used is multiplied by `GasPrices` to determine a `Fee`. */
typedef struct _penumbra_core_component_fee_v1_Gas {
    /* The amount of block space used. */
    uint64_t block_space;
    /* The amount of compact block space used. */
    uint64_t compact_block_space;
    /* The amount of verification cost used. */
    uint64_t verification;
    /* The amount of execution cost used. */
    uint64_t execution;
} penumbra_core_component_fee_v1_Gas;

typedef struct _penumbra_core_component_fee_v1_GasPrices {
    /* The price per unit block space in terms of the staking token, with an implicit 1,000 denominator. */
    uint64_t block_space_price;
    /* The price per unit compact block space in terms of the staking token, with an implicit 1,000 denominator. */
    uint64_t compact_block_space_price;
    /* The price per unit verification cost in terms of the staking token, with an implicit 1,000 denominator. */
    uint64_t verification_price;
    /* The price per unit execution cost in terms of the staking token, with an implicit 1,000 denominator. */
    uint64_t execution_price;
    /* The asset ID of the fee token these prices are for.

 If absent, specifies the staking token implicitly. */
    bool has_asset_id;
    penumbra_core_asset_v1_AssetId asset_id;
} penumbra_core_component_fee_v1_GasPrices;

typedef struct _penumbra_core_component_fee_v1_FeeTier {
    /* The selected fee tier. */
    penumbra_core_component_fee_v1_FeeTier_Tier fee_tier;
} penumbra_core_component_fee_v1_FeeTier;

/* Fee component configuration data. */
typedef struct _penumbra_core_component_fee_v1_FeeParameters {
    /* Fixed gas prices in the native token used to compute transactions' base
 fees.

 In the future, this should be removed and replaced with parameters for
 dynamic gas pricing. */
    bool has_fixed_gas_prices;
    penumbra_core_component_fee_v1_GasPrices fixed_gas_prices;
    /* Fixed gas prices in other tokens used to compute transactions' base fees.

 In the future, this should be removed and replaced with fixed multiples of
 the native token's price (so that there is one set of dynamically
 determined gas prices in the native token, and derived gas prices in other
 alternative tokens).

 If this is empty, no other tokens are accepted for gas. */
    pb_callback_t fixed_alt_gas_prices;
} penumbra_core_component_fee_v1_FeeParameters;

/* Fee-specific genesis content. */
typedef struct _penumbra_core_component_fee_v1_GenesisContent {
    /* The FeeParameters present at genesis. */
    bool has_fee_params;
    penumbra_core_component_fee_v1_FeeParameters fee_params;
} penumbra_core_component_fee_v1_GenesisContent;

typedef struct _penumbra_core_component_fee_v1_CurrentGasPricesRequest {
    char dummy_field;
} penumbra_core_component_fee_v1_CurrentGasPricesRequest;

typedef struct _penumbra_core_component_fee_v1_CurrentGasPricesResponse {
    /* The current gas prices, in the preferred (native) token. */
    bool has_gas_prices;
    penumbra_core_component_fee_v1_GasPrices gas_prices;
    /* Other gas prices for other accepted tokens. */
    pb_callback_t alt_gas_prices;
} penumbra_core_component_fee_v1_CurrentGasPricesResponse;

/* Emitted during fee payment. */
typedef struct _penumbra_core_component_fee_v1_EventPaidFee {
    /* The fee paid. */
    bool has_fee;
    penumbra_core_component_fee_v1_Fee fee;
    /* The base fee that was required. */
    bool has_base_fee;
    penumbra_core_component_fee_v1_Fee base_fee;
    /* The tip that was paid to the proposer. */
    bool has_tip;
    penumbra_core_component_fee_v1_Fee tip;
    /* The gas used to compute the base fee. */
    bool has_gas_used;
    penumbra_core_component_fee_v1_Gas gas_used;
} penumbra_core_component_fee_v1_EventPaidFee;

/* Emitted as a summary of fees in the block. */
typedef struct _penumbra_core_component_fee_v1_EventBlockFees {
    /* The total fees, after swapping to the native token. */
    bool has_swapped_fee_total;
    penumbra_core_component_fee_v1_Fee swapped_fee_total;
    /* The total base fees, after swapping to the native token. */
    bool has_swapped_base_fee_total;
    penumbra_core_component_fee_v1_Fee swapped_base_fee_total;
    /* The total tips, after swapping to the native token. */
    bool has_swapped_tip_total;
    penumbra_core_component_fee_v1_Fee swapped_tip_total;
} penumbra_core_component_fee_v1_EventBlockFees;

#ifdef __cplusplus
extern "C" {
#endif

/* Helper constants for enums */
#define _penumbra_core_component_fee_v1_FeeTier_Tier_MIN penumbra_core_component_fee_v1_FeeTier_Tier_TIER_UNSPECIFIED
#define _penumbra_core_component_fee_v1_FeeTier_Tier_MAX penumbra_core_component_fee_v1_FeeTier_Tier_TIER_HIGH
#define _penumbra_core_component_fee_v1_FeeTier_Tier_ARRAYSIZE \
    ((penumbra_core_component_fee_v1_FeeTier_Tier)(penumbra_core_component_fee_v1_FeeTier_Tier_TIER_HIGH + 1))

#define penumbra_core_component_fee_v1_FeeTier_fee_tier_ENUMTYPE penumbra_core_component_fee_v1_FeeTier_Tier

/* Initializer values for message structs */
#define penumbra_core_component_fee_v1_Fee_init_default \
    { false, penumbra_core_num_v1_Amount_init_default, false, penumbra_core_asset_v1_AssetId_init_default }
#define penumbra_core_component_fee_v1_Gas_init_default \
    { 0, 0, 0, 0 }
#define penumbra_core_component_fee_v1_GasPrices_init_default \
    { 0, 0, 0, 0, false, penumbra_core_asset_v1_AssetId_init_default }
#define penumbra_core_component_fee_v1_FeeTier_init_default \
    { _penumbra_core_component_fee_v1_FeeTier_Tier_MIN }
#define penumbra_core_component_fee_v1_FeeParameters_init_default                      \
    {                                                                                  \
        false, penumbra_core_component_fee_v1_GasPrices_init_default, { {NULL}, NULL } \
    }
#define penumbra_core_component_fee_v1_GenesisContent_init_default \
    { false, penumbra_core_component_fee_v1_FeeParameters_init_default }
#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_init_default \
    { 0 }
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_init_default           \
    {                                                                                  \
        false, penumbra_core_component_fee_v1_GasPrices_init_default, { {NULL}, NULL } \
    }
#define penumbra_core_component_fee_v1_EventPaidFee_init_default                                                           \
    {                                                                                                                      \
        false, penumbra_core_component_fee_v1_Fee_init_default, false, penumbra_core_component_fee_v1_Fee_init_default,    \
            false, penumbra_core_component_fee_v1_Fee_init_default, false, penumbra_core_component_fee_v1_Gas_init_default \
    }
#define penumbra_core_component_fee_v1_EventBlockFees_init_default                                                      \
    {                                                                                                                   \
        false, penumbra_core_component_fee_v1_Fee_init_default, false, penumbra_core_component_fee_v1_Fee_init_default, \
            false, penumbra_core_component_fee_v1_Fee_init_default                                                      \
    }
#define penumbra_core_component_fee_v1_Fee_init_zero \
    { false, penumbra_core_num_v1_Amount_init_zero, false, penumbra_core_asset_v1_AssetId_init_zero }
#define penumbra_core_component_fee_v1_Gas_init_zero \
    { 0, 0, 0, 0 }
#define penumbra_core_component_fee_v1_GasPrices_init_zero \
    { 0, 0, 0, 0, false, penumbra_core_asset_v1_AssetId_init_zero }
#define penumbra_core_component_fee_v1_FeeTier_init_zero \
    { _penumbra_core_component_fee_v1_FeeTier_Tier_MIN }
#define penumbra_core_component_fee_v1_FeeParameters_init_zero                      \
    {                                                                               \
        false, penumbra_core_component_fee_v1_GasPrices_init_zero, { {NULL}, NULL } \
    }
#define penumbra_core_component_fee_v1_GenesisContent_init_zero \
    { false, penumbra_core_component_fee_v1_FeeParameters_init_zero }
#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_init_zero \
    { 0 }
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_init_zero           \
    {                                                                               \
        false, penumbra_core_component_fee_v1_GasPrices_init_zero, { {NULL}, NULL } \
    }
#define penumbra_core_component_fee_v1_EventPaidFee_init_zero                                                            \
    {                                                                                                                    \
        false, penumbra_core_component_fee_v1_Fee_init_zero, false, penumbra_core_component_fee_v1_Fee_init_zero, false, \
            penumbra_core_component_fee_v1_Fee_init_zero, false, penumbra_core_component_fee_v1_Gas_init_zero            \
    }
#define penumbra_core_component_fee_v1_EventBlockFees_init_zero                                                          \
    {                                                                                                                    \
        false, penumbra_core_component_fee_v1_Fee_init_zero, false, penumbra_core_component_fee_v1_Fee_init_zero, false, \
            penumbra_core_component_fee_v1_Fee_init_zero                                                                 \
    }

/* Field tags (for use in manual encoding/decoding) */
#define penumbra_core_component_fee_v1_Fee_amount_tag 1
#define penumbra_core_component_fee_v1_Fee_asset_id_tag 2
#define penumbra_core_component_fee_v1_Gas_block_space_tag 1
#define penumbra_core_component_fee_v1_Gas_compact_block_space_tag 2
#define penumbra_core_component_fee_v1_Gas_verification_tag 3
#define penumbra_core_component_fee_v1_Gas_execution_tag 4
#define penumbra_core_component_fee_v1_GasPrices_block_space_price_tag 1
#define penumbra_core_component_fee_v1_GasPrices_compact_block_space_price_tag 2
#define penumbra_core_component_fee_v1_GasPrices_verification_price_tag 3
#define penumbra_core_component_fee_v1_GasPrices_execution_price_tag 4
#define penumbra_core_component_fee_v1_GasPrices_asset_id_tag 15
#define penumbra_core_component_fee_v1_FeeTier_fee_tier_tag 1
#define penumbra_core_component_fee_v1_FeeParameters_fixed_gas_prices_tag 1
#define penumbra_core_component_fee_v1_FeeParameters_fixed_alt_gas_prices_tag 2
#define penumbra_core_component_fee_v1_GenesisContent_fee_params_tag 1
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_gas_prices_tag 1
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_alt_gas_prices_tag 2
#define penumbra_core_component_fee_v1_EventPaidFee_fee_tag 1
#define penumbra_core_component_fee_v1_EventPaidFee_base_fee_tag 2
#define penumbra_core_component_fee_v1_EventPaidFee_tip_tag 3
#define penumbra_core_component_fee_v1_EventPaidFee_gas_used_tag 4
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_fee_total_tag 1
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_base_fee_total_tag 2
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_tip_total_tag 3

/* Struct field encoding specification for nanopb */
#define penumbra_core_component_fee_v1_Fee_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, amount, 1)             \
    X(a, STATIC, OPTIONAL, MESSAGE, asset_id, 2)
#define penumbra_core_component_fee_v1_Fee_CALLBACK NULL
#define penumbra_core_component_fee_v1_Fee_DEFAULT NULL
#define penumbra_core_component_fee_v1_Fee_amount_MSGTYPE penumbra_core_num_v1_Amount
#define penumbra_core_component_fee_v1_Fee_asset_id_MSGTYPE penumbra_core_asset_v1_AssetId

#define penumbra_core_component_fee_v1_Gas_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, block_space, 1)         \
    X(a, STATIC, SINGULAR, UINT64, compact_block_space, 2) \
    X(a, STATIC, SINGULAR, UINT64, verification, 3)        \
    X(a, STATIC, SINGULAR, UINT64, execution, 4)
#define penumbra_core_component_fee_v1_Gas_CALLBACK NULL
#define penumbra_core_component_fee_v1_Gas_DEFAULT NULL

#define penumbra_core_component_fee_v1_GasPrices_FIELDLIST(X, a) \
    X(a, STATIC, SINGULAR, UINT64, block_space_price, 1)         \
    X(a, STATIC, SINGULAR, UINT64, compact_block_space_price, 2) \
    X(a, STATIC, SINGULAR, UINT64, verification_price, 3)        \
    X(a, STATIC, SINGULAR, UINT64, execution_price, 4)           \
    X(a, STATIC, OPTIONAL, MESSAGE, asset_id, 15)
#define penumbra_core_component_fee_v1_GasPrices_CALLBACK NULL
#define penumbra_core_component_fee_v1_GasPrices_DEFAULT NULL
#define penumbra_core_component_fee_v1_GasPrices_asset_id_MSGTYPE penumbra_core_asset_v1_AssetId

#define penumbra_core_component_fee_v1_FeeTier_FIELDLIST(X, a) X(a, STATIC, SINGULAR, UENUM, fee_tier, 1)
#define penumbra_core_component_fee_v1_FeeTier_CALLBACK NULL
#define penumbra_core_component_fee_v1_FeeTier_DEFAULT NULL

#define penumbra_core_component_fee_v1_FeeParameters_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, fixed_gas_prices, 1)             \
    X(a, CALLBACK, REPEATED, MESSAGE, fixed_alt_gas_prices, 2)
#define penumbra_core_component_fee_v1_FeeParameters_CALLBACK pb_default_field_callback
#define penumbra_core_component_fee_v1_FeeParameters_DEFAULT NULL
#define penumbra_core_component_fee_v1_FeeParameters_fixed_gas_prices_MSGTYPE penumbra_core_component_fee_v1_GasPrices
#define penumbra_core_component_fee_v1_FeeParameters_fixed_alt_gas_prices_MSGTYPE penumbra_core_component_fee_v1_GasPrices

#define penumbra_core_component_fee_v1_GenesisContent_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, fee_params, 1)
#define penumbra_core_component_fee_v1_GenesisContent_CALLBACK NULL
#define penumbra_core_component_fee_v1_GenesisContent_DEFAULT NULL
#define penumbra_core_component_fee_v1_GenesisContent_fee_params_MSGTYPE penumbra_core_component_fee_v1_FeeParameters

#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_FIELDLIST(X, a)

#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_CALLBACK NULL
#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_DEFAULT NULL

#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, gas_prices, 1)                              \
    X(a, CALLBACK, REPEATED, MESSAGE, alt_gas_prices, 2)
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_CALLBACK pb_default_field_callback
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_DEFAULT NULL
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_gas_prices_MSGTYPE penumbra_core_component_fee_v1_GasPrices
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_alt_gas_prices_MSGTYPE \
    penumbra_core_component_fee_v1_GasPrices

#define penumbra_core_component_fee_v1_EventPaidFee_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, fee, 1)                         \
    X(a, STATIC, OPTIONAL, MESSAGE, base_fee, 2)                    \
    X(a, STATIC, OPTIONAL, MESSAGE, tip, 3)                         \
    X(a, STATIC, OPTIONAL, MESSAGE, gas_used, 4)
#define penumbra_core_component_fee_v1_EventPaidFee_CALLBACK NULL
#define penumbra_core_component_fee_v1_EventPaidFee_DEFAULT NULL
#define penumbra_core_component_fee_v1_EventPaidFee_fee_MSGTYPE penumbra_core_component_fee_v1_Fee
#define penumbra_core_component_fee_v1_EventPaidFee_base_fee_MSGTYPE penumbra_core_component_fee_v1_Fee
#define penumbra_core_component_fee_v1_EventPaidFee_tip_MSGTYPE penumbra_core_component_fee_v1_Fee
#define penumbra_core_component_fee_v1_EventPaidFee_gas_used_MSGTYPE penumbra_core_component_fee_v1_Gas

#define penumbra_core_component_fee_v1_EventBlockFees_FIELDLIST(X, a) \
    X(a, STATIC, OPTIONAL, MESSAGE, swapped_fee_total, 1)             \
    X(a, STATIC, OPTIONAL, MESSAGE, swapped_base_fee_total, 2)        \
    X(a, STATIC, OPTIONAL, MESSAGE, swapped_tip_total, 3)
#define penumbra_core_component_fee_v1_EventBlockFees_CALLBACK NULL
#define penumbra_core_component_fee_v1_EventBlockFees_DEFAULT NULL
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_fee_total_MSGTYPE penumbra_core_component_fee_v1_Fee
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_base_fee_total_MSGTYPE penumbra_core_component_fee_v1_Fee
#define penumbra_core_component_fee_v1_EventBlockFees_swapped_tip_total_MSGTYPE penumbra_core_component_fee_v1_Fee

extern const pb_msgdesc_t penumbra_core_component_fee_v1_Fee_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_Gas_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_GasPrices_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_FeeTier_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_FeeParameters_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_GenesisContent_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_CurrentGasPricesRequest_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_CurrentGasPricesResponse_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_EventPaidFee_msg;
extern const pb_msgdesc_t penumbra_core_component_fee_v1_EventBlockFees_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define penumbra_core_component_fee_v1_Fee_fields &penumbra_core_component_fee_v1_Fee_msg
#define penumbra_core_component_fee_v1_Gas_fields &penumbra_core_component_fee_v1_Gas_msg
#define penumbra_core_component_fee_v1_GasPrices_fields &penumbra_core_component_fee_v1_GasPrices_msg
#define penumbra_core_component_fee_v1_FeeTier_fields &penumbra_core_component_fee_v1_FeeTier_msg
#define penumbra_core_component_fee_v1_FeeParameters_fields &penumbra_core_component_fee_v1_FeeParameters_msg
#define penumbra_core_component_fee_v1_GenesisContent_fields &penumbra_core_component_fee_v1_GenesisContent_msg
#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_fields \
    &penumbra_core_component_fee_v1_CurrentGasPricesRequest_msg
#define penumbra_core_component_fee_v1_CurrentGasPricesResponse_fields \
    &penumbra_core_component_fee_v1_CurrentGasPricesResponse_msg
#define penumbra_core_component_fee_v1_EventPaidFee_fields &penumbra_core_component_fee_v1_EventPaidFee_msg
#define penumbra_core_component_fee_v1_EventBlockFees_fields &penumbra_core_component_fee_v1_EventBlockFees_msg

/* Maximum encoded size of messages (where known) */
/* penumbra_core_component_fee_v1_FeeParameters_size depends on runtime parameters */
/* penumbra_core_component_fee_v1_GenesisContent_size depends on runtime parameters */
/* penumbra_core_component_fee_v1_CurrentGasPricesResponse_size depends on runtime parameters */
#if defined(penumbra_core_asset_v1_AssetId_size)
#define penumbra_core_component_fee_v1_Fee_size (30 + penumbra_core_asset_v1_AssetId_size)
#define penumbra_core_component_fee_v1_GasPrices_size (50 + penumbra_core_asset_v1_AssetId_size)
#endif
#define penumbra_core_component_fee_v1_CurrentGasPricesRequest_size 0
#define penumbra_core_component_fee_v1_FeeTier_size 2
#define penumbra_core_component_fee_v1_Gas_size 44
#if defined(penumbra_core_asset_v1_AssetId_size) && defined(penumbra_core_asset_v1_AssetId_size) && \
    defined(penumbra_core_asset_v1_AssetId_size)
#define PENUMBRA_CORE_COMPONENT_FEE_V1_PENUMBRA_CORE_COMPONENT_FEE_V1_FEE_PB_H_MAX_SIZE \
    penumbra_core_component_fee_v1_EventPaidFee_size
#define penumbra_core_component_fee_v1_EventBlockFees_size \
    (108 + penumbra_core_asset_v1_AssetId_size + penumbra_core_asset_v1_AssetId_size + penumbra_core_asset_v1_AssetId_size)
#define penumbra_core_component_fee_v1_EventPaidFee_size \
    (154 + penumbra_core_asset_v1_AssetId_size + penumbra_core_asset_v1_AssetId_size + penumbra_core_asset_v1_AssetId_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif