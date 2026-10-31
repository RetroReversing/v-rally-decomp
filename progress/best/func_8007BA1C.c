#define sqrtf(x) sqrt(x)
extern s32 D_800A1860;
extern s32 D_800A1864;
extern s32 D_800A1868;
extern s32 D_800A186C;
extern s32 D_800A1870;
extern s32 D_800A1874;
extern f32 D_800A1878;
extern f32 D_800A187C;
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
s32 func_8002DA98(u8 *arg0, s32 *arg1);
void func_8002E514(s16 *arg0, s16 *arg1, s16 *arg2);
f32 sqrt(f32);
static inline static static static static f32 inline_fn(s16 *arg0, s16 *arg1)
{
  return (f32) (arg0[2] - arg1[2]);
}

s32 func_8007BA1C(void *arg0)
{
  float new_var2;
  s16 a[4];
  s16 b[4];
  s16 c[4];
  s32 sp28[8];
  f32 temp_fs2;
  f32 temp_fs2_2;
  f32 temp_ft0;
  u8 *new_var;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_fv0;
  f32 temp_fv0_2;
  s16 temp_a3;
  s16 temp_a3_2;
  s32 var_v0;
  u8 var_v0_2;
  void **p;
  s32 *q;
  func_8002DA98(D_800AE850 + 0x6E78, &sp28);
  b[0] = D_800A1860 - (*((s32 *) (D_800AE850 + 0x6E8C)));
  b[1] = D_800A1864 - (*((s32 *) (D_800AE850 + 0x6E90)));
  b[2] = D_800A1868 - (*((s32 *) (0x6E94 + D_800AE850)));
  func_8002E514((s16 *) (&sp28), &b[0], &b[0]);
  c[0] = D_800A186C - (*((s32 *) (D_800AE850 + 0x6E8C)));
  c[1] = D_800A1870 - (*((s32 *) (D_800AE850 + 0x6E90)));
  c[2] = D_800A1874 - (*((s32 *) (D_800AE850 + 0x6E94)));
  func_8002E514((s16 *) (&sp28), &c[0], &c[0]);
  temp_fs2 = (f32) (b[0] - c[0]);
  temp_fs2_2 = (f32) (b[1] - c[1]);
  temp_fv0_2 = inline_fn(b, c);
  temp_fv0 = sqrtf(((temp_fs2 * temp_fs2) + (temp_fs2_2 * temp_fs2_2)) + (temp_fv0_2 * temp_fv0_2));
  temp_fs2_2 = temp_fs2 / temp_fv0;
  temp_fs2_2 /= temp_fv0;
  temp_fv0_2 /= temp_fv0;
  *((s32 *) (D_800C02AE + 0x5D32)) = (s32) b[0];
  *((s32 *) (D_800C02AE + 0x5D36)) = (s32) b[1];
  *((s32 *) (D_800C02AE + 0x5D3A)) = (s32) b[2];
  *((s32 *) (D_800C02AE + 0x5D3E)) = (s32) c[0];
  *((s32 *) (D_800C02AE + 0x5D42)) = (s32) c[1];
  *((s32 *) (D_800C02AE + 0x5D46)) = (s32) c[2];
  new_var = D_800C02AE + 0x5D4E;
  *((f32 *) new_var) = D_800A187C;
  *((f32 *) (D_800C02AE + 0x5D4A)) = D_800A1878;
  p = *((void **) (((u8 *) arg0) + 0x5C));
  q = (s32 *) (((u8 *) p) + 0x54);
  a[0] = (s16) (q[0] - (*((s32 *) (D_800AE850 + 0x6E8C))));
  a[1] = (s16) (q[1] - (*((s32 *) (D_800AE850 + 0x6E90))));
  a[2] = (s16) (q[2] - (*((s32 *) (D_800AE850 + 0x6E94))));
  func_8002E514((s16 *) (&sp28), &a[0], &a[0]);
  temp_ft1 = (f32) ((*((s32 *) (D_800C02AE + 0x5D32))) - a[0]);
  temp_ft1_2 = (f32) ((*((s32 *) (D_800C02AE + 0x5D36))) - a[1]);
  temp_ft0 = temp_ft1_2;
  temp_fs2_2 = (f32) ((*((s32 *) (D_800C02AE + 0x5D3A))) - a[2]);
  temp_fv0_2 = sqrtf(((temp_ft1 * temp_ft1) + (temp_ft0 * temp_ft0)) + (temp_fs2_2 * temp_fs2_2));
  new_var2 = (temp_fs2_2 / temp_fv0_2) * temp_fv0_2;
  temp_ft1_2 = (((temp_ft1 / temp_fv0_2) * temp_fs2_2) + ((temp_ft0 / temp_fv0_2) * temp_fs2_2)) + new_var2;
  var_v0_2 = 0xFF;
  if (!((*((f32 *) (D_800C02AE + 0x5D4A))) < temp_ft1_2))
  {
    if (D_800C02AE)
    {
      var_v0 = 0xFF;
    }
    else
    {
      var_v0 = 0xFF;
    }
    if (!((*((f32 *) new_var)) < temp_ft1_2))
    {
      var_v0_2 = D_800A73E0[0x6BE7];
      goto block_3;
    }
  }
  else
  {
    block_3:
    var_v0 = (s32) var_v0_2;

  }
  return var_v0;
}
