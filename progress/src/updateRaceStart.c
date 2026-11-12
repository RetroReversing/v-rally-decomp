extern s32 gRaceFlags;
extern s32 gPadFlags;
extern s32 gRaceState;
extern char stream_state[];
extern char *gRaceCtx;
extern void race_reset();
extern void init_cars_from_records();
extern void clearRaceData();
extern s32 func_80049DB0();
typedef struct { char pad0[0x1e]; u16 state; char pad20[0x16]; u16 f36; } RaceObj;

/* Per-frame race start check: clears the race flags and the slot's pending
 * flag, then, while the race is still in the start phase, runs race_reset once
 * the start data is ready. Returns 0 when the race was reset, 1 otherwise. */
s32 updateRaceStart(void)
{
  RaceObj *p;
  int a;
  s32 z;
  gRaceFlags = (gRaceFlags | 3) & ~8;
  p = *((RaceObj **) (stream_state + 0x32F2));
  a = p->state;
  p->f36 = 0;
  if ((a == 5) | (a == 0) || (z = (a >> 16) == 0))
  {
    u16 b = p->state;
    gRaceState = 2;
    if (b == 0 && (u8)func_80049DB0() == 1)
    {
      race_reset();
      clearRaceData();
      gRaceCtx[0x384] = 0;
      return 0;
    }
  }
  else
  {
    gRaceState = 5;
  }
  gRaceCtx[0x384] = 0;
  if (gPadFlags & 0x4000)
  {
    init_cars_from_records();
  }
  *(u8 *)(stream_state + 0x7E72) = 0;
  return 1;
}
