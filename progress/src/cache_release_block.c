void heapReleaseBlock(s32 block);
extern s32 D_800C6F0C;

/* Releases the cached heap block and clears the saved handle. */
void cache_release_block(void) {
    heapReleaseBlock(D_800C6F0C);
    D_800C6F0C = 0;
}
