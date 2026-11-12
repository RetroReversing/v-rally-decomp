u64 osGetTime(void);
u64 __udivdi3(u64, u64);
extern char *gTimeSampleState;

/* Timing sample: while the sample block holds fewer than four samples (count at +4, last
 * timestamp at +8, 8-byte sample slots from +0xF0), stores the time since the last one, as
 * (now << 6) / 3000 minus the last timestamp, in the next free slot and advances the count. */
void func_80013EA0(void)
{
  char *block;
  char *slot;
  u32 idx;
  u64 t;
  u64 r;
  if ((*((u32 *) (gTimeSampleState + 4))) < 4)
  {
    t = osGetTime();
    block = gTimeSampleState;
    idx = *((u32 *) (block + 4));
    *((u32 *) (block + 4)) = idx + 1;
#ifdef PORT
    slot = block + idx * 8;
#else
    slot = (char *) (idx * 8);
    slot = block + ((u32) slot);
#endif
    r = __udivdi3(t << 6, 3000);
    r = r - (*((u64 *) (block + 8)));
    *((u64 *) (slot + 0xF0)) = r;
  }
}
