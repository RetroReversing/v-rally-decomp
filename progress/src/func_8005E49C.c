typedef struct LayoutRecord { s32 a; u8 b; u8 pad[3]; s32 c; } LayoutRecord;
typedef struct Entry { void (*fn)(s32,s32,s32); LayoutRecord *data; u8 count,a,b,pad; } Entry;
typedef struct Inner { void (*fn)(void); LayoutRecord *data; Entry *subs; u8 count,start,cur,extra; s32 zero; } Inner;
typedef struct Root { u16 n; s16 a; u16 b,pad; s32 c,d; Inner *inner; u8 e; u8 padding[3]; } Root;
typedef struct G1468
{
  unsigned char pad0[0x1F8];
  s32 x1f8;
  s32 x1fc;
  s8 x200;
  unsigned char pad201[0x8b];
  void (*cb)(void);
} G1468;
typedef struct A5474
{
  s32 a;
  s32 b;
  s8 c;
} A5474;
extern Root *gLeague;
extern s32 gSelectStep;
extern void *gSelectStepHandle;
extern G1468 *gSelectState;
extern s32 D_800A14BC[];
extern A5474 D_800A5474;
extern void func_8002FB64(void);
extern void setSoundEntryTable(s32);
extern void *func_80057810(s32);
extern void func_800578E0(void *);
extern s32 func_8005A338();
extern void func_8005E1B8(void);
extern void func_8006ECB4(void);
extern s32 save_race_to_pak(void);
extern void func_80084AD8(void);
extern void func_80084AF4(void);
extern s32 func_80084DD4(s32);
extern u8 func_80084E10(void);
extern s32 cont_port_is_connected(s32, s32);
extern void func_8005E820(void);

/* Starts a league stage: picks the stage index from the inner table's cursor,
 * reloads the stage's resources, and, if every entry in the stage list passes
 * its check, sets up the stage's records and enters the stage. Otherwise it
 * only runs the common start and installs the fallback callback. */
s32 func_8005E49C(s32 arg0, s32 arg1)
{
  s32 i;
  s32 idx;
  s32 all_ok;
  s32 total;
  Inner *inner_arr;
  u8 *new_var;
  Inner *inner;
  LayoutRecord *rec;
  inner_arr = gLeague->inner;
  gSelectStep = (inner_arr[3].cur - inner_arr[3].start) + 1;
  setSoundEntryTable(gSelectStep & 0xFF);
  all_ok = 1;
  func_8006ECB4();
  idx = 0;
  save_race_to_pak();
  func_800578E0(gSelectStepHandle);
  gSelectStepHandle = func_80057810(D_800A14BC[gSelectStep]);
  {
    u8 count = func_80084E10();
    if (count)
    {
      total = count;
      do
      {
        i = idx & 0xFF;
        if (func_80084DD4(i))
        {
          all_ok &= -(cont_port_is_connected(i, 2) != 0);
        }
        idx++;
      }
      while (((u32) (idx & 0xFF)) < ((u32) total));
    }
  }
  if (all_ok & 0xFF)
  {
    idx = 0;
    func_80084AF4();
    func_80084AD8();
    func_8002FB64();
    inner = gLeague->inner;
    do
    {
      rec = gLeague->inner[3].subs[idx & 0xFF].data;
      rec[3].c = 5;
      idx++;
    }
    while (((u32) (idx & 0xFF)) < 3);
    new_var = ((u8 *) gSelectState) + 0x1F8;
    gLeague->inner[0].data[2].c = 5;
    __builtin_memcpy(&gSelectState->x1f8, &D_800A5474, 9);
    func_8005A338(arg0, arg1);
    func_8005E1B8();
  }
  else
  {
    func_8005A338(arg0, arg1);
    gSelectState->cb = func_8005E820;
  }
  return 0;
}
