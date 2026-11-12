s32 heapFreeBlock();
extern char stream_state[];

/* Releases `block`. Looks for the 0x800-entry handle table in stream_state whose entry
 * refers to `block`. A handle with refcount 1 frees the entry and its slot, otherwise
 * the refcount is decremented. */
void stream_release_block(void *block)
{
    u8 found;
    u16 i;
    void **table;
    void *entry;
    u8 kind;

    found = 0;
    i = 0;
    table = (void **)(stream_state + 0x3902);
    do
    {
        entry = table[i];
        if (entry != NULL)
        {
            if (*(void **)((char *)entry + 4) == block)
            {
                found = 1;
            }
        }
        i++;
    } while ((found == 0) && (i < 0x800));
    if (found != 0)
    {
        kind = *(u8 *)((char *)entry + 2);
        if (kind == 1)
        {
            heapFreeBlock(entry);
            *(s32 *)(stream_state + 0x38FE + (i << 2)) = 0;
            heapFreeBlock(block);
            return;
        }
        *(u8 *)((char *)entry + 2) = kind - 1;
    }
}
