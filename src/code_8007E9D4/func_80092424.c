#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
s32 func_8008BAF0(s32, s32, s32, s32, s32);
extern void *func_800948E0;
extern void *func_80094ACC;

void func_80092424(void *arg0, s32 arg1) {
    func_80093790(arg0, &func_800948E0, &func_80094ACC, 1);
    *(s32 *)((s8 *)arg0 + 0x14) = func_8008BAF0(0, 0, arg1, 1, 0x20);
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    *(s32 *)((s8 *)arg0 + 0x24) = 1;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(f32 *)((s8 *)arg0 + 0x18) = 1.0f;
}
