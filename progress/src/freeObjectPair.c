s32 heapFreeBlock(void *);

typedef struct { s32 pad[3]; void *child; } ObjPair;

/* Frees an object's child block (stored at offset 12), if any, then frees the object block itself. */
s32 freeObjectPair(ObjPair *obj) {
    s32 *objWords;
    void *childBlock;
    objWords = (s32 *)obj;
#ifdef PORT
    childBlock = obj->child;
#else
    childBlock = (void *)objWords[3];
#endif
    if (childBlock) {
        heapFreeBlock(childBlock);
        return heapFreeBlock(objWords);
    }
    return 0;
}
