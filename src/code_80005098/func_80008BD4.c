#include "common.h"

void func_80008BD4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 temp_a2;
    s32 temp_a3;

    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x8) = (s16) ((temp_a2 = arg2 & 0xFFFF) << 6);
    temp_a3 = arg3 & 0xFFFF;
    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0xA) = (s16) (temp_a3 << 6);
    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x18) = (s16) (((u16 *)&arg4)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x1A) = (s16) (((u16 *)&arg5)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x28) = (s16) (((u16 *)&arg6)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)arg0 + 0x70) + ((arg1 & 0xFFFF) * 0x10) + 0x2A) = (s16) (((u16 *)&arg7)[1] << 6);
}
