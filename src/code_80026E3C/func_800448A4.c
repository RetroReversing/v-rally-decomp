#include "common.h"

s32 func_80023648();

void func_800448A4(void *arg0) {
    s32 temp_v1;
    s32 var_v0;
    s32 c;

    c = func_80023648();
    temp_v1 = ~0x20;
    if ((u32)(c - 0x501) < 0x5FFU) {
        var_v0 = *(vs32 *)((char *)arg0 + 0x14) | 0x20;
    } else {
        var_v0 = temp_v1 & *(vs32 *)((char *)arg0 + 0x14);
    }
    *(vs32 *)((char *)arg0 + 0x14) = var_v0;
    temp_v1 = *(vs32 *)((char *)arg0 + 0x14);
    if (temp_v1 & 0x80) {
        *(vs32 *)((char *)arg0 + 0x14) = temp_v1 & ~0x20;
    }
}
