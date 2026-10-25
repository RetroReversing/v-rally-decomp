#include "common.h"

s32 func_8008ACA0();
s32 func_8008D090();
s32 func_8008D4A0();
extern s32 D_800A39A0;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800B6FF8[];

void func_800946B4(void)
{
    s32 sp10;

    if (D_800A39A0 == 0) {
        D_800A39A0 = 1;
        func_8008ACA0(D_800AE850 + 0x87A8, D_800A73E0 + 0x6AF0, 1);
        func_8008D4A0(D_800B6FF8, 0, 0);
    }
    func_8008D090(D_800AE850 + 0x87A8, &sp10, 1);
}
