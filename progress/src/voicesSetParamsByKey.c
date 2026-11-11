extern s32 gVoiceCount;
extern char *gVoices;

/* Sets the two parameter words of every voice whose key at +0x28 equals arg0->key (arg0 + 4). */
void voicesSetParamsByKey(void *arg0, s32 arg1) {
    s32 saved = arg1;
    s32 value = arg1;
    s32 i;
    s32 count;
    char pad[8];
    volatile s32 *p;
    s32 *base;
    s32 field;
    if (!value) value = 1;
    count = gVoiceCount;
    base = (s32 *)gVoices;
    i = 0;
    if (count > 0) {
        s32 limit = count;
        p = (volatile s32 *)((u8 *)base + 0x18);
        do {
            field = p[10];
            i++;
            if (field == *(s32 *)((u8 *)arg0 + 4)) {
                p[-3] = saved;
                p[0] = value;
            }
            p = (volatile s32 *)((u8 *)p + 0x134);
        } while (i < limit);
    }
    (void)&pad;
}
