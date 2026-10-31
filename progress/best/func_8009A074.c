u64 func_8009A074(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
  union _PermuterAnon1
  {
    u64 whole;
    struct 
    {
      u32 hi;
      u32 lo;
    } word;
  } product;
  union _PermuterAnon1 result;
  u32 hi;
  u32 rem;
  u32 qlo;
  u32 v0;
  u32 v1;
  u32 t;
  u32 prodlo;
  u32 prodhi;
  u32 borrow;
 do { hi = arg0 / arg3; rem = arg0 % arg3; qlo = 0; loop: if (rem) { v1 = arg1; v0 = rem; t = arg3; do { v1 = (v1 >> 1) | (v0 << 31); v0 >>= 1; t >>= 1; } while (v0); t++; v1 /= t; qlo += v1; hi += qlo < v1; product.whole = ((u64) v1) * arg3; prodlo = product.word.lo; prodhi = product.word.hi; borrow = arg1 < prodlo; arg1 -= prodlo; rem = (rem - borrow) - prodhi; goto loop; } v1 = arg1 / arg3; v1 += qlo; hi += v1 < qlo; } while (0);
  result.word.hi = hi;
  result.word.lo = v1;
  return result.whole;
}
