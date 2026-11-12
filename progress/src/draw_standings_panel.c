typedef struct 
{
  u32 id;
  u32 second;
  u32 duration;
  u32 a;
  u32 b;
  u32 c;
} MenuRow;
extern MenuRow gStandingsRows[];
void *gfx_get_dl(void *);
void gfx_set_dl(void *, void *);
void gfx_round_vtx_pos(void *);
void gfx_set_quad_pos();
int func_80006B4C();
void gfx_set_quad_colors_shared_alpha();
void font_set_color(void *, s32, s32, s32, u8);
void font_draw_text();
s32 font_text_width(void *, void *, u8, f32, u8);
u16 font_draw_string(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
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
inline static s32 menu_language()
{
  return *((s32 *) (stream_state + 0x807A));
}

/* Draws the standings panel with title and up to 7 rows onto the display list. */ void draw_standings_panel(void *panel, void *dl)
{
  char title_buf[0x78];
  char row_buf1[0x18];
  char row_buf2[0x18];
  char row_buf3[24];
  u16 x_pos;
  void *sp10C;
  void *sp114;
  s32 *temp_s5_2;
  s32 var_a2;
  s32 total_width;
  s32 second_position;
  s32 header_raw_width;
  s32 heading_gap;
  s32 heading_other;
  u16 x_start2;
  s16 temp_s1_7;
  s16 temp_s1_8;
  s16 temp_s1_9;
  s32 temp_a0;
  s32 quad_y;
  s32 temp_s0_11;
  s32 temp_s0_12;
  s32 temp_s0_13;
  s32 lang_width;
  s32 temp_s0_6;
  s32 temp_s0_7;
  s32 x_start;
  s32 temp_s1_2;
  s32 temp_s1_3;
  u16 temp_s1_4;
  s32 title_width;
  s32 temp_s3_2;
  s32 width_mask;
  s32 temp_v0_3;
  s32 var_a1;
  u16 var_s0;
  s32 row_idx;
  int new_var3;
  s32 var_v0;
  s32 var_v0_3;
  s32 metric_row;
  s32 var_v0_4;
  char (*new_var5)[24];
  int new_var;
  u32 temp_a2;
  u32 temp_a2_2;
  u32 temp_s0_10;
  u32 temp_s0_4;
  u32 temp_s0_8;
  void *new_var4;
  u32 temp_s1_5;
  u32 temp_v1;
  u32 temp_v1_2;
  u32 var_a2_2;
  u32 var_v0_2;
  void *temp_s3_3;
  void *temp_v0;
  void *temp_v0_2;
  int new_var2;
  temp_v0 = gfx_get_dl(dl);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  gfx_set_dl(dl, temp_v0 + 8);
  quad_y = func_80006B4C(dl, 0);
  if ((*((u16 *) ((*((char **) (stream_state + 0x32F2))) + 0x12))) == 1)
  {
    gfx_set_quad_pos(dl, quad_y & 65535, 32, 0, 0, 288, 0, 0, 288, 240, 0, 32, 240, 0);
  }
  else
  {
    gfx_set_quad_pos(dl, quad_y & 65535, 0, 0, 0, 320, 0, 0, 320, 240, 0, 0, 240, 0);
  }
  gfx_set_quad_colors_shared_alpha(dl, quad_y & 0xFFFF, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  gfx_round_vtx_pos(dl);
  format_to_buffer(&title_buf, &D_800A5DC8);
  sp114 = panel + 0x40;
  title_width = font_text_width((void *)(sp114), (void *)(&title_buf), (u8)(1), (f32)(1.0f), (u8)(1));
  x_start = 0xA0 - (((u32) (title_width & 0xFFFF)) >> 1);
  lang_width = font_text_width((void *)(sp114), (void *)(stream_state + 0x7CE2), (u8)(1), (f32)(1.0f), (u8)(1));
  quad_y = (D_800A17EA + lang_width) + font_text_width((void *)(sp114), (void *)(pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD0)), (u8)(1), (f32)(1.0f), (u8)(1));
  x_pos = 40;
  row_idx = 0;
  new_var5 = &row_buf3;
  sp10C = row_buf2;
  temp_s1_2 = (x_start - 7) & 0xFFFF;
  temp_s3_2 = (unsigned short) (title_width + 0xD);
  draw_panel_quad(dl, temp_s1_2, 0x17, temp_s3_2, 0x11);
  #ifdef PORT
    font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#else
    font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#endif
    x_start2 = 0xA0;
  temp_s0_4 = ((u32) (quad_y & 0xFFFF)) >> 1;
  width_mask = temp_s0_4 & 0xFFFF;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, x_start2 - width_mask, 0x19, stream_state + 0x7CE2, 1);
  func_80073108(dl, (s16) (font_text_width((void *)(sp114), (void *)(stream_state + 0x7CE2), (u8)(1), (f32)(1.0f), (u8)(1)) - (temp_s0_4 - x_start2)), 0x18, *((s32 *) (stream_state + 0x103B2)), (s32) (*((u8 *) (stream_state + 0x7CF4))));
  total_width = ((font_text_width((void *)(sp114), (void *)(stream_state + 0x7CE2), (u8)(1), (f32)(1.0f), (u8)(1)) + x_start2) - width_mask) + D_800A17EA;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, total_width, 0x19, pool_get_item(menu_language(), 0xD0), 1);
  #ifdef PORT
    font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#else
    font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#endif
    new_var2 = 5;
  temp_s5_2 = (stream_state + 0x7CE2) + 0x60;
  header_raw_width = font_text_width((void *)(sp114), (void *)(temp_s5_2), (u8)(1), (f32)(1.0f), (u8)(1));
  quad_y = (D_800A17EA + header_raw_width) + font_text_width((void *)(sp114), (void *)(pool_get_item(menu_language(), 0xD0)), (u8)(1), (f32)(1.0f), (u8)(1));
  draw_panel_quad(dl, temp_s1_2, 0x8F, temp_s3_2, 0x11);
  #ifdef PORT
    font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#else
    font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#endif
    temp_s0_8 = ((u32) (quad_y & 0xFFFF)) >> 1;
  temp_s1_3 = temp_s0_8 & 0xFFFF;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, x_start2 - temp_s1_3, 0x91, temp_s5_2, 1);
  func_80073108(dl, (s16) (font_text_width((void *)(sp114), (void *)(stream_state + 0x7CE2), (u8)(1), (f32)(1.0f), (u8)(1)) - (temp_s0_8 - x_start2)), 0x90, *((s32 *) (stream_state + 0x103B2)), (s32) (*((u8 *) (stream_state + 0x7D54))));
  second_position = x_start2;
  second_position = ((font_text_width((void *)(sp114), (void *)(stream_state + 0x7CE2), (u8)(1), (f32)(1.0f), (u8)(1)) + second_position) - temp_s1_3) + D_800A17EA;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, second_position, 0x91, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD0), 1);
  new_var4 = sp114;
  #ifdef PORT
    font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#else
    font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#endif
    /* FIXED_GAME_SUFFIX */
  do
  {
    temp_s1_4 = row_idx & 0xFFFF;
    if (temp_s1_4 == 6)
    {
      temp_v0_3 = font_text_width((void *)(panel + 0x40), (void *)(pool_get_item(menu_language(), 0xD1)), (u8)(1), (f32)(1.0f), (u8)(1));
      temp_s0_10 = ((u32) (temp_v0_3 & 0xFFFF)) >> 1;
      draw_panel_quad(dl, (0x97 - temp_s0_10) & 0xFFFF, 0x67, (temp_v0_3 + 0xF) & 0xFFFF, 0x11);
      #ifdef PORT
        font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#else
        font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
#endif
        x_pos = 0x78;
      font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, 0xA0 - temp_s0_10, 0x69, pool_get_item(menu_language(), 0xD1), 1);
#ifdef PORT
        font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#else
        font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#endif
    }
    temp_s0_11 = temp_s1_4 * 24;
    if ((gStandingsRows[temp_s1_4].id == (*((s32 *) (stream_state + 0x7D76)))) & (temp_s1_4 != 6))
    {
      #ifdef PORT
        font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
#else
        font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
#endif
    }
    func_80052E94(gStandingsRows[temp_s1_4].id, &row_buf1);
    func_80052E94(gStandingsRows[temp_s1_4].second, &row_buf2);
    if ((*((u16 *) ((*((char **) (stream_state + 0x32F2))) + 0x50))) != 0)
    {
      temp_v1 = gStandingsRows[temp_s1_4].duration;
      if (temp_v1 >= 0x12DU)
      {
        format_to_buffer(&row_buf3, &D_800A5DE8);
        var_v0_3 = row_idx & 0xFFFF;
      }
      else
      {
        var_a2 = 0x10;
        format_to_buffer(&row_buf3, &D_800A5D7C, ((u32) (temp_v1 * 0x9F00)) >> var_a2);
        var_v0_3 = row_idx & 0xFFFF;
      }
      var_v0_2 = ((u32) (gStandingsRows[var_v0_3].duration * 0x27C)) >> 0xA;
    }
    else
    {
      temp_a2 = gStandingsRows[temp_s1_4].duration;
      if (temp_a2 >= 0x12DU)
      {
        format_to_buffer(&row_buf3, &D_800A5DF4);
        metric_row = row_idx & 0xFFFF;
      }
      else
      {
        format_to_buffer(&row_buf3, &D_800A5D84, temp_a2 & 0xFFFF);
        metric_row = row_idx & 0xFFFF;
      }
      var_v0_3 = metric_row << 1;
      var_v0_3 += metric_row;
      var_v0_3 <<= 3;
      var_v0_2 = *((u32 *) ((((char *) gStandingsRows) + var_v0_3) + 8));
    }

    if (var_v0_2 < 0x64U)
    {
      #ifdef PORT
        format_to_buffer(&title_buf, &D_800A5DF0, (*new_var5));
#else
        format_to_buffer(&title_buf, &D_800A5DF0, (u32) (*new_var5));
#endif
      do
      {
      }
      while (0);
      #ifdef PORT
        format_to_buffer((*new_var5), &D_800A5D9C, (&title_buf));
#else
        format_to_buffer((*new_var5), &D_800A5D9C, (u32) (&title_buf));
#endif
    }
    temp_v1_2 = row_idx & 0xFFFF;
    if (temp_v1_2 != 6)
    {
      temp_a0 = temp_v1_2 < 3U;
      if (temp_a0 != 0)
      {
        if (((s32) temp_v1_2) >= ((*((u8 *) (gGameState + 0x6C00))) - 1))
        {
          if (temp_a0 == 0)
          {
            goto block_23;
 do { } while (0);
          }
          goto block_27;
        }
        goto block_24;
      }
      block_23:
      if (((s32) (temp_v1_2 - 3)) < ((*((u8 *) (gGameState + 0x6C00))) - 1))
      {
        block_24:
        temp_a2_2 = row_idx & 0xFFFF;

        if (temp_a2_2 < 3U)
        {
          format_to_buffer(&title_buf, &D_800A5DFC, temp_a2_2 + 1, &row_buf1, sp10C, (*new_var5));
        }
        else
        {
          format_to_buffer(&title_buf, &D_800A5DFC, temp_a2_2 - 2, &row_buf1, sp10C, (*new_var5));
        }
        var_s0 = row_idx & 0xFFFF;
        goto formatted;
      }

      block_27:
      if ((*((u8 *) (gGameState + 0x6C00))) == 0)
      {
        temp_s1_5 = row_idx & 0xFFFF;
        if (gStandingsRows[temp_s1_5].id == 0)
        {
          format_to_buffer(&row_buf1, &D_800A5D70);
          format_to_buffer(&row_buf2, &D_800A5D70);
          format_to_buffer((void *) (&row_buf3), &D_800A5D8C);
        }
        if (temp_s1_5 < 3U)
        {
          format_to_buffer(&title_buf, &D_800A5DFC, temp_s1_5 + 1, &row_buf1, sp10C, (*new_var5));
        }
        else
        {
          #ifdef PORT
          if ((uintptr_t)new_var5 & 0x10000) {
            if ((uintptr_t)new_var5 & 0x100) {
#else
          if ((u32)new_var5 & 0x10000) {
            if ((u32)new_var5 & 0x100) {
#endif
          format_to_buffer(&title_buf, &D_800A5DFC, temp_s1_5 - 2, &row_buf1, sp10C, (*new_var5));
          } else {
          format_to_buffer(&title_buf, &D_800A5DFC, temp_s1_5 - 2, &row_buf1, sp10C, (*new_var5));
          }
          } else {
#ifdef PORT
            if ((uintptr_t)new_var5 & 0x100) {
#else
            if ((u32)new_var5 & 0x100) {
#endif
          format_to_buffer(&title_buf, &D_800A5DFC, temp_s1_5 - 2, &row_buf1, sp10C, (*new_var5));
          } else {
          format_to_buffer(&title_buf, &D_800A5DFC, temp_s1_5 - 2, &row_buf1, sp10C, (*new_var5));
          }
          }
        }
        var_s0 = row_idx & 0xFFFF;
      }
      else
      {
        format_to_buffer(&title_buf, &D_800A5E0C);
        var_s0 = row_idx & 0xFFFF;
        format_to_buffer((void *) (&row_buf3), &D_800A5E0C);
      }

    }
    else
    {
      #ifdef PORT
        temp_s0_6 = (uintptr_t) (stream_state + 0x7D72);
#else
        temp_s0_6 = (u32) (stream_state + 0x7D72);
#endif
      format_to_buffer(&title_buf, &D_800A5E10, temp_s0_6, &row_buf1, (void *) ((*new_var5)));
      block_36:
      ;

      ;
      ;
      ;
      ;
      ;
      ;
      format_to_buffer((void *) ((*new_var5)), &D_800A5E0C);
    }
    formatted:
    if (gStandingsRows[row_idx & 0xFFFF].id != 0)
    {
      font_draw_string((void *)(new_var4), (void *)(dl), (s16)((s16) (0xA0 - (((u32) (font_text_width((void *)(new_var4), (void *)(&title_buf), (u8)(1), (f32)(1.0f), (u8)(1)) & 0xFFFF)) >> 1))), (s16)((s16) x_pos), (void *)(&title_buf), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
    }

    #ifdef PORT
      font_set_color(*((void **) (((char *) panel) + 0x40)), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#else
      font_set_color((void *)(*((s32 *) (((char *) panel) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
#endif
      x_pos += 0xF;
    if ((row_idx & 0xFFFF) == 2)
    {
      x_pos = 0xA0;
    }
  }
  while (((u32) ((++row_idx) & 0xFFFF)) < 7U);
  temp_s3_3 = panel + 0x40;
  temp_s0_12 = font_text_width((void *)(temp_s3_3), (void *)(pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
  new_var3 = 1;
  temp_s0_13 = ((panel_gap + temp_s0_12) + (panel_gap + new_var2)) + font_text_width((void *)(temp_s3_3), (void *)(pool_get_item(menu_language(), 0xD7)), (u8)(new_var3), (f32)(1.0f), (u8)(new_var3));
  x_start2 = 0x11D - temp_s0_13;
  func_80073320(dl, x_start2 & 0xFFFF, 0xDC, temp_s0_13 & 0xFFFF, 0x11);
  func_80073108(dl, (s16)x_start2, 0xDC, *((s32 *) (stream_state + 0x103B6)), 2);
  temp_s1_7 = x_start2 + panel_gap;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, temp_s1_7, 0xDE, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD3), new_var3);
  temp_s1_8 = temp_s1_7 + font_text_width((void *)(temp_s3_3), (void *)(pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD3)), (u8)(new_var3), (f32)(1.0f), (u8)(new_var3));
  func_80073108(dl, temp_s1_8, 0xDC, *((s32 *) (stream_state + 0x103B6)), 0);
  temp_s1_9 = temp_s1_8 + panel_gap;
  font_draw_text(*((s32 *) (((char *) panel) + 0x40)), dl, temp_s1_9, 0xDE, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0xD7), 1);
}


