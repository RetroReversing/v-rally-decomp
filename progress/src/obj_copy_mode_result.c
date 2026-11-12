/* Copies the mode at +0x90 of src into dst's result word (dst->0x94 + 4) when it is 1 or 2; mode 0 clears the word. */
void obj_copy_mode_result(void *src, void *dst) {
    s32 mode;

    mode = *(s32 *)((char *)src + 0x90);
    if (mode != 0) {
        goto block_2;
    }
    *(s32 *)((char *)*(void **)((char *)dst + 0x94) + 4) = 0;
    return;
block_2:
    if (mode == 1) {
        goto block_4;
    }
    if (mode != 2) {
        goto block_5;
    }
block_4:
    *(s32 *)((char *)*(void **)((char *)dst + 0x94) + 4) = mode;
block_5:
    return;
}
