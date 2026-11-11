/* Turns the stat value at +4 of the sub-record at owner+0x78 into a level (value / 40, capped
 * at 50) and writes it as two bars: 50 + level into +0x14 and +0x17, and 50 - level into +0x15. */
void statBarsUpdate(void *owner)
{
  char *rec;
  s32 value;
  s32 level;
  s8 bar;

  rec = *((char **) ((char *) owner + 0x78));
  value = *((s16 *) (rec + 4));
  level = value / 40;
  if (level >= 0x33)
  {
    level = 0x32;
  }
  bar = level + 0x32;
  *((s8 *) (rec + 0x14)) = bar;
  *((s8 *) (*((char **) ((char *) owner + 0x78)) + 0x17)) = bar;
  *((s8 *) (*((char **) ((char *) owner + 0x78)) + 0x15)) = (s8) (0x32 - level);
}
