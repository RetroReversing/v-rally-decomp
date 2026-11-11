void heapFreeBlock(s32);

/* Frees the 12 heap blocks listed in the table at obj+0x38 (block i at
 * table+0x30+i*4), skipping empty slots and a missing table. */
void func_8001A2E0(void *obj)
{
    s32 i;
    void *table;
    s32 block;

    for (i = 0; i < 12; i++) {
        table = *(void **)((char *)obj + 0x38);
        if (table != 0) {
            block = *(s32 *)((char *)table + i * 4 + 0x30);
            if (block != 0) {
                heapFreeBlock(block);
            }
        }
    }
}
