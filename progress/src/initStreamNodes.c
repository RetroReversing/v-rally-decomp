s32 asset_list_init_once(void);
s32 poolAllocListNode(void *list, s32 size);
extern u8 gOrderState[];
extern u8 stream_state[];

/* Makes sure the order state is initialised, then allocates one 0x94-byte node
 * per entry in the stream header's count (byte +0xF) and links them into the
 * list at gOrderState+0x6D94. */
s32 initStreamNodes(void) {
    u32 i;
    u8 count;
    u8 *stream;

    asset_list_init_once();
    stream = *(u8 **)(stream_state + 0x32F2);
    count = stream[0xF];
    i = 1;
    if (count != 0) {
        do {
            i += 1;
            poolAllocListNode(*(void **)(gOrderState + 0x6D94), 0x94);
        } while (count >= i);
    }
    return 1;
}
