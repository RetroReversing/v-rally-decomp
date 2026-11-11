s32 view_get_ctx_id();
void *gfx_get_dl();
s32 gfx_set_dl();
s32 gfx_round_vtx_pos();
s32 gfx_set_quad_pos();
s32 gfx_append_quad();
s32 gfx_set_quad_colors();
extern char D_800A03E0[];

/* Draws one quad described by `quad`: sets the texture state, then sends its vertex
   positions and vertex colours to the display list. */
void func_8004C370(s32 unused, void *quad)
{
    s32 slot;
    s32 ctx;
    void *gfx;

    ctx = view_get_ctx_id();
    gfx = gfx_get_dl(ctx);
    *(s32 *)((char *)gfx + 0) = 0xDE000000;
    *(s32 * *)((char *)gfx + 4) = &D_800A03E0;
    gfx_set_dl(ctx, gfx + 8);
    slot = gfx_append_quad(ctx, 0) & 0xFFFF;
    gfx_set_quad_pos(ctx, slot, *(s16 *)((char *)quad + 0x12), *(s16 *)((char *)quad + 0x22), (s32) *(s16 *)((char *)quad + 0x32), (s32) *(s16 *)((char *)quad + 0x16), (s32) *(s16 *)((char *)quad + 0x26), (s32) *(s16 *)((char *)quad + 0x36), (s32) *(s16 *)((char *)quad + 0x1A), (s32) *(s16 *)((char *)quad + 0x2A), (s32) *(s16 *)((char *)quad + 0x3A), (s32) *(s16 *)((char *)quad + 0x1E), (s32) *(s16 *)((char *)quad + 0x2E), (s32) *(s16 *)((char *)quad + 0x3E));
    gfx_set_quad_colors(ctx, slot, *(u8 *)((char *)quad + 0x40), *(u8 *)((char *)quad + 0x44), (s32) *(u8 *)((char *)quad + 0x48), (s32) *(u8 *)((char *)quad + 0x4C), (s32) *(u8 *)((char *)quad + 0x41), (s32) *(u8 *)((char *)quad + 0x45), (s32) *(u8 *)((char *)quad + 0x49), (s32) *(u8 *)((char *)quad + 0x4D), (s32) *(u8 *)((char *)quad + 0x42), (s32) *(u8 *)((char *)quad + 0x46), (s32) *(u8 *)((char *)quad + 0x4A), (s32) *(u8 *)((char *)quad + 0x4E), (s32) *(u8 *)((char *)quad + 0x43), (s32) *(u8 *)((char *)quad + 0x47), (s32) *(u8 *)((char *)quad + 0x4B), (s32) *(u8 *)((char *)quad + 0x4F));
    gfx_round_vtx_pos(ctx);
}
