#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad[8]; s16 x0, y0, x1, y1; } Vp;
s32 func_800056FC(void *);
Gfx *func_80006008(s32);
void func_80006014(s32, Gfx *);
void func_800061FC(s32, s32);
void func_80006298(s32);
void func_800068C0(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
u16 func_80006CF8(s32, s32);
void func_800072F4(s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
s32 func_8001BD1C();
void guMtxF2L(f32 *, s32);
void guMtxIdent(void *);
void guOrthoF(f32 *, f32, f32, f32, f32, f32, f32, f32);
extern char D_8009B780[];
extern u8 D_800AE850[];
#define B (*(volatile u8 *)(D_800AE850 + 0x741B))

void func_8000F1D4(Vp *vp) {
    f32 mf[4][4];
    void *mtx;
    s32 ctx;
    s32 m;
    u16 n;
    Gfx *g;

    mtx = D_800AE850 + 0x6E30;
    guMtxIdent(mtx);
    ctx = func_800056FC(vp);
    g = func_80006008(ctx);
    { Gfx *_g = g++; _g->w0 = 0xDA380003; _g->w1 = (u32)mtx; }
    func_80006014(ctx, g);
    m = func_8001BD1C();
    guOrthoF(mf[0], 0.0f, vp->x1, vp->y1, 0.0f, -1.0f, 10.0f, 1.0f);
    guMtxF2L(mf[0], m);
    func_800061FC(ctx, m);
    func_80006298(ctx);
    g = func_80006008(ctx);
    { Gfx *_g = g++; _g->w0 = 0xDE000000; _g->w1 = (u32)D_8009B780; }
    func_80006014(ctx, g);
    n = func_80006CF8(ctx, 0);
    func_800068C0(ctx, n, 0, 0, 0, vp->x1, vp->y0, 0, vp->x1, vp->y1, 0, vp->x0, vp->y1, 0);
    {
        func_800072F4(ctx, n, D_800AE850[0x741B], D_800AE850[0x741B], D_800AE850[0x741B], B, B, B, B, B, B, B, B, B, *(volatile u8 *)(D_800AE850 + 0x7419));
    }
    func_80006298(ctx);
}
