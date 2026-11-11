extern s32 gCarList, gRaceState;
extern u8 D_800C8308;
extern void *gRecords;
extern void func_80021AB8();
extern void func_8005322C();
extern void func_80053784();
extern void records_restore_from_order();
extern void clearRaceData();

/* Per-frame race-state update. When the state is not 2..3 or 5, runs the
   handler for the record's mode at +0x1E and moves to the next state; while in
   state 2..3, runs the follow-up step for modes 1..4. Then updates the car list. */
void updateRaceState(void) {
    u16 mode;
    s32 mode32;
    if ((u32)(gRaceState - 2) >= 2 && gRaceState != 5) {
        mode32 = *(u16 *)((u8 *)gRecords + 0x1e);
        gRaceState = 0;
        switch (mode32) {
        case 5:
            func_8005322C();
            break;
        case 0:
            clearRaceData();
            gRaceState = 2;
            break;
        case 1: case 2: case 3: case 4:
            func_80053784();
            break;
        }
        D_800C8308 = 0;
    }
    if ((u32)(gRaceState - 2) < 2) {
        mode = *(u16 *)((u8 *)gRecords + 0x1e);
        if ((mode != 0) & (mode < 5))
            records_restore_from_order();
    }
    func_80021AB8(gCarList);
}
