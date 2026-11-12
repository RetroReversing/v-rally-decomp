/* Port-only C (WebAssembly build): written from the assembly so it behaves as the game does, not matching C.
 * The project still has this function open for agents to match. */
#include "common.h"
#include "gap.h"

/* port: rewritten from the asm (func_80078760.s); the m2c draft added offsets to a word-typed
 * D_800C02AE (scaled by 4), passed 1.0f as the integer 0x3F800000 and dropped arguments.
 * D_800C02AE is stream_state (same address); callees use the names the port defines, with
 * prototypes matching w/sigs.txt so the wasm signatures agree:
 *   gfx_get_dl gfx_get_dl, gfx_set_dl gfx_set_dl, gfx_append_quad gfx_append_quad,
 *   gfx_set_quad_pos gfx_set_quad_pos, gfx_set_quad_colors_shared_alpha gfx_set_quad_colors_shared_alpha,
 *   gfx_round_vtx_pos gfx_round_vtx_pos, font_set_color font_set_color, font_draw_text font_draw_text,
 *   font_text_width font_text_width, font_draw_string font_draw_string, pool_get_item pool_get_item,
 *   draw_panel_quad draw_panel_quad, format_to_buffer format_to_buffer (sprintf-like, variadic). */
u32 *gfx_get_dl(s32);
void gfx_set_dl(s32, void *);
s32 gfx_append_quad(s32, s16);
void gfx_set_quad_pos(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void gfx_set_quad_colors_shared_alpha(s32, s32, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);
void gfx_round_vtx_pos(s32);
void font_set_color(void *, s32, s32, s32, u8);
u16 font_draw_text(void *, s32, u32, u32, void *, u8);
s32 font_text_width(void *, void *, u8, f32, u8);
u16 font_draw_string(void *, s32, s16, s16, void *, u8, f32, f32, u16, u8);
void *pool_get_item(void *, s32);
void draw_panel_quad(s32, s16, s32, s32, s32);
void format_to_buffer(char *, char *, ...);
void func_8004CEB4(s32, void *, void *, u8, u8, u8, u8, u8, u8);
void func_80052E94(s32, char *);
void func_80073108(s32, s16, s16, void *, u8);

extern u8 stream_state[];
extern char D_800A1798[];
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern s32 D_800A1824[];
extern char D_800A5EB8[];
extern char D_800A5ED8[];
extern char D_800A5EE0[];
extern char D_800A5EEC[];
extern char D_800A5EF4[];
extern char D_800A5EFC[];
extern char D_800A5F04[];
extern char D_800A5F0C[];
extern char D_800A5F14[];
extern char D_800A5F18[];
extern char D_800A5F2C[];
extern char D_800A5F38[];

/* stream_state fields this function reads (offsets from the asm). The results table is five
 * 0x18-byte rows at +0x7CE2: name[4], first, second, third (words), flag (u8 +0x10), icon (u8 +0x12). */
#define SS_WORD(off) (*(s32 *)(stream_state + (off)))
#define SS_PTR(off) (*(void **)(stream_state + (off)))
#define SS_U16(off) (*(u16 *)(stream_state + (off)))
#define SS_U8(off) (*(u8 *)(stream_state + (off)))
#define FONT_A (stream_state + 0x7F5E)          /* font list for the table */
#define FONT_B (stream_state + 0x7F62)          /* font list for the footer */
#define POOL SS_PTR(0x807A)                     /* text pool */
#define ROW(i) (0x7CE2 + (i) * 0x18)
#define ROW_NAME(i) (stream_state + ROW(i))
#define ROW_FIRST(i) SS_WORD(ROW(i) + 4)
#define ROW_SECOND(i) SS_WORD(ROW(i) + 8)
#define ROW_THIRD(i) SS_WORD(ROW(i) + 0xC)
#define ROW_FLAG(i) SS_U8(ROW(i) + 0x10)
#define ROW_ICON(i) SS_U8(ROW(i) + 0x12)
#define TITLE_TEXT_ID D_800A1824[SS_U16(0x7F88)]

/* Draws the results panel: a dark backdrop, a header, five rows (rows 0-3 a position, name and
 * times; row 4 the player's own line), then a footer chosen by the results state.
 * ctx is the graphics context func_80078724 passes through in $a0. */
void func_80078760(s32 ctx) {
    char line[0x78];        /* sp40 */
    char col1[0x18];        /* spB8 */
    char col2[0x18];        /* spD0 */
    char col3[0x18];        /* spE8 */
    s16 rect[4];            /* sp100: x, y, w, h */
    u16 left_x;             /* sp10E */
    s32 right_x;            /* sp114: (-right edge) << 16 */
    u32 *dl;
    s32 quad;
    s32 w;
    s32 hdr;
    s32 half;
    s32 x;                  /* $s4 */
    s32 y;                  /* $fp */
    s32 tx;                 /* $s0 */
    s32 ry;                 /* $s4 after the row text */
    s32 ny;                 /* $s2 */
    s32 cx;
    u32 row;                /* $s7 */
    u32 r;
    s32 third;
    void *str;
    void *str2;
    s32 fx;
    s32 fy;

    dl = gfx_get_dl(ctx);
    dl[0] = 0xDE000000;
    dl[1] = (u32)(AddrWord)D_800A1798;
    gfx_set_dl(ctx, (u8 *)dl + 8);
    quad = gfx_append_quad(ctx, 0) & 0xFFFF;
    gfx_set_quad_pos(ctx, quad, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
    gfx_set_quad_colors_shared_alpha(ctx, quad, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
    gfx_round_vtx_pos(ctx);

    {
        void *view = SS_PTR(0x7F4A);
        u8 *img = *(u8 **)*(void **)((u8 *)view + 4);
        rect[0] = -4;
        rect[1] = -4;
        rect[2] = *(u16 *)(img + 6) - 4;
        rect[3] = *(u16 *)(img + 8);
        func_8004CEB4(*(s32 *)((u8 *)SS_PTR(0x7CD6) + 0x178), *(void **)*(void **)((u8 *)view + 4), rect,
                      0, 0xAA, 0xAA, 0xAA, 0xAA, 0);
    }
    y = 0x5A;

    /* Header, centred on 160 with a panel behind it. */
    font_set_color(SS_PTR(0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    format_to_buffer(line, D_800A5EB8);
    hdr = D_800A17EA + D_800A17E9 + font_text_width(FONT_A, line, 1, 1.0f, 1);
    half = (u32)(hdr & 0xFFFF) >> 1;
    font_set_color(SS_PTR(0x7F5E), 0xDC, 0xDC, 0x80, 0xFF);
    draw_panel_quad(ctx, (0xA0 - half - 7) & 0xFFFF, 0x46, (hdr + 0xD) & 0xFFFF, 0x11);
    row = 0;
    left_x = 0xA0 - half;
    font_draw_text(SS_PTR(0x7F5E), ctx, (s16)(0xA0 - half), 0x48, pool_get_item(POOL, 0xCF), 1);
    font_set_color(SS_PTR(0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    right_x = (u32)(-(half + 0xA0)) << 16;

    do {
        x = left_x;
        if ((row & 0xFFFF) == 4) {
            /* The player's row: a title line in its own panel above it. */
            x = 0x25;
            ny = y + 0x19;
            y = ny + 0x12;
            str = pool_get_item(POOL, TITLE_TEXT_ID);
            format_to_buffer(line, D_800A5ED8, str, pool_get_item(POOL, 0xD2));
            w = font_text_width(FONT_A, line, 1, 1.0f, 1);
            font_set_color(SS_PTR(0x7F5E), 0xDC, 0xDC, 0x80, 0xFF);
            half = (u32)(w & 0xFFFF) >> 1;
            draw_panel_quad(ctx, (0x97 - half) & 0xFFFF, (ny - 2) & 0xFFFF, (w + 0xF) & 0xFFFF, 0x11);
            font_draw_text(SS_PTR(0x7F5E), ctx, 0xA0 - half, (s16)ny, line, 1);
            font_set_color(SS_PTR(0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
        } else if (ROW_FIRST(row & 0xFFFF) == ROW_FIRST(4)) {
            /* The row with the player's time is highlighted. */
            font_set_color(SS_PTR(0x7F5E), 0xDC, 0xDC, 0x10, 0xFF);
        }

        r = row & 0xFFFF;
        if (ROW_FIRST(r) != 0) {
            func_80052E94(ROW_FIRST(r), col1);
        } else {
            format_to_buffer(col1, D_800A5EE0);
        }
        r = row & 0xFFFF;
        if (ROW_SECOND(r) != 0) {
            func_80052E94(ROW_SECOND(r), col2);
        } else {
            format_to_buffer(col2, D_800A5EE0);
        }
        r = row & 0xFFFF;
        third = ROW_THIRD(r);
        if (third != 0) {
            if (SS_U16(0x7FB6) != 0) {
                format_to_buffer(col3, D_800A5EEC, (u32)(third * 0x9F00) >> 16);
            } else {
                format_to_buffer(col3, D_800A5EF4, third & 0xFFFF);
            }
        } else {
            format_to_buffer(col3, SS_U16(0x7FB6) != 0 ? D_800A5EFC : D_800A5F04);
        }

        r = row & 0xFFFF;
        if (r != 4) {
            format_to_buffer(line, D_800A5F0C, r + 1, ROW_NAME(r));
        } else {
            format_to_buffer(line, D_800A5F14, ROW_NAME(4));
        }
        r = row & 0xFFFF;
        if (r != 4) {
            font_draw_text(SS_PTR(0x7F5E), ctx, (s16)x, (s16)y, line, 1);
        }
        tx = x + D_800A17E9;
        ry = y - 1;
        if (((u32)(tx & 0xFFFF) < 0x141) & (r != 4)) {
            func_80073108(ctx, (s16)tx, (s16)ry, SS_PTR(0x103B2), ROW_ICON(r));
        }
        ny = ry + 1;
        y = ny;
        tx += D_800A17EA;

        if (r == 4) {
            /* The player's line, centred. */
            w = D_800A17EA + (D_800A17E9 + 0xFFF1) + font_text_width(FONT_A, D_800A5F18, 1, 1.0f, 1);
            cx = (s32)(0x140 - (w & 0xFFFF)) / 2;
            font_draw_text(SS_PTR(0x7F5E), ctx, cx & 0xFFFF, (s16)ny, line, 1);
            if ((u32)(tx & 0xFFFF) < 0x141) {
                func_80073108(ctx, (s16)(cx + (D_800A17E9 + 0xFFF1)), (s16)ry, SS_PTR(0x103B2), ROW_ICON(4));
            }
            y = ny;
            format_to_buffer(line, D_800A5ED8, col1, col3);
            font_draw_text(SS_PTR(0x7F5E), ctx, (cx & 0xFFFF) - 0xF + D_800A17E9 + D_800A17EA, (s16)ny, line, 1);
            y += 0xF;
        } else {
            if (r == 0) {
                /* The winner's row shows only the first time. */
                font_draw_text(SS_PTR(0x7F5E), ctx, (s16)tx, (s16)ny, col1, 1);
            } else {
                format_to_buffer(line, D_800A5F2C, col1, col2);
                font_draw_text(SS_PTR(0x7F5E), ctx, (s16)tx, (s16)ny, line, 1);
            }
            font_draw_string(FONT_A, ctx, (s16)(right_x >> 16), (s16)ny, col3, 1, 1.0f, 1.0f, 0, 1);
            y += 0xF;
        }
        row += 1;
        font_set_color(SS_PTR(0x7F5E), 0xFF, 0xFF, 0xFF, 0xFF);
    } while ((row & 0xFFFF) < 5);

    /* Footer. */
    font_set_color(SS_PTR(0x7F62), 0xDC, 0xDC, 0x10, 0xFF);
    if (ROW_FLAG(0) < 4) {
        format_to_buffer(line, D_800A5ED8, pool_get_item(POOL, 0xD8), ROW_NAME(0));
        w = font_text_width(FONT_B, line, 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), ctx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), 0x14, line, 0);
        w = font_text_width(FONT_B, pool_get_item(POOL, 0xE3), 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), ctx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), 0x23, pool_get_item(POOL, 0xE3), 0);
        w = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        str = pool_get_item(POOL, TITLE_TEXT_ID);
        fx = 0xA0 - ((u32)(w & 0xFFFF) >> 1);
        fy = 0x32;
    } else if (SS_WORD(0x32AA) == 3) {
        y = 0x23;
        w = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), ctx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), 0x14, pool_get_item(POOL, TITLE_TEXT_ID), 0);
        str2 = pool_get_item(POOL, 0xDC);
        if (ROW_FLAG(1) < 4) {
            str = pool_get_item(POOL, 0xC6);
        } else if (ROW_FLAG(2) < 4) {
            str = pool_get_item(POOL, 0xC7);
        } else {
            str = pool_get_item(POOL, 0xC8);
        }
        format_to_buffer(line, D_800A5ED8, str2, str);
        w = font_text_width(FONT_B, line, 1, 1.0f, 0);
        str = line;
        fx = 0xA0 - ((u32)(w & 0xFFFF) >> 1);
        fy = (s16)y;
    } else {
        void *s1;
        y = 0x14;
        s1 = pool_get_item(POOL, 0xDC);
        if (ROW_FLAG(1) < 4) {
            str2 = pool_get_item(POOL, 0xC6);
        } else if (ROW_FLAG(2) < 4) {
            str2 = pool_get_item(POOL, 0xC7);
        } else {
            str2 = pool_get_item(POOL, 0xC8);
        }
        format_to_buffer(line, D_800A5F38, s1, str2, pool_get_item(POOL, 0xE0));
        w = font_text_width(FONT_B, line, 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), ctx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), (s16)y, line, 0);
        w = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        str = pool_get_item(POOL, TITLE_TEXT_ID);
        fx = 0xA0 - ((u32)(w & 0xFFFF) >> 1);
        fy = (s16)(y + 0xF);
    }
    font_draw_text(SS_PTR(0x7F62), ctx, fx, fy, str, 0);
    font_set_color(SS_PTR(0x7F62), 0xFF, 0xFF, 0xFF, 0xFF);
}
