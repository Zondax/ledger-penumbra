import { IDeviceModel, DEFAULT_START_OPTIONS } from '@zondax/zemu'

import { resolve } from 'path'

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'
export const PENUMBRA_PATH = "m/44'/6532'/0'"
export const ACCOUNT_ID = 1
export const ACCOUNT_ID2 = 2

// Due to binary size problems nanos is not supported
// const APP_PATH_S = resolve('../app/output/app_s.elf')
const APP_PATH_X = resolve('../app/output/app_x.elf')
const APP_PATH_SP = resolve('../app/output/app_s2.elf')
const APP_PATH_ST = resolve('../app/output/app_stax.elf')
const APP_PATH_FL = resolve('../app/output/app_flex.elf')

export const models: IDeviceModel[] = [
  // Due to binary size problems nanos is not supported
  // { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  // { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
  // { name: 'stax', prefix: 'ST', path: APP_PATH_ST },
  // { name: 'flex', prefix: 'FL', path: APP_PATH_FL },
]

export const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}


