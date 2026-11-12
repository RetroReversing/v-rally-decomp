typedef s32 M2C_UNK;
M2C_UNK func_80005A54(s32, s32);
M2C_UNK sceneSwapSlots();
extern s32 gSceneSlot0;
extern s32 gSceneSlot1;

/* Swaps the two scene slots: func_80005A54 takes the pair, then sceneSwapSlots finishes the swap. */
void func_80005ACC(void) {
    func_80005A54(gSceneSlot0, gSceneSlot1);
    sceneSwapSlots();
}
