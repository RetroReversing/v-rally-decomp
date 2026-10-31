extern int D_800C8328;
s16 func_8000C9B0();
s32 func_80057918();
void *func_800592AC();
void *func_800592D0();
void *func_8007EAA0();
extern void *D_800A1468;
extern char D_800C02AE[];
void func_80057B40(s32 arg0, u16 arg1, s32 arg2, s32 arg3)
{
  void *node;
  s32 *temp_v0_6;
  s32 temp_s5;
  s16 temp_v0_3;
  s16 temp_v0_5;
  s16 var_s3;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_s0;
  s8 temp_v0_2;
  s8 temp_v0_4;
  s8 var_s1;
  void *temp_s0_2;
  void *temp_s2;
  void *temp_v1;
  void *temp_v1_2;
  node = func_8007EAA0(1, 0xC);
  temp_a1 = *((s32 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 0x10));
  temp_s5 = arg0 - (*((u8 *) (((char *) (((*((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2))) * 0x14) + temp_a1)) + 0xD)));
  var_s3 = 0;
  *((s8 *) (((char *) node) + 9)) = arg3;
  arg3 &= 0xFF;
  *((s16 *) (((char *) node) + 6)) = arg1;
  *((s8 *) (((char *) node) + 8)) = arg2;
  *((s16 *) (((char *) node) + 4)) = temp_s5;
  if (temp_s0 != 0)
  {
    var_s1 = 0;
    temp_s2 = func_800592D0(arg2 & 0xFF);
    if (temp_s0 != 0)
    {
      do
      {
        temp_a1 = func_80057918(D_800C8328, *((u16 *) (((char *) temp_s2) + 4)));
        temp_v1 = D_800A1468 + ((*((s8 *) (((char *) temp_s2) + 0xA))) * 2);
        temp_v0_3 = func_8000C9B0(D_800A1468 + (((*((u8 *) (((char *) temp_v1) + 0xD0))) * 4) + 0xE4), temp_a1, *((u8 *) (((char *) temp_v1) + 0xD1)), *((s32 *) (((char *) temp_s2) + 0x10)), 0);
        if (var_s3 < temp_v0_3)
        {
          var_s3 = temp_v0_3;
        }
        temp_v0_2 = var_s1 + 1;
        var_s1 = temp_v0_2;
      }
      while (temp_v0_2 < temp_s0);
    }
  }
  var_s1 = 0;
  temp_s0_2 = func_800592AC(temp_s5 & 0xFFFF);
  temp_a1_2 = arg1 & 0xFFFF;
  if (temp_a1_2 != 0)
  {
    temp_v1_2 = (char *) temp_s0_2;
    do
    {
      temp_a1 = func_80057918(D_800C8328, *((u16 *) (temp_v1_2 + 8)));
      temp_v1_2 = D_800A1468 + ((*((s8 *) (((char *) temp_s0_2) + 0xE))) * 2);
      temp_v0_5 = func_8000C9B0(D_800A1468 + (((*((u8 *) (((char *) temp_v1_2) + 0xD0))) * 4) + 0xE4), temp_a1, *((u8 *) (((char *) temp_v1_2) + 0xD1)), *((s32 *) (((char *) temp_s0_2) + 0x14)), 0);
      if (var_s3 < temp_v0_5)
      {
        var_s3 = temp_v0_5;
      }
      temp_v0_4 = var_s1 + 1;
      var_s1 = temp_v0_4;
    }
    while (temp_v0_4 < temp_a1_2);
  }
  *((s8 *) (((char *) node) + 0xA)) = 0;
  temp_v0_6 = *((s32 **) (((char *) D_800A1468) + 0x28));
  if (temp_v0_6 != NULL)
  {
    *temp_v0_6 = (s32) node;
  }
  else
  {
    *((s32 **) (((char *) D_800A1468) + 0x24)) = (s32 *) node;
  }
  *((s32 **) (((char *) D_800A1468) + 0x28)) = (s32 *) node;
  *((s32 *) (((char *) D_800A1468) + 0x2C)) += 1;
}
