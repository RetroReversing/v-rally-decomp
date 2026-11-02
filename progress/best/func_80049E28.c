extern s32 D_8009D538;
extern s32 D_8009F640;
extern s32 D_800B6880;
extern char D_800C02AE[];
extern char *D_800A0384;
extern void func_80042F40();
extern void func_80049450();
extern void func_80054838();
extern s32 func_80049DB0();
s32 func_80049E28(void)
{
  char *p = *((char **) (D_800C02AE + 0x32F2));
  int a = *(u16 *)(p + 0x1e);
  D_8009F640 = (D_8009F640 | 3) & ~8;
  *(u16 *)(p + 0x36) = 0;
  if ((a == 5) | (a == 0) || (a >> 16) == 0 || (u32)a < 0x10000)
  {
    u16 b = *(u16 *)(p + 0x1e);
    D_800B6880 = 2;
    if (b == 0 && (u8)func_80049DB0() == 1)
    {
      func_80042F40();
      func_80054838();
      D_800A0384[0x384] = 0;
      return 0;
    }
  }
  else
  {
    D_800B6880 = 5;
  }
  D_800A0384[0x384] = 0;
  if (D_8009D538 & 0x4000)
  {
    func_80049450();
  }
  *(u8 *)(D_800C02AE + 0x7E72) = 0;
  return 1;
}
