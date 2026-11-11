/* Derives the two 0x32-based offsets stored at +0x15 and +0x16 of the state block (obj+0x78) from the
 * u16 values at +4 and +6 divided by 40, then copies bytes between +0x14, +0x15, +0x16 and +0x17 depending
 * on whether the lo byte (+0xE) is below the hi byte (+0xF). */
void func_80033298(u8 *obj)
{
  u8 *state = *((u8 **) (obj + 0x78));
  u8 *s2;
  s32 v0;
  s32 cond;
  s8 *new_var;
  s32 lo;
  s32 hi;
  u8 *tail;
  *((s8 *) (state + 0x15)) = 0x32 - (((s16) (*((u16 *) (state + 4)))) / 40);
  lo = state[0xE];
  hi = state[0xF];
  cond = lo < hi;
  s2 = *((u8 **) (obj + 0x78));
  *((s8 *) (s2 + 0x16)) = 0x32 + (((s16) (*((u16 *) (s2 + 6)))) / 40);
  if (cond)
  {
    if (hi || obj)
    {
      *((s8 *) ((*((u8 **) (obj + 0x78))) + 0x14)) = (*((u8 **) (obj + 0x78)))[0x16];
      tail = *((u8 **) (obj + 0x78));
      v0 = tail[0x15];
    }
    else
    {
      *((s8 *) ((*((u8 **) (obj + 0x78))) + 0x14)) = (*((u8 **) (obj + 0x78)))[0x16];
      tail = *((u8 **) (obj + 0x78));
      v0 = tail[0x15];
    }
  }
  else
  {
    new_var = (s8 *) ((*((u8 **) (obj + 0x78))) + 0x14);
    *new_var = (*((u8 **) (obj + 0x78)))[0x15];
    tail = *((u8 **) (obj + 0x78));
    v0 = tail[0x16];
  }
  tail[0x17] = v0;
}
