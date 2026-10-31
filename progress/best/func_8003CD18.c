extern void *D_800C35A0;
extern void *D_800C7F84;
extern unsigned char D_800ADFE0;
extern unsigned char D_800ADFE1;
s32 func_80034FF0();
void *func_80040260(s32, s16, s16, s32, void *, s32);
void *func_8004240C();
extern char D_800A73E0[];
extern char D_800C02AE[];
extern s32 func_8003CB8C;
extern s32 func_8003CC0C;
extern s32 func_8003CC50;
static inline s16 inline_fn(int arg0)
{
  return (s16) arg0;
}

void func_8003CD18(s32 arg0, s32 arg1, s32 arg2)
{
  s32 result;
  void *owner;
  s32 temp_s0;
  s16 temp_s0_2;
  s16 temp_s0_3;
  s16 temp_s0_4;
  s16 temp_s0_5;
  s16 temp_s0_6;
  s16 temp_s0_7;
  s16 temp_s0_8;
  s16 temp_s0_9;
  s32 temp_s6;
  s32 temp_t0;
  s32 var_a1;
  s32 var_a1_2;
  s32 var_a2;
  s16 var_s0;
  s32 var_s3;
  s32 temp_a2;
  s32 temp_s1;
  s32 temp_s1_2;
  s32 temp_s1_3;
  s32 temp_s2;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s2_4;
  s32 temp_t1;
  s32 var_a0;
  s32 var_a3;
  s32 var_s1;
  s32 var_v0;
  u16 temp_v1;
  int new_var;
  void *temp_v0;
  void *temp_v0_2;
  void *var_s4;
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) == 7)
  {
    goto block_33;
  }
  if (((u8) D_800ADFE0) < 2U)
  {
    goto block_33;
  }
  temp_v0 = func_8004240C((((arg2 & 0xFFFF) - 1) * 2) | 1);
  temp_v0_2 = *((void **) (((char *) temp_v0) + 0x178));
  D_800C7F84 = temp_v0;
  temp_s6 = *((s16 *) (((char *) temp_v0_2) + 8));
  temp_s0 = *((s16 *) (((char *) temp_v0_2) + 0xA));
  temp_t0 = *((s16 *) (((char *) temp_v0_2) + 0xE));
  var_s3 = temp_s6 + 0x14;
  temp_a2 = (*((s16 *) (((char *) temp_v0_2) + 0xC))) - 0x10;
  temp_v1 = *((u16 *) (((char *) D_800C35A0) + 0xE));
  var_a3 = temp_s0 + 6;
  temp_t1 = temp_t0 - 8;
  if (temp_v1 == 1)
  {
    goto block_5;
  }
  if (temp_v1 == 2)
  {
    goto block_9;
  }
  return;
  block_5:
  if (D_800ADFE1 != 0)
  {
    goto block_7;
  }

  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 0)
  {
    goto block_8;
  }
  block_7:
  temp_s1 = var_s3 + temp_a2;

  temp_s0_2 = temp_s0 + 0x10;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1 - 0x38), temp_s0_2, 2, &func_8003CB8C, 0);
  temp_s2 = arg1 + 0x4C;
  result = func_80034FF0(temp_s2, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1 - 0x31), temp_s0_2, 2, &func_8003CC50, 0);
  result = func_80034FF0(temp_s2, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s1 - 0x2A), temp_s0_2, 2, &func_8003CC50, 0);
  var_a0 = temp_s2;
  goto block_32;
  block_8:
  temp_s1_2 = var_s3 + temp_a2;

  temp_s0_3 = temp_s0 + 0x10;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1_2 - 0x38), temp_s0_3, 2, &func_8003CC0C, 0);
  temp_s2_2 = arg1 + 0x4C;
  result = func_80034FF0(temp_s2_2, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1_2 - 0x31), temp_s0_3, 2, NULL, 0);
  result = func_80034FF0(temp_s2_2, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s1_2 - 0x2A), temp_s0_3, 2, NULL, 0);
  var_a0 = temp_s2_2;
  goto block_32;
  block_9:
  if ((*((u16 *) (((char *) D_800C35A0) + 0x1E))) != 0)
  {
    goto block_19;
  }

  if (!((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1))
  {
    goto block_12;
  }
  temp_s0_4 = temp_s0 + 0x10;
  var_s4 = func_80040260(arg0, temp_s6, temp_s0_4, 2, &func_8003CB8C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s6 + 7), temp_s0_4, 2, &func_8003CC50, 0);
  var_a1 = temp_s6 + 0xE;
  var_a2 = temp_s0_4;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  goto block_31;
  block_12:
  if ((*((s32 *) (((char *) temp_v0) + 0xC))) != 3)
  {
    goto block_16;
  }

  temp_s1_3 = var_s3 + temp_a2;
  if (D_800ADFE1 == 0)
  {
    goto block_15;
  }
  temp_s0_5 = temp_s0 + 0x10;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1_3 - 0x32), temp_s0_5, 2, &func_8003CB8C, 0);
  temp_s2_3 = arg1 + 0x4C;
  result = func_80034FF0(temp_s2_3, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1_3 + 0xFFD5), temp_s0_5, 2, &func_8003CC50, 0);
  result = func_80034FF0(temp_s2_3, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s1_3 + 0xFFDC), temp_s0_5, 2, &func_8003CC50, 0);
  var_a0 = temp_s2_3;
  goto block_32;
  block_15:
  temp_s0_6 = temp_s0 + 0x10;

  var_s4 = func_80040260(arg0, (s16) (temp_s1_3 - 0x32), temp_s0_6, 2, &func_8003CC0C, 0);
  temp_s2_4 = arg1 + 0x4C;
  result = func_80034FF0(temp_s2_4, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(temp_s1_3 + 0xFFD5), temp_s0_6, 2, NULL, 0);
  result = func_80034FF0(temp_s2_4, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  new_var = temp_s1_3 + 0xFFDC;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(new_var), temp_s0_6, 2, NULL, 0);
  var_a0 = temp_s2_4;
  goto block_32;
  block_16:
  if (D_800ADFE1 == 0)
  {
    goto block_18;
  }

  temp_s0_7 = temp_s0 + 0x10;
  var_s4 = func_80040260(arg0, var_s3, temp_s0_7, 2, &func_8003CB8C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s6 + 0x1B), temp_s0_7, 2, &func_8003CC50, 0);
  var_a1 = temp_s6 + 0x22;
  var_a2 = temp_s0_7;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  goto block_31;
  block_18:
  var_s0 = temp_s0 + 0x10;

  var_s4 = func_80040260(arg0, var_s3, var_s0, 2, &func_8003CC0C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (temp_s6 + 0x1B), var_s0, 2, NULL, 0);
  var_v0 = func_80034FF0(var_s1, 0);
  var_a1_2 = temp_s6 + 0x22;
  goto block_30;
  block_19:
  if (!((*((u16 *) (((char *) D_800C35A0) + 0x12))) & 1))
  {
    goto block_25;
  }

  if ((*((s32 *) (((char *) temp_v0) + 0xC))) != 1)
  {
    goto block_22;
  }
  var_a3 = temp_s0 + 8;
  block_22:
  if (D_800ADFE1 == 0)
  {
    goto block_24;
  }

  temp_s0_8 = (var_a3 + temp_t1) - 0x15;
  var_s4 = func_80040260(arg0, temp_s6, temp_s0_8, 2, &func_8003CB8C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (var_s3 + 0xFFF3), temp_s0_8, 2, &func_8003CC50, 0);
  var_a1 = var_s3 + 0xFFFA;
  var_a2 = temp_s0_8;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  goto block_31;
  block_24:
  var_s0 = (var_a3 + temp_t1) - 0x15;

  var_s4 = func_80040260(arg0, temp_s6, var_s0, 2, &func_8003CC0C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(var_s3 + 0xFFF3), var_s0, 2, NULL, 0);
  var_v0 = func_80034FF0(var_s1, 0);
  var_a1_2 = var_s3 + 0xFFFA;
  goto block_30;
  block_25:
  if ((*((s32 *) (((char *) temp_v0) + 0xC))) != 3)
  {
    goto block_27;
  }

  var_s3 = temp_s6 + 6;
  block_27:
  if (D_800ADFE1 == 0)
  {
    goto block_29;
  }

  temp_s0_9 = temp_t0 - 0x26;
  var_s4 = func_80040260(arg0, var_s3, temp_s0_9, 2, &func_8003CB8C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, inline_fn(var_s3 + 7), temp_s0_9, 2, &func_8003CC50, 0);
  var_a1 = var_s3 + 0xE;
  var_a2 = temp_s0_9;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  goto block_31;
  block_29:
  var_s0 = temp_t0 - 0x26;

  var_s4 = func_80040260(arg0, var_s3, var_s0, 2, &func_8003CC0C, 0);
  var_s1 = arg1 + 0x4C;
  result = func_80034FF0(var_s1, 0);
  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  var_s4 = func_80040260(arg0, (s16) (var_s3 + 7), var_s0, 2, NULL, 0);
  var_v0 = func_80034FF0(var_s1, 0);
  var_a1_2 = var_s3 + 0xE;
  block_30:
  var_a1 = var_a1_2;

  var_a2 = var_s0;
  *((s32 *) (((char *) var_s4) + 0xA4)) = var_v0;
  *((s16 *) (((char *) var_s4) + 0x7A)) = 0xF;
  *((void **) (((char *) var_s4) + 0xA8)) = (void *) D_800C7F84;
  block_31:
  var_s4 = func_80040260(arg0, var_a1, var_a2, 2, NULL, 0);

  var_a0 = var_s1;
  block_32:
  result = func_80034FF0(var_a0, 0);

  owner = D_800C7F84;
  *((s32 *) (((char *) var_s4) + 0xA4)) = result;
  *((void **) (((char *) var_s4) + 0xA8)) = owner;
  *((s16 *) (((char *) var_s4) + 0x7A)) = (s16) (D_800ADFE0 - 1);
  block_33:
  return;

}
