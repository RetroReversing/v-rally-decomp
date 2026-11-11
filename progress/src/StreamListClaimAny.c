/* Walks the list whose first node is at list+4 (next pointer at +0) and claims the first node whose flags word (+0x14) has bit 0 clear, setting that bit. Returns NULL if every node is claimed. */
void *StreamListClaimAny(void *arg0) {
    s32 flags;
    void *node;

    if (arg0 != NULL) {
        node = *(void **)((char *)arg0 + 4);
        if (node != NULL) {
loop_2:
            flags = *(s32 *)((char *)node + 0x14);
            if (!(flags & 1)) {
                *(s32 *)((char *)node + 0x14) = (s32) (flags | 1);
                return node;
            }
            node = *(void **)((char *)node + 0);
            if (node == NULL) {
                return NULL;
            }
            goto loop_2;
        }
    }
    return NULL;
}
