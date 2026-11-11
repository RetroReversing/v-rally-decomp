typedef u64 OSTime;
typedef void *OSMesg;
typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    OSTime interval;
    OSTime value;
    OSMesgQueue *mq;
    OSMesg msg;
} OSTimer;
extern OSTimer *__osTimerList;
extern OSTime __osInsertTimer(OSTimer *);
extern void __osSetTimerIntr(OSTime);

/* Arms timer t. A zero countdown means "first fire after one interval". The timer is linked into the
 * timer list; if it is now the head, the hardware timer interrupt is reprogrammed to its time. */
int osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg) {
    OSTime time;

    timer->next = 0;
    timer->prev = 0;
    timer->interval = interval;
    timer->value = (countdown != 0) ? countdown : interval;
    timer->mq = mq;
    timer->msg = msg;

    time = __osInsertTimer(timer);
    if (__osTimerList->next == timer) {
        __osSetTimerIntr(time);
    }

    return 0;
}
