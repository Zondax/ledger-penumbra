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

use crate::constants::SPEND_PERSONALIZED;
use crate::keys::FullViewingKey;
use crate::parser::{
    balance::Balance,
    bytes::BytesC,
    commitment::Commitment,
    effect_hash::{create_personalized_state, EffectHash},
    note::{Note, NoteC},
    nullifier::Nullifier,
    value::{Imbalance, Sign, Value},
};
use crate::protobuf_h::decaf377_rdsa_pb::penumbra_crypto_decaf377_rdsa_v1_SpendVerificationKey_inner_tag;
use crate::protobuf_h::shielded_pool_pb::{
    penumbra_core_component_shielded_pool_v1_SpendBody_balance_commitment_tag,
    penumbra_core_component_shielded_pool_v1_SpendBody_nullifier_tag,
    penumbra_core_component_shielded_pool_v1_SpendBody_rk_tag, PB_LTYPE_UVARINT,
};
use crate::utils::protobuf::{encode_and_update_proto_field, encode_varint};
use crate::ParserError;
use decaf377::Fr;
use decaf377_rdsa::{SpendAuth, VerificationKey};

pub struct Body {
    pub balance_commitment: Commitment,
    pub nullifier: Nullifier,
    pub rk: VerificationKey<SpendAuth>,
}

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct SpendPlanC {
    pub note: NoteC,
    pub position: u64,
    pub randomizer: BytesC,
    pub value_blinding: BytesC,
}

impl SpendPlanC {
    pub const RK_LEN: usize = 32;
    pub const RK_PROTO_LEN: usize = Self::RK_LEN + 2;

    pub fn rk_to_proto(&self, rk_bytes: &[u8]) -> [u8; Self::RK_PROTO_LEN] {
        let mut proto = [0u8; Self::RK_PROTO_LEN];

        let tag_and_type =
            penumbra_crypto_decaf377_rdsa_v1_SpendVerificationKey_inner_tag << 3 | PB_LTYPE_UVARINT;
        let mut len = encode_varint(tag_and_type as u64, &mut proto);
        len += encode_varint(Self::RK_LEN as u64, &mut proto[len..]);

        proto[len..].copy_from_slice(&rk_bytes);
        proto
    }

    pub fn effect_hash(&self, fvk: &FullViewingKey) -> Result<EffectHash, ParserError> {
        let body = self.spend_body(fvk)?;

        let mut state = create_personalized_state(
            std::str::from_utf8(SPEND_PERSONALIZED)
                .expect("SPEND_PERSONALIZED must be valid UTF-8"),
        );

        // Encode balance commitment
        encode_and_update_proto_field(
            &mut state,
            penumbra_core_component_shielded_pool_v1_SpendBody_balance_commitment_tag as u64,
            PB_LTYPE_UVARINT as u64,
            &body.balance_commitment.to_proto(),
        )?;

        // Encode rk
        encode_and_update_proto_field(
            &mut state,
            penumbra_core_component_shielded_pool_v1_SpendBody_rk_tag as u64,
            PB_LTYPE_UVARINT as u64,
            &self.rk_to_proto(&body.rk.to_bytes()),
        )?;

        // Encode nullifier
        encode_and_update_proto_field(
            &mut state,
            penumbra_core_component_shielded_pool_v1_SpendBody_nullifier_tag as u64,
            PB_LTYPE_UVARINT as u64,
            &body.nullifier.to_proto(),
        )?;

        Ok(EffectHash(*state.finalize().as_array()))
    }

    pub fn spend_body(&self, fvk: &FullViewingKey) -> Result<Body, ParserError> {
        Ok(Body {
            balance_commitment: self.balance()?.commit(self.get_value_blinding_fr()?)?,
            nullifier: self.nullifier(fvk)?,
            rk: self.rk(fvk)?,
        })
    }

    pub fn balance(&self) -> Result<Balance, ParserError> {
        let mut balance = Balance::new();
        balance.insert(Imbalance {
            value: Value::try_from(self.note.value.clone())?,
            sign: Sign::Provided,
        })?;
        Ok(balance)
    }

    pub fn nullifier(&self, fvk: &FullViewingKey) -> Result<Nullifier, ParserError> {
        let nk = fvk.nullifier_key();
        let note = Note::try_from(self.note.clone())?;
        let nullifier = Nullifier::derive(nk, self.position, &note.commit()?.0);
        Ok(nullifier)
    }

    pub fn rk(&self, fvk: &FullViewingKey) -> Result<VerificationKey<SpendAuth>, ParserError> {
        Ok(fvk
            .spend_verification_key()
            .randomize(&self.get_randomizer_fr()?))
    }

    pub fn get_randomizer(&self) -> Result<&[u8], ParserError> {
        self.randomizer.get_bytes()
    }

    pub fn get_randomizer_fr(&self) -> Result<Fr, ParserError> {
        let randomizer_bytes = self.get_randomizer()?;
        Ok(Fr::from_le_bytes_mod_order(randomizer_bytes))
    }

    pub fn get_value_blinding(&self) -> Result<&[u8], ParserError> {
        self.value_blinding.get_bytes()
    }

    pub fn get_value_blinding_fr(&self) -> Result<Fr, ParserError> {
        let value_blinding_bytes = self.get_value_blinding()?;
        Ok(Fr::from_le_bytes_mod_order(value_blinding_bytes))
    }
}
