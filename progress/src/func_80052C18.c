extern s32 gOrderState;
extern char *D_800D0648;
extern u16 D_800D0628;

/* For each of the D_800D0628 records of 0x2C4 bytes starting at D_800D0648, stores 1 in
 * gOrderState's flag table (at +0x7DB0, entry 8+i) when record flag 0x2 is set, else 0. */
void func_80052C18(void)
{
  volatile char pad[8];
  u32 i;
  u16 bit;
  char **pp;
  char *rec;
  s16 *flags;
  u16 *count;

  pp = &D_800D0648;
  rec = *pp;
  i = 0;
  if (D_800D0628 != 0)
  {
    bit = 1;
    do { count = (u16 *) (((char *) pp) - 0x20); } while (0);
    flags = (s16 *) (((char *) (&gOrderState)) + 0x7DB0);
    do
    {
      flags[i + 8] = 0;
      if ((*((u16 *) (rec + 0x10))) & 2)
      {
        flags[i + 8] = bit;
      }
      rec += 0x2C4;
      i++;
    }
    while (i < (*count));
  }
}
