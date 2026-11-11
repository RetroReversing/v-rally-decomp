typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad[8]; s16 x0, y0, x1, y1; } Vp;
s32 view_get_ctx_id(void *);
Gfx *gfx_get_dl(s32);
void gfx_set_dl(s32, Gfx *);
void gfx_push_mtx(s32, s32);
void gfx_round_vtx_pos(s32);
void gfx_set_quad_pos(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
u16 gfx_append_quad(s32, s32);
void gfx_set_quad_colors_shared_alpha(s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
s32 mtx_pool_alloc();
void guMtxF2L(f32 *, s32);
void guMtxIdent(void *);
void guOrthoF(f32 *, f32, f32, f32, f32, f32, f32, f32);
extern char D_8009B780[];
extern u8 gOrderState[];
/* Fill colour components of the quad at 0x741B (the last one is volatile). */
#define QUAD_RGB (*(volatile u8 *)(gOrderState + 0x741B))

/* Draws a full-screen quad over the viewport vp. Sets an identity matrix, pushes an ortho
 * projection sized to vp, runs the overlay display list D_8009B780, then emits the quad and
 * restores the matrix stack. */
void func_8000F1D4(Vp *vp) {
    f32 ortho_mf[4][4];
    void *ident_mtx;
    s32 ctx;
    s32 mtx_idx;
    u16 quad_idx;
    Gfx *dl;

    ident_mtx = gOrderState + 0x6E30;
    guMtxIdent(ident_mtx);
    ctx = view_get_ctx_id(vp);
    dl = gfx_get_dl(ctx);
    { Gfx *_g = dl++; _g->w0 = 0xDA380003; _g->w1 = (u32)ident_mtx; }
    gfx_set_dl(ctx, dl);
    mtx_idx = mtx_pool_alloc();
    guOrthoF(ortho_mf[0], 0.0f, vp->x1, vp->y1, 0.0f, -1.0f, 10.0f, 1.0f);
    guMtxF2L(ortho_mf[0], mtx_idx);
    gfx_push_mtx(ctx, mtx_idx);
    gfx_round_vtx_pos(ctx);
    dl = gfx_get_dl(ctx);
    { Gfx *_g = dl++; _g->w0 = 0xDE000000; _g->w1 = (u32)D_8009B780; }
    gfx_set_dl(ctx, dl);
    quad_idx = gfx_append_quad(ctx, 0);
    gfx_set_quad_pos(ctx, quad_idx, 0, 0, 0, vp->x1, vp->y0, 0, vp->x1, vp->y1, 0, vp->x0, vp->y1, 0);
    {
        gfx_set_quad_colors_shared_alpha(ctx, quad_idx, gOrderState[0x741B], gOrderState[0x741B], gOrderState[0x741B], QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, QUAD_RGB, *(volatile u8 *)(gOrderState + 0x7419));
    }
    gfx_round_vtx_pos(ctx);
}
