/* Copies the four 16-bit words of a 8-byte record from src to dst. Returns 1. */
s32 func_80005BDC(void *dst, void *src)
{
    u16 *d = (u16 *)dst;
    u16 *s = (u16 *)src;
    d[0] = (u16) s[0];
    d[1] = (u16) s[1];
    d[2] = (u16) s[2];
    d[3] = (u16) s[3];
    return 1;
}
