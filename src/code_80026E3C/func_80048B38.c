#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 D_800A4E4C[];
extern u8 D_800A4E50[];
s32 func_8000A188(void *, void *, s32, s32, s32);
s32 func_80034FF0(void *, s32);
void *func_8004240C(s32);
void *func_80048C74(void *, s32, void *);
s32 func_80098180(void *, void *);

void func_80048B38(u8 *arg0)
{
    u8 *arg1;
    u8 *temp_s0;
    u8 *temp_s2;
    u8 *temp_s6;
    s32 temp_s3;
    s32 var_s4;
    u32 var_s5;
    u32 var_s7;
    u8 temp_v0;

    arg1 = arg0;
    temp_s2 = NULL;
    temp_v0 = *(u8 *)(*(u8 **)&D_800C02AE[0x32F2] + 0xF);
    temp_s0 = **(u8 ***)&D_800AE850[0x6D94];
    var_s5 = 1;
    if (temp_v0 != 0) {
        temp_s6 = arg1 + 0x4C;
        var_s7 = temp_v0;
        var_s4 = 1;
        do {
            temp_s3 = func_80034FF0(arg1 + 0x98, 0);
            if (func_80098180(temp_s6, D_800A4E4C) == 0) {
                temp_s2 = func_80048C74(temp_s0 + 0xC, 0, arg1);
                *(s32 *)(temp_s0 + 0x40) = *(s32 *)(arg1 + 0x128);
            } else if (func_80098180(temp_s6, D_800A4E50) == 0) {
                temp_s2 = func_80048C74(temp_s0 + 0x44, 1, arg1);
                *(s32 *)(temp_s0 + 0x78) = *(s32 *)(arg1 + 0x128);
            }
            *(s32 *)(temp_s2 + 0xC) = temp_s3;
            func_8000A188(*(void **)((u8 *)func_8004240C(var_s4) + 0x178), temp_s2, *(arg1 + 0x12B), 0, 0);
            var_s4 += 2;
            var_s5 += 1;
            temp_s0 = *(u8 **)(temp_s0 + 4);
        } while (var_s7 >= var_s5);
    }
}
