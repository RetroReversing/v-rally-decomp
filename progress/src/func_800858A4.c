#ifdef PORT
extern u8 *gControllerInputContext;
#else
extern s32 gControllerInputContext;
#endif

/* For mode 2 only: if the state word at [1] of the object in slot slot (pointer at gControllerInputContext+slot*4+0x38C)
   is 1, clears its word [2], stores value in its byte at 0x14, and returns 1. Otherwise returns 0. */
s32 func_800858A4(u8 slot, u8 mode, u8 value)
{
  s32 *state;
#ifdef PORT
  u8 *slotOffset;
#else
  s32 slotOffset;
#endif

  if (mode != 2)
  {
    return 0;
  }
  #ifdef PORT
  slotOffset = gControllerInputContext + (slot * 4);
#else
  slotOffset = (slot * 4) + gControllerInputContext;
#endif
  state = *(s32 **)(slotOffset + 0x38C);
  if (state[1] != 1)
  {
    return 0;
  }
  state[2] = 0;
  *(u8 *)((char *)*(s32 **)(slotOffset + 0x38C) + 0x14) = value;
  return 1;
}
