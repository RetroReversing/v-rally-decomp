#include "common.h"

extern s16 D_800B5C6A;
extern s32 D_800B5C60;
extern s16 D_800B5C68;
extern s16 D_800B5C58[];

void func_8000F400(u8 arg0, u16 arg1, u8 arg2)
{
    s16 *temp_a0;
    u32 temp_v0;
    s32 temp_q;

    D_800B5C6A = arg0;
    temp_a0 = D_800B5C58;
    D_800B5C60 = arg2;
    if (arg2 == 1)
    {
        D_800B5C68 = 0xFF;
        temp_v0 = arg1;
    }
    else
    {
        D_800B5C68 = 0;
        temp_v0 = arg1;
    }
    if (temp_v0 >= 0x100)
    {
        arg1 = 0xFF;
    }
    temp_q = 0xFF / arg1;
    temp_a0[0] = arg1;
    temp_a0[2] = temp_q;
}
