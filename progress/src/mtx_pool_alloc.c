extern s32 D_800B7038;
extern u8 gOrderState[];

/* Bump-allocates one 0x40-byte matrix slot from the pool selected by D_800B7038 and returns the previous offset. */
s32 mtx_pool_alloc(void) {
    s32 idx = D_800B7038;
    s32 *cursor = (s32 *)(gOrderState + 0x87E0) + idx;
    s32 old = *cursor;
    *cursor = old + 0x40;
    return old;
}
