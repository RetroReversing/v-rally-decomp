#include "common.h"

s32 func_80097E30(s32, s32, s32);

void func_8001B514(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s8 temp_a0;
    s8 var_a1;
    void *temp_v1;

    func_80097E30((s32)arg0, 0, 0x28);
    var_a1 = 0;
    *(s16 *)((s8 *)arg0 + 0xC) = 0;
    *(s8 *)((s8 *)arg0 + 9) = 1;
    do {
        temp_v0 = var_a1 << 0x18;
        temp_a0 = var_a1 + 1;
        var_a1 = temp_a0;
        temp_v0_2 = temp_v0 >> 0x18;
        temp_v1 = arg0 + temp_v0_2;
        *(s8 *)((s8 *)temp_v1 + 0x10) = 1;
        *(s8 *)((s8 *)temp_v1 + 0x14) = 1;
        *(s8 *)((s8 *)temp_v1 + 0x18) = 1;
        *(s16 *)((s8 *)arg0 + (temp_v0_2 * 2) + 0x1C) = 0;
    } while (temp_a0 < 4);
    *(s16 *)((s8 *)arg0 + 0xA) = 8;
    *(s8 *)((s8 *)arg0 + 4) = 7;
    *(s32 *)((s8 *)arg0 + 0x24) = 0x75834210;
}
