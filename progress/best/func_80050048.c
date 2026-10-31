/* Partial candidate from function #25210 in project #57; rechecked locally. */
typedef struct { u8 pad[4]; u32 *buf; u16 flags, status, count, len; } Entry;
typedef struct { u8 pad[0x110]; u16 max, limit; u8 idx; } State;
typedef struct { u8 pad[0x0E]; u16 e; u8 pad2[0x0A]; u16 a; u8 pad3[2]; u16 b; } Event;
extern State *D_800A1234;
extern Event *D_800C35A0;
extern s32 func_8004F57C(void *);
s32 func_80050048(s32 arg0, s16 arg1) {
    State *s = D_800A1234;
    u8 i = s->idx;
    Entry *q = (Entry *)((u8 *)s + i * 0x44);
    Event *e;
    u8 j;
    u16 f;
    if (q->status != 1) {
        e = D_800C35A0;
        if (e->b == 0 && e->a != 0 && e->e == 2) {
            s->idx = i + 1;
            if (s->idx == s->max) s->idx = 0;
        }
        return 0;
    }
    if (q->flags & 8) {
        j = 0;
        e = D_800C35A0;
        if (e->b == 0 && e->a == 0) {
            {
                if (e->a < s->max) do {
                    Entry *p = (Entry *)((u8 *)s + j * 0x44);
                    p->status = 1;
                    p->flags &= ~8;
                    j++;
                } while ((u8)j < s->max);
            }
        } else {
            do {
                Entry *p = (Entry *)((u8 *)s + j * 0x44);
                f = p->flags;
                j++;
                p->status = 1;
                p->flags = f & ~8;
            } while ((u8)j < 4);
        }
    }
    if (q->count == 0 && !(q->flags & 0x200)) func_8004F57C(s);
    q->buf[q->count] = arg0;
    q->count++;
    if (q->len < q->count) q->len++;
    if (s->limit - 1 < q->count) {
        if (q->flags & 0x10) {
            e = D_800C35A0;
            if (e->b == 0) q->flags |= 0x80;
        }
        e = D_800C35A0;
        if (e->b) {
            for (j = 0; (u8)j < 4; j++) {q = (Entry *)((u8 *)s + (u8)j * 0x44); q->status = 3;}
        } else {q = (Entry *)((u8 *)s + s->idx * 0x44);q->status = 3;}
    }
    s->idx++;
    if (s->idx == s->max) s->idx = 0;
    return 1;
}
