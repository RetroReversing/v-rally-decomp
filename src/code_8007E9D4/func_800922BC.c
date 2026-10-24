#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
s32 func_8008BAF0(s32, s32, s32, s32, s32);
extern void *func_800925B0;
extern void *func_80092AFC;

void func_800922BC(void *arg0, s32 arg1) {
    func_80093790(arg0, &func_800925B0, &func_80092AFC, 4);
    *(s32 *)((s8 *)arg0 + 0x14) = func_8008BAF0(0, 0, arg1, 1, 0x50);
    *(s32 *)((s8 *)arg0 + 0x38) = 1;
    *(s32 *)((s8 *)arg0 + 0x48) = 0;
    *(s16 *)((s8 *)arg0 + 0x1A) = 1;
    *(s16 *)((s8 *)arg0 + 0x28) = 1;
    *(s16 *)((s8 *)arg0 + 0x2E) = 1;
    *(s16 *)((s8 *)arg0 + 0x1C) = 1;
    *(s16 *)((s8 *)arg0 + 0x1E) = 1;
    *(s16 *)((s8 *)arg0 + 0x20) = 0;
    *(s16 *)((s8 *)arg0 + 0x22) = 0;
    *(s16 *)((s8 *)arg0 + 0x26) = 1;
    *(s16 *)((s8 *)arg0 + 0x24) = 0;
    *(s16 *)((s8 *)arg0 + 0x26) = 1;
    *(s16 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s16 *)((s8 *)arg0 + 0x18) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    *(s32 *)((s8 *)arg0 + 0x40) = 0;
    *(s32 *)((s8 *)arg0 + 0x44) = 0;
}
