extern s32 gVoiceCount;
extern char *gVoices;

/* Sets the volume (at +0x96 of each 0x134-byte voice record) of every voice whose
 * key at +0x40 matches the id stored at +4 of `src`. */
void voiceSetVolumeByKey(void *src, s16 volume) {
    char scratch[8]; /* unused; keeps the frame layout */
    char *base;
    char *p;
    s32 i;
    s32 n;

    n = gVoiceCount;
    base = gVoices;
    i = 0;
    if (n > 0) {
        p = base + 0x96;
        do {
            if (*(s32 *)(p - 0x56) == *(s32 *)((char *)src + 4)) {
                *(s16 *)p = volume;
                i = n;
            }
            i++;
            p += 0x134;
            n = gVoiceCount;
        } while (i < n);
    }
}
