void osCreateMesgQueue(void *mq, void *msgBuf, s32 count);
void osSendMesg(void *mq, void *msg, s32 flags);
void osRecvMesg(void *mq, void *msg, s32 flags);
extern s32 D_800A1CF0;
extern char D_800AB990[];
extern char D_800D05C0[];
extern char D_800D05C1[];

/* Takes the PIF lock. The first call sets up the lock's message queue (one slot,
 * buffer D_800AB990) and posts the initial token, then every call waits for it. */
void pif_lock(void)
{
    s32 msg;

    if (D_800A1CF0 == 0) {
        D_800A1CF0 = 1;
        osCreateMesgQueue(D_800D05C0, D_800AB990, 1);
        osSendMesg((D_800D05C1-1), 0, 0);
    }
    osRecvMesg(D_800D05C0, &msg, 1);
}