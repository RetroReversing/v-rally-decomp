s32 slot_set_selected();
extern char gStreamState[];

/* Picks the next selection step for the current select entry: sets flag 0x1000
 * (step 1), then 0x2000 (step 2), then 0x4000 (step 3), whichever is still
 * clear, and reports the step to slot 0x1B. Always returns 0. */
s32 func_8005FF70(void)
{
    s32 step;
    u16 flags;

    flags = *((u16 *) (((char *) *(void **) (gStreamState + 0x32F2)) + 0x2A));
    if (!(flags & 0x1000)) {
        *((u16 *) (((char *) *(void **) (gStreamState + 0x32F2)) + 0x2A)) = (u16) (flags | 0x1000);
        step = 1;
    } else if (!(flags & 0x2000)) {
        *((u16 *) (((char *) *(void **) (gStreamState + 0x32F2)) + 0x2A)) = (u16) (flags | 0x2000);
        step = 2;
    } else {
        step = 3;
        if (!(flags & 0x4000)) {
            *((u16 *) (((char *) *(void **) (gStreamState + 0x32F2)) + 0x2A)) = (u16) (flags | 0x4000);
        }
    }
    slot_set_selected(0x1B, step);
    return 0;
}
