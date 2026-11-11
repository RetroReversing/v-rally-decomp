s32 heapFreeBlock(s32);
s32 huftFreeTables(void);
extern s32 gOrderState;
extern s32 gStreamState;

/* Frees the order-state block, the stream's Huffman tables, and the stream block at gStreamState+0x308A (if set). */
void streamFreeBuffers(void) {
    heapFreeBlock(*(s32 *)((char *)&gOrderState + 0x8AE0));
    huftFreeTables();
    if (*(s32 *)((char *)&gStreamState + 0x308A) != 0) {
        heapFreeBlock(*(s32 *)((char *)&gStreamState + 0x308A));
    }
    *(s32 *)((char *)&gStreamState + 0x308A) = 0;
}
