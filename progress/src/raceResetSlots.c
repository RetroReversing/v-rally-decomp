void init_cars_from_records(void);
void input_set_all_flags(s32);
extern s32 gPadFlags;
extern void *gRaceCtx;

/* Resets the four race slots and clears the race context's +0x384 byte. If the start
 * button bit (0x4000) is held in gPadFlags, the cars are also set up from the records. */
s32 raceResetSlots(void) {
    input_set_all_flags(0);
    input_set_all_flags(1);
    input_set_all_flags(2);
    input_set_all_flags(3);
    *(s8 *)((u8 *)gRaceCtx + 0x384) = 0;
    if (gPadFlags & 0x4000) {
        init_cars_from_records();
    }
    return 1;
}
