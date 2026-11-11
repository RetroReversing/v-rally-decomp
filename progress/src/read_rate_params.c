extern f64 D_800A6D00;

/* Reads a run of parameter bytes from src into the record at dst, and derives
 * the timing values from them: a 1024-based step count (unk_60), and per-field
 * rates (unk_54, unk_58) scaled by the change in each byte. A zero count is
 * treated as 1. Returns the position after the last byte read. */
u8 *read_rate_params(S_func_80088D10_layout *dst, u8 *src)
{
  s32 n;
  s32 v;
  f64 new_var;
  double new_var3;
  f64 rate54;
  f64 rate58;
  int new_var2;
  f64 base;

  n = *(src++);
  if (!n) {
    n = 1;
  }
  new_var2 = 1024;
  dst->unk_60 = (long long) (new_var2 / n);
  dst->unk_B7 = n;
  dst->unk_B8 = *(src++);
  n = *(src++);
  base = D_800A6D00;
  new_var3 = base / ((f32) n);
  rate54 = new_var3;
  new_var = base;
  dst->unk_BE = n;
  v = *(src++);
  rate54 *= (f32) (v - dst->unk_B8);
  dst->unk_B9 = v;
  dst->unk_54 = (f32) rate54;
  n = *(src++);
  rate58 = (f32) n;
  rate58 = new_var / rate58;
  dst->unk_BF = n;
  v = *(src++);
  rate58 *= (f32) (v - dst->unk_B9);
  dst->unk_BA = v;
  dst->unk_58 = (f32) rate58;
  n = *(src++);
  dst->unk_C0 = n;
  dst->unk_5C = (f32) (base / ((f32) n));
  return src;
}
