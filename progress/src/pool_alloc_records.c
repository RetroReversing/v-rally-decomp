s32 poolAlloc(s32 pool, s32 size, ...);

/* Allocates count records of 96 bytes each from heap pool 6. */
void pool_alloc_records(s32 count) {
    poolAlloc(6, count * 0x60);
}
