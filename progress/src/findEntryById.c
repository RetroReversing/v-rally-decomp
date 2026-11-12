extern char stream_state[];

/* Linear search of the 0x3C-byte entry table (count at +4, entries at +0) for the entry
 * whose id at +0x24 equals id. Returns the entry, or NULL. */
void *findEntryById(s32 id)
{
    char pad[8];
    char *table;
    char *entry;
    u16 temp_v0;
    u32 count;
    u32 i;
    void *result;

    table = *(char **)(stream_state + 0x7CDE);
    temp_v0 = *(u16 *)(table + 4);
    i = 0;
    result = NULL;
    if (temp_v0 != 0) {
        count = temp_v0;
        entry = *(char **)table;
        do {
            if (*(s32 *)(entry + 0x24) == id) {
                result = entry;
                goto done;
            }
            i++;
            entry += 0x3C;
        } while (i < count);
    }
done:
    return result;
}
