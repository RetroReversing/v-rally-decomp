#define SEL D_800C35A0
#define H(off) (*(u16 *)(SEL+(off)))
#define TAB(i) (*(s32 *)(D_800C02AE+0x10386+(i)*4))
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 D_800A1530[];
extern u8 D_800A1548[];
extern u16 D_800A1504[];
extern u16 D_800A150C[];
extern u16 D_800A1514[];
extern u16 D_800A1520[];
extern u16 D_800A1528;
extern u16 D_800A152A;
extern u16 D_800A152C;
extern s8 *D_800A1468;
extern u8 D_800A14D5;
extern s32 D_800A14DC;
void func_800584D4(void);
u8 *func_800592D0(s32);
void func_8005A05C(s32);
s32 func_800602F4(s32, u16);
extern u8 *D_800C35A0;
void func_800603B4(void)
{
  s32 n;
  s32 mask;
  int new_var;
  s32 i;
  s32 base;
  u16 a;
  unsigned int b;
  u8 *p;
  f32 f;
  a = H(0x22);
  n = func_800602F4((TAB(H(0x1E)) + (H(0x20) * 0x2C4)) + (new_var = (a * 14) + 0x24C), a);
  func_800584D4();
  D_800A14DC = 0;
  D_800A1468[0x233] = -1;
  *((u16 *) (func_800592D0(5) + 4)) = D_800A1504[D_800A1530[n & 255]];
  *((u16 *) (func_800592D0(13) + 4)) = D_800A150C[D_800AE850[0x1300 + (SEL[0x2E] * 28)]];
  *((u16 *) (func_800592D0(9) + 4)) = D_800A1514[D_800AE850[0x1301 + (SEL[0x2E] * 28)]];
  *((u16 *) (func_800592D0(7) + 4)) = D_800A1520[D_800AE850[0x1302 + (SEL[0x2E] * 28)]];
  p = func_800592D0(11);
  f = *((f32 *) ((D_800AE850 + 0x1304) + (SEL[0x2E] * 28)));
  if (f <= 118.0f)
  {
    *((u16 *) (p + 4)) = D_800A1528;
  }
  else
    if (f <= 132.0f)
  {
    *((u16 *) (p + 4)) = D_800A152A;
  }
  else
  {
    *((u16 *) (p + 4)) = D_800A152C;
  }
  a = H(0x1E);
  if (((((u32) (a - 1)) < 2) || (((u32) (a - 3)) < 2)) || (((b = H(0x20)) < 8) && ((mask = 1 << H(0x22), (D_800C02AE[0x807E + b] & mask) != mask))))
  {
    D_800A14D5 = 1;
  }
  else
  {
    D_800A14D5 = 0;
  }
  i = 0;
  a = H(0x1E);
  do
  {
    if (a == 5)
    {
      b = H(0x20);
      if (b < 8)
      {
        base = (b * 0x2C4) + TAB(0);
        goto common;
      }
      base = D_800A1548[b];
      base = (base * 0x2C4) + TAB(0);
      p = (u8 *) (base + (((i & 255) * 16) + ((((*((u8 *) (base + 0x15))) + H(0x22)) - 2) << 6)));
    }
    else
    {
      base = (H(0x20) * 0x2C4) + TAB(a);
      common:
      p = (u8 *) (base + (((i & 255) * 16) + (H(0x22) << 6)));

    }
    do
    {
      D_800A14DC += *((s32 *) (p + 0x2C));
    }
    while (0);
    i++;
  }
  while (((u32) (i & 255)) < 3);
  if ((H(0x1E) != 5) || (D_800A14D5 == 0))
  {
    D_800A14DC /= 3;
  }
  if (((*((s16 *) ((*((u8 **) (D_800C02AE + 0x325A))) + 2))) == 4) && (H(0x22) == 0))
  {
    func_8005A05C(1);
  }
  D_800A1468[0x22B] = -1;
}
