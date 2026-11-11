void func_800308B8(void *);
void func_8004F27C(void *);
void heapFreeBlock(s32);
typedef struct { u8 pad[0x74]; s32 heapBlock; u8 pad78[0x94 - 0x78]; } Item18900;
typedef struct { Item18900 *items; u16 count; } List18900;

/* Releases every item in the list at owner->+0x44: frees each item's heap block, then runs
 * the two per-item cleanup functions. */
void func_80018900(void *owner)
{
  List18900 *list = (List18900 *)(*(char **)((char *)owner + 8) + 0x44);
  s32 i;
  Item18900 *items;
  if (list->count != 0)
  {
    items = list->items;
    for (i = 0; i < list->count; i++)
    {
      heapFreeBlock(items[i].heapBlock);
      func_8004F27C(&items[i]);
      func_800308B8(&items[i]);
    }
  }
}
