extern u8 gStreamState[];

/* Fills one channel's 0x81-byte envelope row in gStreamState. The track holds
   envelope points (0x4C bytes apart, from offset 0xDF) and a point count at 0x44.
   Each segment is linearly interpolated over 10 steps, clamped to 0x7F. The row's
   last byte gets the final point's level. */
void func_80020098(u8 *track, u8 channel)
{
  u8 seg, step, out;
  u8 prev, cur;
  u8 *dst;
  out = 0;

  cur = track[0x93];
  for (seg = 0; seg < *(s32 *)(track + 0x44) - 1; seg++)
  {
    prev = cur;
    cur = track[seg * 0x4C + 0xDF];
    for (step = 0; step < 10; step++)
    {
      gStreamState[0x5BAA + channel * 0x81 + out] = prev + step * (cur - prev) / 10;
      if (gStreamState[0x5BAA + channel * 0x81 + out] >= 0x80) gStreamState[0x5BAA + channel * 0x81 + out] = 0x7F;
      if (out < 0x80) out++;
    }
  }
  gStreamState[0x5C2A + channel * 0x81] = cur;
}
