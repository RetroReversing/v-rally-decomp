extern u8 *gControllerInputContext;

/* Maps a slot's current level onto a signed gain (-128..127). Mode 0x10000
 * and 0x20000 select which pair of bound thresholds in the slot's table entry
 * apply. Returns 0 when the level is outside the active range and 0x7F/-0x80
 * when it is past the lower/upper bound. */
s8 input_get_stick_axis(s32 slot, s32 mode)
{
  s32 pad[1];
  signed char *ent;
  signed char level;
  int lo;
  int cur;
  signed char b;
  s32 hi;
  int d;
  u8 *base;
  u8 *tbl;
  u8 idx;
  s32 t;
  if (mode != 0x10000)
  {
    if (mode != 0x20000)
    {
      return 0;
    }
    base = gControllerInputContext;
    idx = slot;
    cur = (level = *((signed char *) ((base - (-(idx * 6))) + 0x1E)));
    ent = (signed char *) (gControllerInputContext + (idx * 20));
    lo = ent[0x5F];
    t = lo + ent[0x60];
    if (cur >= t)
    {
      lo = ent[0x5C];
      hi = t;
    }
    else
    {
      t = lo + ent[0x5E];
      if (t < cur)
      {
        return 0;
      }
      lo = ent[0x5D];
      hi = t;
    }
  }
  else
  {
    tbl = gControllerInputContext;
    idx = slot;
    cur = (level = *((signed char *) ((tbl - (-(idx * 6))) + 0x1F)));
    do
    {
      ent = (signed char *) (tbl + (idx * 20));
      lo = ent[0x64];
      t = lo + ent[0x65];
    }
    while (0);
    if (cur >= t)
    {
      lo = ent[0x61];
      hi = t;
    }
    else
    {
      t = lo + ent[0x63];
      if (t < cur)
      {
        return 0;
      }
      b = ent[0x62];
      lo = b;
      hi = t;
    }
  }
  if (hi < level)
  {
    if (lo < level)
    {
      return 0x7F;
    }
    if (hi != 0)
    {
      lo -= hi;
      level -= hi;
      hi = 0;
    }
    t = level * 0x7F;
    d = lo - hi;
    t = t / d;
    return t;
  }
  d = level < hi;
  if (d)
  {
    if (level < lo)
    {
      return -0x80;
    }
    if (hi != 0)
    {
      lo -= hi;
      level -= hi;
      hi = 0;
    }
    t = level << 7;
    d = hi - lo;
    t = t / d;
    return t;
  }
  return 0;
}
