typedef struct {
    u8 *ptr;
    s32 cnt;
    u8 pad[0x74];
    u32 wp;
    u32 bb;
    u32 bk;
} InflState;
struct huft {
    u8 e;
    u8 b;
    union {
        u16 n;
        struct huft *t;
    } v;
};
extern InflState inflateState;
extern u16 mask_bits[];
extern u32 border_order[];
extern u16 cplens[];
extern u16 cplext[];
extern u16 cpdist[];
extern u16 cpdext[];
extern s32 lbits;
extern s32 dbits;
s32 order_stream_next_byte(void);
s32 huft_build(u32 *, u32, u32, u16 *, u16 *, struct huft **, s32 *);
s32 huft_free(struct huft *);
s32 inflate_codes(struct huft *, struct huft *, s32, s32);

#define NEXTBYTE() (--inflateState.cnt >= 0 ? *inflateState.ptr++ : order_stream_next_byte())
#define NEEDBITS(n) while (k < (n)) { c = NEXTBYTE(); if (c == -1) return 1; b |= (u32)c << k; k += 8; }
#define DUMPBITS(n) { b >>= (n); k -= (n); }

/* Reads the dynamic Huffman block header (inflate type 2), builds the literal and distance tables, and decodes them. */ s32 inflate_dynamic(void)
{
    s32 i;
    u32 j;
    u32 l;
    u32 m;
    u32 n;
    struct huft *tl;
    struct huft *td;
    s32 litBits;
    s32 distBits;
    u32 numCodeLen;
    u32 numLitLen;
    u32 numDist;
    u32 ll[320];
    u32 b;
    u32 k;
    s32 c;

    b = inflateState.bb;
    k = inflateState.bk;

    NEEDBITS(5)
    numLitLen = 257 + (b & 0x1f);
    DUMPBITS(5)
    NEEDBITS(5)
    numDist = 1 + (b & 0x1f);
    DUMPBITS(5)
    NEEDBITS(4)
    numCodeLen = 4 + (b & 0xf);
    DUMPBITS(4)
    if (numLitLen > 288 || numDist > 32) {
        return 1;
    }

    for (j = 0; j < numCodeLen; j++) {
        NEEDBITS(3)
        ll[border_order[j]] = b & 7;
        DUMPBITS(3)
    }
    for (; j < 19; j++) {
        ll[border_order[j]] = 0;
    }

    litBits = 7;
    i = huft_build(ll, 19, 19, NULL, NULL, &tl, &litBits);
    if (litBits == 0) {
        i = 1;
    }
    if (i != 0) {
        if (i == 1) {
            huft_free(tl);
        }
        return i;
    }

    n = numLitLen + numDist;
    m = mask_bits[litBits];
    i = l = 0;
    while ((u32)i < n) {
        NEEDBITS((u32)litBits)
        j = (td = tl + (b & m))->b;
        DUMPBITS(j)
        j = td->v.n;
        if (j < 16) {
            ll[i++] = l = j;
        } else if (j == 16) {
            NEEDBITS(2)
            j = 3 + (b & 3);
            DUMPBITS(2)
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = l;
            }
        } else if (j == 17) {
            NEEDBITS(3)
            j = 3 + (b & 7);
            DUMPBITS(3)
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        } else {
            NEEDBITS(7)
            j = 11 + (b & 0x7f);
            DUMPBITS(7)
            if ((u32)i + j > n) {
                return 1;
            }
            while (j--) {
                ll[i++] = 0;
            }
            l = 0;
        }
    }

    huft_free(tl);

    inflateState.bb = b;
    inflateState.bk = k;

    litBits = lbits;
    i = huft_build(ll, numLitLen, 257, cplens, cplext, &tl, &litBits);
    if (litBits == 0) {
        i = 1;
    }
    if (i != 0) {
        if (i == 1) {
            huft_free(tl);
        }
        return i;
    }
    distBits = dbits;
    i = huft_build(ll + numLitLen, numDist, 0, cpdist, cpdext, &td, &distBits);
    if (distBits == 0 && numLitLen > 257) {
        huft_free(tl);
        return 1;
    }
    if (i == 1) {
        i = 0;
    }
    if (i != 0) {
        huft_free(tl);
        return i;
    }

    if (inflate_codes(tl, td, litBits, distBits)) {
        return 1;
    }

    huft_free(tl);
    huft_free(td);
    return 0;
}
