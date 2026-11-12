extern s32 order_recv_msg();
extern s32 freeObjectPair(s32);
extern s32 osViBlack(s32);
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;
extern s32 gSceneSlot2;
extern char stream_state[];

/* Tears down the current scene: blanks the display, marks the stream state as
 * exiting, then releases any scene slots still in use. */
s32 scene_teardown(void) {
    osViBlack(1);
    *(s8 *)(stream_state + 0x5BA6) = 4;
    order_recv_msg();
    if (gSceneSlot0 != 0) {
        freeObjectPair(gSceneSlot0);
        gSceneSlot0 = 0;
    }
    if (gSceneSlot1 != 0) {
        freeObjectPair(gSceneSlot1);
        gSceneSlot1 = 0;
    }
    if (gSceneSlot2 != 0) {
        freeObjectPair(gSceneSlot2);
        gSceneSlot2 = 0;
    }
    return 1;
}
