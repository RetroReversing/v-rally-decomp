extern s32 gVoices;
extern char gStreamState[];

void func_80086A94(void) {
    char pad[8];
    s32 count;
    s32 i;
    s32 value;
    s32 base;
    char *p;

    count = *(s32 *)(gStreamState + 0x757E);
    base = gVoices;
    i = 0;
    if (count > 0) {
        value = 1;
        p = (char *)base + 0x18;
        do {
            i += 1;
            *(s32 *)(p - 0xC) = value;
            *(s32 *)p = value;
            p += 0x134;
        } while (i < count);
    }
}
