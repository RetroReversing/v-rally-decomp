#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
void func_800308B8(void *);
void func_8004F27C(void *);
void func_8007EE9C(s32);
typedef struct { u8 pad[0x74]; s32 unk74; u8 pad78[0x94 - 0x78]; } Item18900;
typedef struct { Item18900 *items; u16 count; } List18900;
void func_80018900(void *arg0)
{
  List18900 *l = (List18900 *)(*(char **)((char *)arg0 + 8) + 0x44);
  s32 i;
  Item18900 *items;
  if (l->count != 0)
  {
    items = l->items;
    for (i = 0; i < l->count; i++)
    {
      func_8007EE9C(items[i].unk74);
      func_8004F27C(&items[i]);
      func_800308B8(&items[i]);
    }
  }
}

