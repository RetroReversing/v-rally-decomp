extern s64 cordicAtanTable[];
extern f64 D_800A7240;
extern f64 func_8009A430(s64);

/* CORDIC in vectoring mode: drives y to zero with 52 shift-and-add rotations
 * and accumulates the rotation angles from cordicAtanTable. The result,
 * scaled to radians by D_800A7240, goes to *out. */
void func_80097770(const s64 xin, const s64 yin, f64 *out)
{
  s64 x = xin, y = yin;
  s64 z = 0;
  s32 i = 0;
  s64 *p = cordicAtanTable;
  s64 next;

  do
  {
    if (y >= 0)
    {
      next = x + (y >> i);
      y -= x >> i;
      z += *p;
    }
    else
    {
      next = x - (y >> i);
      y += x >> i;
      z -= *p;
    }
    x = next;
    i++;
    p++;
  }
  while (i < 52);
  *out = func_8009A430(z) / D_800A7240;
}
