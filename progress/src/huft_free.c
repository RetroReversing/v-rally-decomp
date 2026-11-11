s32 heapFreeBlock(void *);
s32 huft_free(s32 arg0) {
    register s32 next;
    void *p = (void *)arg0;
    if (p != 0) {
        do {
            p = (void *)((u8 *)p - 8);
            next = *(s32 *)((u8 *)p + 4);
            heapFreeBlock(p);
            p = (void *)next;
        } while (p != 0);
    }
    return 0;
}
