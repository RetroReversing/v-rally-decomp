extern s32 osPiIsInitialized;
extern void *__osPiThread, *osPiCommandQueue, *__osPiEventQueue, *__osPiAccessQueue, *D_800A2554, *D_800A2558;
extern s32 __osPiAccessQueueEnabled;
extern u8 gGameState[], gOrderState[];
extern u8 D_800AB9E0[], D_800ACB90[], D_800ACBA8[], D_800B6FF8[];
extern void __osDevMgrMain(void), pi_raw_start_dma(void), PiRawStartDma(void), func_800903F0(void);
extern s32 func_800937D0(s32), func_80094660(void), osDisableInt(void), osRestoreInt(s32);
extern s32 osCreateMesgQueue(void *, void *, s32), osCreateThread(void *, s32, void (*)(void), void *, void *, s32), osStartThread(void *), osSetEventMesg(s32, void *, s32), osSetThreadPri(s32, s32);

/* Starts the PI manager once: saves the PI timing, creates the command and event queues,
 * the PI access queue, and the dev manager thread at priority pri. */
void osCreatePiManager(s32 pri, void *cmdQueue, void *cmdBuf, s32 cmdMsgCnt) {
    s32 *initialized = &osPiIsInitialized;
    s32 prevPri, savedMask, restorePri;
    void *eventQueue, *thread;

    if (*initialized) return;
    func_800903F0();
    osCreateMesgQueue(cmdQueue, cmdBuf, cmdMsgCnt);
    eventQueue = D_800ACB90;
    osCreateMesgQueue(eventQueue, D_800ACBA8, 1);
    if (__osPiAccessQueueEnabled == 0) func_80094660();
    osSetEventMesg(8, eventQueue, 0x22222222);
    restorePri = -1;
    prevPri = func_800937D0(0);
    if (prevPri < pri) {
        restorePri = prevPri;
        osSetThreadPri(0, pri);
    }
    savedMask = osDisableInt();
    thread = D_800AB9E0;
    *initialized = 1;
    __osPiAccessQueue = gOrderState + 0x87A8;
    D_800A2554 = pi_raw_start_dma;
    D_800A2558 = PiRawStartDma;
    __osPiEventQueue = eventQueue;
    __osPiThread = thread;
    osPiCommandQueue = cmdQueue;
    osCreateThread(thread, 0, __osDevMgrMain, initialized, gGameState + 0x57B0, pri);
    osStartThread(thread);
    osRestoreInt(savedMask);
    if (restorePri != -1) osSetThreadPri(0, restorePri);
}
