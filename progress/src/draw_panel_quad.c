extern void *gfx_get_dl(void);
extern void gfx_set_dl(s32, void *);
extern s32 gfx_append_quad(s32, s32);
extern s32 gfx_set_quad_pos(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 gfx_set_quad_colors(s32, s32, s8, s8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
extern s32 gfx_round_vtx_pos(s32);
extern s32 D_800A1798;

/* Draws a coloured HUD panel quad with its top-left corner at (x, y), size w x h.
   Emits a call to the panel's display list, appends the quad, places its four
   corners (the top edge sits 3 units above y), sets the vertex colours, then
   rounds the vertex position up to the next block. */
void draw_panel_quad(s32 ctx, s16 x, s32 y, s32 w, s32 h) {
    s16 top;
    s16 bottom;
    s16 right;
    s32 slot;
    void *dl;

    dl = gfx_get_dl();
    *(s32 *)dl = 0xDE000000;
    *(s32 **)((u8 *)dl + 4) = &D_800A1798;
    gfx_set_dl(ctx, (u8 *)dl + 8);
    slot = gfx_append_quad(ctx, 0) & 0xFFFF;
    top = y - 3;
    right = x + w;
    bottom = top + h;
    gfx_set_quad_pos(ctx, slot, x, top, -4, (s32) x, (s32) bottom, -4, (s32) right, (s32) bottom, -4, (s32) right, (s32) top, -4);
    gfx_set_quad_colors(ctx, slot, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78, 0x1E, 0x32, 0x94, 0x78);
    gfx_round_vtx_pos(ctx);
}
