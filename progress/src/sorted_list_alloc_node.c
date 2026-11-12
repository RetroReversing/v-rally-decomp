void *poolAlloc(s32);
void *memset(void *, s32, s32);
s32 sorted_list_insert(void *, void *, s32);

/* Allocates a list node from the pool, zeroes its first size bytes, and inserts it into list
   in key order (see sorted_list_insert). Returns the new node. */
void *sorted_list_alloc_node(void *list, s32 size, u16 key) {
    void *node;

    node = poolAlloc(6);
    memset(node, 0, size);
    sorted_list_insert(node, list, key & 0xFFFF);
    return node;
}
