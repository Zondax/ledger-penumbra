pub mod asset_id;
mod bech32;
pub mod c_api;
mod keys;
pub mod sign;

#[cfg(test)]
mod check_signature {
    use penumbra_sdk_keys::keys::SpendKey;
    use penumbra_sdk_keys::keys::SpendKeyBytes;
    use penumbra_sdk_keys::FullViewingKey as PenFvk;
    use penumbra_sdk_proto::penumbra::core::transaction::v1::TransactionPlan as ProtoTxPlan;
    use penumbra_sdk_tct::Tree;
    use penumbra_sdk_transaction::TransactionPlan;
    use serde as _;

    use super::*;

    const TRANSACTION_PLAN: &str = "0abe020abb020aa8010a300a0a08cff4aebf94dbb8fa0512220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a10122040239669cfbb58184c7b5928c1436c398b5cf95aa6a55c91e7bdec9128192d101a520a50890bc98e3698aa4578e419b028da5672e627c280d8b06166f4c42d5366bccf1fcf3b296cd61e8d744a21f75f2fb697183e18595d8a79008539d8fb138b405db09db65cc42d54c0e772e5d42d5f20b52f10b793fcecca8f1e1a20724a23f90c0cb8565c769c6d668b92217c1f079b0e5eb8f3e4117040e48183022220d04282bbadf3761d779b2281bc1aae0ca9a0f4af36ce4a3990c4054993d948042a20bbde21969c9070f2bbd7a9751d392a6d70ade2e7f95766b7687491cd7d78c4103220b1c88672abc9aea6ee9f0929f50bee154e45d1bc8c0c08fe3f6fa61dddb87111121a120a70656e756d6272612d311a0c0a0a08a8cb84b2f1cd979f022acb030aa6030a520a50c80865d9789f0e689712ad1b899358377556145e1d4d1297dcb94fa9bea93086254f8081a23e5e6ff88fdf45bf9bd469d40e07c20f26d3dc73e72be32002b8097e6764b16de3f8481c66120cf0c6912612cf02304c524a20394e77567820314464754d346a66206671203630753333346833726465594220756520382078784920627120207a577a204e61554647696b484c37736561745949204f4b382048307220435631795330204c207961596920334935205a74757362207236204e516e6b775339434939767249343346377332305a587762392047206220724b48204b304230764b49674d4b365043636d54353820325776596e6c4b542042205a35574a654f49204f3132432069206d4b7220516c3131464f67464f44476e6a7420205a20726c66204a41203670467a5736764f206a6f6f363458596620344173676c6933487442564a705620536b413935204a424e42703920643838384620356e4949594d57516978203956555543462055203345374e43726d7938202034546f412050334270312075763036312030612056496e4442474e35336c43203163204c4230122082bbb52a115d88526f91ea6d6c3ce4a9bd0d700c81722704fd06d104423c563e";
    const EFFECT_HASH: &str = "209e162852d8d5aee3412e65cd61c83665014cca40779f740181362097dbe318a19449127557e7298f42c41891edf0262edefed3d0a7af4bc44bdff1f27c44ee";
    // Keys from the device taken using a real device with our zondax testing mnemonic
    const SPEND_KEY: &str = "a1ffba0c37931f0a626137520da650632d35853bf591b36bb428630a4d87c4dc";
    const NK: &str = "3a35ee29cccf93149dfa565ea693aa5cd36dc5cf8adff15081038d31e796580b";
    const AK: &str = "92c3e768d3ecf0f2c4d93d879dbc16226fe8540443a8216d6b093d8684865a06";
    const FVK_STR: &str = "92c3e768d3ecf0f2c4d93d879dbc16226fe8540443a8216d6b093d8684865a063a35ee29cccf93149dfa565ea693aa5cd36dc5cf8adff15081038d31e796580b";
    const SPEND_SIGNATURE: &str = "0cb6695b84bd0747641bd4fe2e7349401a0873c49e70a6a4fc7c14260f1b2d0a7aa8aa67e4a1ccbc4f8ea622088f67b8a6f0c60a805977d7fde3e300b6470101";

    #[tokio::test]
    async fn check_signature() {
        let plan_bytes = hex::decode(TRANSACTION_PLAN).unwrap();
        // first get the SpendAuthorization
        // Record that note in an SCT, where we can generate an auth path.
        let mut sct = Tree::new();
        // let proto_tx = ProtoTxPlan::decode(&hex::decode(TRANSACTION_PLAN).unwrap()).unwrap();

        let proto_tx: ProtoTxPlan =
            prost::Message::decode(&plan_bytes[..]).expect("Failed to decode protobuf message");
        let plan = TransactionPlan::try_from(proto_tx).expect("Failed to convert proto to tx plan");

        std::println!("TransactionPlan: {:?}", plan);

        let spk_bytes: [u8; 32] = hex::decode(SPEND_KEY).unwrap().try_into().unwrap();
        let spk_bytes = SpendKeyBytes(spk_bytes);

        let sk = SpendKey::from(spk_bytes);

        let fvk = sk.full_viewing_key();
        let auth_data = plan.authorize(rand_chacha::rand_core::OsRng, &sk).unwrap();
        std::println!("AuthorizationData: {:?}", auth_data);
    }
}
