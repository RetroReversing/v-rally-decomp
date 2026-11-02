#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct
{
  u8 x[4];
} Four;
extern Four D_800A56F0;
extern u8 *D_800C35A0;
void func_8006F0E0(u8);
void func_8006F4A8(u8);
s32 func_8006F75C(void);

void func_80066B88(void)
{
  u8 a[4];
  u8 b[4];
  u8 changed;
  s8 k;
  s8 i;
  s8 j;
  s8 n;
  s8 *p;
  u8 *q;
  s8 t;

  *((Four *) a) = D_800A56F0;
  *((Four *) b) = D_800A56F0;
  changed = 0;
  q = D_800C35A0 + 0x44;
  p = (s8 *) D_800C35A0 + 0x32;
  for (k = 0; k < 2; k++)
  {
    for (i = 0; i < 4; i++)
    {
      if (q[i * 40] < 0x5B)
      {
        b[i] = 0;
      }
      for (j = 0; j < 2; j++)
      {
        if (p[j] == i)
        {
          a[p[j]] = 0;
        }
      }
    }
    if (b[p[k]])
    {
      for (i = 0; i < 4; i++)
      {
        if (a[i] && !b[i])
        {
          break;
        }
      }
      if (i == 4)
      {
        s8 *x = &p[k];
        func_8006F4A8(*x);
        q[*x * 40] = 0x50;
        q[*x * 40 + 1] = 0x4C;
        q[*x * 40 + 2] = *x + 0x41;
        func_8006F0E0(*x);
        changed = 1;
      }
      else
      {
        n = i;
        for (i = 0; i < 4 && p[i] != n; i++)
        {
        }
        t = p[k];
        p[k] = n;
        p[i] = t;
      }
    }
  }
  if (changed)
  {
    func_8006F75C();
  }
}

