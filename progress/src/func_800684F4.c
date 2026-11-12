extern void *gSelectState;
extern s32 D_800A1630;
extern u8 gOrderState[];
extern char stream_state[];
extern void records_apply_slot(s32);
extern s32 unpackRecord(u8);
extern s32 select_group_set_value(s32, s32);
extern s32 func_80068130(void);
extern s32 func_8006F424(void);
extern s32 buildLinkPacket(void);

/* Re-checks the selection (byte at +0x229 of gSelectState) against the two 4-bit fields of
 * stream_state's word at +0x6E62 (the low nibble too when bits 8-9 equal 2). On a mismatch
 * it clears the state at gOrderState+0x7FCA and rebuilds the link packet. Then it applies
 * the selection, clears the flag at +0x24D and returns 0. */
s32 func_800684F4(void)
{
  s32 mismatch;
  s32 needReset;
  s8 selected;

  selected = *(s8 *)((char *)gSelectState + 0x229);
  mismatch = (((u32) *(u32 *)((char *)stream_state + 0x6E62) >> 4) & 0xF) != selected;
  needReset = mismatch;
  if ((((u32) *(u32 *)((char *)stream_state + 0x6E62) >> 8) & 3) == 2) {
    needReset = mismatch & -((*(u32 *)((char *)stream_state + 0x6E62) & 0xF) != selected);
  }
  if (!(needReset & 0xFF)) {
    *(s8 *)((char *)gOrderState + 0x7FCA) = 0;
    func_8006F424();
    buildLinkPacket();
  }
  records_apply_slot((u8) *(s8 *)((char *)gSelectState + 0x229));
  unpackRecord((u8) *(s8 *)((char *)gSelectState + 0x229));
  select_group_set_value(0, 0);
  *(s8 *)((char *)gSelectState + 0x24D) = 0;
  D_800A1630 = func_80068130();
  return 0;
}
