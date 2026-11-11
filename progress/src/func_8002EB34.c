extern char gStreamState[];
/* Takes the next free 0x24-byte entry from the pool at pool->entries (wrapping at pool->capacity), marks it active, copies the source record into it, and fills it from the lookup table at pool+0x1C[kind]. Kinds 0 and 1 are remapped to 6 and 5 when the global mode word at +4 is 3. Returns the entry. */
void *func_8002EB34(void *pool, u8 kind, void *src)
{
  char *pool_p;
  s32 entry_base;
  u16 cur;
  u16 next;
  char *entry;
  char *lookup;
  u32 off;
  pool_p = pool;
  if ((kind == 1) && ((*((u16 *) ((*((char **) (gStreamState + 0x7E6E))) + 4))) == 3))
  {
    kind = 5;
  }
  if ((kind == 0) && ((*((u16 *) ((*((char **) (gStreamState + 0x7E6E))) + 4))) == 3))
  {
    kind = 6;
  }
  cur = *((u16 *) (pool_p + 0x1A));
  entry = *((char **) (pool_p + 0x10));
  entry = entry + (cur * 0x24);
  next = cur + 1;
  *((u16 *) (pool_p + 0x1A)) = next;
  if (next != *((u16 *) (pool_p + 0x16)))
  {
  }
  else
  {
    *((u16 *) (pool_p + 0x1A)) = 0;
  }
  off = kind * 4;
  lookup = (char *) (off + (s32) pool_p);
  entry_base = *((s32 *) (lookup + 0x1C));
  *((s16 *) (entry + 0)) = 1;
  *((s16 *) (entry + 0x12)) = 0;
  *((s32 *) (entry + 0x20)) = entry_base;
  *((u16 *) (entry + 0xA)) = *((u16 *) (((char *) src) + 0));
  *((u16 *) (entry + 0xC)) = *((u16 *) (((char *) src) + 2));
  *((u16 *) (entry + 0xE)) = *((u16 *) (((char *) src) + 4));
  *((u16 *) (entry + 0x10)) = *((u16 *) ((*((char **) (lookup + 0x38))) + 0));
  *((u16 *) (entry + 0x16)) = *((u16 *) ((*((char **) (lookup + 0x38))) + 2));
  *((u8 *) (entry + 0x14)) = *((u8 *) ((*((char **) (lookup + 0x38))) + 4));
  *((u8 *) (entry + 0x15)) = *((u8 *) ((*((char **) (lookup + 0x38))) + 5));
  *((u8 *) (entry + 0x1E)) = *((u8 *) ((*((char **) (lookup + 0x38))) + 6));
  *((u16 *) (entry + 0x18)) = *((u16 *) ((*((char **) (lookup + 0x38))) + 8));
  *((u16 *) (entry + 0x1A)) = *((u16 *) ((*((char **) (lookup + 0x38))) + 0xA));
  *((u16 *) (entry + 0x1C)) = *((u16 *) ((*((char **) (lookup + 0x38))) + 0xC));
  *((u8 *) (entry + 0x1F)) = kind;
  *((u16 *) (entry + 2)) = *((u16 *) (entry + 0x16));
  return entry;
}
