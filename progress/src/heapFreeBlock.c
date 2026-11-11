extern s32 gHeapBusy;
extern volatile s32 gHeapCallerRa;
extern s32 D_800C5BB0[];
extern s32 heapPanicFn;
extern s32 heapReentryFn;

/* Frees `block` through the allocator class in its header (the word 8 bytes before
 * the block indexes D_800C5BB0; that class's free routine is slot 1). Sets gHeapBusy
 * while it runs. A re-entrant call goes to heapReentryFn, a NULL block to heapPanicFn. */
s32 heapFreeBlock(void *block) {
    s32 result = 0;
    if (gHeapBusy == 1) {
        ((void (*)(s32))heapReentryFn)(gHeapCallerRa - 4);
    }
    gHeapBusy = 1;
    { void *return_address = __builtin_mips_live_return_address(); gHeapCallerRa = (s32)return_address; }
    if (block != 0) {
        s32 classIndex = *(s32 *)((u8 *)block - 8);
        s32 **allocator = (s32 **)((u8 *)D_800C5BB0 + classIndex * 4);
        result = ((s32 (*)(void *))(*allocator)[1])(block);
    } else {
        ((void (*)(s32))heapPanicFn)(gHeapCallerRa - 4);
    }
    gHeapBusy = 0;
    return result;
}
