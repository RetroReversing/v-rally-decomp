extern u8 *gSelectState;
void *list_advance(u32,void *);
void *select_get_entry(u32 index) {
  return list_advance(index, *(void **)(gSelectState+12)); }
