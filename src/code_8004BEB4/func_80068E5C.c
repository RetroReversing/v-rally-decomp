#include "common.h"

extern u8 *D_800C35A0;
extern void *D_800C3508;
extern u8 *D_800A1468;
u8 *func_800592AC();
void func_800592F4();
void func_80068D9C();
void func_8008A0D8();

s32 func_80068E5C(s32 arg0) {
    u8 *temp_a0;
    u8 temp_v1;
    u8 *temp_v0;

    temp_a0 = D_800C35A0 + (*(s8 *)(D_800A1468 + 0x22A)) * 0x28;
    temp_v1 = temp_a0[0x48];
    if (temp_v1 & 0x10) {
        func_80068D9C(arg0);
        return 0;
    }
    temp_a0[0x48] = temp_v1 | 0x10;
    func_8008A0D8(D_800C3508, 0x17, 0);
    temp_v0 = func_800592AC(6);
    temp_v0[0xF] = 0x50;
    temp_v0[0x10] = 0x50;
    temp_v0[0x11] = 0x50;
    func_800592F4(arg0, 1);
    return 0;
}
