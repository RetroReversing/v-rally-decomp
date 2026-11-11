extern int gSceneSlot0;
extern int gSceneSlot1;
extern void (*gOrderPrevHook)(void);

/* Swaps the two scene slots, then calls the order-previous hook. */
void sceneSwapSlots(void)
{
    int a = gSceneSlot0;
    int b = gSceneSlot1;
    gSceneSlot1 = a;
    gSceneSlot0 = b;
    (*gOrderPrevHook)();
}
