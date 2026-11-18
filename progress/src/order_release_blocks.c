extern char gOrderState[];
extern char stream_state[];
extern void *gOrderPrevHook;
void heapFreeBlockThunk(s32);

/* Frees the two order record buffers and saves the order hook pointer into stream_state. */
void order_release_blocks(void)
{
    heapFreeBlockThunk(*(s32 *)(gOrderState + 0x87D8));
    heapFreeBlockThunk(*(s32 *)(gOrderState + 0x87DC));
    *(s32 *)(stream_state + 0x7DA6) = *(s32 *)(gOrderState + 0x6D9C);
}
