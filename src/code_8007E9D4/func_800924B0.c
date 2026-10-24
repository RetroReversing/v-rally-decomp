#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
extern void *func_800914F0;
extern void *func_800915CC;

void func_800924B0(void *arg0, s32 arg1, s32 arg2) {
    func_80093790(arg0, &func_800914F0, &func_800915CC, 6);
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = arg2;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
}
