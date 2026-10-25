#include "common.h"

s32 func_8003A794();
extern char D_800C02AE[];
extern s32 func_8003AD18;

void func_8003D780(s32 arg0, s32 arg1)
{
    u8 col[4];
    u8 *g;
    u8 *a3;
    s32 t1;
    s32 t2;
    s32 t4;
    s32 t5;
    s32 a1;
    s32 a2;
    s32 mode;

    g = *(u8 **)(D_800C02AE + 0x7CD6);
    t1 = *(s16 *)(*(u8 **)(g + 0x178) + 8);
    t4 = *(s16 *)(*(u8 **)(g + 0x178) + 0xA);
    t5 = *(s16 *)(*(u8 **)(g + 0x178) + 0xC);
    t2 = *(s16 *)(*(u8 **)(g + 0x178) + 0xE);
    col[0] = 0xFE;
    col[1] = 0xD5;
    col[2] = 0x1E;
    col[3] = 0xFF;
    a3 = *(u8 **)(D_800C02AE + 0x32F2);
    mode = *(u16 *)(a3 + 0xE);
    a1 = t1 + 0x14;
    a2 = t4 + 6;
    switch (mode) {
    case 1:
        if (*(u16 *)(a3 + 0x1E) == 0) {
            a2 = *(s16 *)(*(u8 **)(g + 0x178) + 0xA) + t2 - 0x12;
            func_8003A794(arg0, a1, a2, &func_8003AD18, arg1, 0, col);
        } else {
            func_8003A794(arg0, t5 - 0x4A, a2, &func_8003AD18, arg1, 0, 0);
        }
        break;
    case 2:
        if (*(u16 *)(a3 + 0x1E) == 0) {
            a2 = *(s16 *)(*(u8 **)(g + 0x178) + 0xA) + 2;
            if (*(u16 *)(a3 + 0x12) & 1) {
                a1 = t1 + 0x14;
            } else if (*(s32 *)(g + 0xC) == 3) {
                a1 = t1 + 0x18;
            } else {
                a1 = t1 + 0x28;
            }
            a1 -= 0x14;
            a2 = a2 + t2 - 0x14;
            func_8003A794(arg0, a1, a2, &func_8003AD18, arg1, 0, col);
        } else {
            if (*(u16 *)(a3 + 0x12) & 1) {
                if (*(s32 *)(g + 0xC) == 3) {
                    a2 = t4 + 4;
                }
                a1 = t1;
                a2 += t2;
                a2 -= 0x11;
            } else {
                if (*(s32 *)(g + 0xC) == 3) {
                    a1 = t1 + 6;
                }
                a2 = t2 - 0x1C;
            }
            func_8003A794(arg0, a1, a2, &func_8003AD18, arg1, 0, 0);
        }
        break;
    }
}
