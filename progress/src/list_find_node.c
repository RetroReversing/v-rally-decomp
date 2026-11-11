void func_8001B730(u8 *a0);
s32 strCmp(const u8 *a0, const u8 *a1);
u8 *strCpy(u8 *dst, u8 *src);

/* Finds the entry in a linked list whose name (at +0xC) matches the given name,
 * comparing case-insensitively: the key is uppercased before the comparison. */
void *list_find_node(void **head, u8 *name) {
    s32 key[4];
    void *node;

    strCpy((u8 *)key, name);
    func_8001B730((u8 *)key);
    node = *head;
    if (node != NULL) {
        do {
            if (strCmp(*(void **)((u8 *)node + 0xC), (const u8 *)key) == 0) {
                return node;
            }
            node = *(void **)((u8 *)node + 4);
        } while (node != NULL);
    }
    return NULL;
}
