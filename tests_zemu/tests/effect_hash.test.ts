/** ******************************************************************************
 *  (c) 2018 - 2023 Zondax AG
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
 ******************************************************************************* */

import Zemu from '@zondax/zemu'
import { PENUMBRA_PATH, defaultOptions, models, ACCOUNT_ID } from './common'
import { PenumbraApp, AddressIndex } from '@zondax/ledger-penumbra'
import { ACTIONS_TESTCASES } from './testscases/actions'

jest.setTimeout(60000)

describe('Standard', function () {
  test.concurrent.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  describe.each(ACTIONS_TESTCASES)('Wallet transactions', function (data) {
    test.concurrent.each(models)('sign %s', async function (m) {
      const sim = new Zemu(m.path)
      try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = new PenumbraApp(sim.getTransport())

        const messageToSign = Buffer.from(data.blob, 'hex')

        const addressIndex: AddressIndex = {
          account: ACCOUNT_ID,
          randomizer: undefined,
        }
        // do not wait here... we need to navigate
        const signatureRequest = app.sign(PENUMBRA_PATH, messageToSign, data.metadata)

        // Wait until we are not in the main menu
        await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
        await sim.waitForText('Review')
        await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_${data.name}`)

        const signatureResponse = await signatureRequest
        console.log('Effect hash:', signatureResponse.effectHash.toString('hex'))

        if (signatureResponse.spendAuthSignatures.length > 0) {
          signatureResponse.spendAuthSignatures.forEach((signature, index) => {
            console.log(`Spend Auth Signature ${index + 1}: ${signature.toString('hex')}`)
            expect(signature.toString('hex')).toEqual(data.expected_spend_sig)
          })
        } else {
          console.log('No spend auth signatures available.')
        }

        if (signatureResponse.delegatorVoteSignatures.length > 0) {
          signatureResponse.delegatorVoteSignatures.forEach((signature, index) => {
            console.log(`Delegator Vote Signature ${index + 1}: ${signature.toString('hex')}`)
          })
        } else {
          console.log('No delegator vote signatures available.')
        }

        // Now verify effect hash
        expect(signatureResponse.effectHash.toString('hex')).toEqual(data.expected_effect_hash)
      } finally {
        await sim.close()
      }
    })
  })
})
