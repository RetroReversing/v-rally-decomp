#include "common.h"

s32 func_80034FF0();
void *func_80040260();
s32 func_80098680();
void func_8003FD04();
void func_8004C04C();
extern char D_800A4C00[];
extern char D_800A4C08[];
extern char D_800C02AE[];

void *func_80040084(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_v;
    void *var_s1;

    var_s1 = NULL;
    if (*(u16 *)(*(char **)(D_800C02AE + 0x32F2) + 0x1E) != 7) {
        if (func_80098680(D_800A4C00, arg1 + 0x4C, 4) == 0) {
            var_s1 = func_80040260(arg0, 0, 0, arg2 & 0xFFFF, func_8004C04C, 1);
        } else {
            var_s1 = func_80040260(arg0, 0, 0, arg2 & 0xFFFF, 0, 1);
        }
        *(s32 *)((char *)var_s1 + 0xA4) = func_80034FF0(arg1 + 0x4C, 0);
    } else {
        temp_s0 = arg1 + 0x4C;
        if (func_80098680(D_800A4C00, temp_s0, 4) == 0) {
            var_s1 = func_80040260(arg0, 0, 0, arg2 & 0xFFFF, func_8004C04C, 1);
            *(s32 *)((char *)var_s1 + 0xA4) = func_80034FF0(temp_s0, 0);
        } else if (func_80098680(D_800A4C08, temp_s0, 4) == 0) {
            temp_v = func_80034FF0(temp_s0, 0);
            var_s1 = func_80040260(arg0, 0, 0, arg2 & 0xFFFF, func_8003FD04, 1);
            *(s32 *)((char *)var_s1 + 0xA4) = temp_v;
        }
    }
    return var_s1;
}
