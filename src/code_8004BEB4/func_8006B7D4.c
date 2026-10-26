#include "common.h"

s32 func_8002B618();
s32 func_8006B8C4();
s32 func_8006E33C();
s32 func_8006F5E8();
s32 func_8006F628();
s32 func_8006F69C();
s32 func_8006F7F8();
s32 func_8006F8E0();
s32 func_8006FA8C();
s32 func_80084AFC();
s32 func_80084B50();
s32 func_80084BF0();
s32 func_80084DD4();
s32 osEepromProbe();
extern s32 D_8009F640;
extern s8 D_800A16F0;
extern char D_800A57C0[];
extern char D_800AE850[];

s32 func_8006B7D4(void) {
    D_800A16F0 = 0;
    D_8009F640 &= 0xFFFF7FFF;
    func_8002B618(&D_800A57C0, 0);
    func_80084AFC();
    if (osEepromProbe(D_800AE850 + 0x5A38) != 1) {
        func_8006F628();
        return 0;
    }
    func_80084B50();
    func_8006F69C();
    if ((func_80084DD4(3) != 0) && (func_80084BF0(3) & 0xA000)) {
        func_8006F7F8();
    }
    if (func_8006F5E8() == 0) {
        func_8006B8C4();
    } else {
        func_8006F8E0();
    }
    func_8006E33C();
    func_8006FA8C();
    return 1;
}
