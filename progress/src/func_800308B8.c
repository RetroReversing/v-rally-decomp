/* Frees the two heap blocks owned by obj: the sub-block at +0x78 (its inner block at +0x1C is freed first), then the block at +0x78. */
void heapFreeBlock(void *);

void func_800308B8(void *arg0) {
    heapFreeBlock(*(void **)(*(char **)((char *)arg0 + 0x78) + 0x1C));
    heapFreeBlock(*(void **)((char *)arg0 + 0x78));
}
