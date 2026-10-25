#include "common.h"

extern char D_800C02AE[];

s32 func_80041564(void) {
    void *p;
    u16 a;
    u16 b;

    p = *(void **)(D_800C02AE + 0x32F2);
    a = *(u16 *)((u8 *)p + 0x1E);
    b = *(u16 *)((u8 *)p + 0x20);
    return *(s32 *)(D_800C02AE + 0x10386 + a * 4) + b * 0x2C4;
}
