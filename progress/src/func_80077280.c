#define U16_AT(p, o) (*(u16*)((p)+(o)))
#define S32_AT(p, o) (*(s32*)((p)+(o)))
#define PTR_AT(p, o) (*(u8**)((p)+(o)))
extern u8 gOrderState[];
extern u8 gStreamState[];
extern u8 D_800A5E9C[];
extern u8 *gCarEntries;
extern u8 *D_800A17F4[];
extern u8 *gRecords;
extern int flag_test_bit0(void *);
extern void initRaceSession(void);
extern void resolve_path(void *);
extern u8 *func_80081664(int, void *);
extern u8 *poolAlloc(int, int);
extern void heapFreeBlock(void *);
extern void func_8008E13C(void *, void *, int);
extern void copyStringAligned(void *, void *, int);
typedef struct 
{
  u32 w[61];
} SaveState;
/* Loads the saved-game block for the current slot: a 0x118-byte header, a 6000-byte
 * block and a sized data block, into the working buffers. The saved mode picks the
 * track index; an unknown version word resets the track fields. */
void func_80077280(void)
{
  u8 *saveFile = 0;
  u8 *src;
  u8 *dst;
  u8 *state;
  u8 *allocation;
  u8 i;
  int k;
  long car;
  if (!flag_test_bit0(gOrderState + 0x7320))
  {
    initRaceSession();
  }
  if (flag_test_bit0(gOrderState + 0x7320))
  {
    dst = gCarEntries;
    resolve_path(D_800A5E9C);
    saveFile = func_80081664(1, D_800A17F4[U16_AT(gRecords, 0x22)]);
    src = saveFile;
    __builtin_memcpy(dst, src, 0x118);
    allocation = poolAlloc(1, 6000);
    state = dst;
    PTR_AT(state, 4) = allocation;
    PTR_AT(state, 0) = poolAlloc(1, (S32_AT(state, 16) + 3) & (~3));
    U16_AT(state, 8) |= 1;
    src += 0x118;
    __builtin_memcpy(PTR_AT(state, 4), src, 6000);
    src += 6000;
    U16_AT(state, 12) = 0;
    func_8008E13C(PTR_AT(state, 0), src, (S32_AT(state, 16) + 3) & (~3));
    src += (S32_AT(state, 16) + 3) & (~3);
    *((SaveState *) (gStreamState + 0x7f66)) = *((SaveState *) gRecords);
    __builtin_memcpy(gRecords, src, 0xf4);
    U16_AT(gRecords, 0x1e) = 8;
    for (i = 0; i < 4; i++)
    {
      k = i * 40;
      car = U16_AT(gStreamState, k + 0x7fb4);
      U16_AT(k + gRecords, 0x4e) = car;
      copyStringAligned(gRecords + (k + 0x44), (gStreamState + k) + 0x7faa, car);
    }

    if ((gStreamState[0x7f4f] != 5) && (!(U16_AT(gStreamState, 0x7f92) & 0x800)))
    {
      switch (gStreamState[0x7f4f])
      {
        case 2:
          U16_AT(gRecords, 0x20) = 0;
          U16_AT(gRecords, 0x22) = 3;
          break;

        case 4:
          U16_AT(gRecords, 0x20) = 0;
          U16_AT(gRecords, 0x22) = 6;
          break;

        case 3:

        case 8:
          U16_AT(gRecords, 0x20) = 0;
          U16_AT(gRecords, 0x22) = 1;
          break;

      }

    }
  }
  heapFreeBlock(saveFile);
  {
  u8 *tail = gRecords;
  if (U16_AT(tail, 0x1e) != 8)
  {
    U16_AT(tail, 0x1e) = 8;
    U16_AT(tail, 0x20) = 0;
    U16_AT(tail, 0x22) = 0;
    gStreamState[0x7f4e] = 0;
  }
  }
}
