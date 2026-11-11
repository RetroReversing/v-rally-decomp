extern f64 atan(f64);
extern f64 __kernel_standard(s32, void *, f64, f64, f64);
extern u8 D_800A7268;
extern f64 D_800A7280;
extern f64 D_800A7288;

/* Integer atan2 returning an angle in 4096 units per turn (0x800 = pi), with
 * the y and x inputs as integers. Handles the x==0 and y==0 cases directly and
 * reports the (0,0) domain error through __kernel_standard. */
s32 atan2_angle4096(s32 y, s32 x)
{
  f32 angle_scale = 651.9246f;
  f64 d;
  s32 r;
  if ((x == 0) & (y == 0))
  {
    return (s32) __kernel_standard(1, &D_800A7268, (f64) x, (f64) y, 0.0);
  }
  if (x == 0)
  {
    return ((-(y < 1)) & (~0x3FF)) | 0x400;
  }
  d = atan(((f64) y) / ((f64) x)) * ((f64) angle_scale);
  r = (s32) d;
  if (x > 0)
  {
    return r;
  }
  if (y == 0)
  {
    return 0x800;
  }
  if (y > 0)
  {
    return (s32) (d + D_800A7288);
  }
  return (s32) (((f64) r) - D_800A7280);
}
