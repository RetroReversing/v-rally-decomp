typedef struct { u32 w0; u32 w1; } Gfx;

/* Emits the RDP command sequence that loads a texture image (timg, fmt, siz,
 * width x height) into TMEM and sets up its tile descriptor. Appends to the
 * display list at g and returns the new end pointer. */
Gfx *gsn_dp_load_texture_block(Gfx *g, s32 timg, s32 fmt, s32 width, s32 arg4, s32 arg5, s32 siz, s32 arg7, s32 height, s32 pal, s32 cms, s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt)
{
  {
    Gfx *_g = g++;
    _g->w0 = ((fmt & 7) << 21) | 0xFD100000;
    _g->w1 = timg + (siz * width) / 2;
  }
  {
    Gfx *_g = g++;
    _g->w0 = ((fmt & 7) << 21) | 0xF5100000;
    _g->w1 = 0x07000000 | ((cmt & 3) << 18) | ((maskt & 0xF) << 14) | ((shiftt & 0xF) << 10) | ((cms & 3) << 8) | ((masks & 0xF) << 4) | (shifts & 0xF);
  }
  {
    Gfx *_g = g++;
    _g->w0 = 0xE6000000;
    _g->w1 = 0;
  }
  {
    Gfx *_g = g++;
    s32 a, b, c;
    _g->w0 = 0xF3000000;
    a = width / 16;
    b = a > 0 ? a + 0x7FF : 0x800;
    c = ((width * height + 3) >> 2) - 1;
    if (c >= 0x800) c = 0x7FF;
    _g->w1 = ((c & 0xFFF) << 12) | 0x07000000 | ((a > 0 ? b / a : b) & 0xFFF);
  }
  {
    Gfx *_g = g++;
    _g->w0 = 0xE7000000;
    _g->w1 = 0;
  }
  {
    Gfx *_g = g++;
    _g->w0 = ((fmt & 7) << 21) | 0xF5000000 | ((((width >> 1) + 7) >> 3 & 0x1FF) << 9);
    _g->w1 = ((pal & 0xF) << 20) | ((cmt & 3) << 18) | ((maskt & 0xF) << 14) | ((shiftt & 0xF) << 10) | ((cms & 3) << 8) | ((masks & 0xF) << 4) | (shifts & 0xF);
  }
  {
    Gfx *_g = g++;
    _g->w0 = 0xF2000000;
    _g->w1 = ((((width - 1) * 4) & 0xFFF) << 12) | (((height - 1) * 4) & 0xFFF);
  }
  return g;
}
