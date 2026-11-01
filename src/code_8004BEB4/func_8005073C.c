#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Blk40 { s32 w[10]; } Blk40;
typedef struct Slot { s32 a; s32 b; u16 flags; u16 state; u16 c; u16 d; s32 asz; s32 bsz; s32 x18; Blk40 blk; } Slot;
typedef struct Bank { Slot slots[4]; u16 count; } Bank;
typedef struct Sub { char pad0[0x6C]; s32 f6C; } Sub;
typedef struct Car { char pad0[4]; struct Car *next; char pad8[0x14 - 8]; s32 flags; char pad18[0x30 - 0x18]; Sub *p30; char pad34[0x48 - 0x34]; u8 *info; char pad4C[0x5C - 0x4C]; Sub *p5C; } Car;
typedef struct Cfg { char pad0[0xE]; u16 mode; char pad10[0x1A - 0x10]; u16 f1A; char pad1C[2]; u16 f1E; } Cfg;
typedef struct Pad { u16 btn; char pad2[4]; s16 v6; char pad8[0x44 - 8]; } Pad;

extern void func_8004F3C4(void);
extern void func_8008E13C(s32, s32, s32);
extern Bank *D_800A1234;
extern Bank *D_800A1238;
extern u8 D_800ADFE1;
extern Pad D_800B0C60[2];
#define D_800B1060 D_800B0C60
extern Car **D_800B5C40;
extern Cfg *D_800C35A0;

void func_8005073C(Car *car) {
    u8 me;
    Bank *dst;
    Bank *src;
    Slot *d;
    Slot *s;
    s32 ok;
    u32 i;
    Car *c;

    func_8004F3C4();
    if (D_800C35A0->f1E == 0) {
        me = car->info[3];
        if (D_800C35A0->f1A == 1) {
            dst = D_800A1238;
            src = D_800A1234;
            d = &dst->slots[me];
            s = &src->slots[me];
            if (d->flags & 0x10) {
                ok = d->state != 5;
            } else {
                ok = 1;
            }
            if ((d->flags & 0x80) && (s->flags & 0x80)) {
                d->flags &= ~0x80;
                ok = 0;
                s->flags &= ~0x100;
            }
            ok &= -!(s->flags & 2);
            if (ok && (s->d < d->d || d->d == 0)) {
                for (i = 0; i < src->count; i++) {
                    d = &dst->slots[i];
                    d->flags = 0;
                    d->state = 0;
                    d->c = 0;
                    d->d = s->d;
                    func_8008E13C(d->a, s->a, (s->asz + 3) & ~3);
                    func_8008E13C(d->b, s->b, (s->bsz + 3) & ~3);
                    if (i != me) {
                        c = *D_800B5C40;
                        if (D_800C35A0->mode == 2) {
                            if (i == 1) {
                                c = c->next;
                                c = c->next;
                            }
                            c = c->next;
                            c->p5C->f6C = 0;
                            c->p30->f6C = 0;
                        }
                        d->c = d->d;
                    }
                    d->blk = s->blk;
                    d->x18 = s->x18;
                    d->flags = (d->flags | 0x211) & ~0x400;
                }
                car->flags |= 0x4000;
            } else {
                d->flags = (d->flags | 0x201) & ~0x400;
                car->flags &= ~0x4000;
                d->c = 0;
            }
            if (D_800ADFE1 != 0) {
                d = &dst->slots[me];
                d->state = 4;
                car->p5C->f6C = 1;
                car->p30->f6C = 1;
                s = &src->slots[me];
                s->state = 1;
                s->c = 0;
                s->d = 0;
                s->flags = (s->flags | 0x400) & ~0x200;
            } else {
                d = &dst->slots[me];
                d->state = 3;
                car->p5C->f6C = 0;
                car->p30->f6C = 0;
                s = &src->slots[me];
                s->state = 3;
                s->c = 0;
                s->d = 0;
                s->flags |= 0x600;
            }
            return;
        }
        if ((D_800B1060[0].btn & 2) || (D_800B1060[1].btn & 2)) {
            D_800B1060[0].v6 = 0;
            D_800B1060[1].v6 = 0;
        }
    }
}

