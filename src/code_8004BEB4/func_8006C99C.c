#include "snapshot29_0433f7af8f6d.h"

extern s32 func_8006B924(u8 *);
extern u8 D_800C02AE[];
extern u8 D_800A73E0[];
void func_8006C99C(void)
{
  u8 *s3 = D_800C02AE + 0x6FC4;
  u8 *s7 = s3 - 3;
  u8 s2 = 0;
  s32 s6 = 5;
  s32 s5 = 0xFFFF;
  s32 s4 = -2;
  s32 s0;
  s32 s1;
  s32 a1;
  s32 a2;
  u8 *a0;
  do
  {
    s0 = s2;
    s1 = s0 << 4;
    a2 = func_8006B924((D_800C02AE + 0x37E2) + s1);
    if ((a2 & 0xFF) == s6)
    {
      *((s16 *) (((u32) (s0 << 1)) + ((u32) s3))) = s5;
    }
    else
    {
      a1 = (*((s32 *) (D_800A73E0 + 0x6B94))) - (*((s32 *) ((D_800C02AE + 0x37E2) + s1)));
      if (a1 >= 0)
      {
        if (a1 >= 0x4000)
        {
          a1 = 0x3FFE;
        }
        a1 &= s4;
      }
      else
      {
        a1 = -a1;
        if (a1 >= 0x4000)
        {
          a1 = 0x3FFE;
        }
        a1 |= 1;
      }
      *((s16 *) (((u32) ((s2 & 0xFF) << 1)) + ((u32) s3))) = a1 | ((a2 & 0xFF) << 14);
      a0 = s7 - (-(s2 & 0xFF));
      *a0 = ((*a0) & 0xF0) + ((*((D_800C02AE + 0x37E6) + ((s2 & 0xFF) << 4))) & 0xF);
    }
    s0 = s2 & 0xFF;
    s1 = s0 << 4;
    a2 = func_8006B924((D_800C02AE + 0x3822) + s1);
    if ((a2 & 0xFF) == s6)
    {
      *((s16 *) ((((u32) (s0 << 1)) + ((u32) s3)) + 6)) = s5;
    }
    else
    {
      a1 = (*((s32 *) (D_800A73E0 + 0x6B98))) - (*((s32 *) ((D_800C02AE + 0x3822) + s1)));
      if (a1 >= 0)
      {
        if (a1 >= 0x4000)
        {
          a1 = 0x3FFE;
        }
        a1 &= s4;
      }
      else
      {
        a1 = -a1;
        if (a1 >= 0x4000)
        {
          a1 = 0x3FFE;
        }
        a1 |= 1;
      }
      *((s16 *) ((((u32) ((s2 & 0xFF) << 1)) + ((u32) s3)) + 6)) = a1 | ((a2 & 0xFF) << 14);
      a0 = s7 + (s2 & 0xFF);
      *a0 = ((*a0) & 0xF) + (((*((D_800C02AE + 0x3826) + ((s2 & 0xFF) << 4))) & 0xF) << 4);
    }
    s2++;
  }
  while ((s2 & 0xFF) < 3);
}
