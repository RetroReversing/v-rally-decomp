extern unsigned int func_8004D31C();
extern void selectCopyEntryLabel(s32, s32);
extern void func_8006AE34(void);
extern u8 *gSelectState;
extern u8 gStreamPhase;
extern u8 gStreamState[];

/* Resets the select-screen state: installs the update handler at +0x288, sets the mode byte
 * gStreamPhase to 3, and sets the select-screen field +0x228 to the current entry's
 * timing value minus an offset chosen by the stream record's mode (+0x1E). */
s32 func_8006B664(s32 arg0, s32 arg1)
{
  u8 *header;
  u8 *state;
  u8 *rec;
  u8 *element;
  s32 idx;
  s32 offset;
  void **handler;
  s32 mode;

  offset = 0;
  func_8004D31C();
  selectCopyEntryLabel(arg0, arg1);
  header = gSelectState;
  state = *((u8 **) (gStreamState + 0x325A));
  handler = (void **) (header + 0x288);
  *handler = func_8006AE34;
  idx = *((s16 *) (state + 2));

  gStreamPhase = 3;
  element = (*((u8 **) (state + 0x10))) + 20 * idx;
  rec = *((u8 **) (gStreamState + 0x32F2));
  mode = *((u16 *) (rec + 0x1E));
  switch (mode)
  {
    case 0:
      offset = 25;
      break;

    case 1:
    case 2:
    case 3:
    case 4:
      offset = 15;
      break;

    case 5:
      offset = 38;
      break;
  }

  *((u8 *) (gSelectState + 0x228)) = element[0xE] - offset;
  return 1;
}
