s16 cos_q12(s32);
s16 sin_q12(s32);

/* Writes a Y-axis rotation matrix (Q12 fixed point) for the angle into the
   3x3 s16 matrix at out, and returns out. */
s16 *setYRotationMatrix(s32 angle, s16 *out)
{
    s16 cos_v;
    s16 sin_v;

    cos_v = cos_q12(angle);
    sin_v = sin_q12(angle);
    out[2] = sin_v;
    out[0] = cos_v;
    out[1] = 0;
    out[3] = 0;
    out[4] = 0x1000;
    out[5] = 0;
    out[6] = -sin_v;
    out[7] = 0;
    out[8] = cos_v;
    return out;
}
