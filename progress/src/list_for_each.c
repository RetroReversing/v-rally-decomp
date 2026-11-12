/* Walks a singly linked list whose next pointer is at offset 4 and calls
   callback on each node. The list head is read from *list; nothing happens if list or *list is NULL. */
void list_for_each(void **list, s32 (*callback)(void *)) {
    void *next;
    void *node;

    if (list != NULL) {
        node = *list;
        if (node != NULL) {
            do {
                next = *(void **)((s8 *)node + 4);
                callback(node);
                node = next;
            } while (node != NULL);
        }
    }
}
