typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x14]; Gfx *gfx; } GfxState;
typedef struct { u8 pad0[8]; void *addr; s32 width; s32 height; } TexInfo;
typedef struct {
    s16 code;
    s16 pad2;
    u8 w;
    u8 h;
    s8 k6;
    s8 k7;
    s8 k8;
    u8 pad9[7];
} Glyph;
typedef struct {
    u8 pad0[4];
    u8 r, g, b, a;
    u8 adv;
    u8 pad9[7];
    TexInfo *tex;
    u8 pad14[4];
    Glyph *glyphs;
    s16 uv[1][8];
} Font;

extern s32 str_len(u8 *);
extern void func_8008E3A0(char *, s32);
extern char D_800A3F28[];
extern u8 stream_state[];
extern u8 font_dl_mode0[];
extern u8 font_dl_mode1[];
extern u32 osVirtualToPhysical(void *);
extern void guRotateF(f32 *m, f32 a, f32 x, f32 y, f32 z);
extern void vec3_transform_mtx3(f32 *m, f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz);
extern s32 dl_reserve_vertices(GfxState *, s32);
extern void gfx_set_quad_pos(GfxState *, u16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16);
extern void gfx_set_quad_uv(GfxState *, u16, u16, u16, u16, u16, u16, u16, u16, u16);
s32 font_text_width(void *, void *, u8, f32, u8);

#define pen_y n

#define LOAD_TEX(font) \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xFD900000; _g->w1 = osVirtualToPhysical(font->tex->addr); } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xF5900000; _g->w1 = 0x07080200; } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xE6000000; _g->w1 = 0; } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xF3000000; \
      _g->w1 = (((((font->tex->width * font->tex->height) + 3) >> 2) - 1 < 0x800 ? \
                 (((font->tex->width * font->tex->height) + 3) >> 2) - 1 : 0x7FF) & 0xFFF) << 12 | 0x07000000 | \
               ((((font->tex->width / 16) <= 0 ? 1 : (font->tex->width / 16)) + 0x7FF) / \
                ((font->tex->width / 16) <= 0 ? 1 : (font->tex->width / 16)) & 0xFFF); } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xE7000000; _g->w1 = 0; } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xF5800000 | (((((font->tex->width >> 1) + 7) >> 3) & 0x1FF) << 9); _g->w1 = 0x80200; } \
    { Gfx *_g = gs->gfx++; _g->w0 = 0xF2000000; \
      _g->w1 = (((font->tex->width - 1) << 2) & 0xFFF) << 12 | (((font->tex->height - 1) << 2) & 0xFFF); }

/* Draws a string with the font list into the display list and returns the pen x after the last glyph.
 * x < 0 means right-aligned at -x; angle != 0 rotates the glyph quads around the first glyph. */
u16 font_draw_string(void *font_list, void *state, s16 x, s16 y, void *text, u8 font_count, f32 scale_x, f32 scale_y, u16 angle, u8 mode)
{
    f32 mtx[16];
    f32 v0x, v0y, z, v1x, v1y, v2x, v2y, v3x, v3y;
    f32 origin_x, origin_y;
    GfxState *gs;
    register s32 font_idx;
    s32 text_len;
    s32 kern;
    s32 base_y;
    u8 first_glyph;
    u8 shrink;
    u8 rotated;
    u8 fixed_origin;
    s32 i;
    s32 pen_x;
    s32 n;
    u8 ch;
    s32 vtx;
    Font *font;

    gs = state;
    font_idx = 0;

    kern = 0;
    fixed_origin = 0;
    origin_x = 0.0f;
    origin_y = 0.0f;
    z = 0.0f;
    rotated = angle != 0;
    if (x < 0) {
        s32 text_w;
        s32 neg_x = x;
        text_w = font_text_width((void *)(font_list), (void *)(text), (u8)(font_count), (f32)(scale_x), (u8)(mode));
        fixed_origin = 1;
        origin_x = (s16)-neg_x;
        origin_y = y;
        x = -neg_x - text_w;
    }
    font = ((Font **)font_list)[0];
    if (mode == 0) {
        shrink = 1;
        { Gfx *_g = gs->gfx++; _g->w0 = 0xDE000000;
#ifdef PORT
          _g->w1 = 0; /* N64 display-list address: no meaning on PC */
#else
          _g->w1 = (u32)font_dl_mode0;
#endif
        }
    } else if (mode == 1) {
        shrink = 2;
        { Gfx *_g = gs->gfx++; _g->w0 = 0xDE000000;
#ifdef PORT
          _g->w1 = 0; /* N64 display-list address: no meaning on PC */
#else
          _g->w1 = (u32)font_dl_mode1;
#endif
        }
    } else {
        shrink = 1;
    }
    { Gfx *_g = gs->gfx++; _g->w0 = 0xFA000000; _g->w1 = (font->r << 24) | (font->g << 16) | (font->b << 8) | font->a; }
    LOAD_TEX(font)
    pen_x = x;
    base_y = 0;
    first_glyph = 1;
    text_len = str_len(text);
    if ((text_len == 0) | (text_len >= 0xA1)) {
        func_8008E3A0(D_800A3F28, text_len);
#ifndef PORT
        __builtin_mips_debug_break();
#endif
        
    }
    for (i = 0; i < text_len; i++) {
        ch = ((u8 *)text)[i];
        ch -= 0x20;
        n = 0;
        if (ch != 0) {
            while ((font->glyphs[ch].code == -0x80) & ((n & 0xFF) != font_count)) {
                if (((font_idx + 1) & 0xFF) == font_count) font_idx = 0; else font_idx++;
                font = ((Font **)font_list)[font_idx & 0xFF];
                LOAD_TEX(font)
                n++;
            }
            if (font->glyphs[ch].code != -0x80) {
                if (first_glyph) {
                    base_y = font->glyphs[ch].k7 * scale_y;
                    if (rotated) {
                        guRotateF(mtx, angle, 0.0f, 0.0f, 1.0f);
                    }
                    if (*(s32 *)(stream_state + 0x32AA) == 3 && (((u8)(ch - 3) < 2) | (ch == 6))) {
                        base_y -= 5;
                    }
                }
                pen_y = ((f32)base_y - font->glyphs[ch].k7 * scale_y) + y;
                pen_x += font->glyphs[ch].k6 + kern - shrink;
                if (first_glyph) {
                    if (rotated) {
                        first_glyph = 0;
                        if (!fixed_origin) {
                            origin_x = pen_x;
                            origin_y = pen_y;
                        }
                    } else {
                        first_glyph = 0;
                    }
                }
                vtx = dl_reserve_vertices(state, 4);
                if (rotated) {
                    f32 fx = pen_x;
                    f32 dx = fx - origin_x;
                    f32 fy = pen_y;
                    vec3_transform_mtx3(mtx, dx, (fy + font->glyphs[ch].h * scale_y) - origin_y, 0.0f, &v0x, &v0y, &z);
                    vec3_transform_mtx3(mtx, (fx + font->glyphs[ch].w * scale_x) - origin_x, (fy + font->glyphs[ch].h * scale_y) - origin_y, 0.0f, &v1x, &v1y, &z);
                    fy = fy - origin_y;
                    vec3_transform_mtx3(mtx, (fx + font->glyphs[ch].w * scale_x) - origin_x, fy, 0.0f, &v2x, &v2y, &z);
                    vec3_transform_mtx3(mtx, dx, fy, 0.0f, &v3x, &v3y, &z);
                    v0x += origin_x; v0y += origin_y;
                    v1x += origin_x; v1y += origin_y;
                    v2x += origin_x; v2y += origin_y;
                    v3x += origin_x; v3y += origin_y;
                    gfx_set_quad_pos(state, vtx, (s32)v0x, (s32)v0y, 0, (s32)v1x, (s32)v1y, 0, (s32)v2x, (s32)v2y, 0, (s32)v3x, (s32)v3y, 0);
                } else {
                    gfx_set_quad_pos(state, vtx, pen_x, (s32)(pen_y + font->glyphs[ch].h * scale_y), 0,
                                  (s32)(pen_x + font->glyphs[ch].w * scale_x), (s32)(pen_y + font->glyphs[ch].h * scale_y), 0,
                                  (s32)(pen_x + font->glyphs[ch].w * scale_x), pen_y, 0, pen_x, pen_y, 0);
                }
                {
                    u32 t;
                    Gfx *_g;
                gfx_set_quad_uv(state, vtx, font->uv[ch][0] * 2, font->uv[ch][4] * 2, font->uv[ch][1] * 2, font->uv[ch][5] * 2,
                              font->uv[ch][2] * 2, font->uv[ch][6] * 2, font->uv[ch][3] * 2, font->uv[ch][7] * 2);
                    t = (u16)vtx;
                    t &= 0x1F;
                    _g = gs->gfx++;
                    {
                        u32 a = t << 17;
                        s32 b = (t + 2) * 2;
                        _g->w0 = a | ((t + 1) << 9) | b | 0x07000000;
                        _g->w1 = a | ((b & 0xFFFFFFFE) << 8) | ((t + 3) * 2);
                    }
                }
                pen_x = pen_x + font->glyphs[ch].w * scale_x;
                kern = font->glyphs[ch].k8;
            }
        } else {
            { s32 temp;
 temp = pen_x + font->glyphs[0].w * scale_x;
 pen_x = temp;
 }
        }
        pen_x += font->adv;
    }
    return pen_x - (u16)x - font->adv;
}
