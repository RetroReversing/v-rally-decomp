#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 pad[4]; u32 *buf; u16 flags, status, count, len; } Entry;
typedef struct { u8 pad[0x110]; u16 max, limit; u8 idx; } State;
typedef struct { u8 pad[0x0E]; u16 e; u8 pad2[0x0A]; u16 a; u8 pad3[2]; u16 b; } Event;
extern State *D_800A1234;
extern char D_800C02AE[];
extern void func_8004F57C(void *);
#define EV (*(Event **)(D_800C02AE + 0x32F2))
#define ENT(s, n) ((Entry *)((u8 *)(s) + (n) * 0x44))
s32 func_80050048(s32 arg0) {
char *__repair_addr;

    State *s = D_800A1234;
    u8 i = s->idx;
    Entry *q = ENT(s, i);
    u8 j;
    if (q->status != 1) {
        if (EV->b == 0 && EV->a != 0 && EV->e == 2) {
            s->idx = i + 1;
            if (s->idx == s->max) s->idx = 0;
        }
        return 0;
    }
    if (q->flags & 8) {
        if (EV->b == 0 && EV->a == 0) {
            for (j = 0; j < s->max; j++) {
                Entry *p = ENT(s, j);
                p->status = 1;
                p->flags &= ~8;
            }
        } else {
            for (j = 0; j < 4; j++) {
                Entry *p = ENT(s, j);
                p->status = 1;
                p->flags &= ~8;
            }
        }
    }
    if (q->count == 0 && !(q->flags & 0x200)) func_8004F57C(s);
    { u32 *b = q->buf; u16 c = q->count;
__repair_addr = (char *)((u8 *)b + c * 4);
 *(u32 *)(__repair_addr) = arg0; } q->count++;
    if (q->len < q->count) q->len++;
    if (s->limit - 1 < q->count) {
        if (q->flags & 0x10) {
            if (EV->b == 0) q->flags |= 0x80;
        }
        if (EV->b) {
            for (j = 0; j < 4; j++) { q = ENT(s, j); q->status = 3; }
        } else {
            q = ENT(s, s->idx);
            q->status = 3;
        }
    }
    s->idx++;
    if (s->idx == s->max) s->idx = 0;
    return 1;
}
