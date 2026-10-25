#include "common.h"

s32 func_8001FEE8(s32);
void func_80099DF8(u8 *, void *, s32);
extern u8 D_800A4B3C[];

void func_8003C254(u8 *arg0) {
    u8 buf[4];
    s32 temp_a0;
    s32 temp_v0;
    u8 *temp_v1;
    u8 *temp_a0_2;

    temp_a0 = *(s32 *)(*(u8 **)(arg0 + 0xA8) + 0x24);
    if (temp_a0 != 0) {
        if (*(u16 *)(arg0 + 0x78) == 0) {
            temp_v0 = func_8001FEE8(temp_a0);
            temp_v0 &= ~temp_v0 >> 31;
            func_80099DF8(buf, D_800A4B3C, temp_v0 & 0xFFFF);
            temp_v1 = *(u8 **)(arg0 + 0x8C);
            *(s16 *)(arg0 + 0x7A) = buf[0] - 0x30;
            temp_a0_2 = *(u8 **)(temp_v1 + 0x8C);
            if (buf[1] != 0) {
                *(s32 *)(temp_v1 + 0x80) &= -5;
                *(s16 *)(arg0 + 0x7A) = buf[1] - 0x30;
                *(s16 *)(temp_v1 + 0x7A) = buf[0] - 0x30;
                if (buf[2] != 0) {
                    *(s32 *)(temp_a0_2 + 0x80) &= -5;
                    *(s16 *)(arg0 + 0x7A) = buf[2] - 0x30;
                    *(s16 *)(temp_v1 + 0x7A) = buf[1] - 0x30;
                    *(s16 *)(temp_a0_2 + 0x7A) = buf[0] - 0x30;
                    return;
                }
            } else {
                *(s32 *)(temp_v1 + 0x80) |= 4;
            }
            *(s32 *)(temp_a0_2 + 0x80) |= 4;
        }
    }
}
