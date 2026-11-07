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
extern InflState D_800C333C;
extern u16 D_800A19F0[];
extern u32 D_800A1A20[];
extern u16 D_800A1A6C[];
extern u16 D_800A1AAC[];
extern u16 D_800A1AEC[];
extern u16 D_800A1B28[];
extern s32 D_800A1B64;
extern s32 D_800A1B68;
s32 func_80082094(void);
s32 huft_build(u32 *, u32, u32, u16 *, u16 *, struct huft **, s32 *);
s32 huft_free(struct huft *);
s32 inflate_codes(struct huft *, struct huft *, s32, s32);

#define NEXTBYTE() (--D_800C333C.cnt >= 0 ? *D_800C333C.ptr++ : func_80082094())
#define NEEDBITS(n) while (k < (n)) { c = NEXTBYTE(); if (c == -1) return 1; b |= (u32)c << k; k += 8; }
#define DUMPBITS(n) { b >>= (n); k -= (n); }

s32 inflate_dynamic(void)
{
    s32 i;
    u32 j;
    u32 l;
    u32 m;
    u32 n;
    struct huft *tl;
    struct huft *td;
    s32 bl;
    s32 bd;
    u32 nb;
    u32 nl;
    u32 nd;
    u32 ll[320];
    u32 b;
    u32 k;
    s32 c;

    b = D_800C333C.bb;
    k = D_800C333C.bk;

    NEEDBITS(5)
    nl = 257 + (b & 0x1f);
    DUMPBITS(5)
    NEEDBITS(5)
    nd = 1 + (b & 0x1f);
    DUMPBITS(5)
    NEEDBITS(4)
    nb = 4 + (b & 0xf);
    DUMPBITS(4)
    if (nl > 288 || nd > 32) {
        return 1;
    }

    for (j = 0; j < nb; j++) {
        NEEDBITS(3)
        ll[D_800A1A20[j]] = b & 7;
        DUMPBITS(3)
    }
    for (; j < 19; j++) {
        ll[D_800A1A20[j]] = 0;
    }

    bl = 7;
    i = huft_build(ll, 19, 19, NULL, NULL, &tl, &bl);
    if (bl == 0) {
        i = 1;
    }
    if (i != 0) {
        if (i == 1) {
            huft_free(tl);
        }
        return i;
    }

    n = nl + nd;
    m = D_800A19F0[bl];
    i = l = 0;
    while ((u32)i < n) {
        NEEDBITS((u32)bl)
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

    D_800C333C.bb = b;
    D_800C333C.bk = k;

    bl = D_800A1B64;
    i = huft_build(ll, nl, 257, D_800A1A6C, D_800A1AAC, &tl, &bl);
    if (bl == 0) {
        i = 1;
    }
    if (i != 0) {
        if (i == 1) {
            huft_free(tl);
        }
        return i;
    }
    bd = D_800A1B68;
    i = huft_build(ll + nl, nd, 0, D_800A1AEC, D_800A1B28, &td, &bd);
    if (bd == 0 && nl > 257) {
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

    if (inflate_codes(tl, td, bl, bd)) {
        return 1;
    }

    huft_free(tl);
    huft_free(td);
    return 0;
}
