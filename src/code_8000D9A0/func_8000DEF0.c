#include "common.h"

void func_8000DEF0(s16 *arg0, s16 *arg1) {
    arg0[0] = arg1[2] * 2;
    arg0[1] = arg1[3] * 2;
    arg0[2] = 0x1FF;
    arg0[3] = 0;
    arg0[4] = arg1[2] * 2 + arg1[0] * 4;
    arg0[5] = arg1[3] * 2 + arg1[1] * 4;
    arg0[6] = 0x1FF;
    arg0[7] = 0;
}
