#include "common.h"

s32 func_80093790(void *a0, void *fn2, void *fn3, s32 n4);
extern void *alSavePull;
extern void *alSaveParam;

void alSaveNew(void *arg0) {
    func_80093790(arg0, &alSavePull, &alSaveParam, 3);
    *(s32 *)((s8 *)arg0 + 0x14) = 0;
    *(s32 *)((s8 *)arg0 + 0x18) = 1;
}
