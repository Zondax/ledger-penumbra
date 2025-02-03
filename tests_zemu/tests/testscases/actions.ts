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
  {
    idx: 4,
    name: 'Deleagte',
    blob: '0a42c2023f0a220a20190f5214f58d21b07bc3f143e2a8ec4de51b463843cdb537e8221084b4e4be7d10a70c1a0a08f1b980b6c0b7acff09220a08c6bdf9ca96c487e009122512157274732d34363830313137323933343733323539341a0c0a0a08ecb09bcd85889cd90a2aec020ac7020a520a5003ea4fa22155ab8476c5e8b1db71e0aa898099485bc38f82684a669730587fcdfa31d1280722aad3155503cec36632f1ec1740febad7ba6169a2c442732c5a7581f17f56185adad613c0f604b5211a3212f001326c433359416d472020502073564e5077352036492067454c615832383069204b2020204e562072416c33617a36202076595a56582067775558312039482050775456307a426f203367354c20654b204a3852206f457533702039354c78485a6a2050496271764a32374231374d7a7a44203744206f372078303033685668783520206d2073316e634f38203450386441324f67517130685247663434584a204b4d344f206235612039326c6120587639624520314763566e39312068726632664e4a65204d6e456d596d38672020414d366e4f49334832624d753369776e72206d204a20203034384a6d3530384678122099aef8745c0a34e4085939bb061198411c55df15507482c4e6a0914ce8ec5587',
    expected_effect_hash:
      '6d2048e48ada8800a46ca80c2a42b394f0459e132c041cd9a9c85fb8c4bb159048951f39b3f4299401f0e47ba5a59319bed54ec1221950ba2f6a24add73743e8',
  },
  {
    idx: 5,
    name: 'Undelegate',
    blob: '0a46ca02430a220a200429420ed639777d600b547e6adc8fe8e8858fa944188a2734c502c3edd9aff21a0908c6dbe5d3e0bd9718220a08cebfcaeef2a2dcfd0c2a0608ab1110ab11122c08b98f28121879656a636279766d6a6f6768696e76787275792d343738341a0c0a0a0898d5b3c1d0c6dbe30a',
    expected_effect_hash:
      '9616a3347a7fb88ee1ef46bf6893e542bd7f19da7f0d3bb1d2968ef0366f6748f95678ddb205b078658c45917e1ed8d1fd9530a3908490d3de37a1370e9705e2',
  },
  {
    idx: 6,
    name: 'Undelegate_Claim',
    blob: '0ac201d202be010a220a2027836f69712e112e9db6957619379924fed46c2ea43254ad5b03389d87bb8ed222220a2000000000000000000000000000000000ffb15b573eab367a0f9096bb98c7e2832a0a08a4f1d88eabb7a088073220ce45b5ca03c5b70aad2572a3e60b9cd348c6d4d6175bafcdbadc77df5c715f013a20d0e4be966e508d10b493d8896a9a6cd33c4bc6ab3abcbdf9d03a78b62fde0f02422095b6d39c349ec34643c6a5330f9f1fbe225e3f81b05c2d9afc7cb8c559966c0d48d6f505122408d2a72f12106f71667277642d3136373735323039301a0c0a0a08dbe3f3ebd89eedff042aa3030afe020a520a503db91d3972d73cd32b0a2b50ad228bd1d5f8eb13ab367ba7fec05aed82324fcbb84218b399b55aa96ef7fef3768d8ce78ebd8d735cd46d767a48dc8059ddf1f83d29d2473b64847af2a8cc379e6ba92012a7025559204e3172205865414f6758465a203678356b6752317537374f32353820534b38496c6d7a4220652020733037206551424b204f79326757663335373452202053594e204e7330554f6168646f3438206f705836206c20652077206747494c6d312039314e4957314e55435732376168386470683520382043756a726d67316b324777395a387232366c364f2020786863397a7556324a3238434845394d385a63205a7970367265334a32654b20202020373436785a3230205634535439377a4b38386e6f2057572020555a4b3936367853206e6b74504f20626f20396a692072386e2074797343566e3148674c5839387220323971447a3859623748206620774b4a5a6120754275202055417a37337a2031207968572031204e513954203920206932503512202fcfc901480c42fda18c33fbe8d7901e57291ceca1f74b8357b366ab20436167',
    expected_effect_hash:
      '54d1599266060ded55b6af002002c78cbb39a3368b32059a426cc01d4a9ed978433390b5b0efc49a9549ea18bc6f55395ae48a0cde5098df7461dec5e16bc665',
  },
  {
    idx: 7,
    name: 'Position_Open',
    blob: '0aaf01f201ab010aa8010a640a18120a08ac8efeb6d8fcc88c081a0a08f5a4be9393a88bf50112480a220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a10122000000000000000000000000000000000000000000000000000000000000000001a02080122180a0a08a0e7cdd5f8edc5c708120a08f7cfccd1df95bd9e052801121a120a70656e756d6272612d311a0c0a0a08e58f8483fad4c98405',
    expected_effect_hash:
      '6ff26ef4a86f85a79aa821c1fa44720bbfa253eeb890f3557a6d45349111b40af63e22e936a40435116fc790ec87d0bec7bc41a2f87202b36fac85399d2bc586',
  },
  {
    idx: 8,
    name: 'Position_Close',
    blob: '0a27fa01240a220a204bbe086b0f46948f7fd7a5b873f7fb086fc399ede0ed812cfb46800769c701b5121e0896e71b120a70656e756d6272612d311a0c0a0a08b9f0f9d6bed78e8e01',
    expected_effect_hash:
      'b29f5e6cdd16d91953f827e5afd254d3691b209ab8c0ce449b709d2de99f9169b6a931ff206a888e99143f7691bcad94eaa1a91d4047844fa6e8afac9ee05232',
  },
  {
    idx: 9,
    name: 'Position_Withdraw',
    blob: '0a9701820293010a180a0a08aa9588978fb6cb8f02120a08d8c2ffceeffececc0612220a20e51530cb7af3ad0a870394567d165be6c235585f9d6b4310334fb2fd2fe337891a480a220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1020b1a0eba691e5d1e4cd0112371227786b61626d6a766873617263656e6f7664696c6e66622d343933393636383538313832353231361a0c0a0a0892a0feb38d8297980c',
    expected_effect_hash:
      '3ae113513e3a6022f40b9eef1e7a1b47ea33b5a1ef08aa4db1659b8a8163a14943f311515669bb608d3f5f65cd75a1df89fe5b3afaa6d41298f06f2db4f9d0d9',
  },
  {
    idx: 10,
    name: 'Dutch_Auction_Schedule',
    blob: '0aa801aa03a4010aa1010a300a0a08efc1ac90d8c79c9f0712220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1012220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a101a0908d299b9a5ccef8d2d220a08c38397f18be6b5f60528cbf1f0bf0130ccf1f0bf0138d2abe2910342201c8c0f7041df8be2fe5f6bf04ec82e725986f6e4822679a68c45b9f473ef6c5f124b123b61706c6d6a7a6e71636d7675617165716c6c73717a637066706876642d3735373236353238353632363830313339353636393830363530333939311a0c0a0a08da93c3c4a1d7ec9607',
    expected_effect_hash:
      'a7ec1f4df0720884446ae9c3a82d7e0f5ccd68117af1a66205f00a5ec7e652608e2e83fead73c6fb62785df9454255d8e291e2c637e0514ac2ca5681d3d49051',
  },
  {
    idx: 11,
    name: 'Dutch_Auction_End',
    blob: '0a27b203240a220a209146032b96da50eb4002fca16ca8caf6d814eb04d1587e2d7375f7631f8c3223121a120a70656e756d6272612d311a0c0a0a08a2c6db89a5ccf2920a2a81020adc010a520a503405ce7611de176cf025875f5fe88e40f887ca3d057343fbee5d26325b698a89bd4f61f2f05b0c3fefaf35db606e928f68582ad48a5f2f879ae7f5a5bcc9cbf67dc68abc8d64d4fa676fff340f88d81c128501596177376a464d20426f3020684e5420307a3452546530476d203033652050573138204820206b3158774d5641365020323559452020733669207a44445020367a50684d4e36543855305979202047595a527862203320205446584720594a31494c6b38366a50476d7235362020623462652036416720322066506c4e43774b42634620531220218952e6049b4fe8d33c1ccd34b01d4067c7ca4a24313f609db9d3cfc6be739a',
    expected_effect_hash:
      '831e71ade8f18e52d8b6d5917e5dd92cde5995b12de7bb9f513cdd1fa9d0f5510f178dac9c07bef18fdd8d0f62823e88b458d4bd479608cd5d77cbec59432c8f',
  },
  {
    idx: 12,
    name: 'Dutch_Auction_Withdraw',
    blob: '0a9101ba038d010a220a20c8e835549a1ff640a5812680855d9f23d6ff06ebeed9e57dddca5e71806624b210f480db0a1a300a0a08f0a0aa93b1c3839a0c12220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a1022300a0a08fda0b3c49de6d1cb0912220a2029ea9c2f3371f6a487e7e95c247041f4a356f983eb064e5d2b3bcf322ca96a10122a121b6566657774677a72736873796d6162777a6c78647a6b63642d30321a0b0a0908f4bfcfd98adebe042af1020acc020a520a500f0b7f44e8814645e90dcaf1a8b1d35f794483fd067037a4c9ad0a104c12b0dc4fa351bd73ea6b3a3b7fd8af874e987a3e5d4f6420a53d66bd022b6c97048fad6430718940efc32fbf5d7e9f36105f1212f501485a48387320582068646a2020206e207538686f52533331202063376e43356f68722050356c2031205638695341206920343161207520386c4a7a4b79662062334a3120206a6c3133685564795a374973394756202051722032203420206b3732476d6531203465616131206b48346549375420454c2020716b4e72583631203420414155206d30385076426e3745522062202052663955437220204534204f366e594643644a4f363972757333203972207935204d7331625a496f20205943363167612058592036672050206b6d5a20436244206f4e51305632203533772041396e6f4e31574938686e39664e204f7a4c3171201220e59b72f45b2a4ae19ff9f731d0b5bd45766de79e791901deebdbf090380ea29d',
    expected_effect_hash:
      '5a43389ca7f1beddea45593243f3d3074df09cbba250b5b2f29a0d9e13f4769b352d2b7cceb77264186754bad2b31513e08071f1714cc82f7b986ffc1c1d34b2',
  }
]
