typedef s32 OSPri;
typedef s32 OSId;

typedef struct OSThread_s {
    struct OSThread_s    *next;
    OSPri                 priority;
    struct OSThread_s   **queue;
    struct OSThread_s    *tlnext;
    u16                   state;
    u16                   flags;
    OSId                  id;
    int                   fp;
    void                 *thprof;
    u8                    context[0x1A0];
} OSThread;

extern OSThread *D_800A2520;
extern OSThread *D_800A2518;
u32 osDisableInt(void);
void osRestoreInt(u32);
void func_8008B4D4(OSThread **);
void func_8008B5DC(OSThread **, OSThread *);
OSThread *func_8008B624(OSThread **);
void func_8008B634(void);

/* Makes a thread runnable. A stopped thread goes straight onto the run queue; a
   thread that is waiting on a queue is moved to the run queue. If the running
   thread has lower priority than the new head of the run queue, it is preempted.
   Runs with interrupts disabled. */
void osStartThread(OSThread *thread) {
    register u32 saved_int_mask = osDisableInt();

    switch (thread->state) {
        case (1 << 3):
            thread->state = (1 << 1);
            func_8008B5DC(&D_800A2518, thread);
            break;
        case (1 << 0):
            if (thread->queue == 0 || thread->queue == &D_800A2518) {
                thread->state = (1 << 1);
                func_8008B5DC(&D_800A2518, thread);
            } else {
                thread->state = (1 << 3);
                func_8008B5DC(thread->queue, thread);
                func_8008B5DC(&D_800A2518, func_8008B624(thread->queue));
            }
            break;
    }

    if (D_800A2520 == 0) {
        func_8008B634();
    } else if (D_800A2520->priority < D_800A2518->priority) {
        D_800A2520->state = (1 << 1);
        func_8008B4D4(&D_800A2518);
    }

    osRestoreInt(saved_int_mask);
}
