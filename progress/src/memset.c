/* Sets n bytes at dst to the low byte of c. Writes the unaligned head and tail a byte or
   halfword at a time and the aligned middle a word at a time. Returns dst. */
#ifdef PORT
void *memset(void *dst, s32 c, u32 n)
#else
s32 memset(s32 dst, s32 c, u32 n)
#endif
{
    u32 pat;
#ifdef PORT
    u8 *p;
#else
    s32 p;
#endif
    u32 n_left;
    s32 words;

    if (n != 0) {
        pat = c & 0xFF;
        pat = pat | (pat << 8);
        pat = pat | (pat << 16);
        p = dst;
        n_left = n;
        #ifdef PORT
        if (((uintptr_t)p & 1)) {
#else
        if (p & 1) {
#endif
            *((s8 *)p) = pat;
            p += 1;
            n_left -= 1;
        }
        words = n_left >> 2;
        if (n_left >= 2) {
            #ifdef PORT
            if (((uintptr_t)p & 2)) {
#else
            if (p & 2) {
#endif
                *((s16 *)p) = pat;
                p += 2;
                n_left -= 2;
                words = n_left >> 2;
            }
        }
        words -= 1;
        if (words != -1) {
            do {
                *((s32 *)p) = pat;
                words -= 1;
                p += 4;
            } while (words != -1);
        }
        if (n_left & 2) {
            *((s16 *)p) = pat;
            p += 2;
        }
        if (n_left & 1) {
            *((s8 *)p) = pat;
        }
    }
    return dst;
}
