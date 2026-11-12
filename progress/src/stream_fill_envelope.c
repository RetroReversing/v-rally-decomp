extern u8 stream_state[];

/* Fills one channel's 0x81-byte envelope row in stream_state. The track holds
   envelope points (0x4C bytes apart, from offset 0xDF) and a point count at 0x44.
   Each segment is linearly interpolated over 10 steps, clamped to 0x7F. The row's
   last byte gets the final point's level. */
void stream_fill_envelope(u8 *track, u8 channel)
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
      stream_state[0x5BAA + channel * 0x81 + out] = prev + step * (cur - prev) / 10;
      if (stream_state[0x5BAA + channel * 0x81 + out] >= 0x80) stream_state[0x5BAA + channel * 0x81 + out] = 0x7F;
      if (out < 0x80) out++;
    }
  }
  stream_state[0x5C2A + channel * 0x81] = cur;
}
