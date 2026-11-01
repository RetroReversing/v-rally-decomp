#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Track {
    s32 count;
    s32 *a;
    s32 *b;
    s32 *c;
} Track;
typedef struct Ent {
    s32 x0;
    u8 pad04[0x2C];
    s32 x30;
    s32 x34;
    u8 pad38[8];
    s32 x40;
    u8 pad44[0x2C];
    Track *owner;
    u8 pad74[4];
    s32 x78;
    u8 pad7C[4];
    s32 x80;
    s32 x84;
    u8 pad88[0x134 - 0x88];
} Ent;
extern s32 D_800B0100;
extern Ent *D_800B68F0;
extern void func_8008989C(void *, void *, s32);
extern void func_800885CC(Ent *);
extern s32 func_80089554(Track *, s32);

s32 func_80086854(Track *t)
{
    s32 n;
    s32 i;
    s32 stamp;
    Ent *e;
    s32 n2;

    n = t->count;
    if ((u32)t->a < 0x400) {
        func_8008989C(&t->a, t, 5);
        func_8008989C(t->a, t, n);
        func_8008989C(t->b, t, n);
        func_8008989C(t->c, t, n);
    }
    stamp = D_800B0100++;
    for (i = 0; i < n; i++) {
        if (t->a[i] != 0) {
            e = &D_800B68F0[func_80089554(t, i)];
            func_800885CC(e);
            e->owner = t;
            e->x34 = e->x84 = t->b[i];
            e->x30 = e->x80 = t->c[i];
            n2 = t->a[i];
            e->x40 = stamp;
            e->x0 = e->x78 = n2;
        }
    }
    return stamp;
}

