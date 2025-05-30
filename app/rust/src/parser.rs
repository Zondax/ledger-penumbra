/*******************************************************************************
*   (c) 2021 Zondax GmbH
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
use core::mem::MaybeUninit;

// transaction plan:
// https://rustdoc.penumbra.zone/main/penumbra_transaction/plan/struct.TransactionPlan.html
// actions:
// https://rustdoc.penumbra.zone/main/penumbra_transaction/plan/enum.ActionPlan.html
pub mod action;
mod address;
pub mod amount;
pub mod backref;
pub mod balance;
pub mod bytes;
mod clue_plan;
pub mod commitment;
pub mod detection;
pub mod effect_hash;
mod error;
pub mod fee;
pub mod fixpoint;
pub mod id;
pub mod identity_key;
pub mod memo;
pub mod memo_plain_text;
mod note;
mod note_payload;
pub mod nullifier;
mod parameters;
pub mod penalty;
mod plans;
pub mod reserves;
pub mod rk;
pub mod rseed;
pub mod swap_ciphertext;
pub mod swap_payload;
pub mod swap_plaintext;
pub mod symmetric;
pub mod trading_pair;
pub mod validator_identity;
pub mod value;

pub use bytes::BytesC;
pub use error::ParserError;
pub use plans::spend::SpendPlanC;

#[derive(Clone, Copy, PartialEq, Eq)]
#[cfg_attr(test, derive(Debug))]
pub enum ViewError {
    Unknown,
    NoData,
    Reject,
}

///This trait defines the interface useful in the UI context
/// so that all the different OperationTypes or other items can handle their own UI
pub trait DisplayableItem {
    /// Returns the number of items to display
    fn num_items(&self) -> Result<u8, ViewError>;

    /// This is invoked when a given page is to be displayed
    ///
    /// `item_n` is the item of the operation to display;
    /// guarantee: 0 <= item_n < self.num_items()
    /// `title` is the title of the item
    /// `message` is the contents of the item
    /// `page` is what page we are supposed to display, this is used to split big messages
    ///
    /// returns the total number of pages on success
    ///
    /// It's a good idea to always put `#[inline(never)]` on top of this
    /// function's implementation
    //#[inline(never)]
    fn render_item(
        &self,
        item_n: u8,
        title: &mut [u8],
        message: &mut [u8],
        page: u8,
    ) -> Result<u8, ViewError>;
}

///This trait defines an useful interface to parse
///objects from bytes.
///this gives different objects in a transaction
///a way to define their own deserilization implementation, allowing higher level objects to generalize the
///parsing of their inner types
pub trait FromBytes<'b>: Sized {
    /// this method is avaliable for testing only, as the preferable
    /// option is to save stack by passing the memory where the object should
    /// store itself
    #[cfg(test)]
    fn from_bytes(input: &'b [u8]) -> Result<(&'b [u8], Self), nom::Err<ParserError>> {
        let mut out = MaybeUninit::uninit();
        let rem = Self::from_bytes_into(input, &mut out)?;
        unsafe { Ok((rem, out.assume_init())) }
    }

    ///Main deserialization method
    ///`input` the input data that contains the serialized form in bytes of this object.
    ///`out` the memory where this object would be stored
    ///
    /// returns the remaining bytes on success
    ///
    /// `Safety` Dealing with uninitialize memory is undefine behavior
    /// even in rust, so implementors should follow the rust documentation
    /// for MaybeUninit and unsafe guidelines.
    ///
    /// It's a good idea to always put `#[inline(never)]` on top of this
    /// function's implementation
    fn from_bytes_into(
        input: &'b [u8],
        out: &mut MaybeUninit<Self>,
    ) -> Result<&'b [u8], nom::Err<ParserError>>;
}
