import { TestCase } from './types'

export const ACTIONS_TESTCASES: TestCase[] = [
  {
    idx: 0,
    name: 'Spend',
    blob: '0abe020abb020aa8010a300a0a08cff4aebf94dbb8fa0512220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a10122040239669cfbb58184c7b5928c1436c398b5cf95aa6a55c91e7bdec9128192d101a520a50890bc98e3698aa4578e419b028da5672e627c280d8b06166f4c42d5366bccf1fcf3b296cd61e8d744a21f75f2fb697183e18595d8a79008539d8fb138b405db09db65cc42d54c0e772e5d42d5f20b52f10b793fcecca8f1e1a20724a23f90c0cb8565c769c6d668b92217c1f079b0e5eb8f3e4117040e48183022220d04282bbadf3761d779b2281bc1aae0ca9a0f4af36ce4a3990c4054993d948042a20bbde21969c9070f2bbd7a9751d392a6d70ade2e7f95766b7687491cd7d78c4103220b1c88672abc9aea6ee9f0929f50bee154e45d1bc8c0c08fe3f6fa61dddb87111121a120a70656e756d6272612d311a0c0a0a08a8cb84b2f1cd979f022acb030aa6030a520a50c80865d9789f0e689712ad1b899358377556145e1d4d1297dcb94fa9bea93086254f8081a23e5e6ff88fdf45bf9bd469d40e07c20f26d3dc73e72be32002b8097e6764b16de3f8481c66120cf0c6912612cf02304c524a20394e77567820314464754d346a66206671203630753333346833726465594220756520382078784920627120207a577a204e61554647696b484c37736561745949204f4b382048307220435631795330204c207961596920334935205a74757362207236204e516e6b775339434939767249343346377332305a587762392047206220724b48204b304230764b49674d4b365043636d54353820325776596e6c4b542042205a35574a654f49204f3132432069206d4b7220516c3131464f67464f44476e6a7420205a20726c66204a41203670467a5736764f206a6f6f363458596620344173676c6933487442564a705620536b413935204a424e42703920643838384620356e4949594d57516978203956555543462055203345374e43726d7938202034546f412050334270312075763036312030612056496e4442474e35336c43203163204c4230122082bbb52a115d88526f91ea6d6c3ce4a9bd0d700c81722704fd06d104423c563e',
    expected_effect_hash:
      '209e162852d8d5aee3412e65cd61c83665014cca40779f740181362097dbe318a19449127557e7298f42c41891edf0262edefed3d0a7af4bc44bdff1f27c44ee',
  },
  {
    idx: 1,
    name: 'Output',
    blob: '0a9102128e020a300a0a0897e4ffc783b1a6ec0c12220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012520a50bfbb4c92e67eb7e6af13f633a477c3d325bee50d044e441512e6bf7fcdd9650934f9d8ead350816317dad39308f0d91dcaa155f9bf4aa7e2f8378df85008aef46766d1fe5c2b097f71ac1489154ddea91a20cb302f60ae37fb29c3cfc6e58c8b3f3a633ed723542d29145343fc8516f5268922208f05c39e61fa49c5b3b00707835362a7f280bf57a3c49f4f256f5b72746926032a20ddef66f55bdde614f8a26292a463cedce66b4c3a44f67a593f4e0baa22dd720b3220e870b617cb404e0167291fb08fa02df2df4c9180a4d18c63e17f7017ce1b8301121b120b612d3230393139353532361a0c0a0a08f5dcb0cbcedfe69a05',
    expected_effect_hash:
      '0ac386aecba110d78e238465f0b7e39e49f7f9839eb7e36ae4113c58fef9cf9c72a3ae99c34b1f48ef82497171613a3aea4a7fae6f6b3991771130a805a5e3d3',
  },
  // {
  //     idx: 2,
  //     name: "Swap",
  //     blob: "0abe021abb020ad2010a480a220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012001a0a089cafa1c7c7acf8810222020a002a520a501e4aebd4bce2cacf963e429753cb1ec313316b9b8734ad9e283e4c68b283731ee430988d512315805e384a1a53c64c5cbd2fd28e8f6a346af49643780f86bae30424fc0114f0391fb220cedf31d29d01322098e7a833a3078477140079b2a1f0ef131a2999f71d14285afbd5c1e2d7a695421220751ed3a0014209512df12f8a8f40b9440aa5da9fa54b9222665f72cd0e8152001a20fdfcf28112019695c35eb5c077f6ed1d6a4036151f4609a466aa4c615711aa1222208f5be55a5b7b36815a8ed4d3fc976aa39c4189c13cada6a8c6ead96d95168b0e121a120a70656e756d6272612d311a0c0a0a08b7b2afc2b586b5d80d",
  //     expected_effect_hash: "282a8a4c9e071da2fb2e700e4a7b6cfd2c05616df8c76166f04e0b293f5848e62e092c4d9a1dcdd924916da3aff07158470446df1f236ecf3a4840f14e440c5a"
  // },
  {
    idx: 3,
    name: 'Ics20_Withdrawal',
    blob: '0aa802c20ca4020a0a089ac1a69ed6899eb20a12170a156555696136517031326662333046327071304e67411a8f0170656e756d62726131357a376c717a30667578716c3363746168717a6a687365726d6b74756c327a376e716b3074673364787876656b793076327574706130373474377174766e6a3036796d33756c6771766a6c356b6a7271686c32636464736866306a337a79666e30746c733974397736677975616e363263376e61613239747a3238353430323970716563776d22520a507d1ae84746eeca2356ab7d18a7597b3b0e3a91fdb701b3003df15e90d2f6b2775d41893e37ccd1afd4d8cd170838f2f3ff69a99baa1384cca876c0ed7ff7771956f46197af3fc6f9b10aa671ff53e46e2a0c08f6baf1db0310fe97bafb013a096368616e6e656c2d30123808e188091224796469667779697573666f6b737777627166656e6b2d33323234363639343633383737331a0c0a0a08fae384879bc48c890a2a91030aec020a520a50738391f16c9d87ecf88aaa28f6dc7cc4eb413594adfb83ae85fb2fd5dd6c9709c3899b3a15f6a5a4dd8fdd5c10d0ea84dccaa02f20bb5476e1646b18fd54f657a8b1906f67995f40834f9c44440f22e01295025820452032386a31547520204868303147652033554c52375a532020383575782079492072202063597165202020206168346631583079306e6c3255453737313020544774506b5a514766766e4f4678314f2020346920393768207056204f203120544c6f697659706e794630774a506b3733556f3573336e205a76652078623774613136642064207738734d436a2053207730314a6b37204962452078616d2020654a392042205455203066566a634e204437554d684e4b4d71717a2036656d492046376c457431546e376578674f4f71546667387050386c204e203352333139764774706b4820455520344320754b30306f4170332020204d6f35204634353820383774356f58396562204f4520644f5553201220dd9b6fc0592cbdc2d6680301d529a5448f72b0ba63451979351d7d2ada963950',
    expected_effect_hash:
      '462717be27e0ecf1a4d9d52537fb3729d4328f1867a97fa7c374a6c02a44ee58ca0acb2f2702693946e5d4dfbd6c014238231b27556938bb2f0c2ffd2b3e3d0b',
  },
  // {
  //     idx: 4,
  //     name: "Ics20_Withdrawal_Output_Output_Swap",
  //     blob: "0ab202c20cae020a0908a3f7bf85dee4834112220a20383434336737366e68464b50415330655a4158325357325a3279686e37466d681a8f0170656e756d627261317634357632707737736334366d786c717964306472757832716a347834306b64376e6e30397475667875687835766c6e643261786b347970327a64746a713472736b34686679356135343933346e397673656c716a736a33796635366d68373966323372307839366b3078657036326c7774716a61366561723673637333646330667167647922520a50e36d2527859acb08cf24cfd2d0a33ab885a1f620ffabd8e04b55a8ec318296cc353086b43ae2464e41b1ca82e07d49e65d37a3942df18ef1e82fb82b0e1e33e27066c17c57dcb3b27d8cb8fc88674aca2a0c08eb86ef870310f4d7faa4033a096368616e6e656c2d300a9102128e020a300a0a08999ed385d8b9dbe20812220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012520a50fc48056bc3fa38105dec3bbf85360034324a68f5f9ad7b1b5b6796f97d8279ae15308df6d619d93aab071c2ea360d09dd0f3fa4d3a8a49b9f9b208ee42e491efff1162c3525990477dfc81a681b7d7c11a20e6c8f1315f134443f8b2fbcf8eb261133e630baabc514d8d97527ea7fc5c4698222052e3247b8af144014822c6a1640d65a80d9285c22bea5fef5e5dd220ce6a76012a20b0dcd8596fa908795337c88329cc1599ac327069b48b79f64d089db5a9642d10322041ee25a60f43df71b28c8677fc19bc1e0fd41433132ffee0b9bde222cde616120a9102128e020a300a0a08d9bacf9082a1d2a80612220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012520a500fa1c90b7b5a37c415800fffe133ff58900ddf87f2bb554f2738c51f0f1591e1b88f33afcaec891632dee4a24400335c453618299673c680b467043c271cdd71bbeb9eebc86f98e5896de26658df64181a20ade0c63b41986930e31b4944cbe0a246eabae9ac2dab3f2ce21daefa03b408f722206da3f56a8ff35a1167c9a5447974588fbce628bb0e428ca2cfcb4fcaf75d61032a20fc8e31cf4ed1ae3821db366157a27106af1bf1e93525b717caf5204dc11aec0132206348b4e143b548762d272f38ea6f6ef868e9234e987607a058e4e66238d51d060abe021abb020ad2010a480a220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012001a0a08cab2f7869ceecc8e0d22020a002a520a50695c4366531a04c83a71e70d31ad399b6f8df14e4f581aa936c920048236096eb6ee116e1d16f71a92773093c031be6646653ea5a6d46c85f23d61ee577e2d3aad2ab3dc6f9661250457c809f8753c313220b4dbd903a787e8c3ee9e81f1dce34585f4f3e73e367fb5a20795ab1d9e85607612200cc3557010bf5d416661d60f6f101c59fb8a11e56523f1c991e90240c4b944031a20c0ca8df9502ba597ea371f4ee2b558bacc61c6e4670f2a31bd0625310d280a072220467109e81b74d93152a4f06e9e852eb008f0a01fb530e72979837f659810a400121e08b4ff38120a70656e756d6272612d311a0c0a0a08d6c6ecba9d88dda304",
  //     expected_effect_hash: "33e570e3d3f30d17aee23e51cc25de5d95c3a22d54861ebca7039d3480b157e9edc255f79476dfd40f68ec778d7365d2e56b11b557d7f86f40700b68f8b39996"
  // },
]
