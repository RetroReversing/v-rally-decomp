s32 func_800059DC();
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;
extern s32 gSceneSlot2;

/* Creates frame buffers for the display mode bits in `mode` and stores them in the scene
 * slots. Does nothing unless bit 0x2000 is set. Bit 0x100 makes one buffer shared by slots
 * 0 and 1; bit 0x200 gives slots 0 and 1 separate buffers; bit 0x800 adds one in slot 2. */
void scene_setup_frame_buffers(s32 mode) {
    s32 fb;

    if (mode & 0x2000) {
        if (mode & 0x100) {
            fb = func_800059DC(mode, 1, 3);
            gSceneSlot1 = fb;
            gSceneSlot0 = fb;
        } else if (mode & 0x200) {
            gSceneSlot1 = func_800059DC(mode, 1, 3);
            fb = func_800059DC(mode, 1, 3);
            gSceneSlot0 = fb;
        }
        if (mode & 0x800) {
            gSceneSlot2 = func_800059DC(mode, 1, 5);
        }
    }
}
