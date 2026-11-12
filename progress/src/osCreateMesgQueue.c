typedef struct OSMesgQueue {
    void *mtqueue;
    void *fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
} OSMesgQueue;

extern void *D_800A2510;

/* Initialise a message queue: both thread queues empty, no messages queued, msg buffer of msgCount entries. */
void osCreateMesgQueue(OSMesgQueue *mq, void **msg, s32 msgCount) {
    mq->mtqueue = &D_800A2510;
    mq->fullqueue = &D_800A2510;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = msgCount;
    mq->msg = msg;
}
