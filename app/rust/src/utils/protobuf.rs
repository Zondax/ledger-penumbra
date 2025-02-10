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

use crate::ParserError;

pub fn encode_varint(mut value: u64, buf: &mut [u8]) -> usize {
    let mut pos = 0;
    loop {
        let mut byte = (value & 0x7F) as u8;
        value >>= 7;
        if value != 0 {
            byte |= 0x80;
        }
        buf[pos] = byte;
        pos += 1;
        if value == 0 {
            break;
        }
    }
    pos
}

pub fn encode_proto_field(
    tag: u64,
    wire_type: u64,
    value: &[u8],
    buf: &mut [u8],
) -> Result<usize, ParserError> {
    let tag_and_type = tag << 3 | wire_type;
    let mut len = encode_varint(tag_and_type, buf);
    if len >= buf.len() {
        return Err(ParserError::InvalidLength);
    }

    let remaining_buf = &mut buf[len..];
    let value_len = value.len();
    let varint_len = encode_varint(value_len as u64, remaining_buf);
    len += varint_len;

    if len > buf.len() {
        return Err(ParserError::InvalidLength);
    }

    Ok(len)
}

pub fn encode_and_update_proto_field(
    state: &mut blake2b_simd::State,
    tag: u64,
    wire_type: u64,
    value: &[u8],
) -> Result<(), ParserError> {
    let mut proto_buf = [0u8; 20];

    let len = encode_proto_field(tag, wire_type, value, &mut proto_buf)?;

    state.update(&proto_buf[..len]);
    state.update(value);
    Ok(())
}

pub fn encode_and_update_proto_number(
    state: &mut blake2b_simd::State,
    tag: u64,
    value: u64,
) -> Result<(), ParserError> {
    let mut proto_buf = [0u8; 20];
    let len = encode_varint(value, &mut proto_buf);

    state.update(&[(tag << 3) as u8]);
    state.update(&proto_buf[..len]);
    Ok(())
}
