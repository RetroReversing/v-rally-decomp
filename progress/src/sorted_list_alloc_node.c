/* Allocates a list node from the pool, zeroes its first size bytes, and inserts it into list
   in key order (see sorted_list_insert). Returns the new node. */
s32 sorted_list_alloc_node(s32 list, s32 size, u16 key) {
    s32 node;

    node = poolAlloc(6);
    memset(node, 0, size);
    sorted_list_insert(node, list, key & 0xFFFF);
    return node;
}
