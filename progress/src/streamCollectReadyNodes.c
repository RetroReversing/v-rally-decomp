extern char stream_state[];

/* Walks the node list at *listHead (next pointer at +4) and appends each node whose state at +0x5C+0x6C is 1 to the ready array in stream_state. */
void streamCollectReadyNodes(void **listHead) {
    void **temp_v0;
    void *node;

    node = *listHead;
    if (node != NULL) {
        do {
            if (*(s32 *)((char *)*(void * *)((char *)node + 0x5C) + 0x6C) == 1) {
                temp_v0 = (*(u16 *)(stream_state + 0x5A4A) * 4) + (stream_state + 0x5A4A + 4);
                *(u16 *)(stream_state + 0x5A4A) = (u16) (*(u16 *)(stream_state + 0x5A4A) + 1);
                *temp_v0 = node;
            }
            node = *(void * *)((char *)node + 4);
        } while (node != NULL);
    }
}
