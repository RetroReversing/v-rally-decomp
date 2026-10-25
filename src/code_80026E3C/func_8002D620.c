#include "common.h"

void func_8002D620(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    x = arg0[1] * arg1[2] - arg0[2] * arg1[1];
    y = arg0[2] * arg1[0] - arg0[0] * arg1[2];
    z = arg0[0] * arg1[1] - arg0[1] * arg1[0];
    t = x;
    if (x < 0) {
        t = x + 0xFFF;
    }
    x = t >> 12;
    t = y;
    if (y < 0) {
        t = y + 0xFFF;
    }
    y = t >> 12;
    t = z;
    if (z < 0) {
        t = z + 0xFFF;
    }
    z = t >> 12;
    arg2[0] = x;
    arg2[1] = y;
    arg2[2] = z;
}
