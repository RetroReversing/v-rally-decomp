extern u8 gStreamState[];

/* Searches the 0x800-entry pointer table at gStreamState+0x3902 for an entry
 * whose key at +4 equals key. When found, bumps that entry's byte at +2 and
 * returns it. */
u8 func_800556C4(s32 key)
{
  u8 *entry;
  u16 i;
  u8 found;

  found = 0;
  i = 0;
  do {
    entry = *(u8 **) (gStreamState + 0x3902 + i * 4);
    if (entry != NULL) {
      if (*(s32 *) (entry + 4) == key) {
        found = 1;
      }
    }
    i++;
  } while (found == 0 && i < 0x800);
  if (found != 0) {
    entry[2] += 1;
  }
  return *(vu8 *)(entry + 2);
}
