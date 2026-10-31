extern u8 D_800C02AE[];
extern u8 D_800C7124[];
extern u8 D_800C70D4[];
extern s32 D_800ADF70;
void func_8006BF30(s32, s32, s32, s32);
void func_8006CCD0(void)
{
  u16 *new_var;
  int __repair_literal;
  s32 i = 0;
  u32 x;
  s32 j;
  s32 off;
  u8 *p;
  do
  {
    j = i & 255;
    new_var = (u16 *) D_800C7124;
    x = new_var[j + 0xD1];
    if (x != 65535)
    {
      p = D_800C70D4 + ((x >> 14) * 14);
      func_8006BF30(j, 24, 0, 0);
      __repair_literal = 16;
      off = j * __repair_literal;
      D_800C02AE[0x37A8 + off] = (((*((u16 *) p)) >> 10) & 31) + 65;
      D_800C02AE[0x37A9 + off] = (((*((u16 *) p)) >> 5) & 31) + 65;
      x &= 0x3FFF;
      D_800C02AE[0x37AA + off] = (p[1] & 31) + 65;
      if (x & 1)
      {
        x = -x;
      }
      x = D_800ADF70 - x;
      *((s32 *) ((D_800C02AE + 0x37A2) + off)) = x;
      D_800C02AE[0x37A6 + off] = ((*((u16 *) (p + 2))) >> 12) + (((*((u16 *) p)) >> 15) * 16);
    }
    i++;
  }
  while (((u32) (255 & i)) < 3);
}
