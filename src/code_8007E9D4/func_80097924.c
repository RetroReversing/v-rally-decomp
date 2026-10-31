#include "snapshot31_verified.h"

extern f64 D_800A7248;
extern f64 D_800A7250;
extern f64 D_800A7258;
extern f64 D_800A7260;
extern u64 func_8009A310(f64);
extern s32 func_80097770(u64, u64, f64 *);
f64 func_80097924(f64 arg0)
{
  f64 sp18;
  f64 var_fv0;
  f64 var_fv1;
  s32 var_s4;
  u64 numerator;
  u64 denominator;
  u32 var_s3;
  u64 temp_ret;
  u64 temp_ret_2;
  double new_var;
  u32 var_s2;
  u32 var_s0;
  var_fv1 = arg0;
  if (var_fv1 < 0.0)
  {
    var_s4 = -1;
    var_fv1 = -var_fv1;
  }
  else
  {
    var_s4 = 1;
  }
  if (D_800A7248 < var_fv1)
  {
    arg0 = D_800A7250;
    if (arg0 <= var_fv1)
    {
      new_var = arg0 / var_fv1;
      new_var = D_800A7258 * new_var;
      denominator = 0x1000000000000000ULL;
      temp_ret = func_8009A310(new_var);
      numerator = temp_ret;
    }
    else
    {
      numerator = 0x1000000000000000ULL;
      temp_ret_2 = func_8009A310(var_fv1 * D_800A7260);
      denominator = temp_ret_2;
    }
    func_80097770(numerator, denominator, &sp18);
  }
  else
  {
    sp18 = var_fv1;
  }
  var_fv0 = sp18;
  if (var_s4 < 0)
  {
    var_fv0 = -var_fv0;
  }
  return var_fv0;
}
