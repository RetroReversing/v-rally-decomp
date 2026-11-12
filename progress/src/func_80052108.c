s32 order_table_swap(s32, s32);
s32 strncmp(s32, s32 *, s32);
extern char order_tag[];
extern s32 gOrderState;

/* Moves the entries whose name starts with order_tag (5 bytes) to the front of the order
 * table, keeping their order. Walks count entries of 0x14 bytes; the entry array pointer
 * lives at gOrderState+0x237C. */
void func_80052108(s32 count)
{
  s32 i;
  s32 matched;
  s32 offset;
  s32 slot;

  matched = 0;
  i = 0;
  slot = 0;
  if (count > slot)
  {
    offset = 0;
    do
    {
      if (strncmp((*((s32 *) (((char *) (&gOrderState)) + 0x237C))) + offset, (s32 *)order_tag, 5) == 0)
      {
        slot = matched & 0xFFFF;
        matched += 1;
        order_table_swap(i & 0xFFFF, slot);
      }
      i += 1;
      offset += 0x14;
    }
    while (i < count);
  }
}
