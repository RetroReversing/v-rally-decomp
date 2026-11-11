s16 cos_q12();
s16 sin_q12();

/* Fills the 3x3 s16 matrix m (Q12) with a rotation about the Z axis by angle, using cos_q12 and sin_q12. Returns m. */
s16 *mat3_set_rot_z(s32 angle, s16 *m)
{
    s16 c;
    s16 s;

    c = cos_q12(angle);
    s = sin_q12(angle);
    m[1] = -s;
    m[0] = c;
    m[2] = 0;
    m[3] = s;
    m[4] = c;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0x1000;
    return m;
}
