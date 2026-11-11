void mat3_set_current();

/* Multiplies a 3x3 matrix of s16 Q12 elements by the s32 vector vec and writes the
 * three components to out, each rounded from Q12 (toward zero). Copies the matrix
 * to the current matrix first. */
s32 *mat3_mul_vec3_q12(s16 *mat, s32 *vec, s32 *out)
{
  s32 result[3];
  s32 sum;
  s32 x;
  s32 rounded;

  mat3_set_current();

  sum = mat[0];
  sum *= vec[0];
  sum += mat[1] * vec[1];
  sum += mat[2] * vec[2];
  if (sum >= 0) {
    rounded = sum;
  } else {
    rounded = sum + 0xFFF;
  }
  x = rounded >> 12;
  result[0] = x;

  sum = mat[3];
  sum *= vec[0];
  sum += mat[4] * vec[1];
  sum += mat[5] * vec[2];
  if (sum >= 0) {
    rounded = sum;
  } else {
    rounded = sum + 0xFFF;
  }
  sum = rounded >> 12;
  result[1] = sum;

  sum = mat[6];
  sum *= vec[0];
  sum += mat[7] * vec[1];
  sum += mat[8] * vec[2];
  if (sum >= 0) {
    rounded = sum;
  } else {
    rounded = sum + 0xFFF;
  }
  sum = rounded >> 12;
  result[2] = sum;

  out[0] = x;
  out[1] = result[1];
  out[2] = result[2];
  return out;
}
