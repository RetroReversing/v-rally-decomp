#include "common.h"

void func_80006764(void *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7)
{
    u32 off;

    off = (u16)arg1 * 16;
    *(s16 *)(off + *(u32 *)((u8 *)arg0 + 0x70)) = arg2;
    *(s16 *)(off + *(u32 *)((u8 *)arg0 + 0x70) + 2) = arg3;
    *(u16 *)(off + *(u32 *)((u8 *)arg0 + 0x70) + 0x10) = ((u16 *)&arg4)[1];
    *(u16 *)(off + *(u32 *)((u8 *)arg0 + 0x70) + 0x12) = ((u16 *)&arg5)[1];
    *(u16 *)(off + *(u32 *)((u8 *)arg0 + 0x70) + 0x20) = ((u16 *)&arg6)[1];
    *(u16 *)(off + *(u32 *)((u8 *)arg0 + 0x70) + 0x22) = ((u16 *)&arg7)[1];
}
