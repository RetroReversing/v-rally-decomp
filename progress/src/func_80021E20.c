extern int D_800C6ED0;
s32 streamReleaseEntry();
s32 heapFreeBlock();
extern char gOrderState[], stream_state[];

/* Releases an object's heap blocks. Its table at +0x38 is freed with its entries; when the object is the
 * current one it also runs streamReleaseEntry on D_800C6ED0 first, and when the stream slot is below 3 it also
 * frees the sub-tables (seven 4-byte entries each with a block at +0x38 and a value at +0x1C). */
void func_80021E20(void *obj)
{
    u8 i, idx;
    void *table, *entry;
    table = **(void ***)((char *)obj + 0x38);
    if (obj == **(void ***)(gOrderState + 0x73f0))
    {
        streamReleaseEntry(D_800C6ED0);
    }
    if (*(u16 *)((char *)*(void **)(stream_state + 0x32f2) + 0xe) < 3U)
    {
        heapFreeBlock(*(void **)((char *)table + 0x10));
        i = 0;
        heapFreeBlock(*(void **)table);
        do
        {
            idx = i;
#ifdef PORT
            entry = (void *)((char *)table + idx * 4);
#else
            entry = (void *)((u32)(idx * 4) + (u32)table);
#endif
            heapFreeBlock(*(void **)((char *)entry + 0x38));
            i++;
            streamReleaseEntry(*(s32 *)((char *)entry + 0x1c));
        } while (i < 7);
    }
    heapFreeBlock(table);
}
