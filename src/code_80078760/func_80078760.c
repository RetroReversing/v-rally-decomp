#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
#define SS_WORD(off) (*(s32 *)(gStreamState + (off)))
#define SS_PTR(off) (*(void **)(gStreamState + (off)))
#define SS_U16(off) (*(u16 *)(gStreamState + (off)))
#define SS_U8(off) (*(u8 *)(gStreamState + (off)))
#define FONT_A (gStreamState + 0x7F5E)          /* font list for the table */
#define FONT_B (gStreamState + 0x7F62)          /* font list for the footer */
#define POOL gSelectStepHandle                     /* text pool */
#define ROW(i) (0x7CE2 + (i) * 0x18)
#define ROW_NAME(i) (gStreamState + ROW(i))
#define ROW_FIRST(i) SS_WORD(ROW(i) + 4)
#define ROW_SECOND(i) SS_WORD(ROW(i) + 8)
#define ROW_THIRD(i) SS_WORD(ROW(i) + 0xC)
#define ROW_FLAG(i) SS_U8(ROW(i) + 0x10)
#define ROW_ICON(i) SS_U8(ROW(i) + 0x12)
#define TITLE_TEXT_ID D_800A1824[SS_U16(0x7F88)]

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
extern char D_800A5F38[];
extern s32 D_800A1824[];
void func_8004CEB4();
extern char D_800A5F54[];
extern char gStreamState[];
extern s32 D_800C8328;
extern u8 D_800C7FA0;
extern u8 *g_camera;
extern void *D_800C820C;
/* Draws the results screen: a title, five result rows (name, two times and an extra value; the
 * last row is the player's own result and is drawn separately), then a footer line. */
void func_80078760(s32 gfx)
{
  char line_buf[0x78];
  char name_buf[0x18];
  char first_buf[0x18];
  char extra_buf[0x18];
  s16 rect[4];
  char *var_a1_3;
  s32 *var_a1_4;
  s32 *var_a2_2;
  s32 *var_a3_2 ; int new_var6 ;
  u16 left_x;
  s32  * font_ptr ; s32 var_a1_2 ; int one ; s32 special_x;
  s32 var_a2;
  s32 neg_right_x ; int mask16 ;
  s32 var_a3;
  s32 text_y;
  s32 icon_x;
  s32 name_x;
  s32 header_left;
  s32 header_right;
  s32 temp_s2_2;
  s32 line_y;
  s32 icon_y;
  s32 footer_x;
  s32 first_val;
  s32 second_val;
  s32 quad_id;
  u32 *new_var;
  s32 header_w;
  int font_off;
  s32 temp_s1_2;
  s32 temp_s1_3;
  u16 w16;
  s32 third_val;
  s16 row;
  s32 text_x;
  u32 special_half;
  u32 header_half;
  void *footer_font;
  void *str, *str2;
  s32 fx, fy, w;
  u8 *flag;
  int id, handle;
  void *dl;
  u32 identity_zero;
  dl = gfx_get_dl(gfx);
  *((u32 *) dl) = 0xDE000000;
  *((void **) (((char *) dl) + 4)) = &D_800A1798;
  gfx_set_dl(gfx, dl + 8);
  quad_id = gfx_append_quad(gfx, 0) & 0xFFFF;
  gfx_set_quad_pos(gfx, quad_id, 0, 0, 0, 0x140, 0, 0, 0x140, 0xF0, 0, 0, 0xF0, 0);
  gfx_set_quad_colors_shared_alpha(gfx, quad_id, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0x1E, 0x32, 0x94, 0xAA);
  gfx_round_vtx_pos(gfx);
    {
        extern void *D_800C81F8;
        u32 camera_arg;
        u8 *camera;
        u8 *image;
        void *view = D_800C81F8;
        u8 **volatile *images = (u8 **volatile *)((u8 *)view + 4);
        rect[0] = -4;
        rect[1] = -4;
        rect[2] = *(u16 *)(*(*images) + 6) - 4;
        new_var = (void *)(gStreamState + 0x7F5E);
        camera = g_camera;
        rect[3] = *(u16 *)(*(*images) + 8);
        camera_arg = *(s32 *)(camera + 0x178);
        func_8004CEB4(camera_arg, *(*images), rect,
                      0, 0xAA, 0xAA, 0xAA, 0xAA, 0);
    }
  text_y = 0x5A;
  font_set_color(*(void **)new_var, (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  format_to_buffer(&line_buf, &D_800A5EB8);
  header_w = (D_800A17EA + D_800A17E9) + font_text_width((void *)(gStreamState + 0x7F5E), (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1));
  header_half = ((u32)(header_w & 0xFFFF)) >> 1;
  header_right = header_half + 0xA0;
  header_left = 0xA0 - header_half;
  font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
  draw_panel_quad(gfx, (header_left - 7) & 0xFFFF, 0x46, (header_w + 0xD) & 0xFFFF, 0x11);
  row = 0;
  left_x = header_left;
  font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, (s16)header_left, 0x48, pool_get_item(gSelectStepHandle, 0xCF), 1);
   new_var6 = 0x12 ; font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
  neg_right_x = (u32)(-header_right) << 16;
  do
  {
    text_x = (u16) left_x ; one = 1 ;

    if ((row & 0xFFFF) == 4)
    {
      format_to_buffer(&line_buf, &D_800A5ED8, pool_get_item(gSelectStepHandle, TITLE_TEXT_ID), pool_get_item(gSelectStepHandle, 0xD2)) ; text_x = 0x25; temp_s2_2 = text_y ; temp_s2_2 += 0x19 ; text_y = temp_s2_2 + new_var6 ;
      temp_s1_2 = font_text_width((void *)(gStreamState + 0x7F88) - 0x2A, (void *)(&line_buf), (u8)(1), (f32)(1.0f), (u8)(1));
      w16 = temp_s1_2;
      font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x80), (u8)(0xFF));
        special_half = ((u32) (w16 & 0xFFFF)) >> 1;
       mask16 = 0xFFFF ; font_off = 0x7F5E;
      draw_panel_quad(gfx, (0x97 - special_half) &  mask16 , (temp_s2_2 + (-2)) &  mask16 , (temp_s1_2 + 0xF) &  mask16 , 0x11);
       font_ptr = (s32 *) (gStreamState + font_off) ; font_draw_text ( * font_ptr , gfx, 0xA0 - special_half, temp_s2_2, line_buf, 1);
      font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));

      goto row_color_done;
    }
    new_var = &gResultsTable[(row & 0xFFFF)].first;

    if ((*new_var) == gResultsTable[4].first)
    {
      font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xDC), (s32)(0xDC), (s32)(0x10), (u8)(0xFF));

    }
row_color_done:
    do { do { do { do { first_val = gResultsTable[(row & 0xFFFF)].first; } while (0); } while (0); } while (0); } while (0);
    if (first_val != 0)
    {
      func_80052E94(first_val, &name_buf);

    }
    else
    {
      format_to_buffer(&name_buf, &D_800A5EE0);

    }
    do { do { do { do { do { do { do { do { do { do { do { do { do { do { do { do { do { do { second_val = gResultsTable[(row & 0xFFFF)].second; } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0); } while (0);
    if (gResultsTable[( 0xFFFF & row   )].second != 0)
    {
      func_80052E94(second_val, &first_buf);

    }
    else
    {
      format_to_buffer(&first_buf, &D_800A5EE0);

    }
    third_val = gResultsTable[(row & 0xFFFF)].third;
    if (third_val != 0)
    {
      if ((*((u16 *) (gStreamState + 0x7FB6))) != 0)
      {
        #ifdef PORT
          format_to_buffer(&extra_buf, &D_800A5EEC, (uintptr_t) (((u32) (third_val * 0x9F00)) >> 0x10));
#else
          format_to_buffer(&extra_buf, &D_800A5EEC, (s32 *) (((u32) (third_val * 0x9F00)) >> 0x10));
#endif

      }
      else
      {
        #ifdef PORT
          format_to_buffer(&extra_buf, &D_800A5EF4, (uintptr_t) (third_val & 0xFFFF));
#else
          format_to_buffer(&extra_buf, &D_800A5EF4, (s32 *) (third_val & 0xFFFF));
#endif

      }
    }
    else
    {
      if ((*((u16 *) (gStreamState + 0x7FB6))) != 0)
      {
        var_a1_3 = &D_800A5EFC;
        format_to_buffer(&extra_buf, var_a1_3); }
      else
      {
        var_a1_3 = &D_800A5F04;
        format_to_buffer(&extra_buf, var_a1_3);
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
       do { font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, (s16) text_x, text_y, line_buf, 1 ) ; } while ( 0 );
    }
do {     icon_x = text_x + D_800A17E9;
    do { do { icon_y = text_y -  one ; } while (0); } while (0);
    if ((((u32) (icon_x & 0xFFFF)) < 0x141U) & ((row & 0xFFFF) != 4))
    {
      func_80073108(gfx, icon_x, icon_y, *((s32 *) (gStreamState - (-0x103B2))), (s32) gResultsTable[(row & 0xFFFF)].icon);
    }
    line_y = icon_y; ++line_y;
    name_x = icon_x + D_800A17EA; name_x ^= gfx; name_x ^= gfx; 
    text_y = line_y ^ gfx; text_y ^= gfx;
    

 } while (0);
    if ((row & 0xFFFF) == 0) goto zero_row;
    if ((row & 0xFFFF) != 4) goto normal_row;
    {
        w16 = ((D_800A17E9 + 0xFFF1) + D_800A17EA) + font_text_width((void *)(gStreamState + 0x7F5E), (void *)(&D_800A5F18), (u8)(1), (f32)(1.0f), (u8)(1));
        temp_s1_3 = (s32)(0x140 - (w16 & 0xFFFF)) / 2;
        w16 = temp_s1_3;
        w16 = w16 & 0xFFFF;
        font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, w16, line_y, line_buf, 1);



        if (((u32) (name_x & 0xFFFF)) < 0x141U)
        {
          func_80073108(gfx, (s16) (temp_s1_3 + (D_800A17E9 + 0xFFF1)), icon_y, *((s32 *) (gStreamState + 0x103B2)), (s32) gResultsTable[4].icon);
        }
        text_y = line_y ^ gfx; text_y ^= gfx;
        format_to_buffer(line_buf, &D_800A5ED8, &name_buf, &extra_buf);
        
        font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, w16 + (D_800A17E9 - 0xF) + D_800A17EA, line_y, line_buf, 1);
        identity_zero = (u32)name_x ^ (u32)gfx; identity_zero ^= (u32)gfx; identity_zero ^= (u32)name_x;
        gfx = (u32)gfx + (u32)(s16)line_y * identity_zero;
        do { text_y += 0xF; } while (0);
      goto row_done;
    }
zero_row:
  {
    s16 local_y;
      ;
    font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, (s16)name_x,  ( s16 ) line_y , name_buf, 1);
    font_draw_string((void *)(gStreamState + 0x7F5E),
#ifdef PORT
      (void *)(uintptr_t)(gfx),
#else
      (void *)(gfx),
#endif
      (s16)(neg_right_x >> 0x10),  (s16)(( s16 ) line_y) , (void *)(&extra_buf), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row:
  {
    s16 local_y;
    format_to_buffer(&line_buf, &D_800A5F2C, &name_buf, &first_buf);
    local_y = (s16)line_y;
    font_draw_text(*((s32 *) (gStreamState + 0x7F5E)), gfx, (s16)name_x, local_y, line_buf, 1);
    font_draw_string((void *)(gStreamState + 0x7F5E),
#ifdef PORT
      (void *)(uintptr_t)(gfx),
#else
      (void *)(gfx),
#endif
      (s16)(neg_right_x >> 0x10), (s16)(local_y), (void *)(&extra_buf), (u8)(1), (f32)(1.0f), (f32)(1.0f), (u16)(0), (u8)(1)); 
    goto normal_row_done;
  }
normal_row_done:
    text_y ^= line_y; text_y ^= line_y;
    text_y += 0xF;
  row_done:
    font_set_color((void *)(*((void **) (gStreamState + 0x7F5E))), (s32)(0xFF), (s32)(0xFF), (s32)(0xFF), (u8)(0xFF));
    row += 1;
  }
  while ((u16)row < 5U);

    font_set_color(SS_PTR(0x7F62), 0xDC, 0xDC, 0x10, 0xFF);
    flag = &D_800C7FA0;
    if (*flag < 4) {
        format_to_buffer(line_buf, D_800A5ED8, pool_get_item(POOL, 0xD8), flag - 0x10);
        w = font_text_width(FONT_B, line_buf, 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), gfx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), 0x14, line_buf, 0);
        w16 = font_text_width(FONT_B, pool_get_item(POOL, 0xE3), 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), gfx, 0xA0 - ((u32)(w16 & 0xFFFF) >> 1), 0x23, pool_get_item(POOL, 0xE3), 0);
        w16 = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        font_draw_text(SS_WORD(0x7F62), gfx, 0xA0 - ((u32)(w16 & 0xFFFF) >> 1), 0x32, pool_get_item(POOL, TITLE_TEXT_ID), 0);
        goto color_end;
    } else if ((text_y = 0x14, SS_WORD(0x32AA) == 3)) {
        text_y = 0x23;
        w16 = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), gfx, 0xA0 - ((u32)(w16 & 0xFFFF) >> 1), 0x14, pool_get_item(POOL, TITLE_TEXT_ID), 0);
        if (ROW_FLAG(1) < 4) {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC6);
            format_to_buffer(line_buf, D_800A5ED8, prefix,msg);
        } else if (ROW_FLAG(2) < 4) {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC7);
            format_to_buffer(line_buf, D_800A5ED8, prefix,msg);
        } else {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC8);
            format_to_buffer(line_buf, D_800A5ED8, prefix,msg);
        }
        w = font_text_width(FONT_B, line_buf, 1, 1.0f, 0);
        font_draw_text(SS_WORD(0x7F62), gfx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), text_y, line_buf, 0);
        goto color_end;
    } else {
        void *s1;
        if (ROW_FLAG(1) < 4) {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC6);
            format_to_buffer(line_buf, D_800A5F38, prefix,msg, pool_get_item(POOL,0xE0));
        } else if (ROW_FLAG(2) < 4) {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC7);
            format_to_buffer(line_buf, D_800A5F38, prefix,msg, pool_get_item(POOL,0xE0));
        } else {
            void *prefix;
            void *msg;
            s32 handle;
            prefix = pool_get_item(POOL, 0xDC);
            msg = pool_get_item(POOL, 0xC8);
            format_to_buffer(line_buf, D_800A5F38, prefix,msg, pool_get_item(POOL,0xE0));
        }
        w = font_text_width(FONT_B, line_buf, 1, 1.0f, 0);
        font_draw_text(SS_PTR(0x7F62), gfx, 0xA0 - ((u32)(w & 0xFFFF) >> 1), (s16)text_y, line_buf, 0);
        w16 = font_text_width(FONT_B, pool_get_item(POOL, TITLE_TEXT_ID), 1, 1.0f, 0);
        str = pool_get_item(POOL, TITLE_TEXT_ID);
        fx = 0xA0 - ((u32)(w16 & 0xFFFF) >> 1);
        fy = (s16)(text_y + 0xF);
    }
    font_draw_text(SS_PTR(0x7F62), gfx, fx, fy, str, 0);
color_end:
    font_set_color(SS_PTR(0x7F62), 0xFF, 0xFF, 0xFF, 0xFF);
}

