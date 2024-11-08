use core::ptr::addr_of_mut;

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
use crate::{
    effect_hash::{create_personalized_state, EffectHash},
    ParserError,
};

use super::bytes::BytesC;

#[repr(C)]
#[derive(Clone)]
#[cfg_attr(any(feature = "derive-debug", test), derive(Debug))]
pub struct TransactionParametersC {
    pub bytes: BytesC,
}

impl TransactionParametersC {
    pub fn effect_hash(&self) -> Result<EffectHash, ParserError> {
        let mut state =
            create_personalized_state("/penumbra.core.transaction.v1.TransactionParameters");
        let bytes = unsafe { core::slice::from_raw_parts(self.bytes.ptr, self.bytes.len as usize) };
        state.update(bytes);
        let hash = state.finalize();
        Ok(EffectHash(*hash.as_array()))
    }
}
