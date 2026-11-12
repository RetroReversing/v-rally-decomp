s32 streamFreeObject(void *obj);
s32 heapFreeBlock(void *block);

/* Frees the two stream objects (owner +0x20, +0x24) and the heap block (owner +0x1C)
 * held by an owner struct, clearing the stream object pointers. */
void streamFreeHandles(void *owner)
{
    streamFreeObject(*(void **)((char *)owner + 0x20));
    *(void **)((char *)owner + 0x20) = NULL;
    streamFreeObject(*(void **)((char *)owner + 0x24));
    *(void **)((char *)owner + 0x24) = NULL;
    heapFreeBlock(*(void **)((char *)owner + 0x1C));
}
