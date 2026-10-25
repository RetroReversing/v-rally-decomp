#include "common.h"

s32 func_80095A90(s32 arg0) {
    s32 ret;

    if (*(vu32 *)0xA4040010 & 1) {
        *(vs32 *)0xA4080000 = arg0;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}
