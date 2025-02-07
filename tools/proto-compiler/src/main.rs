use std::path::PathBuf;

fn main() -> anyhow::Result<()> {
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    println!("root: {}", root.display());

    // We build the proto files for the main penumbra_proto crate
    // and for the cnidarium crate separately, because the
    // cnidarium crate is supposed to be independent of the
    // rest of the Penumbra codebase and its proto structures.
    // Unfortunately, this means duplicating a lot of logic, because
    // we can't share the prost_build::Config between the two.

    let target_dir = root
        .join("..")
        .join("..")
        .join("app")
        .join("rust")
        .join("src")
        .join("protobuf");


    println!("target_dir: {}", target_dir.display());
    
    // https://github.com/penumbra-zone/penumbra/issues/3038#issuecomment-1722534133
    // Using the "no_lfs" suffix prevents matching a catch-all LFS rule.
    let descriptor_file_name = "proto_descriptor.bin.no_lfs";

    // prost_build::Config isn't Clone, so we need to make two.
    let mut config = prost_build::Config::new();

    config.compile_well_known_types();
    // As recommended in pbjson_types docs.
    config.extern_path(".google.protobuf", "::pbjson_types");
    // NOTE: we need this because the rust module that defines the IBC types is external, and not
    // part of this crate.
    // See https://docs.rs/prost-build/0.5.0/prost_build/struct.Config.html#method.extern_path
    config.extern_path(".ibc", "::ibc_proto::ibc");
    // TODO: which of these is the right path?
    config.extern_path(".ics23", "::ics23");
    config.extern_path(".cosmos.ics23", "::ics23");

    config
        .out_dir(&target_dir)
        .file_descriptor_set_path(&target_dir.join(descriptor_file_name))
        .enable_type_names();

    let rpc_doc_attr = r#"#[cfg(feature = "rpc")]"#;

    tonic_build::configure()
        .out_dir(&target_dir)
        .emit_rerun_if_changed(false)
        // Only in Tonic 0.10
        //.generate_default_stubs(true)
        // We need to feature-gate the RPCs.
        .server_mod_attribute(".", rpc_doc_attr)
        .client_mod_attribute(".", rpc_doc_attr)
        .compile_with_config(
            config,
            &[
                "../../proto/penumbra/penumbra/core/asset/v1/asset.proto",
                "../../proto/penumbra/penumbra/core/component/auction/v1/auction.proto",
                "../../proto/penumbra/penumbra/core/component/community_pool/v1/community_pool.proto",
                "../../proto/penumbra/penumbra/core/component/dex/v1/dex.proto",
                "../../proto/penumbra/penumbra/core/component/distributions/v1/distributions.proto",
                "../../proto/penumbra/penumbra/core/component/fee/v1/fee.proto",
                "../../proto/penumbra/penumbra/core/component/funding/v1/funding.proto",
                "../../proto/penumbra/penumbra/core/component/governance/v1/governance.proto",
                "../../proto/penumbra/penumbra/core/component/ibc/v1/ibc.proto",
                "../../proto/penumbra/penumbra/core/component/sct/v1/sct.proto",
                "../../proto/penumbra/penumbra/core/component/shielded_pool/v1/shielded_pool.proto",
                "../../proto/penumbra/penumbra/core/component/stake/v1/stake.proto",
                "../../proto/penumbra/penumbra/core/keys/v1/keys.proto",
                "../../proto/penumbra/penumbra/core/num/v1/num.proto",
                "../../proto/penumbra/penumbra/core/transaction/v1/transaction.proto",
                "../../proto/penumbra/penumbra/core/txhash/v1/txhash.proto",
                "../../proto/penumbra/penumbra/crypto/decaf377_fmd/v1/decaf377_fmd.proto",
                "../../proto/penumbra/penumbra/crypto/decaf377_rdsa/v1/decaf377_rdsa.proto",
                "../../proto/penumbra/penumbra/crypto/tct/v1/tct.proto",
                "../../proto/rust-vendored/gogoproto/gogo.proto",
                "../../proto/rust-vendored/google/protobuf/any.proto",
                "../../proto/rust-vendored/google/protobuf/descriptor.proto",
                "../../proto/rust-vendored/google/protobuf/timestamp.proto",
            ],
            &["../../proto/penumbra/", "../../proto/rust-vendored/"],
        )?;

    Ok(())
}
