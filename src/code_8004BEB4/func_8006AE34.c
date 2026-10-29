#include "snapshot29_0433f7af8f6d.h"

extern void *D_800A1468;
extern u16 D_800A16E0[];
extern void *D_800C35A0;
s32 func_8006204C(u8, u8, u8);
void *func_8005A744(s32, s32);
s32 func_800592F4(s32, s32);
void func_8006AE34(void)
{
  s8 a;
  s16 q;
  s16 x;
  s32 z;
  s32 y;
  s32 w;
  s32 new_var;
  u8 k;
  char index;
  void *p;
  void *b;
  void *c;
  void *base;
  void *t = D_800A1468;
  b = D_800C35A0;
  a = *((s8 *) (((u8 *) t) + 0x228));
  b = ((u8 *) b) + a;
  index = *((u8 *) (((u8 *) b) + 0x32));
  *((s8 *) (((u8 *) t) + 0x22b)) = a;
  base = D_800C35A0;
  index = (s8) index;
  p = ((u8 *) base) + ((((s32) index) * 0x28) + 0x44);
  if ((*((u16 *) (((u8 *) base) + 0x1e))) == 0)
  {
    k = 0x1e;
  }
  else
  {
    k = 0x14;
    if ((*((u16 *) (((u8 *) base) + 0x1e))) == 5)
    {
      k = 0x2d;
    }
  }
  w = k & 255;
  new_var = func_8006204C(*((u8 *) (((u8 *) D_800C35A0) + 0x1f)), *((u8 *) (((u8 *) D_800C35A0) + 0x21)), *((u8 *) (((u8 *) D_800C35A0) + 0x23)));
  y = new_var;
  t = func_8005A744(0, *((s32 *) D_800A1468));
  y &= 255;
  z = y * 2;
  *((u16 *) (((u8 *) t) + 4)) = D_800A16E0[z / 2];
  func_800592F4(w, *((u8 *) (((u8 *) p) + 9)));
  c = ((u8 *) p) + y;
  func_800592F4(w + 1, *((u8 *) (((u8 *) c) + 0x10)));
  x = *((s16 *) (((u8 *) (z + ((s32) p))) + 0x1c));
  func_800592F4(w + 2, (-((s16) (x / 10))) + 2);
  func_800592F4(w + 3, *((u8 *) (((u8 *) c) + 0x18)));
  func_800592F4(w + 4, *((u8 *) (((u8 *) c) + 0x14)));
  {
    void *out = func_8005A744(2, *((s32 *) D_800A1468));
    q = 0x128;
    index = (*((s8 *) (((u8 *) D_800A1468) + 0x228))) == 0;
    if (index)
    {
      q = 0x126;
    }
    *((s16 *) (((u8 *) out) + 4)) = q;
  }
}
