#include "common.h"

s16 func_8002D2E4();
s16 func_8002D348();

s16 *func_8002DD90(s32 arg0, s16 *arg1) {
    s16 temp_s0;
    s16 temp_v0;

    temp_s0 = func_8002D2E4(arg0);
    temp_v0 = func_8002D348(arg0);
    arg1[0] = 0x1000;
    arg1[1] = 0;
    arg1[2] = 0;
    arg1[3] = 0;
    arg1[4] = temp_s0;
    arg1[5] = -temp_v0;
    arg1[6] = 0;
    arg1[7] = temp_v0;
    arg1[8] = temp_s0;
    return arg1;
}
