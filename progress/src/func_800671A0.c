extern int gRecords;
s32 select_reset_text();
s32 func_8006F0E0();
s32 save_race_to_pak();
extern void *gSelectState;
extern char gStreamState[];
extern s32 func_80069648;
extern s32 func_80069690;

/* Adds a signed byte to a base index. */
static inline int addSignedIndex(int base, s8 index)
{
  return base + index;
}

/* Select-state setup: when the stream record's type (+2) is 5, sets the sound for the select
 * index at +0x228, then clears the flags at +0x245 and +0x24D and installs the two callbacks
 * at +0x288 and +0x28C. */
s32 func_800671A0(s32 arg0, s32 arg1)
{
  void *select;
  void *select2;
  if ((*((s16 *) (((char *) (*((void **) (gStreamState + 0x325A)))) + 2))) == 5)
  {
    func_8006F0E0(*((u8 *) (((char *) addSignedIndex(gRecords, *((s8 *) (((char *) gSelectState) + 0x228)))) + 0x32)));
    save_race_to_pak();
  }
  select_reset_text(arg0, arg1);
  select = gSelectState;
  *((s8 *) (((char *) select) + 0x245)) = 0;
  select2 = gSelectState;
  *((s32 **) (((char *) select) + 0x288)) = &func_80069648;
  *((s32 **) (((char *) select) + 0x28C)) = &func_80069690;
  *((s8 *) (((char *) select2) + 0x24D)) = 0;
  return 0;
}
