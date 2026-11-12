#define H(p,o) (*(s16 *)((u8*)(p)+(o)))
#define U(p,o) (*(u16 *)((u8*)(p)+(o)))
#define A(p,o) (*(u8 **)((u8*)(p)+(o)))
typedef struct Blob
{
  s32 words[177];
} Blob;
extern u8 *gSelectState;
extern u8 *gLeague;
extern u8 *gRecords;
extern u8 D_800A161C[];
extern u8 D_800A1620;
extern s32 D_800AFA58;
extern Blob *gSlotTableB[];
extern void select_clear_slots(void);
extern void func_8005BB5C(void);
extern void func_80065860(void);
extern void func_80065C04(void);
extern void func_80062304(void *, s16);
extern void func_8005937C(s32, u16);
extern void func_8008A0D8(void *, u16, s32);
extern void func_8008A1CC(void *, u16, s32, void *);
void *select_get_entry(u32);
extern void func_80061740(Blob);

/* Season setup for the league screen: resets the record and state blocks, sets
 * up the four league slots (mode 2 uses the second bank of slots), and installs
 * the per-slot callback. Then loads the track blob chosen in the state block. */
void func_8006556C(void)
{
  Blob blob;
  s32 i;
  s32 k;
  s32 val;
  s16 leagueMode;
  u8 *p;
  u8 *q;
  select_clear_slots();
  func_8005BB5C();
  {
    u8 *records = gRecords;
    u8 *state = gSelectState;
    U(records, 0x20) = 0;
    state[0x23c] = D_800A1620;
  }
  {
    u8 *league = gLeague;
    leagueMode = H(league, 2);
    if (leagueMode == 2)
    {
      A(league, 0x10)[(2 * 20) + 0xE] = gRecords[0x21] + 9;
    }
    else
    {
      u8 *entry = A(league, 0x10);
      entry[(leagueMode * 20) + 0xE] = 4 + gRecords[0x21];
      func_80062304(entry, leagueMode);
    }
  }
  i = 0;
  val = 80;
  D_800AFA58 = U(gRecords, 0x20);
  do
  {
    if (H(gLeague, 2) == 2)
    {
      func_8005937C(i + 9, U(gSlotTableB[D_800A161C[i + 4]], 0x14));
    }
    else
    {
      func_8005937C(i + 4, U(gSlotTableB[D_800A161C[i + 4]], 0x14));
    }
    if ((i != 0) && ((U(gRecords, 0x2a) & (0x1000 << (i - 1))) != (0x1000 << (i - 1))))
    {
      func_8008A0D8(gLeague, i + 9, 0);
      func_8008A0D8(gLeague, i + 4, 0);
      p = select_get_entry(i);
      if (i != 3)
      {
        p[0xf] = 80;
        p[0x10] = 80;
        p[0x11] = 80;
      }
      else
      {
        k = 3;
        q = p + 6;
        do
        {
          q[0x41] = 0;
          q -= 2;
        }
        while ((--k) >= 0);
      }
    }
    func_8008A1CC(gLeague, (H(gLeague, 2) == 2) ? (i + 9) : (i + 4), 16, func_80065C04);
    i++;
  }
  while (i < 4);
  if (H(gLeague, 2) == 1)
  {
    *((void **) (gSelectState + 0x28c)) = func_80065860;
  }
  blob = *gSlotTableB[gSelectState[0x23c]];
  func_80061740(blob);
}
