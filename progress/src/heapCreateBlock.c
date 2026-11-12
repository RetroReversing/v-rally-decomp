void heapInitBlock(void *block, s32 size);

/* Sets up a heap block of `size` bytes at `block` and returns the usable area just past its 0x14-byte header. */
void *heapCreateBlock(void *block, s32 size) {
    heapInitBlock(block, size);
    *(s32 *)((s8 *)block + 0xC) = 1;
    return (s8 *)block + 0x14;
}
