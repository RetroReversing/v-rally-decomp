#include "common.h"

extern char D_800A6F90[];
extern char D_800A6F94[];

void func_800914E0(char *, char *, s32);
s32 func_80095940(void);

s32 func_8008DB50(s32 arg0, s32 *arg1) {
    s32 val;

    if (arg0 & 3) {
        func_800914E0(D_800A6F90, D_800A6F94, 0x33);
    }
    if (arg1 == NULL) {
        func_800914E0(D_800A6F90, D_800A6F94, 0x34);
    }
    if (func_80095940() != 0) {
        return -1;
    }
    val = *(s32 *)(arg0 | 0xA0000000);
    *arg1 = val;
    return 0;
}
