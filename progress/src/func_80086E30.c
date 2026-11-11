extern s32 gVoiceCount;
typedef struct VoiceEntry { u8 pad[0x40]; s32 key; u8 pad44[100]; s16 value; u8 padB2[12]; u8 flag; u8 tail[0x79]; } VoiceEntry;

/* Looks up every voice whose key equals request->key (at +4) and sets its value to
 * `value` and its flag to 0xFF. Voice entries are 0x134 bytes apart. */
void func_80086E30(void *request, s16 value) {
    s32 pad[2];
    s32 n;
    s32 i;
    VoiceEntry *base;
    VoiceEntry *p;

    n = gVoiceCount;
    base = (VoiceEntry *)(*(u8 **)0x800b68f0);
    i = 0;
    if (n > 0) {
        p = (VoiceEntry *)((u8 *)base);
        do {
            if (p->key == *(s32 *)((u8 *)request + 4)) {
                p->value = value;
                p->flag = 0xFF;
            }
            n = gVoiceCount;
            i++;
            p = (VoiceEntry *)((u8 *)p + 0x134);
        } while (i < n);
    }
}
