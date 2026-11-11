typedef struct StreamEntry { u8 pad00[0x10]; s32 block; } StreamEntry;
typedef struct StreamTable { StreamEntry *entries; u16 count; } StreamTable;

s32 streamReleaseEntry();

/* Releases the stream block of every entry in the table at +0x24 of owner->slot,
 * and returns the table's address. */
void *streamReleaseEntries(void *owner) {
    void *slot;
    StreamTable *table;
    StreamEntry *entry;
    s32 i;
    s32 block;

    slot = *(void **)((u8 *)owner + 8);
    i = 0;
    block = 0;
    entry = *(StreamEntry **)((u8 *)slot + 0x24);
    table = (StreamTable *)((u8 *)slot + 0x24);
    if ((s32)table->count > block) {
        do {
            block = entry->block;
            entry = (StreamEntry *)((u8 *)entry + 0x14);
            streamReleaseEntry(block);
            i += 1;
        } while (i < (s32)table->count);
    }
    return table;
}
