typedef struct Track {
    s32 count;
    s32 *level;
    s32 *pan;
    s32 *rate;
} Track;
typedef struct Voice {
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
} Voice;
extern s32 D_800B0100;
extern Voice *gVoices;
extern void fix_up_offsets(void *, void *, s32);
extern void voice_reset(Voice *);
extern s32 voice_pick_slot(Track *, s32);

/* Starts a track: on first use, turns its stored offsets into pointers, then claims
   a voice for each entry with a nonzero level and copies its pan and rate into it.
   Returns this start's stamp, a serial number bumped on every call. */
s32 start_track_voices(Track *track)
{
    s32 count;
    s32 i;
    s32 stamp;
    Voice *voice;
    s32 level;

    count = track->count;
    if ((u32)track->level < 0x400) {
        fix_up_offsets(&track->level, track, 5);
        fix_up_offsets(track->level, track, count);
        fix_up_offsets(track->pan, track, count);
        fix_up_offsets(track->rate, track, count);
    }
    stamp = D_800B0100++;
    for (i = 0; i < count; i++) {
        if (track->level[i] != 0) {
            voice = &gVoices[voice_pick_slot(track, i)];
            voice_reset(voice);
            voice->owner = track;
            voice->x34 = voice->x84 = track->pan[i];
            voice->x30 = voice->x80 = track->rate[i];
            level = track->level[i];
            voice->x40 = stamp;
            voice->x0 = voice->x78 = level;
        }
    }
    return stamp;
}
