s32 slot_set_selected();
s32 stream_refresh_car_flags();
extern char gStreamState[];

/* Claims the first clear bit (0..3) in the flag byte at +0x2F of the current stream slot
 * and sets it. Then refreshes the car flags and selects the slot index. Always returns 0. */
s32 func_80060054(void)
{
  s32 slot_index;
  s32 pad_count;
  s32 bit_shift;
  s32 flag_value;
  long pad;
  u8 flags;
  short one;
  void *slot;
  slot_index = 0;
  pad_count = 1;
  one = 1;
  loop_1:
  slot = gStreamState + 0x32F2;

  slot = *((void **) (gStreamState + 0x32F2));
  flags = *((u8 *) (((char *) slot) + 0x2F));
  bit_shift = slot_index & 0xFF;
  flag_value = (flag_value = (s32) flags) >> bit_shift;
  flag_value &= 1;
  slot_index += 1;
  if (flag_value == 0)
  {
    do
    {
      flag_value = one << bit_shift;
    }
    while (0);
    flag_value |= flags;
    *((u8 *) (((char *) slot) + 0x2F)) = (u8) flag_value;
  }
  else
  {
    flag_value = slot_index & 0xFF;
    flag_value = ((u32) flag_value) < 4U;
    if (flag_value != 0)
    {
      goto loop_1;
    }
  }
  stream_refresh_car_flags(flags, slot, one);
  flags = 0x1C;
  slot = (void *) (slot_index & 0xFF);
  slot_set_selected(0x1C, slot);
  flag_value = 0;
  return 0;
}
