#include "common.h"

s32 func_800221D4();
s32 func_80034FF0();
s32 func_80081540();
extern s32 D_800A1240;
extern char D_800A4FEC[];
extern char D_800AE850[];
extern s32 func_8005194C;

void func_800518F4(s32 arg0) {
    func_800221D4(D_800AE850 + 0x73E0, &func_8005194C);
    func_80081540(&D_800A4FEC);
    D_800A1240 = func_80034FF0(arg0, 0);
}
