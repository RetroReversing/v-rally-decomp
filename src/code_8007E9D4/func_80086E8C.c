#include "common.h"

extern s32 D_800C782C;
extern char D_800AE850[];

void func_80086E8C(void *arg0, f32 arg1)
{
    s32 pad[2];
    s32 n;
    s32 i;
    u8 *base;
    u8 *p;

    base = *(u8 **)(D_800AE850 + 0x80A0);
    i = 0;
    n = D_800C782C;
    if (n > 0) {
        p = base + 0x2C;
        do {
            if (*(s32 *)(p + 0x14) == *(s32 *)((u8 *)arg0 + 4)) {
                *(f32 *)p = arg1;
                i = n;
            }
            i++;
            p += 0x134;
            n = D_800C782C;
        } while (i < n);
    }
}
