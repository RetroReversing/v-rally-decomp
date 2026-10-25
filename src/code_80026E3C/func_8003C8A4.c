#include "common.h"

s32 func_8003A594(void *, s32, s32);
s32 func_80099DF8(void *, void *, s32);
extern u8 D_8009FE30[];
extern u8 D_800A4B40[];
extern u8 *D_800C7F84;

void func_8003C8A4(u8 *arg0) {
    s32 temp_s1;
    u8 *temp_a0;
    s32 temp_v1;

    temp_a0 = *(u8 **)(D_800C7F84 + 0x24);
    if (temp_a0 != NULL) {
        temp_v1 = *(s32 *)(arg0 + 0x80) & ~4;
        *(s32 *)(arg0 + 0x80) = temp_v1;
        if (!(*(s32 *)(temp_a0 + 0x14) & 0x300)) {
            temp_s1 = *(s32 *)(*(u8 **)(temp_a0 + 0x6C) + 0x10);
            if (*(u16 *)(arg0 + 0x78) == 0) {
                func_80099DF8(D_8009FE30, D_800A4B40, (s16) temp_s1);
            }
            func_8003A594(arg0, (s16) temp_s1, 1 - *(u16 *)(arg0 + 0x78));
            *(s16 *)(arg0 + 0x7A) = D_8009FE30[*(u16 *)(arg0 + 0x78)] - 0x30;
            return;
        }
        *(s32 *)(arg0 + 0x80) = temp_v1 | 4;
    }
}
