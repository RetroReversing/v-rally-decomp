#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u32 w0, w1; } Gfx;
Gfx *func_80006008(s32); void func_80006014(s32, Gfx *);
extern u16 D_8009C02A, D_8009C02E; extern s32 D_8009FF30; extern u8 D_800A73E0[];
void func_80015F3C(s32 arg0){
    Gfx *g;
    s16 x, y;
    g = func_80006008(arg0);
    { Gfx *_g = g++; _g->w0 = 0xF8000000; _g->w1 = (D_800A73E0[0x6bd9]<<24)|(D_800A73E0[0x6bdb]<<16)|(D_800A73E0[0x6bdd]<<8)|D_800A73E0[0x6bdf]; }
    if (D_8009FF30 == 5) {
        x = *(u16*)(D_800A73E0+0x6bd4) + *(u16*)(D_800A73E0+0x6be0);
        if (x > 0x3e4) x = 0x3e4;
        if (x < 0x2bc) x = 0x2bc;
        y = 1000 - (1000 - x) / 10;
        if (y > 0x3e4) y = 0x3e4;
        { Gfx *_g = g++; _g->w0 = 0xdb080000; _g->w1 = ((0x1f400 / (1000 - y)) << 16) | (((0x1f4 - y) << 8) / (1000 - y) & 0xffff); }
    } else {
        Gfx *_g = g++; _g->w0 = 0xdb080000; _g->w1 = (D_8009C02A << 16) | D_8009C02E;
    }
    { Gfx *_g = g++; _g->w0 = 0xfb000000; _g->w1 = (D_800A73E0[0x6be7]<<24)|(D_800A73E0[0x6be9]<<16)|(D_800A73E0[0x6beb]<<8)|D_800A73E0[0x6bed]; }
    func_80006014(arg0, g);
}
