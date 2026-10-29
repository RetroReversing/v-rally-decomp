#include "snapshot29_0433f7af8f6d.h"

typedef struct { u8 pad0[4]; u8 r, g, b; } Col;
typedef struct { u8 start, count; } Rng;
typedef struct { u8 p0[0xD0]; Rng rng[1]; u8 p1[0x14-0+0]; } GX;
typedef struct { u8 p[0xA]; s8 idx; u8 q; u8 t; u8 s; u8 r; u8 pad; f32 w10; f32 f14; u16 h18; } Arg;
extern u8 *D_800A1468;
extern struct { u8 p[4]; s16 w; } *D_8009B5A4;
extern u8 D_800A73E0[];
s32 func_800056FC(s32);
s32 func_8000C22C();
s32 func_8000C9B0(void *, s32, u8, f32, s32);
s32 func_8000CC04(void *, s32, s16, s16, s32, s32, f32, f32, s32, s32);
#define RNG(g, a) ((Rng *)((g) + (s16)((a)->idx * 2) + 0xD0))
#define COL(g, i) (*(Col **)((g) + (i) * 4 + 0xE4))
void func_800596F4(Arg *arg0, s16 arg1, u16 arg2, s32 arg3) {
    u8 i;
    u8 r = 0, g = 0, b = 0;
    if (arg1 == 0x7FFF) {
        Rng *rg = RNG(D_800A1468, arg0);
        s16 w = func_8000C9B0(D_800A1468 + (rg->start * 4 + 0xE4), arg3, rg->count, arg0->w10, 0);
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
            func_8000C22C(COL(D_800A1468, i), r >> 3, g >> 3, b >> 3, arg0->r);
            i++;
        }
    }
    func_8000CC04(D_800A1468 + (RNG(D_800A1468, arg0)->start * 4 + 0xE4), func_800056FC(*(s32*)(D_800A73E0+0x6ba0)), arg1, arg2, arg3, RNG(D_800A1468, arg0)->count, arg0->w10, arg0->f14, arg0->h18, 0);
    if (D_800A1468[0x24D] != 0) {
        i = RNG(D_800A1468, arg0)->start;
        while (i < RNG(D_800A1468, arg0)->start + RNG(D_800A1468, arg0)->count) {
            func_8000C22C(COL(D_800A1468, i), r, g, b, arg0->r);
            i++;
        }
    }
}
