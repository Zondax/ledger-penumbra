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

// #{TODO} --> Apply tests that check this app's encoding/libraries

#include "parser_impl.h"

#include <hexutils.h>

#include <iostream>
#include <vector>

#include "gmock/gmock.h"
#include "parser.h"
#include "parser_txdef.h"

using namespace std;

TEST(SCALE, ReadBytes) {
    parser_context_t ctx;
    parser_tx_t tx_obj;
    parser_error_t err;
    uint8_t buffer[6000];
    auto bufferLen = parseHexString(
        buffer, sizeof(buffer),
        "0abe020abb020aa8010a300a0a08f6fec6bbb0eda1e10a12220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012202263a493b8201d37bc24d2bb459212cd9e3d88c6afb707d43283a0e80d3839591a520a50890bc98e3698aa4578e419b028da5672e627c280d8b06166f4c42d5366bccf1fcf3b296cd61e8d744a21f75f2fb697183e18595d8a79008539d8fb138b405db09db65cc42d54c0e772e5d42d5f20b52f10ca9bb6be92d60a1a204950faad59ed83dbbbf19633dabcb3c82259961ebf297bf194948af065c820042220d69fe89087a1ae87386ac5ecf89f1170ade0317b2de9958e6566fe5cc47a5f002a2060d3f34832aaaf0f6de5f974171c261597ba66b0903a85fb823436498e2dba0a32201282a0d9c64554db3f2518da1598fd9c92bb33677e8855f730dc13b75b633a0d0abd020aba020aa8010a300a0a08ecd69fe7c6e9e2ab0b12220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a101220e6d9e25c36380ffb8263f57bc5c93893f75a26167a03e2ac029f62e0fed2fb021a520a50890bc98e3698aa4578e419b028da5672e627c280d8b06166f4c42d5366bccf1fcf3b296cd61e8d744a21f75f2fb697183e18595d8a79008539d8fb138b405db09db65cc42d54c0e772e5d42d5f20b52f10fbaaaebabc741a208966acb303c3dbdb7f480d39d207d72495563e00a083ad8cce351faaaf2aeb022220bbe68d3e70458b4b5ffd860c374fb40930b07a639d4c7c7077928d9ac0e868012a208f01c1ebcd5582b05da53bd8ea147a6257b0160966c4b9237f144694adc72702322017be7f31a2da7e50001f277754757d9f5ab9ed3c0a27dc2218dee79d4d6815120abe020abb020aa8010a300a0a08fcd0d382feba9cff0212220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a101220aff1713cd7fa8c9eac9db187dd4ee116e3af522e914b91317e8ae962f79902f31a520a50890bc98e3698aa4578e419b028da5672e627c280d8b06166f4c42d5366bccf1fcf3b296cd61e8d744a21f75f2fb697183e18595d8a79008539d8fb138b405db09db65cc42d54c0e772e5d42d5f20b52f10fcfe94f3b0fe171a2019f0b16d495c974d1d7ad0e80257d69997f8c6e45a1e63b5c419c61da3a48b042220975392c6113a406257578b0cc5c5086e8100b1b7328f1445a924a83b0f1876012a20c99bc5e70a76b5fd612f01e031f9b5df38d523e0c148eb52c72b037882ae010b32202e8ce2aa8c19a80895bd55f64eaf6eae6b1fb783096f4c42b6b844bfcdaaf7051229089e8eed98081213776b636b616e2d3432373935373034323035371a0c0a0a08e383f09ac580a0a906");

    parser_parse(&ctx, buffer, bufferLen, &tx_obj);
}
