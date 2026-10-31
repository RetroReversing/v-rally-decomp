#include "snapshot31_manual_verified.h"

#define v i
extern s32 func_80082930(s32, s32, s32, s32);
extern s32 func_80083C28(s32 *, s32, s32, void *, void *, s32 *, s32 *);
extern void func_800842C0(s32);
extern u8 D_800A1A6C[];
extern u8 D_800A1AAC[];
extern u8 D_800A1AEC[];
extern u8 D_800A1B28[];
extern u8 D_800C02AE[];
s32 func_800830C8(void)
{
  s32 a[0x120];
  u8 *new_var;
  s32 later;
 s32 value;
  s32 i;
  s32 *p;
  s32 *s1;
  if ((*((s32 *) (D_800C02AE + 0x30FA))) == 0)
  {
    value = 8;
    i = 0x8f;
    p = &a[0x8f];
    do
    {
      a[i] = value;
    }
    while ((--i) >= 0);
    for (i = 0x90; i < 0x100; i++)
    {
      a[i] = 9;
    }

    for (; i < 0x118; i++)
    {
      a[i] = 7;
    }

    for (; i < 0x120; i++)
    {
      a[i] = 8;
    }

    s1 = (s32 *) (D_800C02AE + 0x3102);
    *s1 = 7;
    v = func_80083C28(a, 0x120, 0x101, D_800A1A6C, D_800A1AAC, s1 - 2, s1);
    i = v;
    if (i)
    {
      *((s32 *) (s1 - 2)) = 0;
      return v;
    }
    later = 5;
    for (p = a; i < 0x1e; i++, p++)
    {
      *p = later;
    }

    new_var = D_800C02AE + 0x3106;
    ;
    *((s32 *) new_var) = 5;
    v = func_80083C28(a, 0x1e, 0, D_800A1AEC, D_800A1B28, ((s32 *)new_var) - 2, (s32 *)new_var);
    if (v >= 2)
    {
      func_800842C0(*((s32 *) (D_800C02AE + 0x30FA)));
      *((s32 *) (D_800C02AE + 0x30FA)) = 0;
      return v;
    }
  }
  v = func_80082930(*((s32 *) (D_800C02AE + 0x30FA)), *((s32 *) (D_800C02AE + 0x30FE)), *((s32 *) (D_800C02AE + 0x3102)), *((s32 *) (D_800C02AE + 0x3106)));
  return v != 0;
}
