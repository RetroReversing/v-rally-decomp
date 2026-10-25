#include "common.h"

s32 func_8007F278();
s32 func_8008ACD0(void *, s32, void *, s32, void *, s32);
s32 func_8008DFC0(void *);
s32 func_80090250(s32, void *, void *, s32);
s32 func_8000E428();
extern s32 D_800A19C0;
extern s32 D_800A19C4;
extern char D_800A73E0[];
extern char D_800A7400[];
extern char D_800A75C8[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern char D_800D0680[];

void func_8007FF9C(s32 arg0) {
    void *temp_s0;

    func_8007F278();
    D_800A19C0 = (s32) D_800D0680;
    D_800A19C4 = 0x80400000 - (s32) D_800D0680;
    func_80090250(0x96, D_800A7400, D_800A73E0, 8);
    temp_s0 = D_800A75C8;
    func_8008ACD0(temp_s0, 3, func_8000E428, arg0, D_800AE850 + 0x5550, 5);
    func_8008DFC0(temp_s0);
    for (;;) {
        ((void (*)()) *(s32 *) (D_800C02AE + 0x7DFE))();
    }
}
