/* Bump-allocates num * elem_size bytes (rounded up to 16) from the heap block at heap:
 * heap[1] is the next free address and heap[0] + heap[2] is the end of the block.
 * Returns the start address, or 0 if the block is too full. */
u32 alHeapDBAlloc(s32 arg0, s32 arg1, s32 *heap, s32 num, s32 elem_size)
{
    u32 start;
    u32 end;
    u32 ret;
    u32 bytes;

    bytes = ((num * elem_size) + 0xF) & -0x10;
    start = heap[1];
    end = start + bytes;
    ret = 0;
    if (heap[0] + heap[2] >= end) {
        ret = start;
        heap[1] = end;
    }
    return ret;
}
