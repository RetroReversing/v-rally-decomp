extern s32 heapFreeBlock(void *block);

/* Frees the four buffers held by the object's buffer block at +0x40. */
void free_obj_buffers(void *obj) {
    heapFreeBlock(*(void **)(*(u8 **)((u8 *)obj + 0x40) + 0));
    heapFreeBlock(*(void **)(*(u8 **)((u8 *)obj + 0x40) + 0x18));
    heapFreeBlock(*(void **)(*(u8 **)((u8 *)obj + 0x40) + 0x24));
    heapFreeBlock(*(void **)(*(u8 **)((u8 *)obj + 0x40) + 0x28));
}
