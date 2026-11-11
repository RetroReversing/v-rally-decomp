extern u8 gNumberBuf[];
extern u8 *gDigitChars;
extern s64 __udivdi3(s64, s64);
extern s64 func_8009A2D0(s64, s64);

/* Formats an unsigned 64-bit value in base `base`, writing the digits backwards into
 * the end of gNumberBuf. Returns a pointer to the first digit. */
u8 *func_800988C8(s64 value, s32 base)
{
  u8 *p = gNumberBuf;
  s64 new_var;
  union
  {
    s64 q;
    struct
    {
      s32 hi;
      u32 lo;
    } w;
  } y;
  s32 h = base >> 31;
  vu32 digit;

  do
  {
    {
      y.w.lo = base;
      new_var = value;
      y.w.hi = h;
      digit = (s32) func_8009A2D0(value, (s64)base);
      p--;
    }
    *p = gDigitChars[digit];
    value = __udivdi3(value, (s64)base);
  }
  while (value != 0);
  return p;
}
