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
extern u32 D_800C3634;
extern u32 osGetCount(void);
extern void osSetCompareRegister(u32);
extern void __osSetTimerIntr(OSTime);
extern OSTime __osInsertTimer(OSTimer *);
extern void osSendMesg(OSMesgQueue *, OSMesg, s32);

/* Runs on the compare interrupt. Fires every timer whose time has come and reprograms the compare register for the next one. Periodic timers are re-inserted. */
void __osTimerInterrupt(void) {
    OSTimer *timer;
    u32 count;
    u32 elapsed;

    if (__osTimerList->next == __osTimerList) {
        return;
    }
    for (;;) {
        timer = __osTimerList->next;

        if (timer == __osTimerList) {
            osSetCompareRegister(0);
            D_800C3634 = 0;
            break;
        }

        count = osGetCount();
        elapsed = count - D_800C3634;
        D_800C3634 = count;

        if (elapsed < timer->value) {
            timer->value -= elapsed;
            __osSetTimerIntr(timer->value);
            break;
        }

        timer->prev->next = timer->next;
        timer->next->prev = timer->prev;
        timer->next = 0;
        timer->prev = 0;

        if (timer->mq != 0) {
            osSendMesg(timer->mq, timer->msg, 0);
        }

        if (timer->interval != 0) {
            timer->value = timer->interval;
            __osInsertTimer(timer);
        }
    }
}
