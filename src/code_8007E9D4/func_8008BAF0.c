#include "checkpoint_common.h"

u32 alHeapDBAlloc(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4)
{
    u32 start;
    u32 end;
    u32 ret;
    u32 size;

    size = ((arg3 * arg4) + 0xF) & -0x10;
    start = arg2[1];
    end = start + size;
    ret = 0;
    if (arg2[0] + arg2[2] >= end) {
        ret = start;
        arg2[1] = end;
    }
    return ret;
}
