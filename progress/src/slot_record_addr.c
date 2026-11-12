extern u8 *gSlotState;

/* Returns the address of the 0x28-byte record that the byte at gSlotState[(index & 0xFFFF) + 0x32] selects. */
u8 *slot_record_addr(s32 index)
{
  u8 *table = gSlotState;
  u8 *cell = table + (index & 0xFFFF);
  u8 sel = cell[0x32];
  s32 offset = (sel * 5) << 3;
  offset += 0x44;
  return table + offset;
}
