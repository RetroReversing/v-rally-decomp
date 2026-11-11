s32 mat3_set_current();
/* 3x3 matrix product in Q12 fixed point: out = a * b, row-major. Each sum is rounded toward zero
 * before the >> 12 shift, so negative products round the same way the game's math does. */
void mat3x3MulQ12(s16 *a, s16 *b, s16 *out)
{
  u16 tmp[3][3];
  s32 pad[2];
  s32 sum;
  s32 val;
  s16 *row;
  s16 i;
  s16 j;
  s16 k;
  mat3_set_current();
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      sum = 0;
      k = 0;
      row = a - (-(j * 3));
      for (; k < 3; k++)
      {
        sum += row[k] * (*((s16 *) ((((u8 *) b) + (k * 6)) + (i * 2))));
      }

      if (sum >= 0)
      {
        val = sum;
      }
      else
      {
        val = sum + 0xFFF;
      }
      sum = val >> 12;
      tmp[j][i] = sum;
    }

  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      *((u16 *) ((((u8 *) out) + (j * 6)) + (i * 2))) = tmp[j][i];
    }

  }

}
