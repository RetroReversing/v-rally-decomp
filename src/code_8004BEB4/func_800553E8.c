#include "common.h"

s32 func_800553E8(u8 *arg0, s32 arg1)
{
    u8 *var_a0;
    u8 temp_a2;
    u32 var_v0;

    var_v0 = *arg0;
    var_a0 = arg0 + 1;
    goto test;
    do {
        var_v0 = temp_a2 + ((var_v0 & 0xFFFF) * 0xD);
        var_a0++;
test:
        temp_a2 = *var_a0;
    } while (temp_a2 != 0);
    return (var_v0 + arg1) & 0x7FF;
}
