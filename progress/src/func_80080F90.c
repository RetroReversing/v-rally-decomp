/* Allocates size bytes from the heap at 0x40 alignment, using 0x14-shifted granules and the 0x428 mask (see heap_alloc_granule). */
s32 heap_alloc_granule();

void func_80080F90(s32 heap, s32 size) {
    heap_alloc_granule(heap, size, 0x40, 0x14, 0x428);
}
