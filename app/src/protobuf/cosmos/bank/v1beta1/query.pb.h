/* Automatically generated nanopb header */
/* Generated by nanopb-1.0.0-dev */

#ifndef PB_COSMOS_BANK_V1BETA1_COSMOS_BANK_V1BETA1_QUERY_PB_H_INCLUDED
#define PB_COSMOS_BANK_V1BETA1_COSMOS_BANK_V1BETA1_QUERY_PB_H_INCLUDED
#include <pb.h>

#include "amino/amino.pb.h"
#include "cosmos/bank/v1beta1/bank.pb.h"
#include "cosmos/base/query/v1beta1/pagination.pb.h"
#include "cosmos/base/v1beta1/coin.pb.h"
#include "cosmos/query/v1/query.pb.h"
#include "cosmos_proto/cosmos.pb.h"
#include "gogoproto/gogo.pb.h"
#include "google/api/annotations.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
/* QueryBalanceRequest is the request type for the Query/Balance RPC method. */
typedef struct _cosmos_bank_v1beta1_QueryBalanceRequest {
    /* address is the address to query balances for. */
    pb_callback_t address;
    /* denom is the coin denom to query balances for. */
    pb_callback_t denom;
} cosmos_bank_v1beta1_QueryBalanceRequest;

/* QueryBalanceResponse is the response type for the Query/Balance RPC method. */
typedef struct _cosmos_bank_v1beta1_QueryBalanceResponse {
    /* balance is the balance of the coin. */
    bool has_balance;
    cosmos_base_v1beta1_Coin balance;
} cosmos_bank_v1beta1_QueryBalanceResponse;

/* QueryBalanceRequest is the request type for the Query/AllBalances RPC method. */
typedef struct _cosmos_bank_v1beta1_QueryAllBalancesRequest {
    /* address is the address to query balances for. */
    pb_callback_t address;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
    /* resolve_denom is the flag to resolve the denom into a human-readable form from the metadata.

 Since: cosmos-sdk 0.48 */
    bool resolve_denom;
} cosmos_bank_v1beta1_QueryAllBalancesRequest;

/* QueryAllBalancesResponse is the response type for the Query/AllBalances RPC
 method. */
typedef struct _cosmos_bank_v1beta1_QueryAllBalancesResponse {
    /* balances is the balances of all the coins. */
    pb_callback_t balances;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QueryAllBalancesResponse;

/* QuerySpendableBalancesRequest defines the gRPC request structure for querying
 an account's spendable balances.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_bank_v1beta1_QuerySpendableBalancesRequest {
    /* address is the address to query spendable balances for. */
    pb_callback_t address;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_bank_v1beta1_QuerySpendableBalancesRequest;

/* QuerySpendableBalancesResponse defines the gRPC response structure for querying
 an account's spendable balances.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_bank_v1beta1_QuerySpendableBalancesResponse {
    /* balances is the spendable balances of all the coins. */
    pb_callback_t balances;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QuerySpendableBalancesResponse;

/* QuerySpendableBalanceByDenomRequest defines the gRPC request structure for
 querying an account's spendable balance for a specific denom.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest {
    /* address is the address to query balances for. */
    pb_callback_t address;
    /* denom is the coin denom to query balances for. */
    pb_callback_t denom;
} cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest;

/* QuerySpendableBalanceByDenomResponse defines the gRPC response structure for
 querying an account's spendable balance for a specific denom.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse {
    /* balance is the balance of the coin. */
    bool has_balance;
    cosmos_base_v1beta1_Coin balance;
} cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse;

/* QueryTotalSupplyRequest is the request type for the Query/TotalSupply RPC
 method. */
typedef struct _cosmos_bank_v1beta1_QueryTotalSupplyRequest {
    /* pagination defines an optional pagination for the request.

 Since: cosmos-sdk 0.43 */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_bank_v1beta1_QueryTotalSupplyRequest;

/* QueryTotalSupplyResponse is the response type for the Query/TotalSupply RPC
 method */
typedef struct _cosmos_bank_v1beta1_QueryTotalSupplyResponse {
    /* supply is the supply of the coins */
    pb_callback_t supply;
    /* pagination defines the pagination in the response.

 Since: cosmos-sdk 0.43 */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QueryTotalSupplyResponse;

/* QuerySupplyOfRequest is the request type for the Query/SupplyOf RPC method. */
typedef struct _cosmos_bank_v1beta1_QuerySupplyOfRequest {
    /* denom is the coin denom to query balances for. */
    pb_callback_t denom;
} cosmos_bank_v1beta1_QuerySupplyOfRequest;

/* QuerySupplyOfResponse is the response type for the Query/SupplyOf RPC method. */
typedef struct _cosmos_bank_v1beta1_QuerySupplyOfResponse {
    /* amount is the supply of the coin. */
    bool has_amount;
    cosmos_base_v1beta1_Coin amount;
} cosmos_bank_v1beta1_QuerySupplyOfResponse;

/* QueryParamsRequest defines the request type for querying x/bank parameters. */
typedef struct _cosmos_bank_v1beta1_QueryParamsRequest {
    char dummy_field;
} cosmos_bank_v1beta1_QueryParamsRequest;

/* QueryParamsResponse defines the response type for querying x/bank parameters. */
typedef struct _cosmos_bank_v1beta1_QueryParamsResponse {
    bool has_params;
    cosmos_bank_v1beta1_Params params;
} cosmos_bank_v1beta1_QueryParamsResponse;

/* QueryDenomsMetadataRequest is the request type for the Query/DenomsMetadata RPC method. */
typedef struct _cosmos_bank_v1beta1_QueryDenomsMetadataRequest {
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_bank_v1beta1_QueryDenomsMetadataRequest;

/* QueryDenomsMetadataResponse is the response type for the Query/DenomsMetadata RPC
 method. */
typedef struct _cosmos_bank_v1beta1_QueryDenomsMetadataResponse {
    /* metadata provides the client information for all the registered tokens. */
    pb_callback_t metadatas;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QueryDenomsMetadataResponse;

/* QueryDenomMetadataRequest is the request type for the Query/DenomMetadata RPC method. */
typedef struct _cosmos_bank_v1beta1_QueryDenomMetadataRequest {
    /* denom is the coin denom to query the metadata for. */
    pb_callback_t denom;
} cosmos_bank_v1beta1_QueryDenomMetadataRequest;

/* QueryDenomMetadataResponse is the response type for the Query/DenomMetadata RPC
 method. */
typedef struct _cosmos_bank_v1beta1_QueryDenomMetadataResponse {
    /* metadata describes and provides all the client information for the requested token. */
    bool has_metadata;
    cosmos_bank_v1beta1_Metadata metadata;
} cosmos_bank_v1beta1_QueryDenomMetadataResponse;

/* QueryDenomOwnersRequest defines the request type for the DenomOwners RPC query,
 which queries for a paginated set of all account holders of a particular
 denomination. */
typedef struct _cosmos_bank_v1beta1_QueryDenomOwnersRequest {
    /* denom defines the coin denomination to query all account holders for. */
    pb_callback_t denom;
    /* pagination defines an optional pagination for the request. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_bank_v1beta1_QueryDenomOwnersRequest;

/* DenomOwner defines structure representing an account that owns or holds a
 particular denominated token. It contains the account address and account
 balance of the denominated token.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_bank_v1beta1_DenomOwner {
    /* address defines the address that owns a particular denomination. */
    pb_callback_t address;
    /* balance is the balance of the denominated coin for an account. */
    bool has_balance;
    cosmos_base_v1beta1_Coin balance;
} cosmos_bank_v1beta1_DenomOwner;

/* QueryDenomOwnersResponse defines the RPC response of a DenomOwners RPC query.

 Since: cosmos-sdk 0.46 */
typedef struct _cosmos_bank_v1beta1_QueryDenomOwnersResponse {
    pb_callback_t denom_owners;
    /* pagination defines the pagination in the response. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QueryDenomOwnersResponse;

/* QuerySendEnabledRequest defines the RPC request for looking up SendEnabled entries.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_QuerySendEnabledRequest {
    /* denoms is the specific denoms you want look up. Leave empty to get all entries. */
    pb_callback_t denoms;
    /* pagination defines an optional pagination for the request. This field is
 only read if the denoms field is empty. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageRequest pagination;
} cosmos_bank_v1beta1_QuerySendEnabledRequest;

/* QuerySendEnabledResponse defines the RPC response of a SendEnable query.

 Since: cosmos-sdk 0.47 */
typedef struct _cosmos_bank_v1beta1_QuerySendEnabledResponse {
    pb_callback_t send_enabled;
    /* pagination defines the pagination in the response. This field is only
 populated if the denoms field in the request is empty. */
    bool has_pagination;
    cosmos_base_query_v1beta1_PageResponse pagination;
} cosmos_bank_v1beta1_QuerySendEnabledResponse;

#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define cosmos_bank_v1beta1_QueryBalanceRequest_init_default \
    {                                                        \
        {{NULL}, NULL}, { {NULL}, NULL }                     \
    }
#define cosmos_bank_v1beta1_QueryBalanceResponse_init_default \
    { false, cosmos_base_v1beta1_Coin_init_default }
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default, 0 }
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_init_default \
    {                                                                        \
        {{NULL}, NULL}, { {NULL}, NULL }                                     \
    }
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_init_default \
    { false, cosmos_base_v1beta1_Coin_init_default }
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_init_default \
    { false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_init_default \
    {                                                         \
        { {NULL}, NULL }                                      \
    }
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_init_default \
    { false, cosmos_base_v1beta1_Coin_init_default }
#define cosmos_bank_v1beta1_QueryParamsRequest_init_default \
    { 0 }
#define cosmos_bank_v1beta1_QueryParamsResponse_init_default \
    { false, cosmos_bank_v1beta1_Params_init_default }
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_init_default \
    { false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_init_default \
    {                                                              \
        { {NULL}, NULL }                                           \
    }
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_init_default \
    { false, cosmos_bank_v1beta1_Metadata_init_default }
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_bank_v1beta1_DenomOwner_init_default \
    { {{NULL}, NULL}, false, cosmos_base_v1beta1_Coin_init_default }
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_default }
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_init_default \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_default }
#define cosmos_bank_v1beta1_QueryBalanceRequest_init_zero \
    {                                                     \
        {{NULL}, NULL}, { {NULL}, NULL }                  \
    }
#define cosmos_bank_v1beta1_QueryBalanceResponse_init_zero \
    { false, cosmos_base_v1beta1_Coin_init_zero }
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero, 0 }
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_init_zero \
    {                                                                     \
        {{NULL}, NULL}, { {NULL}, NULL }                                  \
    }
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_init_zero \
    { false, cosmos_base_v1beta1_Coin_init_zero }
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_init_zero \
    { false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_init_zero \
    {                                                      \
        { {NULL}, NULL }                                   \
    }
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_init_zero \
    { false, cosmos_base_v1beta1_Coin_init_zero }
#define cosmos_bank_v1beta1_QueryParamsRequest_init_zero \
    { 0 }
#define cosmos_bank_v1beta1_QueryParamsResponse_init_zero \
    { false, cosmos_bank_v1beta1_Params_init_zero }
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_init_zero \
    { false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_init_zero \
    {                                                           \
        { {NULL}, NULL }                                        \
    }
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_init_zero \
    { false, cosmos_bank_v1beta1_Metadata_init_zero }
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_bank_v1beta1_DenomOwner_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_v1beta1_Coin_init_zero }
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageRequest_init_zero }
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_init_zero \
    { {{NULL}, NULL}, false, cosmos_base_query_v1beta1_PageResponse_init_zero }

/* Field tags (for use in manual encoding/decoding) */
#define cosmos_bank_v1beta1_QueryBalanceRequest_address_tag 1
#define cosmos_bank_v1beta1_QueryBalanceRequest_denom_tag 2
#define cosmos_bank_v1beta1_QueryBalanceResponse_balance_tag 1
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_address_tag 1
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_pagination_tag 2
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_resolve_denom_tag 3
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_balances_tag 1
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_pagination_tag 2
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_address_tag 1
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_pagination_tag 2
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_balances_tag 1
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_pagination_tag 2
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_address_tag 1
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_denom_tag 2
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_balance_tag 1
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_pagination_tag 1
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_supply_tag 1
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_pagination_tag 2
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_denom_tag 1
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_amount_tag 1
#define cosmos_bank_v1beta1_QueryParamsResponse_params_tag 1
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_pagination_tag 1
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_metadatas_tag 1
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_pagination_tag 2
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_denom_tag 1
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_metadata_tag 1
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_denom_tag 1
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_pagination_tag 2
#define cosmos_bank_v1beta1_DenomOwner_address_tag 1
#define cosmos_bank_v1beta1_DenomOwner_balance_tag 2
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_denom_owners_tag 1
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_pagination_tag 2
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_denoms_tag 1
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_pagination_tag 99
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_send_enabled_tag 1
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_pagination_tag 99

/* Struct field encoding specification for nanopb */
#define cosmos_bank_v1beta1_QueryBalanceRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)                \
    X(a, CALLBACK, SINGULAR, STRING, denom, 2)
#define cosmos_bank_v1beta1_QueryBalanceRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryBalanceRequest_DEFAULT NULL

#define cosmos_bank_v1beta1_QueryBalanceResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, balance, 1)
#define cosmos_bank_v1beta1_QueryBalanceResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryBalanceResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryBalanceResponse_balance_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_bank_v1beta1_QueryAllBalancesRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)                    \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)                  \
    X(a, STATIC, SINGULAR, BOOL, resolve_denom, 3)
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_QueryAllBalancesResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, balances, 1)                   \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_balances_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)                          \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, balances, 1)                         \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_balances_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)                                \
    X(a, CALLBACK, SINGULAR, STRING, denom, 2)
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_DEFAULT NULL

#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, balance, 1)
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_balance_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, pagination, 1)
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, supply, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_supply_MSGTYPE cosmos_base_v1beta1_Coin
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_bank_v1beta1_QuerySupplyOfRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, denom, 1)
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_DEFAULT NULL

#define cosmos_bank_v1beta1_QuerySupplyOfResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, amount, 1)
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_amount_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_bank_v1beta1_QueryParamsRequest_FIELDLIST(X, a)

#define cosmos_bank_v1beta1_QueryParamsRequest_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryParamsRequest_DEFAULT NULL

#define cosmos_bank_v1beta1_QueryParamsResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, params, 1)
#define cosmos_bank_v1beta1_QueryParamsResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryParamsResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryParamsResponse_params_MSGTYPE cosmos_bank_v1beta1_Params

#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, pagination, 1)
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, metadatas, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_metadatas_MSGTYPE cosmos_bank_v1beta1_Metadata
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_FIELDLIST(X, a) X(a, CALLBACK, SINGULAR, STRING, denom, 1)
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_DEFAULT NULL

#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_FIELDLIST(X, a) X(a, STATIC, OPTIONAL, MESSAGE, metadata, 1)
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_CALLBACK NULL
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_metadata_MSGTYPE cosmos_bank_v1beta1_Metadata

#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, denom, 1)                      \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_DenomOwner_FIELDLIST(X, a) \
    X(a, CALLBACK, SINGULAR, STRING, address, 1)       \
    X(a, STATIC, OPTIONAL, MESSAGE, balance, 2)
#define cosmos_bank_v1beta1_DenomOwner_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_DenomOwner_DEFAULT NULL
#define cosmos_bank_v1beta1_DenomOwner_balance_MSGTYPE cosmos_base_v1beta1_Coin

#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, denom_owners, 1)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 2)
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_denom_owners_MSGTYPE cosmos_bank_v1beta1_DenomOwner
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

#define cosmos_bank_v1beta1_QuerySendEnabledRequest_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, STRING, denoms, 1)                     \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 99)
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_pagination_MSGTYPE cosmos_base_query_v1beta1_PageRequest

#define cosmos_bank_v1beta1_QuerySendEnabledResponse_FIELDLIST(X, a) \
    X(a, CALLBACK, REPEATED, MESSAGE, send_enabled, 1)               \
    X(a, STATIC, OPTIONAL, MESSAGE, pagination, 99)
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_CALLBACK pb_default_field_callback
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_DEFAULT NULL
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_send_enabled_MSGTYPE cosmos_bank_v1beta1_SendEnabled
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_pagination_MSGTYPE cosmos_base_query_v1beta1_PageResponse

extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryBalanceRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryBalanceResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryAllBalancesRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryAllBalancesResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySpendableBalancesRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySpendableBalancesResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryTotalSupplyRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryTotalSupplyResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySupplyOfRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySupplyOfResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryParamsRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryParamsResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomsMetadataRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomsMetadataResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomMetadataRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomMetadataResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomOwnersRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_DenomOwner_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QueryDenomOwnersResponse_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySendEnabledRequest_msg;
extern const pb_msgdesc_t cosmos_bank_v1beta1_QuerySendEnabledResponse_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define cosmos_bank_v1beta1_QueryBalanceRequest_fields &cosmos_bank_v1beta1_QueryBalanceRequest_msg
#define cosmos_bank_v1beta1_QueryBalanceResponse_fields &cosmos_bank_v1beta1_QueryBalanceResponse_msg
#define cosmos_bank_v1beta1_QueryAllBalancesRequest_fields &cosmos_bank_v1beta1_QueryAllBalancesRequest_msg
#define cosmos_bank_v1beta1_QueryAllBalancesResponse_fields &cosmos_bank_v1beta1_QueryAllBalancesResponse_msg
#define cosmos_bank_v1beta1_QuerySpendableBalancesRequest_fields &cosmos_bank_v1beta1_QuerySpendableBalancesRequest_msg
#define cosmos_bank_v1beta1_QuerySpendableBalancesResponse_fields &cosmos_bank_v1beta1_QuerySpendableBalancesResponse_msg
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_fields \
    &cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_msg
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_fields \
    &cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_msg
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_fields &cosmos_bank_v1beta1_QueryTotalSupplyRequest_msg
#define cosmos_bank_v1beta1_QueryTotalSupplyResponse_fields &cosmos_bank_v1beta1_QueryTotalSupplyResponse_msg
#define cosmos_bank_v1beta1_QuerySupplyOfRequest_fields &cosmos_bank_v1beta1_QuerySupplyOfRequest_msg
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_fields &cosmos_bank_v1beta1_QuerySupplyOfResponse_msg
#define cosmos_bank_v1beta1_QueryParamsRequest_fields &cosmos_bank_v1beta1_QueryParamsRequest_msg
#define cosmos_bank_v1beta1_QueryParamsResponse_fields &cosmos_bank_v1beta1_QueryParamsResponse_msg
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_fields &cosmos_bank_v1beta1_QueryDenomsMetadataRequest_msg
#define cosmos_bank_v1beta1_QueryDenomsMetadataResponse_fields &cosmos_bank_v1beta1_QueryDenomsMetadataResponse_msg
#define cosmos_bank_v1beta1_QueryDenomMetadataRequest_fields &cosmos_bank_v1beta1_QueryDenomMetadataRequest_msg
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_fields &cosmos_bank_v1beta1_QueryDenomMetadataResponse_msg
#define cosmos_bank_v1beta1_QueryDenomOwnersRequest_fields &cosmos_bank_v1beta1_QueryDenomOwnersRequest_msg
#define cosmos_bank_v1beta1_DenomOwner_fields &cosmos_bank_v1beta1_DenomOwner_msg
#define cosmos_bank_v1beta1_QueryDenomOwnersResponse_fields &cosmos_bank_v1beta1_QueryDenomOwnersResponse_msg
#define cosmos_bank_v1beta1_QuerySendEnabledRequest_fields &cosmos_bank_v1beta1_QuerySendEnabledRequest_msg
#define cosmos_bank_v1beta1_QuerySendEnabledResponse_fields &cosmos_bank_v1beta1_QuerySendEnabledResponse_msg

/* Maximum encoded size of messages (where known) */
/* cosmos_bank_v1beta1_QueryBalanceRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryAllBalancesRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryAllBalancesResponse_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySpendableBalancesRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySpendableBalancesResponse_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySpendableBalanceByDenomRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryTotalSupplyResponse_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySupplyOfRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryDenomsMetadataResponse_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryDenomMetadataRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryDenomOwnersRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_DenomOwner_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QueryDenomOwnersResponse_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySendEnabledRequest_size depends on runtime parameters */
/* cosmos_bank_v1beta1_QuerySendEnabledResponse_size depends on runtime parameters */
#if defined(cosmos_base_v1beta1_Coin_size)
#define COSMOS_BANK_V1BETA1_COSMOS_BANK_V1BETA1_QUERY_PB_H_MAX_SIZE cosmos_bank_v1beta1_QueryBalanceResponse_size
#define cosmos_bank_v1beta1_QueryBalanceResponse_size (6 + cosmos_base_v1beta1_Coin_size)
#define cosmos_bank_v1beta1_QuerySpendableBalanceByDenomResponse_size (6 + cosmos_base_v1beta1_Coin_size)
#define cosmos_bank_v1beta1_QuerySupplyOfResponse_size (6 + cosmos_base_v1beta1_Coin_size)
#endif
#if defined(cosmos_base_query_v1beta1_PageRequest_size)
#define cosmos_bank_v1beta1_QueryDenomsMetadataRequest_size (6 + cosmos_base_query_v1beta1_PageRequest_size)
#define cosmos_bank_v1beta1_QueryTotalSupplyRequest_size (6 + cosmos_base_query_v1beta1_PageRequest_size)
#endif
#define cosmos_bank_v1beta1_QueryParamsRequest_size 0
#if defined(cosmos_bank_v1beta1_Params_size)
#define cosmos_bank_v1beta1_QueryParamsResponse_size (6 + cosmos_bank_v1beta1_Params_size)
#endif
#if defined(cosmos_bank_v1beta1_Metadata_size)
#define cosmos_bank_v1beta1_QueryDenomMetadataResponse_size (6 + cosmos_bank_v1beta1_Metadata_size)
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
