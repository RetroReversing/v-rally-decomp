extern void *g_ent_list;
extern s32 *D_800C60D4;
extern unsigned char g_dark_mode;
s32 streamReleaseEntry();
s32 heapFreeBlock();
s32 list_unlink_free();
s32 heapReleaseBlock();

/* Tears down the entity list: frees its first two child objects, and when the
   list is empty and dark mode is off, releases each queued entry in D_800C60D4
   (its entity at +0xC) before freeing the queue head. */
void func_80035A10(void) {
    void **queue;
    void *entry;

    if (*(s32 *)g_ent_list) {
        streamReleaseEntry(*(s32 *)g_ent_list);
    }
    if (*(u16 *)((char *)g_ent_list + 4) == 0 && g_dark_mode == 0) {
        queue = (void **)D_800C60D4;
        if (queue[0] != 0) {
            do {
                entry = queue[1];
                streamReleaseEntry(*(s32 *)(*(char **)(((char *)entry) + 0xC) + 0xA4));
                heapFreeBlock(*(void **)(((char *)entry) + 0xC));
                list_unlink_free(entry, queue);
            } while (queue[0] != 0);
        }
        heapReleaseBlock(queue);
    }
    if (*(void **)((char *)g_ent_list + 0x10)) {
        heapFreeBlock(*(void **)((char *)g_ent_list + 0x10));
    }
    if (*(void **)((char *)g_ent_list + 0x14)) {
        heapFreeBlock(*(void **)((char *)g_ent_list + 0x14));
    }
    heapFreeBlock(g_ent_list);
}
