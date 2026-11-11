s32 view_get_ctx_id();
s32 gfx_get_dl(s32);
void gfx_set_dl(s32, s32);
void func_8000E844(s32 *);

/* Gets the current view's context id and its display-list pointer, lets func_8000E844 update the pointer, then stores it back. */
void view_gfx_setup(void) {
    s32 dl;
    s32 ctxId;

    ctxId = view_get_ctx_id();
    dl = gfx_get_dl(ctxId);
    func_8000E844(&dl);
    gfx_set_dl(ctxId, dl);
}
