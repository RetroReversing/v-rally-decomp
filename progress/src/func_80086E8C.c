extern s32 gVoiceCount;
extern char gOrderState[];

/* Sets the float at +0x2C of every voice entry whose +0x14 word equals the word at +4 of
 * obj to value. Entries are 0x134 bytes apart in the table that gOrderState points to at +0x80A0.
 * The loop stops after the first match. */
void func_80086E8C(void *obj, f32 value)
{
    s32 pad[2];
    s32 count;
    s32 i;
    u8 *voices;
    u8 *entry;

    voices = *(u8 **)(gOrderState + 0x80A0);
    i = 0;
    count = gVoiceCount;
    if (count > 0) {
        entry = voices + 0x2C;
        do {
            if (*(s32 *)(entry + 0x14) == *(s32 *)((u8 *)obj + 4)) {
                *(f32 *)entry = value;
                i = count;
            }
            i++;
            entry += 0x134;
            count = gVoiceCount;
        } while (i < count);
    }
}
