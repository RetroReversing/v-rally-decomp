extern u8 *gControllerInputContext;

/* Stores two bytes into the controller context entry for `slot` (20-byte entries):
   the pair at +0x5E/+0x60 for flag 0x20000, or at +0x63/+0x65 for flag 0x10000. */
void func_80084EEC(s32 slot, s32 flags, s8 first, s8 second)
{
  unsigned short off;
  if (flags == 0x20000)
  {
    u8 *base = gControllerInputContext;
    off = (slot & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x5E)) = first;
    *((s8 *) ((gControllerInputContext + off) + 0x60)) = second;
  }
  else if (flags == 0x10000)
  {
    u8 *base = gControllerInputContext;
    off = (slot & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x63)) = first;
    *((s8 *) ((gControllerInputContext + off) + 0x65)) = second;
  }
}
