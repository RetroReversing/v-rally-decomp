#include "common.h"

void func_8002D740(void *arg0, s32 *arg1, s32 *arg2);

void func_80026E3C(u8 *arg0, void *arg1, s32 *arg2) {
    s32 sp10[3];
    u8 *temp_a0;

    temp_a0 = *(u8 **)(arg0 + 0x58);
    *(s32 *)(temp_a0 + 0x5C) += arg2[0];
    *(s32 *)(temp_a0 + 0x60) += arg2[1];
    *(s32 *)(temp_a0 + 0x64) += arg2[2];
    func_8002D740(arg1, arg2, sp10);
    temp_a0 = *(u8 **)(arg0 + 0x58);
    *(s32 *)(temp_a0 + 0x70) += sp10[0];
    *(s32 *)(temp_a0 + 0x74) += sp10[1];
    *(s32 *)(temp_a0 + 0x78) += sp10[2];
}
