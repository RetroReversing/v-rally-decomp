#include "common.h"

void func_8002D594(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 x;
    s32 y;
    s32 z;

    x = arg0[1] * arg1[2] - arg0[2] * arg1[1];
    y = arg0[2] * arg1[0] - arg0[0] * arg1[2];
    z = arg0[0] * arg1[1] - arg0[1] * arg1[0];
    arg2[0] = x;
    arg2[1] = y;
    arg2[2] = z;
}
