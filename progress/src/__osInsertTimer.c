typedef u64 OSTime;
typedef void *OSMesg;
typedef struct OSMesgQueue_s { void *mtqueue; void *fullqueue; s32 validCount; s32 first; s32 msgCount; OSMesg *msg; } OSMesgQueue;
typedef struct OSTimer_s { struct OSTimer_s *next; struct OSTimer_s *prev; OSTime interval; OSTime value; OSMesgQueue *mq; OSMesg msg; } OSTimer;
extern OSTimer *__osTimerList;
extern u32 osDisableInt(void);
extern void osRestoreInt(u32);

/* Inserts timer t into the sorted timer list __osTimerList (a circular list with a sentinel
 * head). Each entry's value is the delay after the previous one, so t->value is made
 * relative to the entries before it. Returns the relative delay stored in t. Interrupts
 * are masked around the list update. */
OSTime __osInsertTimer(OSTimer* t) {
    OSTimer* timep;
    OSTime tim;
    u32 savedMask = osDisableInt();

    timep = __osTimerList->next;
    tim = t->value;
    for (; timep != __osTimerList && tim > timep->value; timep = timep->next) {
        tim -= timep->value;
    }

    t->value = tim;

    if (timep != __osTimerList) {
        timep->value -= tim;
    }

    t->next = timep;
    t->prev = timep->prev;
    timep->prev->next = t;
    timep->prev = t;
    osRestoreInt(savedMask);
    return tim;
}
