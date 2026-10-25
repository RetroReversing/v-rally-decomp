#include "common.h"

void func_8000682C(void *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10)
{
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10)) = arg2;
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 2) = arg3;
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 4) = ((u16 *)&arg4)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x10) = ((u16 *)&arg5)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x12) = ((u16 *)&arg6)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x14) = ((u16 *)&arg7)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x20) = ((u16 *)&arg8)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x22) = ((u16 *)&arg9)[1];
    *(u16 *)(*(u8 **)((u8 *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x24) = ((u16 *)&arg10)[1];
}
