#include "common.h"

extern char D_800C02AE[];
extern u8 D_8009FE18[];
void func_8003AB38(s32 a0, void *a1);

void func_8003B574(void *arg0) {
    u8 *s0;
    u8 *a1;
    s32 a;
    s32 off;
    s32 base;

    a1 = *(u8 **)(*(u8 **)(D_800C02AE + 0x7CD6) + 0x24);
    if (a1 != 0) {
        s0 = arg0;
        base = *(s32 *)(*(u8 **)(a1 + 0x6C) + 0x14);
        off = (*(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x22) << 6) + 0x2C;
        a = *(s32 *)(base + off);
        if (*(s32 *)(a1 + 0x14) & 0x100) {
            *(s32 *)(s0 + 0x80) |= 4;
        }
        if (*(u16 *)(s0 + 0x78) == 0) {
            func_8003AB38(a, D_8009FE18);
        }
        *(s16 *)(s0 + 0x7A) = D_8009FE18[*(u16 *)(s0 + 0x78)] - 0x30;
    }
}
