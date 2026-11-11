s32 streamFreeObject(s32);
s32 heapFreeBlock(void *);
typedef struct { u8 pad00[0x1C]; void *block; s32 streamA; s32 streamB; } VRStreamObj;

/* Frees the two stream objects and the data block of a stream object, then the object itself. Returns 1. */
s32 streamObjDestroy(void *arg0) {
    void *temp_a0;
    VRStreamObj *obj;

    obj = (VRStreamObj *)arg0;
    streamFreeObject(obj->streamA);
    obj->streamA = 0;
    streamFreeObject(obj->streamB);
    temp_a0 = obj->block;
    obj->streamB = 0;
    if (temp_a0 != NULL) {
        heapFreeBlock(temp_a0);
    }
    heapFreeBlock(arg0);
    return 1;
}
