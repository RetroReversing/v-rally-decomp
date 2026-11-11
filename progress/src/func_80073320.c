void *gfx_get_dl();
s32 gfx_set_dl();
s32 gfx_round_vtx_pos();
s32 gfx_set_quad_pos();
s32 gfx_append_quad();
s32 gfx_set_quad_colors();
extern char D_800A1798[];

/* Draws a 20x50 (approx.) panel quad at (x, y) offset by (w, h) with a fixed colour
   gradient, after setting the texture state. */
void func_80073320(s32 ctx, s32 x, s32 y, s32 w, s32 h)
{
  s16 x0;
  s16 x1;
  s16 y0;
  s16 y1;
  s32 slot;
  void *gfx;
  gfx = gfx_get_dl();
  *((s32 *) (((char *) gfx) + 0)) = 0xDE000000;
  *((s32 **) (((char *) gfx) + 4)) = &D_800A1798;
  gfx_set_dl(ctx, gfx + 8);
  x0 = x - 0x14;
  slot = gfx_append_quad(ctx, 0) & 0xFFFF;
  y0 = y - 3;
  x1 = (x0 + w) + 0x14;
  y1 = y0 + h;
  gfx_set_quad_pos(ctx, slot, x0, y0, -4, (s32) x0, (s32) y1, -4, (s32) x1, (s32) y1, -4, (s32) x1, (s32) y0, -4);
  gfx_set_quad_colors(ctx, slot, 0x1E, 0x32, 0x94, 0, 0x1E, 0x32, 0x94, 0, 0x1E, 0x32, 0x94, 0xC8, 0x1E, 0x32, 0x94, 0xC8);
  gfx_round_vtx_pos(ctx);
}
