#*******************************************************************************
#  Ledger App
#  (c) 2018 - 2024 Zondax AG
#  (c) 2017 Ledger
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#*******************************************************************************

ifeq ($(BOLOS_SDK),)
$(error BOLOS_SDK is not set)
endif

########################################
#        Mandatory configuration       #
########################################
# Upload targets to configure the devices 
include $(BOLOS_SDK)/Makefile.defines

# Application name
APPNAME = "Penumbra"

# Application version
include $(CURDIR)/Makefile.version
APPVERSION = "$(APPVERSION_M).$(APPVERSION_N).$(APPVERSION_P)"

# Application source files
APP_SOURCE_PATH += src

# Application icons following guidelines:
# https://developers.ledger.com/docs/embedded-app/design-requirements/#device-icon
ICON_NANOX = nanox_icon.gif
ICON_NANOSP = nanox_icon.gif
ICON_STAX = stax_icon.gif
ICON_FLEX = flex_icon.gif

# Application allowed derivation curves.
# Possibles curves are: secp256k1, secp256r1, ed25519 and bls12381g1
# If your app needs it, you can specify multiple curves by using:
# `CURVE_APP_LOAD_PARAMS = <curve1> <curve2>`
CURVE_APP_LOAD_PARAMS = secp256k1

# Application allowed derivation paths.
# You should request a specific path for your app.
# This serve as an isolation mechanism.
# Most application will have to request a path according to the BIP-0044
# and SLIP-0044 standards.
# If your app needs it, you can specify multiple path by using:
# `PATH_APP_LOAD_PARAMS = "44'/1'" "45'/1'"`

APPPATH = "44'/6532'"
$(info PATHS LIST = $(APPPATH))
PATH_APP_LOAD_PARAMS = $(APPPATH)

# Setting to allow building variant applications
# - <VARIANT_PARAM> is the name of the parameter which should be set
#   to specify the variant that should be build.
# - <VARIANT_VALUES> a list of variant that can be build using this app code.
#   * It must at least contains one value.
#   * Values can be the app ticker or anything else but should be unique.
ifeq ($(COIN),)
    COIN = UM
endif
$(info COIN  = [$(COIN)])
VARIANT_PARAM=COIN
VARIANT_VALUES=$(COIN)

INCLUDES_PATH += $(CURDIR)/src/protobuf
INCLUDES_PATH += $(CURDIR)/src/common

# Flag to compile all Penumbra actions
FULL_APP ?= 0
ifeq ($(FULL_APP),1)
DEFINES += FULL_APP
$(info ************ FULL APP ENABLED ************)
endif

########################################
# Application communication interfaces #
########################################
ENABLE_BLUETOOTH = 1
#ENABLE_NFC = 1

########################################
#         NBGL custom features         #
########################################
ENABLE_NBGL_QRCODE = 1
#ENABLE_NBGL_KEYBOARD = 1
#ENABLE_NBGL_KEYPAD = 1

########################################
#          Features disablers          #
########################################
# These advanced settings allow to disable some feature that are by
# default enabled in the SDK `Makefile.standard_app`.
#DISABLE_STANDARD_APP_FILES = 1
#DISABLE_DEFAULT_IO_SEPROXY_BUFFER_SIZE = 1 # To allow custom size declaration
#DISABLE_STANDARD_APP_DEFINES = 1 # Will set all the following disablers
#DISABLE_STANDARD_SNPRINTF = 1
#DISABLE_STANDARD_USB = 1
#DISABLE_STANDARD_WEBUSB = 1
#DISABLE_DEBUG_LEDGER_ASSERT = 1
#DISABLE_DEBUG_THROW = 1

########################################
#        Other configurations          #
########################################
# Set the default value for PRODUCTION_BUILD to 0 if not already defined
PRODUCTION_BUILD ?= 1
# Display whether this is a production build or for internal use
ifeq ($(PRODUCTION_BUILD), 1)
    $(info ************ PRODUCTION_BUILD  = [PRODUCTION BUILD])
else
    $(info ************ PRODUCTION_BUILD  = [INTERNAL USE])
endif
 # Add the PRODUCTION_BUILD definition to the compiler flags
DEFINES += PRODUCTION_BUILD=$(PRODUCTION_BUILD)

# Display whether swap functionality is enabled or not
ifeq ($(ENABLE_SWAP), 1)
    $(info ************ HAVE_SWAP  = [ENABLED])
else
    $(info ************ HAVE_SWAP  = [DISABLED])
endif

########################################

# Configure devices and permissions
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.devices
# Create installer script
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.installer_script
# Enable logging
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.app_testing
# Call standard app flags
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.platform
# Include Rust-specific build rules
include $(CURDIR)/Makefile.rust

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])
ifeq ($(ICONNAME),)
$(error ICONNAME is not set)
endif

.PHONY: version
version:
	@echo "v$(APPVERSION)" > app.version