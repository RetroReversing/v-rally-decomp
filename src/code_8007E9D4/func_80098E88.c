#include "common.h"

extern char D_800A73E0[];
s32 func_80098998(void *, s32, s32);
s32 func_80098B7C(s32, s32, s32, s32 *, s32);

void *func_80098E88(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4)
{
    s8 *var_v1;
    s32 temp_a1;
    s32 var_a2;

    var_v1 = (s8 *) func_80098B7C(arg0, arg1, 0x14, arg3, arg4);
    temp_a1 = *arg3;
    if (temp_a1 != 0x7FFFFFFF) {
        var_a2 = temp_a1 + arg2;
        if (var_a2 >= 0) {
            if (var_a2 < 0x14) {
                *arg3 = func_80098998(&D_800A73E0[0x6B28], temp_a1, var_a2);
            } else {
                if (var_a2 >= 0x29) {
                    var_a2 = 0x28;
                }
                var_a2 -= 0x14;
                var_v1 += 0x14;
                if (var_a2 > 0) {
                    do {
                        *var_v1 = 0x30;
                        var_a2 -= 1;
                        var_v1 += 1;
                    } while (var_a2 > 0);
                }
            }
        }
    }
    return &D_800A73E0[0x6B28];
}
