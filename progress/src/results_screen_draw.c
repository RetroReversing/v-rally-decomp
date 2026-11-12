typedef struct { char name[4]; u32 first, second, third; u8 flag, pad17, icon, pad19[5]; } ScoreRow;
extern ScoreRow gResultsTable[5];
extern s32 gSelectStepHandle;
void *gfx_get_dl();
void gfx_set_dl();
void gfx_round_vtx_pos();
void gfx_set_quad_pos();
int gfx_append_quad();
void gfx_set_quad_colors_shared_alpha();
void font_set_color(void *, s32, s32, s32, u8);
void font_draw_text(s32,s32,s32,s16,void*,s32);
s32 font_text_width(void *, void *, u8, f32, u8);
u16 font_draw_string(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
void func_80052E94();
char *pool_get_item();
void func_80073108(s32,s16,s16,s32,u8);
void draw_panel_quad();
int format_to_buffer(void *, void *, ...);
extern char D_800A1798[];
extern u8 D_800A17E9;
extern u8 D_800A17EA;
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
extern char D_800A5F44[];
extern char D_800A5F54[];
extern char stream_state[];
/* Draws the results screen: a title, five result rows (name, two times and an extra value; the
 * last row is the player's own result and is drawn separately), then a footer line. */
void results_screen_draw(s32 ctx)
{
  char line_buf[0x78];
  char col1_buf[0x18];
  char col2_buf[0x18];
  char col3_buf[0x18];
  struct { char text[0x18];    } title;
  s32 *var_a1_3;
  s32 *var_a1_4;
  s32 *var_a2_2;
  s32 *var_a3_2 ; int new_var6 ;
  u16 left_x;
  s32  * new_var4 ; s32 var_a1_2 ; int new_var3 ; s32 special_x;
  s32 var_a2;
  s32 right_x ; int new_var5 ;
  s32 var_a3;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s4;
  s32 text_y;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_s0;
  u32 *new_var;
  s32 temp_s0_2;
  int new_var2;
  s32 temp_s1_2;
  s32 temp_s1_3;
  s32 temp_s2;
  u16 temp_s3;
  s32 temp_v1_2;
  s16 row;
  s32 text_x;
  u32 temp_s0_3;
  u32 temp_v0_2;
  void *temp_s1_4;
  void *temp_v0;
  u32 identity_zero;
  temp_v0 = gfx_get_dl(ctx);
  *((u32 *) temp_v0) = 0xDE000000;
  *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
  gfx_set_dl(ctx, temp_v0 + 8);
  temp_s0 = gfx_append_quad(ctx, 0) & 0xFFFF;
  gfx_set_quad_pos(ctx, temp_s0, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  gfx_set_quad_colors_shared_alpha(ctx, temp_s0, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  gfx_round_vtx_pos(ctx);
  {
  char *nm;
  if ((*((u8 *) (stream_state + 0x7F4F))) == 2)
    nm = pool_get_item(gSelectStepHandle, 0x1CD);
  else if ((*((u8 *) (stream_state + 0x7F4F))) == 3)
    nm = pool_get_item(gSelectStepHandle, 0x1CE);
  else if ((*((u8 *) (stream_state + 0x7F4F))) == 4)
    nm = pool_get_item(gSelectStepHandle, 0x1CF);
  else
    nm = pool_get_item(gSelectStepHandle, 0x1D0);
  text_y = 0x5A;
  format_to_buffer(&title.text, &D_800A5F14, nm);
  }
  font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  format_to_buffer(&line_buf, &D_800A5EB8);
  temp_s0_2 = (D_800A17EA + D_800A17E9) + font_text_width((void *)(stream_state + 0x7F5E), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1));
  temp_v0_2 = ((u32)(temp_s0_2 & 0xFFFF)) >> 1;
  temp_s2 = temp_v0_2 + 0xA0;
  temp_s1 = 0xA0 - temp_v0_2;
  font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
  draw_panel_quad(ctx, (temp_s1 - 7) & 0xFFFF, 0x46, (temp_s0_2 + 0xD) & 0xFFFF, 0x11);
  row = 0;
  left_x = temp_s1;
  font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, (s16)temp_s1, 0x48, pool_get_item(gSelectStepHandle, 0xCF), 1);
   new_var6 = 0x12 ; font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  right_x = (u32)(-temp_s2) << 16;
  do
  {
    text_x = (u16) left_x ; new_var3 = 1 ;

    if ((row & 0xFFFF) == 4)
    {
      format_to_buffer(&line_buf, &D_800A5F44, &title.text, pool_get_item(gSelectStepHandle, 0xD2)) ; text_x = 0x25; temp_s2_2 = text_y ; temp_s2_2 += 0x19 ; text_y = temp_s2_2 + new_var6 ;
      temp_s1_2 = font_text_width((void *)(stream_state + 0x7F5E), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1));
      temp_s3 = temp_s1_2;
      font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
        temp_s0_3 = ((u32) (temp_s3 & 0xFFFF)) >> 1;
       new_var5 = 0xFFFF ; new_var2 = 0x7F5E;
      draw_panel_quad(ctx, (0x97 - temp_s0_3) &  new_var5 , (temp_s2_2 + (-2)) &  new_var5 , (temp_s1_2 + 0xF) &  new_var5 , 0x11);
       new_var4 = (s32 *) (stream_state + new_var2) ; font_draw_text ( * new_var4 , ctx, 0xA0 - temp_s0_3, temp_s2_2, line_buf, 1);
      font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));

      goto row_color_done;
    }
    new_var = &gResultsTable[(row & 0xFFFF)].first;

    if ((*new_var) == gResultsTable[4].first)
    {
      font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));

    }
row_color_done:
    temp_a0 = gResultsTable[(row & 0xFFFF)].first;
    if (temp_a0 != 0)
    {
      func_80052E94(temp_a0, &col1_buf);

    }
    else
    {
      format_to_buffer(&col1_buf, &D_800A5EE0);

    }
    temp_a0_2 = gResultsTable[(row & 0xFFFF)].second;
    if (gResultsTable[( 0xFFFF & row   )].second != 0)
    {
      func_80052E94(temp_a0_2, &col2_buf);

    }
    else
    {
      format_to_buffer(&col2_buf, &D_800A5EE0);

    }
    temp_v1_2 = gResultsTable[(row & 0xFFFF)].third;
    if (temp_v1_2 != 0)
    {
      if ((*((u16 *) (stream_state + 0x7FB6))) != 0)
      {
        #ifdef PORT
          format_to_buffer(&col3_buf, &D_800A5EEC, (uintptr_t) (((u32) (temp_v1_2 * 0x9F00)) >> 0x10));
#else
          format_to_buffer(&col3_buf, &D_800A5EEC, (s32 *) (((u32) (temp_v1_2 * 0x9F00)) >> 0x10));
#endif

      }
      else
      {
        #ifdef PORT
          format_to_buffer(&col3_buf, &D_800A5EF4, (uintptr_t) (temp_v1_2 & 0xFFFF));
#else
          format_to_buffer(&col3_buf, &D_800A5EF4, (s32 *) (temp_v1_2 & 0xFFFF));
#endif

      }
    }
    else
    {
      if ((*((u16 *) (stream_state + 0x7FB6))) != 0)
      {
        var_a1_3 = &D_800A5EFC;
        format_to_buffer(&col3_buf, var_a1_3); }
      else
      {
        var_a1_3 = &D_800A5F04;
        format_to_buffer(&col3_buf, var_a1_3);
      }

    }
    if ((row & 0xFFFF) != 4)
    {
      format_to_buffer(&line_buf, &D_800A5F0C, (row & 0xFFFF) + 1, gResultsTable[(row & 0xFFFF)].name);

    }
    else
    {
      format_to_buffer(&line_buf, &D_800A5F14, gResultsTable[4].name);

    }
    if ((row & 0xFFFF) != 4)
    {
       do { font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, (s16) text_x, text_y, line_buf, 1 ) ; } while ( 0 );
    }
    temp_s0_4 = text_x + D_800A17E9;
    temp_s4 = text_y -  new_var3 ;
    if ((((u32) (temp_s0_4 & 0xFFFF)) < 0x141U) & ((row & 0xFFFF) != 4))
    {
      func_80073108(ctx, temp_s0_4, temp_s4, *((s32 *) (stream_state - (-0x103B2))), (s32) gResultsTable[(row & 0xFFFF)].icon);
    }
    temp_s2_3 = temp_s4; ++temp_s2_3;
    temp_s0_5 = temp_s0_4 + D_800A17EA; temp_s0_5 ^= ctx; temp_s0_5 ^= ctx; 
    text_y = temp_s2_3 ^ ctx; text_y ^= ctx;
    ctx ^= temp_s4; ctx ^= temp_s4;

    if ((row & 0xFFFF) == 0) goto zero_row;
    if ((row & 0xFFFF) != 4) goto normal_row;
    {
        temp_s3 = ((D_800A17E9 + 0xFFF1) + D_800A17EA) + font_text_width((void *)(stream_state + 0x7F5E), (void *)(&D_800A5F18), (u8)(1), (f32)(1.0f), (u8)(1));
        temp_s1_3 = (s32)(0x140 - (temp_s3 & 0xFFFF)) / 2;
        temp_s3 = temp_s1_3;
        temp_s3 = temp_s3 & 0xFFFF;
        font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, temp_s3, temp_s2_3, line_buf, 1);



        if (((u32) (temp_s0_5 & 0xFFFF)) < 0x141U)
        {
          func_80073108(ctx, (s16) (temp_s1_3 + (D_800A17E9 + 0xFFF1)), temp_s4, *((s32 *) (stream_state + 0x103B2)), (s32) gResultsTable[4].icon);
        }
        text_y = temp_s2_3 ^ ctx; text_y ^= ctx;
        format_to_buffer(line_buf, &D_800A5ED8, &col1_buf, &col3_buf);
        
        font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, temp_s3 + (D_800A17E9 - 0xF) + D_800A17EA, temp_s2_3, line_buf, 1);
        identity_zero = (u32)temp_s0_5 ^ (u32)ctx; identity_zero ^= (u32)ctx; identity_zero ^= (u32)temp_s0_5;
        ctx = (u32)ctx + (u32)(s16)temp_s2_3 * identity_zero;
        do { text_y += 0xF; } while (0);
      goto row_done;
    }
zero_row:
  {
    s16 local_y;
      ;
    font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, (s16)temp_s0_5,  ( s16 ) temp_s2_3 , col1_buf, 1);
    font_draw_string((void *)(stream_state + 0x7F5E),
#ifdef PORT
      (void *)(uintptr_t)(ctx),
#else
      (void *)(ctx),
#endif
      (s16)(right_x >> 0x10),  (s16)(( s16 ) temp_s2_3) , (void *)(&col3_buf), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row:
  {
    s16 local_y;
    format_to_buffer(&line_buf, &D_800A5F2C, &col1_buf, &col2_buf);
    local_y = (s16)temp_s2_3;
    font_draw_text(*((s32 *) (stream_state + 0x7F5E)), ctx, (s16)temp_s0_5, local_y, line_buf, 1);
    font_draw_string((void *)(stream_state + 0x7F5E),
#ifdef PORT
      (void *)(uintptr_t)(ctx),
#else
      (void *)(ctx),
#endif
      (s16)(right_x >> 0x10), (s16)(local_y), (void *)(&col3_buf), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row_done:
    text_y ^= temp_s2_3; text_y ^= temp_s2_3;
    text_y += 0xF;
  row_done:
    font_set_color((void *)(*((void **) (stream_state + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    row += 1;
  }
  while ((u16)row < 5U);
  temp_s1_4 = stream_state + 0x7F62;
  font_set_color((void *)(*((void **) (stream_state + 0x7F62))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));
  if (gResultsTable[0].flag < 4U)
  {
    format_to_buffer(&line_buf, &D_800A5ED8, pool_get_item(gSelectStepHandle, 0xD8), gResultsTable[0].name);
    font_draw_text(*((s32 *) (stream_state + 0x7F62)), ctx, 0xA0 - (((u32) (font_text_width((void *)(temp_s1_4), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(0)) & 0xFFFF)) >> 1), 0x14, &line_buf, 0);
  }
  
  text_y = 0x28;
  if ((*((s32 *) (stream_state + 0x32AA))) == 2)
  {
    if ((*((u8 *) (stream_state + 0x7F4F))) == 8)
      { format_to_buffer(&line_buf, &D_800A5ED8, pool_get_item(gSelectStepHandle, 0xD9), &title.text); temp_s3 = font_text_width((void *)(temp_s1_4), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(0)); }
    else
      { format_to_buffer(&line_buf, &D_800A5F54, pool_get_item(gSelectStepHandle, 0xD9), &title.text); temp_s3 = font_text_width((void *)(temp_s1_4), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(0)); }
  }
  else
      { format_to_buffer(&line_buf, &D_800A5F44, &title.text, pool_get_item(gSelectStepHandle, 0xD9)); temp_s3 = font_text_width((void *)(temp_s1_4), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(0)); }
  font_draw_text(*((s32 *) (stream_state + 0x7F62)), ctx, (temp_s2_3 = 0xA0 - (((u32) (temp_s3 & 0xFFFF)) >> 1)), text_y, &line_buf, 0);
  font_set_color((void *)(*((void **) (stream_state + 0x7F62))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
}