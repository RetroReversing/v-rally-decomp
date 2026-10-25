#include "common.h"

extern char D_800A6FA0[];
extern char D_800A6FA4[];
void func_800914E0(void *, void *, s32);
s32 func_80095940();

s32 func_8008DBE0(s32 arg0, s32 arg1) {
    if (arg0 & 3) {
        func_800914E0(D_800A6FA0, D_800A6FA4, 0x34);
    }
    if (func_80095940() != 0) {
        return -1;
    }
    *(s32 *)(arg0 | 0xA0000000) = arg1;
    return 0;
}
