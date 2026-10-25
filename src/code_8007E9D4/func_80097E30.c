#include "common.h"

s32 func_80097E30(s32 arg0, s32 arg1, u32 arg2)
{
    u32 pat;
    s32 p;
    u32 n;
    s32 words;

    if (arg2 != 0) {
        pat = arg1 & 0xFF;
        pat = pat | (pat << 8);
        pat = pat | (pat << 16);
        p = arg0;
        n = arg2;
        if (p & 1) {
            *((s8 *)p) = pat;
            p += 1;
            n -= 1;
        }
        words = n >> 2;
        if (n >= 2) {
            if (p & 2) {
                *((s16 *)p) = pat;
                p += 2;
                n -= 2;
                words = n >> 2;
            }
        }
        words -= 1;
        if (words != -1) {
            do {
                *((s32 *)p) = pat;
                words -= 1;
                p += 4;
            } while (words != -1);
        }
        if (n & 2) {
            *((s16 *)p) = pat;
            p += 2;
        }
        if (n & 1) {
            *((s8 *)p) = pat;
        }
    }
    return arg0;
}
