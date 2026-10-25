#include "common.h"

extern f64 D_800A6D18;

void *func_80087CF4(void *arg0, u8 *arg1)
{
    s32 var_v1;
    f32 temp_fv0;
    f32 temp_fv1;

    var_v1 = *arg1;
    arg1++;
    if (var_v1 & 0x80) {
        var_v1 |= ~0xFF;
    }
    temp_fv0 = (f32)((f64)(f32)var_v1 * D_800A6D18);
    temp_fv1 = (*(f32 *)((char *)arg0 + 0x2C) - *(f32 *)((char *)arg0 + 0x88)) + temp_fv0;
    *(f32 *)((char *)arg0 + 0x88) = temp_fv0;
    *(f32 *)((char *)arg0 + 0x2C) = temp_fv1;
    return arg1;
}
