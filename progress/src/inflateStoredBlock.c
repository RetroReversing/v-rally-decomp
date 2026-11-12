s32 order_stream_next_byte(void);
void func_800821A4(u8 *, s32, s32);
typedef struct {
    u8 *in_ptr;
    s32 in_left;
    u8 pad[0x74];
    u32 win_pos;
    u32 bit_buf;
    u32 bit_cnt;
} InflState;
extern InflState inflateState;
extern u8 gOrderState[];

#define INFL_WINDOW (gOrderState + 0x8AE8)
#define WINDOW_SIZE 0x8000
#define NEXTBYTE() (--inflateState.in_left >= 0 ? *inflateState.in_ptr++ : order_stream_next_byte())
#define NEEDBITS(n) while (k < (n)) { c = NEXTBYTE(); if (c == -1) return 1; b |= (u32)c << k; k += 8; }
#define DUMPBITS(n) { b >>= (n); k -= (n); }

/* Inflate a stored (uncompressed) block. Skips to a byte boundary, reads LEN and its
 * complement NLEN (returns 1 if they do not match), then copies LEN bytes into the
 * 32 KB window. The window is flushed through func_800821A4 each time it fills. Returns 0 on
 * success. The bit buffer and window position are kept in inflateState between calls. */
s32 inflateStoredBlock(void) {
    u32 n;
    u32 w;
    u32 b;
    u32 k;
    s32 c;

    b = inflateState.bit_buf;
    k = inflateState.bit_cnt;
    w = inflateState.win_pos;
    n = k & 7;
    DUMPBITS(n);
    NEEDBITS(16);
    n = b & 0xffff;
    DUMPBITS(16);
    NEEDBITS(16);
    if (n != ((~b) & 0xffff)) return 1;
    DUMPBITS(16);
    while (n--) {
        NEEDBITS(8);
        (INFL_WINDOW)[w++] = (u8)b;
        if (w == WINDOW_SIZE) {
            func_800821A4(INFL_WINDOW, WINDOW_SIZE, 0);
            w = 0;
        }
        DUMPBITS(8);
    }
    inflateState.win_pos = w;
    inflateState.bit_buf = b;
    inflateState.bit_cnt = k;
    return 0;
}
