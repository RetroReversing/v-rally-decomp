extern char *gVoices;
extern char stream_state[];

/* Marks the first voice_count voice entries (stride 0x134 from gVoices) as active by setting two flag words to 1. */ /* Marks the first voiceCount voice entries (stride 0x134 from gVoices) as active by setting two flag words to 1. */ void func_80086A94(void) {
    char pad[8];
    s32 voice_count;
    s32 i;
    s32 flag_on;
    char *voice_base;
    char *voice;

    voice_count = *(s32 *)(stream_state + 0x757E);
    voice_base = gVoices;
    i = 0;
    if (voice_count > 0) {
        flag_on = 1;
        voice = (char *)voice_base + 0x18;
        do {
            i += 1;
            *(s32 *)(voice - 0xC) = flag_on;
            *(s32 *)voice = flag_on;
            voice += 0x134;
        } while (i < voice_count);
    }
}
