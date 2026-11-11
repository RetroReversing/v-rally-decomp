s32 scene_setup_frame_buffers();
s32 heapFreeBlock();
extern s32 gSceneId;
extern s32 *gSceneSlot0;
extern s32 *gSceneSlot1;
extern s32 *gSceneSlot2;

/* Switches to scene sceneId. When a scene is already loaded, frees the buffers in the three scene slots
 * first (unless the scene is unchanged). Returns 1 if the scene was switched, 0 if not. */
s32 scene_switch(s32 arg0, s32 arg1) {
    s32 sceneId;
    s32 result;
    s32 *slot;
    s32 *slot0;

    sceneId = arg1;
    result = 0;
    if (arg0 != 0) {
        slot = gSceneSlot0;
        if (slot == NULL) {
            goto done;
        }
        slot0 = slot;
        if (sceneId == slot0[6]) {
            goto done;
        }
        if (slot0[3] != 0) {
            heapFreeBlock(slot0[3]);
        }
        slot0[3] = 0;
        if (gSceneSlot0 != gSceneSlot1) {
            slot0 = gSceneSlot1;
            if (slot0[3] != 0) {
                heapFreeBlock(slot0[3]);
            }
            slot0[3] = 0;
        }
        slot = gSceneSlot2;
        if (slot != NULL) {
            slot0 = slot;
            if (slot0[3] != 0) {
                heapFreeBlock(slot0[3]);
            }
            slot0[3] = 0;
        }
    }
    scene_setup_frame_buffers(sceneId);
    gSceneId = sceneId;
    result = 1;
done:
    return result;
}
