#include "common.h"

s32 func_8002E148();

void func_80023134(void *arg0, s32 *arg1, s32 *arg2) {
    s16 sp10[3];
    s32 *var_s1;
    u32 var_v1;
    void *var_s0;

    var_s0 = *(void **)((char *)arg0 + 0x5C);
    sp10[0] = arg2[0];
    var_s1 = arg1;
    sp10[1] = arg2[1];
    sp10[2] = arg2[2];
    var_s0 += 0x40;
    func_8002E148(sp10, var_s0);
    var_v1 = 0;
    do {
        *(s32 *)((char *)var_s0 + 0x14) = *var_s1;
        var_s1 += 1;
        var_v1 += 1;
        var_s0 += 4;
    } while (var_v1 < 3U);
}
