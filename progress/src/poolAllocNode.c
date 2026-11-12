void *poolAlloc(s32);
s32 listAppendNode(void *, s32);
void *memset(void *, s32, s32);

/* Allocates one pool block of arg1 bytes, zeroes it, passes it to listAppendNode with arg0,
 * and returns it. */
void *poolAllocNode(s32 arg0, s32 arg1) {
    void *node;

    node = poolAlloc(1);
    memset(node, 0, arg1);
    listAppendNode(node, arg0);
    return node;
}
