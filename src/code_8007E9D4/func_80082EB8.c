#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
s32 func_80082094(void);
void func_800821A4(u8 *, s32, s32);
typedef struct {
    u8 *ptr;
    s32 cnt;
    u8 pad[0x74];
    u32 wp;
    u32 bb;
    u32 bk;
} InflState;
extern InflState D_800C333C;
extern u8 D_800AE850[];

#define NEXTBYTE() (--D_800C333C.cnt >= 0 ? *D_800C333C.ptr++ : func_80082094())
#define NEEDBITS(n) while (k < (n)) { c = NEXTBYTE(); if (c == -1) return 1; b |= (u32)c << k; k += 8; }
#define DUMPBITS(n) { b >>= (n); k -= (n); }

s32 func_80082EB8(void) {
    u32 n;
    u32 w;
    u32 b;
    u32 k;
    s32 c;

    b = D_800C333C.bb;
    k = D_800C333C.bk;
    w = D_800C333C.wp;
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
        (D_800AE850 + 0x8AE8)[w++] = (u8)b;
        if (w == 0x8000) {
            func_800821A4(D_800AE850 + 0x8AE8, 0x8000, 0);
            w = 0;
        }
        DUMPBITS(8);
    }
    D_800C333C.wp = w;
    D_800C333C.bb = b;
    D_800C333C.bk = k;
    return 0;
}

