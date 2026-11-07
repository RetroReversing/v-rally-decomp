#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 pad0[4]; u8 r, g, b; } Col;
typedef struct { u8 start, count; } Rng;
typedef struct { u8 p0[0xD0]; Rng rng[1]; u8 p1[0x14-0+0]; } GX;
typedef struct { u8 p[0xA]; s8 idx; u8 q; u8 t; u8 s; u8 r; u8 pad; f32 w10; f32 f14; u16 h18; } Arg;
extern u8 *D_800A1468;
extern struct { u8 p[4]; s16 w; } *D_8009B5A4;
extern u8 D_800A73E0[];
s32 func_800056FC(void *);
void func_8000C22C(void *, s32, s32, s32, u8);
s32 func_8000C9B0(void *, void *, u8, f32, u8);
u16 func_8000CC04(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
#define RNG(g, a) ((Rng *)((g) + (s16)(((Arg *)(a))->idx * 2) + 0xD0))
#define COL(g, i) (*(Col **)((g) + (i) * 4 + 0xE4))
void func_800596F4(void *arg0, s16 arg1, s16 arg2, void *arg3) {
    u8 i;
    u8 r = 0, g = 0, b = 0;
    if (arg1 == 0x7FFF) {
        Rng *rg = RNG(D_800A1468, arg0);
        s16 w = func_8000C9B0((void *)(D_800A1468 + (rg->start * 4 + 0xE4)), (void *)(arg3), (u8)(rg->count), (f32)(((Arg *)arg0)->w10), (u8)(0));
        if (D_8009B5A4->w == 0x280) { u32 u = D_8009B5A4->w - w; arg1 = (s16)((u + (u >> 31)) >> 1); }
        else { u32 u = 0x140 - w; arg1 = (s16)((u + (u >> 31)) >> 1); }
    }
    if (D_800A1468[0x24D] != 0) {
        Rng *rg = RNG(D_800A1468, arg0);
        Col *c;
        c = COL(D_800A1468, rg->start);
        i = rg->start;
        r = c->r; g = c->g; b = c->b;
        while (i < RNG(D_800A1468, arg0)->start + RNG(D_800A1468, arg0)->count) {
            func_8000C22C((void *)(COL(D_800A1468, i)), (s32)(r >> 3), (s32)(g >> 3), (s32)(b >> 3), (u8)(((Arg *)arg0)->r));
            i++;
        }
    }
    func_8000CC04((void *)(D_800A1468 + (RNG(D_800A1468, arg0)->start * 4 + 0xE4)), (void *)(func_800056FC((void *)(*(s32*)(D_800A73E0+0x6ba0)))), (s16)(arg1), (s16)(arg2), (void *)(arg3), (u8)(RNG(D_800A1468, arg0)->count), (f32)(((Arg *)arg0)->w10), (f32)(((Arg *)arg0)->f14), (u16)(((Arg *)arg0)->h18), (u8)(0));
    if (D_800A1468[0x24D] != 0) {
        i = RNG(D_800A1468, arg0)->start;
        while (i < RNG(D_800A1468, arg0)->start + RNG(D_800A1468, arg0)->count) {
            func_8000C22C((void *)(COL(D_800A1468, i)), (s32)(r), (s32)(g), (s32)(b), (u8)(((Arg *)arg0)->r));
            i++;
        }
    }
}

