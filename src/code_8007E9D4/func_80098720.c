#include "common.h"

extern char D_800A3E10[];

s32 func_80098720(s32 arg0) {
    s32 var_a0;

    var_a0 = arg0;
    if (*(D_800A3E10 + (var_a0 & 0xFF)) & 4) {
        var_a0 -= 0x20;
    }
    return var_a0;
}
