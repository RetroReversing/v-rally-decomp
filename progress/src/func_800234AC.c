/* Walks the car list (gCarList points at the head pointer; next pointer at +4) and sets flag bit 0x10 in each car's word at +0x14. */
extern void *gCarList;

void func_800234AC(void) {
    void *node;

    node = *(void **)gCarList;
    if (node != NULL) {
        do {
            *(s32 *)((char *)node + 0x14) = (s32)(*(s32 *)((char *)node + 0x14) | 0x10);
            node = *(void **)((char *)node + 4);
        } while (node != NULL);
    }
}
