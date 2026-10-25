#include "common.h"

void func_800098C4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 *temp_v1 = *(s32 **)((char *)arg0 + 0x14);
    s32 a1;
    s32 a2;
    s32 a3;

    a1 = (arg1 & 0x1F) << 17;
    a2 = a1 | ((arg2 & 0x1F) << 9);
    a3 = arg3 & 0x1F;
    a3 = a3 << 1;
    a2 = a2 | a3;
    temp_v1[0] = a2 | 0x07000000;
    a3 = a3 << 8;
    a1 |= a3;
    a1 |= (((u16 *)&arg4)[1] & 0x1F) << 1;
    temp_v1[1] = a1;
    temp_v1 = (s32 *)((char *)*(void **)((char *)arg0 + 0x14) + 8);
    *(void **)((char *)arg0 + 0x14) = temp_v1;
}
