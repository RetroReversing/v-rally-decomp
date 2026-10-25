#include "common.h"

extern u8 D_800AE850[];
extern u8 D_800C02AE[];
s32 func_8000EC94(void *, void *, void *);
s32 func_80047F3C(void *, s32);

#define CD6_178 (*(u8 **)(*(u8 **)(D_800C02AE + 0x7CD6) + 0x178))

void func_800489D8(void)
{
    u16 box[4];
    u8 col[3];
    u8 *s0;
    s32 i;

    if (*(u16 *)(*(u8 **)(D_800C02AE + 0x7E6E) + 4) == 5) {
        box[0] = *(u16 *)(CD6_178 + 8);
        box[1] = *(u16 *)(CD6_178 + 0xA);
        box[2] = *(u16 *)(CD6_178 + 0xC);
        box[3] = *(u16 *)(CD6_178 + 0xE);
        if (*(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0xE) == 2 && (*(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x12) & 1)) {
            box[0] += 0x20;
            box[2] -= 0x20;
        }
        col[0] = 0xCC;
        col[1] = 0xCC;
        col[2] = 0xCC;
        func_8000EC94(CD6_178, box, col);
        return;
    }
    s0 = *(u8 **)(*(u8 **)(D_800AE850 + 0x6D94));
    if (s0 != NULL) {
        i = 1;
        do {
            func_80047F3C(s0, i & 0xFF);
            s0 = *(u8 **)(s0 + 4);
            i++;
        } while (s0 != NULL);
    }
}
