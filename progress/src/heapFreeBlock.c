extern s32 gHeapBusy;
extern volatile s32 gHeapCallerRa;
extern s32 D_800C5BB0[];
extern void (*heapPanicFn)(s32);
extern void (*heapReentryFn)(s32);

/* Frees `block` through the allocator class in its header (the word 8 bytes before
 * the block indexes D_800C5BB0; that class's free routine is slot 1). Sets gHeapBusy
 * while it runs. A re-entrant call goes to heapReentryFn, a NULL block to heapPanicFn. */
s32 heapFreeBlock(void *block) {
    s32 result = 0;
    if (gHeapBusy == 1) {
        heapReentryFn(gHeapCallerRa - 4);
    }
    gHeapBusy = 1;
#ifdef PORT
    /* The live return address has no PC equivalent; record 0. */
    gHeapCallerRa = 0;
#else
    { void *return_address = __builtin_mips_live_return_address(); gHeapCallerRa = (s32)return_address; }
#endif
    if (block != 0) {
        s32 classIndex = *(s32 *)((u8 *)block - 8);
        void **allocator = (void **)((u8 *)D_800C5BB0 + classIndex * 4);
        result = ((s32 (*)(void *))((void **)*allocator)[1])(block);
    } else {
        heapPanicFn(gHeapCallerRa - 4);
    }
    gHeapBusy = 0;
    return result;
}
