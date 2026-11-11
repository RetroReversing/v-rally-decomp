typedef void *OSMesg;
typedef struct OSThread_s OSThread;
struct OSThread_s { struct OSThread_s *next; s32 priority; struct OSThread_s **queue; struct OSThread_s *tlnext; u16 state; };
typedef struct OSMesgQueue_s {
    OSThread    *mtqueue;
    OSThread    *fullqueue;
    s32          validCount;
    s32          first;
    s32          msgCount;
    OSMesg      *msg;
} OSMesgQueue;

extern OSThread *D_800A2520;
extern u32 osDisableInt(void);
extern void osRestoreInt(u32);
extern void func_8008B4D4(OSThread **);
extern OSThread *func_8008B624(OSThread **);
extern void osStartThread(OSThread *);

/* Sends msg to mq. If the queue is full, OS_MESG_BLOCK (flags == 1) sleeps the
 * running thread until there is room; otherwise returns -1. Wakes a thread
 * waiting to receive. Returns 0 on success. */
s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, s32 flags) {
    register u32 saveMask;
    register s32 last;

    saveMask = osDisableInt();

    while ((((  mq  )->validCount)  >= ( mq )->msgCount) ) {
        if (flags == 1 ) {
            D_800A2520->state = (1 << 3) ;
            func_8008B4D4(&mq->fullqueue);
        } else {
            osRestoreInt(saveMask);
            return -1;
        }
    }

    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != 0 ) {
        osStartThread(func_8008B624(&mq->mtqueue));
    }

    osRestoreInt(saveMask);
    return 0;
}
