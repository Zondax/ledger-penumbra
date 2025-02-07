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

use crate::keys::ka;
use crate::parser::commitment::StateCommitment;
use crate::parser::note::NoteCiphertext;
use crate::parser::note::NOTE_CIPHERTEXT_BYTES;
use crate::ParserError;
use crate::utils::protobuf::encode_proto_field;
use crate::protobuf_h::shielded_pool_pb::{
    penumbra_core_component_shielded_pool_v1_NotePayload_note_commitment_tag,
    penumbra_core_component_shielded_pool_v1_NotePayload_ephemeral_key_tag,
    penumbra_core_component_shielded_pool_v1_NotePayload_encrypted_note_tag, PB_LTYPE_UVARINT,
};

#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct NotePayload {
    pub note_commitment: StateCommitment,
    pub ephemeral_key: ka::Public,
    pub encrypted_note: NoteCiphertext,
}

impl NotePayload {
    pub const LEN: usize = 32 + 32 + NOTE_CIPHERTEXT_BYTES;
    pub const PROTO_LEN: usize = Self::LEN + 15;
    pub const PROTO_PREFIX_NOTE_COMMITMENT: [u8; 3] = [0x0a, 0xfc, 0x01];
    pub const PROTO_PREFIX_EPHEMERAL_KEY: [u8; 2] = [0x12, 0x20];
    pub const PROTO_PREFIX_ENCRYPTED_NOTE: [u8; 6] = [0x1a, 0xb3, 0x01, 0x0a, 0xb0, 0x01];

    pub fn to_proto(&self) -> [u8; Self::PROTO_LEN] {
        let mut proto = [0u8; Self::PROTO_LEN];
        proto[0..5].copy_from_slice(&Self::PROTO_PREFIX_NOTE_COMMITMENT);
        proto[5..39].copy_from_slice(&self.note_commitment.to_proto());
        proto[39..41].copy_from_slice(&Self::PROTO_PREFIX_EPHEMERAL_KEY);
        proto[41..73].copy_from_slice(&self.ephemeral_key.0);
        proto[73..79].copy_from_slice(&Self::PROTO_PREFIX_ENCRYPTED_NOTE);
        proto[79..].copy_from_slice(&self.encrypted_note.0);

        proto
    }

    pub fn update_proto(&self, state: &mut blake2b_simd::State) -> Result<(), ParserError> {
        let mut proto = [0u8; Self::PROTO_LEN];
        proto[0..3].copy_from_slice(&Self::PROTO_PREFIX_NOTE_COMMITMENT);
        //proto[5..39].copy_from_slice(&self.note_commitment.to_proto());

        encode_proto_field(
            penumbra_core_component_shielded_pool_v1_NotePayload_note_commitment_tag as u64,
            PB_LTYPE_UVARINT as u64,
            &self.note_commitment.to_proto(),
            &mut proto[3..5],
        )?;
        proto[5..39].copy_from_slice(&self.note_commitment.to_proto());

        encode_proto_field(
            penumbra_core_component_shielded_pool_v1_NotePayload_ephemeral_key_tag as u64,
            PB_LTYPE_UVARINT as u64,
            &self.ephemeral_key.0,
            &mut proto[39..41],
        )?;
        proto[41..73].copy_from_slice(&self.ephemeral_key.0);
        
        proto[73..79].copy_from_slice(&Self::PROTO_PREFIX_ENCRYPTED_NOTE);
        proto[79..].copy_from_slice(&self.encrypted_note.0);



        state.update(&proto);
        Ok(())
    }
}
