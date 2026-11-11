typedef struct Ent {
    s32 active;
    u8 pad04[0x9A];
    u16 h9E;
    u8 padA0[0x134 - 0xA0];
} Ent;
extern s32 gVoiceCount;
extern Ent *gVoices;

/* Counts the active voices that match the flags: bit 0 selects voices with h9E set,
 * bit 1 selects voices with h9E clear. */
s32 voice_count_flagged(s32 flags)
{
    u8 pad[1];
    s32 i;
    s32 hits;
    Ent *e;

    i = 0;
    hits = 0;
    e = gVoices;
    for (; i < gVoiceCount; i++, e++) {
        if (e->active == 0) {
            continue;
        }
        if (e->h9E != 0) {
            if (flags & 1) {
                goto hit;
            }
            continue;
        } else if (!(flags & 2)) {
            continue;
        }
    hit:
        hits++;
    }
    return hits;
}
