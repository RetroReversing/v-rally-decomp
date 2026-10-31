extern s32 D_800C3558;
extern u32 D_8009B618;
extern u32 D_8009B680;
extern f64 D_800A3F10;
extern f64 D_800A3F18;
extern f64 D_800A3F20;
s32 func_8000665C(void *, s32, s32);
void func_800068C0(void *, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32, s16, s16, s32);
void func_80008B28(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8008E118(u8 *);
s32 osVirtualToPhysical(void *);
s32 func_8000C244(void *arg0, void *arg1, u32 arg2, u32 arg3, u8 *arg4, u8 arg5)
{
  u32 sp3C;
  u32 sp44;
  s32 sp4C;
  u8 sp57;
  u8 sp5F;
  f32 temp_fs0;
  f32 temp_ft0;
  f32 temp_ft0_2;
  f64 var_ft0;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_5;
  s32 temp_a1_3;
  s32 temp_a1_4;
  s32 temp_a3;
  s32 temp_a3_2;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s1;
  s32 temp_s4;
  s32 temp_v0;
  s32 temp_v0_3;
  s32 temp_v0_5;
  s32 var_a2;
  s32 var_s7;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v1;
  u32 var_s1;
  u32 var_s3;
  u8 *var_s6;
  void *temp_a0_3;
  void *temp_a0_4;
  unsigned long new_var2;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_a2;
  void *temp_s0;
  void *temp_v0_2;
  void *temp_v0_4;
  f32 new_var;
  void *temp_v0_6;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_5;
  void *temp_v1_6;
  void *temp_v1_7;
  void *temp_v1_8;
  sp3C = arg2;
  sp44 = arg3;
  var_s1 = 0;
  if (((arg2 >= 0x141U) | (arg3 >= 0xF1U)) != 0)
  {
    return 0;
  }
  if (arg5 == 0)
  {
    temp_v1_2 = *((void **) (((char *) arg1) + 0x14));
    sp5F = 1;
    *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_2) + 8);
    *((s32 *) temp_v1_2) = 0xDE000000;
    *(((s32 *) temp_v1_2) + 1) = (s32) (&D_8009B680);
  }
  else
    if (arg5 == 1)
  {
    temp_a0_3 = *((void **) (((char *) arg1) + 0x14));
    temp_v1_2 = (void *) temp_a0_3;
    sp5F = 2;
    *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_2) + 8);
    *((s32 *) temp_v1_2) = 0xDE000000;
    *(((s32 *) temp_v1_2) + 1) = (s32) (&D_8009B618);
  }
  else
    if (arg5 == 2)
  {
    temp_v1_2 = *((void **) (((char *) arg1) + 0x14));
    sp5F = 2;
    *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_2) + 8);
    *((s32 *) temp_v1_2) = 0xDE000000;
    *(((s32 *) temp_v1_2) + 1) = (s32) (&D_8009B680);
  }
  else
  {
    sp5F = 1;
  }
  temp_a1 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_a1) + 8);
  *((s32 *) temp_a1) = 0xFA000000;
  *(((s32 *) temp_a1) + 1) = ((((*((u8 *) (((char *) arg0) + 4))) << 0x18) | ((*((u8 *) (((char *) arg0) + 5))) << 0x10)) | ((*((u8 *) (((char *) arg0) + 6))) << 8)) | (*((u8 *) (((char *) arg0) + 7)));
  temp_s0 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_s0) + 8);
  *((s32 *) temp_s0) = 0xFD900000;
  var_s1 = (*((s32 *) (((char *) arg0) + 0x10))); var_s1 += 8;
  *(((s32 *) temp_s0) + 1) = osVirtualToPhysical(*((void **) var_s1));
  temp_v1_3 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_3) + 8);
  *((s32 *) temp_v1_3) = 0xF5900000;
  *(((s32 *) temp_v1_3) + 1) = 0x07080200;
  temp_v1_4 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_4) + 8);
  *((s32 *) temp_v1_4) = 0xE6000000;
  *(((s32 *) temp_v1_4) + 1) = 0;
  temp_v1_5 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_5) + 8);
  *((s32 *) temp_v1_5) = 0xF3000000;
  temp_a0 = *((s32 *) ((*((s32 *) (((char *) arg0) + 0x10))) + 0xC));
  var_v0 = temp_a0;
  if (temp_a0 < 0)
  {
    var_v0 = temp_a0 + 0xF;
  }
  temp_v0 = var_v0 >> 4;
  var_v0 = 0x800;
  if (temp_v0 > 0)
  {
    var_v0 = temp_v0 + 0x7FF;
  }
  temp_v0_2 = *((void **) (((char *) arg0) + 0x10));
  temp_a0_2 = *((s32 *) (((char *) temp_v0_2) + 0xC));
  var_v1 = (((s32) ((temp_a0_2 * (*((s32 *) (((char *) temp_v0_2) + 0x10)))) + 3)) >> 2) - 1;
  if (var_v1 >= 0x800)
  {
    var_v1 = 0x7FF;
  }
  var_a2 = temp_a0_2;
  temp_a3 = ((var_v1 & 0xFFF) << 0xC) | 0x07000000;
  new_var2 = 6;
  if (temp_a0_2 < 0)
  {
    var_a2 = temp_a0_2 + 0xF;
  }
  temp_v0_3 = var_a2 >> 4;
  if (temp_v0_3 > 0)
  {
    var_v0_2 = (var_v0 / temp_v0_3) & 0xFFF;
  }
  else
  {
    var_v0_2 = var_v0 & 0xFFF;
  }
  *(((s32 *) temp_v1_5) + 1) = temp_a3 | var_v0_2;
  temp_v1_6 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_v1_6) + 8);
  *((s32 *) temp_v1_6) = 0xE7000000;
  *(((s32 *) temp_v1_6) + 1) = 0;
  temp_a0_3 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_a0_3) + 8);
  temp_a0 = *((s32 *) ((*((s32 *) (((char *) arg0) + 0x10))) + 0xC));
  *(((s32 *) temp_a0_3) + 1) = 0x80200;
  *((s32 *) temp_a0_3) = (((((temp_a0 >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5800000;
  temp_a1_2 = *((void **) (((char *) arg1) + 0x14));
  *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_a1_2) + 8);
  *((s32 *) temp_a1_2) = 0xF2000000;
  temp_v0_4 = *((void **) (((char *) arg0) + 0x10));
  var_s3 = sp3C;
  var_s7 = 0;
  sp57 = 1;
  *(((s32 *) temp_a1_2) + 1) = (((((*((s32 *) (((char *) temp_v0_4) + 0xC))) - 1) * 4) & 0xFFF) << 0xC) | ((((*((s32 *) (((char *) temp_v0_4) + 0x10))) - 1) * 4) & 0xFFF);
  temp_v0_5 = func_8008E118(arg4);
  sp4C = temp_v0_5;
  if (temp_v0_5 > 0)
  {
    var_s6 = arg4;
    do
    {
      temp_a3_2 = (*var_s6) - 0x20;
      temp_a1_3 = temp_a3_2 & 0xFF;
      if (temp_a1_3 != 0)
      {
        temp_a0_4 = (void *) ((temp_a1_3 * 0x10) + (*((s32 *) (((char *) arg0) + 0x18))));
        if ((*((s16 *) temp_a0_4)) != (-0x80))
        {
          if (sp57 != 0)
          {
            temp_ft0 = *((f32 *) (((char *) arg0) + 0x820));
            var_s7 = (s32) (((f32) (*((s8 *) (((char *) temp_a0_4) + 7)))) * temp_ft0);
            sp57 = 0;
            if ((D_800C3558 == 3) && (((((u32) ((temp_a3_2 - 3) & 0xFF)) < 2U) | (temp_a1_3 == new_var2)) != 0))
            {
              var_s7 = (s32) (((f64) var_s7) - (((f64) (temp_ft0 * 3.0f)) - D_800A3F10));
            }
          }
          temp_s4 = (temp_a3_2 & 0xFF) * 0x10;
          temp_v1_7 = (void *) (temp_s4 + (*((s32 *) (((char *) arg0) + 0x18))));
          var_ft0 = (f64) ((s32) sp44);
          if (((s32) sp44) < 0)
          {
            var_ft0 += D_800A3F20;
          }
          var_s3 = var_s3 + (((*((s8 *) (((char *) temp_v1_7) + 6))) + var_s1) - sp5F);
          temp_s1 = (s32) ((((f64) var_s7) - (((f64) (((f32) (*((s8 *) (((char *) temp_v1_7) + 7)))) * (*((f32 *) (((char *) arg0) + 0x820))))) + D_800A3F18)) + var_ft0);
          temp_fs0 = (f32) ((s32) var_s3);
          temp_s0_2 = func_8000665C(arg1, 4, temp_a3_2) & 0xFFFF;
          temp_ft0_2 = (f32) temp_s1;
          new_var = *((f32 *) (((char *) arg0) + 0x820));
          func_800068C0(arg1, temp_s0_2, (s16) var_s3, (s16) ((s32) (temp_ft0_2 + (((f32) (*((u8 *) (((char *) temp_v1_7) + 5)))) * new_var))), 0, (s16) ((s32) (temp_fs0 + (((f32) (*((u8 *) ((temp_s4 + (*((s32 *) (((char *) arg0) + 0x18)))) + 4)))) * (*((f32 *) (((char *) arg0) + 0x81C)))))), (s16) ((s32) (temp_ft0_2 + (((f32) (*((u8 *) ((temp_s4 + (*((s32 *) (((char *) arg0) + 0x18)))) + 5)))) * (*((f32 *) (((char *) arg0) + 0x820)))))), 0, (s16) ((s32) (temp_fs0 + (((f32) (*((u8 *) ((temp_s4 + (*((s32 *) (((char *) arg0) + 0x18)))) + 4)))) * (*((f32 *) (((char *) arg0) + 0x81C)))))), (s16) temp_s1, 0, (s16) var_s3, (s16) temp_s1, 0);
          temp_v1_8 = (void *) (((char *) arg0) + temp_s4);
          func_80008B28(arg1, temp_s0_2, ((*((s16 *) (((char *) temp_v1_8) + 0x1C))) * 2) & 0xFFFE, ((*((s16 *) (((char *) temp_v1_8) + 0x24))) * 2) & 0xFFFE, ((*((s16 *) (((char *) temp_v1_8) + 0x1E))) * 2) & 0xFFFF, ((*((s16 *) (((char *) temp_v1_8) + 0x26))) * 2) & 0xFFFF, ((*((s16 *) (((char *) temp_v1_8) + 0x20))) * 2) & 0xFFFF, ((*((s16 *) (((char *) temp_v1_8) + 0x28))) * 2) & 0xFFFF, ((*((s16 *) (((char *) temp_v1_8) + 0x22))) * 2) & 0xFFFF, ((*((s16 *) (((char *) temp_v1_8) + 0x2A))) * 2) & 0xFFFF);
          temp_a2 = *((void **) (((char *) arg1) + 0x14));
          temp_s0_3 = temp_s0_2 & 0x1F;
          temp_a1_4 = temp_s0_3 << 0x11;
          temp_a0_5 = temp_s0_3 + 2;
          temp_a0_5 = temp_a0_5 * 2;
          *((void **) (((char *) arg1) + 0x14)) = (void *) (((char *) temp_a2) + 8);
          *((s32 *) temp_a2) = ((temp_a1_4 | ((temp_s0_3 + 1) << 9)) | temp_a0_5) | 0x07000000;
          *(((s32 *) temp_a2) + 1) = (temp_a1_4 | (temp_a0_5 << 8)) | ((temp_s0_3 + 3) * 2);
          temp_v0_6 = (void *) (temp_s4 + (*((s32 *) (((char *) arg0) + 0x18))));
          var_s1 = *((s8 *) (((char *) temp_v0_6) + 8));
          var_s3 = (u32) ((s32) (temp_fs0 + (((f32) (*((u8 *) (((char *) temp_v0_6) + 4)))) * (*((f32 *) (((char *) arg0) + 0x81C))))));
        }
      }
      else
      {
        var_s3 = (u32) ((s32) (((f32) ((s32) var_s3)) + (((f32) (*((u8 *) ((*((s32 *) (((char *) arg0) + 0x18))) + 4)))) * (*((f32 *) (((char *) arg0) + 0x81C))))));
      }
      var_s6 += 1;
      var_s3 += *((u8 *) (((char *) arg0) + 8));
    }
    while (((s32) var_s6) < ((s32) (&arg4[sp4C])));
  }
  return ((var_s3 - sp3C) - (*((u8 *) (((char *) arg0) + 8)))) & 0xFFFF;
}
