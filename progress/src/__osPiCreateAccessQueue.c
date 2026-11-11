s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 __osPiAccessQueueEnabled;
extern char D_800A73E0[];
extern char gOrderState[];

/* Enables the PI access queue: creates the one-slot message queue at gOrderState+0x87A8 (buffer at D_800A73E0+0x6AF0) and posts an empty message to it. */
void __osPiCreateAccessQueue(void) {
    void *queue;

    queue = gOrderState + 0x87A8;
    __osPiAccessQueueEnabled = 1;
    osCreateMesgQueue(queue, D_800A73E0 + 0x6AF0, 1);
    osSendMesg(queue, 0, 0);
}
