s32 heapFreeBlock(s32);
void osDestroyThread();

/* Destroys the current thread, then frees the heap block passed in. Returns 1. */
s32 func_8007FBE4(s32 block) {
    osDestroyThread();
    heapFreeBlock(block);
    return 1;
}
