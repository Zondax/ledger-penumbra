#*******************************************************************************
#*   (c) 2018 - 2024 Zondax AG
#*
#*  Licensed under the Apache License, Version 2.0 (the "License");
#*  you may not use this file except in compliance with the License.
#*  You may obtain a copy of the License at
#*
#*      http://www.apache.org/licenses/LICENSE-2.0
#*
#*  Unless required by applicable law or agreed to in writing, software
#*  distributed under the License is distributed on an "AS IS" BASIS,
#*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#*  See the License for the specific language governing permissions and
#*  limitations under the License.
#********************************************************************************
cmake_minimum_required(VERSION 3.28)
set(CMAKE_VERBOSE_MAKEFILE ON)
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.26.1.tar.gz"
    SHA1 "e41ac7a18c49b35ebac99ff2b5244317b2638a65"
    LOCAL
)

if(CMAKE_GENERATOR MATCHES "Ninja")
    message(FATAL_ERROR "This project does not support the Ninja generator. "
                            "Please use Unix Makefiles or another supported generator. "
                            "This error is typical in CLion. In this case, switch to generator Unix Makefiles.")
endif()

########################################################

project(ledger-penumbra VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0025 NEW)
cmake_policy(SET CMP0144 NEW)

set(HUNTER_STATUS_DEBUG ON)
set(HUNTER_TLS_VERIFY OFF)

enable_testing()

option(ENABLE_FUZZING "Build with fuzzing instrumentation and build fuzz targets" OFF)
option(ENABLE_COVERAGE "Build with source code coverage instrumentation" OFF)
option(ENABLE_SANITIZERS "Build with ASAN and UBSAN" OFF)

string(APPEND CMAKE_C_FLAGS " -fno-omit-frame-pointer -g")
string(APPEND CMAKE_CXX_FLAGS " -fno-omit-frame-pointer -g")
string(APPEND CMAKE_LINKER_FLAGS " -fno-omit-frame-pointer -g")

hunter_add_package(fmt)
find_package(fmt CONFIG REQUIRED)

# Use FetchContent to get nlohmann_json 3.12.0 since Hunter doesn't support this version
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz
    URL_HASH SHA256=42f6e95cad6ec532fd372391373363b62a14af6d771056dbfc86160e6dfff7aa
)
FetchContent_MakeAvailable(nlohmann_json)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

if(ENABLE_FUZZING)
    add_definitions(-DFUZZING_BUILD_MODE_UNSAFE_FOR_PRODUCTION=1)
    SET(ENABLE_SANITIZERS ON CACHE BOOL "Sanitizer automatically enabled" FORCE)
    SET(CMAKE_BUILD_TYPE Debug)

    if (DEFINED ENV{FUZZ_LOGGING})
        add_definitions(-DFUZZING_LOGGING)
        message(FATAL_ERROR "Fuzz logging enabled")
    endif()

    set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,bugprone-*,cert-*,clang-analyzer-*,-cert-err58-cpp,misc-*)

    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # require at least clang 3.2
        if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.0)
            message(FATAL_ERROR "Clang version must be at least 10.0!")
        endif()
    else()
        message(FATAL_ERROR
                "Unsupported compiler! Fuzzing requires Clang 10.\n"
                "1. Install clang-10 \n"
                "2. Use -DCMAKE_C_COMPILER=clang-10 -DCMAKE_CXX_COMPILER=clang++-10")
    endif()

    string(APPEND CMAKE_C_FLAGS " -fsanitize=fuzzer-no-link")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=fuzzer-no-link")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=fuzzer-no-link")
endif()

if(ENABLE_COVERAGE)
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/fuzz/coverage")
    
    string(APPEND CMAKE_C_FLAGS " -fprofile-instr-generate=fuzz/coverage/%p.profraw -fcoverage-mapping")
    string(APPEND CMAKE_CXX_FLAGS " -fprofile-instr-generate=fuzz/coverage/%p.profraw -fcoverage-mapping")
    string(APPEND CMAKE_LINKER_FLAGS " -fprofile-instr-generate=fuzz/coverage/%p.profraw -fcoverage-mapping")
endif()

if(ENABLE_SANITIZERS)
    string(APPEND CMAKE_C_FLAGS " -fsanitize=address,undefined")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address,undefined")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=address,undefined")
    
    string(APPEND CMAKE_C_FLAGS " -fsanitize-recover=address,undefined")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize-recover=address,undefined")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize-recover=address,undefined")
    
    string(APPEND CMAKE_C_FLAGS " -fsanitize-address-use-after-scope")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize-address-use-after-scope")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize-address-use-after-scope")
    
    string(APPEND CMAKE_C_FLAGS " -fsanitize=integer -fsanitize=bounds")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=integer -fsanitize=bounds")
    string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=integer -fsanitize=bounds")

    string(APPEND CMAKE_C_FLAGS " -fstack-protector-strong")
    string(APPEND CMAKE_CXX_FLAGS " -fstack-protector-strong")
endif()

set (RETRIEVE_MAJOR_CMD
        "cat ${CMAKE_CURRENT_SOURCE_DIR}/app/Makefile.version | grep APPVERSION_M | cut -b 14- | tr -d '\n'"
)
set (RETRIEVE_MINOR_CMD
        "cat ${CMAKE_CURRENT_SOURCE_DIR}/app/Makefile.version | grep APPVERSION_N | cut -b 14- | tr -d '\n'"
)
execute_process(
        COMMAND bash "-c" ${RETRIEVE_MAJOR_CMD}
        RESULT_VARIABLE MAJOR_RESULT
        OUTPUT_VARIABLE MAJOR_VERSION
)
execute_process(
        COMMAND bash "-c" ${RETRIEVE_MINOR_CMD}
        RESULT_VARIABLE MINOR_RESULT
        OUTPUT_VARIABLE MINOR_VERSION
)

message(STATUS "LEDGER_MAJOR_VERSION [${MAJOR_RESULT}]: ${MAJOR_VERSION}" )
message(STATUS "LEDGER_MINOR_VERSION [${MINOR_RESULT}]: ${MINOR_VERSION}" )

add_definitions(
    -DLEDGER_MAJOR_VERSION=${MAJOR_VERSION}
    -DLEDGER_MINOR_VERSION=${MINOR_VERSION}
)

# Add flag to compile all Penumbra actions for cpp tests 
add_definitions(-DFULL_APP)

##############################################################
# Static Libraries
file(GLOB_RECURSE LIB_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/app_mode.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/base58.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/bech32.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/bignum.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/hexutils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zxmacros.c
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/src/zxformat.c
        ####
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_impl.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/protobuf/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/crypto_helper.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/nanopb_tiny/pb_common.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/nanopb_tiny/pb_decode.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_interface.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parser_pb_utils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/spend.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/output.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/delegate.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/undelegate.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/ics20_withdrawal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/swap.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/ui/note.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/known_assets.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/ui_utils.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/parameters.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/tx_metadata.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/memo.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/swap.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/c_api/rust.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/ics20_withdrawal.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/undelegate_claim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/delegator_vote.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/position_open.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/position_close.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/position_withdraw.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/action_dutch_auction_schedule.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/action_dutch_auction_end.c
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan/action_dutch_auction_withdraw.c
        )

add_library(app_lib STATIC ${LIB_SRC})

target_include_directories(app_lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/deps/ledger-zxlib/include
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/common
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/nanopb_tiny
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/protobuf
        ${CMAKE_CURRENT_SOURCE_DIR}/app/rust/include
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/plan
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/ui
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/c_api
        )

##############################################################
## Rust library for CPP tests
set(RUST_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/app/rust")
message(STATUS "Rust library path: ${RUST_LIB}")
message(STATUS "Rust library path2: ${RUST_LIB_DIR}")

# Determine the Rust target triple based on the host system
if(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
    if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
        set(RUST_TARGET_TRIPLE "aarch64-unknown-linux-gnu")
    elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
        set(RUST_TARGET_TRIPLE "x86_64-unknown-linux-gnu")
    else()
        message(FATAL_ERROR "Unsupported processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
    endif()
elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Darwin")
    if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "arm64")
        set(RUST_TARGET_TRIPLE "aarch64-apple-darwin")
    elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
        set(RUST_TARGET_TRIPLE "x86_64-apple-darwin")
    else()
        message(FATAL_ERROR "Unsupported processor: ${CMAKE_HOST_SYSTEM_PROCESSOR}")
    endif()
else()
    message(FATAL_ERROR "Unsupported host system: ${CMAKE_HOST_SYSTEM_NAME}")
endif()

# Use debug mode for debugging tests
set(RUST_TARGET_DIR "${RUST_LIB_DIR}/target/${RUST_TARGET_TRIPLE}/release")

# Custom target for the Rust library
add_custom_target(RustLibClean
    COMMAND cargo clean
    WORKING_DIRECTORY ${RUST_LIB_DIR}
)
add_custom_target(RustLibBuild
    COMMAND cargo build --release --target ${RUST_TARGET_TRIPLE} --features cpp_tests
    WORKING_DIRECTORY ${RUST_LIB_DIR}
    DEPENDS RustLibClean
)

# Assuming the Rust library outputs a file named librslib.a
set(RUST_LIB "${RUST_TARGET_DIR}/librslib.a")

# Ensure the Rust library is built before the C++ project
add_library(rslib STATIC IMPORTED)
set_property(TARGET rslib PROPERTY IMPORTED_LOCATION ${RUST_LIB})
add_dependencies(rslib RustLibBuild)

# Ensure your C++ targets depend on the Rust library being built first
# For example, for your app_lib static library:
add_dependencies(app_lib rslib)


##############################################################
#  Fuzz Targets
if(ENABLE_FUZZING)
    set(FUZZ_TARGETS
        parser_parse
        )

    foreach(target ${FUZZ_TARGETS})
        add_executable(fuzz-${target} ${CMAKE_CURRENT_SOURCE_DIR}/fuzz/${target}.cpp)
        target_link_libraries(fuzz-${target} PRIVATE 
        app_lib
        rslib)
        target_link_options(fuzz-${target} PRIVATE "-fsanitize=fuzzer")
    endforeach()
else()
    ##############################################################
    #  Tests
    file(GLOB_RECURSE TESTS_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

    add_executable(unittests ${TESTS_SRC})
    target_include_directories(unittests PRIVATE
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
        ${CONAN_INCLUDE_DIRS_FMT}
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src
        ${CMAKE_CURRENT_SOURCE_DIR}/app/src/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/app/rust/include
        )

    target_link_libraries(unittests PRIVATE
    app_lib
    rslib
    GTest::gtest_main
    fmt::fmt
    nlohmann_json::nlohmann_json)

    add_compile_definitions(TESTVECTORS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/tests/")
    add_test(NAME unittests COMMAND unittests)
    set_tests_properties(unittests PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif()
