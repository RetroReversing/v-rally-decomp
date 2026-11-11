extern s32 gVoiceCount;
extern char *gVoices;

/* Sets the two parameter words of every idle voice (play flag at +0x86 clear). */
void voicesSetIdleParams(s32 value)
{
  char pad[8];
  s32 i;
  s32 count;
  s32 saved;
  s32 unused = 0;
  s32 orig;
  char *voice;
  (void) pad;
  value &= 0xFFFF;
  unused = value;
  saved = unused;
  if (value == 0)
  {
    value = 1;
  }

  count = gVoiceCount;
  voice = gVoices;
  i = 0;

  if (count > 0)
  {
    orig = unused;
    saved = count;
    voice += 0x18;
    do
    {
      if (*((u16 *)(voice + 0x86)) == 0)
      {
        *((s32 *)(voice - 0xC)) = orig;
        *((s32 *)voice) = value;
      }
      i++;
      voice += 0x134;
    }
    while (i < saved);
  }
}
