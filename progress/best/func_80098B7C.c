extern int D_800ADF08;
s32 func_80098998();
f64 func_8009A590(f64, f64 *);
extern f64 D_800A3DB8;
extern f64 D_800A3E00;
extern char D_800A7290[];
extern char D_800A7294[];
extern f64 D_800A7298;
extern f64 D_800A72A0;
extern f64 D_800A72A8;
extern f64 D_800A72B0;
extern f64 D_800A72B8;
extern char D_800A73E0[];
void *func_80098B7C(f64 arg0, s32 arg2, s32 *arg3, s32 *arg4)
{
  short __repair_literal;
  volatile s32 pad[1];
  union 
  {
    f64 d;
    u32 w[2];
  } bits;
  f64 sp10;
  f64 sp18;
  char *var_a0;
  char *var_a0_2;
  char *var_v0_2;
  char *var_v0_3;
  f64 *new_var;
  f64 temp_fs0;
  f64 var_fa0;
  s32 temp_v0;
  s32 var_a2;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  s32 var_v0;
  s32 var_v1;
  s32 var_v1_2;
  char *var_s0_2;
  var_fa0 = arg0;
  var_s3 = arg2;
  var_s1 = 0;
  var_a2 = 0x100;
  var_s2 = var_s3;
  *arg4 = 0;
  if (var_s3 >= 0x14)
  {
    var_s3 = 0x14;
    var_s2 = 0x13;
  }
  bits.d = arg0;
  temp_v0 = bits.w[0] & 0x7FF00000;
  switch (temp_v0)
  {
    case 0x0:
      var_s0_2 = D_800A73E0 + 0x6B28;
      var_v1 = 0;
      __repair_literal = 0;
      if (var_s3 > __repair_literal)
    {
      do
      {
        *((s8 *) var_s0_2) = 0x30;
        var_v1 += 1;
        var_s0_2 += 1;
      }
      while (var_v1 < var_s3);
    }
      var_v0 = 1;
      block_38:
    *arg3 = var_v0;

      return D_800A73E0 + 0x6B28;

    case 0x7FF00000:
      *arg3 = 0x7FFFFFFF;
      if ((bits.w[0] & 0xFFFFF) || (bits.w[1] != 0))
    {
      __builtin_memcpy(D_800A73E0 + 0x6B28, D_800A7290, 4);
      *arg4 = 0;
      return D_800A73E0 + 0x6B28;
    }
      __builtin_memcpy(D_800A73E0 + 0x6B28, D_800A7294, 4);
      return D_800A73E0 + 0x6B28;
      new_var = &sp10;

    default:
      if (var_fa0 < 0.0)
    {
      *arg4 = 1;
      var_fa0 = -var_fa0;
    }
      var_v1_2 = 8;
      if (D_800A7298 <= var_fa0)
    {
      var_a0 = &D_800A3E00;
      var_v0_2 = &D_800A3DB8;
      do
      {
        if ((*((f64 *) var_v0_2)) <= var_fa0)
        {
          var_s1 += var_a2;
          var_fa0 *= *((f64 *) var_a0);
        }
        var_a2 = var_a2 >> 1;
        var_a0 = (var_v0_2 = 8);
        var_v1_2 -= 1;
      }
      while (var_v1_2 >= 0);
    }
    else
    {
      var_a0_2 = &D_800A3DB8;
      var_v0_3 = &D_800A3E00;
      do
      {
        if (var_fa0 < (*((f64 *) var_v0_3)))
        {
          var_s1 -= var_a2;
          var_fa0 *= *((f64 *) var_a0_2);
        }
        var_a2 = var_a2 >> 1;
        var_a0_2 -= 8;
        var_v1_2 -= 1;
        var_v0_3 -= 8;
      }
      while (var_v1_2 >= 0);
      var_s1 -= 1;
      var_fa0 *= D_800A72A0;
    }
      ;
      loop_29:
    if (D_800A72A8 <= var_fa0)
    {
      var_s1 += 1;
      sp10 *= D_800A72B0;
      goto loop_29;
    }

      temp_fs0 = D_800A72A8;
      if ((*new_var) < D_800A72B8)
    {
      var_s1 -= 1;
      sp10 *= D_800A72A8;
      goto loop_29;
    }
      var_s0_2 = D_800A73E0 + 0x6B28;
      do
    {
      var_s2 -= 1;
      sp10 = func_8009A590(sp10, &sp18) * temp_fs0;
      *((s8 *) var_s0_2) = ((s32) sp18) + 0x30;
      var_s0_2 += 1;
    }
    while (var_s2 >= 0);
      if (var_s3 >= 0x14)
    {
      var_v0 = var_s1 + 1;
    }
    else
    {
      var_v0 = func_80098998(D_800A73E0 + 0x6B28, var_s1, var_s3) + 1;
    }
      goto block_38;

  }

}

