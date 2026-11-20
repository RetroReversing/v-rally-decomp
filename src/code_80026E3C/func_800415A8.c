#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
typedef struct Obj
{
  u8 pad0[0x10];
  u16 flags;
  u8 pad12[0x2C4 - 0x12];
} Obj;

/* Scans pool[0..count) for the first object whose flags bit 0 is clear, sets that
 * bit to reserve it and returns it. Returns NULL if every object is already reserved. */
Obj *func_800415A8(Obj *pool, s32 count)
{
  while (count != 0)
  {
    if (!(pool->flags & 1))
    {
      pool->flags |= 1;
      return pool;
    }
    pool++;
    count--;
  }
  return 0;
}

