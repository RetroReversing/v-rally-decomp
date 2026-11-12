s32 func_80053F44();
s32 func_800540A0();
s32 func_800544D4();
s32 func_800545E4();
s32 func_80054740();
s32 hiscore_refresh_all();
s32 func_8006ECB4();
s32 save_race_to_pak();
s32 memset();
extern char gOrderState[];

/* Clears the 0x19-byte per-race tally block at gOrderState+0x2530, then runs the
 * per-race bookkeeping passes (points, flags and totals) in the order the race end needs. */
void clearRaceData(void) {
    memset(gOrderState + 0x2530, 0, 0x19);
    func_80053F44();
    func_800540A0();
    func_800544D4();
    func_800545E4();
    hiscore_refresh_all();
    func_80054740();
    func_8006ECB4();
    save_race_to_pak();
}
