#include "decompdecomp_debug_glyph_cc04.h"
#line 1 "func.c"
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

extern s32 func_8008E118(u8 *);
extern void func_8008E3A0(char *, s32);
extern char D_800A3F28[];
extern u8 D_800C02AE[];
extern u8 D_8009B680[];
extern u8 D_8009B618[];
extern u32 osVirtualToPhysical(void *);
extern void guRotateF(f32 *m, f32 a, f32 x, f32 y, f32 z);
extern void func_8001C108(f32 *m, f32 x, f32 y, f32 z, f32 *ox, f32 *oy, f32 *oz);
extern s32 func_8000665C(GfxState *, s32);
extern void func_800068C0(GfxState *, u16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16, s16);
extern void func_80008B28(GfxState *, u16, u16, u16, u16, u16, u16, u16, u16, u16);
s32 func_8000C9B0(Font **arg0, u8 *arg1, u8 arg2, f32 arg3, u8 arg4);

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

u16 func_8000CC04(Font **fonts, GfxState *st, s16 x, s16 y, u8 *str, u8 nfonts, f32 sx, f32 sy, u16 angle, u8 mode)
{
    f32 mtx[16];
    f32 v0x, v0y, z, v1x, v1y, v2x, v2y, v3x, v3y;
    f32 ox, oy;
    GfxState *gs;
    register s32 cur;
    s32 len;
    s32 kern;
    s32 base;
    u8 first;
    u8 shrink;
    u8 rot;
    u8 fixed;
    s32 i;
    s32 px;
    s32 n;
#define py n
    u8 c;
    s32 vtx;
    Font *font;

    gs = st;
    cur = 0;

    kern = 0;
    fixed = 0;
    ox = 0.0f;
    oy = 0.0f;
    z = 0.0f;
    rot = angle != 0;
    if (x < 0) {
        s32 w;
        s32 nx = x;
        w = func_8000C9B0(fonts, str, nfonts, sx, mode);
        fixed = 1;
        ox = (s16)-nx;
        oy = y;
        x = -nx - w;
    }
    font = fonts[0];
    if (mode == 0) {
        shrink = 1;
        { Gfx *_g = gs->gfx++; _g->w0 = 0xDE000000; _g->w1 = (u32)D_8009B680; }
    } else if (mode == 1) {
        shrink = 2;
        { Gfx *_g = gs->gfx++; _g->w0 = 0xDE000000; _g->w1 = (u32)D_8009B618; }
    } else {
        shrink = 1;
    }
    { Gfx *_g = gs->gfx++; _g->w0 = 0xFA000000; _g->w1 = (font->r << 24) | (font->g << 16) | (font->b << 8) | font->a; }
    LOAD_TEX(font)
    px = x;
    base = 0;
    first = 1;
    len = func_8008E118(str);
    if ((len == 0) | (len >= 0xA1)) {
        func_8008E3A0(D_800A3F28, len); __builtin_mips_debug_break();
        
    }
    for (i = 0; i < len; i++) {
        c = str[i];
        c -= 0x20;
        n = 0;
        if (c != 0) {
            while ((font->glyphs[c].code == -0x80) & ((n & 0xFF) != nfonts)) {
                if (((cur + 1) & 0xFF) == nfonts) cur = 0; else cur++;
                font = fonts[cur & 0xFF];
                LOAD_TEX(font)
                n++;
            }
            if (font->glyphs[c].code != -0x80) {
                if (first) {
                    base = font->glyphs[c].k7 * sy;
                    if (rot) {
                        guRotateF(mtx, angle, 0.0f, 0.0f, 1.0f);
                    }
                    if (*(s32 *)(D_800C02AE + 0x32AA) == 3 && (((u8)(c - 3) < 2) | (c == 6))) {
                        base -= 5;
                    }
                }
                py = ((f32)base - font->glyphs[c].k7 * sy) + y;
                px += font->glyphs[c].k6 + kern - shrink;
                if (first) {
                    if (rot) {
                        first = 0;
                        if (!fixed) {
                            ox = px;
                            oy = py;
                        }
                    } else {
                        first = 0;
                    }
                }
                vtx = func_8000665C(st, 4);
                if (rot) {
                    f32 fx = px;
                    f32 dx = fx - ox;
                    f32 fy = py;
                    func_8001C108(mtx, dx, (fy + font->glyphs[c].h * sy) - oy, 0.0f, &v0x, &v0y, &z);
                    func_8001C108(mtx, (fx + font->glyphs[c].w * sx) - ox, (fy + font->glyphs[c].h * sy) - oy, 0.0f, &v1x, &v1y, &z);
                    fy = fy - oy;
                    func_8001C108(mtx, (fx + font->glyphs[c].w * sx) - ox, fy, 0.0f, &v2x, &v2y, &z);
                    func_8001C108(mtx, dx, fy, 0.0f, &v3x, &v3y, &z);
                    v0x += ox; v0y += oy;
                    v1x += ox; v1y += oy;
                    v2x += ox; v2y += oy;
                    v3x += ox; v3y += oy;
                    func_800068C0(st, vtx, (s32)v0x, (s32)v0y, 0, (s32)v1x, (s32)v1y, 0, (s32)v2x, (s32)v2y, 0, (s32)v3x, (s32)v3y, 0);
                } else {
                    func_800068C0(st, vtx, px, (s32)(py + font->glyphs[c].h * sy), 0,
                                  (s32)(px + font->glyphs[c].w * sx), (s32)(py + font->glyphs[c].h * sy), 0,
                                  (s32)(px + font->glyphs[c].w * sx), py, 0, px, py, 0);
                }
                {
                    u32 t;
                    Gfx *_g;
                func_80008B28(st, vtx, font->uv[c][0] * 2, font->uv[c][4] * 2, font->uv[c][1] * 2, font->uv[c][5] * 2,
                              font->uv[c][2] * 2, font->uv[c][6] * 2, font->uv[c][3] * 2, font->uv[c][7] * 2);
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
                px = px + font->glyphs[c].w * sx;
                kern = font->glyphs[c].k8;
            }
        } else {
            { s32 temp;
 temp = px + font->glyphs[0].w * sx;
 px = temp;
 }
        }
        px += font->adv;
    }
    return px - (u16)x - font->adv;
}

