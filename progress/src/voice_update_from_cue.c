s32 func_8003A594();
extern char stream_state[];

/* Updates a voice's flag word (+0x80) from the current cue: a cue with 0x300
   in its flags sets bit 4 (stop), a cue with 0x200 clears it, and any other
   cue passes its state to func_8003A594. */
void voice_update_from_cue(void *voice)
{
    s32 cue_flags;
    s32 flags;
    void *cue;

    cue = *(void **)(*(void **)(stream_state + 0x7CD6) + 0x24);
    if (cue == NULL) {
        return;
    }
    cue_flags = *(s32 *)((u8 *)cue + 0x14);
    if (cue_flags & 0x300) {
        flags = *(s32 *)((u8 *)voice + 0x80) | 4;
    } else if (cue_flags & 0x200) {
#ifdef PORT
        flags = *(s32 *)((u8 *)voice + 0x80) & -5;
#else
        cue = (void *) -5;
        flags = *(s32 *)((u8 *)voice + 0x80) & (s32) cue;
#endif
    } else {
        func_8003A594(voice, *(s16 *)(*(u8 **)((u8 *)cue + 0x6C) + 0x12), 0);
        return;
    }
    *(s32 *)((u8 *)voice + 0x80) = flags;
}
