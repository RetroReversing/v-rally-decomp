#include "common.h"

extern u8 D_800C02AE[];
extern u8 D_800AE850[];
void func_8008288C(s32 arg0) {
    s32 pad[2];
    s32 temp_s0;
    s32 var_s0;
    s32 var_s2;
    u16 var_s1;
    func_800849BC();
    var_s1 = *(u16 *)((s8 *)&D_800C02AE + 0x30DE);
    temp_s0 = var_s1 & 0xFFFF;
    *(s32 *)((s8 *)&D_800AE850 + 0x8AE0) = func_8007EAA0(arg0, temp_s0 * 8);
    var_s2 = arg0 - arg0;
    if (temp_s0 != 0) {
        var_s1 -= 1;
        do {
            func_800849EC(var_s2);
            var_s2 += 1;
            func_80081C00();
            if (!(var_s1 & 0xFFFF)) break;
            var_s1 -= 1;
        } while (1);
    }
    var_s0 = 0;
    if (var_s2 > 0) {
        do {
            func_80084A3C(var_s0);
            var_s0 += 1;
            func_8008276C();
        } while (var_s0 < var_s2);
    }
}
