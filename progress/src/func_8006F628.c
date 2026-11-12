void reset_time_records(void);
void unpackAllRecords(void);
void func_8006F3C0(void);
void func_8006F424(void);
void func_8006F5B0(void);
extern s32 gRaceFlags;
extern u8 stream_state[];

/* Race stream reset: writes three marker bytes into the stream state block
   (+0x701F..+0x7021), sets race flag 0x8000, resets the stream channels and
   the time records, then runs the final per-slot pass. */
void func_8006F628(void)
{
    stream_state[0x701F] = 0x44;
    stream_state[0x7020] = 0x45;
    stream_state[0x7021] = 0x1D;
    gRaceFlags |= 0x8000;
    func_8006F5B0();
    func_8006F3C0();
    func_8006F424();
    reset_time_records();
    unpackAllRecords();
}
