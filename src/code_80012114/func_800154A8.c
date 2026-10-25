#include "common.h"

void func_800154A8(u32 *arg0, s32 arg1, s32 arg2) {
    char pad[8];
    s32 var_a3;
    u32 *var_a0;
    u32 temp_v1;

    var_a0 = arg0;
    var_a3 = 0;
    if (arg1 > 0) {
        do {
            temp_v1 = *var_a0;
            var_a3 += 1;
            if (temp_v1 <= 0x7FFFFFFFU) {
                *var_a0 = temp_v1 + arg2;
            }
            var_a0 += 2;
        } while (var_a3 < arg1);
    }
}
