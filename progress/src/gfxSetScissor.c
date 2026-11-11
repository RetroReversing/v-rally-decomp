s32 view_get_ctx_id();
void *gfx_get_dl();
s32 gfx_set_dl();

/* Appends an F3D G_SETSCISSOR command to the view's display list. rect holds
   ulx, uly, lrx, lry in pixels; each is stored as 10.2 fixed point (x4). */
void gfxSetScissor(s32 view, s16 *rect)
{
    s32 ctx;
    s32 *dl;
    s32 w0;
    s32 w1;

    ctx = view_get_ctx_id(view);
    dl = gfx_get_dl(ctx);
    w0 = (((s32)(rect[0] * 4.0f)) & 0xFFF) << 12;
    w1 = (((s32)(rect[1] * 4.0f)) & 0xFFF) | 0xED000000;
    dl[0] = w0 | w1;
    dl[1] = ((((s32)(rect[2] * 4.0f)) & 0xFFF) << 12) | (((s32)(rect[3] * 4.0f)) & 0xFFF);
    gfx_set_dl(ctx, dl + 2);
}
