extern u8 *gSelectState;
extern u8 stream_state[];
void *select_get_entry(u32);
extern void slotSetSelected(s32 arg0, s32);
extern void select_mark_pending(s32);
extern void record_set_byte9(void *, s32, s32);

/* Looks up this select-state's stream record (0x28 bytes each, index at +0x22A). If its 0x10 flag is
 * set, clears it, sends sound/event 0x17 and writes a 6-byte record from the select state's
 * sub-block (bytes 0xB..0xD) to select_get_entry's buffer; otherwise calls select_mark_pending. Returns 0. */
s32 func_80068D9C(s32 arg0)
{
  u8 *rec;
  u8 *obj;
  u8 *p;
  u8 v;
  obj = gSelectState;
  rec = (*((u8 **) (stream_state + 0x32F2))) + ((*((s8 *) (obj + 0x22A))) * 0x28);
  v = rec[0x48];
  if (v & 0x10)
  {
    p = *((u8 **) (obj + 0xC));
    rec[0x48] = v & 0xEF;
    obj = p + 4;
    record_set_byte9(*((void **) (stream_state + 0x325A)), 0x17, 1);
    p = select_get_entry(6);
    p[0xF] = obj[0xB];
    p[0x10] = obj[0xC];
    p[0x11] = obj[0xD];
    slotSetSelected(arg0, 0);
  }
  else
  {
    select_mark_pending(arg0);
  }
  return 0;
}
