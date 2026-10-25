#include "common.h"

extern char D_800C02AE[];
s32 func_8006874C();

void func_80066EBC(void) {
    char *base;
    u8 v;
    s8 arg;

    base = *(char **)(D_800C02AE + 0x325A);
    v = *(u8 *)(*(char **)(base + 0x10) + *(s16 *)(base + 2) * 20 + 0xE);
    if (v < 2) {
        arg = *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + v + 0x32);
    } else {
        arg = -1;
    }
    func_8006874C(arg);
}
