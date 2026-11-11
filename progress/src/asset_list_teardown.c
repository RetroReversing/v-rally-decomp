s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 stream_list_destroy();
s32 heapFreeBlock();
s32 heapReleaseBlock();
extern char gOrderState[];

/* Tears down the asset block list: frees each node's buffers, then the list
 * itself, and clears the list head. Does nothing unless the lock is taken. */
void asset_list_teardown(void) {
    void *node;

    if (flag_test_bit0(gOrderState + 0x7348) != 0) {
        if (*(void ** *)(gOrderState + 0x6D94) != NULL) {
            node = **(void ** *)(gOrderState + 0x6D94);
            if (node != NULL) {
                do {
                    stream_list_destroy(*(s32 *)((char *)node + 0xC));
                    stream_list_destroy(*(s32 *)((char *)node + 0x44));
                    heapFreeBlock(*(s32 *)((char *)node + 0x30));
                    heapFreeBlock(*(s32 *)((char *)node + 0x68));
                    heapFreeBlock(*(s32 *)((char *)node + 0x34));
                    heapFreeBlock(*(s32 *)((char *)node + 0x6C));
                    heapFreeBlock(*(s32 *)((char *)node + 0x38));
                    heapFreeBlock(*(s32 *)((char *)node + 0x70));
                    node = *(void * *)((char *)node + 4);
                } while (node != NULL);
            }
        }
        flag_clear_bit0(gOrderState + 0x7348);
        heapReleaseBlock(*(void ** *)(gOrderState + 0x6D94));
        *(void ** *)(gOrderState + 0x6D94) = NULL;
    }
}
