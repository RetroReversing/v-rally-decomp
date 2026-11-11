/* Fills the 8-short record `out` from the source rectangle `src` (x at [0], y at [1], width
 * at [2], height at [3]): the top-left and bottom-right corners in 2x units, then the two
 * 0x1FF/0 limit pairs. */
void func_8000DEF0(s16 *out, s16 *src) {
    out[0] = src[2] * 2;
    out[1] = src[3] * 2;
    out[2] = 0x1FF;
    out[3] = 0;
    out[4] = src[2] * 2 + src[0] * 4;
    out[5] = src[3] * 2 + src[1] * 4;
    out[6] = 0x1FF;
    out[7] = 0;
}
