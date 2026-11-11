/* Refreshes the object's status bytes from its linked target: while the target
 * has a live sub-block, sets the busy bit (0x4) in the flags at +0x80, and when
 * the sub-block's flag at +0xC is set, writes the state at +0x7A and, if the
 * sub-block's +0x20 is zero, the four status bytes at +0x90. */
void func_8003AE84(void *obj) {
    void *target;

    target = *(void **)(*(void **)((char *)obj + 0xA8) + 0x24);
    if (target != NULL) {
        *(s32 *)((char *)obj + 0x80) |= 4;
        if (*(s32 *)(*(void **)((char *)target + 0x6C) + 0xC) != 0) {
            *(s16 *)((char *)obj + 0x7A) = 0xB;
            if (*(s32 *)(*(void **)((char *)target + 0x6C) + 0x20) == 0) {
                *(u8 *)((char *)obj + 0x90) = 0xFE;
                *(u8 *)((char *)obj + 0x91) = 0xD5;
                *(s8 *)((char *)obj + 0x92) = 0x1E;
                *(u8 *)((char *)obj + 0x93) = 0xFF;
            }
            *(s32 *)((char *)obj + 0x80) &= ~4;
        }
    }
}
