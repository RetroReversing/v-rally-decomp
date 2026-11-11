typedef struct { s32 used; u8 pad4[0x40]; s32 prio; u8 pad48[0x28]; void *owner; s32 pad74; s32 key; u8 pad7c[0x22]; u16 active; u8 rest[0x134 - 0xA0]; } Ent;
typedef struct { s32 pad0; s32 *keys; } Owner;
extern u8 gOrderState[];
extern s32 gVoiceCount;
#define gEnts (*(Ent **)(gOrderState + 0x80A0))

/* Picks the entry to use for owner's key slot `index`: the first unused entry, else the
 * active entry with the lowest priority, else an idle entry owned by someone else, else
 * the entry this owner used for that key before, else a fixed slot by index. */
s32 voice_pick_slot(Owner *owner, s32 index)
{
    u8 scratch[1];
    Ent *e;
    s32 i;
    s32 best;
    s32 bestPrio;

    e = gEnts;
    for (i = 0; i < gVoiceCount; i++, e++) {
        if (e->used == 0) return i;
    }
    e = gEnts;
    bestPrio = 0x7FFFFFFF;
    best = -1;
    for (i = 0; i < gVoiceCount; i++, e++) {
        if (e->active != 0 && e->prio <= bestPrio) {
            bestPrio = e->prio;
            best = i;
        }
    }
    if (best != -1) return best;
    e = gEnts;
    for (i = 0; i < gVoiceCount; i++) {
        if (e->active == 0 && e->owner != owner) return i;
    }
    e = gEnts;
    for (i = 0; i < gVoiceCount; i++, e++) {
        if (e->owner == owner && owner->keys[index] == e->key) return i;
    }
    return index % gVoiceCount;
}
