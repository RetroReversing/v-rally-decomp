void *poolAlloc();
s32 func_8000DBC0();

/* Allocates a 0x90-byte object from objPool and sets its type id. nItems (8-byte
   entries at +0x10/+0xC) and nExtra (16-byte entries at +0x70/+0x74) each get a
   block from dataPool; with nItems zero the blocks are NULL. Clears the flag fields,
   then runs func_8000DBC0 on it. Returns the object, or NULL if the pool is empty. */
void *func_80005CB8(s16 typeId, s32 nItems, s32 nExtra, s32 objPool, s32 dataPool) {
    void *obj;
    void *block;
    s32 itemBytes;

    obj = poolAlloc(objPool, 0x90);
    if (obj != NULL) {
        if (nItems != 0) {
            if (nExtra != 0) {
                nExtra *= 0x10;
                block = poolAlloc(dataPool, nExtra);
                *(void **)((char *)obj + 0x70) = block;
                block += nExtra;
                *(void **)((char *)obj + 0x74) = block;
            } else {
                *(void **)((char *)obj + 0x70) = NULL;
                *(void **)((char *)obj + 0x74) = NULL;
            }
            itemBytes = nItems * 8;
            block = poolAlloc(dataPool, itemBytes);
            *(void **)((char *)obj + 0x10) = block;
            block += itemBytes;
            *(void **)((char *)obj + 0xC) = block;
        } else {
            *(void **)((char *)obj + 0x10) = NULL;
            *(void **)((char *)obj + 0x70) = NULL;
            *(void **)((char *)obj + 0x74) = NULL;
            *(void **)((char *)obj + 0xC) = NULL;
        }
        *(s16 *)((char *)obj + 0x1C) = typeId;
        *(s16 *)((char *)obj + 4) = 0;
        *(s16 *)((char *)obj + 6) = 0;
        *(s16 *)((char *)obj + 0x7A) = 0;
        func_8000DBC0(obj);
    }
    return obj;
}
