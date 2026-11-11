s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800A1CF0;
extern char D_800A73E0[];
extern char gStreamState[];

/* Sets the ready flag, creates the one-slot message queue at gStreamState+0x10312 (buffer at D_800A73E0+0x45B0), and posts an empty message to it. */
void func_8008D860(void) {
    void *queue;

    queue = gStreamState + 0x10312;
    D_800A1CF0 = 1;
    osCreateMesgQueue(queue, D_800A73E0 + 0x45B0, 1);
    osSendMesg(queue, 0, 0);
}
