s32 osDisableInt();
s32 osRestoreInt(s32);
extern s32 __osGlobalIntMask;

/* Clears the given interrupt bits in the global interrupt mask (keeping bits
 * 0x401 set), with interrupts disabled while the mask is changed. */
void __osResetGlobalIntMask(s32 mask) {
    s32 saved;

    saved = osDisableInt();
    __osGlobalIntMask &= ~mask | 0x401;
    osRestoreInt(saved);
}
