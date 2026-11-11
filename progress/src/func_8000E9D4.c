typedef struct A1564
{
  u16 x0;
  u16 y0;
  s16 width;
  s16 height;
} A1564;
s32 view_get_ctx_id();
s32 *gfx_get_dl(s32);
s32 gfx_set_dl(s32, s32 *);
s32 osVirtualToPhysical(s32);

/* Appends a fill-rectangle to the display list: sets the fill colour from the RGB bytes in
 * color, points the image at addr, then fills the rect (x0, y0, width, height) with it. */
void func_8000E9D4(s32 arg0, s32 addr, A1564 *rect, u8 *color)
{
  s32 *gfx;
  s32 *cmd0;
  s32 *cmd1;
  s32 *cmd2;
  s32 *cmd3;
  s32 *cmd4;
  s32 *cmd5;
  s32 temp_s6;
  s32 packed;
  s32 temp_v0;
  s32 temp_v1;

  temp_s6 = view_get_ctx_id();
  gfx = gfx_get_dl(temp_s6);
  cmd0 = gfx;
  gfx += 2;
  cmd1 = gfx;
  gfx += 2;
  cmd0[0] = 0xE7000000;
  cmd0[1] = 0;
  cmd1[0] = 0xE3000A01;
  cmd1[1] = 0x300000;
  cmd2 = gfx;
  gfx += 2;
  cmd2[0] = ((rect->width - 1) & 0xFFF) | 0xFF100000;
  cmd2[1] = osVirtualToPhysical(addr);
  cmd3 = gfx;
  gfx += 2;
  cmd3[0] = 0xF7000000;
  packed = (((color[0] << 8) & 0xF800) | ((color[1] * 8) & 0x7C0)) | ((color[2] >> 2) & 0x3E);
  cmd3[1] = ((packed | 1) << 16) | (1 | packed);
  cmd4 = gfx;
  gfx += 2;
  temp_v1 = ((rect->width - 1) & 0x3FF) << 14;
  temp_v0 = ((rect->height - 1) & 0x3FF) * 4;
  temp_v0 = temp_v0 | 0xF6000000;
  cmd4[0] = temp_v1 | temp_v0;
  cmd4[1] = ((rect->x0 & 0x3FF) << 14) | ((rect->y0 & 0x3FF) * 4);
  cmd5 = gfx;
  gfx += 2;
  cmd5[0] = 0xE7000000;
  cmd5[1] = 0;
  gfx_set_dl(temp_s6, gfx);
}
