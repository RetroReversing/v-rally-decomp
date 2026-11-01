extern f64 func_80097924(f64);
extern f64 func_80098750(s32, void *, f64, f64, f64);
extern u8 D_800A7268;
extern f64 D_800A7280;
extern f64 D_800A7288;
s32 atan2_angle4096(s32 arg0, s32 arg1)
{
  f32 scale = 651.9246f;
  f64 d;
  s32 r;
  if ((arg1 == 0) & (arg0 == 0))
  {
    return (s32) func_80098750(1, &D_800A7268, (f64) arg1, (f64) arg0, 0.0);
  }
  if (arg1 == 0)
  {
    return ((-(arg0 < 1)) & (~0x3FF)) | 0x400;
  }
  d = func_80097924(((f64) arg0) / ((f64) arg1)) * ((f64) scale);
  r = (s32) d;
  if (arg1 > 0)
  {
    return r;
  }
  if (arg0 == 0)
  {
    return 0x800;
  }
  if (arg0 > 0)
  {
    return (s32) (d + D_800A7288);
  }
  return (s32) (((f64) r) - D_800A7280);
}
