void *streamSetCurrent(void *);
void streamProcessNode(void *);
extern s32 gOrderState;
extern s32 stream_state;

/* Walks the list hanging off gOrderState+0x72FC: each node becomes the current stream
 * node and is processed in turn. */
void streamProcessList(void) {
    void *node;

    node = streamSetCurrent(*(void **)(*(void ***)((u8 *)&gOrderState + 0x72FC)));
    if (node != NULL) {
        do {
            *(void **)((u8 *)&stream_state + 0x7CD6) = node;
            streamProcessNode(node);
            node = *(void **)((u8 *)node + 4);
            if (node != NULL) {
                streamSetCurrent(node);
            }
        } while (node != NULL);
    }
}
