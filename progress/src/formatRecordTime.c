s32 format_to_buffer();
extern u32 gRecordTimeScale;
extern char sRecordTimeFormat[];

/* Formats a race time (ticks at gRecordTimeScale per second) as minutes, seconds and hundredths into buf.
 * Times of a minute or more are clamped to 59.09. */
void formatRecordTime(u32 ticks, char *buf)
{
  s32 minutes;
  u32 remainder;
  u16 seconds;
  u16 hundredths;
  int overflow;

  minutes = ticks / (gRecordTimeScale * 0x3C);
  minutes &= 0xFFFF;
  overflow = minutes != 0;
  minutes = minutes * 0x3C; remainder = ticks - (minutes * gRecordTimeScale);
  seconds = remainder / ((u32) gRecordTimeScale);
  hundredths = ((u32) ((remainder - ((seconds & 0xFFFF) * gRecordTimeScale)) * 0x64)) / ((u32) gRecordTimeScale);
  if (overflow)
  {
    seconds = 0x3B;
    hundredths = 9;
  }
  format_to_buffer(buf, &sRecordTimeFormat, seconds & 0xFFFF, hundredths & 0xFFFF);
}
