void mat3x3MulQ12();
s32 cos_q12();
s32 sin_q12();

/* Builds a 3x3 rotation matrix (Q12 fixed point) from three s16 Euler angles in angles[0..2].
 * The matrix is rot_y(angles[1]) * rot_x(angles[0]) * rot_z(angles[2]); it is written to out.
 * cos_q12 returns the cosine and sin_q12 the sine of an s16 angle, both in Q12. */
s16 *mat3_from_euler_angles(s16 *angles, s16 *out)
{
  s16 rot_y[16];
  s16 rot_x[16];
  s16 rot_z[16];
  s16 rot_yx[16];
  s16 *dst;
  s16 cos0;
  s16 sin0;
  s16 cos1;
  s16 sin1;
  s16 cos2;
  s16 sin2;

  dst = out;
  sin0 = angles[0];
  cos0 = cos_q12(sin0);
  sin0 = sin_q12(angles[0]);
  cos1 = cos_q12(angles[1]);
  sin1 = sin_q12(angles[1]);
  cos2 = cos_q12(angles[2]);
  sin2 = sin_q12(angles[2]);
  rot_y[0] = cos1;
  rot_y[1] = 0;
  {
    s16 positive = sin1;
    ;
    rot_y[2] = positive;
  }
  rot_y[3] = 0;
  rot_y[4] = 0x1000;
  rot_y[5] = 0;
  rot_y[6] = -sin1;
  rot_y[7] = 0;
  rot_y[8] = cos1;
  rot_x[0] = 0x1000;
  rot_x[1] = 0;
  rot_x[2] = 0;
  rot_x[3] = 0;
  rot_x[4] = cos0;
  rot_x[5] = -sin0;
  rot_x[6] = 0;
  rot_x[7] = sin0;
  rot_x[8] = cos0;
  rot_z[0] = cos2;
  rot_z[1] = -sin2;
  rot_z[2] = 0;
  rot_z[3] = sin2;
  rot_z[4] = cos2;
  rot_z[5] = 0;
  rot_z[6] = 0;
  rot_z[7] = 0;
  rot_z[8] = 0x1000;
  mat3x3MulQ12(rot_y, rot_x, rot_yx);
  mat3x3MulQ12(rot_yx, rot_z, dst);
  return dst;
}
