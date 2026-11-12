extern s32 label_alt;
s32 view_get_ctx_id(s32);
void *gfx_get_dl(s32);
s32 gfx_set_dl(s32, s32);
s32 gfx_push_mtx(s32, s32);
void font_set_color(void *, s32, s32, s32, u8);
s32 font_draw_text();
s32 font_text_width(void *, void *, u8, f32, u8);
u16 font_draw_string(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
s32 mtx_pool_alloc();
s32 *pool_get_item(s32, s32);
s32 func_80073108(s32, s16, s32, s32, s32);
s32 func_80073320(s32, s32, s32, s32, s32);
s32 draw_select_screen_options(void *, s32);
s32 render_results_panel(void *, s32);
s32 draw_standings_panel(void *, s32);
s32 input_get_buttons(s32);
s32 input_clear_flags(s32, s32);
s32 guMtxF2L(s32 *, s32);
s32 guMtxIdent(void *);
void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern s32 gPadFlags;
extern u32 overlay_frames;
extern u8 panel_gap;
extern s32 label_default;
extern char gOrderState[];
extern char stream_state[];
static __inline__ char *read_config(void)
{
  return *((char **) (stream_state + 0x32F2));
}

static __inline__ s32 read_handle(void)
{
  return *((s32 *) (stream_state + 0x807A));
}

#ifdef PORT
#define HWORD uintptr_t
#else
#define HWORD s32
#endif

void draw_select_overlay(void *overlay)
{
  u16 saved_field;
  void *context_flag;
  HWORD first_dl;
  s16 padding;
  s16 draw_x;
  s32 draw_one;
  f32 ortho_mtx[16];
  s32 *var_v0_5;
  s16 temp_s0_12;
  s16 temp_s0_13;
  s16 temp_s0_14;
  s16 temp_s0_15;
  s16 temp_s0_9;
  s16 var_a2_3;
  s16 var_a3;
  s16 var_a3_2;
  s16 var_a3_4;
  s16 draw_y;
  s16 fixed_draw_y;
  s32 temp_s0_10;
  s32 temp_s0_11;
  s32 temp_s0_2;
  s32 temp_s0_5;
  s32 temp_s0_8;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 early_frame;
  HWORD view_id;
  u16 var_a1;
  s32 var_a1_2;
  s32 var_a2;
  s32 var_a2_2;
  s16 var_a3_3;
  s16 var_a3_5;
  s32 buttons;
  s32 var_s0_2;
  s32 var_v0;
  s32 var_v0_2;
  s8 var_v0_3;
  s8 var_v0_4;
  u16 temp_s1;
  u16 temp_s1_2;
  u16 temp_v0_4;
  u16 temp_v0_5;
  s32 temp_v0_6;
  u16 temp_v0_7;
  void *temp_s0;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s0_6;
  void *temp_s0_7;
  void *temp_s1_3;
  void *temp_s2;
  void *temp_s5;
  void *temp_v0_3;
  void *var_a0;
  void *var_a0_2;
  void *var_a0_3;
  early_frame = ((u32) overlay_frames) < 5U;
  overlay_frames += 1;
  if (early_frame == 0)
  {
    temp_s0 = stream_state + 0x80D2;
    guMtxIdent(temp_s0);
    view_id = view_get_ctx_id(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)));
    temp_v0_3 = gfx_get_dl(view_id);
    *((s32 *) (((char *) temp_v0_3) + 0x0)) = 0xDA380003;
    *((HWORD *) (((char *) temp_v0_3) + 0x4)) = (HWORD)temp_s0;
    gfx_set_dl(view_id, (HWORD)temp_v0_3 + 8);
    temp_s0_2 = mtx_pool_alloc();
    guOrthoF(&ortho_mtx, 0.0f, 320.0f, 240.0f, 0.0f, -1.0f, 10.0f, 1.0f);
    guMtxF2L(&ortho_mtx, temp_s0_2);
    gfx_push_mtx(view_id, temp_s0_2);
    font_set_color((void *)(*((HWORD *) (((char *) overlay) + 0x40))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    if (gPadFlags & 1)
    {
      if ((*((s32 *) (((char *) overlay) + 0x3C))) == 2)
      {
        gPadFlags &= ~1;
      }
      buttons = input_get_buttons(0);
      input_clear_flags(0, buttons);
      if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
      {
        buttons |= input_get_buttons(1);
        input_clear_flags(1, input_get_buttons(1));
      }
      temp_v0_4 = *((u16 *) (((char *) read_config()) + 0x1E));
      if ((temp_v0_4 != 0) & (temp_v0_4 < 5U))
      {
        if ((*((s32 *) (gOrderState + 0x8030))) == 2)
        {
          if ((*((s32 *) (((char *) overlay) + 0x48))) != 0)
          {
            buttons = 0x1000;
          }
        }
      }
      var_v0_2 = buttons & 0x8000;
      if (buttons & 0x1000)
      {
        if ((*((s32 *) (((char *) overlay) + 0x48))) != 0)
        {
          if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
          {
            *((u8 *) (stream_state + 0x8076)) = 1;
          }
          else
          {
            *((u8 *) (stream_state + 0x8076)) = 3;
          }
          *((s32 *) (((char *) overlay) + 0x48)) = 0;
        }
        else
        {
          temp_v0_5 = *((u16 *) (((char *) read_config()) + 0x1E));
          if ((((temp_v0_5 == 0) | (temp_v0_5 >= 5U)) != 0) || ((*((s32 *) (gOrderState + 0x8030))) != 2))
          {
            if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
            {
              *((u8 *) (stream_state + 0x8076)) = 1;
            }
            else
            {
              if (input_get_buttons(0) & 0x1000)
              {
                *((u8 *) (stream_state + 0x8076)) = 1;
              }
              if (input_get_buttons(1) & 0x1000)
              {
                *((u8 *) (stream_state + 0x8076)) = 2;
              }
            }
          }
        }
        *((s32 *) (((char *) overlay) + 0x3C)) = 1;
      }
      if ((buttons & 0x8000) || (overlay_frames == 0x1D4C))
      {
        input_clear_flags(0, buttons);
        *((s32 *) (((char *) overlay) + 0x3C)) = 2;
      }
    }
    if ((*((s32 *) (((char *) overlay) + 0x3C))) == 0)
    {
      temp_v0_6 = *((u16 *) (((char *) read_config()) + 0x1E));
      switch (temp_v0_6)
      {
        case 0:
          if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          render_results_panel(overlay, view_id);
        }
        else
        {
          draw_standings_panel(overlay, view_id);
        }
          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 5:
          draw_select_screen_options(overlay, view_id);
          break;

      }

    }
    else
    {
      if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
      {
        if ((((u32) (*((s32 *) (gOrderState + 0x121C)))) >> 3) & 1)
        {
          font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, 0x104, 5, pool_get_item(read_handle(), 0xC1), 1);
          font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, 0x113, 0xF, read_config() + (((*((u8 *) (((char *) read_config()) + 0x32))) * 0x28) + 0x44), 1);
        }
      }
      else
        if ((((u32) (*((s32 *) (gOrderState + 0x121C)))) >> 3) & 1)
      {
        draw_x = 0x1E;
        if ((*((u16 *) (((char *) read_config()) + 0x12))) == 1)
        {
          draw_x = 0x118;
          draw_y = 5;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((*((u16 *) (((char *) read_config()) + 0x1A))) == 1))
          {
            temp_s0_3 = overlay + 0x40;
            font_draw_string((void *)(temp_s0_3), (void *)(view_id), (s16)(-0x118), (s16)(5), (void *)(pool_get_item(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_v0_5 = pool_get_item(read_handle(), 0xD2);
            font_draw_string((void *)(temp_s0_3), (void *)(view_id), (s16)(-0x118), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
          else
            {
            var_v0_5 = pool_get_item(read_handle(), 0xC1);
if (var_v0_5){
            context_flag = (void *)(overlay + 0x40);}else{
            context_flag = (void *)(overlay + 0x40);}
            var_a0_2 = ((void *)context_flag); first_dl=view_id;
            {s32 x;void *secondctx;HWORD seconddl;s32 secondx;s16 secondy;x=(s32)draw_x;x=-(s16)x;font_draw_string((void *)(var_a0_2),(void *)(first_dl),(s16)(x),(s16)(draw_y),(void *)(var_v0_5),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));secondctx=((void *)context_flag);seconddl=view_id;secondx=x;secondy=draw_y+10;font_draw_string((void *)(secondctx),(void *)(seconddl),(s16)(secondx),(s16)(secondy),(void *)(read_config()+((*((u8 *)(read_config()+0x32)))*40+0x44)),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));}
          }
        }
        else
          if (draw_y = 5, ((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((temp_s1 = *((u16 *) (((char *) read_config()) + 0x1A)), temp_s1 == 1)))
        {
          temp_s0_4 = overlay + 0x40;
          font_draw_string((void *)(temp_s0_4), (void *)(view_id), (s16)(0x1E), (s16)(5), (void *)(pool_get_item(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          var_v0_5 = pool_get_item(read_handle(), 0xD2);
          font_draw_string((void *)(temp_s0_4), (void *)(view_id), (s16)(0x1E), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
        }
        else
        {
          var_v0_5 = pool_get_item(read_handle(), 0xC1);
if (var_v0_5){
          context_flag = (void *)(overlay + 0x40);}else{
          context_flag = (void *)(overlay + 0x40);}
          var_a0_2 = ((void *)context_flag); first_dl=view_id;
          {s32 x;void *secondctx;HWORD seconddl;s32 secondx;s16 secondy;x=(s32)draw_x;x=(s16)x;font_draw_string((void *)(var_a0_2),(void *)(first_dl),(s16)(x),(s16)(draw_y),(void *)(var_v0_5),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));secondctx=((void *)context_flag);seconddl=view_id;secondx=x;secondy=draw_y+10;font_draw_string((void *)(secondctx),(void *)(seconddl),(s16)(secondx),(s16)(secondy),(void *)(read_config()+((*((u8 *)(read_config()+0x32)))*40+0x44)),(u8)(1),(f32)(1.0f),(f32)(1.0f),(u16)(0),(u8)(1));}
        }
        context_flag = (void *)(1);
        draw_x = 0x128;
        if ((*((u16 *) (((char *) read_config()) + 0x12))) == ((HWORD)context_flag))
        {
          draw_x = 0x118;
          draw_y = 0x7D;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((*((u16 *) (((char *) read_config()) + 0x1A))) == ((HWORD)context_flag)))
          {
            temp_s0_6 = overlay + 0x40;
            font_draw_string((void *)(temp_s0_6), (void *)(view_id), (s16)(-0x118), (s16)(0x7D), (void *)(pool_get_item(read_handle(), 0xC1)), (u8)(((HWORD)context_flag)), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(((HWORD)context_flag)));
            var_v0_5 = pool_get_item(read_handle(), 0xD2);
            font_draw_string((void *)(temp_s0_6), (void *)(view_id), (s16)(-0x118), (s16)(0x87), (void *)(var_v0_5), (u8)(((HWORD)context_flag)), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(((HWORD)context_flag)));
          }
          else
          {
            goto block_60;
          }
        }
        else
        {
          draw_y = 5;
          if (((*((u16 *) (((char *) read_config()) + 0x1E))) == 0) && ((temp_s1_2 = *((u16 *) (((char *) read_config()) + 0x1A)), temp_s1_2 == ((HWORD)context_flag))))
          {
saved_field=temp_s1_2;
            temp_s0_7 = overlay + 0x40;
            font_draw_string((void *)(temp_s0_7), (void *)(view_id), (s16)(-0x128), (s16)(5), (void *)(pool_get_item(read_handle(), 0xC1)), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_v0_5 = pool_get_item(read_handle(), 0xD2);
            font_draw_string((void *)(temp_s0_7), (void *)(view_id), (s16)(-0x128), (s16)(0xF), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
          else
          {
            block_60:
            var_v0_5 = pool_get_item(read_handle(), 0xC1);

            temp_s2 = overlay + 0x40;
            temp_s0_8 = ((s32) (-(((s32)draw_x) << 0x10))) >> 0x10;
            font_draw_string((void *)(temp_s2), (void *)(view_id), (s16)(temp_s0_8), (s16)(draw_y), (void *)(var_v0_5), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
            var_a0_3 = temp_s2;
            var_a2_2 = temp_s0_8;
            var_a3_2 = draw_y + 0xA;
            ;
            font_draw_string((void *)(var_a0_3), (void *)(view_id), (s16)(var_a2_2), (s16)(var_a3_2), (void *)((s32 *) (read_config() + (((*((u8 *) (read_config() + 0x33))) * 40) + 0x44))), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
          }
        }
      }
      temp_v0_7 = *((u16 *) (((char *) read_config()) + 0x1E));
      if (((temp_v0_7 != 0) & (temp_v0_7 < 5U)) && ((*((s32 *) (gOrderState + 0x8030))) == 2))
      {
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          var_a3_3 = (panel_gap + font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0xF;
        }
        else
        {
          var_a3_3 = (panel_gap + font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x23;
        }
        draw_x = 0x140 - var_a3_3;
        draw_y = 0xDC;
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
        {
          var_a1 = ((s16)draw_x) & 0xFFFF;
          var_a3_3 -= 0x23;
          func_80073320(view_id, var_a1, draw_y, var_a3_3 & 0xFFFF, 0x11);
        }
        else
        {
          var_a1 = ((s16)draw_x) & 0xFFFF;
          func_80073320(view_id, var_a1, draw_y, var_a3_3 & 0xFFFF, 0x11);
        }
        draw_y -= 2;
        func_80073108(view_id, ((s16)draw_x), (s16) draw_y, *((s32 *) (stream_state + 0x103B6)), 0);
        draw_y += 2;
        temp_s0_9 = ((s16)draw_x) + panel_gap;
        var_v0_5 = pool_get_item(read_handle(), 0xD7);
        var_a2_3 = temp_s0_9;
        var_a3_4 = draw_y;
        font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, var_a2_3, var_a3_4, var_v0_5, 1);
      }
      else
      {

        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 1)
        {
          temp_s0_10 = font_text_width((void *)(overlay + 0x40), (void *)(&label_default), (u8)(1), (f32)(1.0f), (u8)(1));
          temp_s2_2 = font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xE2)), (u8)(1), (f32)(1.0f), (u8)(1));
          var_a3_5 = ((panel_gap + (((panel_gap + temp_s0_10) + (panel_gap + 5)) + temp_s2_2)) + font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0xF;
        }
        else
        {
          temp_s0_11 = font_text_width((void *)(overlay + 0x40), (void *)(&label_default), (u8)(1), (f32)(1.0f), (u8)(1));
          temp_s2_3 = font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xE2)), (u8)(1), (f32)(1.0f), (u8)(1));
          var_a3_5 = ((panel_gap + (((panel_gap + temp_s0_11) + (panel_gap + 5)) + temp_s2_3)) + font_text_width((void *)(overlay + 0x40), (void *)(pool_get_item(read_handle(), 0xD7)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x19;
        }
        draw_x = 0x140 - var_a3_5;
        draw_y = 0xDC;
        if ((*((u16 *) (((char *) read_config()) + 0xE))) == 2)
        {
          var_a3_5 -= 0x23;
          var_a1_2 = ((u16)draw_x) & 0xFFFF;
          func_80073320(view_id, var_a1_2, draw_y, var_a3_5 & 0xFFFF, 0x11);
        }
        else
        {
          var_a1_2 = ((u16)draw_x) & 0xFFFF;
          func_80073320(view_id, var_a1_2, draw_y, var_a3_5 & 0xFFFF, 0x11);
        }
        func_80073108(view_id, ((u16)draw_x), draw_y, *((s32 *) (stream_state + 0x103B6)), 3);
        padding=panel_gap;
        draw_y+=2;
        draw_x = (s16)(((u16)draw_x)+padding);
        if ((*((s32 *) (stream_state + 0x32AA))) == 3)
        {
          font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, ((s16)draw_x), (s16) draw_y, &label_alt, 1);
        }
        else
        {
          font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, ((s16)draw_x), draw_y, &label_default, 1);
        }
        temp_s5 = overlay + 0x40;
        temp_s0_12 = ((s16)draw_x) + font_text_width((void *)(temp_s5), (void *)(&label_default), (u8)(1), (f32)(1.0f), (u8)(1));
        draw_y -= 2;
        fixed_draw_y = draw_y;
        func_80073108(view_id, temp_s0_12, fixed_draw_y, *((s32 *) (stream_state + 0x103B6)), 2);
        temp_s0_13 = temp_s0_12 + panel_gap;
        draw_y += 2;
        font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, temp_s0_13, (s16) draw_y, pool_get_item(read_handle(), 0xD3), 1);
        temp_s0_14 = temp_s0_13 + font_text_width((void *)(temp_s5), (void *)(pool_get_item(read_handle(), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
        func_80073108(view_id, temp_s0_14, fixed_draw_y, *((s32 *) (stream_state + 0x103B6)), 0);
        temp_s0_15 = temp_s0_14 + panel_gap;
        var_v0_5 = pool_get_item(read_handle(), 0xD7);
        var_a2_3 = temp_s0_15;
        var_a3_4 = draw_y;
        font_draw_text(*((s32 *) (((char *) overlay) + 0x40)), view_id, var_a2_3, var_a3_4, var_v0_5, 1);
      }
    }
  }
}