/* Converts a libultra fixed-point matrix (16.16 pairs packed in 32-bit words) into a 4x4 float
 * matrix, scaling by 1/65536. */
void guMtxL2F(f32 *mf, s32 *mtx)
{
    volatile s32 sp0;
    volatile s32 sp4;
    s32 row;
    s32 col;
    s32 temp_v0;
    s32 temp_v1;
    s32 *var_a1;
    u16 *var_t0;
    f32 *var_a2;

    var_t0 = (u16 *) ((char *) mtx + 0x20);
    row = 0;
    var_a1 = mtx;
    do {
        col = 0;
        var_a2 = mf;
        do {
            temp_v0 = (*var_a1 & 0xFFFF0000) | var_t0[0];
            sp0 = temp_v0;
            temp_v1 = ((*var_a1 << 0x10) & 0xFFFF0000) | var_t0[1];
            sp4 = temp_v1;
            var_a2[0] = (f32) temp_v0 * 0.000015258789f;
            var_a2[1] = (f32) temp_v1 * 0.000015258789f;
            col += 1;
            var_t0 += 2;
            var_a1 += 1;
            var_a2 += 2;
        } while (col < 2);
        row += 1;
        mf += 4;
    } while (row < 4);
}
