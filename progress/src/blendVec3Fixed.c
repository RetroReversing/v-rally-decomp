/* Adds a bias so that a negative sum rounds toward zero when shifted right by 12. */
static inline int roundTowardZeroBias(s32 sum)
{
  return sum + 0xFFF;
}

/* Blends two 3-element s16 vectors with fixed-point gains (1.0 = 4096):
 * dst[i] = (a[i] * gainA + b[i] * gainB) / 4096, truncated toward zero. */
void blendVec3Fixed(s16 *vecA, s16 *vecB, s32 gainA, s32 gainB, s16 *dst)
{
  s32 v;
  s32 x;
  v = vecA[0] * gainA; v += vecB[0] * gainB;
  if (v >= 0)
  {
    x = v;
  }
  else
  {
    x = roundTowardZeroBias(v);
  }
  v = x >> 12;
  dst[0] = v;
  v = vecA[1] * gainA; v += vecB[1] * gainB;
  if (v >= 0)
  {
    x = v;
  }
  else
  {
    x = roundTowardZeroBias(v);
  }
  v = x >> 12;
  dst[1] = v;
  v = vecA[2] * gainA; gainA=v; gainA += vecB[2] * gainB;
  if (gainA >= 0)
  {
    x = gainA;
  }
  else
  {
    x = roundTowardZeroBias(gainA);
  }
  gainA = x >> 12;
  dst[2] = gainA;
}
