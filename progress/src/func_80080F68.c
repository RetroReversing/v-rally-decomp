void *heap_alloc_granule(void *heap, s32 size, s32 align, s32 shift, s32 mask);

/* Allocate a 64-byte aligned block from heap with shift 0x14 and mask 0x430 */
void func_80080F68(void *heap, s32 size) {
    heap_alloc_granule(heap, size, 0x40, 0x14, 0x430);
}
