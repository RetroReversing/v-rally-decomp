s32 frame_buffer_setup(void *, s32);
void *poolAlloc(s32, s32);
s32 heapFreeBlock(void *);

/* Allocates a 0x28-byte pool block and stores arg2 in its word at +0x10. The block is
 * handed to frame_buffer_setup; if that reports failure it is freed and NULL is returned. */
void *func_800059DC(s32 arg0, s32 pool, s32 arg2)
{
    void *block;
    void *result;

    block = poolAlloc(pool, 0x28);
    result = block;
    if (block != NULL) {
        *(s32 *)((u8 *)block + 0x10) = arg2;
        result = block;
        if (!(frame_buffer_setup(block, arg0) & 0xFF)) {
            heapFreeBlock(block);
            result = NULL;
        }
    }
    return result;
}
