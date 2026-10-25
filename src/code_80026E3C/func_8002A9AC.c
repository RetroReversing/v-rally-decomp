#include "common.h"

s8 *func_8002A9AC(s8 *arg0, u32 arg1)
{
    s8 *var_a0;
    s8 temp_a2;

    var_a0 = arg0;
    while (((((temp_a2 = *var_a0) == 0x20) | (temp_a2 == 9)) != 0 || temp_a2 == 0x2C) && (u32) var_a0 < arg1) {
        var_a0 += 1;
    }
    return var_a0;
}
