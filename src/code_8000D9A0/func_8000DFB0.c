#include "common.h"

extern s8 D_800C5E54;
extern s8 D_800AE865;
extern s8 D_8009B5B0;
extern char D_800C02AE[];
extern s32 D_800D05B8;
s32 func_80005C48();
s32 func_8007F4E4();
s32 func_8007F6E0();
s32 func_8007F798();
s32 osViBlack();
s32 osViSwapBuffer();

void func_8000DFB0(s32 arg0)
{
    s32 temp_s1;

    temp_s1 = func_8007F4E4(4, 0, 1);
    for (;;) {
        func_8007F6E0(arg0);
        osViSwapBuffer(func_80005C48(D_800D05B8));
        func_8007F6E0(temp_s1);
        if (D_800C5E54 == 0) {
            osViBlack(0);
            D_800C5E54 = (u8)D_800C5E54 - 1;
        } else if (D_800C5E54 > 0) {
            D_800C5E54 = D_800C5E54 - 1;
        }
        D_800AE865 = 0;
        D_8009B5B0 = 0;
        *(s8 *)(D_800D05B8 + 0x14) = 1;
        *(s8 *)(*(s32 *)(D_800C02AE + 0x3252) + 0x14) = 1;
        func_8007F798(6, 2, D_800D05B8);
    }
}
