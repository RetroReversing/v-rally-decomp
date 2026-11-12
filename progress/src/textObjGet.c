extern u8 *gSelectState;
void *list_advance(u32,void *);
/* Returns the index-th node of the list whose head is stored at the start of gSelectState. */ void *textObjGet(u32 index) { return list_advance(index, *(void **)gSelectState); }
