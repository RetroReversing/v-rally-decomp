#include "common.h"

extern char D_800A167C[];

s32 func_80068CA4(s32 arg0, s32 arg1) {
    u8 temp_v1;

    temp_v1 = *(D_800A167C + arg1);
    if (temp_v1 < 8U) {
        *(D_800A167C + arg1) = temp_v1 + 1;
    }
    return 0;
}
