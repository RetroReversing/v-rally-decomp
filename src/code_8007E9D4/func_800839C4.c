#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct InflateState { u8 *ptr; s32 cnt; u8 pad8[0x74]; u32 wp; u32 bb; u32 bk; } InflateState;
extern InflateState D_800C333C;
extern s32 func_80082094(void);
extern s32 func_80082EB8(void);
extern s32 func_800830C8(void);
extern s32 inflate_dynamic(void);

#define NEXTBYTE() (--D_800C333C.cnt >= 0 ? (s32)*D_800C333C.ptr++ : func_80082094())
#define NEEDBITS(n) { while (k < (n)) { s32 c = NEXTBYTE(); if (c == -1) return 1; b |= ((u32)c) << k; k += 8; } }
#define DUMPBITS(n) { b >>= (n); k -= (n); }

s32 func_800839C4(s32 *e) {
    u32 t;
    u32 b;
    u32 k;

    b = D_800C333C.bb;
    k = D_800C333C.bk;
    NEEDBITS(1)
    *e = (s32)b & 1;
    DUMPBITS(1)
    NEEDBITS(2)
    t = (u32)b & 3;
    DUMPBITS(2)
    D_800C333C.bb = b;
    D_800C333C.bk = k;
    if (t == 2) return inflate_dynamic();
    if (t == 0) return func_80082EB8();
    if (t == 1) return func_800830C8();
    return 2;
}

