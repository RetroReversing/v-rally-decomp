#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef void (*SpriteHook)(void *);
#define G D_800C35A0
#define P D_800C7F84
#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define W(p,o) (*(s32 *)((u8*)(p)+(o)))
#define B(p,o) (*((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
typedef struct { u8 pad0[6]; u16 w; } Img;
typedef struct { u8 pad0[4]; Img **imgs; } Spr;
typedef struct {
  u8 pad0[0xc];
  s16 xc;
  s16 xe;
  u8 pad10[0x7a - 0x10];
  s16 x7a;
  u8 pad7c[0x9c - 0x7c];
  s16 x9c;
  s16 x9e;
  s32 flags;
  Spr *spr;
  u8 *owner;
} Obj;
extern u8 *D_800C35A0;
extern u8 *D_800C7F84;
extern u8 *func_8004240C(s32);
void *func_80040260(void *, s16, s16, s32, SpriteHook, s32);
extern Spr *func_80034FF0(void *, s32);
extern void func_8003B980(void *);
void func_8003946C(s32 a, u8 *b, s32 c)
{
  u8 *g = G;
  u8 *p;
  u8 *q;
  u8 *r;
  Spr *s;
  Obj *o;
  s32 x;
  s32 y;
  s32 z;
  s32 sum;
  s32 off;
  s32 n;
  u32 i;
  char *row;
  char *lrow;
  if (U(g, 0x1e) != 7)
  {
    if (U(g, 0xe) == 1)
    {
      row = (char *) g;
      row += B(g, 0x32) * 40;
      if (row[0x48] & 2)
      {
        r = func_8004240C(1);
        x = H(A(r, 0x178), 0xc);
        y = H(A(r, 0x178), 0xe);
        P = r;
        o = ((Obj *)func_80040260((void *)(a), 0, 0, (u16)((u16) c), func_8003B980, 1));
        o->x9c = x - 63;
        o->x9e = y - 42;
        s = func_80034FF0(b + 0x4c, 0);
        o->spr = s;
        o->xc = -(s->imgs[0]->w >> 1);
        o->xe = -3;
        o->flags |= 0x20;
        o->owner = P;
      }
    }
    else
    {
      i = 1;
      if (U(g, 0xe) == 2)
      {
        n = 1;
        do
        {
          lrow = (char *) G;
          lrow += B(((u8 *) G) + i, 0x31) * 40;
          if (lrow[0x48] & 2)
          {
            p = func_8004240C(n);
            q = A(p, 0x178);
            off = 0;
            P = p;
            x = H(q, 0xc);
            z = H(q, 8);
            sum = H(q, 0xa) + H(q, 0xe);
            if (!(U(G, 0x12) & 1))
            {
              x -= 16;
              off = (-(W(p, 0xc) == 1)) & 20;
            }
            o = ((Obj *)func_80040260((void *)(a), 0, 0, (u16)((u16) c), func_8003B980, 1));
            o->spr = func_80034FF0(b + 0x4c, 0);
            o->x9c = (u16)(z + x) - 35 + off;
            o->x9e = sum - 32;
            o->xc = -(o->spr->imgs[0]->w >> 1);
            o->xe = -2;
            o->flags |= 0x20;
            o->owner = P;
            o->x7a = 1;
          }
          i++;
          n += 2;
        }
        while (U(g, 0xe) >= i);
      }
    }
  }
}
