#include "common.h"

void func_800068C0(u8 *arg0, s32 arg1, u16 arg2, u16 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13) {
    s32 off = (arg1 & 0xFFFF) << 4;

    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70)) = arg2;
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 2) = arg3;
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 4) = *(u16 *)((u8 *)&arg4 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x10) = *(u16 *)((u8 *)&arg5 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x12) = *(u16 *)((u8 *)&arg6 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x14) = *(u16 *)((u8 *)&arg7 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x20) = *(u16 *)((u8 *)&arg8 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x22) = *(u16 *)((u8 *)&arg9 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x24) = *(u16 *)((u8 *)&arg10 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x30) = *(u16 *)((u8 *)&arg11 + 2);
    *(u16 *)(off + (s32)*(u8 **)(arg0 + 0x70) + 0x32) = *(u16 *)((u8 *)&arg12 + 2);
    off = off + (s32)*(u8 **)(arg0 + 0x70);
    *(u16 *)(off + 0x34) = *(u16 *)((u8 *)&arg13 + 2);
}
