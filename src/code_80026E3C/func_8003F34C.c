#include "common.h"

void func_8003F34C(void *arg0)
{
  char *p;
  void *v1;
  char *tbl;
  s32 idx;

  p = *(char **)((char *)arg0 + 0xA8);
  v1 = *(void **)(p + 0x24);
  if (v1 != NULL)
  {
    *(s32 *)((char *)arg0 + 0x80) |= 4;
    if (*(s32 *)((char *)v1 + 0x14) & 0x100)
    {
      *(s16 *)((char *)arg0 + 0x7A) = 6;
      *(s32 *)((char *)arg0 + 0x80) &= ~4;
    }
    tbl = *(char **)(*(char **)((char *)arg0 + 0xA4) + 4);
    idx = *(s16 *)((char *)arg0 + 0x7A);
    *(s16 *)((char *)arg0 + 0x70) = -(*(u16 *)(*(char **)(tbl + idx * 4) + 6) >> 1);
  }
}
