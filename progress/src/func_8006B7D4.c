s32 text_load_and_parse();
s32 race_reset_and_save();
s32 func_8006E33C();
s32 func_8006F5E8();
s32 func_8006F628();
s32 func_8006F69C();
s32 func_8006F7F8();
s32 func_8006F8E0();
s32 stream_refresh_car_flags();
s32 func_80084AFC();
s32 func_80084B50();
s32 func_80084BF0();
s32 func_80084DD4();
s32 osEepromProbe();
extern s32 gRaceFlags;
extern s8 D_800A16F0;
extern char D_800A57C0[];
extern char gOrderState[];

/* Start-up for the save data: clears the pending flag and bit 15 of gRaceFlags, initialises
 * the save block, and probes the EEPROM. With no EEPROM it falls back to the default path
 * and returns 0; otherwise it loads and checks the save slots and returns 1. */
s32 func_8006B7D4(void) {
    D_800A16F0 = 0;
    gRaceFlags &= 0xFFFF7FFF;
    text_load_and_parse(&D_800A57C0, 0);
    func_80084AFC();
    if (osEepromProbe(gOrderState + 0x5A38) != 1) {
        func_8006F628();
        return 0;
    }
    func_80084B50();
    func_8006F69C();
    if ((func_80084DD4(3) != 0) && (func_80084BF0(3) & 0xA000)) {
        func_8006F7F8();
    }
    if (func_8006F5E8() == 0) {
        race_reset_and_save();
    } else {
        func_8006F8E0();
    }
    func_8006E33C();
    stream_refresh_car_flags();
    return 1;
}
