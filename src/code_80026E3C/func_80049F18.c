#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct {
    u8 data[5][0x2A];
    s16 vals[5];
    u8 count;
    u8 pad;
} Rec;
typedef struct {
    u8 pad0[4];
    u8 obj[6];
    Rec recs[4];
    u8 pad1[0x3A4 - 0x382];
    s32 x3A4;
} Mgr;
extern Mgr *D_800A0384;
void memset(void *, s32, s32);
void func_80098290(void *, void *);
s16 func_8000C9B0(void *, void *, s32, s32, s32);

void func_80049F18(void)
{
    u8 buf[0x2A];
    u8 i;
    u8 j;
    Mgr *m;
    s16 v;

    memset(buf, 0, 0x2A);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            D_800A0384->recs[i].vals[j] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_800A0384->recs[i].count; j++) {
            func_80098290(buf, D_800A0384->recs[i].data[j]);
            D_800A0384->recs[i].vals[j] = func_8000C9B0(D_800A0384->pad0 + 4, buf, 1, D_800A0384->x3A4, 0);
        }
    }
}

