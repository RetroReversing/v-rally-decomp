#include "common.h"

extern s32 D_8009D6B0;

void func_80022F98(s32 *arg0) {
    s32 *a1;
    s32 a0;
    s32 s2;
    s32 *s1;

    a1 = (s32 *)arg0[0];
    arg0[2] &= ~1;
    a0 = *(s32 *)((u8 *)a1 + 0xA0);
    if (a0 != -1) {
        s2 = -1;
        s1 = a1;
        do {
            void (*fn)(void *) = *(void (**)(void *))(*(u8 **)(*(u8 **)arg0 + 0xD0) + a0 * 0x1C + 0x14);
            fn(arg0);
            s1 += 1;
            a0 = *(s32 *)((u8 *)s1 + 0xA0);
            if (a0 == s2) {
                break;
            }
        } while (!(arg0[2] & 1));
    }
    if (arg0[2] & 2) {
        D_8009D6B0 = 0;
        arg0[2] &= ~2;
    }
}
