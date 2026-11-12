/* Looks up the entry at index, then returns the handler pointer from the select state table indexed by the entry's type byte. */ extern u8 *gSelectState;
void *select_get_entry(u32 index);

void *select_get_entry_handler(u32 index)
{
  return *(void **)(gSelectState + *((s8 *)select_get_entry(index) + 0xE) * 4 + 0xE4);
}
