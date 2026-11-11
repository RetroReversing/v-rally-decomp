extern s8 D_800C5E54;
extern s8 D_800AE865;
extern s8 D_8009B5B0;
extern char gStreamState[];
extern s32 D_800D05B8;
s32 func_80005C48();
s32 taskOpen();
s32 func_8007F798();
s32 taskRecvMsg(void *);
s32 osViBlack();
s32 osViSwapBuffer();

/* Main display loop: waits for the previous task and the current frame, swaps the
   framebuffer, counts down the blank-screen timer, then clears the stream flags
   and posts the next frame message. */
void displayLoop(void *prevTask)
{
    s32 curTask;

    curTask = taskOpen(4, 0, 1);
    for (;;) {
        taskRecvMsg(prevTask);
        osViSwapBuffer(func_80005C48(D_800D05B8));
        taskRecvMsg(curTask);
        if (D_800C5E54 == 0) {
            osViBlack(0);
            D_800C5E54 = (u8)D_800C5E54 - 1;
        } else if (D_800C5E54 > 0) {
            D_800C5E54 = D_800C5E54 - 1;
        }
        D_800AE865 = 0;
        D_8009B5B0 = 0;
        *(s8 *)(D_800D05B8 + 0x14) = 1;
        *(s8 *)(*(s32 *)(gStreamState + 0x3252) + 0x14) = 1;
        func_8007F798(6, 2, D_800D05B8);
    }
}
