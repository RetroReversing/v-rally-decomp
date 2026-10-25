#include "common.h"

u8 func_800602F4();
extern u8 D_8009EB83;
extern char D_800A1530[];
extern char D_800C02AE[];

u8 func_8006204C(s32 arg0, s32 arg1, s32 arg2)
{
    s32 temp_a0;
    s32 temp_a1;
    s32 off;
    u8 var_a3;
    s32 v;
    s32 mul;

    temp_a0 = arg0 & 0xFF;
    var_a3 = 0;
    if (temp_a0 >= 0) {
        if (temp_a0 < 6) {
            v = arg1 & 0xFF;
            temp_a0 = temp_a0 << 2;
            mul = (v << 1) + v;
            mul = (mul << 2) - v;
            mul = (mul << 4) + v;
            temp_a1 = *(s32 *)(D_800C02AE + 0x10386 + temp_a0) + (mul << 2);
            off = (arg2 & 0xFF) * 14 + 0x24C;
            var_a3 = func_800602F4(temp_a1 + off, temp_a1);
        } else if (temp_a0 < 0xA) {
            var_a3 = D_8009EB83;
        }
    }
    return D_800A1530[var_a3];
}
