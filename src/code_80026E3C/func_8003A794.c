#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct
{
  u8 pad0[0x76];
  u16 n;
  u16 part;
  s16 sub;
  u8 pad7C[0x14];
  u8 col[4];
  u8 pad94[0x10];
  s32 tex;
  void *owner;
} Spr;
extern void *D_800C7F84;
s32 func_80034FF0(void *, s32);
void *func_80040260(void *, s16, s16, s32, void (*)(void *), s32);
extern void func_8003A73C(void *);
void func_8003A794(s32 arg0, s32 x, s32 y, void (*fn)(void *), u8 *arg4, u16 n, u8 *col)
{
  Spr *s;
  u32 i;
  void *tex;
  tex = (void *) (arg4 + 0x4C);
  for (i = 0; i < 5; i++)
  {
    s = func_80040260((void *)arg0, x, y, 2, fn, 0);
    s->part = i;
    x += 7;
    s->tex = func_80034FF0(tex, 0);
    s->n = n;
    s->owner = D_800C7F84;
    if (col != 0)
    {
      s->col[0] = col[0];
      s->col[1] = col[1];
      s->col[2] = col[2];
      s->col[3] = col[3];
    }
    if (i == 0)
    {
      s = func_80040260((void *)arg0, x, y, 2, func_8003A73C, 0);
      x += 4;
      s->tex = func_80034FF0(tex, 0);
      s->n = n;
      s->sub = 0xD;
      s->owner = D_800C7F84;
      if (col != 0)
      {
        s->col[0] = col[0];
        s->col[1] = col[1];
        s->col[2] = col[2];
        s->col[3] = col[3];
      }
    }
    if (i == 2)
    {
      s = func_80040260((void *)arg0, x, y, 2, func_8003A73C, 0);
      x += 5;
      s->tex = func_80034FF0((void *) (arg4 + 0x4C), 0);
      s->n = n;
      s->sub = 0xC;
      s->owner = D_800C7F84;
      if (col != 0)
      {
        s->col[0] = col[0];
        s->col[1] = col[1];
        s->col[2] = col[2];
        s->col[3] = col[3];
      }
    }
  }
}

