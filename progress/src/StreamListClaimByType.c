void *StreamListClaimAny();
extern u8 stream_state[];

/* Claims a node from the list at *list: the first node whose index matches the slot's byte in
 * stream_state (stride 0x18) and whose flag word at +0x14 lacks the given bits. Sets those bits and
 * returns the node; otherwise falls back to StreamListClaimAny. */
void *StreamListClaimByType(void **list, s32 flags, s32 slot, void *node)
{
    s32 i;
    s32 v;

    i = 0;
    if (list != NULL && stream_state[0x7CF3] != stream_state[0x7D0B]) {
        node = *list;
        if (node != NULL) {
            slot = (slot & 0xFF) * 0x18;
            flags &= 0xFF;
            i = 0;
            do {
                s32 k = i;
                i++;
                if (stream_state[0x7CF3 + slot] == (u8)k) {
                    v = *(s32 *)((char *)node + 0x14);
                    if ((v & flags) != flags) {
                        *(s32 *)((char *)node + 0x14) = v | flags;
                        return node;
                    }
                }
                node = *(void **)((char *)node + 4);
            } while (node != NULL);
        }
    }
    return StreamListClaimAny(list, flags, slot, node);
}
