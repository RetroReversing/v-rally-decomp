s32 format_to_buffer();
extern u32 gRecordTimeScale;
extern char D_800A4B20[];

/* Writes a race time into buf as minutes, seconds and hundredths. time is in
   timer ticks (gRecordTimeScale ticks per second). Times of 10 minutes or more
   are shown as 0. */
void format_time_text(u32 time, s32 buf)
{
    u32 totalTicks;
    u16 minutesU16;
    u16 seconds;
    u16 minutes;
    u16 hundredths;
    minutes = time / ((u32) (gRecordTimeScale * 0x3C));
    minutesU16 = minutes;
    totalTicks = minutesU16 * 0x3C; totalTicks = time - (totalTicks * gRecordTimeScale);
    seconds = totalTicks / ((u32) gRecordTimeScale);
    hundredths = ((u32) ((totalTicks - (seconds * gRecordTimeScale)) * 0x64)) / ((u32) gRecordTimeScale);
    if (minutesU16 >= 0xA)
    {
        hundredths = (seconds = (minutes = 0));
    }
    format_to_buffer(buf, &D_800A4B20, minutes, seconds, hundredths);
}
