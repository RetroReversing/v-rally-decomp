/* Wrapper that frees a block on the heap. */
s32 heapFreeBlock(void *block);

void func_80009FC8(void *block) {
    heapFreeBlock(block);
}
