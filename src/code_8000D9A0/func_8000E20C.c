#include "common.h"

s32 func_800059DC();
extern s32 D_8009B5A4;
extern s32 D_8009B5A8;
extern s32 D_8009B5AC;

void func_8000E20C(s32 arg0) {
    s32 var_v0;

    if (arg0 & 0x2000) {
        if (arg0 & 0x100) {
            var_v0 = func_800059DC(arg0, 1, 3);
            D_8009B5A8 = var_v0;
            D_8009B5A4 = var_v0;
        } else if (arg0 & 0x200) {
            D_8009B5A8 = func_800059DC(arg0, 1, 3);
            var_v0 = func_800059DC(arg0, 1, 3);
            D_8009B5A4 = var_v0;
        }
        if (arg0 & 0x800) {
            D_8009B5AC = func_800059DC(arg0, 1, 5);
        }
    }
}
