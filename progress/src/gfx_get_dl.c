/* Returns the current display-list pointer stored at gfx+0x14 (as a word; callers cast it to u32 *). */
s32 gfx_get_dl(void *gfx) {
    return *(s32 *)((s8 *)gfx + 0x14);
}
