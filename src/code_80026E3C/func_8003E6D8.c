#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s16 pad0[4];
  s16 x;
  s16 y;
} Pos;
typedef struct 
{
  u8 pad0[0xC];
  s32 type;
  u8 pad10[0x168];
  Pos *pos;
} Mgr;
typedef struct 
{
  u8 flags;
  u8 pad[0x27];
} Slot;
typedef struct 
{
  u8 pad0[0xE];
  u16 mode;
  u8 pad10[2];
  u16 flags12;
  u8 pad14[0xA];
  u16 state;
  u8 pad20[0x11];
  u8 sel[0x17];
  Slot slots[4];
} Game;
typedef struct Tex3 {u16 h0,h2,type,width,height;u8 a,b;u32 c;u8 **pal,**image;u32 x,y;} Tex3;
typedef struct {u8 count,pad[3];Tex3 **tex;} Pack3;
typedef void (*SpriteHook)(void *);
typedef struct 
{
  u8 pad0[0x76];
  u16 n;
  s16 part;
  u8 pad7A[0x16];
  u8 r;
  u8 g;
  u8 b;
  u8 a;
  u8 pad94[0x10];
  Pack3 *tex;
  Mgr *owner;
} Spr;
extern Game *D_800C35A0;
extern Mgr *D_800C7F84;
Pack3 *func_80034FF0(s32, s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
struct N;
struct N *func_8004240C(s32);
extern void func_8003ED04(void *);
extern void func_8003ED94(void *);
extern void func_8003EE84(void *);
extern void func_8003EF20(void *);
void func_8003E6D8(s32 arg0, s32 arg1)
{
  SpriteHook loop_callback;
  s32 loop_one;
  s32 mode2_one;
  s32 loop_resource;
  Pos *pos;
  Pos *start_pos;
  Mgr *m;
  Spr *s;
  s32 new_var2;
  s32 x;
  s32 base_x;
  s32 y;
  u32 i;
  u32 j;
  u32 row_number;
  s32 new_var;
  s32 k;
  s32 p;
  u16 state;
  u16 mode;
  s16 yy;
  s16 x1;
  s16 x2;
  s16 x3;
  start_pos = D_800C7F84->pos;
  base_x = start_pos->x;
  x = base_x + 0x14;
  y = start_pos->y + 6;
  state = D_800C35A0->state;
  if (state == 7)
  {
    return;
  }
  mode = D_800C35A0->mode;
  switch (mode)
  {
    case 1:
      if (state == 0)
    {
      if (D_800C35A0->slots[D_800C35A0->sel[1]].flags & 1)
      {
        s = func_80040260((void *)arg0, x, y, 5, func_8003ED04, mode);
        new_var2 = (s32) ((u32)arg1 + 0x4CU);
        s->tex = func_80034FF0(new_var2, 0);
        s->part = 0;
        s->owner = D_800C7F84;
        s = func_80040260((void *)arg0, base_x + 0x1C, y, 5, func_8003ED04, mode);
        new_var = (s32) ((u32)arg1 + 0x4CU);
        s->tex = func_80034FF0(new_var, 0);
        s->part = 1;
        s->owner = D_800C7F84;
        s = func_80040260((void *)arg0, base_x + 0x24, y, 5, func_8003ED04, mode);
        s->tex = func_80034FF0(new_var, 0);
        s->part = 2;
        s->owner = D_800C7F84;
      }
    }
    else
    {
      j = 0;
      if (D_800C35A0->slots[D_800C35A0->sel[1]].flags & 4)
      {
        loop_callback = func_8003ED94;
        loop_one = 1;
        loop_resource = (s32)((u32)arg1 + 0x4CU);
mode1_rows:
        {
          yy = y + (j * 11);
          s = func_80040260((void *)arg0, 0x1C, yy, 5, loop_callback, loop_one);
          s->tex = func_80034FF0(loop_resource, 0);
          s->part = 0;
          row_number = j + 1;
          s->n = row_number;
          s->owner = D_800C7F84;
          s = func_80040260((void *)arg0, 0x24, yy, 5, loop_callback, loop_one);
          s->tex = func_80034FF0(loop_resource, 0);
          s->part = loop_one;
          s->n = row_number;
          s->owner = D_800C7F84;
          s = func_80040260((void *)arg0, 0x2C, yy, 5, loop_callback, loop_one);
          s->tex = func_80034FF0(loop_resource, 0);
          s->part = 2;
          s->n = row_number;
          s->owner = D_800C7F84;
        }
        j = row_number;
        if (j < 4) goto mode1_rows;
      }
    }
      break;

    case 2:
      i = 1;
      k = 1;
      p = (u32)arg1 + 0x4CU;
      mode2_one = 1;
      arg1 = 0;
      do
    {
      m = (Mgr *)func_8004240C(k);
      pos = m->pos;
      D_800C7F84 = m;
      x = pos->x;
      y = pos->y + 6;
      if (!(D_800C35A0->flags12 & 1))
      {
        x += 0x14;
        if (m->type == 3)
        {
          x -= 0xE;
        }
      }
      if ((D_800C35A0->state != 0) && (D_800C35A0->slots[D_800C35A0->sel[i]].flags & 4))
      {
        loop_resource = (s16)(x + 8);
        yy = y + 10;
        s = func_80040260((void *)arg0, loop_resource, yy, 5, func_8003EF20, mode2_one);
        x2 = x + 0x10;
        s->tex = func_80034FF0(p, 0);
        s->part = 0;
        s->owner = D_800C7F84;
        s = func_80040260((void *)arg0, x2, yy, 5, func_8003EF20, mode2_one);
        x3 = x + 0x18;
        s->tex = func_80034FF0(p, 0);
        s->part = mode2_one;
        s->owner = D_800C7F84;
        s = func_80040260((void *)arg0, x3, yy, 5, func_8003EF20, mode2_one);
        s->tex = func_80034FF0(p, 0);
        s->part = 2;
        s->owner = D_800C7F84;
        s = func_80040260((void *)arg0, loop_resource, yy, 5, func_8003EE84, mode2_one);
        s->tex = func_80034FF0(p, 0);
        s->owner = D_800C7F84;
        s->part = 0;
        s->n = arg1;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
        s = func_80040260((void *)arg0, x2, yy, 5, func_8003EE84, mode2_one);
        s->tex = func_80034FF0(p, 0);
        s->owner = D_800C7F84;
        s->part = mode2_one;
        s->n = arg1;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
        s = func_80040260((void *)arg0, x3, yy, 5, func_8003EE84, mode2_one);
        s->tex = func_80034FF0(p, 0);
        s->owner = D_800C7F84;
        s->part = 2;
        s->n = arg1;
        s->r = 0xFE;
        s->g = 0xD5;
        s->b = 0x1E;
        s->a = 0xFF;
      }
      k += 2;
      arg1++;
      i++;
    }
    while (i < 3);
      break;

  }

}


