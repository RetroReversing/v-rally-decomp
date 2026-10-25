#include "common.h"

extern s32 D_800C816C;
extern s8 D_800C3520;

typedef struct {
    s8 a;
    s8 b;
    s8 c;
    s8 d;
    s8 e;
    s8 f;
} Pack6;

void func_8009750C(s32 arg0) {
    s32 i;
    Pack6 buf;
    Pack6 *p;
    s32 *q;
    u8 k;
    s8 pad[8];

    q = &D_800C816C;
    p = (Pack6 *)((s8 *)q - 0x3C);
    i = 0;
    *q = 1;
    buf.a = 1;
    buf.b = 3;
    D_800C3520 = 0;
    buf.c = 0;
    k = 0xFF;
    buf.d = k;
    buf.e = k;
    buf.f = k;
    if (arg0 > 0) {
        do {
            *(s8 *)p = 0;
            i++;
            p = (Pack6 *)((s8 *)p + 1);
        } while (i < arg0);
    }
    *p = buf;
    ((u8 *)p)[6] = 0xFE;
}
