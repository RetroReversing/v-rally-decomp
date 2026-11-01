typedef struct Trk {
    u8 pad00[0x30];
    s32 x30;
    s32 x34;
    u8 pad38[0x6C - 0x38];
    f32 f6C;
    u8 pad70[0x78 - 0x70];
    s32 x78;
    u8 pad7C[4];
    s32 x80;
    s32 x84;
    u8 pad88[0x9A - 0x88];
    u16 h9A;
    u16 h9C;
    u8 pad9E[0xB4 - 0x9E];
    u8 bB4;
    u8 padB5[0xD3 - 0xB5];
    u8 depth;
    u8 *ret[5];
    s32 e8[5];
    s32 fc[5];
    u16 h110[5];
    u16 h11A[5];
    u8 b124[5];
    u8 b129[5];
    u8 b12E[5];
} Trk;

u8 *func_80087DE4(Trk *t, u8 *p)
{
    s32 idx = t->depth;

    t->b124[idx] = *p++;
    t->ret[idx] = p;
    t->e8[idx] = t->x34;
    t->fc[idx] = t->x30;
    t->b129[idx] = t->bB4;
    t->b12E[idx] = t->f6C;
    t->h110[idx] = t->h9A;
    t->h11A[idx] = t->h9C;
    t->depth++;
    return p;
}

typedef struct Ent {
    s32 active;
    u8 pad04[0x9A];
    u16 h9E;
    u8 padA0[0x134 - 0xA0];
} Ent;
extern s32 D_800C782C;
extern Ent *D_800B68F0;

s32 func_800869B8(s32 arg0)
{
    s32 i;
    s32 hits;
    Ent *e;

    i = 0;
    hits = 0;
    e = D_800B68F0;
    for (i = 0; i < D_800C782C; i++, e++) {
        if (e->active != 0) {
            if (e->h9E != 0) {
                if (arg0 & 1) {
                    hits++;
                }
            } else {
                if (arg0 & 2) {
                    hits++;
                }
            }
        }
    }
    return hits;
}

extern s32 D_800A19B0;
extern s32 D_800B5B40;
extern s32 *D_800C5BB0[];
extern void (*D_800C8090)(s32);
extern void (*D_800C80A8)(s32);

s32 func_8007EE9C(void *arg0)
{
    s32 result = 0;

    if (D_800A19B0 == 1) {
        D_800C80A8(D_800B5B40 - 4);
    }
    D_800A19B0 = 1;
    D_800B5B40 = (s32)__builtin_return_address(0);
    if (arg0 != 0) {
        result = ((s32 (*)(void *))D_800C5BB0[*(s32 *)((u8 *)arg0 - 8)][1])(arg0);
    } else {
        D_800C8090(D_800B5B40 - 4);
    }
    D_800A19B0 = 0;
    return result;
}

s32 func_80088008(Trk *t, u8 *p)
{
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    a = *p++;
    b = *p++;
    c = *p++;
    d = *p++;
    t->h9A = 1;
    t->x34 = t->x84 + ((c << 8) + d);
    t->h9C = 1;
    t->x30 = t->x80 + ((p[0] << 8) + p[1]);
    return t->x78 + ((a << 8) + b);
}
