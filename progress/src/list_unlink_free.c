s32 heapFreeBlock(s32);
void list_unlink();

/* Unlinks the current node from its list, then frees the memory block it sits in. */
void list_unlink_free(s32 block) {
    list_unlink();
    heapFreeBlock(block);
}
