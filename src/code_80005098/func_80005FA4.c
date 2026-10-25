#include "common.h"

extern s32 D_800AE850[];

s32 func_80005FA4(s32 arg0) {
    s32 var_v0;

    if (arg0 != 0) {
        var_v0 = *(vs32 *)((s32)&D_800AE850[4]) ^ arg0;
    } else {
        var_v0 = *(vs32 *)((s32)&D_800AE850[4]);
    }
    return var_v0 != 0;
}
