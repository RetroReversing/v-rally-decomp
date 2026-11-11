s32 osCreateMesgQueue();
s32 osCreateThread();
s32 osStartThread();
extern char gDmaRequestQueue[];
extern char gDmaRequestMsg[];
extern char D_800A7780[];
extern char gDmaThreadStack[];
extern s32 gNameSlotCount;
extern s32 gStringEntryCount;
extern char dma_thread_main[];

/* Starts the DMA service thread: sets up its request queue, creates the thread
 * (id 0xA, priority 0x7F) on its own stack, starts it, and clears two counters. */
void dma_thread_start(void)
{
    osCreateMesgQueue(gDmaRequestQueue, gDmaRequestMsg, 1);
    osCreateThread(D_800A7780, 0xA, dma_thread_main, 0, gDmaThreadStack, 0x7F);
    osStartThread(D_800A7780);
    gNameSlotCount = 0;
    gStringEntryCount = 0;
}
