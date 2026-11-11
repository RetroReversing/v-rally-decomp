/* Writes a 4x4 f32 matrix (row-major, 16 bytes per row) to *mtx: identity with the translation
 * in the last row, taken from pos[5..7]. The integer zeros are stored first, then the diagonal
 * and the translation words are overwritten as floats. */
void mtx_init_translate(s32 *mtx, s32 *pos) {
    u8 row;
    u8 col;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            ((s32 *)((u8 *)mtx + row * 16))[col] = 0;
        }
    }
    *(f32 *)((u8 *)mtx + 0x30) = (f32)pos[5];
    *(f32 *)((u8 *)mtx + 0x34) = (f32)pos[6];
    *(f32 *)((u8 *)mtx + 0x38) = (f32)pos[7];
    *(f32 *)((u8 *)mtx + 0x3C) = 1.0f;
    *(f32 *)((u8 *)mtx + 0x00) = 1.0f;
    *(f32 *)((u8 *)mtx + 0x14) = 1.0f;
    *(f32 *)((u8 *)mtx + 0x28) = 1.0f;
}
