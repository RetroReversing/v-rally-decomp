extern char gOrderState[];
extern char stream_state[];
s32 heapQueryFreeSize(s32 heap);

/* Records the free heap size for heap 2 in the order state and for heap 1 in stream_state. */
void cacheHeapFreeSizes(void)
{
    *((s32 *) (gOrderState + 0x2380)) = heapQueryFreeSize(2);
    *((s32 *) (stream_state + 0x80CE)) = heapQueryFreeSize(1);
}
