#include "common.h"

s32 func_800592AC();
s32 func_8005937C();
s32 func_8006185C();
s32 func_80069A08();
s32 func_8007A688();
s32 func_8007A7D0();
extern void *D_800A1468;
extern char D_800C02AE[];

void func_8007A9A8(void)
{
    void *temp_s;
    u8 *temp_a1;
    u8 *temp_a0_2;
    u8 *base;
    void *temp_v0;
    s32 temp_a0;
    void *d;

    temp_s = *(void **)(D_800C02AE + 0x325A);
    temp_a1 = *(u8 **)((u8 *)temp_s + 0x10) + *(s16 *)((u8 *)temp_s + 2) * 0x14;
    d = D_800A1468;
    temp_a0 = *((u8 *)d + 0x245);
    if (temp_a0 == 0) {
        *((u8 *)D_800A1468 + 0x238) = temp_a1[0xE] - temp_a1[0xD];
        func_8005937C(temp_a1[0xE], *((u8 *)D_800A1468 + *((u8 *)D_800A1468 + 0x238) + 0x23D), d);
        base = *(u8 **)(D_800C02AE + 0x32F2);
        temp_a0_2 = base + *(u8 *)(base + *(s8 *)((u8 *)D_800A1468 + 0x228) + 0x32) * 0x28;
        temp_v0 = D_800A1468;
        *((u8 *)temp_v0 + 0x237) = *(u16 *)(temp_a0_2 + 0x4E);
        func_80069A08(temp_a0_2, temp_v0);
    } else {
        func_8007A688(temp_a0, temp_a1, D_800A1468);
        func_80069A08();
        func_8006185C(func_800592AC(*((u8 *)D_800A1468 + 0x238)), 1);
    }
    func_8007A7D0(*((u8 *)D_800A1468 + 0x237));
}
