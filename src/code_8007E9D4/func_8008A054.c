#include "snapshot29_0433f7af8f6d.h"

s32 func_8008A054(void *arg0, s32 arg1) {
    u16 n;
    u8 *q;
    u32 i;
    u32 t0;
    s32 pad[1];
    n = *(u16 *)arg0;
    q = *(u8 **)((u8 *)arg0 + 16);
    i = 0;
    if (n == 0) {
        return 0;
    } else {
        u8 *p;
        arg1 &= 65535;
        t0 = n;
        arg0 = (void *)((u8 *)q + 13);
        do {
            p = (u8 *)arg0;
            if (arg1 < p[-1] + p[0]) {
                return (s32)q;
            }
            arg0 = (void *)(p + 20);
            i++;
            q += 20;
        } while (i < t0);
    }
    (void)&pad;
    return 0;
}
