/* Normalizes the integer vector src to 4096 units of length in dst, and returns the
 * rounded-down length (1 if the input is zero or shorter than 1). */
s32 vec3_normalize_fixed(s32 *src, s32 *dst)
{
  f32 v[3];
  f32 len;
  f32 fn;
  f32 s;
  s32 n;
  v[0] = (f32) src[0];
  v[1] = (f32) src[1];
  v[2] = (f32) src[2];
  len = ((v[0] * v[0]) + (v[1] * v[1])) + (v[2] * v[2]);
  if (len != 0.0f)
  {
    n = (s32) __builtin_sqrtf(len);
  }
  else
  {
    n = 0;
  }
  if (n == 0)
  {
    n = 1;
  }
  s = 4096.0f; dst[0] = (s32) ((((f32) src[0]) / ((f32) n)) * s);
  dst[1] = (s32) ((((f32) src[1]) / ((f32) n)) * s);
  s = (((f32) src[2]) / ((f32) n)) * s;
  dst[2] = (s32) s;
  return n;
}
