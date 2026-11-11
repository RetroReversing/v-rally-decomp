void func_8001A2E0(void *);
void heapFreeBlock(s32);
extern u8 D_8009BBBC;

/* Releases the objects in the list at arg0 + 0x14, last entry first. Each object's parts
 * are released through func_8001A2E0, then its block at +0x38 is freed and cleared. Does
 * nothing unless D_8009BBBC is 1 or the list is missing. */
void releaseNodeObjects(u8 *arg0) {
    s32 i;
    u8 *obj;
    s32 val;

    if (D_8009BBBC == 1) {
        if (*(void **)(arg0 + 0x14) != NULL) {
            i = *(s32 *)(*(u8 **)(arg0 + 0x14) + 0x28) - 1;
            if (i >= 0) {
                do {
                    obj = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x14) + 0x2C) + 0 + i * 8);
                    func_8001A2E0(obj);
                    val = *(s32 *)(obj + 0x38);
                    i--;
                    if (val != 0) {
                        heapFreeBlock(val);
                        *(s32 *)(obj + 0x38) = 0;
                    }
                } while (i >= 0);
            }
        }
    }
}
