#include "common.h"

extern char D_800A73E0[];
extern s32 func_80086F40;

s32 *func_80086F00(void **arg0) {
    if (*(u8 *)(D_800A73E0 + 0x4560) == 0) {
        *(s32 *)(D_800A73E0 + 0x4564) = 0;
        *(u8 *)(D_800A73E0 + 0x4560) = 1U;
        *(s32 *)(D_800A73E0 + 0x4568) = (s32) *(s32 *)(D_800A73E0 + 0x456C);
    }
    *arg0 = D_800A73E0 + 0x4560;
    return &func_80086F40;
}
