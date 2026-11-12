s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800A1CF0;
extern char gGameState[];
extern char stream_state[];

/* Sets the ready flag, creates the one-slot message queue at stream_state+0x10312 (buffer at gGameState+0x45B0), and posts an empty message to it. */
void func_8008D860(void) {
    void *queue;

    queue = stream_state + 0x10312;
    D_800A1CF0 = 1;
    osCreateMesgQueue(queue, gGameState + 0x45B0, 1);
    osSendMesg(queue, 0, 0);
}
