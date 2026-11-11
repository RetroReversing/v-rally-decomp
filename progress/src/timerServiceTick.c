extern unsigned char gTimerStarted;
extern void (*gTimerCallback)(void);
extern long long D_800C6080;
long long osGetTime(void);

/* Records the start time on the first tick, then calls the timer callback. */
void timerServiceTick(void) {
    if (gTimerStarted == 0) {
        D_800C6080 = osGetTime();
        gTimerStarted = 1;
    }
    gTimerCallback();
}
