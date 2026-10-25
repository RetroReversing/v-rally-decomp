#include "common.h"

extern char D_800C02AE[];

s32 func_8006B924(u8 *arg0) {
    s8 sp[3];
    u8 i;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 idx;

    if (arg0[0xC] != 0) {
        for (i = 0; i < 4; i++) {
            idx = i * 14;
            c0 = ((*(u16 *)(D_800C02AE + 0x6E26 + idx) >> 10) & 0x1F) + 0x41;
            sp[0] = c0;
            c1 = ((*(u16 *)(D_800C02AE + 0x6E26 + idx) >> 5) & 0x1F) + 0x41;
            sp[1] = c1;
            c2 = (D_800C02AE[0x6E27 + idx] & 0x1F) + 0x41;
            sp[2] = c2;
            if (c0 == arg0[6] && c1 == arg0[7] && c2 == arg0[8]) {
                return i;
            }
        }
    }
    return 5;
}
