#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
extern void *alMainBusPull;
extern void *func_80094580;

void alMainBusNew(void *arg0, s32 arg1, s32 arg2) {
    func_80093790(arg0, &alMainBusPull, &func_80094580, 7);
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = arg2;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
}
