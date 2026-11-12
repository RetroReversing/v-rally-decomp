s32 heap_alloc_granule();

/* Allocates from the given heap with fixed alignment and range-mask parameters. */
void func_80080FE0(s32 heap, s32 size) {
    heap_alloc_granule(heap, size, 8, 0x14, 1);
}
