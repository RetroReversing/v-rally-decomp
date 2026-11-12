s32 heapReleaseStub(void **);
s32 streamReleaseEntry(s32);

/* Releases every entry in the list headed by *list (each entry's id is at +0xA4, the next
 * link at +4), then frees the list header itself. */
void func_80040718(void **list) {
    void *node;

    node = *list;
    if (node != NULL) {
        do {
            streamReleaseEntry(*(s32 *)((char *)node + 0xA4));
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
    heapReleaseStub(list);
}
