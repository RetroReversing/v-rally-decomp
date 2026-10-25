#include "common.h"

s32 func_8002B618(void *, void *);
void *func_8007EAA0(s32, s32);
s32 func_80084BF0(s32);
extern u8 D_800A13C0[];
extern u8 *D_800A1468;
extern u8 D_800A5230[];

void func_80057998(void)
{
    u8 *temp_s0;
    u8 i;

    temp_s0 = func_8007EAA0(1, 0x2C0);
    i = 0;
    *(s8 *)(temp_s0 + 0x246) = 1;
    *(s8 *)(temp_s0 + 0x22B) = -1;
    *(s32 *)(temp_s0 + 0x8) = 0;
    *(s32 *)(temp_s0 + 0x0) = 0;
    *(s32 *)(temp_s0 + 0x4) = 0;
    *(s32 *)(temp_s0 + 0x14) = 0;
    *(s32 *)(temp_s0 + 0xC) = 0;
    *(s32 *)(temp_s0 + 0x10) = 0;
    *(s32 *)(temp_s0 + 0x20) = 0;
    *(s32 *)(temp_s0 + 0x18) = 0;
    *(s32 *)(temp_s0 + 0x1C) = 0;
    *(s32 *)(temp_s0 + 0x2C) = 0;
    *(s32 *)(temp_s0 + 0x24) = 0;
    *(s32 *)(temp_s0 + 0x28) = 0;
    *(s8 *)(temp_s0 + 0x234) = 0;
    *(s8 *)(temp_s0 + 0x232) = 0;
    *(s8 *)(temp_s0 + 0x233) = 0;
    *(s8 *)(temp_s0 + 0x22C) = 0;
    *(s8 *)(temp_s0 + 0x22D) = 0;
    *(s32 *)(temp_s0 + 0x288) = 0;
    *(s32 *)(temp_s0 + 0x28C) = 0;
    *(s32 *)(temp_s0 + 0x290) = 0;
    *(s32 *)(temp_s0 + 0x294) = 0;
    *(s8 *)(temp_s0 + 0x247) = 0;
    *(s8 *)(temp_s0 + 0x228) = 0;
    *(s8 *)(temp_s0 + 0x2BC) = 3;
    *(s8 *)(temp_s0 + 0x24D) = 0;
    *(s8 *)(temp_s0 + 0x24E) = 0;
    do {
        *(s32 *)(temp_s0 + (i * 4) + 0x184) = 0;
        i++;
    } while (i < 4);
    *(s16 *)(temp_s0 + 0x222) = -1;
    if (func_80084BF0(0) & 0x2020) {
        *(s8 *)(temp_s0 + 0x248) = 1;
    } else {
        *(s8 *)(temp_s0 + 0x248) = 0;
    }
    D_800A1468 = temp_s0;
    func_8002B618(D_800A13C0, D_800A5230);
}
