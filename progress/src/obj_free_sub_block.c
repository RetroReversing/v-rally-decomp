void heapFreeBlock(s32 block);

/* Frees the heap block at +0x7C of the sub-object pointed to by the object's +0x88 field. */
void obj_free_sub_block(void *obj) {
    void *sub;

    sub = *(void **)((s8 *)obj + 0x88);
    heapFreeBlock(*(s32 *)((s8 *)sub + 0x7C));
}
