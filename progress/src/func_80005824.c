/* Stores two words into the pooled-list header of obj: first at 0x3C, second at 0x40. */
void func_80005824(void *obj, s32 first, s32 second) {
    *(s32 *)((s8 *)obj + 0x3C) = first;
    *(s32 *)((s8 *)obj + 0x40) = second;
}
