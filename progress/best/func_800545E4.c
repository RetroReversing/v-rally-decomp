s32 func_80098180(void *, void *);
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800B0D96;
void func_800545E4(void)
{
  u8 *new_var2;
  s32 temp_a1;
  s32 temp_v0;
  s32 temp_v1_2;
  s32 var_s1;
  s32 var_s3;
  s32 var_v0;
  u32 temp_s0;
  u32 var_v0_2;
  int new_var3;
  int new_var;
  u8 *temp_s4;
  void *s6;
  new_var2 = D_800C02AE + 0x34A8;
  var_s3 = 0;
  s6 = new_var2;
  temp_s4 = D_800AE850 + 0x2546;
  var_v0 = 0;
  do
  {
    temp_a1 = var_v0 << 6;
    new_var2 = D_800C02AE + 0x34AE;
    if ((*((u8 *) (new_var2 + temp_a1))) == 1)
    {
      var_s1 = 0;
      loop_3:
      temp_s0 = var_s1 & 0xFF;

      new_var = 0x44;
      new_var3 = (temp_s0 * 0x28) + new_var;
      if (func_80098180((void *) ((*((s32 *) (D_800C02AE + 0x32F2))) + new_var3), (void *) (((s32) s6) + temp_a1)) != 0)
      {
        var_v0_2 = var_s3 & 0xFF;
        if (temp_s0 < 4U)
        {
          var_s1 += 1;
          goto loop_3;
        }
      }
      else
      {
        ;
      }
      temp_v0 = var_s1 & 0xFF;
      if ((var_s3 & 0xFF) < 8U)
      {
        temp_v0 = temp_v0 * 5;
        *((u8 *) ((D_800AE850 + 0x2532) + temp_v0)) += 9;
        *temp_s4 += 9;
      }
      else
      {
        temp_a1 = temp_v0 * 5;
        temp_v1_2 = temp_a1;
        *((u8 *) ((D_800AE850 + 0x2533) + ((0, temp_v1_2)))) += 7;
        temp_s4[1] += 7;
      }
    }
    var_s3 += 1;
    var_v0 = var_s3 & 0xFF;
  }
  while (((short) ((u32) var_s3)) < 0xCU);
}
