#include "common.h"

extern s32 D_800AFA54;
extern u32 D_800AB974;
extern u8 D_800AB973;
extern char D_800A73E0[];
extern char D_800AE850[];
void func_800899DC(void *arg0, s32 arg1)
{
  s32 found;
  u32 i;
  int idx;
  void **slot;
  u32 next;
  s32 more;
  s32 keep;
  D_800AFA54 = arg1;
  if (D_800AB974 < 3U)
  {
    found = 0;
    idx = D_800AB973;
    i = 1;
    do
    {
      slot = ((void **) (D_800A73E0 + 0x4598)) + (idx & 0xFF);
      i += 1;
      if ((*slot) == NULL)
      {
        found = 1;
        arg1 = D_800AB974;
        *slot = arg0;
        D_800AB974 = arg1 + 1;
        *((s8 *) (((char *) arg0) + 8)) = 0;
      }
      next = idx + 1;
      idx = next & (-((next & 0xFF) < 4U));
      keep = found ^ 1;
      more = (i & 0xFF) < 4U;
    }
    while ((keep & more) != 0);
  }
}
