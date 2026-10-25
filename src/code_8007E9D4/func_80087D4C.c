#include "common.h"

void func_80087988(void *a0, s32 a1);

u8 *func_80087D4C(void *arg0, u8 *arg1) {
    u8 *p;
    u32 v;
    u32 lo;

    p = arg1;
    v = *p;
    p++;
    if (v & 0x80) {
        v = v & 0x7F;
        lo = *p;
        v = v << 8;
        p++;
        v = v | lo;
    }
    func_80087988(arg0, *(s32 *)(*(u8 **)((u8 *)arg0 + 0x70) + 0x10) + v * 7);
    return p;
}
