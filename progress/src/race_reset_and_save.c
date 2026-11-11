void reset_time_records(void);
void func_8006F3C0(void);
void func_8006F424(void);
void func_8006F5B0(void);
void save_race_to_pak(void);
extern u8 gStreamState[];

/* Writes the three-byte tag 'D' 'E' 0x1D into the stream state at +0x701F, runs
 * the reset steps (func_8006F5B0, func_8006F3C0, func_8006F424, time records)
 * and saves the race to the controller pak. */
void race_reset_and_save(void) {
    *(s8 *)(gStreamState + 0x701F) = 0x44;
    *(s8 *)(gStreamState + 0x7020) = 0x45;
    *(s8 *)(gStreamState + 0x7021) = 0x1D;
    func_8006F5B0();
    func_8006F3C0();
    func_8006F424();
    reset_time_records();
    save_race_to_pak();
}
