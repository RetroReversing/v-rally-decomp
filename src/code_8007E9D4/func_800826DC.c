#include "common.h"

s32 func_8008260C();
void func_800826DC(s32 *arg0)
{
  s32 n;
  s32 done;
  s32 a;
  s32 b;
  s32 flag;

  n = arg0[0x1F];
  done = 0;
  flag = (n < 2) ^ 1;
  if (flag)
  {
    do
    {
      if (func_8008260C(arg0[n + 0x20], arg0[n + 0x1F]) != 0)
      {
        done = 1;
      }
      else
      {
        a = arg0[n + 0x1F];
        b = arg0[n + 0x20];
        arg0[n + 0x20] = a;
        arg0[n + 0x1F] = b;
      }
      n--;
    }
    while ((n >= 2) & (done == 0));
  }
}
