#include "common.h"

extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern s32 func_8002291C(void);
extern s32 func_80022930(void);
extern s32 func_80022948(void);
extern s32 func_80080514(s32, s32 (*)(void), s32);

void func_8004F3C4(void) {
    s32 mode;
    u8 *p;
    p = *(u8 **)(D_800C02AE + 0x32F2);
    mode = *(u16 *)(p + 0x1E);
    if (mode == 0) {
        if (*(u16 *)(p + 0x1A) == 0) {
            func_80080514(*(s32 *)(D_800AE850 + 0x73F0), func_80022948, 0x40); } else {
            func_80080514(*(s32 *)(D_800AE850 + 0x73F0), func_8002291C, 0x40);
        }
    } else if (mode == 5 && *(u8 *)(D_800AE850 + 0x7FC8) == 0) {
        func_80080514(*(s32 *)(D_800AE850 + 0x73F0), func_8002291C, 0x40);
    } else {
        u8 *q = *(u8 **)(D_800C02AE + 0x32F2);
        if (*(u16 *)(q + 0xE) == 2) {
            u16 x = *(u16 *)(q + 0x1E);
            if ((x != 0 && x < 5) || x == 5) {
                func_80080514(*(s32 *)(D_800AE850 + 0x73F0), func_80022948, 0x40);
                return;
            }
        }
        func_80080514(*(s32 *)(D_800AE850 + 0x73F0), func_80022930, 0x40);
    }
}
