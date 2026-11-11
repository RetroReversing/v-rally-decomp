extern f64 D_800A7248;
extern f64 D_800A7250;
extern f64 D_800A7258;
extern f64 D_800A7260;
extern u64 func_8009A310(f64);
extern s32 func_80097770(u64, u64, f64 *);

/* Arctangent. Works on |x|: when |x| is above D_800A7248 it is reduced to a fixed-point
 * ratio through func_80097770, then the sign of x is applied to the result. */
f64 atan(f64 x)
{
  f64 result;
  f64 ret;
  f64 absx;
  s32 sign;
  u64 num;
  u64 den;
  u64 tmp;
  u64 tmp2;
  double scaled;

  absx = x;
  if (absx < 0.0)
  {
    sign = -1;
    absx = -absx;
  }
  else
  {
    sign = 1;
  }
  if (D_800A7248 < absx)
  {
    x = D_800A7250;
    if (x <= absx)
    {
      scaled = x / absx;
      scaled = D_800A7258 * scaled;
      den = 0x1000000000000000ULL;
      tmp = func_8009A310(scaled);
      num = tmp;
    }
    else
    {
      num = 0x1000000000000000ULL;
      tmp2 = func_8009A310(absx * D_800A7260);
      den = tmp2;
    }
    func_80097770(num, den, &result);
  }
  else
  {
    result = absx;
  }
  ret = result;
  if (sign < 0)
  {
    ret = -ret;
  }
  return ret;
}
