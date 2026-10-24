#include "common.h"

extern char D_800A167C[];

s32 func_80068C78(s32 arg0, s32 arg1) {
    u8 temp_v0;

    temp_v0 = *(D_800A167C + arg1);
    if (temp_v0 != 0) {
        *(D_800A167C + arg1) = temp_v0 - 1;
    }
    return 0;
}
