s32 poolAlloc(s32);
s32 listAppendNode(s32, s32);
void *memset(void *, s32, s32);

/* Allocates one pool block of arg1 bytes, zeroes it, passes it to listAppendNode with arg0,
 * and returns it. */
s32 poolAllocNode(s32 arg0, s32 arg1) {
    s32 node;

    node = poolAlloc(1);
    memset(node, 0, arg1);
    listAppendNode(node, arg0);
    return node;
}
