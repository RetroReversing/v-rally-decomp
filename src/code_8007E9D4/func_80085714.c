#include "common.h"

extern s32 D_800A1B70;
s8 func_80084C0C();

s8 func_80085714(s32 arg0, s32 arg1)
{
    s32 idx;
    char *base;
    char *entry;
    s32 var_a1;

    base = (char *)D_800A1B70;
    idx = arg0 & 0xFF;
    entry = base + idx * 0x14;
    if (arg1 == *(s32 *)(entry + 0x68)) {
        var_a1 = 0x20000;
    } else if (arg1 == *(s32 *)(entry + 0x6C)) {
        var_a1 = 0x10000;
    } else {
        return 0;
    }
    return func_80084C0C(idx, var_a1);
}
