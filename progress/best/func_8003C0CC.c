extern u8 D_800C02AE[];
void func_8003BEBC(void);
void *func_80034FF0(s32, s32);
void *func_80040260(s32, s32, s32, s32, void *, s32);
void *func_8004240C(s32);
static inline f32 inline_fn(u16 *arg0)
{
  return (f32) (*arg0);
}
static inline f32 inline_fns(s16 *arg0)
{
  return (f32) (*arg0);
}

static inline s16 inline_fn2(u8 *arg0)
{
  return *((s16 *) (arg0 + 0xE));
}

void func_8003C0CC(s32 arg0, s32 arg1)
{
  u8 *var_s0 = (u8 *) arg0;
  s32 var_s1 = arg1;
  u8 *temp_v1;
  u8 *temp_v0_3;
  u8 *temp_v1_3;
  s16 temp_v1_2;
  s16 temp_a2;
  f32 temp_ft0;
  s16 *new_var;
  s8 *temp_v0;
  f32 temp_f2;
  if ((*((u16 *) ((*((u8 **) (&D_800C02AE[0x32F2]))) + 0x1E))) != 7)
  {
    temp_v0 = func_8004240C(((*((u16 *) ((*((u8 **) (&D_800C02AE[0x32F2]))) + 0xE))) << 1) | 1);
    temp_v1 = *((u8 **) (temp_v0 + 0x178));
    *((u8 **) (&D_800C02AE[0x7CD6])) = temp_v0;
    temp_a2 = *((s16 *) (temp_v1 + 0xC));
    temp_v1_2 = inline_fn2(temp_v1);
    var_s0 = func_80040260((s32) var_s0, temp_a2 / 2, temp_v1_2 / 2, 4, func_8003BEBC, 0);
    new_var = (s16 *) (var_s0 + 0x98);
    *new_var = 0x100;
    temp_v1_3 = var_s0 + 0x9A;
    *((u16 *) temp_v1_3) = 0x100;
    *((u32 *) (var_s0 + 0x80)) |= 4;
    temp_v0_3 = func_80034FF0(var_s1 + 0x4C, 0);
    temp_ft0 = 1024.0f;
    temp_ft0 = temp_ft0 / inline_fns((s16 *) (var_s0 + 0x98));
    *((u8 **) (var_s0 + 0xA4)) = temp_v0_3;
    temp_v1_3 = *(*((u8 ***) (temp_v0_3 + 4)));
    temp_v1_2 = -((temp_ft0 * inline_fn((u16 *) (temp_v1_3 + 6))) * 0.5f);
    temp_f2 = -((temp_ft0 * inline_fn((u16 *) (temp_v1_3 + 8))) * 0.5f);
    *((u32 *) (var_s0 + 0xA0)) |= 4;
    *((u16 *) temp_v1_3) = *((u16 *) (var_s0 + 0x98));
    *((s16 *) (var_s0 + 0x78)) = 1;
    *((s16 *) (var_s0 + 0x70)) = temp_v1_2;
    temp_a2 = temp_f2;
    *((s16 *) (var_s0 + 0x72)) = temp_a2;
  }
}
