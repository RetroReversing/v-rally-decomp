extern u8 D_800C02AE[];
extern s32 D_8009D540;
extern f64 D_800A57F0;
extern f64 D_800A57F8;
extern f64 D_800A5800;
s32 func_8006BF30(s32, s32, s32, s32);
void func_8006BA44(s32 arg0, unsigned int arg1)
{
  u16 *sp14;
  f64 temp_fs0;
  f64 temp_fs1;
  f64 temp_fv1;
  s16 temp_a1;
  s32 temp_s2;
  s16 temp_s2_2;
  s16 var_s0;
  unsigned short temp_a0;
  s32 temp_s0;
  short new_var;
  s32 temp_s3;
  s32 temp_s5;
  s32 temp_s6;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a2;
  s32 var_s4;
  s32 var_t0;
  s32 var_t1;
  s32 var_v1;
  u32 temp_a0_2;
  u8 temp_t1;
  u8 temp_t1_2;
  void *temp_fp;
  void *temp_v0;
  void *temp_v0_2;
  void *var_a2_2;
  void *var_s1;
  var_a2 = 0;
  var_t0 = 0;
  temp_v1 = arg0 & 0xFF;
  temp_s6 = *((s32 *) ((D_800C02AE + 0x10386) + (temp_v1 * 4)));
  if (temp_v1 != 2)
  {
    if (temp_v1 < 3)
    {
      do
      {
        if (temp_v1 == 1)
        {
          var_t0 = 0x32;
          goto block_14;
        }
        var_t1 = arg1;
      }
      while (0);
    }
    else
    {
      switch (temp_v1)
      {
        case 3:
          var_a2 = 9;
          var_t0 = 0x3B;
          goto block_14;

        case 4:
          var_a2 = 0xF;
          var_t0 = 0x41;
          goto block_14;

        default:
          var_t1 = arg1;
          break;

      }

    }
  }
  else
  {
    var_a2 = 4;
    var_t0 = 0x36;
    block_14:
    var_t1 = arg1 + var_a2;

  }
  var_s4 = 0;
  temp_fs0 = D_800A57F0;
  temp_s3 = arg1 & 0xFF;
  sp14 = (u16 *) ((D_800C02AE + 0x5A8A) + ((var_t0 + temp_s3) * 2));
  temp_fp = (void *) (((s8 *) temp_s6) + (temp_s3 * 4));
  temp_s5 = var_t1 & 0xFF;
  temp_fs1 = ((f64) temp_s5) * D_800A57F8;
  do
  {
    temp_fv1 = temp_fs1 + (((f64) (var_s4 & 0xFF)) * D_800A5800);
    if (temp_fs0 > temp_fv1)
    {
      var_a0 = (s32) temp_fv1;
      var_v1 = temp_s5 * 8;
    }
    else
    {
      var_a0 = ((s32) (temp_fv1 - temp_fs0)) | 0x80000000;
      var_v1 = temp_s5 * 8;
    }
    temp_s0 = var_s4 & 0xFF;
    temp_a0 = var_a0 & 0xFF;
    if (((((((unsigned char) (temp_s0 * 3)) + (var_v1 + temp_s5)) * 4) - (temp_a0 * 8)) & 0xFF) == 4)
    {
      temp_v0 = (void *) ((D_800C02AE + 0x6F70) + temp_a0);
      temp_t1 = ((u8 *) temp_v0)[1];
      temp_a0_2 = ((u8) ((u8 *) temp_v0)[0]) >> 4;
      if (((temp_t1 < 0xFFU) | (((u32) (temp_a0_2 & 0xFF)) < 0xFU)) != 0)
      {
        var_s1 = (void *) ((D_800C02AE + 0x6E26) + ((temp_a0_2 & 0xF3) * 0xE));
        temp_s2 = (temp_t1 * 4) + (((u32) (temp_a0_2 & 0xC)) >> 2);
        func_8006BF30(temp_s0, arg0 & 0xFF, 0, temp_s3);
        var_a2_2 = (void *) ((((s8 *) temp_s6) + (temp_s0 * 0x10)) + (temp_s3 << 6));
        ((s8 *) var_a2_2)[0x38] = 1;
        ((s8 *) var_a2_2)[0x32] = (s8) (((((u16) (*((u16 *) var_s1))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2_2)[0x33] = (s8) (((((u16) (*((u16 *) var_s1))) >> 5) & 0x1F) + 0x41);
        var_s0 = temp_s2;
        new_var = (var_a2 = -temp_s2);
        ((s8 *) var_a2_2)[0x34] = (s8) ((((u8 *) var_s1)[1] & 0x1F) + 0x41);
        if (temp_s2 & 1)
        {
          var_s0 = new_var;
        }
        goto block_28;
      }
    }
    else
    {
      temp_v0_2 = (void *) ((D_800C02AE + 0x6F70) + temp_a0);
      temp_t1_2 = ((u8 *) temp_v0_2)[0];
      arg1 = ((u8 *) temp_v0_2)[1] & 0xF;
      if (((temp_t1_2 < 0xFFU) | (arg1 < 0xFU)) != 0)
      {
        var_s1 = (void *) ((D_800C02AE + 0x6E26) + ((arg1 >> 2) * 0xE));
        temp_s2_2 = (s16) (temp_t1_2 | ((arg1 & 3) << 8));
        func_8006BF30(temp_s0, arg0 & 0xFF, 0, temp_s3);
        var_a2_2 = (void *) ((((s8 *) temp_s6) + (temp_s0 * 0x10)) + (temp_s3 <<= 6));
        ((s8 *) var_a2_2)[0x32] = (s8) (((((u16) (*((u16 *) var_s1))) >> 0xA) & 0x1F) + 0x41);
        ((s8 *) var_a2_2)[0x33] = (s8) (((((u16) (*((u16 *) var_s1))) >> 5) & 0x1F) + 0x41);
        var_s0 = temp_s2_2;
        temp_t1 = (((u8 *) var_s1)[1] & 0x1F) + 0x41;
        ((s8 *) var_a2_2)[0x38] = 1;
        ((s8 *) var_a2_2)[0x34] = (s8) temp_t1;
        if (temp_s2_2 & 1)
        {
          var_s0 = -temp_s2_2;
        }
        block_28:
        temp_a1 = (s16) ((*sp14) - var_s0);

        if (var_s4)
        {
          *((s32 *) (((s8 *) var_a2_2) + 0x2C)) = (s32) temp_a1;
          ((s8 *) var_a2_2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) var_s1))) >> 0xF) * 0x10));
          ((s8 *) var_a2_2)[0x36] = (s8) (((u32) (((*((s32 *) (((s8 *) temp_fp) + 0x22C))) * D_8009D540) * 0xE10)) / ((u32) (temp_a1 * 0x3E8)));
        }
        else
        {
          *((s32 *) (((s8 *) var_a2_2) + 0x2C)) = (s32) temp_a1;
          ((s8 *) var_a2_2)[0x30] = (s8) ((((u16) (*((u16 *) (((s8 *) var_s1) + 2)))) >> 0xC) + ((((u16) (*((u16 *) var_s1))) >> 0xF) * 0x10));
          ((s8 *) var_a2_2)[0x36] = (s8) (((u32) (((*((s32 *) (((s8 *) temp_fp) + 0x22C))) * D_8009D540) * 0xE10)) / ((u32) (temp_a1 * 0x3E8)));
        }
      }
    }
    var_s4 += 1;
  }
  while (((u32) (var_s4 & 0xFF)) < 3U);
}
