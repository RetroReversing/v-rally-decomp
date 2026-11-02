#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern char D_800ADF08[];
s32 func_80098998(s8 *arg0, s32 arg1, s32 arg2);
f64 func_8009A590(f64 arg0, f64 *arg2);
extern f64 D_800A3DB8;
extern f64 D_800A3E00;
extern char D_800A7290[];
extern char D_800A7294[];
extern f64 D_800A7298;
extern f64 D_800A72A0;
extern f64 D_800A72A8;
extern f64 D_800A72B0;
extern f64 D_800A72B8;

typedef union {
    f64 d;
    u32 w[2];
} DBits;

char *func_80098B7C(f64 value, s32 ndigit, s32 *decpt, s32 *sign) {
    DBits bits;
    volatile f64 x;
    f64 ip;
    f64 ten;
    s32 exp10;
    s32 bit;
    s32 n;
    s32 i;
    f64 *pp;
    f64 *np;
    char *p;

    exp10 = 0; 
    bit = 0x100;
    n = ndigit;
    *sign = 0;
    if (ndigit >= 20) {
        ndigit = 20;
        n = 19;
    }
    bits.d = value; switch (bits.w[0] & 0x7FF00000) {
    case 0:
        p = D_800ADF08;
        for (i = 0; i < ndigit; i++) {
            *p++ = '0';
        }
        *decpt = 1;
        return D_800ADF08;
    case 0x7FF00000:
        *decpt = 0x7FFFFFFF;
        if ((bits.w[0] & 0xFFFFF) || bits.w[1]) {
            __builtin_memcpy(D_800ADF08, D_800A7290, 4);
            *sign = 0;
            return D_800ADF08;
        }
        __builtin_memcpy(D_800ADF08, D_800A7294, 4); return D_800ADF08;
    }
    if (value < 0.0) {
        *sign = 1;
        value = -value;
    }
    if (value >= D_800A7298) {
        np = &D_800A3E00;
        pp = &D_800A3DB8;
        for (i = 8; i >= 0; i--) {
            if (value >= *pp) {
                exp10 += bit; value *= *np;
            }
            bit >>= 1;
            np--;
            pp--;
        }
    } else {
        np = &D_800A3DB8;
        pp = &D_800A3E00;
        for (i = 8; i >= 0; i--) {
            if (value < *pp) {
                exp10 -= bit; value *= *np;
            }
            bit >>= 1;
            np--;
            pp--;
        }
        exp10--; value *= D_800A72A0;
    }
    x = value;
again:
    if (x >= D_800A72A8) {
        exp10++;
        x *= D_800A72B0; goto again;
    }
    if (x < D_800A72B8) {
        exp10--;
        x *= D_800A72A8; goto again;
    }
    ten = D_800A72A8;
    p = D_800ADF08;
    do {
        x = func_8009A590(x, &ip) * ten;
        *p++ = (s32)ip + '0';
    } while (--n >= 0);
    if (ndigit >= 20) {
        *decpt = exp10 + 1;
    } else {
        *decpt = func_80098998(D_800ADF08, exp10, ndigit) + 1;
    }
    return D_800ADF08;
}

