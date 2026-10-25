#include "common.h"

void func_8000DBC0(char *arg0)
{
    s32 t;
    u16 v;
    s32 flags;

    t = (*((s32 *)(arg0 + 0x14)) - *((s32 *)(arg0 + 0x10))) >> 3;
    if (*((u16 *)(arg0 + 4)) < t) {
        *((u16 *)(arg0 + 4)) = t;
    }
    v = *((u16 *)(arg0 + 0x7A));
    if (*((u16 *)(arg0 + 6)) < v) {
        *((u16 *)(arg0 + 6)) = v;
    }
    *((s32 *)(arg0 + 8)) = 0;
    *((u16 *)(arg0 + 0x7A)) = 0;
    *((u16 *)(arg0 + 0x78)) = 0;
    *((s32 *)(arg0 + 0x7C)) = 0;
    *((s32 *)(arg0 + 0x80)) = 0;
    *((s32 *)(arg0 + 0x18)) = 0;
    flags = *((s32 *)(arg0 + 0x84)) | 0x80000000;
    flags &= 0x87FFFFFF;
    flags |= 0x08000000;
    flags |= 0x04000000;
    flags &= 0xFCFFFFFF;
    flags &= 0xFF3FFFFF;
    flags |= 0x00400000;
    *((s32 *)(arg0 + 0x84)) = flags;
    *((s32 *)(arg0 + 0x14)) = *((s32 *)(arg0 + 0x10));
}
