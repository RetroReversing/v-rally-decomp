#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
s32 func_8008BAF0(s32, s32, s32, s32, s32);
extern void *func_80093930;
extern void *func_80094110;

void func_80092374(void *arg0, s32 (*arg1)(void *), s32 arg2) {
    func_80093790(arg0, &func_80093930, &func_80094110, 0);
    *(s32 *)((s8 *)arg0 + 0x14) = func_8008BAF0(0, 0, arg2, 1, 0x20);
    *(s32 *)((s8 *)arg0 + 0x18) = func_8008BAF0(0, 0, arg2, 1, 0x20);
    *(s32 *)((s8 *)arg0 + 0x30) = arg1((s8 *)arg0 + 0x34);
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    *(s32 *)((s8 *)arg0 + 0x40) = 1;
    *(s32 *)((s8 *)arg0 + 0x44) = 0;
}
