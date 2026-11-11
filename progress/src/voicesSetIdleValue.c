extern s32 gVoiceCount;
extern char *gVoices;

/* Sets the first s16 of every voice whose pointer at +8 is NULL (idle) to value. Voices are 0x134 bytes apart, starting at gVoices+0x96. */
void voicesSetIdleValue(s16 value) {
    char pad[8];
    s32 i;
    s32 count;
    void *voice;
    s32 limit;

    count = gVoiceCount;
    voice = gVoices;
    i = 0;
    if (count > 0) {
        limit = count;
        voice = (char *)voice + 0x96;
        do {
            if (*(u16 *)((char *)voice + 8) == 0) {
                *(s16 *)((char *)voice + 0) = value;
            }
            i++;
            voice = (char *)voice + 0x134;
        } while (i < limit);
    }
}
