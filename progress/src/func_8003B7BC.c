s32 format_time_text(s32, void *);
extern u8 gTimeModeChars[];

/* Refreshes a HUD timer digit from its linked target. The time is read from the target's
 * table at +0x6C, indexed by the digit position at +0x76. The HUD flag at +0x80 bit 2
 * marks a digit that shows blank. When the time is zero, the digit shows blank (0xE). */
void func_8003B7BC(void *arg0)
{
  s32 *timeSlot;
  s32 index;
  s32 blankDigit;
  u16 mode;
  s32 flags;
  void *target;

  target = *(void **)((char *)*(void **)((char *)arg0 + 0xA8) + 0x24);
  if (target != NULL)
  {
    timeSlot = (s32 *)**(s32 **)((char *)target + 0x6C);
    index = *(u16 *)((char *)arg0 + 0x76);
    timeSlot = (s32 *)((s32)timeSlot + index * 4);
    if (*(s32 *)((char *)target + 0x14) & 0x100)
    {
      *(s32 *)((char *)arg0 + 0x80) |= 4;
    }
    if (*(u16 *)((char *)arg0 + 0x78) == 0)
    {
      format_time_text(*timeSlot, gTimeModeChars);
    }
    blankDigit = 0xE;
    if (*timeSlot != 0)
    {
      mode = *(u16 *)((char *)arg0 + 0x78);
      flags = *(s32 *)((char *)arg0 + 0x80);
      *(s16 *)((char *)arg0 + 0x7A) = (s16)(gTimeModeChars[mode] - 0x30);
      *(s32 *)((char *)arg0 + 0x80) = flags & ~4;
      return;
    }
    *(s16 *)((char *)arg0 + 0x7A) = blankDigit;
    *(s32 *)((char *)arg0 + 0x80) |= 4;
  }
}
