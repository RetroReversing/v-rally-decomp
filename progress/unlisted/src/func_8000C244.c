#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
typedef struct { u32 w0, w1; } Gfx;
#define gDma(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (u32)(b); }
typedef struct { u8 pad0[0x14]; Gfx *dl; } GfxCtx;
typedef struct { u8 pad0[8]; void *img; s32 w; s32 h; } FontTex;
typedef struct { s16 id; s16 pad2; u8 w; u8 h; s8 xoff; s8 yoff; s8 adv; u8 pad9[7]; } Glyph;
typedef struct { s16 u[4]; s16 v[4]; } GlyphUV;
typedef struct {
  u8 pad0[4];
  u8 r, g, b, a;
  u8 spacing;
  u8 pad9[7];
  FontTex *tex;
  u8 pad14[4];
  Glyph *glyphs;
  GlyphUV uv[128];
  f32 sx;
  f32 sy;
} Font;
extern s32 gSelectStep;
extern u32 D_8009B618[];
extern u32 D_8009B680[];
extern f64 D_800A3F10;
extern f64 D_800A3F18;
s32 dl_reserve_vertices(GfxCtx *, s32);
void gfx_set_quad_pos(GfxCtx *, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32);
void func_80008B28(GfxCtx *, s32, u16, u16, u16, u16, u16, u16, u16, u16);
s32 str_len(u8 *);
s32 osVirtualToPhysical(void *);

u16 func_8000C244(Font *font, GfxCtx *ctx, u32 x0, u32 y0, u8 *str, u8 mode)
{
  s32 kern;
  s32 x;
  s32 y;
  s32 bias;
  s32 len;
  s32 i;
  u8 ch;
  s32 vtx;
  f32 fx;
  Glyph *gl;
  u8 first;
  u8 dec;

  kern = 0;
  if (x0 > 320 || y0 > 240)
  {
    return 0;
  }
  {
  GfxCtx *c = ctx;
  Font *f = font;
#define font f
  if (mode == 0)
  {
    dec = 1;
    gDma(c->dl++, 0xDE000000, D_8009B680);
  }
  else if (mode == 1)
  {
    dec = 2;
    gDma(c->dl++, 0xDE000000, D_8009B618);
  }
  else if (mode == 2)
  {
    dec = 2;
    gDma(c->dl++, 0xDE000000, D_8009B680);
  }
  else
  {
    dec = 1;
  }
  gDma(c->dl++, 0xFA000000, (font->r << 24) | (font->g << 16) | (font->b << 8) | font->a);
  gDma(c->dl++, 0xFD900000, osVirtualToPhysical(font->tex->img));
  gDma(c->dl++, 0xF5900000, 0x07080200);
  gDma(c->dl++, 0xE6000000, 0);
  gDma(c->dl++, 0xF3000000, _SHIFTL(7, 24, 3) | _SHIFTL(MIN((((font->tex->w * font->tex->h) + 3) >> 2) - 1, 0x7FF), 12, 12)
        | _SHIFTL(((1 << 11) + MAX(1, font->tex->w / 16) - 1) / MAX(1, font->tex->w / 16), 0, 12));
  gDma(c->dl++, 0xE7000000, 0);
  gDma(c->dl++, _SHIFTL(0xF5, 24, 8) | _SHIFTL(4, 21, 3) | _SHIFTL(0, 19, 2) | _SHIFTL(((font->tex->w >> 1) + 7) >> 3, 9, 9), 0x80200);
  x = x0;
  bias = 0;
  first = 1;
  gDma(c->dl++, 0xF2000000, _SHIFTL((font->tex->w - 1) << 2, 12, 12) | _SHIFTL((font->tex->h - 1) << 2, 0, 12));
  len = str_len(str);
  for (i = 0; i < len; i++, x += font->spacing)
  {
    ch = str[i];
    ch -= 0x20;
    if (ch != 0)
    {
      if (font->glyphs[ch].id != -0x80)
      {
        if (first)
        {
          bias = font->glyphs[ch].yoff * font->sy;
          first = 0;
          if (gSelectStep == 3 && (ch == 3 || ch == 4 || ch == 6))
          {
            bias = bias - (font->sy * 3.0f - D_800A3F10);
          }
        }
        y = bias - (font->glyphs[ch].yoff * font->sy + D_800A3F18) + (f64) y0;
        x += font->glyphs[ch].xoff + kern - dec;
        vtx = ((u16 (*)(GfxCtx *, s32))dl_reserve_vertices)(ctx, 4);
        fx = x;
        gfx_set_quad_pos(ctx, vtx, x, (f32) y + font->glyphs[ch].h * font->sy, 0,
                      fx + font->glyphs[ch].w * font->sx, (f32) y + font->glyphs[ch].h * font->sy, 0,
                      fx + font->glyphs[ch].w * font->sx, y, 0, x, y, 0);
        func_80008B28(ctx, vtx, font->uv[ch].u[0] * 2, font->uv[ch].v[0] * 2,
                      font->uv[ch].u[1] * 2, font->uv[ch].v[1] * 2,
                      font->uv[ch].u[2] * 2, font->uv[ch].v[2] * 2,
                      font->uv[ch].u[3] * 2, font->uv[ch].v[3] * 2);
        gDma(c->dl++, (_SHIFTL((vtx & 31) * 2, 16, 8) | _SHIFTL(((vtx & 31) + 1) * 2, 8, 8) | _SHIFTL(((vtx & 31) + 2) * 2, 0, 8)) | _SHIFTL(0x07, 24, 8),
             _SHIFTL((vtx & 31) * 2, 16, 8) | _SHIFTL(((vtx & 31) + 2) * 2, 8, 8) | _SHIFTL(((vtx & 31) + 3) * 2, 0, 8));
        x = fx + font->glyphs[ch].w * font->sx;
        kern = font->glyphs[ch].adv;
      }
    }
    else
    {
      x = (f32) x + font->glyphs[0].w * font->sx;
    }
  }
  return x - x0 - font->spacing;
  }
}
