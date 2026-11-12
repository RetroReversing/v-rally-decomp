/* Appends a G_DL command (0xDE) that calls the display list at src->0x10 to the list at list->0x14; returns 1. */
s32 dl_append_call(void *list, void *src) {
    void *cmd;

    cmd = *(void **)((s8 *)list + 0x14);
    *(void **)((s8 *)list + 0x14) = (void *)(cmd + 8);
    *(s32 *)((s8 *)cmd + 0) = 0xDE000000;
    *(s32 *)((s8 *)cmd + 4) = *(s32 *)((s8 *)src + 0x10);
    return 1;
}
