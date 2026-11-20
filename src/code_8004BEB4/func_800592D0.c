#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
extern u8 *gSelectState;
void *list_advance(u32,void *);
/* Returns the index-th node of the list whose head is stored at the start of gSelectState. */ void *func_800592D0(u32 index) { return list_advance(index, *(void **)gSelectState); }

