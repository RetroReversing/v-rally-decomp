void func_80005718(s32 unused, s32 obj);
extern s32 gSceneSlot0;
extern s32 D_800C35C0;

/* Finishes the buffers for the stream node's field at +0x178 and counts the node as processed. */
void streamProcessNode(void *node) {
    func_80005718(gSceneSlot0, *(s32 *)((s8 *)node + 0x178));
    D_800C35C0 += 1;
}
