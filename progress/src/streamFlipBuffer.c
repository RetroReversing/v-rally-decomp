extern s32 D_800C3594;
extern s32 D_800C35B8;

/* Runs the stream callback, then flips the double-buffer index and copies the
 * saved word for the new side into the other buffer slot. */
void streamFlipBuffer(void)
{
    s32 *indexPtr;
    s32 oldIndex;
    s32 off;
    s32 saved;
    ((void (*)(void)) D_800C3594)();
    indexPtr = &D_800C35B8;
    oldIndex = *indexPtr;
    *indexPtr = 1 - oldIndex;
    off = D_800C35B8 * 4;
    saved = *((s32 *) ((((u8 *) indexPtr) - (-off)) - 0x10));
    indexPtr -= 2;
    *((s32 *) (((u8 *) indexPtr) + off)) = saved;
}
