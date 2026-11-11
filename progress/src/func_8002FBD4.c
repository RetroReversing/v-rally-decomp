s32 cont_port_is_connected(s32, s32);
s32 func_800857EC();
extern s32 gPadFlags;
extern void *gRaceCtx;
extern u8 gOrderState[];
extern char gStreamState[];
static inline int inline_fn(u8 **obj)
{
  return (*((s32 *) (*obj))) * 0x10;
}

/* Tries to start the voice in slot *(obj+0x48) with the value arg2; returns early if
 * the slot is busy, the pad input is blocked, or the state says not to start. */
void func_8002FBD4(u8 *obj, s32 channel, s32 value)
{
  s32 idx;
  s32 off;
  u8 s0;
  if ((*((u16 *) ((*((u8 **) (gStreamState + 0x32F2))) + 0x1E))) == 7)
  {
    return;
  }
  if (gPadFlags & 0x800)
  {
    return;
  }
  idx = *((s32 *) (*((u8 **) (obj + 0x48))));
  if (idx >= 4)
  {
    return;
  }
  if ((*((u8 *) (((u8 *) gRaceCtx) + 0x384))) != 0)
  {
    return;
  }
  if ((*((s32 *) ((*((u8 **) (obj + 0x6C))) + 0x34))) != 0)
  {
    return;
  }
  off = idx << 4;
  if (gOrderState[0x239D + off] != 0)
  {
    return;
  }
  if ((*((s32 *) (obj + 0x14))) & 0x100)
  {
    return;
  }
  s0 = gOrderState[0x239C + off];
  if (s0 != cont_port_is_connected(idx & 0xFF, 2))
  {
    *((u8 *) ((gOrderState + 0x239D) + inline_fn((u8 **) (obj + 0x48)))) = 1;
    *((s32 *) ((gOrderState + 0x2394) + inline_fn((u8 **) (obj + 0x48)))) = 0;
  }
  off = (*((s32 *) (*((u8 **) (obj + 0x48))))) << 4;
  if (gOrderState[0x239D + off] != 0)
  {
    return;
  }
  if ((*((s32 *) ((gOrderState + 0x2394) + off))) != 0)
  {
    return;
  }
  *((s32 *) ((gOrderState + 0x2394) + off)) = 1;
  *((u16 *) ((gOrderState + 0x2392) + inline_fn((u8 **) (obj + 0x48)))) = 0;
  *((u8 *) ((gOrderState + 0x2390) + inline_fn((u8 **) (obj + 0x48)))) = value;
  func_800857EC(*((u8 *) ((*((u8 **) (obj + 0x48))) + 3)), 2, channel & 0xFF);
}
