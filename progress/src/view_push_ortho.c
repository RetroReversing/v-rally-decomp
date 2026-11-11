void *view_get_ctx_id(void *);
s32 gfx_push_mtx(void *, s32);
s32 mtx_pool_alloc();
void guMtxIdent(s32);
void guOrtho(s32, f32, f32, f32, f32, f32, f32, f32);

/* Queues an identity matrix and then an orthographic projection built from the
 * view rectangle (s16 fields at +8, +0xA, +0xC, +0xE) onto the view's display
 * list. Each matrix is pushed with G_MTX (0xDA380003). */
void view_push_ortho(void *view) {
    s32 mtx;
    u32 *dl;
    void *ctx;

    ctx = view_get_ctx_id(view);
    mtx = mtx_pool_alloc();
    guMtxIdent(mtx);
    dl = *(u32 **)((u8 *)ctx + 0x14);
    *(u32 **)((u8 *)ctx + 0x14) = dl + 2;
    dl[0] = 0xDA380003;
    dl[1] = mtx;
    mtx = mtx_pool_alloc();
    guOrtho(mtx, (f32)*(s16 *)((u8 *)view + 8), (f32)*(s16 *)((u8 *)view + 0xC), (f32)*(s16 *)((u8 *)view + 0xE), (f32)*(s16 *)((u8 *)view + 0xA), -1.0f, 10.0f, 1.0f);
    gfx_push_mtx(ctx, mtx);
}
