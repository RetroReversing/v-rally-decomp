extern f64 func_80097924(f64);
extern f64 func_80098750(s32, void *, f64, f64, f64);
extern u8 D_800A7268;
extern f64 D_800A7270;
extern f64 D_800A7278;
f32 func_80097A34(f32 arg0, f32 arg1)
{
  f32 var_fv0;
  s32 var_v0;
  s32 var_v1;
  var_v0 = arg1 == 0.0f;
  var_v1 = arg0 == 0.0f;
  if (var_v0 & var_v1)
  {
    return (f32) func_80098750(1, &D_800A7268, (f64) arg1, (f64) arg0, 0.0);
  }
  if (arg1 == 0.0f)
  {
    var_fv0 = -1.5707964f;
    if (arg0 > 0.0f)
    {
      return 1.5707964f;
    }
    return var_fv0;
  }
  {
    var_fv0 = arg0 / arg1;
    var_fv0 = (f32) func_80097924((f64) var_fv0);
    if (!(arg1 > 0.0f))
    {
      if (arg0 == 0.0f)
      {
        return 3.1415927f;
      }
      var_fv0 = (f64) var_fv0;
      if (!(arg0 > 0.0f))
      {
        var_fv0 -= D_800A7270;
      }
      else
      {
        var_fv0 += D_800A7278;
      }
      var_fv0 = (f32) var_fv0;
    }
    return var_fv0;
  }
  var_fv0 = -1.5707964f;
  if (arg0 > 0.0f)
  {
    return 1.5707964f;
  }
  return var_fv0;
}
