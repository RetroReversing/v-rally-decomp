typedef struct { s32 used; u8 pad4[0x40]; s32 prio; u8 pad48[0x28]; void *owner; s32 pad74; s32 key; u8 pad7c[0x22]; u16 active; u8 rest[0x134 - 0xA0]; } Ent;
typedef struct { s32 pad0; s32 *keys; } Owner;
extern u8 D_800AE850[];
extern s32 D_800C782C;
#define gEnts (*(Ent **)(D_800AE850 + 0x80A0))
s32 func_80089554(Owner *arg0, s32 arg1)
{
    u8 scratch[1];
    Ent *e;
    s32 i;
    s32 best;
    s32 bestv;

    e = gEnts;
    for (i = 0; i < D_800C782C; i++, e++) {
        if (e->used == 0) return i;
    }
    e = gEnts;
    bestv = 0x7FFFFFFF;
    best = -1;
    for (i = 0; i < D_800C782C; i++, e++) {
        if (e->active != 0 && e->prio <= bestv) {
            bestv = e->prio;
            best = i;
        }
    }
    if (best != -1) return best;
    e = gEnts;
    for (i = 0; i < D_800C782C; i++) {
        if (e->active == 0 && e->owner != arg0) return i;
    }
    e = gEnts;
    for (i = 0; i < D_800C782C; i++, e++) {
        if (e->owner == arg0 && arg0->keys[arg1] == e->key) return i;
    }
    return arg1 % D_800C782C;
}
