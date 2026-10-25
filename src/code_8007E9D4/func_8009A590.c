#include "common.h"

f64 func_8009A590(f64 arg0, void *arg2) {
    s32 exp;
    s32 e;
    s32 t;
    s32 idx;
    u8 *p;
    u8 *q;

    *(f64 *)arg2 = arg0;
    exp = (*(u32 *)arg2 >> 20) & 0x7FF;
    e = exp - 0x3FF;
    if (e < 0) {
        *(f64 *)arg2 = 0.0;
        return arg0;
    }
    if (e >= 0x34) {
        *(f64 *)arg2 = arg0;
        return 0.0;
    }
    t = exp - 0x3F3;
    idx = t >> 3;
    p = (u8 *)arg2 + idx;
    *p &= 0xFF << (8 - (t & 7));
    if (idx < 7) {
        q = p;
        do {
            q++;
            *q = 0;
        } while ((s32)q < (s32)((u8 *)arg2 + 7));
    }
    return arg0 - *(f64 *)arg2;
}
