s32 func_800914E0();
extern s32 D_800A6FE0;
extern s32 D_800A6FE4;

/* Walks the list of entries (linked through +0, each with its time at +0x10) and finds
   the one due soonest after the list's base time (+0x20). Stores that entry in *next
   and returns its time. */
s32 __nextSampleTime(void *list, void **next) {
    s32 minDelta;
    void *node;

    minDelta = 0x7FFFFFFF;
    if (*(void **)((u8 *)list + 0) == NULL) {
        func_800914E0(&D_800A6FE0, &D_800A6FE4, 0x133);
    }
    *next = NULL;
    node = *(void **)((u8 *)list + 0);
    if (node != NULL) {
        do {
            if ((*(s32 *)((u8 *)node + 0x10) - *(s32 *)((u8 *)list + 0x20)) < minDelta) {
                *next = node;
                minDelta = *(s32 *)((u8 *)node + 0x10) - *(s32 *)((u8 *)list + 0x20);
            }
            node = *(void **)((u8 *)node + 0);
        } while (node != NULL);
    }
    return *(s32 *)((u8 *)*next + 0x10);
}
