#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800A3B40;
extern u8 D_800C02AE[];
extern u8 D_800C3520;
extern s32 osRecvMesg(s32, void *, s32);
extern void func_8008D8B4(void);
extern void func_8008D920(void);
extern void func_80090DC0(s32, void *);
extern void func_80091600(void *, void *, s32);
extern s32 __osContAddressCrc(u32);
extern s32 __osContDataCrc(void *);
extern u32 func_80097420(s32, s32);
u32 func_80096A10(s32 arg0, s32 arg1, u16 arg2, void *arg3, s32 arg4)
{
  u8 scratch[8];
  u8 *p = D_800C02AE + 0x7e82;
  s32 tries = 2;
  s32 raw;
  u32 res;
  s32 i;
  u32 a;
  if ((arg4 != 1) & (((u32) arg2) < 7U))
  {
    if (arg2 != 0)
    {
      return 0;
    }
  }
  func_8008D8B4();
  if ((D_800C3520 != 3) || (D_800A3B40 != arg1))
  {
    D_800C02AE[0x3272] = 3;
    D_800A3B40 = arg1;
    i = 0;
    if (arg1 > 0)
    {
      do
      {
        *(p++) = 0;
        i++;
      }
      while (i < arg1);
    }
    *((s32 *) (D_800C02AE + 0x7ebe)) = 1;
    p[0] = (i = 255);
    p[1] = 0x23;
    p[2] = 1;
    p[3] = 3;
    p[0x26] = i;
    p[0x27] = 254;
  }
  else
  {
    p += arg1;
  }
  a = arg2 & 0xffff;
  p[4] = a >> 3;
  p[5] = __osContAddressCrc(a) | (arg2 << 5);
  func_80091600(arg3, p + 6, 32);
  func_80090DC0(1, D_800C02AE + 0x7e82);
  raw = __osContDataCrc(arg3);
  osRecvMesg(arg0, 0, 1);
  do
  {
    func_80090DC0(0, D_800C02AE + 0x7e82);
    osRecvMesg(arg0, 0, 1);
    res = (p[2] & 0xc0) >> 4;
    if (res == 0)
    {
      if (((u32) ((void *) (raw & 255))) != p[0x26])
      {
        res = func_80097420(arg0, arg1);
        if (res != 0)
        {
          break;
        }
        res = 4;
      }
    }
    else
    {
      res = 1;
    }
  }
  while ((res == 4) && ((tries--) >= 0));
  func_8008D920();
  return res;
}
