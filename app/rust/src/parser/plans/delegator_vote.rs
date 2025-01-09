/*******************************************************************************
*   (c) 2024 Zondax GmbH
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

use crate::parser::{
    bytes::BytesC,
    identity_key::IdentityKeyC,
    amount::AmountC,
    penalty::{PenaltyC, Penalty},
    effect_hash::{create_personalized_state, EffectHash},
    commitment::Commitment,
    value::Balance,
    id::Id,
    id::AssetId,
    note::NoteC,
};
use decaf377::{Fr, Fq};
use crate::ParserError;
use crate::ffi::bech32::bech32_encode;
use itoa::Buffer;
use crate::utils::protobuf::encode_varint;

pub struct Body {
    /// The identity key of the validator to undelegate from.
    pub validator_identity: [u8; 32],
    /// The penalty applied to undelegation, in bps^2.
    pub penalty: [u8; 32],
    /// The action's contribution to the transaction's value balance.
    pub balance_commitment: Commitment,
    /// The height at which unbonding started.
    pub unbonding_start_height: u64,
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct DelegatorVotePlanC {
    pub proposal: u64,
    pub start_position: u64,
    pub has_vote: bool,
    pub vote: u16,
    pub has_staked_note: bool,
    pub staked_note: NoteC,
    pub staked_note_position: u64,
    pub has_unbonded_amount: bool,
    pub unbonded_amount: AmountC,
    pub randomizer: BytesC,
    pub proof_blinding_r: BytesC,
    pub proof_blinding_s: BytesC,
}

impl DelegatorVotePlanC {
    pub fn effect_hash(&self) -> Result<EffectHash, ParserError> {
        let body = self.delegator_vote_body()?;

        let mut state = create_personalized_state("/penumbra.core.component.stake.v1.UndelegateClaimBody");

        state.update(&[0x0a, 0x22, 0x0a, 0x20]); // encode header 0a220a20 validator_identity
        state.update(&body.validator_identity);

        state.update(&[0x1a, 0x22, 0x0a, 0x20]); // encode header 1a220a20 penalty
        state.update(&body.penalty);

        state.update(&body.balance_commitment.to_proto_unbonding_claim());

        let mut encoded = [0u8; 10];
        encoded[0] = 0x28;
        let pos = 1;
        let len = encode_varint(body.unbonding_start_height, &mut encoded[pos..]);
        state.update(&encoded[..len + 1]);

        let hash = state.finalize();
        Ok(EffectHash(*hash.as_array()))
    }

    pub fn delegator_vote_body(&self) -> Result<Body, ParserError> {


        Err(ParserError::InvalidLength)
    }

    pub fn get_balance_blinding(&self) -> Result<&[u8], ParserError> {
        self.balance_blinding.get_bytes()
    }

    pub fn get_balance_blinding_fr(&self) -> Result<Fr, ParserError> {
        let balance_blinding_bytes = self.get_balance_blinding()?;
        Ok(Fr::from_le_bytes_mod_order(balance_blinding_bytes))
    }

}
