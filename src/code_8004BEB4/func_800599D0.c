#include "common.h"

extern char D_800C02AE[];
s32 func_80057918();
s32 func_80059618();
s32 func_800596F4();

void func_800599D0(u8 *arg0, s32 arg1) {
    if (*(u16 *)(arg0 + 4) != 0x1C7) {
        if (arg1 & 0xFF) {
            func_80059618(arg0, 0xDC, 0xDC, 0xE, 0xFF);
        } else {
            func_80059618(arg0, arg0[0xB], arg0[0xC], arg0[0xD], arg0[0xE]);
        }
        func_800596F4(arg0, *(s16 *)(arg0 + 6), *(s16 *)(arg0 + 8), func_80057918(*(s32 *)(D_800C02AE + 0x807A), *(u16 *)(arg0 + 4)));
    }
}
