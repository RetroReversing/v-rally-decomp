/* Zeroes the word at +0x74 of the sub-object pointed to by obj+0x88. */
void obj_clear_sub_0x74(void *obj) {
    *(s32 *)((s8 *)*(void **)((s8 *)obj + 0x88) + 0x74) = 0;
}
