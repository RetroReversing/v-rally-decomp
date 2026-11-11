s32 taskOpen();
s32 osCreateMesgQueue();
extern char gOrderState[];
extern char gStreamState[];
extern s32 func_8007FC14;

/* Sets up the task system at startup: installs the stream callback, clears the four counters at
 * gOrderState+0x2268 and creates the message queues for the four tasks (task ids 4, 9, 38, 34). */
s32 func_8007FA70(void) {
    void *queue;

    queue = gOrderState + 0x1D10;
    *(s32 * *)(gStreamState + 0x7DFA) = &func_8007FC14;
    *(s32 *)(gOrderState + 0x2268) = 0;
    *(s32 *)(gOrderState + 0x226C) = 0;
    *(s32 *)(gOrderState + 0x2270) = 0;
    *(s32 *)(gOrderState + 0x2274) = 0;
    osCreateMesgQueue(queue + 0x10, queue + 0x28, 8);
    *(s32 *)(gOrderState + 0x1D10) = taskOpen(4, 0, 8);
    *(s32 *)(gOrderState + 0x1D14) = taskOpen(9, 1, 0x10);
    *(s32 *)(gOrderState + 0x1D18) = taskOpen(0x26, 0, 8);
    *(s32 *)(gOrderState + 0x1D1C) = taskOpen(0x22, 0, 8);
    return 1;
}
