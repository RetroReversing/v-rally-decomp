#include "common.h"

extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern s32 D_800B0108[];
extern void func_800607F0();
void func_80097F30(void *, s32, s32, void *);
static inline u16 inline_fn(u8 *arg0)
{
  return *((u16 *) (arg0 + 0x22));
}

u8 func_80060820(s32 arg0)
{
  u8 sp10[4];
  u8 i;
  u8 j;
  u16 count;
  s32 sum;
  u8 *base;
  u8 *tbl;
  s32 *res;
  s32 sel = arg0;
  i = 0;
  base = *((u8 **) (D_800C02AE + 0x32F2));
  tbl = D_800AE850 + 0x7EC8;
  res = D_800B0108;
  for (; i < 4; i++)
  {
    count = inline_fn(base);
    sum = 0;
    for (j = 0; j < count; j++)
    {
      sum += *((s32 *) ((tbl + (j * 16)) + (i * 4)));
    }

    res[i] = sum;
  }

  for (i = 0; i < 4; i++)
  {
    sp10[i] = i;
  }

  func_80097F30(sp10, 4, 1, func_800607F0);
  return sp10[sel & 0xFF];
}
