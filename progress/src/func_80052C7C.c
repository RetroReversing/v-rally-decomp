extern u8 gOrderState;
extern u16 D_800D0628;
extern u8 *D_800D0648;

/* Walks the order entries (count in D_800D0628, 0x2C4 bytes apart, starting at the entry
 * base +0x10): clears flag bit 1 on each, sets it again when the matching gOrderState
 * halfword is nonzero, and returns how many were set. */
s32 func_80052C7C(void)
{
  u16 *count_ptr;
  s32 pad;
  u32 i;
  s32 count;
  u8 *pp;
  u8 *base;
  u8 *p;
  u8 *flag;
  u16 enabled;
  (void) (&pad);
  i = 0;
  enabled = D_800D0628;
  pp = (u8 *) (&D_800D0648);
  base = *((u8 **) pp);
  count = 0;
  if (enabled)
  {
    count_ptr = (u16 *) (pp - 0x20);
    flag = (&gOrderState) + 0x7DB0;
    p = base + 0x10;
    do
    {
      u16 v = (*((u16 *) p)) & 0xFFFD;
      *((u16 *) p) = v;
      if (*((u16 *) (flag + 0x10)))
      {
        *((u16 *) p) = v | 2;
        count++;
      }
      p += 0x2C4;
      i++;
      flag += 2;
    }
    while (i < (*count_ptr));
  }
  return count;
}
