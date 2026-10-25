#include "common.h"

extern u8 D_800C02AE[];
s32 func_800592F4(s32, u16);

s32 func_8005F380(void) {
    u8 *p;
    u8 *base;
    u8 i;
    u32 off;

    p = *(u8 **)(D_800C02AE + 0x32F2);
    *(u16 *)(p + 0x50) = 1 - *(u16 *)(p + 0x50);
    base = p;
    i = 1;
    do {
        off = i * 0x28;
        *(u16 *)(off + base + 0x50) = *(u16 *)(base + 0x50);
        i++;
    } while (i < 4);
    func_800592F4(0x11, *(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x50));
    return 0;
}
