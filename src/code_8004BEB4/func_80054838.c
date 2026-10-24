#include "common.h"

s32 func_80053F44();
s32 func_800540A0();
s32 func_800544D4();
s32 func_800545E4();
s32 func_80054740();
s32 func_80055380();
s32 func_8006ECB4();
s32 func_8006F75C();
s32 func_80097E30();
extern char D_800AE850[];

void func_80054838(void) {
    func_80097E30(D_800AE850 + 0x2530, 0, 0x19);
    func_80053F44();
    func_800540A0();
    func_800544D4();
    func_800545E4();
    func_80055380();
    func_80054740();
    func_8006ECB4();
    func_8006F75C();
}
