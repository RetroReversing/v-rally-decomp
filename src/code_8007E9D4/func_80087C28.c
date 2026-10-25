#include "common.h"

extern f64 D_800A6D10;

u8 *func_80087C28(u8 *arg0, u8 *arg1)
{
    arg0[0xAE] = arg1[0];
    arg1++;
    arg0[0xCD] = arg1[0];
    arg1++;
    *(f32 *)(arg0 + 0x1C) = (f32) ((f64) -(f32) arg1[0] * D_800A6D10);
    return arg1 + 1;
}
