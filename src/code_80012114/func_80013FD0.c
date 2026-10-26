#include "common.h"

extern s32 D_800B727C;
extern void *D_800B681C;
extern void *D_800C7304;
extern char D_800B5C80[];
extern s32 (*D_8009BB24)();
u64 osGetTime();
u64 func_8009A2B0();
static inline int inline_fn(s32 arg0)
{
  return (arg0 + 1) & 3;
}

void func_80013FD0(void)
{
  char *base;
  s32 idx;
  void *slot;
  void *next;
  void *cur;
  u64 ret;
  D_8009BB24();
  base = D_800B5C80;
  idx = D_800B727C;
  slot = base + (idx * 0x118);
  idx = inline_fn(idx);
  D_800B681C = slot;
  next = base + (idx * 0x118);
  D_800B727C = idx;
  D_800C7304 = next;
  ((s32 *) next)[1] = 0;
  ((s32 *) next)[0] = 0;
  do
  {
    ret = osGetTime(base);
  }
  while (0);
  cur = D_800C7304;
  *((u64 *) (((char *) cur) + 8)) = func_8009A2B0(ret << 6, (u64) 0xBB8);
}
