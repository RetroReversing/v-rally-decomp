#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Tex
{
  char pad0[6];
  u16 w;
  u16 h;
} Tex;
typedef struct Img
{
  s32 pad0;
  Tex **tex;
} Img;
typedef struct Elem
{
  char pad0[0x24];
  Img **imgs;
  char pad28[0x37 - 0x28];
  u8 alpha;
} Elem;
extern u8 **D_800B55E4;
extern void *func_8004240C(s32);
extern void func_8004CEB4(s32, Tex *, s16 *, u8, s32, s32, s32, s32, s32);
void func_8005D4A4(s32 arg0)
{
  s16 rect[4];
  f32 scale;
  s32 new_var2;
  u8 *base;
  Tex **new_var;
  Elem *e;
  Tex *new_var3;
  scale = 1.25f;
  if (arg0 & 0xFF)
  {
    scale = 0.625f;
  }
  base = *D_800B55E4;
  e = (Elem *) (base + 12);
  rect[0] = 0;
  rect[1] = (arg0 & 0xFF) ? (135) : (269);
  rect[2] = (*e->imgs[3]->tex)->w * scale;
  rect[3] = (*e->imgs[3]->tex)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) func_8004240C(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[3]->tex, rect, e->alpha, 0, 0, 100, 100, 0);
  e = (Elem *) (base + 68);
  rect[0] = 0;
  rect[1] = (arg0 & 0xFF) ? (187) : (375);
  rect[2] = (*e->imgs[3]->tex)->w * scale;
  new_var = e->imgs[3]->tex;
  rect[3] = (*new_var)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) func_8004240C(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[3]->tex, rect, e->alpha, 100, 100, 200, 200, 0);
  e = (Elem *) (base + 12);
  if (arg0 & 0xFF)
  {
    rect[0] = 160;
    rect[1] = 135;
  }
  else
  {
    rect[0] = 320;
    rect[1] = 269;
  }
  rect[2] = (*e->imgs[0x17]->tex)->w * scale;
  rect[3] = (*e->imgs[0x17]->tex)->h * scale;
  func_8004CEB4((*((s32 *) (((u8 *) func_8004240C(1)) + 0x178))) & 0xFFFFFFFFFFFFFFFFu, *e->imgs[0x17]->tex, rect, e->alpha, 0, 0, 100, 100, 0);
  e = (Elem *) (base + 68);
  if (arg0 & 0xFF)
  {
    rect[0] = 160;
    rect[1] = 187;
  }
  else
  {
    rect[0] = 320;
    rect[1] = 375;
  }
  rect[2] = (*e->imgs[0x17]->tex)->w * scale;
  rect[3] = (*e->imgs[0x17]->tex)->h * scale;
  new_var2 = *((s32 *) (((u8 *) func_8004240C(1)) + 0x178));
  func_8004CEB4(new_var2, *e->imgs[0x17]->tex, rect, e->alpha, 100, 100, 200, 200, 0);
}


