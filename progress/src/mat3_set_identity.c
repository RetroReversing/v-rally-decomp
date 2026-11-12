/* Sets a 3x3 s16 rotation matrix (4.12 fixed point) to the identity. */
void mat3_set_identity(s16 *m) {
    m[0] = 0x1000;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0x1000;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0x1000;
}
