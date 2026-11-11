/* Writes a 3-term cross-style sum of packed fixed-point values to *out: the high
 * halves of a, b and c are multiplied by the low halves of the other two. */
void func_8002D75C(s32 a, s32 b, s32 c, s32 *out) {
    *out = ((a >> 16) * (s16)b) + ((b >> 16) * (s16)c) + ((c >> 16) * (s16)a)
         - ((a >> 16) * (s16)c) - ((b >> 16) * (s16)a) - ((c >> 16) * (s16)b);
}
