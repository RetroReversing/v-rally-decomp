extern u8 stream_state[];
#ifdef PORT
extern u8 *gRecords;
#else
extern s32 gRecords;
#endif
s32 getCounterValue(void *);
void func_80027CFC(void *);
u8 func_80027D24(u8, s32);
u8 func_80027D7C(u8, s32);
s8 func_80027DB4(s8, s32, u8);
s32 getPressedButtonValue(s32);
s8 func_80085714(s32, s32);

/* Refreshes the state bytes of object slot `slot` from its flag word:
 * state[1] gets the 0x10/0x80 flags, state[4] and state[5] are clamped by
 * flags 1 and 2, the object pointer is stored in the slot table, state[0]
 * is the axis value, and state[1] is set from the record's flags. */
void func_80027E8C(void *obj, s32 slot, s8 *state)
{
  u32 flags;
  s8 axis;
  u8 *rec;
  state[1] = 0;
  state[0] = 0;
  flags = getPressedButtonValue(slot & 255);
  state[1] = state[1] & 0xEF;
  if (flags & 0x10) {
    state[1] = state[1] | 0x10;
  }
  if (flags & 0x80) {
    state[1] |= 0x80;
  }
  if (flags & 1) {
    state[4] = func_80027D24(state[4], 255); } else {
    state[4] = func_80027D24(state[4], 0);
  }
  if (flags & 2) {
    state[5] = func_80027D7C(state[5], 255); } else {
    state[5] = func_80027D7C(state[5], 0);
  }
  *(s32 *)(stream_state + 0x8062 + slot * 4) = getCounterValue(obj);
  switch (flags & 0xC) {
  case 4:
    state[0] = func_80027DB4(state[0], -128, slot & 255);
    break;
  case 8:
    state[0] = func_80027DB4(state[0], 127, slot & 255);
    break;
  case 12:
    state[0] = func_80027DB4(state[0], 0, slot & 255);
  default:
    state[0] = func_80027DB4(state[0], 0, slot & 255);
    break;
  }
  axis = func_80085714(slot & 255, 0x200);
  if (axis != 0) {
    state[0] = axis;
  }
  if (*(s32 *)(*(u8 **)((u8 *)obj + 0x24) + 4) != 1) {
    rec = (u8 *)gRecords + *(u8 *)(gRecords + (*(u8 **)((u8 *)obj + 0x48))[3] + 0x32) * 0x28;
    if (rec[0x48] & 0x10) {
      if ((flags & 0x21) == 0x21) {
        state[1] = 0x20;
      }
      if ((flags & 0x21) == 0x20) {
        state[1] = 0x40;
      }
    } else {
      if (flags & 0x20) {
        state[1] = 0x20;
      }
      if (flags & 0x40) {
        state[1] = 0x40;
      }
    }
  }
  func_80027CFC(state);
}
