s32 strCmp();
extern s32 gNameTable;

/* Looks up a name in gNameTable, a list of (name pointer, u8 value) pairs ended by a
 * zero name pointer. Returns the value of the first match, or 1 if the name is not found. */
u8 nameTableLookup(s32 name)
{
  s32 *entry;
  s32 entryName;

  entry = &gNameTable;
  entryName = name;
  if (*entry != 0)
  {
    do {
      if (strCmp(entryName, entry) == 0)
      {
        return *((u8 *) entry + 4);
      }
      entry += 2;

    } while (*entry != 0);
  }
  return 1;
}
