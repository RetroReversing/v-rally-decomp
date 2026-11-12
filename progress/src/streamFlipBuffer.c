extern s32 D_800C3594;
extern s32 gEntryPoolSlot;

/* Runs the stream callback, then flips the double-buffer index and copies the
 * saved word for the new side into the other buffer slot. */
void streamFlipBuffer(void)
{
    s32 *indexPtr;
    s32 oldIndex;
    s32 off;
    s32 saved;
#ifdef PORT
    ((void (*)(void)) (uintptr_t)D_800C3594)();
#else
    ((void (*)(void)) D_800C3594)();
#endif
    indexPtr = &gEntryPoolSlot;
    oldIndex = *indexPtr;
    *indexPtr = 1 - oldIndex;
    off = gEntryPoolSlot * 4;
    saved = *((s32 *) ((((u8 *) indexPtr) - (-off)) - 0x10));
    indexPtr -= 2;
    *((s32 *) (((u8 *) indexPtr) + off)) = saved;
}
