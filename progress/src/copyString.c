/* Copies the NUL-terminated string src to dst and returns dst. Copies a word
 * at a time once both pointers are aligned, and stops at the first zero byte
 * (the bytes of the last word are checked, so the terminator is not overrun). */
char *copyString(char *dst, char *src, u32 n)
{
    char *d = dst;
    u32 w;
    u32 x;

    if (((u32)(src - dst)) & 3) {
bytes:
        while (n-- != 0) {
            if ((*d++ = *src++) == 0) {
                return dst;
            }
        }
        return dst;
    }
    w = n >> 2;
    if ((u32)d & 3) {
        do {
            if (n-- == 0) {
                return dst;
            }
            if ((*d++ = *src++) == 0) {
                return dst;
            }
        } while ((u32)d & 3);
        w = n >> 2;
    }
    while (w-- != 0) {
        x = *(u32 *)src;
        src += 4;
        if (!(x & 0xFF000000)) {
            *d = 0;
            return dst;
        }
        if (!(x & 0xFF0000)) {
            *(u16 *)d = x >> 16;
            return dst;
        }
        if (!(x & 0xFF00)) {
            x >>= 16;
            *(u16 *)d = x;
            d[2] = 0;
            return dst;
        }
        *(u32 *)d = x;
        d += 4;
        if (!(x & 0xFF)) {
            return dst;
        }
    }
    n &= 3;
    goto bytes;
}
