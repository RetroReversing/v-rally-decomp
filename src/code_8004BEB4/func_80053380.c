#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define G533 D_800C35A0
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern s32 D_8009D540;
void func_800535F4(void *);
void func_80098290(void *, void *);
extern u8 *D_800C35A0;
void func_80053380(void)
{
  char *__repair_addr;
  u8 *a;
  u8 *base;
  u8 *b2;
  u8 *s;
  u8 *t;
  u32 *p;
  u32 v;
  s32 i;
  s32 n;
  s32 off;
  u16 mode;
  s32 idx;
  
  u8 pi;
  a = G533;
  i = 0;
  if (*((u16 *) (a + 14)))
  {
    base = D_800AE850 + 0x6dac;
    b2 = base + 16;
    do
    {
      mode = *((u16 *) (a + 30));
      n = i & 255;
      off = n << 5;
      s = (D_800C02AE + 0x3392) + (mode << 6);
      *((s32 *) s) = *((s32 *) ((base + (mode * 4)) + off));
      t = a + n;
      pi = t[0x32];
      __repair_addr = (char *) ((a + (pi * 40)) + 78);
      s[4] = *((u16 *) __repair_addr);
      s[5] = *((u16 *) (G533 + 22));
      func_80098290(s + 6, G533 + ((*(G533 + n + 50) * 40) + 68));
      {
      u8 *g = G533;
 do { *(u32 *) ((((*((u16 *) (g + 30))) * 4) + b2) + off) /= 100; v = *((u32 *) ((((*((u16 *) (g + 30))) * 4) + b2) + off)); v = ((s32) v) * D_8009D540; idx = *((s32 *) s); s[10] = ((u32) (v * 3600)) / ((u32) (5 * (idx * 2))); } while (0);
      }
      *(u32 *) ((((*((u16 *) (G533 + 30))) * 4) + b2) + off) *= 100;
      s[11] = 0;
      s[12] = 1;
      if ((*((u16 *) (G533 + 44))) & 0x4000)
      {
        s32 idx;
        u32 v;
        idx = ((*((u16 *) (G533 + 30))) - 1) << 6;
        if (*((u8 *) ((D_800C02AE + 0x33ae) + idx)))
        {
          v = *((u32 *) ((D_800C02AE + 0x33a2) + idx));
          if (v >= 11)
          {
            *((s32 *) s) = v - 3;
          }
        }
        else
        {
          v = *((u32 *) ((D_800C02AE + 0x33a2) + idx));
          if (v >= 31)
          {
            *((s32 *) s) = v - 10;
          }
        }
      }
      func_800535F4((D_800C02AE + 0x3362) + ((*((u16 *) (G533 + 30))) << 6));
      a = G533;
      i++;
    }
    while (((u32) (i & 255)) < (*((u16 *) (a + 14))));
  }
}

