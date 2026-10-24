#include "common.h"

extern int D_800C337C;
extern int D_800C3388;
extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_80081C00(void)
{
  char *new_var;
  new_var = D_800AE850;
  *((s32 *) (((char *) (*((void **) (new_var + 0x8AE4)))) + 4)) = (s32) D_800C337C;
  *((s32 *) (((char *) (*((void **) (D_800AE850 + 0x8AE4)))) + 0)) = (s32) D_800C3388;
  return 1;
}
