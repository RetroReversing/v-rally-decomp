extern s32 gMtxPoolIndex;
extern u8 gOrderState[];

/* Bump-allocates one 0x40-byte matrix slot from the pool selected by gMtxPoolIndex and returns the slot's old offset. */
s32 mtx_pool_alloc(void)
{
    s32 index = gMtxPoolIndex;
    s32 *cursor = (s32 *)(gOrderState + 0x87E0) + index;
    s32 old = *cursor;

    *cursor = old + 0x40;
    return old;
}
