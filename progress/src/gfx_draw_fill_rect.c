typedef struct A1564
{
  u16 unk0;
  u16 unk2;
  s16 unk4;
  s16 unk6;
} A1564;
s32 view_get_ctx_id();
s32 *gfx_get_dl(s32);
s32 gfx_set_dl(s32, s32 *, s32 *, s32 *);

/* Appends an RDP fill rectangle to the view's display list: pipe sync, fill
   mode and colour from the 3-byte RGB value, then the rectangle from rect
   (x0, y0, width-1, height-1). arg0 is unused. */
void gfx_draw_fill_rect(s32 arg0, A1564 *rect, u8 *rgb)
{
  s32 *d0;
  s32 *d1;
  s32 *d2;
  s32 *d3;
  s32 *d4;
  s32 *d5;
  s32 *gfx;
  s32 ctx_id;
  s32 color;
  s32 temp_v1;
  s32 temp_a0;
  ctx_id = view_get_ctx_id();
  gfx = gfx_get_dl(ctx_id);
  d0 = gfx;
  gfx += 2;
  d1 = gfx;
  gfx += 2;
  d0[0] = 0xE7000000;
  d0[1] = 0;
  d1[1] = 0x300000;
  d1[0] = 0xE3000A01;
  d2 = gfx;
  gfx += 2;
  d2[0] = 0xF7000000;
  color = (((rgb[0] << 8) & 0xF800) | ((rgb[1] * 8) & 0x7C0)) | ((rgb[2] >> 2) & 0x3E);
  d3 = gfx;
  gfx += 2;
  d2[1] = ((color | 1) << 16) | (1 | color);
  d4 = gfx;
  gfx += 2;
  temp_a0 = ((rect->unk4 - 1) & 0x3FF) << 14;
  temp_v1 = (((rect->unk6 - 1) & 0x3FF) * 4) | 0xF6000000;
  color = temp_a0 | temp_v1;
  d3[0] = color;
  d3[1] = ((rect->unk0 & 0x3FF) << 14) | ((rect->unk2 & 0x3FF) * 4);
  d4[0] = 0xE7000000;
  d4[1] = 0;
  d5 = gfx;
  d5[0] = 0xE3000A01;
  d5[1] = 0;
  gfx_set_dl(ctx_id, d5 + 2, d4, d3);
}
