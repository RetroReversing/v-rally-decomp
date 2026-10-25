#include "common.h"

s32 func_800056FC();
void *func_80006008();
s32 func_80006014();

void func_8000F0D8(s32 arg0, s16 *arg1)
{
    s32 temp_s1;
    s32 *temp_v0;
    s32 temp_v1;
    s32 temp_a0;

    temp_s1 = func_800056FC(arg0);
    temp_v0 = func_80006008(temp_s1);
    temp_v1 = (((s32)(arg1[0] * 4.0f)) & 0xFFF) << 12;
    temp_a0 = (((s32)(arg1[1] * 4.0f)) & 0xFFF) | 0xED000000;
    temp_v0[0] = temp_v1 | temp_a0;
    temp_v0[1] = ((((s32)(arg1[2] * 4.0f)) & 0xFFF) << 12) | (((s32)(arg1[3] * 4.0f)) & 0xFFF);
    func_80006014(temp_s1, temp_v0 + 2);
}
