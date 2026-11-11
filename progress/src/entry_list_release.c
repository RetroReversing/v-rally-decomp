s32 RebaseObjectPointers();

/* Runs RebaseObjectPointers (entry_rebase_pointers) over each entry of the list.
 * The list header holds the first entry pointer at +0 and a u16 count at +4;
 * entries are 0x24 bytes each. */
void entry_list_release(void *list)
{
    char pad[8];
    s32 i;
    s32 count;
    s32 entry;

    count = (s32)(*((u16 *)((char *)list + 4)));
    entry = *((s32 *)((char *)list + 0));
    i = 0;
    if (count > 0) {
        do {
            RebaseObjectPointers(entry);
            i += 1;
            entry += 0x24;
        } while (i < (s32)(*((u16 *)((char *)list + 4))));
    }
}
