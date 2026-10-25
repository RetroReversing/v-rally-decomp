#include "common.h"

void func_8001225C(s32 *arg0, s32 *arg1) {
    s32 ax;
    s32 ay;
    s32 az;
    s32 bx;
    s32 by;
    s32 bz;

    ax = arg0[0];
    ay = arg0[1];
    az = arg0[2];
    arg0 += 3;
    bx = arg0[0];
    by = arg0[1];
    bz = arg0[2];
    arg1[0] = bx - ax;
    arg1[1] = by - ay;
    arg1[2] = bz - az;
}
