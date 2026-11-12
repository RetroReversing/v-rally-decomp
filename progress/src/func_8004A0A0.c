static inline static static static static static static static static static static static static static static static static static s32 right_coord(u32 x)
{
  return 0x140 - (x & 0xff);
}

s32 view_get_ctx_id(s32);
void *gfx_get_dl(s32);
s32 gfx_set_dl(s32, void *);
s32 gfx_round_vtx_pos(s32);
s32 gfx_set_quad_pos(s32, s32, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 gfx_append_quad(s32, s32);
s32 gfx_set_quad_colors(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void rect_set_set_scale(s32, f32, f32, f32);
void font_set_color(void *, s32, s32, s32, u8);
s32 font_draw_text(s32, s32, s32, s32, void *, s32);
s32 font_text_width(void *, void *, u8, f32, u8);
s32 func_8004CF7C(s32, s32, s32, s32, f32, s32, s32);
s32 *pool_get_item(s32, u16);
u8 select_stream_char(u8, u8, u8);
s32 cont_port_is_connected(s32, s32);
s32 memset(s32 *, s32, s32);
s32 appendString(s32 *, s32 *);
s32 strCpy(void *, void *);
extern char *gRaceCtx;
extern char *gRecords;
extern s32 D_800A0390;
extern s32 D_800A4EC0;
extern f64 D_800A4EC8;
extern f64 D_800A4ED0;
extern f64 D_800A4ED8;
extern char gOrderState[];
extern char stream_state[];
static inline static static static static static static static static static static char *inline_fn(s32 arg0)
{
  return (char *) (gRaceCtx + (arg0 * 2));
}

static inline static static static static static static static static static char *inline_fn2(int arg0, char *arg1)
{
  return (arg0 * 2) + arg1;
}

static inline static static static char *row_index(u8 idx, char *base)
{
  return (idx * 2) + base;
}

static inline s32 short_scale(s16 value)
{
struct {unsigned pad:16; signed lo:16;} x; x.lo=value; return x.lo*2;
}

static inline s32 read_menu_field(char *base,s32 off) {return *(u16*)((base+902)+(off));}

static inline s32 read_option_width(s32 idx,char *base) {return *(u16*)((base+0xDC)+idx*2);}

/* Draws the race HUD panel: controller port status, the framed title/menu box with per-entry text, and the stream-state rows at the bottom. */ void func_8004A0A0(void)
{
  char entryStr[0x30];
  char scratchStr[0x18];
  char titleStr[0x18];
  char *new_var6;
  s32 var_a1_11;
  s32 ctxId; s32 quadTag; u16 panel_flag;
  s32 menuCount;
  char *menu_ptr;
  s32 var_a1_12;
  s32 var_a1_13;
  s32 var_a1_14;
  s32 var_a1_2;
  u8 *new_var10;
  s32 var_a1_4;
  s32 var_a1_6;
  s32 var_a1_8;
  s32 var_a2;
  s32 var_a2_10;
  s32 var_a2_4;
  int new_var11;
  s32 var_a2_5;
  s32 var_a2_6;
  s32 var_a2_7;
  s32 var_a2_8;
  s32 var_a2_9;
  s32 var_a3_10;
  s32 var_a3_11;
  s32 var_a3_2;
  s32 var_a3_5;
  s32 var_a3_7;
  s32 var_a3_6;
  char *new_var13;
  s32 var_a3_8;
  s32 var_a3_9;
  s16 temp_s0_4;
  s16 temp_s1_2;
  s16 temp_v0_2;
  s32 temp_a3;
  s16 temp_a3_2;
  u16 temp_a3_3;
  s32 temp_a3_4;
  s16 temp_fp;
  s32 temp_fp_2;
  s32 temp_fv1;
  f64 temp_d0;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_5;
  s32 temp_s0_6;
  s32 temp_s0_7;
  u16 temp_s0_9;
  s32 temp_s1;
  int new_var;
  char *new_var7;
  u8 temp_s1_3;
  u16 temp_s2_2;
  int new_var4;
  s32 temp_s3;
  s32 temp_s3_2;
  s32 temp_s5;
  s32 temp_s7;
  s32 var_a0;
  s32 var_a0_2;
  char *new_var3;
  s32 var_a1_10;
  s32 var_a1_5;
  s32 var_a1_7;
  s32 var_a2_2;
  s32 var_a2_3;
  char *new_var2;
  s32 var_a3;
  u16 *new_var5;
  s32 var_a3_3;
  s32 var_a3_4;
  u16 rowY;
  char *new_var9;
  s32 var_fp_2;
  u8 portIdx;
  u8 menuIdx;
  s32 temp_v1_2;
  u16 var_a1;
  u16 var_a1_3;
  u16 var_a1_9;
  u32 temp_a2_2;
  u32 temp_a2_3;
  u32 temp_a2_4;
  u8 temp_a0_2;
  u8 temp_s0;
  u8 *new_var8;
  u8 temp_s0_10;
  u8 temp_s0_11;
  char *new_var12;
  u16 temp_s0_8;
  s32 temp_s2;
  u8 temp_v1;
  void *temp_a0;
  void *temp_a2;
  void *temp_v0;
  portIdx = 0;
  do
  {
    var_a0 = portIdx & 0xFF;
    temp_s1 = var_a0 * 0x10;
    temp_s0 = *((gOrderState + 0x239C) + temp_s1);
    if (temp_s0 != cont_port_is_connected(var_a0, 2))
    {
      *((gOrderState + 0x239D) + temp_s1) = 1;
      *((s32 *) ((gOrderState + 0x2394) + temp_s1)) = 0;
    }
    portIdx += 1;
  }
  while (((u32) (portIdx & 0xFF)) < 4U);
  ctxId = view_get_ctx_id(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)));
  temp_v0 = gfx_get_dl(ctxId);
  *((s32 *) (((char *) temp_v0) + 0x0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v0) + 0x4)) = &D_800A0390;
  gfx_set_dl(ctxId, temp_v0 + 8);
  quadTag = gfx_append_quad(ctxId, 0);
  var_a3 = 0;
  if (1)
  {
    if ((panel_flag=(*((u16 *) (((char *) gRecords) + 0xE))), temp_s3=quadTag, panel_flag) == 2)
    {
      var_a3 = ((*((u16 *) (((char *) gRecords) + 0x12))) & 1) << 5;
    }
    new_var2 = gRaceCtx + ((*((u8 *) (((char *) gRaceCtx) + 0x8))) * 0xDE);
    temp_s3_2 = temp_s3 & 0xFFFF;
    temp_s2 = *((u8 *) (((char *) new_var2) + 0xE6));
    temp_v0_2 = var_a3;
    temp_v0_2 = temp_v0_2 & 0xFF;
    temp_s5 = right_coord(var_a3);
    temp_s0_2 = ((s32) (0xE8 - (temp_s2 * 0x10))) >> 1;
    rowY = temp_s0_2;
    temp_a3 = temp_s0_2 - 0x22;
    temp_s2_2 = (temp_s2 * 8) + 0x14;
    temp_s0_3 = temp_s0_2 + 0xFFDE;
    temp_s1_2 = temp_s2_2 + temp_s0_3;
    gfx_set_quad_pos(ctxId, temp_s3_2, temp_v0_2, temp_a3, 0, (s32) temp_v0_2, (s32) temp_s1_2, 0, temp_s5, (s32) temp_s1_2, 0, temp_s5, temp_a3, 0);
    gfx_set_quad_colors(ctxId, temp_s3_2, 0, 0x4A, 0xA5, 0x32, 0, 0x4A, 0xA5, 0xA0, 0, 0x4A, 0xA5, 0xA0, 0, 0x4A, 0xA5, 0x32);
    gfx_round_vtx_pos(ctxId);
    temp_s7 = gfx_append_quad(ctxId, 0) & 0xFFFF;
    temp_s0_4 = temp_s0_3 + (temp_s2_2 * 2);
    gfx_set_quad_pos(ctxId, temp_s7, temp_v0_2, (s32) temp_s1_2, 0, (s32) temp_v0_2, (s32) temp_s0_4, 0, temp_s5, (s32) temp_s0_4, 0, temp_s5, (s32) temp_s1_2, 0);
    gfx_set_quad_colors(ctxId, temp_s7, 0, 0x4A, 0xA5, 0xA0, 0, 0x4A, 0xA5, 0x32, 0, 0x4A, 0xA5, 0x32, 0, 0x4A, 0xA5, 0xA0);
    gfx_round_vtx_pos(ctxId);
    memset(&entryStr, 0, 0x2A);
    memset(&scratchStr, 0, 0x14);
    memset(&titleStr, 0, 0x14);
    if ((*((u8 *) (((char *) gRaceCtx) + 0x382))) == 0)
    {
      strCpy((menuIdx=0,&titleStr), pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x126));
    }
    else
    {
      strCpy((menuIdx=0,&titleStr), pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x128));
    }
    appendString(&titleStr, gRecords + (((*((u8 *) (((char *) (gRecords + (*((u8 *) (((char *) gRaceCtx) + 0x382))))) + 0x32))) * 0x28) + 0x44));
    temp_s0_5 = font_text_width((void *)(gRaceCtx + 4), (void *)(&titleStr), (u8)(1), (f32)(0.8f), (u8)(0));
    font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
    rect_set_set_scale(*((s32 *) (((char *) gRaceCtx) + 0x4)), 0.8f, 0.8f, 0.8f);
    if(temp_s0_5) {var_a1_11=(s32)(u32)ctxId;} else {var_a1_11=ctxId;}
    #ifdef PORT
#else
var_a0 = (s32)gRaceCtx;
#endif
    temp_s0_7=(u16)temp_s0_5; temp_s3 = ((s32) (0x140 - temp_s0_7)) / 2;
    #ifdef PORT
temp_s0_6 = font_draw_text(*((s32 *) (gRaceCtx + 0x4)), var_a1_11, temp_s3, (rowY & 0xFFFF) - 0x16, &titleStr, 0);
#else
temp_s0_6 = font_draw_text(*((s32 *) (var_a0 + 0x4)), var_a1_11, temp_s3, (rowY & 0xFFFF) - 0x16, &titleStr, 0);
#endif
    rect_set_set_scale(*((s32 *) (((char *) gRaceCtx) + 0x4)), *((f32 *) (gRaceCtx + 0x3A4)), 1.0f, 1.0f);
    menu_ptr = gRaceCtx;
    new_var12 = menu_ptr + ((*((u8 *) (((char *) menu_ptr) + 0x8))) * 0xDE);
    if ((*((u8 *) (((char *) new_var12) + 0xE6))) != 0)
    {
      do
      {
        if ((menuIdx & 0xFF) == (*((u8 *) (((char *) menu_ptr) + 0x383))))
        {
          font_set_color((*((void **) (((char *) menu_ptr) + 4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
        }
        else
        {
          font_set_color((*((void **) (((char *) menu_ptr) + 4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
        }
        temp_s0_7 = menuIdx & 0xFF;
        temp_a2 = gRaceCtx + (((*((u8 *) (((char *) gRaceCtx) + 0x8))) * 0xDE) + 0xA);
        strCpy(&entryStr, temp_a2 + (temp_s0_7 * 0x2A));
        temp_v1 = *((u8 *) (((char *) gRaceCtx) + 0x8));
        if (temp_v1 == 0)
        {
          var_a3_3 = rowY & 0xFFFF;
          temp_a2_2 = 0x140 - (read_option_width(temp_s0_7,gRaceCtx));
          var_a2_2 = ((s32) (temp_a2_2 + (temp_a2_2 >> 0x1F))) >> 1;
          block_44:
          font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, 0);

          goto menu_end;
        }
        else
          if (temp_v1 == 1)
        {
          if (temp_s0_7 != 3)
          {
            var_a3_3 = rowY & 0xFFFF;
            new_var5 = (u16 *) (inline_fn(temp_s0_7) + 0x1BA);
            var_a2_2 = 0xA6 - (*new_var5);
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, 0);
          }
          else
          {
            var_a3_3 = rowY & 0xFFFF;
            temp_a2_3 = 0x140 - (*((u16 *) (((char *) gRaceCtx) + 0x1C0)));
            var_a2_2 = ((s32) (temp_a2_3 + (temp_a2_3 >> 0x1F))) >> 1;
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, 0);
          }
          goto menu_end;
        }
        else
          if (temp_v1 == 2)
        {
          if (temp_s0_7 != 4)
          {
            var_a3_3 = rowY & 0xFFFF;
            var_a2_2 = 0xA6 - (*((u16 *) (inline_fn(temp_s0_7) + 0x298)));
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, 0);
          }
          else
          {
            var_a3_3 = rowY & 0xFFFF;
            temp_a2_4 = 0x140 - (*((u16 *) (((char *) gRaceCtx) + 0x2A0)));
            var_a2_2 = ((s32) (temp_a2_4 + (temp_a2_4 >> 0x1F))) >> 1;
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, 0);
          }
          goto menu_end;
        }
        else
          if (temp_v1 == 3)
        {
          if (temp_s0_7 == 0)
          {
            var_a2_3 = temp_s3 + 4;
            var_a3_4 = (rowY & 0xFFFF) + 0x10;
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_3, var_a3_4, entryStr, 0);
          }
          else
          {
            var_a3_4 = rowY & 0xFFFF;
            var_a2_3 = ((((u16) temp_s0_6) + temp_s3) - (*((u16 *) (((char *) ((temp_s0_7 * 2) + gRaceCtx)) + 0x376)))) - 4;
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_3, var_a3_4, entryStr, 0);
          }
          font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
          temp_v1_2 = *((u16 *) (((char *) gRecords) + 0x1E));
          switch (temp_v1_2)
          {
            case 1:

            case 2:

            case 3:

            case 4:
              strCpy(&entryStr, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x1B3));
              break;

            case 0:
              strCpy(&entryStr, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x1B2));
              break;

            case 5:
              strCpy(&entryStr, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x1B0));
              break;

          }

          appendString(&entryStr, &D_800A4EC0);
          if (!(menuIdx & 0xFF))
          {
            var_a2_2 = (s32) (((u32) (0x140 - font_text_width((void *)(gRaceCtx + 4), (void *)(&entryStr), (u8)(1), (f32)(*((f32 *) (gRaceCtx + 0x3A4))), (u8)(0)))) >> 1);
            var_a3_3 = rowY & 0xFFFF;
            font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, var_a2_2, var_a3_3, entryStr, menuIdx);
            goto menu_end;
          }
          goto menu_end;
        }
        menu_end:
        rowY += 0x10;

        new_var13 = gRaceCtx + ((*((u8 *) (((char *) gRaceCtx) + 0x8))) * 0xDE);
        menu_ptr = gRaceCtx;
        menuCount = (u8) (*((u8 *) (((char *) new_var13) + 0xE6)));
        menuIdx += 1;
      }
      while (((u32) (menuIdx & 0xFF)) < menuCount);
    }
  }
  temp_a0_2 = *((u8 *) (((char *) gRaceCtx) + 0x8));
  new_var8 = (u8 *) (((char *) (gRaceCtx + (temp_a0_2 * 0xDE))) + 0xE6);
  temp_a3_2 = ((s32) (0xE8 - ((*new_var8) * 0x10))) >> 1;
  rowY = temp_a3_2;
  switch (temp_a0_2)
  {
    case 0:
      break;

    case 1:
      temp_d0 = ((f64) (*((f32 *) (stream_state + 0x3332)))) * D_800A4EC8;
      temp_fv1 = (s32) temp_d0;
      new_var = 0x10;
      if ((temp_fv1 << new_var) == 0)
    {
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 0)
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
      }
      else
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
      }
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x1C5U), 0);
    }
    else
      if ((*((u8 *) (gRaceCtx + 0x383))) == 0)
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 + 7) & 0xFFFF, 0xAE, temp_a3_2 - 2, 1.0f, 0, 0xFF);
    }
    else
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 - 1) & 0xFFFF, 0xAE, temp_a3_2 - 2, 1.0f, 0, 0xFF);
    }
      temp_a3_2 = rowY + new_var;
      rowY = temp_a3_2;
      temp_fv1 = (s32) (((f64) (*((f32 *) (stream_state + 0x333A)))) * D_800A4ED0);
      if ((temp_fv1 << new_var) == 0)
    {
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 1)
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
      }
      else
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
      }
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), 0x1C5U), 0);
    }
    else
      if ((*((u8 *) (gRaceCtx + 0x383))) == 1)
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 + 7) & 0xFFFF, 0xAE, (s16) (rowY - 2), 1.0f, 0, 0xFF);
    }
    else
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 - 1) & 0xFFFF, 0xAE, (s16) (rowY - 2), 1.0f, 0, 0xFF);
    }
      temp_a3_2 = new_var;
      temp_a3_2 = (rowY = rowY + temp_a3_2);
      temp_fv1 = (s32) (((f64) (*((f32 *) (stream_state + 0x332E)))) * D_800A4ED8);
      if ((temp_fv1 << new_var) == 0)
    {
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 2)
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
      }
      else
      {
        font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
      }
      var_a1_9 = 0x1C5;
      block_96:
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), var_a1_9), 0);

    }
    else
      if ((*((u8 *) (gRaceCtx + 0x383))) == 2)
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 + 7) & 0xFFFF, 0xAE, (s16) (rowY - 2), 1.0f, 0, 0xFF);
    }
    else
    {
      func_8004CF7C(*((s32 *) (((char *) (*((char **) (stream_state + 0x7CD6)))) + 0x178)), (temp_fv1 - 1) & 0xFFFF, 0xAE, (s16) (rowY - 2), 1.0f, 0, 0xFF);
    }
      break;

    case 2:
      temp_s1_3 = select_stream_char(*((u8 *) (((char *) gRecords) + 0x1F)), *((u8 *) (((char *) gRecords) + 0x21)), *((u8 *) (((char *) gRecords) + 0x23)));
      new_var3 = gRecords + ((*((u8 *) (((char *) (gRecords + (*((u8 *) (((char *) gRaceCtx) + 0x382))))) + 0x32))) * 0x28);
      temp_s0_8 = *((u8 *) (((char *) (new_var3 + (temp_s1_3 & 0xFF))) + 0x54));
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 0)
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
    }
    else
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    }
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), read_menu_field(gRaceCtx,(((s32)(temp_s0_8 << new_var)) >> 15))), 0);
      #ifdef PORT
#else
var_a0 = (s32)gRecords;
#endif
      #ifdef PORT
new_var11 = *(u8*)(gRecords + *(u8*)(gRaceCtx+0x382) + 0x32);
#else
new_var11 = *(u8*)(var_a0 + *(u8*)(gRaceCtx+0x382) + 0x32);
#endif
      new_var11 = new_var11 * 40;
      #ifdef PORT
#else
var_a0 += new_var11;
#endif
      #ifdef PORT
temp_s0_9 = *(u16*)(gRecords + new_var11 + (temp_s1_3 & 255)*2 + 0x60);
#else
temp_s0_9 = *(u16*)(var_a0 + (temp_s1_3 & 255)*2 + 0x60);
#endif
      temp_s0_9 = 2 - (((s16) temp_s0_9) / 10);
      rowY += new_var;
      if ((*((u8 *) (gRaceCtx + 0x383))) == 1)
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
    }
    else
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    }
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), *((u16 *) (((char *) (gRaceCtx + short_scale(temp_s0_9))) + 0x38C))), 0);
      temp_s0_10 = *(new_var10 = &(*((u8 *) (((char *) ((gRecords + ((*((u8 *) (((char *) (gRecords + (*((u8 *) (((char *) gRaceCtx) + 0x382))))) + 0x32))) * 0x28)) + (temp_s1_3 & 0xFF))) + 0x5C))));
      rowY += new_var;
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 2)
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
    }
    else
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    }
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), *((u16 *) (((char *) (gRaceCtx + (((s32) (temp_s0_10 << new_var)) >> 0xF))) + 0x396))), 0);
      new_var7 = gRecords + ((*((u8 *) (((char *) (gRecords + (*((u8 *) (((char *) gRaceCtx) + 0x382))))) + 0x32))) * 0x28);
      temp_s0_11 = *((u8 *) (((char *) (new_var7 + (temp_s1_3 & 0xFF))) + 0x58));
      rowY += new_var;
      if ((*((u8 *) (((char *) gRaceCtx) + 0x383))) == 3)
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFE), (s32)(0xD5), (s32)(0x1E), (u8)(0xFF));
    }
    else
    {
      font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    }
      var_a1_9 = *((u16 *) (((char *) (gRaceCtx + (((s32) (temp_s0_11 << new_var)) >> 0xF))) + 0x39C));
      font_draw_text(*((s32 *) (((char *) gRaceCtx) + 0x4)), ctxId, 0xAE, rowY & 0xFFFF, pool_get_item(*((s32 *) (stream_state + 0x807A)), var_a1_9), 0);

  }

  font_set_color((*((void **) (((char *) gRaceCtx) + 0x4))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
}
