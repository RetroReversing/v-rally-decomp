s32 poolAlloc(s32 pool, s32 size, ...);

/* Allocates count stream nodes of 24 bytes each from heap pool 6. */
void StreamAllocNodes(s32 count) {
    poolAlloc(6, count * 0x18);
}
