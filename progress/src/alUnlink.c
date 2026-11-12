/* Removes a node from an intrusive doubly linked list: next at +0, prev at +4. */
void alUnlink(void *node) {
    void **prev;
    void *next;

    next = *(void **)node;
    if (next != NULL) {
        *(void ***)((u8 *)next + 4) = *(void ***)((u8 *)node + 4);
    }
    prev = *(void ***)((u8 *)node + 4);
    if (prev != NULL) {
        *prev = *(void **)node;
    }
}
