extern char *gVoices;
extern char stream_state[];

/* Marks the first voiceCount voice entries (stride 0x134 from gVoices) as active by setting two flag words to 1. */ void func_80086A94(void) {
    char unused[8];
    s32 voiceCount;
    s32 i;
    s32 on;
    char *voices;
    char *entry;

    voiceCount = *(s32 *)(stream_state + 0x757E);
    voices = gVoices;
    i = 0;
    if (voiceCount > 0) {
        on = 1;
        entry = (char *)voices + 0x18;
        do {
            i += 1;
            *(s32 *)(entry - 0xC) = on;
            *(s32 *)entry = on;
            entry += 0x134;
        } while (i < voiceCount);
    }
}
