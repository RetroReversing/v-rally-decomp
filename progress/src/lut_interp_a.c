/* identical to wave_table_interp (matched), with its names changed by decompdecomp */

s16 wave_table_get_mirrored();
s16 lut_interp_a(s32 arg0)
{
  int new_var;
  int new_var2;
  s16 temp_s0;
  s32 temp_s0_2;
  temp_s0_2 = ((s32) (arg0 << 0x10)) >> 0x14;
  new_var = wave_table_get_mirrored(temp_s0_2);
  temp_s0 = new_var;
  new_var2 = wave_table_get_mirrored(temp_s0_2 + 1) - temp_s0;
  return (s16) (temp_s0 + (((arg0 & 0xF) * new_var2) / 15));
}
