s32 heapFreeBlock();

/* Frees an object and the two heap blocks it owns (at +0x10 and +0x70), clearing their
 * pointers first. Returns the result of freeing the object itself, or 0 for NULL. */
s32 streamFreeObject(void *obj)
{
    void *blockA;
    void *blockB;
    void *cur;
    void *objPtr;

    cur = obj;
    objPtr = cur;
    if (cur != NULL) {
        blockA = *(void **)((char *)cur + 0x10);
        if (blockA != NULL) {
            heapFreeBlock(blockA);
            *(void **)((char *)cur + 0x10) = NULL;
        }
        blockB = *(void **)((char *)cur + 0x70);
        if (blockB != NULL) {
            heapFreeBlock(blockB);
            *(void **)((char *)cur + 0x70) = NULL;
        }
        return heapFreeBlock(objPtr);
    }
    return 0;
}
