#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define sp18 buf.h
#define sp1A buf.c
typedef struct 
{
  u8 p[6];
  s16 x;
  u16 y;
  u8 pad;
  u8 q;
  u8 r;
  u8 g;
  u8 b;
  u8 a;
} Sp;
typedef struct 
{
  u8 p[0x20];
  u16 a;
  u16 b;
} Sel;
extern u8 *D_800D0634;
extern Sel *D_800C35A0;
s32 func_80052E94(u16, void *);void *func_800592D0(u32);
s32 func_80059618(void *, s32, s32, s32, s32);
void func_800596F4(void *, s16, s16, void *);
s32 memset(void *, s32, s32);
s32 func_800980D0(void *, void *);
s32 func_80099DF8(void *, void *, s32, void *);
extern char D_800A5684[];
extern s16 D_800A568C;
extern s8 D_800A568E;
extern char D_800A5690[];
static inline s32 *inline_fn(u8 *arg0, unsigned char arg1, int arg2)
{
  return (s32 *) ((arg0 + ((arg1 * 0x10) + (D_800C35A0->b << arg2))) + 0x2C);
}

void func_80062E68(void)
{
  struct 
  {
    s16 h;
    s8 c;
    s8 pad[13];
  } buf;
  s32 first = 0;
  s16 *new_var2;
  void *bp;
  Sp *u;
  s32 *new_var;
  Sp *s;
  unsigned char i;
  s32 v;
  s32 n;
  s = func_800592D0(0x10);
  memset(&sp18, 0, 0xF);
  n = 0;
  do
  {
    i = n & 0xFF;
    func_80099DF8(&sp18, D_800A5684, i + 1, (((D_800D0634 + (D_800C35A0->a * 0x2C4)) + ((D_800C35A0->b << 6) + 0x2C)) + (i * 0x10)) + 6);
    n++;
    func_80059618(s, s->q, s->r, s->g, s->b);
    func_800596F4((void *)(s), (s16)(s->x), (s16)(s->y + (i * 0x16)), (void *)(&sp18));
  }
  while (3U > ((u32) (n & 0xFF)));
  s = func_800592D0(0x12);
  u = func_800592D0(0x11);
  n = 0;
  bp = &buf;
  do
  {
    i = n & 0xFF;
    new_var = inline_fn(D_800D0634 + (177 * (D_800C35A0->a * 4)), i, 6);
    new_var2 = &u->x;
    v = *new_var;
    memset(&sp18, 0, 0xF);
    func_80052E94(v, &sp18);
    func_800596F4((void *)(s), (s16)(s->x), (s16)(s->y + (i * 0x16)), (void *)(&sp18));
    if (i == 0)
    {
      first = v;
    }
    else
    {
      memset(&sp18, 0, 0xF);
      {
        s32 t1 = D_800A568C;
        s32 t2 = D_800A568E;
        sp18 = t1;
        sp1A = t2;
      }
      if (s)
      {
        func_80052E94(v - first, &sp1A);
        func_800980D0(bp, D_800A5690);
        func_800596F4((void *)(u), (s16)(*new_var2), (s16)(u->y + (((i) - 1) * 0x16)), (void *)(bp));
      }
      else
      {
        func_80052E94(v - first, &sp1A);
        func_800980D0(bp, D_800A5690);
        func_800596F4((void *)(u), (s16)(*new_var2), (s16)(u->y + ((((unsigned int) i) - 1) * 0x16)), (void *)(bp));
      }
    }
    n++;
  }
  while (((u32) (n & 0xFF)) < 3U);
}

