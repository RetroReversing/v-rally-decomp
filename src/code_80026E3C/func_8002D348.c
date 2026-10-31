#include "common.h"
extern f64 D_800A4A30;
extern f64 D_800A4A38;
extern f32 __sinf(f32);
s32 func_8002D348(s32 a)
{
    f32 x;
    x = (f32)(((f64)a) * D_800A4A30);
    x = (f32)(((f64)x) * D_800A4A38);
    x = __sinf(x);
    x *= 4096.0f;
    return (s32)x;
}
