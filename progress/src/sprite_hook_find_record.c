extern char *gCarList;
extern u8 *gRecords;

/* Clears bit 2 of the flags at obj+0x80, then walks the gCarList linked list (next at +4,
   record pointer at +0x6C). The first entry whose record has key (obj's u16 at +0x78) at +8
   and zero at +0x20 gives the index i. Stores the 16-bit value at gRecords[i + 0x32] * 40 + 0x4E
   into obj+0x7A. Does nothing when no entry matches. */
void sprite_hook_find_record(void *obj)
{
  u8 *node;
  u8 *rec;
  u8 *base;
  u8 *p;
  s32 i;
  s32 key;
  s32 mask;
  s32 new_var;
  i = 0;
  node = *((u8 **) gCarList);
  if (node != NULL)
  {
    mask = ~4;
    key = *((u16 *) (((char *) obj) + 0x78));
    base = gRecords;
    do
    {
      *((s32 *) (((char *) obj) + 0x80)) &= mask;
      rec = *((u8 **) (node + 0x6C));
      new_var = key;
      if ((new_var == (*((s32 *) (rec + 8)))) && ((*((s32 *) (rec + 0x20))) == 0))
      {
        p = (base + ((u8) i)) + 0x32;
        *((s16 *) (((char *) obj) + 0x7A)) = *((u16 *) ((base - (-((*p) * 40))) + 0x4E));
        return;
      }
      node = *((u8 **) (node + 4));
      i++;
    }
    while (node != NULL);
  }
}
