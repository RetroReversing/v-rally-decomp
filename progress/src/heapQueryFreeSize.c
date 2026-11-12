extern s32 gHeapBusy, gHeapCallerRa;
extern void (*heapPanicFn)(s32), (*heapReentryFn)(s32);
extern s32 gHeapBlocks[];
extern s32 heapBlockFreeSize(s32);

/* Returns the free bytes in a heap block. handle is a block index into gHeapBlocks, or a block pointer.
 * Panics if the block is null. Calling it while the heap is already busy reports the reentry. */
s32 heapQueryFreeSize(s32 handle)
{
    volatile s32 handleKind;
    s32 result = 0;
    s32 block;
    s32 header;
    if (gHeapBusy == 1) heapReentryFn(gHeapCallerRa - 4);
    gHeapBusy = 1;
#ifdef PORT
    /* The live return address has no PC equivalent; record 0. */
    gHeapCallerRa = 0;
#else
    do { gHeapCallerRa = (s32) __builtin_mips_live_return_address(); } while (0);
#endif
    if (!(handle & 0xffff0000)) { block = gHeapBlocks[handle]; handleKind = handle; } else { block = handle; handleKind = 1; }
    if (block == 0) { heapPanicFn(gHeapCallerRa - 4); header = 0; } else header = block - 8;
    if (header) result = heapBlockFreeSize(header + 8);
    gHeapBusy = 0;
    return result;
}
