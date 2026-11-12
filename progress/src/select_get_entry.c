extern u8 *gSelectState;
void *list_advance(u32,void *);
/* Returns the index-th entry of the select list stored at gSelectState+12. */ void *select_get_entry(u32 index) {
  return list_advance(index, *(void **)(gSelectState+12)); }
