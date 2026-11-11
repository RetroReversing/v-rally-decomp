/* Calls cb(node, arg) for each node of the list whose head is *list; nodes link through +4. */
void func_80080514(void **list, s32 (*cb)(void *, s32), s32 arg) {
    void *next;
    void *node;

    if (list != NULL) {
        node = *list;
        if (node != NULL) {
            do {
                next = *(void **)((s8 *)node + 4);
                cb(node, arg);
                node = next;
            } while (node != NULL);
        }
    }
}
