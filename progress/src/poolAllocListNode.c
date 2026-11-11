s32 poolAlloc(s32, s32, ...);
s32 memset(s32, s32, u32);
void listAppendNode(void *, void *);

/* Allocates a zeroed node of `size` bytes from pool 6 and appends it to the list. */
void *poolAllocListNode(void *list, s32 size) {
    void *node;
    node = (void *)poolAlloc(6, size);
    memset((s32)node, 0, (u32)size);
    listAppendNode(node, list);
    return node;
}
