#include "common.h"

extern u8 D_800C02AE[];

void func_8006FA8C(void) {
    u8 *base;
    u32 flags;
    s32 bit;
    u8 i;

    base = *(u8 **)(D_800C02AE + 0x103AA);
    flags = *(*(u8 **)(D_800C02AE + 0x32F2) + 0x2F);

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if ((flags & bit) == bit) {
            *(u16 *)(base + i * 0x2C4 + 0x2140) &= ~8;
        } else {
            *(u16 *)(base + i * 0x2C4 + 0x2140) |= 8;
        }
    }

    if (flags & 0x20) {
        *(u16 *)(base + 0x1E7C) &= ~8;
    } else {
        *(u16 *)(base + 0x1E7C) |= 8;
    }

    if (flags & 0x10) {
        for (i = 0; i < 4; i++) {
            *(u16 *)(base + i * 0x2C4 + 0x2C50) |= 8;
        }
        return;
    }

    for (i = 0; i < 4; i++) {
        *(u16 *)(base + i * 0x2C4 + 0x2C50) |= 8;
    }
}
