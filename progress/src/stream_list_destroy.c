s32 streamReleaseEntry(s32);
s32 list_unlink_free(void *, void **);
s32 heapReleaseBlock(void **);

/* Tears down a node list: releases each node's entry at +0xC, unlinks and
 * frees the node, then frees the list head itself. Does nothing for NULL. */
void stream_list_destroy(void **list) {
    void *node;
    void *next;

    if (list != NULL) {
        next = *list;
        if (next != NULL) {
            do {
                streamReleaseEntry(*(s32 *)((char *)next + 0xC));
                node = next;
                next = *(void **)((char *)next + 4);
                list_unlink_free(node, list);
            } while (next != NULL);
        }
        heapReleaseBlock(list);
    }
}
