#include "common.h"

s32 func_80099DF8();
extern u32 D_8009D540;
extern char D_800A4B20[];
void func_8003AB38(u32 arg0, s32 arg1)
{
    u32 temp_a0;
    u16 temp_a1;
    u16 var_a3;
    u16 var_t0;
    u16 var_v0;
    var_t0 = arg0 / ((u32) (D_8009D540 * 0x3C));
    temp_a1 = var_t0;
    temp_a0 = temp_a1 * 0x3C; temp_a0 = arg0 - (temp_a0 * D_8009D540);
    var_a3 = temp_a0 / ((u32) D_8009D540);
    var_v0 = ((u32) ((temp_a0 - (var_a3 * D_8009D540)) * 0x64)) / ((u32) D_8009D540);
    if (temp_a1 >= 0xA)
    {
        var_v0 = (var_a3 = (var_t0 = 0));
    }
    func_80099DF8(arg1, &D_800A4B20, var_t0, var_a3, var_v0);
}
