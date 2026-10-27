#include "common.h"

extern s32 D_8009C230;
void func_80022A98(u8 *arg0, s32 *arg1)
{
  s32 pad[3];
  s32 *a1;
  u8 *new_var;
  s32 *a3;
  u8 *t0;
  u8 *t5;
  int new_var2;
  s32 t3;
  s32 t4;
  u32 f;
  u32 t1;
  u32 t2;
  u32 t6;
  u32 a2;
  u32 v1;
  t6 = 0;
  t1 = 0;
  a1 = arg1;
  t5 = arg0;
  do
  {
    if ((*((u32 *) ((t1 + (*((u32 *) (arg0 + 0xD0)))) + 8))) & 1)
    {
      do
      {
        a2 = 0;
        if ((*((u32 *) (t1 + (*((u32 *) (arg0 + 0xD0)))))) != 0)
        {
          new_var2 = (t6 ^ 6) < 1;
          t4 = new_var2;
          t3 = D_8009C230;
          t0 = t5;
          t2 = t1;
          a3 = a1;
          v1 = (double) 0;
          do
          {
            f = (a2 ^ 0x54) < 1;
            if (t1)
            {
            }
            if (t4 & f)
            {
              *a3 = t3 - (*((s32 *) (v1 + (*((s32 *) (t0 + 0x48))))));
            }
            else
            {
              *a3 = *((s32 *) (v1 + (*((s32 *) (t0 + 0x48)))));
            }
            a3++;
            a2++;
            v1 += 4;
          }
          while (a2 < (*((u32 *) (t2 + (*((u32 *) (arg0 + 0xD0)))))));
        }
      }
      while (0);
      a1 += *((u32 *) (t1 + (*((u32 *) (arg0 + 0xD0)))));
    }
    if ((*((u32 *) ((t1 + (*((u32 *) (arg0 + 0xD0)))) + 8))) & 2)
    {
      a2 = 0;
      new_var = (t1 + (*((u32 *) (arg0 + 0xD0)))) + 4;
      if ((*((u32 *) new_var)) != 0)
      {
        if (a3)
        {
          t2 = (u32) t5;
          t0 = (u8 *) t1;
          a3 = a1;
        }
        else
        {
          t2 = (u32) t5;
          t0 = (u8 *) t1;
          a3 = a1;
        }
        do
        {
          *a3 = *((s32 *) ((*((s32 *) (t2 + 0x74))) + (a2 * 4)));
          a2++;
          a3++;
        }
        while (a2 < (*((u32 *) ((((u32) t0) + (*((u32 *) (arg0 + 0xD0)))) + 4))));
      }
      a1 += *((u32 *) ((t1 + (*((u32 *) (arg0 + 0xD0)))) + 4));
    }
    t1 += 0x1C;
    t6++;
    t5 += 4;
  }
  while (t6 < 0xB);
}
