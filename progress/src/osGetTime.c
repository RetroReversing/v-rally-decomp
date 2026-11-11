s32 osDisableInt(); void osRestoreInt(s32); u32 func_800937B0(); extern u8 gOrderState[];

/* Returns the current time: the saved base time at gOrderState+0x7918 plus the cycle count since
 * the base was stored, read with interrupts masked. */
u64 osGetTime(void) {
    s32 saved_mask;
    u32 elapsed;
    u64 base_time;
    saved_mask = osDisableInt();
    elapsed = func_800937B0() - *(u32 *)(gOrderState + 4);
    base_time = *(u64 *)(gOrderState + 0x7918);
    osRestoreInt(saved_mask);
    return base_time + elapsed;
}
