extern u16 D_800A1D00[];

/* Sine of a 16-bit angle (top 12 bits used): looks up a 1024-entry quarter-wave table,
 * mirroring at the half-period (0x400) and negating in the second half (0x800). */
s32 sins(s32 angle)
{
  short phase;
  s32 index;
  u16 value;
  int new_var;
  phase = ((u16) angle) >> 4;
  if (phase & 0x400)
  {
    index = (new_var = (~phase) & 0x3FF);
  }
  else
  {
    index = phase & 0x3FF;
  }
  value = D_800A1D00[index];
  if (phase & 0x800)
  {
    return (s16) (-value);
  }
  return (s16) value;
}
