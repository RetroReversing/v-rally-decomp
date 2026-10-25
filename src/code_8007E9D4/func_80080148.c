#include "common.h"

void func_80080148(s32 *arg0, s32 *arg1, s16 arg2) {
    s32 *var_v1;
    u16 var_a3;

    var_a3 = arg2;
    var_v1 = (s32 *)arg1[0];
    while (var_v1 != NULL) {
        if (*(s16 *)(var_v1 + 2) < var_a3) {
            break;
        }
        var_v1 = (s32 *)var_v1[1];
    }
    if (var_v1 != NULL) {
        arg0[1] = (s32)var_v1;
        arg0[0] = var_v1[0];
        var_v1[0] = (s32)arg0;
        if ((s32)var_v1 == arg1[0]) {
            arg1[0] = (s32)arg0;
        }
    } else {
        arg0[1] = 0;
        arg0[0] = arg1[1];
        if (arg1[1] != 0) {
            ((s32 *)arg1[1])[1] = (s32)arg0;
        }
        arg1[1] = (s32)arg0;
        if (arg1[0] == 0) {
            arg1[0] = (s32)arg0;
        }
    }
    *(s16 *)(arg0 + 2) = arg2;
    *(s16 *)((u8 *)arg0 + 0xA) = 0;
}
