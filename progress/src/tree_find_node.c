s32 str_icmp_eq();

/* Depth-first search for the node whose name matches `name`, starting at `node`. The node's child count is at +0x10 and its children are read from the array at +0x14, last child first. Returns the matching node, or NULL. */
void *tree_find_node(void *node, s32 name) {
    u32 off;
    s32 count;
    s32 *child;
    void *found;

    if (str_icmp_eq(name, node) != 0) {
        return node;
    }
    count = *(s32 *)((char *)node + 0x10);
    if (count > 0) {
        off = count << 2;
        child = (s32 *)(off + (u32)node);
        do {
            found = tree_find_node((void *)child[5], name);
            if (found != NULL) {
                return found;
            }
            count--;
            child--;
        } while (count > 0);
    }
    return NULL;
}
