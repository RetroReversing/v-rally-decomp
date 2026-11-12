/* ALHeap: base is the aligned start, cur the next free byte, len the total size, count the number of allocations. */
typedef struct ALHeap { u8 *base; u8 *cur; s32 len; s32 count; } ALHeap;

/* Sets up an audio heap over the buffer at heap, aligning its start to 16 bytes. */
void alHeapInit(ALHeap *heap, void *start, s32 len) {
    s32 align;

#ifdef PORT
    align = 0x10 - ((uintptr_t)start & 0xF);
#else
    align = 0x10 - ((s32)start & 0xF);
#endif
    if (align != 0x10) {
        heap->base = (u8 *)start + align;
    } else {
        heap->base = start;
    }
    heap->len = len;
    heap->count = 0;
    heap->cur = heap->base;
}
