#include "common.h"

extern void func_8008E13C(void *, void *, s32);
extern u8 D_800A3D76;
extern s8 D_800A73E0[];
void func_80098A1C(u8 *arg0, s32 arg1, s32 arg2, s8 *arg3) {
    s32 length;
    s32 offset;
    s8 *dst;
    u8 *src;
    u8 ch;
    length = arg1 - 1;
    offset = arg2;
    dst = arg3;
    src = arg0;
    ch = *src;
    *dst = ch;
    dst++;
    *dst = '.';
    dst++;
    src++;
    func_8008E13C(dst, src, length);
    dst += length;
    if (D_800A73E0[0x6b24] == 0) {
        if (dst[-1] == '0') {
            do { dst--; } while (dst[-1] == '0');
        }
        dst -= (dst[-1] == '.');
    }
    *dst = D_800A3D76;
    dst++;
    if (offset < 0) { offset = -offset; *dst = '-'; }
    else *dst = '+';
    dst++;
    if (offset >= 100) {
        *dst++ = offset / 100 + '0';
        offset %= 100;
    }
    *dst++ = offset / 10 + '0';
    {
        s32 rem = offset % 10;
        offset = rem;
        dst[0] = offset + '0';
        dst[1] = 0;
    }
}
