#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern u8 D_800C02AE[];
void func_80020098(u8 *arg0, u8 arg1)
{
  u8 i, j, k;
  u8 prev, cur;
  u8 *dst;
  k = 0;

  cur = arg0[0x93];
  for (i = 0; i < *(s32 *)(arg0 + 0x44) - 1; i++)
  {
    prev = cur;
    cur = arg0[i * 0x4C + 0xDF];
    for (j = 0; j < 10; j++)
    {
      D_800C02AE[0x5BAA + arg1 * 0x81 + k] = prev + j * (cur - prev) / 10;
      if (D_800C02AE[0x5BAA + arg1 * 0x81 + k] >= 0x80) D_800C02AE[0x5BAA + arg1 * 0x81 + k] = 0x7F;
      if (k < 0x80) k++;
    }
  }
  D_800C02AE[0x5C2A + arg1 * 0x81] = cur;
}
