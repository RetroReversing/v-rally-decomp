typedef struct { f32 col[4][4]; } Mat4;

/* Transforms the point (x, y, z, 1) by the column-major 4x4 matrix m. Writes the
   transformed x, y and z to out_x, out_y and out_z and divides them by the resulting w.
   Returns w, or 0 when w is 0 (outputs zeroed) or 1 (outputs left undivided). */
f32 func_8001BE68(Mat4 *m, f32 x, f32 y, f32 z, f32 *out_x, f32 *out_y, f32 *out_z)
{
  f32 w;
  w = ((((m->col[0][3]) * x) + ((m->col[1][3]) * y)) + ((m->col[2][3]) * z)) + (m->col[3][3]);
  if (w == 0.0f)
  {
    *out_x = 0.0f;
    *out_y = 0.0f;
    *out_z = 0.0f;
    return 0.0f;
  }
  *out_x = ((((m->col[0][0]) * x) + ((m->col[1][0]) * y)) + ((m->col[2][0]) * z)) + (m->col[3][0]);
  *out_y = ((((m->col[0][1]) * x) + ((m->col[1][1]) * y)) + ((m->col[2][1]) * z)) + (m->col[3][1]);
  *out_z = ((((m->col[0][2]) * x) + ((m->col[1][2]) * y)) + ((m->col[2][2]) * z)) + (m->col[3][2]);
  if (w == 1.0f) return 0.0f;

  {
    do { *out_x /= w; *out_y /= w; *out_z /= w; return w; } while (0);
  }
}
