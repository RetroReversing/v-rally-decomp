typedef struct { u8 pad0[0x10]; u16 flags; u8 pad12[0x2C4 - 0x12]; } RCar;
typedef struct { s32 values[0x28]; } Cfg;
typedef struct { u8 pad0[0x44]; Cfg cfg; } Game;
typedef struct {
  s32 totals[4];
  s16 slot_state[12];
  u8 slot_value[12][4];
  s32 tally[17][4];
  s32 extra[4];
  Cfg cfg;
  u8 pad218[2];
  u8 reset_done;
} Race;
typedef struct { u16 count; u8 pad2[0x1E]; u8 *cars; } RaceInfo;
extern RaceInfo D_800D0628;
extern Game *gRecords;

/* Resets the race state: clears the per-car "flag 2" bit, zeroes the totals and tallies,
   sets every slot value to 3, copies the saved settings from gRecords, and marks the
   race as reset. */
void func_800526E4(Race *r)
{
  u32 i;
  u32 j;
  u8 *car;

  for (i = 0; i < 4; i++) r->totals[i] = 0;
  car = D_800D0628.cars;
  for (i = 0; i < D_800D0628.count; i++) {
    ((RCar *)car)->flags &= ~2;
    car += 0x2C4;
  }
  for (i = 0; i < D_800D0628.count; i++) r->slot_state[i] = 0;
  for (j = 0; j < 4; j++) {
    for (i = 0; i < D_800D0628.count; i++) {
      r->tally[i][j] = 0;
      r->slot_value[i][j] = 3;
    }
    r->extra[j] = 0;
  }
  r->cfg = gRecords->cfg;
  r->reset_done = 1;
}
