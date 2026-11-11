s32 alLink();
s32 alUnlink();

/* Picks a voice for a new note from the pool at `pool`. A free voice from the list at +0x14,
 * or else the list at +0x4, is moved onto the active list at +0xC and returned in *voiceOut.
 * If both are empty, scans the active list for an idle voice (+0xD8 == 0) whose wave priority
 * (+0x16 of its wave at +8) is no greater than `prio` and returns the one with the lowest
 * priority. Returns 1 when a voice was picked from the active list, 0 otherwise. */
s32 _allocatePVoice(u8 *pool, void **voiceOut, s16 prio)
{
    s32 found = 0;
    void *voice;

    voice = *(void **)(pool + 0x14);
    if (voice == NULL) {
        voice = *(void **)(pool + 0x4);
    }
    if (voice != NULL) {
        *voiceOut = voice;
        alUnlink(voice);
        alLink(voice, pool + 0xC);
    } else {
        voice = *(void **)(pool + 0xC);
        while (voice != NULL) {
            if (prio >= *(s16 *)(*(u8 **)((u8 *)voice + 8) + 0x16) && *(s32 *)((u8 *)voice + 0xD8) == 0) {
                *voiceOut = voice;
                found = 1;
                prio = *(u16 *)(*(u8 **)((u8 *)voice + 8) + 0x16);
            }
            voice = *(void **)voice;
        }
    }
    return found;
}
