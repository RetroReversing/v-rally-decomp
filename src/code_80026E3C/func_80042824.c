#include "common.h"

s32 func_80022184();
s32 func_80034FF0();
s32 func_800427CC();
void *func_800801D0();
s32 func_80081540();
extern char D_800A4DC0[];
extern char D_800AE850[];

void func_80042824(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    s32 temp_s0;
    void *temp_v0;

    if (func_80022184(D_800AE850 + 0x73C0) == 0) {
        func_800427CC();
    }
    func_80081540(&D_800A4DC0);
    temp_s0 = func_80034FF0(arg0, 0);
    temp_v0 = func_800801D0(*(s32 *)(D_800AE850 + 0x87F4), 0x14);
    *(s32 *)((char *)temp_v0 + 0xC) = temp_s0;
    *(s8 *)((char *)temp_v0 + 0x10) = arg1;
    *(s8 *)((char *)temp_v0 + 0x11) = arg2;
    *(s8 *)((char *)temp_v0 + 0x12) = arg3;
    *(s8 *)((char *)temp_v0 + 0x13) = 0;
}
