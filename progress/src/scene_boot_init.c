s32 poolAlloc(s32, s32, ...);
s32 scene_switch(s32 do_free, s32 scene_id);
s32 heapFreeBlock(s32);
void video_mode_setup(s32, s32);
extern s32 gSceneSlot1;
extern s32 gSceneHeapBlock;

/* Boot-time scene setup: allocates the scene heap block from pool 3, then switches
 * to scene 0x2217 without freeing the old buffers and applies the video mode for slot 1. */
void scene_boot_init(void) {
    gSceneHeapBlock = poolAlloc(3, 0x54C70);
    scene_switch(0, 0x2217);
    video_mode_setup(gSceneSlot1, 0);
}
