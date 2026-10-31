#include "common.h"
extern f64 D_800A4A20;
extern f64 D_800A4A28;
extern f32 __cosf(f32);
s32 func_8002D2E4(s32 a)
{
    f32 x;
    x = (f32)(((f64)a) * D_800A4A20);
    x = (f32)(((f64)x) * D_800A4A28);
    x = __cosf(x);
    x *= 4096.0f;
    return (s32)x;
}
