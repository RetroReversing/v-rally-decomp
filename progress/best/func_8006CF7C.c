extern s32 func_8006BF30();
extern char D_800A73E0[];
extern char D_800C02AE[];
void func_8006CF7C(s32 arg0)
{
  s32 temp_a0;
  s32 temp_s3;
  s32 var_s1;
  s32 var_s4;
  u32 temp_s0;
  u8 *temp_s2;
  s32 __repair_literal;
  u8 *base6e76;
  var_s4 = 0;
  temp_s3 = arg0 & 0xFF;
  ;
  base6e76 = D_800C02AE + 0x6E76;
  do
  {
    __repair_literal = 2;
    temp_s0 = *((u16 *) ((base6e76 + (((temp_s3 * 3) + var_s1) * __repair_literal)) + 0xE2));
    if (temp_s0 != 0xFFFF)
    {
      temp_s2 = (u8 *) ((D_800C02AE + 0x6E26) + ((temp_s0 >> 0xE) * 0xE));
      func_8006BF30(0, 0x17, temp_s3);
      temp_a0 = (var_s1 * 0x10) + (temp_s3 << 6);
      *((u8 *) ((D_800C02AE + 0x33A8) + temp_a0)) = (((*((u16 *) temp_s2)) >> 0xA) & 0x1F) + 0x41;
      *((u8 *) ((D_800C02AE + 0x33A9) + temp_a0)) = ((((*((u16 *) temp_s2)) >> 3) >> 2) & 0x1F) + 0x41;
      temp_s0 = temp_s0 & 0x3FFF;
      __repair_literal = (temp_s2[1] & 0x1F) + 0x41;
      *((u8 *) ((D_800C02AE + 0x33AE) + temp_a0)) = 1;
      *((u8 *) ((D_800C02AE + 0x33AA) + temp_a0)) = __repair_literal;
      if (temp_s0 & 1)
      {
        temp_s0 = -temp_s0;
      }
      *((s32 *) ((D_800C02AE + 0x33A2) + temp_a0)) = (*((s32 *) ((D_800A73E0 + 0x6B50) + (temp_s3 * 4)))) - temp_s0;
      *((D_800C02AE + 0x33A6) + temp_a0) = ((*((u16 *) (temp_s2 + 2))) >> 0xC) + (((*((u16 *) temp_s2)) >> 0xF) * 0x10);
    }
    var_s4 += 1;
    var_s1 = var_s4 & 0xFF;
  }
  while (((u32) (var_s4 & 0xFF)) < 3U);
}
