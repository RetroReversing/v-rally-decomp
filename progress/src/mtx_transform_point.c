/* 4x4 float matrix, m[col][row]. The x/y/z terms of the transform sit at offsets 0x00-0x28 and the w terms at 0x0C-0x3C. */
typedef struct Mat4 { f32 m[4][4]; } Mat4;

/* Transforms the point (x, y, z) by the matrix mtx. The transformed x, y, z go to out_x, out_y, out_z
 * and the w value is returned. When w is 0 the outputs are zeroed and 0 is returned. Otherwise, when w
 * is not 1, the outputs are divided by w (perspective divide) and w is returned; when w is 1, 0 is returned. */
f32 mtx_transform_point(Mat4 *mtx, f32 x, f32 y, f32 z, f32 *out_x, f32 *out_y, f32 *out_z)
{
  f32 *new_var;
  f32 new_var2;
  f32 w;

  new_var2 = z;
  w = ((((mtx->m[0][3]) * x) + ((mtx->m[1][3]) * y)) + ((mtx->m[2][3]) * new_var2)) + (mtx->m[3][3]);
  if (w == 0.0f)
  {
    *out_x = 0.0f;
    *out_y = 0.0f;
    *out_z = 0.0f;
    return 0.0f;
  }
  new_var = out_x;
  *new_var = (((mtx->m[0][0]) * x) + ((mtx->m[1][0]) * y)) + ((mtx->m[2][0]) * z);
  *out_y = (((mtx->m[0][1]) * x) + ((mtx->m[1][1]) * y)) + ((mtx->m[2][1]) * z);
  *out_z = (((mtx->m[0][2]) * x) + ((mtx->m[1][2]) * y)) + ((mtx->m[2][2]) * z);
  if (w != 1.0f)
  {
    if (mtx)
    {
      *out_x /= w;
      *out_y /= w;
      *out_z /= w;
      return w;
    }
    else
    {
      *out_x /= w;
      *out_y /= w;
      *out_z /= w;
      return w;
    }
  }
  return 0.0f;
}
