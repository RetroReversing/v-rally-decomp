extern s8 D_800C5E54;
extern s8 D_800AE865;
extern s8 D_8009B5B0;
extern char stream_state[];
extern void *D_800D05B8;
s32 obj_get_owner();
void *taskOpen();
s32 orderSendMsgToSlot();
s32 taskRecvMsg(void *);
s32 osViBlack();
s32 viSetSwapBuffer();

/* Main display loop: waits for the previous task and the current frame, swaps the
   framebuffer, counts down the blank-screen timer, then clears the stream flags
   and posts the next frame message. */
void displayLoop(void *prevTask)
{
    void *curTask;

    curTask = taskOpen(4, 0, 1);
    for (;;) {
        taskRecvMsg(prevTask);
        viSetSwapBuffer(obj_get_owner(D_800D05B8));
        taskRecvMsg(curTask);
        if (D_800C5E54 == 0) {
            osViBlack(0);
            D_800C5E54 = (u8)D_800C5E54 - 1;
        } else if (D_800C5E54 > 0) {
            D_800C5E54 = D_800C5E54 - 1;
        }
        D_800AE865 = 0;
        D_8009B5B0 = 0;
        *(s8 *)((char *)D_800D05B8 + 0x14) = 1;
        *(s8 *)((char *)*(void **)(stream_state + 0x3252) + 0x14) = 1;
        orderSendMsgToSlot(6, 2, D_800D05B8);
    }
}