extern s32 *gStreamBuf;
extern s32 D_800A19C4;
extern s32 gStreamBufFill;
extern char D_800A1924[];
extern char gStreamState[];
s32 func_8007F864(s32 *a0, u32 a1, s32 a2);

/* Fills the stream buffer with the fill word and records the buffer's status string and
 * fill result in the stream state. Returns 1 when a buffer is set up, 0 otherwise. */
s32 stream_buffer_init(void)
{
    s32 *a0;
    u32 a1;
    s32 *p;
    u32 n;
    s32 val;
    s32 ret;

    a0 = gStreamBuf;
    a1 = D_800A19C4;
    if (a0 != NULL) {
        n = a1 >> 2;
        val = gStreamBufFill;
        if (n != 0) {
            p = a0;
            do {
                *p = val;
                p++;
                n--;
            } while (n != 0);
        }
        *(s32 *)(gStreamState + 0x7032) = func_8007F864(a0, a1, val);
        *(char **)(gStreamState + 0x590A) = D_800A1924;
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}
