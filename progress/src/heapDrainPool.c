s32 func_8007EF5C(s32);
s32 poolAlloc(s32, s32);
void heapFreeBlock(s32);

/* Takes a count from func_8007EF5C (arg0 is the pool id). While the count is nonzero it allocates a block of that size from the pool, recurses for the rest, frees the block and returns the total. */
s32 heapDrainPool(s32 poolId)
{
    s32 count;
    s32 block;

    count = func_8007EF5C(poolId);
    if (count != 0) {
        block = poolAlloc(poolId, count);
        if (block != 0) {
            count += heapDrainPool(poolId);
            heapFreeBlock(block);
        }
    }
    return count;
}
