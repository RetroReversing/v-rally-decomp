s32 mat3_set_current();

/* Multiplies the 3x3 fixed-point (12 fractional bits) matrix m by vector v and
 * writes the rounded-toward-zero result to out. Returns out. */
s32 *mat3_transform_vec(s16 *m, s16 *v, s32 *out)
{
  s32 temp_a1;
  s32 var_v0;

  mat3_set_current();
  temp_a1 = m[0];
  temp_a1 *= v[0];
  temp_a1 += m[1] * v[1];
  temp_a1 += m[2] * v[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a1 = var_v0 >> 12;
  out[0] = temp_a1;
  temp_a1 = m[3];
  temp_a1 *= v[0];
  temp_a1 += m[4] * v[1];
  temp_a1 += m[5] * v[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a1 = var_v0 >> 12;
  out[1] = temp_a1;
  temp_a1 = m[6];
  temp_a1 *= v[0];
  temp_a1 += m[7] * v[1];
  temp_a1 += m[8] * v[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a1 = var_v0 >> 12;
  out[2] = temp_a1;
  return out;
}
