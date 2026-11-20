#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
extern u8 *gSelectState;
void *list_advance(u32,void *);
/* Returns the index-th entry of the select list stored at gSelectState+12. */ void *func_800592AC(u32 index) {
  return list_advance(index, *(void **)(gSelectState+12)); }

