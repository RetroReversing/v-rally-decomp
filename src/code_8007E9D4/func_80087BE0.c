#include "common.h"

extern f64 D_800A6D08;

void *func_80087BE0(void *arg0, u8 *arg1) {
    *(u8 *)((char *)arg0 + 0xAE) = arg1[0];
    arg1++;
    *(u8 *)((char *)arg0 + 0xCD) = arg1[0];
    arg1++;
    *(f32 *)((char *)arg0 + 0x1C) = (f64)(f32)arg1[0] * D_800A6D08;
    return arg1 + 1;
}
