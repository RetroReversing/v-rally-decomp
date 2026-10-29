#include "snapshot29_0433f7af8f6d.h"

s32 func_8000665C(void *, s32);

s32 func_80006338(void *arg0, s16 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_v0;
    void *temp_a2;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    if (*(u16 *)((char *)arg0 + 0x78) & 1) {
        temp_v1 = *(void **)((char *)arg0 + 0x14);
        *(u16 *)((char *)arg0 + 0x78) = 0U;
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1 + 8);
        *(s32 *)((char *)temp_v1 + 0) = 0xD9C0F9FA;
        *(s32 *)((char *)temp_v1 + 4) = 0;
        temp_v1_2 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_2 + 8);
        *(s32 *)((char *)temp_v1_2 + 0) = 0xD9FFFFFF;
        *(s32 *)((char *)temp_v1_2 + 4) = 5;
        temp_v1_3 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_3 + 8);
        *(s32 *)((char *)temp_v1_3 + 0) = 0xD7000000;
        *(s32 *)((char *)temp_v1_3 + 4) = 0;
        temp_v1_4 = *(void **)((char *)arg0 + 0x14);
        *(void **)((char *)arg0 + 0x14) = (void *)(temp_v1_4 + 8);
        *(s32 *)((char *)temp_v1_4 + 0) = 0xFCFFFFFF;
        *(s32 *)((char *)temp_v1_4 + 4) = 0xFFFE793C;
    }
    temp_v0 = (u16)func_8000665C(arg0, 3);
    temp_a0 = temp_v0 * 0x10;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 4) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x14) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x24) = arg1;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 6) = 0;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x16) = 0;
    *(s16 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x26) = 0;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0xF) = 0xFF;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x1F) = 0xFF;
    *(u8 *)((char *)(temp_a0 + *(s32 *)((char *)arg0 + 0x70)) + 0x2F) = 0xFF;
    temp_a2 = *(void **)((char *)arg0 + 0x14);
    temp_a0_2 = temp_v0 & 0x1F;
    *(void **)((char *)arg0 + 0x14) = (void *)(temp_a2 + 8);
    *(s32 *)((char *)temp_a2 + 0) = (temp_a0_2 << 0x11) | ((temp_a0_2 + 1) << 9) | ((temp_a0_2 + 2) * 2) | 0x05000000;
    *(s32 *)((char *)temp_a2 + 4) = 0;
    return temp_v0;
}
