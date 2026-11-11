s32 huft_free(s32);
extern s32 gStreamState;

/* Frees the two Huffman table buffers held in gStreamState (at +0x30FA and +0x30FE) and clears their pointers, if the first one is set. */
s32 huftFreeTables(void) {
    if (*(s32 *)((char *)&gStreamState + 0x30FA) != 0) {
        huft_free(*(s32 *)((char *)&gStreamState + 0x30FE));
        huft_free(*(s32 *)((char *)&gStreamState + 0x30FA));
        *(s32 *)((char *)&gStreamState + 0x30FA) = 0;
        *(s32 *)((char *)&gStreamState + 0x30FE) = 0;
    }
    return 0;
}
