#include "common.h"

extern s32 D_8009B5A4;
void *func_80005C48(s32);

void func_800150F8(u32 arg0, u32 arg1, s16 arg2) {
    u8 *temp_v0;
    u32 temp_v1;
    u32 temp_a0;

    if ((arg0 < 0x140) & (arg1 < 0xF0)) {
        temp_v0 = func_80005C48(D_8009B5A4);
        temp_v1 = (arg1 * 5) << 7;
        temp_a0 = arg0 * 2 + (u32)temp_v0;
        *(s16 *) (temp_v1 + temp_a0) = arg2;
    }
}
