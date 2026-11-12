extern u8 stream_state[];
void streamReleaseEntry(s32);
void list_unlink_free(void *, void *);

/* Frees every node on the list owned by stream slot (slot & 0xFF): releases the
 * node's block through streamReleaseEntry, unlinks it and frees it. */
void func_80059154(s32 slot) {
    void *owner;
    void *node;
    void *next;

    owner = *(void **)(stream_state + 0x5A72 + (slot & 255) * 4);
    node = **(void ***)((u8 *)owner + 16);
    if (node) {
        do {
            streamReleaseEntry(*(s32 *)((u8 *)node + 0xA4));
            next = node;
            node = *(void **)((u8 *)node + 4);
            list_unlink_free(next, *(void **)((u8 *)owner + 16));
        } while (node);
    }
}
