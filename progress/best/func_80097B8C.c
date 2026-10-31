extern f64 func_80097924(f64);
extern f64 func_80098750(s32, void *, f64, f64, f64);
extern u8 D_800A7268;
extern f64 D_800A7280;
extern f64 D_800A7288;
s32 func_80097B8C(s32 arg0, s32 arg1)
{
  f64 temp_fv1;
  f64 var_fv0;
  s32 temp_fv0;
  s32 var_v0;
  f32 scale = 651.9246f;
  int new_var;
  if ((arg1 == 0) & (arg0 == 0))
  {
    var_fv0 = func_80098750(1, &D_800A7268, (f64) arg1, (f64) arg0, 0.0);
    goto block_9;
  }
  new_var = arg0 < 1;
  if (arg1 == 0)
  {
    return ((-new_var) & (~0x3FF)) | 0x400;
  }
  temp_fv1 = func_80097924(((f64) arg0) / ((f64) arg1)) * ((f64) scale);
  temp_fv0 = (s32) temp_fv1;
  var_v0 = temp_fv0;
  if (arg1 <= 0)
  {
    var_v0 = 0x800;
    if (arg0 != 0)
    {
      if (arg0 <= 0)
      {
        var_fv0 = ((f64) temp_fv0) - D_800A7280;
      }
      else
      {
        var_fv0 = temp_fv1 + D_800A7288;
      }
      block_9:
      return (s32) var_fv0;

    }
  }
  return var_v0;
}
