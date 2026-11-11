extern void (*D_800B55EC)(void);
extern s32 D_800B7038;

/* Runs the stream callback, then flips the double-buffer index and copies the
 * saved word for the new side into the other buffer slot. */
void func_8001BD44(void)
{
    s32 *indexPtr;
    s32 oldIndex;
    s32 off;
    s32 saved;
    D_800B55EC();
    indexPtr = &D_800B7038;
    oldIndex = *indexPtr;
    *indexPtr = 1 - oldIndex;
    off = D_800B7038 * 4;
    saved = *((s32 *) ((((u8 *) indexPtr) - (-off)) - 0x10));
    indexPtr -= 2;
    *((s32 *) (((u8 *) indexPtr) + off)) = saved;
}
