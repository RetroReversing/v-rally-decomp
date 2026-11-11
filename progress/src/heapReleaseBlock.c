s32 heapFreeBlock(void *);                      /* extern */
s32 list_unlink_free(s32, void *);                 /* extern */

/* Frees a heap block: first unlinks every entry from the block's list at +4, then frees the block. */
void heapReleaseBlock(void *block) {
    if (*(s32 *)((u8 *)block + 4) != 0) {
        do {
            list_unlink_free(*(s32 *)((u8 *)block + 4), block);
        } while (*(s32 *)((u8 *)block + 4) != 0);
    }
    heapFreeBlock(block);
}
