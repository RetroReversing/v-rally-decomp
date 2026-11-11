extern s32 D_800A1BA0;
extern u32 cacheTick;
extern s32 D_800A1BB4;
extern u8 gStreamState[];
extern s32 D_800B0AD4[];
extern void func_8008743C(void);
extern s32 taskOpen(s32, s32, s32);
extern void *taskRecvMsg(s32);
extern s32 func_800871FC(s32, s32);
extern void handleAudioUnderrun(s32);
extern void osSetThreadPri(s32, s32);

/* Audio thread body: registers the audio-done callback, then loops servicing the
 * audio buffer queue. When the queue has a free slot the next buffer is fetched
 * and checked for underrun; otherwise the thread drops to priority 6 and waits.
 * The loop never exits (the exit flag s4 is never set). */
void audio_thread_main(void) {
    s32 exit_flag;
    s32 old;
    s32 msg;
    void *buf;

    exit_flag = 0;
    *(s32 *)(gStreamState + 0x8072) = taskOpen(4, 0, 1);
    old = *(s32 *)(gStreamState + 0x7DA6);
    *(s32 *)(gStreamState + 0x7DA6) = (s32)func_8008743C;
    D_800A1BA0 = old;
    msg = taskOpen(0x26, 1, 1);
    do {
        if (func_800871FC(D_800B0AD4[cacheTick % 3], D_800A1BB4)) {
            buf = taskRecvMsg(msg);
            handleAudioUnderrun(*(s32 *)((u8 *)buf + 4));
            D_800A1BB4 = *(s32 *)((u8 *)buf + 4);
        } else {
            taskRecvMsg(*(s32 *)(gStreamState + 0x8072));
            osSetThreadPri(D_800B0AD4[3], 6);
        }
    } while (exit_flag == 0);
}
