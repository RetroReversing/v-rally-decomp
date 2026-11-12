extern char gEntryHandlers[];
extern char gOrderState[];
extern char stream_state[];
s32 heapFreeBlock();
void heap_free_stub();

/* Runs the handler for each entry in the list at obj (count at +0x20, 8-byte entries from +0x24).
 * Each entry's type indexes gEntryHandlers. The list's last result is checked, then the block is freed. */
void runEntryList(s32 arg0, char *obj, s32 arg2)
{
    s32 pad[2];
    char *entry;
    u32 i;
    char *result;
    char *list;
    u32 count;

    list = obj;
    entry = list + 0x24;
    count = *(u32 *)(obj + 0x20);
    i = 0;
    result = NULL;
    *(char **)(gOrderState + 0x6E9C) = obj;
    *(char **)(stream_state + 0x7CD2) = obj;
    if (count != 0)
    {
        do
        {
            result = ((char *(*)(void *, s32, s32)) * (void **)(gEntryHandlers + (*(u16 *)(entry + 6) << 2)))(entry, arg0, arg2);
            entry += 8;
            i++;
        } while (i < *(u32 *)(list + 0x20));
    }
    if (*(u16 *)(result + 0x2C) == 1)
    {
        heap_free_stub(obj);
    }
    heapFreeBlock(*(void **)(gOrderState + 0x1210));
}
