s32 func_80034FF0(s32, s32);
void *func_80040260(s32, s16, s16, s32, s32 *, s32);
void *func_8004240C(s32);
extern s32 D_800C02AE;
extern s32 func_8003C254;
static inline static static static static int inline_fn(int arg0)
{
  return arg0;
}

void func_8003C354(s32 arg0, s32 arg1, s32 arg2)
{
  s32 sp1C;
  s16 temp_a3;
  s16 temp_s0;
  s16 temp_s0_2;
  unsigned int new_var4;
  s16 temp_s0_3;
  s32 temp_s4;
  s32 temp_s1;
  s32 temp_s1_2;
  void *new_var5;
  s32 temp_s3;
  s32 var_fp;
  s32 var_s1;
  void **new_var6;
  u16 temp_a0;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  int new_var7;
  void *temp_v0_4;
  char *new_var = (char *) (&D_800C02AE);
  void *temp_v0_6;
  int new_var2;
  unsigned int new_var3;
  void *var_s6;
  sp1C = arg0;
  temp_v0 = func_8004240C((((arg2 & 0xFFFF) - 1) * 2) | 1);
  temp_v0_2 = *((void **) (((char *) temp_v0) + 0x178));
  new_var4 = 0x7CD6;
  *((void **) (((char *) (&D_800C02AE)) + new_var4)) = temp_v0;
  temp_a3 = *((s16 *) (((char *) temp_v0_2) + 8));
  temp_s4 = *((s16 *) (((char *) temp_v0_2) + 0xC));
  temp_s0 = *((s16 *) (((char *) temp_v0_2) + 0xE));
  temp_a0 = *((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE));
  var_s1 = temp_a3 + 0x14;
  switch (temp_a0)
  {
    case 1:
      temp_s0_2 = temp_s0 - 0x14;
      temp_v0_3 = func_80040260(sp1C, (s16) (temp_s4 - 0x52), temp_s0_2, 3, &func_8003C254, 0);
      temp_s1 = arg1 + 0x4C;
      new_var3 = 0xA8;
      *((s16 *) (((char *) temp_v0_3) + 0x7A)) = 0;
      *((s16 *) (((char *) temp_v0_3) + 0x78)) = 1;
      *((s32 *) (((char *) temp_v0_3) + 0xA4)) = func_80034FF0(temp_s1, 0);
      new_var6 = (void **) (((char *) temp_v0_3) + new_var3);
      *new_var6 = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      temp_v0_4 = func_80040260(sp1C, (s16) (temp_s4 - 0x49), temp_s0_2, 3, &func_8003C254, 0);
      *((s16 *) (((char *) temp_v0_4) + 0x7A)) = 0;
      *((s16 *) (((char *) temp_v0_4) + 0x78)) = 1;
      *((void **) (((char *) temp_v0_4) + 0x8C)) = temp_v0_3;
      *((void **) (((char *) temp_v0_4) + new_var3)) = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      *((s32 *) (((char *) temp_v0_4) + 0xA4)) = func_80034FF0(temp_s1, 0);
      var_s6 = func_80040260(sp1C, (s16) (temp_s4 - 0x40), temp_s0_2, 3, &func_8003C254, 0);
      new_var5 = temp_v0_4;
      *((s16 *) (((char *) var_s6) + 0x7A)) = 0;
      *((s16 *) (((char *) var_s6) + 0x78)) = 0;
      *((void **) (((char *) var_s6) + 0x8C)) = new_var5;
      *((s32 *) (((char *) var_s6) + 0xA4)) = func_80034FF0(temp_s1, 0);
      block_7:
    *((void **) (((char *) var_s6) + new_var3)) = *((void **) (((char *) (&D_800C02AE)) + new_var4));

      return;
      new_var = (char *) (&D_800C02AE);

    case 2:
      var_fp = 0;
      if (!((*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0x12))) & 1))
    {
      var_s1 = temp_a3 + 4;
      var_fp = (-((*((s32 *) (((char *) temp_v0) + 0xC))) == 1)) & 0x14;
    }
      if (1)
    {
      temp_s1_2 = var_s1 + (temp_s4 - 0x10);
      temp_s0_3 = (((*((s16 *) (((char *) temp_v0_2) + 0xA))) + 6) + (temp_s0 - 8)) - 0xE;
      new_var2 = temp_s1_2 + 0xFFCC;
      temp_v0_4 = func_80040260(sp1C, (s16) (new_var2 + var_fp), temp_s0_3, 3, &func_8003C254, 0);
      temp_s3 = arg1 + 0x4C;
      *((s16 *) (((char *) temp_v0_4) + 0x7A)) = 0;
      *((s16 *) (((char *) temp_v0_4) + 0x78)) = 1;
      *((s32 *) (((char *) temp_v0_4) + 0xA4)) = func_80034FF0(temp_s3, 0);
      *((s16 *) (((char *) temp_v0_4) + 0x98)) = 0x600;
      *((s16 *) (((char *) temp_v0_4) + 0x9A)) = 0x600;
      *((void **) (((char *) temp_v0_4) + new_var3)) = (void *) (*((void **) (new_var + new_var4)));
    }
      temp_v0_6 = func_80040260(sp1C, (s16) (inline_fn(temp_s1_2 + 0xFFD5) + var_fp), temp_s0_3, 3, &func_8003C254, 0);
      *((s16 *) (((char *) temp_v0_6) + 0x7A)) = 0;
      *((s16 *) (((char *) temp_v0_6) + 0x78)) = 1;
      *((void **) (((char *) temp_v0_6) + 0x8C)) = temp_v0_4;
      *((s32 *) (((char *) temp_v0_6) + 0xA4)) = func_80034FF0(temp_s3, 0);
      new_var7 = (temp_s1_2 + 0xFFDE) + var_fp;
      *((s16 *) (((char *) temp_v0_6) + 0x98)) = 0x600;
      *((s16 *) (((char *) temp_v0_6) + 0x9A)) = 0x600;
      *((void **) (((char *) temp_v0_6) + new_var3)) = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      var_s6 = func_80040260(sp1C, (s16) new_var7, temp_s0_3, 3, &func_8003C254, 0);
      *((s16 *) (((char *) var_s6) + 0x7A)) = 0;
      *((s16 *) (((char *) var_s6) + 0x78)) = 0;
      *((void **) (((char *) var_s6) + 0x8C)) = temp_v0_6;
      *((s32 *) (((char *) var_s6) + 0xA4)) = func_80034FF0(temp_s3, 0);
      *((s16 *) (((char *) var_s6) + 0x98)) = 0x600;
      *((s16 *) (((char *) var_s6) + 0x9A)) = 0x600;
      goto block_7;

  }

}
