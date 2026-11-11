s32 view_get_ctx_id(void *);
void *gfx_get_dl(s32);
void gfx_set_dl(s32, void *);
void gfx_push_mtx(s32, s32);
s32 mtx_pool_alloc(void);
void func_8004A0A0(void);
void func_8004AFB8(void);
void guMtxF2L(void *, s32);
void guMtxIdent(void *);
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern char gStreamState[];
extern void *g_camera;

/* Builds the 2D orthographic projection for the current view and queues it on the display list: identity matrix, orthographic matrix, then the two draw steps that follow. */
void func_8004BEB4(void) {
    s32 ortho[16];
    void *ident_mtx;
    s32 proj_mtx;
    s32 ctx;
    s32 *dl;
    void *view;

    ident_mtx = gStreamState + 0x80D2;
    guMtxIdent(ident_mtx);
    ctx = view_get_ctx_id(*(void **)((char *)g_camera + 0x178));
    dl = gfx_get_dl(ctx);
    dl[0] = 0xDA380003;
    dl[1] = (s32)ident_mtx;
    gfx_set_dl(ctx, dl + 2);
    proj_mtx = mtx_pool_alloc();
    view = *(void **)((char *)g_camera + 0x178);
    guOrthoF(ortho, (f32)*(s16 *)((char *)view + 8), (f32)*(s16 *)((char *)view + 0xC), (f32)*(s16 *)((char *)view + 0xE), (f32)*(s16 *)((char *)view + 0xA), -1.0f, 10.0f, 1.0f);
    guMtxF2L(ortho, proj_mtx);
    gfx_push_mtx(view_get_ctx_id(*(void **)((char *)g_camera + 0x178)), proj_mtx);
    func_8004A0A0();
    func_8004AFB8();
}
