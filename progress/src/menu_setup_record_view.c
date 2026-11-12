s32 getTexturePack(s32, s32);void *select_get_entry(u32);void *textObjGet(u32);
s32 slotSetSelected(s32, s32);
s32 resolve_path(void *);
s32 record_set_byte9(void *, s32, s32);
extern void *gSelectState;
extern s32 D_800A1658[];
extern s8 D_800A167C[];
extern s8 D_800A1684[];
extern s32 D_800A57A4;
extern char gOrderState[];
extern void *gLeague;
extern void *gRecords;

/* Builds the record-select screen: sets the label x position from the
 * select state, shows or hides the league highlight, loads the 9 entries of
 * D_800A1658 into the table at gOrderState+0x87F8, and copies the 8 nibbles of
 * the selected record's 0x68 bit field into D_800A167C and D_800A1684. */
void menu_setup_record_view(void)
{
  void *label;
  s16 label_x;
  s32 sel;
  void *rec;
  s32 flag;
  void *highlight;
  s32 i;
  s32 slot;
  u32 pieces;
  label = textObjGet(0);
  label_x = 3;
  if ((*(((s8 *) gSelectState) + 0x228)) != 0)
  {
    label_x = 0x98;
  }
  *(((s16 *) label) + 2) = label_x;
  sel = *(((s8 *) gSelectState) + 0x22A);
  rec = ((char *) gRecords) + (sel * 0x28);
  if (((*(((u8 *) rec) + 0x48)) & 0x10) != 0)
  {
    record_set_byte9(gLeague, 0x17, 0);
    highlight = select_get_entry(6);
    *(((s8 *) highlight) + 0xF) = 0x50;
    *(((s8 *) highlight) + 0x10) = 0x50;
    *(((s8 *) highlight) + 0x11) = 0x50;
    slotSetSelected(0x19, 1);
  }
  else
  {
    slotSetSelected(0x19, 0);
  }
  i = 0;
  resolve_path(&D_800A57A4);
  do
  {
    slot = i & 0xFF;
    ((s32 *) (gOrderState + 0x87F8))[slot] = getTexturePack(D_800A1658[slot], 0);
    i += 1;
  }
  while (((u32) (i & 0xFF)) < 9U);
  i = 0;
  sel = *(((s8 *) gSelectState) + 0x22A);
  rec = (char *) gRecords;
  rec = rec + (sel * 0x28);
  pieces = *((u32 *) (((char *) rec) + 0x68));
  do
  {
    s32 k;
    char piece;
    piece = (sel = pieces & 0xF);
    k = i & 0xFF;
    i += 1;
    D_800A167C[k] = (s8) piece;
    D_800A1684[k] = (s8) piece;
    pieces >>= 4;
  }
  while (((u32) (i & 0xFF)) < 8U);
}