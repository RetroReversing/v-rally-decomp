extern unsigned char D_800B6818;
extern int gLeague;void *select_get_entry(u32);
s32 slot_set_selected();
void select_propagate_values(s32, u32, u32);
s32 func_8008A0D8();
extern void *gSelectState;
extern u8 D_800A1700;
extern char gOrderState[];
extern char gStreamState[];

/* Refreshes the select-screen entry for the current stream. If D_800A1700 is 2, or the stream
 * record's byte at +0xE is 2, sets D_800B6818, takes 0x20 off the entry's count and sends
 * select_propagate_values the value at gSelectState+0x14. Then it writes the flag to the entry at +0x41
 * and calls func_8008A0D8 for the league. */
void func_80070A34(void)
{
  s8 flag;
  void *entry;
  void *entryData;
  s32 *selectVal;
  int zero;
  entry = select_get_entry(2);
  zero = 0;
  if ((D_800A1700 == 2) || ((flag = 1, (*((u16 *) (((char *) (*((void **) (gStreamState + 0x32F2)))) + 0xE))) == 2)))
  {
    D_800B6818 = 1U;
    selectVal = (s32 *) (((char *) gSelectState) + 0x14);
    entryData = *((void **) (((char *) entry) + 0));
    flag = zero;
    *((u16 *) (((char *) entryData) + 0xC)) -= 0x20;
    select_propagate_values(2, 1, *selectVal);
  }
  slot_set_selected(7, D_800B6818 == 1);
  *((s8 *) (((char *) entry) + 0x41)) = flag;
  func_8008A0D8(gLeague, 7, flag);
}
