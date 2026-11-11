/* If the sub-object at +0xA8 is enabled (+0x24 nonzero), sets or clears bit 2 (0x4) of the
 * object's flags at +0x80: cleared when the sub-object's mask at +0x20 has bits 0x880000 set,
 * otherwise set. */
void func_8003BA58(void *obj) {
    s32 flags;
    void *sub;

    sub = *(void **)((char *)obj + 0xA8);
    flags = *(s32 *)((char *)sub + 0x24);
    if (flags != 0) {
        flags = *(s32 *)((char *)sub + 0x20);
        sub = (void *)0x880000;
        flags &= 0x880000;
        sub = (void *)-5;
        if (flags != 0) {
            flags = *(s32 *)((char *)obj + 0x80);
            flags &= ~4;
        } else {
            flags = *(s32 *)((char *)obj + 0x80);
            flags |= 4;
        }
        *(s32 *)((char *)obj + 0x80) = flags;
    }
}
