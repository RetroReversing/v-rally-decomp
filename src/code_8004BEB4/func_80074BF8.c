#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
extern u32 D_800C7F9C[];
extern char gResultsTable[];
extern s32 gSelectStepHandle;
extern s32 D_800D0660;
extern s32 D_800D0664;
void *gfx_get_dl();
void gfx_set_dl();
void gfx_round_vtx_pos();
volatile unsigned long long gfx_set_quad_pos();
int func_80006B4C();
void gfx_set_quad_colors_shared_alpha();
void font_set_color(void *, s32, s32, s32, u8);
void font_draw_text();
s32 font_text_width(void *, void *, u8, f32, u8);
void func_80052E94();
char *pool_get_item();
void func_80073108();
void func_80073320();
void draw_panel_quad();
int format_to_buffer(void *, void *, ...);
extern char D_800A1798[];
extern u8 panel_gap;
extern u8 D_800A17EA;
extern char D_800A5D70[];
extern char D_800A5D7C[];
extern char D_800A5D84[];
extern char D_800A5D8C[];
extern char D_800A5D9C[];
extern char D_800A5DC8[];
extern char D_800A5DE8[];
extern char D_800A5DF0[];
extern char D_800A5DF4[];
extern char D_800A5DFC[];
extern char D_800A5E0C[];
extern char D_800A5E10[];
extern char gGameState[];
extern char stream_state[];
static inline static char *inline_fn(int arg0, s32 arg1)
{
  return (stream_state + arg0) + (arg1 * 0x18);
}

static inline static static int inline_fn2(s16 arg0, u8 arg1)
{
  return arg0 + arg1;
}

/* Draws the results panel: title bar, the seven result rows with times and names, and the footer reward strings. */ void func_80074BF8(void *panel_ctx, void *gfx)
{
  s32 * score_ptr;
  s32 pool_w; s32 left_w; s32 spare_w;
  char line_buf[0x78];
  char name_a[0x18];
  char name_b[0x18];
  char value_buf[0x18];
  char *value_text;
  u16 row_y;
  s32 *header_text;
  s32 label_w;
  u16 spare16;
  s16 spare_a;
  s16 spare_b;
  s16 spare_c;
  s32 quad_vtx;
  s32 footer_w;
  char (*row_fmt)[];
  s32 title_x;
  s32 entry_off;
  s32 cur;
  s32 footer_w1;
  s32 title_w;
  s32 half_w16;
  u16 row16;
  s32 pool_w1;
  s32 row;
  s32 spare_v0;
  s32 row_idx;
  s32 idx;
  u32 time_val;
  int sep_w;
  u32 half_w;
  int spare_i;
  u32 pool_half;
  u32 time_raw;
  u32 rank_val;
  void *font_ref;
  void *font_slot;
  void *dl;

  score_ptr=(s32 *)&D_800D0660;
  dl = gfx_get_dl(gfx);
  *((u32 *) dl) = 0xDE000000;
  *((void **) (((char *) dl) + 4)) = &D_800A1798;
  gfx_set_dl(gfx, dl + 8);
  quad_vtx = func_80006B4C(gfx, 0) & 0xFFFF;
  gfx_set_quad_pos(gfx, quad_vtx, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  gfx_set_quad_colors_shared_alpha(gfx, quad_vtx, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  gfx_round_vtx_pos(gfx);
  format_to_buffer(&line_buf, &D_800A5DC8);
  font_slot = panel_ctx + 0x40;
  header_text = gResultsTable;
  title_w = font_text_width((void *)(font_slot), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1));
  row_y = 0x4B;
  value_text = value_buf;
  title_x = 0xA0 - (((u32) (title_w & 0xFFFF)) >> 1);
  row = 0;
#ifdef PORT
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
  value_text = (char *) (((uintptr_t) value_text) ^ ((uintptr_t) panel_ctx));
#else
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
  value_text = (char *) (((u32) value_text) ^ ((u32) panel_ctx));
#endif
  label_w = font_text_width((void *)(font_slot), (void *)(header_text), (u8)(1), (f32)(1.0f), (u8)(1));
  sep_w = 5;
  pool_w = font_text_width((void *)(font_slot), (void *)(pool_get_item(gSelectStepHandle, 0xD0)), (u8)(1), (f32)(1.0f), (u8)(1));
  left_w = D_800A17EA + label_w;
  cur = (left_w + pool_w);
  draw_panel_quad(gfx, (title_x - 7) & 0xFFFF, 0x3A, (title_w + 0xD) & 0xFFFF, 0x11);
  font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
  half_w = ((u32) (cur & 0xFFFF)) >> 1;
  half_w16 = half_w & 0xFFFF;
  font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, 0xA0 - half_w16, 0x3C, header_text, 1);
  func_80073108(gfx, (s16) (font_text_width((void *)(font_slot), (void *)(header_text), (u8)(1), (f32)(1.0f), (u8)(1)) - (half_w - 0xA0)), 0x3B, *((s32 *)score_ptr), (s32) (*((u8 *) (stream_state + 0x7CF4))));
  font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, (font_text_width((void *)(font_slot), (void *)(header_text), (u8)(1), (f32)(1.0f), (u8)(1)) + (0xA0 - half_w16)) + D_800A17EA, 0x3C, pool_get_item(gSelectStepHandle, 0xD0), 1);
  font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  do
  {
    row16 = row & 0xFFFF;
    row_fmt = &D_800A5DF0;
    if (row16 == 6)
    {
      pool_w1 = font_text_width((void *)(panel_ctx + 0x40), (void *)(pool_get_item(gSelectStepHandle, 0xD1)), (u8)(1), (f32)(1.0f), (u8)(1));
      pool_half = ((u32) (pool_w1 & 0xFFFF)) >> 1;
      draw_panel_quad(gfx, (0x97 - pool_half) & 0xFFFF, 0xBC, (pool_w1 + 0xF) & 0xFFFF, 0x11);
      font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
      row_y = 0xCD;
      font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, 0xA0 - pool_half, 0xBE, pool_get_item(gSelectStepHandle, 0xD1), 1);
      font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
      spare_v0 = row16 * 2;
    }
    entry_off = row16 * 24;
    if (((*((u32 *) ((stream_state + 0x7CE6) + entry_off))) == (*((s32 *) (stream_state + 0x7D76)))) & (row16 != 6))
    {
      font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
    }
    func_80052E94(*((u32 *) ((stream_state + 0x7CE6) + entry_off)), &name_a);
    func_80052E94(*((u32 *) ((stream_state + 0x7CEA) + entry_off)), &name_b);
    if ((*((u16 *) ((*((char **) (stream_state + 0x32F2))) + 0x50))) != 0)
    {
      time_raw = *((u32 *) ((stream_state + 0x7CEE) + entry_off));
      if (time_raw >= 0x12DU)
      {
        format_to_buffer(value_buf, &D_800A5DE8);
        idx = 0xFFFF;
        idx = row & idx;
      }
      else
      {
        format_to_buffer(value_buf, &D_800A5D7C, ((u32) (time_raw * 0x9F00)) >> 0x10);
        idx = row & 0xFFFF;
      }
      rank_val = ((u32) ((*((u32 *) ((stream_state + 0x7CEE) + (idx * 0x18)))) * 0x27C)) >> 0xA;
    }
    else
    {
      time_val = *((u32 *) ((stream_state + 0x7CEE) + entry_off));
      if (time_val >= 0x12DU)
      {
        format_to_buffer(value_buf, &D_800A5DF4);
      }
      else
      {
        format_to_buffer(value_buf, &D_800A5D84, time_val & 0xFFFF);
      }
      {s32 idx74;do {do {idx74=row & 0xFFFF;}while(0);}while(0);idx74=D_800C7F9C[idx74*6];rank_val=idx74;}
    }
    if (rank_val < 0x64U)
    {
#ifdef PORT
      format_to_buffer(&line_buf, row_fmt, (uintptr_t) value_text);
      format_to_buffer(value_text, &D_800A5D9C, (uintptr_t) (&line_buf));
#else
      format_to_buffer(&line_buf, row_fmt, (u32) value_text);
      format_to_buffer(value_text, &D_800A5D9C, (u32) (&line_buf));
#endif
    }
    cur = row & 0xFFFF;
    if (cur != 6)
    {
      if (cur >= ((*((u8 *) (gGameState + 0x6C00))) - 1))
      {
        if ((*((u8 *) (gGameState + 0x6C00))) == 0)
        {
          if ((*((u32 *) ((stream_state + 0x7CE6) + (cur * 0x18)))) == 0)
          {
            format_to_buffer(name_a, D_800A5D70);
            format_to_buffer(name_b, D_800A5D70);
            format_to_buffer(value_buf, D_800A5D8C);
          }
        }
        else
        {
          goto e0c;
        }
      }
      format_to_buffer(line_buf, D_800A5DFC, cur + 1, name_a, name_b, value_text);
      goto done;
      e0c:
      {
        char *label_fmt = D_800A5E0C;
        format_to_buffer(line_buf, label_fmt);
        format_to_buffer(value_buf, label_fmt);
      }

    }
    else
    {
      format_to_buffer(line_buf, D_800A5E10, stream_state + 0x7D72, name_a, value_text);
      format_to_buffer(value_text, D_800A5E0C);
    }
    done:
    row_idx = row & 0xFFFF;

    if ((*((u32 *) inline_fn(0x7CE6, row_idx))) != 0)
    {
      font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, 0xA0 - (((u32) (font_text_width((void *)(panel_ctx + 0x40), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1)) & 0xFFFF)) >> 1), (s16) row_y, &line_buf, 1);
    }
    font_set_color((void *)(*((void **) (((char *) panel_ctx) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    row += 1;
    row_y += 0xF;
  }
  while (((u32) (row & 0xFFFF)) < 7U);
  font_ref = panel_ctx + 0x40;
  footer_w1 = font_text_width((void *)(font_ref), (void *)(pool_get_item(gSelectStepHandle, 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
  footer_w = (((panel_gap + footer_w1) + (panel_gap + sep_w)) + font_text_width((void *)(font_ref), (void *)(pool_get_item(gSelectStepHandle, 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x10;
  {
    u16 cursor_x = 0x140 - footer_w;
    s32 *reward_ptr = &D_800D0664;
    func_80073320(gfx, cursor_x & 0xFFFF, 0xDC, footer_w & 0xFFFF, 0x11);
    func_80073108(gfx, (s16) cursor_x, 0xDC, *reward_ptr, 2);
    cursor_x += panel_gap;
    font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, (s16) cursor_x, 0xDE, pool_get_item(gSelectStepHandle, 0xD3), 1);
    cursor_x += font_text_width((void *)(font_ref), (void *)(pool_get_item(gSelectStepHandle, 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
    func_80073108(gfx, (s16) cursor_x, 0xDC, *reward_ptr, 0);
    cursor_x += panel_gap;
    font_draw_text(*((s32 *) (((char *) panel_ctx) + 0x40)), gfx, (s16) cursor_x, 0xDE, pool_get_item(gSelectStepHandle, 0xD7), 1);
  }
}

