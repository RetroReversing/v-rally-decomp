extern s32 func_8000DA84();
extern s32 func_8000E2B0(s32);
extern s32 osViBlack(s32);
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;
extern s32 gSceneSlot2;
extern char gStreamState[];

/* Tears down the current scene: blanks the display, marks the stream state as
 * exiting, then releases any scene slots still in use. */
s32 scene_teardown(void) {
    osViBlack(1);
    *(s8 *)(gStreamState + 0x5BA6) = 4;
    func_8000DA84();
    if (gSceneSlot0 != 0) {
        func_8000E2B0(gSceneSlot0);
        gSceneSlot0 = 0;
    }
    if (gSceneSlot1 != 0) {
        func_8000E2B0(gSceneSlot1);
        gSceneSlot1 = 0;
    }
    if (gSceneSlot2 != 0) {
        func_8000E2B0(gSceneSlot2);
        gSceneSlot2 = 0;
    }
    return 1;
}
