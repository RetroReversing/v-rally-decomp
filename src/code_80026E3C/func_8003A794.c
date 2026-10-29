#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800C7F84;
s32 func_80034FF0();
u8 *func_80040260();
extern void func_8003A73C();

void func_8003A794(s32 arg0, s32 arg1, s16 arg2, void *arg3, u8 *arg4, u16 arg5, u8 *arg6) {
    u32 i;
    u8 *o;
    s32 ret, d;
    for (i = 0; i < 5; i++) {
        o = func_80040260(arg0, (s16)arg1, (s16)arg2, 2, arg3, 0);
        *(u16 *)(o + 0x78) = i;
        ret = func_80034FF0(arg4 + 0x4C, 0);
        d = D_800C7F84;
        arg1 += 7;
        *(s32 *)(o + 0xA4) = ret;
        *(u16 *)(o + 0x76) = arg5;
        *(s32 *)(o + 0xA8) = d;
        if (arg6 != 0) { o[0x90] = arg6[0]; o[0x91] = arg6[1]; o[0x92] = arg6[2]; o[0x93] = arg6[3]; }
        if (i == 0) {
            o = func_80040260(arg0, (s16)arg1, (s16)arg2, 2, func_8003A73C, 0);
            ret = func_80034FF0(arg4 + 0x4C, 0);
            d = D_800C7F84;
            arg1 += 4;
            *(s32 *)(o + 0xA4) = ret;
            *(u16 *)(o + 0x76) = arg5;
            *(s16 *)(o + 0x7A) = 0xD;
            *(s32 *)(o + 0xA8) = d;
            if (arg6 != 0) { o[0x90] = arg6[0]; o[0x91] = arg6[1]; o[0x92] = arg6[2]; o[0x93] = arg6[3]; }
        }
        if (i == 2) {
            o = func_80040260(arg0, (s16)arg1, (s16)arg2, 2, func_8003A73C, 0);
            ret = func_80034FF0(arg4 + 0x4C, 0);
            d = D_800C7F84;
            arg1 += 5;
            *(s32 *)(o + 0xA4) = ret;
            *(u16 *)(o + 0x76) = arg5;
            *(s16 *)(o + 0x7A) = 0xC;
            *(s32 *)(o + 0xA8) = d;
            if (arg6 != 0) { o[0x90] = arg6[0]; o[0x91] = arg6[1]; o[0x92] = arg6[2]; o[0x93] = arg6[3]; }
        }
    }
}
