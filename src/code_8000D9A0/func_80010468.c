#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
s32 func_8001095C();
void *func_80022318(void **, u8 *);
s32 func_80022668();
void *func_8004240C();
f32 sqrtf(f32);
extern char D_800A3FF0[];
extern char D_800AE850[];
extern char *D_800C35A0;
extern char *D_800C7F84;
typedef struct Cb { char pad[0x10]; char *arg; void (*fn)(char *); } Cb;
#define F(p, o) (*(f32 *)((char *)(p) + (o)))
#define I(p, o) (*(s32 *)((char *)(p) + (o)))
#define P(p, o) (*(char **)((char *)(p) + (o)))
void func_80010468(void)
{
  u8 count;
  u8 i;
  char *s1;
  Cb *cb;
  char *node;
  char *q;
  char *sub;
  char *obj;
  f32 dx, dy, dz;
  f32 x2, y2, z2;

  count = D_800C35A0[0xF];
  for (i = 1; i <= count; i++)
  {
    D_800C7F84 = func_8004240C(((i - 1) * 2) | 1);
    s1 = func_8004240C((i - 1) * 2 + 2);
    cb = func_80022318((void **)(D_800C7F84 + 0x28), (u8 *)(D_800A3FF0));
    if (cb == NULL)
      continue;
    cb->fn(cb->arg);
    func_8001095C(s1);
    func_80022668(cb->arg, I(cb->arg, 8));
    sub = D_800C7F84 + 0x38;
    x2 = (F(D_800C7F84, 0x124) - F(sub, 0xE0)) * (F(D_800C7F84, 0x124) - F(sub, 0xE0));
    y2 = (F(D_800C7F84, 0x128) - F(sub, 0xE4)) * (F(D_800C7F84, 0x128) - F(sub, 0xE4));
    z2 = (F(D_800C7F84, 0x12C) - F(sub, 0xE8)) * (F(D_800C7F84, 0x12C) - F(sub, 0xE8));
    if (I(D_800C7F84, 0x20) & 0x880000)
      I(s1, 0x194) = 0;
    else
      I(s1, 0x194) = sqrtf(x2 + y2 + z2);
    obj = D_800C7F84;
    I(obj, 0x194) = I(s1, 0x194);
    node = P(obj, 0x24);
    I(P(node, 0x68), 0x1C) = I(s1, 0x194);
    if (i == 1)
    {
      for (node = *(char **)P(D_800AE850, 0x73F0); node != NULL; node = P(node, 4))
      {
        if (node != P(obj, 0x24))
        {
          q = P(node, 0x5C);
          dx = (f32)I(q, 0x54) - F(sub, 0xE0);
          x2 = dx * dx;
          dy = (f32)I(q, 0x58) - F(sub, 0xE4);
          y2 = dy * dy;
          z2 = ((f32)I(q, 0x5C) - F(sub, 0xE8)) * ((f32)I(q, 0x5C) - F(sub, 0xE8));
          I(P(node, 0x68), 0x1C) = sqrtf(x2 + y2 + z2);
        }
      }
    }
  }
}

