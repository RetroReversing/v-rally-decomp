s32 select_reset_text();
s32 func_80066B88();
s32 glyph_record_pack();
s32 save_race_to_pak();
extern void *gSelectState;
extern s32 select_init_screen;
extern s32 func_80066EBC;
static inline s8 *inline_fn(char *arg0)
{
  return (s8 *) arg0;
}

/* Resets the select screen state in gSelectState: clears the flag bytes at 0x245 and 0x24D,
 * sets the slot at 0x22B to -1 (no selection), and installs the init and update handlers
 * in the two callback slots at 0x288 and 0x28C. */
s32 SelectStateReset(s32 arg0, s32 arg1)
{
  char *base2;
  char *base;
  int invalid;
  func_80066B88();
  glyph_record_pack(*((u8 *) (((char *) gSelectState) + 0x228)));
  save_race_to_pak();
  select_reset_text(arg0, arg1);
  invalid = -1;
  ;
  base2 = (char *) gSelectState;
  *inline_fn(base2 + 0x245) = 0;
  base = (char *) gSelectState;
  *((s32 **) (base2 + 0x288)) = &select_init_screen;
  *((s32 **) (base2 + 0x28C)) = &func_80066EBC;
  *inline_fn(base + 0x22B) = invalid;
  *inline_fn(((char *) gSelectState) + 0x24D) = 0;
  return 0;
}
