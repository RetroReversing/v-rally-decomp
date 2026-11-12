/* Copies a NUL-terminated string. When src and dst differ in alignment it copies byte
 * by byte; otherwise it copies a word at a time and finishes with a halfword or byte
 * store so the NUL is never written past. Returns dst. */
u8 *strCpy(u8 *dst, u8 *src)
{
    u32 w;
    u8 c;
    u8 *d = dst, *s = src;

    if (((u32)(s - d) & 3) != 0) {
        c = *s++;
        *d++ = c;
        if (c) do { c = *s++; *d++ = c; } while (c);
        return dst;
    }
#ifdef PORT
    if ((uintptr_t)d & 3) {
#else
    if ((u32)d & 3) {
#endif
        do {
            c = *s++;
            *d++ = c;
            if (!c) return dst;
#ifdef PORT
        } while ((uintptr_t)d & 3);
#else
        } while ((u32)d & 3);
#endif
    }
    for (;;) {
        w = *(u32 *)s;
        s += 4;
        if (!(w & 0xFF000000)) {
            *d = 0;
            return dst;
        }
        if (!(w & 0x00FF0000)) {
            *(u16 *)d = (u16)(w >> 16);
            return dst;
        }
        if (!(w & 0x0000FF00)) {
            u16 h = w >> 16;
            *(u16 *)d = h;
            d[2] = 0;
            return dst;
        }
        *(u32 *)d = w;
        d += 4;
        if (!(w & 0xFF)) return dst;
    }
}
