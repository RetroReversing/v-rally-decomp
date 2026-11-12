s32 osDisableInt();
void osRestoreInt(s32);
extern void *viCurrent;

/* Sets the VI controller's Y scale and turns on the scale enable bit, with interrupts off. */
void osViSetYScale(f32 yScale)
{
    s32 savedInt;

    savedInt = osDisableInt();
    *(f32 *)((s8 *)viCurrent + 0x24) = yScale;
    *(u16 *)((s8 *)viCurrent + 0) = (u16)(*(u16 *)((s8 *)viCurrent + 0) | 4);
    osRestoreInt(savedInt);
}
