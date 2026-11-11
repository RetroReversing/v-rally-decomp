/* Derives two complementary 0..50 values from the s16 at +6 of the record at arg0->+0x78:
 * level = min(value / 40, 50); the record gets 50 - level at +0x14 and +0x17, and
 * 50 + level at +0x16. */
void func_80033238(void *arg0)
{
  s32 level;
  s32 value;
  s8 inverse;
  void *rec;

  rec = *((void **) (((char *) arg0) + 0x78));
  value = *((s16 *) (((char *) rec) + 6));
  level = value / 40;
  if (level >= 0x33)
  {
    level = 0x32;
  }
  inverse = 0x32 - level;
  *((s8 *) (((char *) rec) + 0x14)) = inverse;
  *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x17)) = inverse;
  *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x16)) = (s8) (level + 0x32);
}
