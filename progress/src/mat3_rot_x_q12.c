s16 cos_q12();
s16 sin_q12();

/* Fills the 3x3 s16 matrix at m with a rotation about the X axis by angle, in 4096 = 1.0 fixed point:
 * identity in row 0 and column 0, cos in [4] and [8], sin in [7] and -sin in [5]. Returns m. */
s16 *mat3_rot_x_q12(s32 angle, s16 *m)
{
    s16 cos_v;
    s16 sin_v;

    cos_v = cos_q12(angle);
    sin_v = sin_q12(angle);
    m[0] = 0x1000;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = cos_v;
    m[5] = -sin_v;
    m[6] = 0;
    m[7] = sin_v;
    m[8] = cos_v;
    return m;
}
