s32 heapFreeBlock(void *);
/* Frees a singly linked chain of heap blocks (link at +4, block header 8 bytes before the pointer) starting at head. */ s32 huft_free(void *head) {
    register void *nextBlock;
    void *block = head;
    if (block != 0) {
        do {
            block = (void *)((u8 *)block - 8);
            nextBlock = *(void **)((u8 *)block + 4);
            heapFreeBlock(block);
            block = nextBlock;
        } while (block != 0);
    }
    return 0;
}
