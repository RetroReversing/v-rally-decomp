#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#ifdef PORT
typedef struct { uintptr_t w0, w1; } Gfx;
#else
typedef struct { u32 w0, w1; } Gfx;
#endif
#ifdef PORT
#define gDma(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (uintptr_t)(b); }
#else
#define gDma(pkt, a, b) { Gfx *_g = (Gfx *)(pkt); _g->w0 = (a); _g->w1 = (u32)(b); }
#endif
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
extern u32 font_dl_mode1[];
extern u32 font_dl_mode0[];
extern f64 D_800A3F10;
extern f64 D_800A3F18;
s32 dl_reserve_vertices(GfxCtx *, s32);
void gfx_set_quad_pos(GfxCtx *, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32);
void gfx_set_quad_uv(GfxCtx *, s32, u16, u16, u16, u16, u16, u16, u16, u16);
s32 str_len(u8 *);
s32 osVirtualToPhysical(void *);

/* Draws a string as textured glyph quads into the display list (with a shadow pass per mode) and returns the pixel width of the text. */
u16 font_draw_text(Font *font, GfxCtx *ctx, u32 x0, u32 y0, u8 *str, u8 mode)
{
  s32 prev_adv;
  s32 pen_x;
  s32 glyph_y;
  s32 baseline_bias;
  s32 text_len;
  s32 idx;
  u8 code;
  s32 vtx0;
  f32 glyph_x;
  u8 first_glyph;
  u8 shadow_px;

  prev_adv = 0;
  if (x0 > 320 || y0 > 240)
  {
    return 0;
  }
  {
  GfxCtx *out = ctx;
  Font *fnt = font;
#define font fnt
  if (mode == 0)
  {
    shadow_px = 1;
    gDma(out->dl++, 0xDE000000, font_dl_mode0);
  }
  else if (mode == 1)
  {
    shadow_px = 2;
    gDma(out->dl++, 0xDE000000, font_dl_mode1);
  }
  else if (mode == 2)
  {
    shadow_px = 2;
    gDma(out->dl++, 0xDE000000, font_dl_mode0);
  }
  else
  {
    shadow_px = 1;
  }
  gDma(out->dl++, 0xFA000000, (font->r << 24) | (font->g << 16) | (font->b << 8) | font->a);
  gDma(out->dl++, 0xFD900000, osVirtualToPhysical(font->tex->img));
  gDma(out->dl++, 0xF5900000, 0x07080200);
  gDma(out->dl++, 0xE6000000, 0);
  gDma(out->dl++, 0xF3000000, _SHIFTL(7, 24, 3) | _SHIFTL(MIN((((font->tex->w * font->tex->h) + 3) >> 2) - 1, 0x7FF), 12, 12)
        | _SHIFTL(((1 << 11) + MAX(1, font->tex->w / 16) - 1) / MAX(1, font->tex->w / 16), 0, 12));
  gDma(out->dl++, 0xE7000000, 0);
  gDma(out->dl++, _SHIFTL(0xF5, 24, 8) | _SHIFTL(4, 21, 3) | _SHIFTL(0, 19, 2) | _SHIFTL(((font->tex->w >> 1) + 7) >> 3, 9, 9), 0x80200);
  pen_x = x0;
  baseline_bias = 0;
  first_glyph = 1;
  gDma(out->dl++, 0xF2000000, _SHIFTL((font->tex->w - 1) << 2, 12, 12) | _SHIFTL((font->tex->h - 1) << 2, 0, 12));
  text_len = str_len(str);
  for (idx = 0; idx < text_len; idx++, pen_x += font->spacing)
  {
    code = str[idx];
    code -= 0x20;
    if (code != 0)
    {
      if (font->glyphs[code].id != -0x80)
      {
        if (first_glyph)
        {
          baseline_bias = font->glyphs[code].yoff * font->sy;
          first_glyph = 0;
          if (gSelectStep == 3 && (code == 3 || code == 4 || code == 6))
          {
            baseline_bias = baseline_bias - (font->sy * 3.0f - D_800A3F10);
          }
        }
        glyph_y = baseline_bias - (font->glyphs[code].yoff * font->sy + D_800A3F18) + (f64) y0;
        pen_x += font->glyphs[code].xoff + prev_adv - shadow_px;
        vtx0 = ((u16 (*)(GfxCtx *, s32))dl_reserve_vertices)(ctx, 4);
        glyph_x = pen_x;
        gfx_set_quad_pos(ctx, vtx0, pen_x, (f32) glyph_y + font->glyphs[code].h * font->sy, 0,
                      glyph_x + font->glyphs[code].w * font->sx, (f32) glyph_y + font->glyphs[code].h * font->sy, 0,
                      glyph_x + font->glyphs[code].w * font->sx, glyph_y, 0, pen_x, glyph_y, 0);
        gfx_set_quad_uv(ctx, vtx0, font->uv[code].u[0] * 2, font->uv[code].v[0] * 2,
                      font->uv[code].u[1] * 2, font->uv[code].v[1] * 2,
                      font->uv[code].u[2] * 2, font->uv[code].v[2] * 2,
                      font->uv[code].u[3] * 2, font->uv[code].v[3] * 2);
        gDma(out->dl++, (_SHIFTL((vtx0 & 31) * 2, 16, 8) | _SHIFTL(((vtx0 & 31) + 1) * 2, 8, 8) | _SHIFTL(((vtx0 & 31) + 2) * 2, 0, 8)) | _SHIFTL(0x07, 24, 8),
             _SHIFTL((vtx0 & 31) * 2, 16, 8) | _SHIFTL(((vtx0 & 31) + 2) * 2, 8, 8) | _SHIFTL(((vtx0 & 31) + 3) * 2, 0, 8));
        pen_x = glyph_x + font->glyphs[code].w * font->sx;
        prev_adv = font->glyphs[code].adv;
      }
    }
    else
    {
      pen_x = (f32) pen_x + font->glyphs[0].w * font->sx;
    }
  }
  return pen_x - x0 - font->spacing;
  }
}
