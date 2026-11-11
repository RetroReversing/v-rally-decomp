s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 __osPiAccessQueueEnabled;
extern char D_800A73E0[];
extern char gOrderState[];
extern char D_800B6FF8[];

/* Blocks until the PI access queue (at gOrderState+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
void pi_access_wait(void)
{
    s32 msg;

    if (__osPiAccessQueueEnabled == 0) {
        __osPiAccessQueueEnabled = 1;
        osCreateMesgQueue(gOrderState + 0x87A8, D_800A73E0 + 0x6AF0, 1);
        osSendMesg(D_800B6FF8, 0, 0);
    }
    osRecvMesg(gOrderState + 0x87A8, &msg, 1);
}
