extern char gStreamState[];

/* Walks the entry list at gStreamState->0x5A7A->+0x10 and clears flag bit 0x2 (at +0xC)
 * on the entry at index slot. Stops at the first match. */
void select_clear_entry_flag2(s32 slot)
{
    s32 index;
    void *head;
    char *entry;

    head = *(void **)(gStreamState + 0x5A7A);
    head = *(void **)((char *)head + 0x10);
    entry = *(char **)head;
    index = 0;
    if (entry != NULL) {
        slot = slot & 0xFF;
        do {
            if ((index & 0xFF) == slot) {
                *(s32 *)(entry + 0xC) &= -3;
                return;
            }
            entry = *(char **)(entry + 4);
            index++;
        } while (entry != NULL);
    }
}
