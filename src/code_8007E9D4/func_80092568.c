#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
extern void *func_800957C0;
extern void *func_800958C0;

void func_80092568(void *arg0) {
    func_80093790(arg0, &func_800957C0, &func_800958C0, 3);
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 1;
}
