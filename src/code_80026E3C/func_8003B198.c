#include "common.h"

s32 func_8003AC30(s32, u8 *);
extern u8 D_8009FE24[];

void func_8003B198(u8 *arg0, s32 arg1) {
    s32 temp_a0;

    if (arg1 != 0) {
        if (*(u16 *)(arg0 + 0x78) == 0) {
            func_8003AC30(arg1, D_8009FE24);
            temp_a0 = D_8009FE24[*(u16 *)(arg0 + 0x78)] - 0x30;
            *(s32 *)(arg0 + 0x80) &= ~4;
            *(s8 *)(arg0 + 0x94) = 0;
            *(s16 *)(arg0 + 0x7A) = temp_a0;
        } else {
            *(s32 *)(arg0 + 0x80) &= ~4;
            *(s8 *)(arg0 + 0x94) = 0;
            *(s16 *)(arg0 + 0x7A) = D_8009FE24[*(u16 *)(arg0 + 0x78)] - 0x30;
        }
    } else {
        *(s32 *)(arg0 + 0x80) |= 4;
    }
}
