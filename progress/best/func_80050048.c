typedef struct { u8 pad[4]; u32 *buf; u16 flags, status, count, len; } Entry;
typedef struct { u8 pad[0x110]; u16 max, limit; u8 idx; } State;
typedef struct { u8 pad[0x0E]; u16 e; u8 pad2[0x0A]; u16 a; u8 pad3[2]; u16 b; } Event;
extern State *D_800A1234;
extern char D_800C02AE[];
extern void func_8004F57C(void *);
#define EV (*(Event **)(D_800C02AE + 0x32F2))
#define ENT(s, n) ((Entry *)((u8 *)(s) + (n) * 0x44))
s32 func_80050048(s32 arg0) {
    State *s = D_800A1234;
    Entry *q = ENT(s, s->idx);
    u8 j;
    if (q->status != 1) {
        if (EV->b == 0 && EV->a != 0 && EV->e == 2) {
            s->idx++;
            if (s->idx == s->max) s->idx = 0;
        }
        return 0;
    }
    if (q->flags & 8) {
        j = 0;
        if (EV->b == 0 && EV->a == 0) {
            if (EV->a < s->max) do {
                Entry *p = ENT(s, j);
                p->status = 1;
                p->flags &= ~8;
                j++;
            } while (j < s->max);
        } else {
            do {
                Entry *p = ENT(s, j);
                p->status = 1;
                p->flags &= ~8;
                j++;
            } while (j < 4);
        }
    }
    if (q->count == 0 && !(q->flags & 0x200)) func_8004F57C(s);
    q->buf[q->count] = arg0;
    q->count++;
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
