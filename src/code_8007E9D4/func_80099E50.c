#include "common.h"

extern s32 D_800A73E0;
s32 func_800987C0(s32);
s32 func_8009912C(s32 *, s32, s32 *);

s32 func_80099E50(s32 arg0, ...)
{
    s32 buf[32];
    s32 temp_s0;
    s32 *rest;

    *(s32 *)((char *)&D_800A73E0 + 0x6B10) = 0x80;
    *(s32 *)((char *)&D_800A73E0 + 0x6B14) = 1;
    *(s32 **)((char *)&D_800A73E0 + 0x6B1C) = buf;
    *(s32 **)((char *)&D_800A73E0 + 0x6B18) = buf;
    rest = (s32 *)__builtin_next_arg(arg0);
    temp_s0 = func_8009912C(buf, arg0, rest);
    func_800987C0(0);
    return temp_s0;
}
