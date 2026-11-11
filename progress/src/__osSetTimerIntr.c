typedef u64 OSTime;
typedef struct OSTimer_s OSTimer;
extern u32 osDisableInt(void);
extern void osRestoreInt(u32);
extern u32 func_800937B0(void);
extern void func_800958F0(u32);
extern u32 D_800C3634;

/* Schedules the next timer interrupt: the compare value is the current count plus tim.
 * Interrupts are masked while the compare register is written. */
void __osSetTimerIntr(OSTime tim)
{
    OSTime newCompare;
    u32 savedMask;

    savedMask = osDisableInt();
    D_800C3634 = func_800937B0();
    newCompare = D_800C3634 + tim;
    func_800958F0(newCompare);
    osRestoreInt(savedMask);
}
