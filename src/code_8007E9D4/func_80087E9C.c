#include "common.h"

s32 func_80087E9C(u8 *a, s32 ret) {
    s32 i;
    u8 *t;
    u8 c;
    u8 d;
    s32 *p;
    u16 *q;
    u16 w;
    i = a[0xD3] - 1;
    t = a + i;
    c = t[0x124];
    if (c != 0xFF) {
        d = c - 1;
        t[0x124] = d;
        if (d == 0) {
            a[0xD3] = i;
            i = -1;
        }
    }
    if (i >= 0) {
        p = (s32 *)(i * 4 + (s32)a);
        ret = p[0xD4 / 4];
        *(s32 *)(a + 0x34) = p[0xE8 / 4];
        *(s32 *)(a + 0x30) = p[0xFC / 4];
        a[0xB4] = *(a + i + 0x129);
        *(f32 *)(a + 0x6C) = (f32)*(a + i + 0x12E);
        q = (u16 *)(i * 2 + (s32)a);
        w = q[0x110 / 2];
        *(u16 *)(a + 0x9A) = w;
        *(u16 *)(a + 0x9C) = q[0x11A / 2];
        *(f32 *)(a + 0x20) = *(volatile f32 *)(a + 0x6C) * *(f32 *)(a + 0x68);
    }
    return ret;
}
