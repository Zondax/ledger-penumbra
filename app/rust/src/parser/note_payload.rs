
use crate::parser::commitment::StateCommitment;
use crate::parser::note::NoteCiphertext;
use crate::keys::ka;
use crate::parser::note::NOTE_CIPHERTEXT_BYTES;

#[derive(Clone, Debug)]
pub struct NotePayload {
    pub note_commitment: StateCommitment,
    pub ephemeral_key: ka::Public,
    pub encrypted_note: NoteCiphertext,
}

impl NotePayload {
    pub const LEN: usize = 32 + 32 + NOTE_CIPHERTEXT_BYTES; 
    pub const PROTO_LEN: usize = Self::LEN + 15;

    pub fn to_proto(&self) -> [u8; Self::PROTO_LEN] {
        let mut proto = [0u8; Self::PROTO_LEN];
        proto[0..7].copy_from_slice(&[0x0a, 0xfc, 0x01, 0x0a, 0x22, 0x0a, 0x20]);
        proto[7..39].copy_from_slice(&self.note_commitment.0.to_bytes());
        proto[39..41].copy_from_slice(&[0x12, 0x20]); 
        proto[41..73].copy_from_slice(&self.ephemeral_key.0);
        proto[73..79].copy_from_slice(&[0x1a, 0xb3, 0x01, 0x0a, 0xb0, 0x01]); 
        proto[79..].copy_from_slice(&self.encrypted_note.0);

        proto
    }
}
