#include "common.h"

extern char *D_800AFA64;
extern char *D_800C3508;
void func_8006A1FC(void)
{
  char *obj;
  char *tbl;
  s32 idx;
  obj = *((char **) (D_800AFA64 + 0x5C));
  if ((*((s32 *) (obj + 0x5C))) != 0)
  {
    tbl = D_800C3508;
    idx = *((s16 *) (tbl + 2));
    D_800AFA64 = obj;
    *((s32 *) (((*((char **) (tbl + 0x10))) - (-(idx * 20))) + 0x10)) = 100;
  }
}
