extern s32 gSceneSlot0;
extern u8 *g_camera;
s32 func_80005718(s32,s32);
s32 func_80005ACC(void);
s32 view_gfx_setup(s32);
s32 func_8000E8FC(s32,s32,s32);
s32 taskOpen(s32,s32,s32);
s32 func_8007F634(s32);
s32 taskRecvMsg(s32);

/* Runs the two draw passes for the frame. Each pass sets up the view from the
 * camera, runs the draw step, and waits for both task messages; the two message
 * ids are released after the second pass. */
void renderTwoPasses(void) {
    s32 msgA;
    s32 msgB;
    s32 v;
    u8 counter;

    counter = 0;
    msgA = taskOpen(6, 2, 1);
    msgB = taskOpen(9, 2, 8);
    do {
        view_gfx_setup(*(s32 *)(g_camera + 0x178));
        func_8000E8FC(*(s32 *)(g_camera + 0x178), gSceneSlot0, 0);
        func_80005718(gSceneSlot0, *(s32 *)(g_camera + 0x178));
        taskRecvMsg(msgB);
        func_80005ACC();
        taskRecvMsg(msgA);
        v = ++counter;
    } while (v != 2);
    func_8007F634(msgA);
    func_8007F634(msgB);
}
