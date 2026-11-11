#define func_800898D0 ((s32 (*)(u8 *, s32, s32, s32, s32))func_800898D0)
extern s32 *gDmaThreadStack;
extern u8 *gVoices;
extern s32 gVoiceCount;

/* Picks a voice in the gVoices pool (0x134-byte entries, active flag at +0, voice id at +0x9E, age at +0x44)
 * for sound `id`. If `steal` is set, a voice already playing `id` is reused first. Otherwise a free voice is
 * used, or else the oldest one whose priority is below `priority`. Starts the sound on the chosen voice. */
s32 func_80086C00(s32 id, s32 param1, s32 param2, s32 steal, s32 priority)
{
  s32 best;
  s32 new_var;
  s32 min;
  s32 i;
  s32 limit;
  u8 *nameField;
  s32 spare[4];
  u8 *p;
  u8 *selected;
  u8 *unusedPtr1;
  u8 *unusedPtr2;
  s32 val;
  s32 count;
  best = priority;
  if (best == (-1))
  {
    best = gDmaThreadStack[id];
  }
  min = best + 1;
  if (steal)
  {
    count = gVoiceCount;
    p = gVoices;
    i = 0;
    nameField = p + 0x9e;
    if (count > 0)
    {
      limit = count;
      do
      {
        min = *((u16 *) (p + 0x9e));
        if ((u16)min == id)
        {
          goto found;
        }
        i++;
        p += 0x134;
      }
      while (i < limit);
      min = best + 1;
    }
  }
  count = gVoiceCount;
  p = gVoices;
  i = 0;
  if (count > 0)
  {
    limit = count;
    new_var = limit;
    do
    {
      count = *((s32 *) p);
      if (!count)
      {
        goto found;
      }
      if ((*((u16 *) (p + 0x9e))) != 0)
      {
        val = *((s32 *) (p + 0x44));
        if (val < min)
        {
          min = val;
          selected = p;
        }
      }
      i++;
      p += 0x134;
    }
    while (i < new_var);
  }
  if (min >= best)
  {
    do { return 0; found: return func_800898D0(p, id, param1, param2, best); } while (0);
  }
  return func_800898D0(selected, id, param1, param2, best);
  unusedPtr2 = p;
}
