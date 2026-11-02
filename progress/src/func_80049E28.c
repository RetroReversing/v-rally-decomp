extern s32 D_8009D538;
extern s32 D_8009F640;
extern s32 D_800B6880;
extern char D_800C02AE[];
extern char *D_800A0384;
extern void func_80042F40();
extern void func_80049450();
extern void func_80054838();
extern s32 func_80049DB0();
typedef struct { char pad0[0x1e]; u16 state; char pad20[0x16]; u16 f36; } Obj49E28;
s32 func_80049E28(void)
{
  Obj49E28 *p;
  int a;
  s32 z;
  D_8009F640 = (D_8009F640 | 3) & ~8;
  p = *((Obj49E28 **) (D_800C02AE + 0x32F2));
  a = p->state;
  p->f36 = 0;
  if ((a == 5) | (a == 0) || (z = (a >> 16) == 0))
  {
    u16 b = p->state;
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
