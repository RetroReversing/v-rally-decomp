extern int gRecords;
s32 slot_set_selected();
extern void *gSelectState;
extern char gStreamState[];

/* Toggles bit 0 of the flags byte (+0x48) of the currently selected record (0x28
 * bytes each, index at gSelectState+0x22A), then sets slot 0x1C to that bit. */
s32 func_80067248(void)
{
  u8 temp_v1;
  u8 var_v0;
  char *new_var;
  void *temp_a0;
  temp_a0 = gRecords + ((*((s8 *) (((char *) gSelectState) + 0x22A))) * 0x28);
  temp_v1 = *((u8 *) (((char *) temp_a0) + 0x48));
  if (temp_v1 & 1)
  {
    var_v0 = temp_v1 & 0xFE;
  }
  else
  {
    var_v0 = temp_v1 | 1;
  }
  *((u8 *) (((char *) temp_a0) + 0x48)) = var_v0;
  new_var = ((char *) (gRecords + ((*((s8 *) (((char *) gSelectState) + 0x22A))) * 0x28))) + 0x48;
  slot_set_selected(0x1C, (((u8) (*((u8 *) new_var))) >> 0) & 1);
  return 0;
}
