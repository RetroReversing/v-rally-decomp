#include "common.h"

s32 func_8002D830();
void func_8002DB18(s16 *arg0, s16 *arg1, s16 *arg2)
{
  u16 tmp[3][3];
  s32 pad[2];
  s32 sum;
  s32 val;
  s16 *row;
  s16 i;
  s16 j;
  s16 k;
  func_8002D830();
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      sum = 0;
      k = 0;
      row = arg0 - (-(j * 3));
      for (; k < 3; k++)
      {
        sum += row[k] * (*((s16 *) ((((u8 *) arg1) + (k * 6)) + (i * 2))));
      }

      if (sum >= 0)
      {
        val = sum;
      }
      else
      {
        val = sum + 0xFFF;
      }
      sum = val >> 12;
      tmp[j][i] = sum;
    }

  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      *((u16 *) ((((u8 *) arg2) + (j * 6)) + (i * 2))) = tmp[j][i];
    }

  }

}
