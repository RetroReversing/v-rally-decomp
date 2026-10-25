#include "common.h"

extern int D_800B5B40;
extern char D_800AE850[];
extern char D_800C02AE[];
void *func_8008081C(u8 *arg0, u32 arg1)
{
  u32 size;
  u8 *node;
  u8 *newn;
  u8 *next;
  int new_var;
  u32 span;
  size = (arg1 + 3) & (~3);
  node = arg0 - 0x14;
  new_var = size == 0;
  if (new_var)
  {
    (*((s32 (**)(s32, u32)) (((char *) (&D_800C02AE)) + 0x7DE2)))(D_800B5B40 - 4, size);
    for (;;)
    {
    }

  }
  if (node[0xB] != 0)
  {
    for (;;)
    {
    }

  }
  span = (*((u32 *) node)) - 0x14;
  if ((span - ((u32) node)) < size)
  {
    for (;;)
    {
    }

  }
  next = *((u8 **) node);
  newn = node + (size + 0x14);
  if (next[0xA] == 0)
  {
    next = *((u8 **) next);
  }
  *((u8 **) (next + 4)) = newn;
  *((u8 **) (newn + 0)) = next;
  *((u8 **) (newn + 4)) = node;
  newn[8] = 0;
  newn[9] = 0;
  newn[0xA] = 0;
  newn[0xB] = 0;
  *((s32 *) (newn + 0x10)) = 0;
  *((u8 **) (node + 0)) = newn;
  node[0xA] = 1;
  return node + 0x14;
}
