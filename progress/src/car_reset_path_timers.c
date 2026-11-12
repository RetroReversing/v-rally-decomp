typedef struct CarPathState { u8 pad00[4]; s16 x, y; u8 pad08[0xC]; u8 timer14, timer15, timer16, timer17; } CarPathState;
typedef struct CarRecord { u8 pad00[0x78]; CarPathState *path; } CarRecord;
/* Resets the path timers of a car on an in-track path point: bytes 0x15/0x16 go to zero, 0x14/0x17 to 50. */
void car_reset_path_timers(void *car) { ((CarRecord *)car)->path->timer15 = 0; ((CarRecord *)car)->path->timer16 = 0; ((CarRecord *)car)->path->timer14 = 0x32; ((CarRecord *)car)->path->timer17 = 0x32; }
