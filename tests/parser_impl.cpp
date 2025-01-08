/*******************************************************************************
 *   (c) 2018 - 2023 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include "parser_impl.h"

#include <hexutils.h>

#include <iostream>
#include <vector>

#include "gmock/gmock.h"
#include "parser.h"
#include "parser_interface.h"
#include "parser_txdef.h"
#include "zxformat.h"

using namespace std;

TEST(SCALE, ReadBytes) {
    parser_context_t ctx = {0};
    parser_tx_t tx_obj = {0};
    parser_error_t err;
    zxerr_t zxerr;

    uint8_t buffer[6000];
    auto bufferLen = parseHexString(
        buffer, sizeof(buffer),
        "0ac201d202be010a220a201e32c63102334a0fdfed9fdd4aa6b088824d1d42ad40109f4a56f8845dfb0e3222220a2000000000000000000000000000000000fecbfb15b573eab367a0f9096bb98c7f2a0a08a7e0eef99af69b8401322002a147e3c45b43f4f0cc9d8d6e2940c6927cbb5141b6062aae8ac3ba10ac45043a20a6f9bd68892e3c662cd41452dca6c196e31ce877f9e7303166e4eb25b496aa0a422084d5bd78cab02b9528a4135abcdcf46d4953ab230d1e6d4dc295eb4208b5bf0d48c8ca01121f08a99639120b6b78717668686361682d371a0c0a0a08cdf1f4ffaeb4a8e406");

    err = parser_parse(&ctx, buffer, bufferLen, &tx_obj);
    ASSERT_EQ(err, parser_ok) << parser_getErrorDescription(err);

    // compute parameters hash
    zxerr = compute_parameters_hash(&tx_obj.parameters_plan.data_bytes, &tx_obj.plan.parameters_hash);
    ASSERT_EQ(zxerr, zxerr_ok);

    // compute action hashes
    for (uint16_t i = 0; i < tx_obj.plan.actions.qty; i++) {
        zxerr = compute_action_hash(&tx_obj.actions_plan[i], &tx_obj.plan.memo.key, &tx_obj.plan.actions.hashes[i]);
        ASSERT_EQ(zxerr, zxerr_ok);
    }

    // compute effect hash
    zxerr = compute_effect_hash(&tx_obj.plan, tx_obj.effect_hash, sizeof(tx_obj.effect_hash));
    ASSERT_EQ(zxerr, zxerr_ok);

    std::string expected =
        "81a8634bb15c983f7c176b03889d204f6d4793f7ad7cf51e33bb21d211f97be7958c9a771ea1475164f5599b9080669eb7554dc26a6cfd20a3d73132d5b2f17a";
    char actual[129];
    array_to_hexstr(actual, sizeof(actual), tx_obj.effect_hash, sizeof(tx_obj.effect_hash));

    EXPECT_EQ(std::string(actual), expected);
}
