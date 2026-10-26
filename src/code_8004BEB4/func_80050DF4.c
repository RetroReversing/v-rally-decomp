#include "common.h"

extern char D_800C02AE[];
extern signed char D_800C3BA0;
extern signed char D_800C3B9E;
extern unsigned char D_800C3B9C;
extern unsigned char D_800C3B9D;
extern unsigned char D_800C3B9F;

u64 osGetTime();
s32 func_80098090();
s32 func_800980C4();

s32 func_80050DF4(void)
{
    u8 *rec;
    u8 *flags;
    u8 cnt;
    s32 v;
    s32 t;
    s32 a3;
    s32 bit;

    func_800980C4((u32)osGetTime());
    rec = *(u8 **)(D_800C02AE + 0x32F2);
    D_800C3BA0 = *(u16 *)(rec + 0x12);
    D_800C3B9E = *(u16 *)(rec + 0xE);
    if (D_800C3B9C == 0xFF) {
        D_800C3B9C = 0x14;
    }
    do {
        v = func_80098090();
        t = v;
        if (v < 0) {
            t = v + 7;
        }
        a3 = v - ((t >> 3) * 8);
        bit = 1 << (a3 & 0xFF);
    } while ((D_800C3B9C & bit) == bit);
    flags = &D_800C3B9C;
    cnt = D_800C3B9D + 1;
    *flags = *flags | (1 << (a3 & 0xFF));
    D_800C3B9D = cnt;
    if ((cnt & 0xFF) == 3) {
        D_800C3B9D = 0;
        D_800C3B9F = D_800C3B9F + 1;
        if (D_800C3B9F == 2) {
            D_800C3B9F = 0;
        }
    }
    return a3 & 0xFF;
}
