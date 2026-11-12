void stream_obj_free(void *obj);
void heapReleaseStub(void **);

/* Frees every stream object in the list at *list (each node's object is at +0x40,
 * the next node at +4), then runs the follow-up stub with the list head. */
void stream_list_free(void **list) {
    void *node;

    node = *list;
    if (node != NULL) {
        do {
            stream_obj_free(*(void **)((u8 *)node + 0x40));
            node = *(void **)((u8 *)node + 4);
        } while (node != NULL);
    }
    heapReleaseStub(list);
}
