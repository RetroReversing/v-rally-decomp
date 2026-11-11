/* Looks up a point on the track for a distance index. The index is taken from
 * this section (its count is at +0x88, stride at +0x8A, base at +0x4C) when it
 * is below the count, otherwise from the next section at +0x5C. The point's
 * three s16 coordinates are read from the section's point table at +0x54 and
 * written to out, each offset by the section origin (+0x24, +0x28, +0x2C). */
void getTrackPoint(void *arg0, s32 arg1, void *arg2)
{
  s32 pt;
  s32 local;
  u8 *countPtr;
  u16 nextCount;
  void *seg;
  void *next;
  seg = arg0;
  countPtr = ((u8 *) seg) + 0x88;
  if (arg1 < (*((u16 *) (((u8 *) seg) + 0x88))))
  {
    pt = (arg1 * (*((u16 *) (((u8 *) seg) + 0x8A)))) + (*((s32 *) (((u8 *) seg) + 0x4C)));
  }
  else
  {
    local = arg1 - (*((u16 *) countPtr));
    next = *((void **) (((u8 *) seg) + 0x5C));
    nextCount = *((u16 *) (((u8 *) next) + 0x88));
    if (local < nextCount)
    {
      seg = next;
      local += 1;
      pt = (*((s32 *) (((u8 *) seg) + 0x4C))) + (local * (*((u16 *) (((u8 *) seg) + 0x8A))));
    }
    else
    {
      seg = *((void **) (((u8 *) next) + 0x5C));
      local = (local - nextCount) + 2;
      pt = (local * (*((u16 *) (((u8 *) seg) + 0x8A)))) + (*((s32 *) (((u8 *) seg) + 0x4C)));
    }
  }
  *((s32 *) arg2) = (*((s16 *) ((*((u8 **) (((u8 *) seg) + 0x54))) + (pt * 6)))) + (*((s32 *) (((u8 *) seg) + 0x24)));
  *((s32 *) (((u8 *) arg2) + 4)) = (*((s16 *) (((*((u8 **) (((u8 *) seg) + 0x54))) + (pt * 6)) + 2))) + (*((s32 *) (((u8 *) seg) + 0x28)));
  *((s32 *) (((u8 *) arg2) + 8)) = (*((s16 *) (((*((u8 **) (((u8 *) seg) + 0x54))) + (pt * 6)) + 4))) + (*((s32 *) (((u8 *) seg) + 0x2C)));
}
