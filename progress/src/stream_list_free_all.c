s32 list_unlink_free(void *, void **);
extern char stream_state[];

/* The stream list header is at stream_state+0x5A7E; its pool pointer is at +0x10.
 * The list is walked from the head (pool[0]) through each node's +4 link, and
 * every node is handed to list_unlink_free. The pool pointer is re-read each
 * time, because list_unlink_free may change it. */
#define STREAM_POOL (*(void ***)((char *)*(void **)(stream_state + 0x5A7E) + 0x10))

void stream_list_free_all(void)
{
    void *node;
    void *next;

    next = *STREAM_POOL;
    if (next != NULL) {
        do {
            node = next;
            next = *(void **)((char *)node + 4);
            list_unlink_free(node, STREAM_POOL);
        } while (next != NULL);
    }
}
