/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_DISTRIBUTION_V1BETA1_COSMOS_DISTRIBUTION_V1BETA1_GENESIS_PB_H_INCLUDED
#define PB_COSMOS_DISTRIBUTION_V1BETA1_COSMOS_DISTRIBUTION_V1BETA1_GENESIS_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos/distribution/v1beta1/distribution.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* DelegatorWithdrawInfo is the address for where distributions rewards are
 withdrawn to by default this struct is only used at genesis to feed in
 default withdraw addresses. */
typedef struct _cosmos_distribution_v1beta1_DelegatorWithdrawInfo {
    /* delegator_address is the address of the delegator. */
    pb_callback_t delegator_address;
    /* withdraw_address is the address to withdraw the delegation rewards to. */
    pb_callback_t withdraw_address;
} cosmos_distribution_v1beta1_DelegatorWithdrawInfo;

/* ValidatorOutstandingRewardsRecord is used for import/export via genesis json. */
typedef struct _cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord {
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* outstanding_rewards represents the outstanding rewards of a validator. */
    pb_callback_t outstanding_rewards;
} cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord;

/* ValidatorAccumulatedCommissionRecord is used for import / export via genesis
 json. */
typedef struct _cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord {
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* accumulated is the accumulated commission of a validator. */
    bool has_accumulated;
    cosmos_distribution_v1beta1_ValidatorAccumulatedCommission accumulated;
} cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord;

/* ValidatorHistoricalRewardsRecord is used for import / export via genesis
 json. */
typedef struct _cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord {
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* period defines the period the historical rewards apply to. */
    uint64_t period;
    /* rewards defines the historical rewards of a validator. */
    bool has_rewards;
    cosmos_distribution_v1beta1_ValidatorHistoricalRewards rewards;
} cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord;

/* ValidatorCurrentRewardsRecord is used for import / export via genesis json. */
typedef struct _cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord {
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* rewards defines the current rewards of a validator. */
    bool has_rewards;
    cosmos_distribution_v1beta1_ValidatorCurrentRewards rewards;
} cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord;

/* DelegatorStartingInfoRecord used for import / export via genesis json. */
typedef struct _cosmos_distribution_v1beta1_DelegatorStartingInfoRecord {
    /* delegator_address is the address of the delegator. */
    pb_callback_t delegator_address;
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* starting_info defines the starting info of a delegator. */
    bool has_starting_info;
    cosmos_distribution_v1beta1_DelegatorStartingInfo starting_info;
} cosmos_distribution_v1beta1_DelegatorStartingInfoRecord;

/* ValidatorSlashEventRecord is used for import / export via genesis json. */
typedef struct _cosmos_distribution_v1beta1_ValidatorSlashEventRecord {
    /* validator_address is the address of the validator. */
    pb_callback_t validator_address;
    /* height defines the block height at which the slash event occurred. */
    uint64_t height;
    /* period is the period of the slash event. */
    uint64_t period;
    /* validator_slash_event describes the slash event. */
    bool has_validator_slash_event;
    cosmos_distribution_v1beta1_ValidatorSlashEvent validator_slash_event;
} cosmos_distribution_v1beta1_ValidatorSlashEventRecord;

/* GenesisState defines the distribution module's genesis state. */
typedef struct _cosmos_distribution_v1beta1_GenesisState {
    /* params defines all the parameters of the module. */
    bool has_params;
    cosmos_distribution_v1beta1_Params params;
    /* fee_pool defines the fee pool at genesis. */
    bool has_fee_pool;
    cosmos_distribution_v1beta1_FeePool fee_pool;
    /* fee_pool defines the delegator withdraw infos at genesis. */
    pb_callback_t delegator_withdraw_infos;
    /* fee_pool defines the previous proposer at genesis. */
    pb_callback_t previous_proposer;
    /* fee_pool defines the outstanding rewards of all validators at genesis. */
    pb_callback_t outstanding_rewards;
    /* fee_pool defines the accumulated commissions of all validators at genesis. */
    pb_callback_t validator_accumulated_commissions;
    /* fee_pool defines the historical rewards of all validators at genesis. */
    pb_callback_t validator_historical_rewards;
    /* fee_pool defines the current rewards of all validators at genesis. */
    pb_callback_t validator_current_rewards;
    /* fee_pool defines the delegator starting infos at genesis. */
    pb_callback_t delegator_starting_infos;
    /* fee_pool defines the validator slash events at genesis. */
    pb_callback_t validator_slash_events;
} cosmos_distribution_v1beta1_GenesisState;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_init_default \
    {                                                                  \
        {{NULL}, NULL}, { {NULL}, NULL }                               \
    }
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_init_default \
    {                                                                              \
        {{NULL}, NULL}, { {NULL}, NULL }                                           \
    }
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_init_default \
    { {{NULL}, NULL}, false, cosmos_distribution_v1beta1_ValidatorAccumulatedCommission_init_default }
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_init_default \
    { {{NULL}, NULL}, 0, false, cosmos_distribution_v1beta1_ValidatorHistoricalRewards_init_default }
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_init_default \
    { {{NULL}, NULL}, false, cosmos_distribution_v1beta1_ValidatorCurrentRewards_init_default }
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_init_default \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_distribution_v1beta1_DelegatorStartingInfo_init_default }
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_init_default \
    { {{NULL}, NULL}, 0, 0, false, cosmos_distribution_v1beta1_ValidatorSlashEvent_init_default }
#define cosmos_distribution_v1beta1_GenesisState_init_default                                                               \
    {                                                                                                                       \
        false, cosmos_distribution_v1beta1_Params_init_default, false, cosmos_distribution_v1beta1_FeePool_init_default,    \
            {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, \
        {                                                                                                                   \
            {NULL}, NULL                                                                                                    \
        }                                                                                                                   \
    }
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_init_zero \
    {                                                               \
        {{NULL}, NULL}, { {NULL}, NULL }                            \
    }
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_init_zero \
    {                                                                           \
        {{NULL}, NULL}, { {NULL}, NULL }                                        \
    }
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_init_zero \
    { {{NULL}, NULL}, false, cosmos_distribution_v1beta1_ValidatorAccumulatedCommission_init_zero }
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_init_zero \
    { {{NULL}, NULL}, 0, false, cosmos_distribution_v1beta1_ValidatorHistoricalRewards_init_zero }
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_init_zero \
    { {{NULL}, NULL}, false, cosmos_distribution_v1beta1_ValidatorCurrentRewards_init_zero }
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_init_zero \
    { {{NULL}, NULL}, {{NULL}, NULL}, false, cosmos_distribution_v1beta1_DelegatorStartingInfo_init_zero }
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_init_zero \
    { {{NULL}, NULL}, 0, 0, false, cosmos_distribution_v1beta1_ValidatorSlashEvent_init_zero }
#define cosmos_distribution_v1beta1_GenesisState_init_zero                                                                  \
    {                                                                                                                       \
        false, cosmos_distribution_v1beta1_Params_init_zero, false, cosmos_distribution_v1beta1_FeePool_init_zero,          \
            {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, \
        {                                                                                                                   \
            {NULL}, NULL                                                                                                    \
        }                                                                                                                   \
    }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_delegator_address_tag 1
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_withdraw_address_tag 2
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_validator_address_tag 1
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_outstanding_rewards_tag 2
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_validator_address_tag 1
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_accumulated_tag 2
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_validator_address_tag 1
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_period_tag 2
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_rewards_tag 3
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_validator_address_tag 1
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_rewards_tag 2
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_delegator_address_tag 1
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_validator_address_tag 2
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_starting_info_tag 3
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_validator_address_tag 1
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_height_tag 2
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_period_tag 3
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_validator_slash_event_tag 4
#define cosmos_distribution_v1beta1_GenesisState_params_tag 1
#define cosmos_distribution_v1beta1_GenesisState_fee_pool_tag 2
#define cosmos_distribution_v1beta1_GenesisState_delegator_withdraw_infos_tag 3
#define cosmos_distribution_v1beta1_GenesisState_previous_proposer_tag 4
#define cosmos_distribution_v1beta1_GenesisState_outstanding_rewards_tag 5
#define cosmos_distribution_v1beta1_GenesisState_validator_accumulated_commissions_tag 6
#define cosmos_distribution_v1beta1_GenesisState_validator_historical_rewards_tag 7
#define cosmos_distribution_v1beta1_GenesisState_validator_current_rewards_tag 8
#define cosmos_distribution_v1beta1_GenesisState_delegator_starting_infos_tag 9
#define cosmos_distribution_v1beta1_GenesisState_validator_slash_events_tag 10

/* Struct field encoding specification for nanopb */
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, delegator_address, 1)                \
    X(a, CALLBACK, SINGULAR, STRING, withdraw_address, 2)
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_DEFAULT NULL

#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 1)                            \
    X(a, CALLBACK, REPEATED, MESSAGE, outstanding_rewards, 2)
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_outstanding_rewards_MSGTYPE cosmos_base_v1beta1_DecCoin

#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 1)                               \
    X(a, STATIC, OPTIONAL, MESSAGE, accumulated, 2)
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_accumulated_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorAccumulatedCommission

#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 1)                           \
    X(a, STATIC, SINGULAR, UINT64, period, 2)                                        \
    X(a, STATIC, OPTIONAL, MESSAGE, rewards, 3)
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_rewards_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorHistoricalRewards

#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 1)                        \
    X(a, STATIC, OPTIONAL, MESSAGE, rewards, 2)
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_rewards_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorCurrentRewards

#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, delegator_address, 1)                      \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 2)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, starting_info, 3)
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_starting_info_MSGTYPE \
    cosmos_distribution_v1beta1_DelegatorStartingInfo

#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, validator_address, 1)                    \
    X(a, STATIC, SINGULAR, UINT64, height, 2)                                 \
    X(a, STATIC, SINGULAR, UINT64, period, 3)                                 \
    X(a, STATIC, OPTIONAL, MESSAGE, validator_slash_event, 4)
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_DEFAULT NULL
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_validator_slash_event_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorSlashEvent

#define cosmos_distribution_v1beta1_GenesisState_FIELDLIST(X, a)            \
    X(a, STATIC, OPTIONAL, MESSAGE, params, 1)                              \
    X(a, STATIC, OPTIONAL, MESSAGE, fee_pool, 2)                            \
    X(a, CALLBACK, REPEATED, MESSAGE, delegator_withdraw_infos, 3)          \
    X(a, CALLBACK, SINGULAR, STRING, previous_proposer, 4)                  \
    X(a, CALLBACK, REPEATED, MESSAGE, outstanding_rewards, 5)               \
    X(a, CALLBACK, REPEATED, MESSAGE, validator_accumulated_commissions, 6) \
    X(a, CALLBACK, REPEATED, MESSAGE, validator_historical_rewards, 7)      \
    X(a, CALLBACK, REPEATED, MESSAGE, validator_current_rewards, 8)         \
    X(a, CALLBACK, REPEATED, MESSAGE, delegator_starting_infos, 9)          \
    X(a, CALLBACK, REPEATED, MESSAGE, validator_slash_events, 10)
#define cosmos_distribution_v1beta1_GenesisState_CALLBACK pb_default_field_callback
#define cosmos_distribution_v1beta1_GenesisState_DEFAULT NULL
#define cosmos_distribution_v1beta1_GenesisState_params_MSGTYPE cosmos_distribution_v1beta1_Params
#define cosmos_distribution_v1beta1_GenesisState_fee_pool_MSGTYPE cosmos_distribution_v1beta1_FeePool
#define cosmos_distribution_v1beta1_GenesisState_delegator_withdraw_infos_MSGTYPE \
    cosmos_distribution_v1beta1_DelegatorWithdrawInfo
#define cosmos_distribution_v1beta1_GenesisState_outstanding_rewards_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord
#define cosmos_distribution_v1beta1_GenesisState_validator_accumulated_commissions_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord
#define cosmos_distribution_v1beta1_GenesisState_validator_historical_rewards_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord
#define cosmos_distribution_v1beta1_GenesisState_validator_current_rewards_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord
#define cosmos_distribution_v1beta1_GenesisState_delegator_starting_infos_MSGTYPE \
    cosmos_distribution_v1beta1_DelegatorStartingInfoRecord
#define cosmos_distribution_v1beta1_GenesisState_validator_slash_events_MSGTYPE \
    cosmos_distribution_v1beta1_ValidatorSlashEventRecord

extern const pb_msgdesc_t cosmos_distribution_v1beta1_DelegatorWithdrawInfo_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_ValidatorSlashEventRecord_msg;
extern const pb_msgdesc_t cosmos_distribution_v1beta1_GenesisState_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_distribution_v1beta1_DelegatorWithdrawInfo_fields &cosmos_distribution_v1beta1_DelegatorWithdrawInfo_msg
#define cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_fields \
    &cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_msg
#define cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_fields \
    &cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_msg
#define cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_fields \
    &cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_msg
#define cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_fields \
    &cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_msg
#define cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_fields \
    &cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_msg
#define cosmos_distribution_v1beta1_ValidatorSlashEventRecord_fields \
    &cosmos_distribution_v1beta1_ValidatorSlashEventRecord_msg
#define cosmos_distribution_v1beta1_GenesisState_fields &cosmos_distribution_v1beta1_GenesisState_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_distribution_v1beta1_DelegatorWithdrawInfo_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_ValidatorOutstandingRewardsRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_ValidatorAccumulatedCommissionRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_ValidatorHistoricalRewardsRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_ValidatorCurrentRewardsRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_DelegatorStartingInfoRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_ValidatorSlashEventRecord_size depends on runtime parameters */
/* cosmos_distribution_v1beta1_GenesisState_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
