/* If the sub-object at +0xA8 has a child at +0x24, clears bit 2 of the object's flags (+0x80)
 * and copies the child's byte at +0x70 into the object's 16-bit counter at +0x7A, capped at 10. */
void func_8003CC0C(void *obj) {
    s32 value;
    void *child;

    child = *(void **)((char *)*(void **)((char *)obj + 0xA8) + 0x24);
    if (child != NULL) {
        *(s32 *)((char *)obj + 0x80) = (s32)(*(s32 *)((char *)obj + 0x80) & ~4);
        value = **(s32 **)((char *)child + 0x70);
        *(s16 *)((char *)obj + 0x7A) = (s16)value;
        if ((s16)value >= 0xA) {
            *(s16 *)((char *)obj + 0x7A) = 0;
        }
    }
}
