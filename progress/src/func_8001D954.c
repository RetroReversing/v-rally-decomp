extern char stream_state[];

/* Copies field +0x44 of entries 1..10 (0x4C bytes apart, starting at base + 0x4C) into the 16-bit table at stream_state + 0x10370. */
void func_8001D954(char *base)
{
    char *table;
    s32 value;
    s32 i;
    char *entry;

    i = 1;
    table = stream_state + 0x10370;
    entry = base + 0x4C;
    do {
        value = *((s32 *) (entry + 0x44));
        entry += 0x4C;
        i += 1;
        *(s16 *)table = (s16) value;
        table += 2;
    } while (i < 0xB);
}
