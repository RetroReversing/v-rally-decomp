void init_cars_from_records(void);
void func_800857A0(s32);
extern s32 gPadFlags;
extern void *gRaceCtx;

/* Resets the four race slots and clears the race context's +0x384 byte. If the start
 * button bit (0x4000) is held in gPadFlags, the cars are also set up from the records. */
s32 raceResetSlots(void) {
    func_800857A0(0);
    func_800857A0(1);
    func_800857A0(2);
    func_800857A0(3);
    *(s8 *)((u8 *)gRaceCtx + 0x384) = 0;
    if (gPadFlags & 0x4000) {
        init_cars_from_records();
    }
    return 1;
}
