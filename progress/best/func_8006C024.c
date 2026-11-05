extern int D_800D0634;
s32 func_8006B9E0();
s32 func_8006BF30();
extern s32 D_8009D540;
extern f64 D_800A5878;
extern f64 D_800A5880;
extern f64 D_800A5888;
extern char D_800C02AE[];
void func_8006C024(s32 arg0, s32 arg1)
{
  u16 *sp14;
  f64 temp_fs0;
  f64 temp_fs1;
  f64 temp_fv1;
  s16 temp_a1;
  s16 temp_s2;
  s16 temp_s2_2;
  s16 var_s0;
  s32 temp_a0;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s5;
  s32 temp_s6;
  s32 var_a0;
  s32 var_s3;
  s32 var_v1;
  u32 temp_a0_3;
  u32 temp_t0;
  u8 temp_t1;
  u8 temp_t1_2;
  char *new_var;
  void *temp_v0;
  s8 new_var2;
  void *temp_v0_2;
  void *var_a2;
  void *var_s1;
  var_a0 = arg0 & 0xFF;
  temp_s0 = arg1 & 0xFF;
  var_s3 = 0;
  temp_fs0 = D_800A5878;
  temp_s6 = D_800D0634 + (var_a0 * 0x2C4);
  temp_s5 = func_8006B9E0(var_a0, temp_s0) & 0xFF;
  if (1)
  {
    sp14 = (char *) (temp_s5 * 2);
    sp14 += (s32) (D_800C02AE + 0x5A8A);
    temp_fs1 = ((f64) temp_s5) * D_800A5880;
  }
  do
  {
    temp_s0_2 = var_s3 & 0xFF;
    temp_fv1 = temp_fs1 + (((f64) temp_s0_2) * D_800A5888);
    if (temp_fs0 > temp_fv1)
    {
      var_a0 = (s32) temp_fv1;
      var_v1 = temp_s5 * 8;
    }
    else
    {
      do
      {
        var_a0 = ((s32) (temp_fv1 - temp_fs0)) | 0x80000000;
      }
      while (0);
      var_v1 = temp_s5 * 8;
    }
    temp_s0_2 = var_s3 & 0xFF;
    temp_a0 = var_a0 & 0xFF;
    if ((((((temp_s0_2 * 3) + (var_v1 + temp_s5)) * 4) - (temp_a0 * 8)) & 0xFF) == 4)
    {
      temp_v0 = (D_800C02AE + 0x6E77) + temp_a0;
      temp_t1 = *((u8 *) (((char *) temp_v0) + 1));
      temp_a0 = ((u8) (*((u8 *) (((char *) temp_v0) + 0)))) >> 4;
      temp_t0 = ((u32) (temp_a0 & 0xC)) >> 2;
      if (((temp_t1 < 0xFFU) | (((u32) (temp_a0 & 0xFF)) < 0xFU)) != 0)
      {
        var_s1 = ((temp_a0 & 0xF3) * 0xE) + (D_800C02AE + 0x6E26);
        temp_s2 = (temp_t1 * 4) + temp_t0;
        func_8006BF30(temp_s0_2, 0, arg0 & 0xFF, temp_s0);
        var_a2 = temp_s6 + ((temp_s0_2 * 0x10) + (temp_s0 << 6));
        *((s8 *) (((char *) var_a2) + 0x32)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xA) & 0x1F) + 0x41);
        *((s8 *) (((char *) var_a2) + 0x33)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 5) & 0x1F) + 0x41);
        var_s0 = temp_s2;
        *((s8 *) (((char *) var_a2) + 0x34)) = (new_var2 = (s8) (((*((u8 *) (((char *) var_s1) + 1))) & 0x1F) + 0x41));
        *((s8 *) (((char *) var_a2) + 0x38)) = 1;
        if (temp_s2 & 1)
        {
          var_s0 = -temp_s2;
        }
        goto block_13;
      }
    }
    else
    {
      temp_v0_2 = temp_a0 + (D_800C02AE + 0x6E77);
      temp_t1_2 = *((u8 *) (((char *) temp_v0_2) + 0));
      temp_t0 = (*((u8 *) (((char *) temp_v0_2) + 1))) & 0xF;
      if (((temp_t1_2 < 0xFFU) | (temp_t0 < 0xFU)) != 0)
      {
        var_s1 = ((temp_t0 >> 2) * 0xE) + (D_800C02AE + 0x6E26);
        temp_s2_2 = temp_t1_2 | ((temp_t0 & 3) << 8);
        func_8006BF30(temp_s0_2, 0, arg0 & 0xFF, temp_s0);
        var_a2 = temp_s6 + ((temp_s0_2 * 0x10) + (temp_s0 << 6));
        *((s8 *) (((char *) var_a2) + 0x32)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xA) & 0x1F) + 0x41);
        *((s8 *) (((char *) var_a2) + 0x33)) = (s8) (((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 5) & 0x1F) + 0x41);
        var_s0 = temp_s2_2;
        temp_t1 = ((*((u8 *) (((char *) var_s1) + 1))) & 0x1F) + 0x41;
        *((s8 *) (((char *) var_a2) + 0x38)) = 1;
        *((s8 *) (((char *) var_a2) + 0x34)) = (s8) temp_t1;
        if (temp_s2_2 & 1)
        {
          var_s0 = -temp_s2_2;
        }
        new_var = (char *) var_a2;
        block_13:
        temp_a1 = (*sp14) - var_s0;

        *((s32 *) (new_var + 0x2C)) = (s32) temp_a1;
        *((s8 *) (new_var + 0x30)) = (s8) ((((u16) (*((u16 *) (((char *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) (((char *) var_s1) + 0)))) >> 0xF) * 0x10));
        *((s8 *) (((char *) var_a2) + 0x36)) = (s8) (((u32) (((*((s32 *) (((char *) ((temp_s0 *= 4) + temp_s6)) + 0x22C))) * D_8009D540) * 0xE10)) / ((u32) (temp_a1 * 0x3E8)));
      }
    }
    do
    {
      do
      {
        var_a2 = temp_s6 + ((temp_s0_2 * 0x10) + (temp_s0 << 6));
        do
        {
          var_s3 += 1;
        }
        while (0);
      }
      while (0);
    }
    while (0);
  }
  while (((u32) (var_s3 & 0xFF)) < 3U);
}

