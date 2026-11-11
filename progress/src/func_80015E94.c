s32 func_8001B730();
s32 memset();
s32 copyStringAligned();

/* Looks up an entry by a 4-character key and its second word, scanning the 56-byte entries that follow the header at offset 60; returns the match or NULL. */
void *func_80015E94(void *table, void *name)
{
  s32 key_buf[3];
  s32 off;
  s32 i;
  s32 n;
  s32 test;
  s32 key;
  s32 *p;
  void *entry;
  s32 count;

  func_8001B730(name);
  memset(key_buf, 0, 12);
  copyStringAligned(key_buf, name);
  i = 0;
  count = *((u16 *) (((u8 *) table) + 32));
  p = &key_buf[1];
  if (count >= i)
  {
    key = key_buf[0];
    n = count;
    off = 60;
    do
    {
      entry = (char *) ((u8 *) table);
      entry += off;
      i++;
      if ((*((s32 *) entry)) == key)
      {
        if ((*((s32 *) (((u8 *) entry) + 4))) == (*p))
        {
          return entry;
        }
      }
      test = n < i;
      off += 56;
    }
    while (!test);
  }
  return NULL;
}
