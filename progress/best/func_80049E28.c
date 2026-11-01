extern s32 D_8009D538;
extern s32 D_8009F640;
extern char D_800AE850[];
extern char D_800C02AE[];
extern char *D_800A0384;
extern void func_80042F40();
extern void func_80049450();
extern void func_80054838();
extern s32 func_80049DB0(int, void *);
s32 func_80049E28(void)
{
  u16 new_var;
  u16 *new_var3;
  int a;
  int new_var2;
  char *p = *((char **) (D_800C02AE + 0x32F2));
  new_var3 = &(*((u16 *) (p + 0x1e)));
  a = *new_var3;
  D_8009F640 = (D_8009F640 | 3) & (~8);
  *((u16 *) (p + 0x36)) = 0;
  new_var2 = a;
  new_var2 = ((u16) a) == new_var2;
  if ((a == 5) | (a == 0))
  {
    *((s32 *) (D_800AE850 + 0x8030)) = 2;
    if (((*((u16 *) (p + 0x1e))) == 0) && ((func_80049DB0(a, p) & 255) == 1))
    {
      func_80042F40();
      func_80054838();
      D_800A0384[0x384] = 0;
      return 0;
    }
  }
  else
    if (new_var2)
  {
    *((s32 *) (D_800AE850 + 0x8030)) = 2;
    new_var = *((u16 *) (p + 0x1e));
    if ((new_var == 0) && ((func_80049DB0(a, p) & 255) == 1))
    {
      func_80042F40();
      func_80054838();
      D_800A0384[0x384] = 0;
      return 0;
    }
  }
  else
  {
    *((s32 *) (D_800AE850 + 0x8030)) = 5;
  }
  D_800A0384[0x384] = 0;
  new_var2 = 0x4000;
  if (D_8009D538 & new_var2)
  {
    func_80049450();
  }
  *((u8 *) (D_800C02AE + 0x7E72)) = 0;
  return 1;
}

