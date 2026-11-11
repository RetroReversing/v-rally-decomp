s32 heapQueryFreeSize(s32);
extern s32 gFreeHeap1;
extern s32 gFreeHeap2;
extern s32 gSceneHeapBlock;
extern char gOrderState[];
extern char gStreamState[];

/* Refreshes the free sizes of heaps 1 and 2 (gFreeHeap1/2), stores gSceneHeapBlock
 * in the order state, and marks the stream state's slot at +0x5BA2 as unset (-1). */
void func_80069974(void)
{
    gFreeHeap1 = heapQueryFreeSize(1);
    gFreeHeap2 = heapQueryFreeSize(2);
    *((s32 *) (gOrderState + 0x881C)) = (s32) gSceneHeapBlock;
    gFreeHeap1 = heapQueryFreeSize(1);
    gFreeHeap2 = heapQueryFreeSize(2);
    *((s32 *) (gStreamState + 0x5BA2)) = -1;
}
