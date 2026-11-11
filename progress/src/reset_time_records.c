extern u8 gStreamState[];

/* Fills the record table at gStreamState+0x6E76 with the "no record" sentinel
 * (0xFF bytes / 0xFFFF halfwords), except for three zeroed bytes. */
void reset_time_records(void)
{
  u8 *base;
  u8 i;

  base = gStreamState + 0x6E76;
  i = 0;
  do {
    *(u8 *)((s32)base + i + 1) = 0xFF;
    i++;
  } while (i < 0xE1);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0xE2) = 0xFFFF;
    i++;
  } while (i < 0xC);
  i = 0;
  do {
    *(u8 *)((s32)base + i + 0xFA) = 0xFF;
    i++;
  } while (i < 0x51);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x14E) = 0xFFFF;
    i++;
  } while (i < 6);
  i = 0;
  do {
    *(u8 *)((s32)base + i + 0x14B) = 0;
    i++;
  } while (i < 3);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x15A) = 0xFFFF;
    i++;
  } while (i < 0x24);
  i = 0;
  do {
    *(u16 *)(base + i * 2 + 0x1A2) = 0xFFFF;
    i++;
  } while (i < 3);
}
