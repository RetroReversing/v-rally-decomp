#include "common.h"

void *func_800801D0(s32, s32);
extern void func_8004C088(void);
extern void func_8004C370(void);

void func_8004C4D0(s32 arg0, s8 *arg1) {
    s8 *temp_v0;
    s32 temp_a0;
    u8 temp_v1;

    temp_v0 = func_800801D0(arg0, 0x58);
    *(s32 *)(temp_v0 + 0x10) = *(s32 *)(arg1 + 0x90);
    *(s32 *)(temp_v0 + 0x20) = *(s32 *)(arg1 + 0xDC);
    *(s32 *)(temp_v0 + 0x30) = *(s32 *)(arg1 + 0x128);
    *(s32 *)(temp_v0 + 0x14) = *(s32 *)(arg1 + 0x174);
    *(s32 *)(temp_v0 + 0x24) = *(s32 *)(arg1 + 0x1C0);
    *(s32 *)(temp_v0 + 0x34) = *(s32 *)(arg1 + 0x20C);
    *(s32 *)(temp_v0 + 0x18) = *(s32 *)(arg1 + 0x258);
    *(s32 *)(temp_v0 + 0x28) = *(s32 *)(arg1 + 0x2A4);
    *(s32 *)(temp_v0 + 0x38) = *(s32 *)(arg1 + 0x2F0);
    *(s32 *)(temp_v0 + 0x1C) = *(s32 *)(arg1 + 0x33C);
    *(s32 *)(temp_v0 + 0x2C) = *(s32 *)(arg1 + 0x388);
    temp_a0 = *(s32 *)(arg1 + 0x3D4);
    temp_v1 = 0xFF;
    *(u8 *)(temp_v0 + 0x40) = temp_v1;
    *(u8 *)(temp_v0 + 0x44) = temp_v1;
    *(u8 *)(temp_v0 + 0x48) = temp_v1;
    *(u8 *)(temp_v0 + 0x4C) = temp_v1;
    *(u8 *)(temp_v0 + 0x41) = temp_v1;
    *(u8 *)(temp_v0 + 0x45) = temp_v1;
    *(u8 *)(temp_v0 + 0x49) = temp_v1;
    *(u8 *)(temp_v0 + 0x4D) = temp_v1;
    *(u8 *)(temp_v0 + 0x42) = temp_v1;
    *(s32 *)(temp_v0 + 0x3C) = temp_a0;
    *(u8 *)(temp_v0 + 0x46) = temp_v1;
    *(u8 *)(temp_v0 + 0x4A) = temp_v1;
    *(u8 *)(temp_v0 + 0x4E) = temp_v1;
    *(u8 *)(temp_v0 + 0x43) = temp_v1;
    *(u8 *)(temp_v0 + 0x47) = temp_v1;
    *(u8 *)(temp_v0 + 0x4B) = temp_v1;
    *(u8 *)(temp_v0 + 0x4F) = temp_v1;
    *(s32 *)(temp_v0 + 0xC) = 1;
    *(void (**)(void))(temp_v0 + 0x54) = func_8004C088;
    *(void (**)(void))(temp_v0 + 0x50) = func_8004C370;
}
