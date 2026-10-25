#include "common.h"

void func_80089298(char *arg0)
{
    u16 temp_v1;

    if (*(u16 *)(arg0 + 0x92) != 0x7FFF) {
        temp_v1 = *(u16 *)(arg0 + 0xAA);
        if (temp_v1 != 0) {
            *(s32 *)(arg0 + 0x50) = *(s32 *)(arg0 + 0x3C) + (temp_v1 << 8);
        } else {
            *(s32 *)(arg0 + 0x50) = *(s32 *)(arg0 + 0x38) - (*(u16 *)(arg0 + 0xAC) << 8);
        }
    } else {
        *(s32 *)(arg0 + 0x50) = 0x7FFFFFFF;
    }
    *(s8 *)(arg0 + 0xBB) = 1;
    *(u8 *)(arg0 + 0xBC) = *(u8 *)(arg0 + 0xB8);
    *(u8 *)(arg0 + 0xBD) = *(u8 *)(arg0 + 0xB7);
}
