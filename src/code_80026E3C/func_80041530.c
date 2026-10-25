#include "common.h"

extern s32 D_800D0634[];

s32 func_80041530(s32 arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = D_800D0634[arg0];
    return temp_v1 + arg1 * 0x2C4;
}
