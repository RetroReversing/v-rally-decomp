#include "decompdecomp_snapshot_8003f3bc.h"
#line 1 "func.c"
typedef void (*SpriteHook)(void);
static inline s32 carflag(u8 *g, u32 i) { u8 *c = g + (g + i)[0x31] * 40; return c[0x48] & 8; }
#define CARFLAG(i) carflag(D_800C35A0, i)
typedef struct Tex3
{
  u16 h0;
  u16 h2;
  u16 type;
  u16 width;
  u16 height;
  u8 a;
  u8 b;
  u32 c;
  u8 **pal;
  u8 **image;
  u32 x;
  u32 y;
} Tex3;
typedef struct 
{
  u8 count;
  u8 pad[3];
  Tex3 **tex;
} Pack3;
typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
} Rect;
typedef struct 
{
  u8 pad[8];
  Rect r;
} RectHolder;
typedef struct 
{
  u8 pad[0x178];
  RectHolder *rh;
} Node;
typedef struct 
{
  u8 pad0[0x70];
  s16 ox;
  s16 oy;
  u8 pad74[6];
  s16 frame;
  u8 pad7C[0x17];
  u8 alpha;
  u8 pad94[4];
  s16 sx;
  s16 sy;
  u8 pad9C[4];
  s32 mode;
  Pack3 *pack;
  Node *node;
} Spr;
extern u8 *D_800C35A0;
extern Node *D_800C7F84;
Pack3 *func_80034FF0(s32 id, s32 extra);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
Node *func_8004240C(s32 arg0);
void func_8003F05C();
void func_8003EFF8();
void func_8003F3BC(s32 arg0, s32 arg1)
{
  u32 cnt;
  s32 dy;
  Rect *r;
  Spr *s0;
  Spr *s1;
  Tex3 *t;
  u32 n;
  u32 i;
  s16 x;
  s16 y;
  s32 hw;
  s32 hh;
  s32 few;
  dy = 0;
  s1 = NULL;
  if (((*((u16 *) (D_800C35A0 + 0x1E))) == 7) && ((*((u16 *) (D_800C35A0 + 0xE))) < 3))
  {
    return;
  }
  cnt = D_800C35A0[0xF];
  if (cnt < 3)
  {
    i = 1;
    if (i <= cnt)
    for (n = cnt; i <= n; i++)
    {
      few = n < 3;
      D_800C7F84 = func_8004240C(((i - 1) * 2) | 1);
      r = &D_800C7F84->rh->r;
      x = r->x;
      y = r->y;
      switch (n)
      {

        case 1:
          dy = 0x4C;
          x = r->w / 2;
          y = (r->h / 5) - 16;
          break;

        case 2:
          if ((*((u16 *) (D_800C35A0 + 0x12))) & 1)
        {
          dy = 0x20;
          x += r->w / 2;
          y = (y + (r->h / 3)) - 20;
        }
        else
        {
          dy = 0x5C;
          x += r->w / 2;
          y = (y + (r->h / 5)) + 12;
        }
          break;

      }

      if (CARFLAG(i))
      {
        s1 = ((Spr *)func_80040260((void *)(arg0), x, y + 10, (s16)(8), (SpriteHook)(func_8003F05C), 1));
        s1->pack = func_80034FF0(arg1 + 0x4C, 0);
        s1->mode = 2;
        s1->node = D_800C7F84;
        s1->alpha = 0xB4;
      }
      s0 = ((Spr *)func_80040260((void *)(arg0), x, r->y + dy, (s16)(8), (SpriteHook)(func_8003EFF8), 1));
      s0->pack = func_80034FF0(arg1 + 0x4C, 0);
      s0->frame = 5;
      s0->node = D_800C7F84;
      t = s0->pack->tex[s0->frame];
      hw = t->width >> 1;
      hh = t->height >> 1;
      if (n < 2)
      {
        s0->ox = -hw;
        s0->oy = -hh;
        if (CARFLAG(i))
        {
          s1->oy = -(s0->pack->tex[s1->frame]->height >> 1);
        }
      }
      else
        if (few)
      {
        if ((*((u16 *) (D_800C35A0 + 0x12))) & 1)
        {
          s0->sx = 0x480;
          s0->sy = 0x480;
          if (CARFLAG(i))
          {
            s1->sx = 0x480;
            s1->sy = 0x480;
          }
          s0->ox = (hw / 4) - hw;
        }
        else
        {
          s0->ox = -(s0->pack->tex[0]->width >> 1);
        }
        s0->oy = -(s0->pack->tex[0]->height >> 1);
        if (CARFLAG(i))
        {
          s1->oy = -(s0->pack->tex[0]->height >> 1);
        }
      }
      else
      {
        s0->sx = 0x800;
        s0->sy = 0x800;
      }
    }

  }
}


