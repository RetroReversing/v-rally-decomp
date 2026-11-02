static __inline__ s16 __repair_inline(s16 a) { return a; }
s32 func_80034FF0(s32, s32);
void *func_80040260(s32, s16, s16, s32, s32 *, s32);
void *func_8004240C(s32);
extern s32 D_800C02AE;
extern s32 func_8003C254;
static inline static static static static int inline_fn(int arg0)
{
  return arg0;
}

typedef struct { unsigned char pad[140]; void * value; } __repair_field_8C;
typedef struct { unsigned char pad_0[120]; short field_78; short field_7A; unsigned char pad_7C[40]; int field_A4; } __repair_record_temp_v0_3;
typedef struct { unsigned char pad_0[120]; short field_78; short field_7A; unsigned char pad_7C[28]; short field_98; short field_9A; unsigned char pad_9C[8]; int field_A4; } __repair_record_temp_v0_4;
typedef struct { unsigned char pad_0[8]; short field_8; short field_A; short field_C; short field_E; } __repair_record_temp_v0_2;
typedef struct { unsigned char pad_0[120]; short field_78; short field_7A; unsigned char pad_7C[28]; short field_98; short field_9A; unsigned char pad_9C[8]; int field_A4; } __repair_record_temp_v0_6;
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
  
  void *new_var5;
  s32 temp_s3;
  s32 var_fp;
  s32 var_s1;
  void **new_var6;
  u16 temp_a0;
  void *temp_v0;
  void *temp_v0_2;
  
  
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
  temp_a3 = ((__repair_record_temp_v0_2*)temp_v0_2)->field_8;
  new_var5 = (void *)(((__repair_record_temp_v0_2*)temp_v0_2)->field_A + 6);
  temp_s4 = ((__repair_record_temp_v0_2*)temp_v0_2)->field_C;
  temp_s0 = __repair_inline(((__repair_record_temp_v0_2*)temp_v0_2)->field_E);
  temp_a0 = *((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE));
  var_s1 = temp_a3 + 0x14;
  switch (temp_a0)
  {
    case 1:
      temp_s0_2 = temp_s0 - 0x14;
      temp_v0 = func_80040260(sp1C, (s16) (temp_s4 - 0x52), temp_s0_2, 3, &func_8003C254, 0);
      temp_s1 = arg1 + 0x4C;
      new_var3 = 0xA8;
      ((__repair_record_temp_v0_3*)temp_v0)->field_7A = 0;
      ((__repair_record_temp_v0_3*)temp_v0)->field_78 = 1;
      ((__repair_record_temp_v0_3*)temp_v0)->field_A4 = func_80034FF0(temp_s1, 0);
      new_var6 = (void **) (((char *) temp_v0) + new_var3);
      *new_var6 = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      temp_v0_4 = func_80040260(sp1C, (s16) (temp_s4 - 0x49), temp_s0_2, 3, &func_8003C254, 0);
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_7A = 0;
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_78 = 1;
      ((__repair_field_8C *)temp_v0_4)->value = temp_v0;
      *((void **) (((char *) temp_v0_4) + new_var3)) = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_A4 = func_80034FF0(temp_s1, 0);
      var_s6 = func_80040260(sp1C, (s16) (temp_s4 - 0x40), temp_s0_2, 3, &func_8003C254, 0);
      new_var5 = temp_v0_4;
      *((s16 *) (((char *) var_s6) + 0x7A)) = 0;
      *((s16 *) (((char *) var_s6) + 0x78)) = 0;
      ((__repair_field_8C *)var_s6)->value = new_var5;
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
      temp_s1 = var_s1 + (temp_s4 - 0x10);
      temp_s0_3 = ((s32)new_var5 + (temp_s0 - 8)) - 0xE;
      new_var2 = temp_s1 + 0xFFCC;
      temp_v0_4 = func_80040260(sp1C, (s16) (new_var2 + var_fp), temp_s0_3, 3, &func_8003C254, 0);
      temp_s3 = arg1 + 0x4C;
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_7A = 0;
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_78 = 1;
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_A4 = func_80034FF0(temp_s3, 0);
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_98 = 0x600;
      ((__repair_record_temp_v0_4*)temp_v0_4)->field_9A = 0x600;
      *((void **) (((char *) temp_v0_4) + new_var3)) = (void *) (*((void **) (new_var + new_var4)));
    }
      temp_v0_6 = func_80040260(sp1C, (s16) (inline_fn(temp_s1 + 0xFFD5) + var_fp), temp_s0_3, 3, &func_8003C254, 0);
      ((__repair_record_temp_v0_6*)temp_v0_6)->field_7A = 0;
      ((__repair_record_temp_v0_6*)temp_v0_6)->field_78 = 1;
      ((__repair_field_8C *)temp_v0_6)->value = temp_v0_4;
      ((__repair_record_temp_v0_6*)temp_v0_6)->field_A4 = func_80034FF0(temp_s3, 0);
      new_var2 = (temp_s1 + 0xFFDE) + var_fp;
      ((__repair_record_temp_v0_6*)temp_v0_6)->field_98 = 0x600;
      ((__repair_record_temp_v0_6*)temp_v0_6)->field_9A = 0x600;
      *((void **) (((char *) temp_v0_6) + new_var3)) = (void *) (*((void **) (((char *) (&D_800C02AE)) + new_var4)));
      var_s6 = func_80040260(sp1C, (s16) new_var2, temp_s0_3, 3, &func_8003C254, 0);
      *((s16 *) (((char *) var_s6) + 0x7A)) = 0;
      *((s16 *) (((char *) var_s6) + 0x78)) = 0;
      ((__repair_field_8C *)var_s6)->value = temp_v0_6;
      *((s32 *) (((char *) var_s6) + 0xA4)) = func_80034FF0(temp_s3, 0);
      *((s16 *) (((char *) var_s6) + 0x98)) = 0x600;
      *((s16 *) (((char *) var_s6) + 0x9A)) = 0x600;
      goto block_7;

  }

}
