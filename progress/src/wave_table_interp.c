s16 wave_table_get();

/* Looks up a wave table value for a 16-bit position: the top 12 bits pick the
 * entry and the low 4 bits give the fraction (out of 15) toward the next entry. */
s16 wave_table_interp(s32 pos)
{
  int lo;
  int step;
  s16 temp_s0;
  s32 index;
  index = ((s32) (pos << 0x10)) >> 0x14;
  lo = wave_table_get(index);
  temp_s0 = lo;
  step = wave_table_get(index + 1) - temp_s0;
  return (s16) (temp_s0 + (((pos & 0xF) * step) / 15));
}
