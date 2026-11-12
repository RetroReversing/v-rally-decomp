/* Returns entry `index` of a pool. The item table pointer is stored at pool word 1. */
void *pool_get_item(void **pool, s32 index) { return ((void **)pool[1])[index]; }
