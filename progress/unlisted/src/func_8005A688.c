extern u8 *gSelectState;
void *select_get_entry(u32 index);

void *func_8005A688(u32 index)
{
  return *(void **)(gSelectState + *((s8 *)select_get_entry(index) + 0xE) * 4 + 0xE4);
}
