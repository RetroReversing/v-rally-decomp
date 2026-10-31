extern unsigned char D_800C3520;
extern int D_800C816C;
extern s32 D_800A3B40;
extern char D_800C02AE[];
s32 __osContAddressCrc(u32);
u8 __osContDataCrc(void *);
s32 func_8008D8B4();
s32 func_8008D920();
s32 func_80090DC0();
s32 func_80091600();
u32 func_80097420();
s32 osRecvMesg(s32, s32, s32);
u32 func_80096830(s32 arg0, s32 arg1, u16 arg2, s32 arg3)
{
  s32 tries;
  s32 i;
  u8 *p;
  u8 *new_var;
  u32 a;
  u32 res;
  res = 0;
  func_8008D8B4();
  p = (u8 *) (D_800C02AE + 0x7E82);
  tries = 2;
  if ((D_800C3520 != 2) || (D_800A3B40 != arg1))
  {
    D_800C3520 = 2;
    D_800A3B40 = arg1;
    if (((s32) res) < arg1)
    {
      i = 0;
      do
      {
        *(p++) = 0;
        i++;
      }
      while (i < arg1);
    }
    i=0xFF;
    D_800C816C = 1;
    p[1] = 3;
    p[2] = 0x21;
    p[3] = 2;
    p[0] = i;
    p[0x26] = i;
    p[0x27] = i-1;
  }
  else
  {
    p += arg1;
  }
  a = arg2 & 0xFFFF;
  p[4] = a >> 3;
  p[5] = __osContAddressCrc(a) | (arg2 << 5);
  func_80090DC0(1, D_800C02AE + 0x7E82);
  osRecvMesg(arg0, 0, 1);
  do
  {
    func_80090DC0(0, D_800C02AE + 0x7E82);
    osRecvMesg(arg0, 0, 1);
    res = (p[2] & 0xC0) >> 4;
    if (!(res != 0))
    {
      if (__osContDataCrc(p + 6) != p[0x26])
      {
        res = func_80097420(arg0, arg1);
        if (res != 0)
        {
          break;
        }
        res = 4;
      }
      else
      {
        new_var = p;
        func_80091600(new_var + 6, arg3, 0x20);
      }
    }
    else
    {
      res = 1;
      do
      {
      }
      while (0);
    }
  }
  while ((res == 4) && ((tries--) >= 0));
  func_8008D920();
  return res;
}
