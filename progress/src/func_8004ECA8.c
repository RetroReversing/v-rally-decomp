/* Ticks down the countdown in arg0[1] (a value of 1 wraps to 2, which is kept as-is) for a
 * record whose state arg0[0] is not 2 and whose flag arg0[3] is clear. If arg1 is active
 * (arg1[3] set), its countdown arg1[1] is subtracted too. Returns 1 when the countdown has
 * run out or the state is 4, otherwise 0. */
s32 func_8004ECA8(u16 *arg0, u16 *arg1)
{
  s32 remaining;
  s32 done;

  remaining = arg0[1];
  done = 0;
  if (arg0[3] == 0 && arg0[0] != 2)
  {
    if (remaining == 1)
    {
      remaining = 2;
    }
    else
    {
      remaining -= 1;
    }
    if (arg1[3] != 0)
    {
      remaining -= arg1[1];
    }
  }
  if (remaining == 0 || arg0[0] == 4)
  {
    done = 1;
  }
  return done;
}
