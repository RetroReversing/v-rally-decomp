s32 stream_obj_free();
s32 heapFreeBlock();
s32 heap_free_stub();
extern void *gSelectState;

/* Frees the select screen's per-slot entries, then the state block itself, and clears gSelectState. */
void select_state_free(void)
{
    s32 slot;
    s32 offset;
    void *state;

    state = gSelectState;
    slot = 0;
    if (*((u8 *)state + 0x22C) != 0) {
        do {
            offset = (slot & 0xFF) << 2;
            stream_obj_free(*(s32 *)((u8 *)state + (offset + 0xE4)));
            slot++;
            offset += (s32)gSelectState;
            heap_free_stub(*(s32 *)(offset + 0x134));
            state = gSelectState;
        } while ((u32)(u8)slot < (u32)*((u8 *)state + 0x22C));
    }
    heapFreeBlock(gSelectState);
    gSelectState = NULL;
}
