extern int D_800C3514;
s32 heapFreeBlock();
extern u8 D_8009B610;
extern char stream_state[];

/* Frees a stream object. Its two sub-blocks (at +0x10 and +0x18) are freed too, unless the
   object is the cached one at D_800C3514; then the cache slot is cleared (when D_8009B610
   is 0) and only the object itself is freed. */
void stream_obj_free(void *obj) {
    if (obj == D_800C3514) {
        if (D_8009B610 == 0) {
            D_800C3514 = 0;
        }
    } else {
        heapFreeBlock(*(void **)((char *)obj + 0x10));
        heapFreeBlock(*(void **)((char *)obj + 0x18));
    }
    heapFreeBlock(obj);
}
