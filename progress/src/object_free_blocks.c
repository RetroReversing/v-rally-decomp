s32 heapFreeBlock(void *block);
s32 heap_free_stub(s32 block);

/* Frees the two sub-blocks owned by an object (at +4 and +0), then the object block itself. */
void object_free_blocks(void *obj)
{
    heapFreeBlock(*(void **)((s8 *)obj + 4));
    heap_free_stub(*(s32 *)((s8 *)obj + 0));
    heapFreeBlock(obj);
}
