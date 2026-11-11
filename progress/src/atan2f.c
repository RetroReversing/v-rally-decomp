extern f64 atan(f64);
extern f64 __kernel_standard(s32, void *, f64, f64, f64);
extern u8 D_800A7268;
extern f64 D_800A7270;
extern f64 D_800A7278;

/* Single-precision atan2(y, x): the angle of the point (x, y), in radians from -pi to pi.
   Zero-zero and vertical cases are handled directly; everything else is atan(y/x)
   corrected into the right quadrant. Errors go through the libm handler. */
f32 atan2f(f32 y, f32 x)
{
  f32 result;
  s32 x_is_zero;
  s32 y_is_zero;
  x_is_zero = x == 0.0f;
  y_is_zero = y == 0.0f;
  if (x_is_zero & y_is_zero)
  {
    return (f32) __kernel_standard(1, &D_800A7268, (f64) x, (f64) y, 0.0);
  }
  if (x == 0.0f)
  {
    result = -1.5707964f;
    if (y > 0.0f)
    {
      return 1.5707964f;
    }
    return result;
  }
  {
    result = y / x;
    result = (f32) atan((f64) result);
    if (!(x > 0.0f))
    {
      if (y == 0.0f)
      {
        return 3.1415927f;
      }
      result = (f64) result;
      if (!(y > 0.0f))
      {
        result -= D_800A7270;
      }
      else
      {
        result += D_800A7278;
      }
      result = (f32) result;
    }
    return result;
  }
}
