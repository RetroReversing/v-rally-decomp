#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
/* Looks up the entry at index, then returns the handler pointer from the select state table indexed by the entry's type byte. */ extern u8 *gSelectState;
void *select_get_entry(u32 index);

void *func_8005A688(u32 index)
{
  return *(void **)(gSelectState + *((s8 *)select_get_entry(index) + 0xE) * 4 + 0xE4);
}

