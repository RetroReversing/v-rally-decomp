#include "common.h"

s32 func_8002D2C8();

s32 func_80023648(u8 *arg0) {
    u8 *obj;
    u8 *temp_a2;
    s32 temp_a0;
    s32 var_a0;
    s32 var_a1;
    u16 temp_v0;
    u16 temp_v1;
    s32 d44;
    s32 d50;
    s32 sp20;
    s32 sp28;
    s32 sp30;
    s32 sp38;
    s32 sp40;
    s32 sp48;
    volatile s32 d44v;
    volatile s32 pad14;
    volatile s32 d50v;
    volatile s32 pad1c;
    volatile s32 sp20v;
    volatile s32 pad24;
    volatile s32 sp28v;
    volatile s32 pad2c;
    volatile s32 sp30v;
    volatile s32 pad34;
    volatile s32 sp38v;
    volatile s32 pad3c;
    volatile s32 sp40v;
    volatile s32 pad44;
    volatile s32 sp48v;
    s32 var_s0;
    s32 var_a0_2;
    s32 t38;

    obj = arg0;
    temp_a2 = *(u8 **)(*(u8 **)(obj + 0x8C) + 0x28);
    temp_a0 = *(s32 *)(*(u8 **)(obj + 0x60) + 0x28);
    if (temp_a0 == *(u16 *)(temp_a2 + 0x88) - 1) {
        temp_v1 = *(u16 *)(temp_a2 + 0x8A);
        var_a0 = (temp_a0 * temp_v1) + (temp_v1 >> 1) - temp_v1;
        var_a1 = var_a0 + temp_v1;
    } else {
        temp_v0 = *(u16 *)(temp_a2 + 0x8A);
        var_a0 = (temp_a0 * temp_v0) + (temp_v0 >> 1);
        var_a1 = var_a0 + temp_v0;
    }
    sp20v = sp20 = *(s16 *)(*(u8 **)(temp_a2 + 0x54) + var_a0 * 6);
    sp28v = sp28 = *(s16 *)(*(u8 **)(temp_a2 + 0x54) + var_a0 * 6 + 4);
    sp30v = sp30 = *(s16 *)(*(u8 **)(temp_a2 + 0x54) + var_a1 * 6);
    sp38v = sp38 = *(s16 *)(*(u8 **)(temp_a2 + 0x54) + var_a1 * 6 + 4);
    d44v = d44 = *(s16 *)(*(u8 **)(obj + 0x5C) + 0x44);
    d50 = *(s16 *)(*(u8 **)(obj + 0x5C) + 0x50);
    sp40v = sp40 = sp30 + d44;
    sp48 = sp38 + d50;
    d50v = d50;
    sp48v = sp48;
    var_s0 = func_8002D2C8(sp48 - sp38, sp40 - sp30, temp_a2, obj);
    t38 = sp38v;
    var_a0_2 = func_8002D2C8(t38 - sp28v, sp30v - sp20v, t38);
    if ((var_s0 < -0x400) & (var_a0_2 > 0x400)) {
        var_s0 += 0x1000;
    }
    if ((var_a0_2 < -0x400) & (var_s0 > 0x400)) {
        var_a0_2 += 0x1000;
    }
    var_s0 -= var_a0_2;
    if (var_s0 < 0) {
        var_s0 += 0x1000;
    }
    return var_s0;
}
