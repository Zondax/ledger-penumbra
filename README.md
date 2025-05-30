# Ledger Penumbra app
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![npm version](https://badge.fury.io/js/%40zondax%2Fledger-penumbra.svg)](https://www.npmjs.com/package/@zondax/ledger-penumbra)
[![GithubActions](https://github.com/Zondax/ledger-penumbra/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-penumbra/blob/main/.github/workflows/main.yml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Penumbra app for Ledger Nano S+, Nano X, Flex, and Stax.

- Ledger Nano S+/X, Flex, and Stax Penumbra BOLOS app
- Specs / Documentation
- Rust unit/integration tests
- Zemu tests

## ATTENTION

The app releases of this repository and the binaries you can build yourself with this repo
are considered unvetted development releases, use with caution.

The releases provided by Ledger via Ledger Live have undergone Ledger's security assessment
and thus are safe to use with real funds.

If you wish to use a development release, we recommend the following:
- Do not use in production
- Do not use a Ledger device with funds for development purposes
- Do use a separate and marked device that is used ONLY for development and testing

Nevertheless, this disclaimer does not apply to the client libraries provided in this repository.

## Download and install

*Once the app is approved by Ledger, it will be available in their app store (Ledger Live).
You can get development builds generated by our CI from the release tab. THESE ARE UNVETTED DEVELOPMENT RELEASES*

Download a release from [the releases page](https://github.com/zondax/ledger-penumbra/releases). 
For the Ledger Nano S+ device, you only need to download the installer_s2.sh script.

If the file is not executable, run
```sh
chmod +x ./installer_s2.sh
```

then run:

```sh
./installer_s2.sh load
```

# Development

## Dependencies

- Required libraries
  - If you are using Ubuntu: 
    ```sh
    sudo apt update && apt-get -y install build-essential git wget cmake \
    libssl-dev libgmp-dev autoconf libtool
    ```
   
- Docker CE for building
  - Instructions can be found here: https://docs.docker.com/install/

- `node > v14.0` for integration tests
  - We typically recommend using `n` or `nvm`

- A valid `rust` toolchain for unit tests
  - Automatic CI tests against 1.63

- Python 3 to sideload on your device

- Be sure you get the SDK and other dependencies:
  - If you have `just` installed you can use it (recommended):
    ```sh
    just init 
    ```
  - If not, you can use `make`:
    ```sh
    make init
    ```

## How to build ?

> We like clion or vscode but let's have some reproducible command line steps
>

- Building the app itself

  If you installed what is described above, just run:
    ```sh
    make
    ```

## Running tests

- Running rust tests (x64)

    If you just wish to run the rust unit and integration tests, just run:
    ```sh
    make rust_test
    ```
    ** Requires a rust toolchain available **

- Running device emulation+integration tests!!

   ```sh
    Use Zemu! Explained below!
    ```

- Running everything

  If you don't want to bother typing all those make commands by hand, you can skip them all!

  The only command you have to type is:
  ```sh
  make test_all
  ```

  This will initially run unit and integration tests (needs `rust` installed!), then install Zemu for you,
  clean the app's build files in case there's anything, proceed to build both application types
  and finally run the Zemu test suite.

## How to test with Zemu?

> What is Zemu?? Great you asked!!
> As part of this project, we are making public a beta version of our internal testing+emulation framework for Ledger apps.
>
> Npm Package here: https://www.npmjs.com/package/@zondax/zemu
>
> Repo here: https://github.com/Zondax/zemu

Let's go! First install everything:
> At this moment, if you change the app you will need to run `make` before running the test again.

```bash
make zemu_install
```

Then you can run JS tests:

```bash
make zemu_test
```

To run a single specific test:

> At the moment, the recommendation is to run from the IDE. Remember to run `make` if you change the app.

## How to debug a ledger app?

You can use vscode or clion to debug the app. We recommend using CLion but we provide a vscode (unsupported) configuration too.

### Preconditions

If you are using CLion, you need to a configuration file in your home directory: `$HOME/.gdbinit` with the following content:

```
set auto-load local-gdbinit on
add-auto-load-safe-path /
```

### Warnings

There are a few things to take into account when enabling Ledger App debugging:

- Once you enable the local .gdbinit that is located in your project workspace. You **will break** local Rust debugging in your host. The reason is that debugging unit tests will use the same `.gdbinit` configuration that sets the environment to ARM. We are looking at some possible fixes. For now, if you want to debug unit tests instead of the ledger app, you need to comment out the lines in `.gdbinit`

## Using a real device

### How to prepare your DEVELOPMENT! device:

>  You can use an emulated device for development. This is only required if you are using a physical device
>
>    **Please do not use a Ledger device with funds for development purposes.**
>
>    **Have a separate and marked device that is used ONLY for development and testing**

   There are a few additional steps that increase reproducibility and simplify development:

**1 - Ensure your device works in your OS**
- In Linux hosts it might be necessary to adjust udev rules, etc.

  Refer to Ledger documentation: https://support.ledger.com/hc/en-us/articles/115005165269-Fix-connection-issues

**2 - Set a test mnemonic**

Many of our integration tests expect the device to be configured with a known test mnemonic.

- Plug your device while pressing the right button

- Your device will show "Recovery" in the screen

- Double click

- Run `make dev_init`. This will take about 2 minutes. The device will be initialized to:

   ```
   PIN: 5555
   Mnemonic: equip will roof matter pink blind book anxiety banner elbow sun young
   ```

### 3. Add a development certificate

- Plug your device while pressing the right button

- Your device will show "Recovery" in the screen

- Click both buttons at the same time

- Enter your pin if necessary

- Run `make dev_ca`. The device will receive a development certificate to avoid constant manual confirmations.

## Building the Ledger App

### Loading into your development device

The Makefile will build the firmware in a docker container and leave the binary in the correct directory. This example is for NanoS+

- Build

   ```sh
   make buildS2               # Builds the app
   ```

- Upload to a device

   The following command will upload the application to the ledger:

   _Warning: The application will be deleted before uploading._
   ```sh
   make loadS2        # Loads the built app to the device
   ```

## Generating Protobuf Files

This project uses protocol buffers (protos) from the [Penumbra repository](https://buf.build/penumbra-zone/penumbra). To fetch and generate the required files, use:

```sh
make proto
```

This command will:
- Download the latest Penumbra protos using [buf](https://buf.build/).
- Generate source code from the protos.
- Generate Rust bindings and header files.

### Dependencies

Before running `make proto`, ensure you have the following installed:
- [buf](https://docs.buf.build/installation) 
- [cargo](https://www.rust-lang.org/tools/install) 

## APDU Specifications

- [APDU Protocol](./docs/APDUSPEC.md)