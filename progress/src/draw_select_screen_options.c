#define CFG(o) (*(u16 *)(*(char **)(stream_state+0x32F2)+(o)))
void *gfx_get_dl(void *);
void gfx_set_dl(void *, void *);
void gfx_round_vtx_pos(void *);
void gfx_set_quad_pos();
int gfx_append_quad();
void gfx_set_quad_colors_shared_alpha();
void font_set_color(void *, s32, s32, s32, u8);
void font_draw_text(void *, void *, s32, s32, void *, int);
s32 font_text_width(void *, void *, u8, f32, u8);
u16 font_draw_string(void *, void *, s16, s16, void *, u8, f32, f32, u16, u8);
void func_80052E94();
char *pool_get_item();
void func_80073108(void *, s16, s16, void *, int);
void func_80073320();
void draw_panel_quad();
int format_to_buffer(void *, void *, ...);
void func_800735D0(void *, s16);
extern char D_800A1798[];
extern u8 panel_gap;
extern u8 D_800A17E9;
extern u8 D_800A17EA;
extern char D_800A5D50[];
extern char D_800A5D70[];
extern char D_800A5D7C[];
extern char D_800A5D84[];
extern char D_800A5D8C[];
extern char D_800A5D94[];
extern char D_800A5D9C[];
extern char D_800A5DA0[];
extern char D_800A5DB4[];
extern char D_800A5DBC[];
typedef struct VRRow
{
  u32 a;
  u32 b;
  u32 c;
  u8 pad[2];
  u8 icon;
  u8 tail[9];
} VRRow;
extern VRRow gStandingsRows[];
extern char stream_state[];
extern char gSlotTableB[];
extern char D_800C8200[];
extern char D_800C8210[];
extern char D_800C8220[];
extern char D_800C8230[];
static inline u16 inline_fn(char *arg0)
{
  return *((u16 *) ((*((char **) arg0)) + 0x50));
}
static inline int inline_fn2(s32 arg0)
{
  return arg0 & 0xffff;
}
static inline char *inline_fn23(char *arg0)
{
  return (*((char **) arg0)) + 0xE;
}
typedef struct 
{
  unsigned char pad[64];
  void *value;
} __repair_field_40;
void draw_select_screen_options(void *menu, void *gfx)
{
  char sp40[0x78];
  char spB8[0x18];
  char spD0[0x18];
  char spE8[0x18];
  s16 sp106;
  u16 sp10E;
  s32 sp114;
  s32 start_x;
  u16 tail_y;
  s32 var_a1_4;
  char *new_var2;
  s32 var_v0;
  s32 var_v0_2;
  s32 temp_s0_2;
  u16 temp_s0_3;
  u16 temp_s1_5;
  u16 temp_s1_6;
  s16 temp_s1_7;
  u16 temp_s1_8;
  u16 row_icon_y;
  s32 temp_s3;
  u16 temp_s4;
  u16 var_fp;
  u16 var_s0_2;
  s32 temp_a0;
  s32 temp_a0_2;
  u16 temp_a3;
  s32 temp_s0;
  s32 temp_s0_5;
  s32 temp_s1;
  s32 special_width;
  u16 temp_s2;
  s32 temp_v1;
  s32 var_s0;
  s32 __repair_result_var_v0_2;
  int new_var;
  s32 header_width;
  u16 temp_v0_2;
  void *temp_v0;
  s16 second_icon_y;
  new_var2 = stream_state + 0x32F2;
  {
    temp_v0 = gfx_get_dl(gfx);
    *((u32 *) temp_v0) = 0xDE000000;
    *((void **) (((char *) temp_v0) + 4)) = &D_800A1798;
    gfx_set_dl(gfx, temp_v0 + 8);
    temp_s0 = gfx_append_quad(gfx, 0);
    if ((CFG(0xE) == 2) && (CFG(0x12) == 1))
    {
      gfx_set_quad_pos(gfx, temp_s0 & 0xffff, 32, 0, 0, 288, 0, 0, 288, 240, 0, 32, 240, 0);
    }
    else
    {
      gfx_set_quad_pos(gfx, inline_fn2(temp_s0), 0, 0, 0, 320, 0, 0, 320, 240, 0, 0, 240, 0);
    }
    gfx_set_quad_colors_shared_alpha(gfx, temp_s0 & 0xFFFF, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  }
  gfx_round_vtx_pos(gfx);
  format_to_buffer(&sp40, &D_800A5D50);
  sp10E = 0;
  new_var = font_text_width((void *)(menu + 0x40), (void *)(&sp40), (u8)(1), (f32)(1.0f), (u8)(1));
  header_width = D_800A17EA;
  header_width += D_800A17E9;
  header_width += new_var;
  sp114 = header_width & 0xFFFF;
  temp_v0_2 = ((u32) sp114) >> 1;
  temp_s0_2 = 0xA0 - temp_v0_2;
  temp_v0_2 += 0xA0;
  func_800735D0(menu, temp_s0_2);
  font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
  draw_panel_quad(gfx, (temp_s0_2 - 7) & 0xFFFF, 0x46, (unsigned short) (header_width + 0xD), 0x11);
  var_fp = 0x5A;
  sp106 = temp_s0_2;
  font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) (temp_s0_2 + 2), 0x48, pool_get_item(*((s32 *) (D_800C8200 + 0x128)), 0xCF), 1);
  font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  sp114 = ((u32) (-((s32) temp_v0_2))) << 16;
  do
  {
    if (sp10E == 4)
    {
      var_v0 = sp10E * 2;
      if ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5)
      {
        special_width = font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8210 + 0x118)), 0xD1)), (u8)(1), (f32)(1.0f), (u8)(1));
        temp_s2 = special_width;
        font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
        temp_s2 = ((u32) (temp_s2 & 0xFFFF)) >> 1;
        temp_s0_3 = var_fp + 0x1B;
        draw_panel_quad(gfx, (0x97 - temp_s2) & 0xFFFF, (temp_s0_3 - 2) & 0xFFFF, (special_width + 0xF) & 0xFFFF, 0x11);
        var_fp = temp_s0_3;
        var_fp = var_fp + 0x12;
        font_draw_text(((__repair_field_40 *) menu)->value, gfx, 0xA0 - temp_s2, (s16) temp_s0_3, pool_get_item(*((s32 *) (D_800C8220 + 0x108)), 0xD1), 1);
        font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(255), (s32)(255), (s32)(255), (u8)(255));
        var_v0 = sp10E * 2;
      }
    }
    else
    {
      if ((gStandingsRows[sp10E].a == (*((s32 *) (stream_state + 0x7D46)))) && ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5))
      {
        font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(220), (s32)(220), (s32)(16), (u8)(255));
      }
      var_v0 = sp10E * 2;
    }
    start_x = (u16)sp106;
    temp_a0 = gStandingsRows[sp10E].a;
    if (temp_a0 != 0)
    {
      func_80052E94(temp_a0, &spB8);
    }
    else
    {
      format_to_buffer(&spB8, &D_800A5D70);
    }
    temp_a0_2 = *((u32 *) ((stream_state + 0x7CEA) + (sp10E * 0x18)));
    if (temp_a0_2 != 0)
    {
      func_80052E94(temp_a0_2, &spD0);
    }
    else
    {
      format_to_buffer(&spD0, &D_800A5D70);
    }
    temp_v1 = *((u32 *) ((stream_state + 0x7CEE) + (sp10E * 0x18)));
    if (temp_v1 != 0)
    {
      if (inline_fn(stream_state + 0x32F2) != 0)
      {
        format_to_buffer(&spE8, &D_800A5D7C, ((u32) (temp_v1 * 0x9F00)) >> 0x10);
      }
      else
      {
        format_to_buffer(&spE8, &D_800A5D84, temp_v1 & 0xFFFF);
      }
    }
    else
    {
      format_to_buffer(&spE8, &D_800A5D8C);
    }
    temp_s3 = sp10E;
    if (temp_s3 != 4)
    {
      format_to_buffer(&sp40, &D_800A5D94, temp_s3 + 1, ((4 * temp_s3) * 6) + (stream_state + 0x7CE2));
    }
    else
    {
      format_to_buffer(&sp40, &D_800A5D9C, (void *) (stream_state + 0x7D42));
    }
    temp_s2 = sp10E;
    if (temp_s2 != 4)
    {
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) start_x, (s16) var_fp, sp40, 1);
    }
    temp_s1 = start_x + D_800A17E9;
    row_icon_y = --var_fp;
    if ((((u32) (temp_s1 & 0xFFFF)) < 0x141U) & (temp_s2 != 4))
    {
      func_80073108(gfx, temp_s1, row_icon_y, *((void **) (stream_state + 0x103B2)), (s32) (*((u8 *) ((stream_state + 0x7CF4) + (temp_s2 * 0x18)))));
    }
    do { do { do { ++var_fp; temp_s1 = temp_s1 + D_800A17EA; } while (0); } while (0); } while (0); 
    if (temp_s2 == 0)
    {
      goto row_zero;
    }
    if (temp_s2 != 4)
    {
      goto row_other;
    }
    if ((*((u16 *) ((*((char **) new_var2)) + 0x1E))) != 5)
    {
      temp_s2 = ((D_800A17E9 + 0xFFF1) + D_800A17EA) + font_text_width((void *)(menu + 0x40), (void *)(&D_800A5DA0), (u8)(1), (f32)(1.0f), (u8)(1));
      temp_s2 = ((s32)(0x140 - (temp_s2 & 0xFFFF))) / 2;
      temp_s4 = temp_s2 & 0xFFFF;
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, temp_s4, ((s16)var_fp), sp40, 1);
      second_icon_y = --var_fp;
      if (((u32) (temp_s1 & 0xFFFF)) < 0x141U)
      {
        func_80073108(gfx, (s16) (temp_s2 + (D_800A17E9 + 0xFFF1)), second_icon_y, *((void **) (stream_state + 0x103B2)), (s32) (*((u8 *) (stream_state + 0x7D54))));
      }
      var_fp = row_icon_y + 1;
      temp_s0_5 = 0xF;
      format_to_buffer(sp40, &D_800A5DB4, (void *) (&spB8), &spE8);
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, ((temp_s4 - temp_s0_5) + D_800A17E9) + D_800A17EA, ((s16)var_fp), sp40, 1);
    }
    goto row_done;
    row_zero:
    {
      s16 local_y;
      s32 local_x;
      void *second_ctx;
      void *second_dl;
      s16 second_x;
      s16 second_y;
      local_y = (s16) ((s16)var_fp);
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) temp_s1, local_y, spB8, 1);
      font_draw_string((void *)(menu + 0x40), (void *)(gfx), (s16)(sp114 >> 16), (s16)(local_y), (void *)(&spE8), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
      goto row_done;
    }

    row_other:
    {
      s16 local_y;
      s32 local_x;
      void *second_ctx;
      void *second_dl;
      s16 second_x;
      s16 second_y;
      format_to_buffer(&sp40, &D_800A5DBC, (void *) (&spB8), &spD0);
      local_y = (s16) ((s16)var_fp);
      {
      }
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) temp_s1, local_y, sp40, 1);
      font_draw_string((void *)(menu + 0x40), (void *)(gfx), (s16)(sp114 >> 16), (s16)(local_y), (void *)(&spE8), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1));
      goto row_done;
    }

    row_done:
    ;

    ;
    ;
    ;
    ;
    
    ;
    {
    }
    font_set_color((void *)(((__repair_field_40 *) menu)->value), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    sp10E += 1;
    var_fp += 0xF;
  }
  while (sp10E < 5U);
  if (CFG(0x22) == ((*((u16 *) (((CFG(0x20) * 0x2c4) + (*((char **) (gSlotTableB + (CFG(0x1e) * 4))))) + 0x14))) - 1))
  {
    __repair_result_var_v0_2 = font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8230 + 0xF8)), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
    temp_a3 = (new_var = ((panel_gap + __repair_result_var_v0_2) + ((u16) (panel_gap + 5))) + font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8210 + 0x118)), 0xDF)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x10;
  }
  else
  {
    var_v0_2 = font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8200 + 0x128)), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
    temp_a3 = (new_var = ((panel_gap + var_v0_2) + ((u16) (panel_gap + 5))) + font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8210 + 0x118)), 0xD4)), (u8)(1), (f32)(1.0f), (u8)(1))) + 0x10;
  }
  temp_s1_5 = 0x140 - temp_a3;
  var_s0_2 = temp_s1_5;
  var_fp = 0xDC;
  if ((*((u16 *) inline_fn23(new_var2))) == 2)
  {
    func_80073320(gfx, var_s0_2 & 0xFFFF, var_fp, (temp_a3 - 0x23) & 0xFFFF, 0x11);
    var_s0_2 = temp_s1_5 - 0xF;
  }
  else
  {
    func_80073320(gfx, var_s0_2 & 0xFFFF, var_fp, temp_a3 & 0xFFFF, 0x11);
  }
  func_80073108(gfx, var_s0_2, var_fp, *((void **) (stream_state + 0x103B6)), 2);
  temp_s1_6 = var_s0_2 + panel_gap;
  tail_y = (var_fp + 2) & 0x1FFFF;
  var_fp = tail_y;
  font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) temp_s1_6, ((s16)var_fp), pool_get_item(*((s32 *) (D_800C8220 + 0x108)), 0xD3), 1);
  temp_s1_7 = temp_s1_6 + font_text_width((void *)(menu + 0x40), (void *)(pool_get_item(*((s32 *) (D_800C8230 + 0xF8)), 0xD3)), (u8)(1), (f32)(1.0f), (u8)(1));
  func_80073108(gfx, temp_s1_7, (s16) (tail_y - 2), *((void **) (stream_state + 0x103B6)), 0);
  temp_s1_8 = temp_s1_7 + panel_gap;
  if (CFG(0x22) == ((*((u16 *) (((CFG(0x20) * 0x2c4) + (*((char **) (gSlotTableB + (CFG(0x1e) * 4))))) + 0x14))) - 1))
  {
    var_a1_4 = 0xDF;
    do
    {
      font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) temp_s1_8, ((s16)var_fp), pool_get_item(*((s32 *) (D_800C8200 + 0x128)), var_a1_4), 1);
    }
    while (0);
  }
  else
  {
    var_a1_4 = 0xD4;
    font_draw_text(((__repair_field_40 *) menu)->value, gfx, (s16) temp_s1_8, ((s16)var_fp), pool_get_item(*((s32 *) (D_800C8210 + 0x118)), var_a1_4), 1);
  }
}