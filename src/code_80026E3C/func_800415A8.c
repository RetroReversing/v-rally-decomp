#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct Obj
{
  u8 pad0[0x10];
  u16 flags;
  u8 pad12[0x2C4 - 0x12];
} Obj;

Obj *func_800415A8(Obj *arr, s32 n)
{
  while (n != 0)
  {
    if (!(arr->flags & 1))
    {
      arr->flags |= 1;
      return arr;
    }
    arr++;
    n--;
  }
  return 0;
}

