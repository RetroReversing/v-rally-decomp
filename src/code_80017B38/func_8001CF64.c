#include "common.h"

s32 func_8002B618();
s32 func_8008E118();
s32 func_80098370();
extern char D_800A47AC[];

void func_8001CF64(char *arg0)
{
  char *temp_s0;
  s32 temp_v0;

  temp_s0 = arg0 + 0x4C;
  temp_v0 = func_8008E118(temp_s0);
  func_80098370(temp_s0, D_800A47AC, temp_v0);
  if (*((s32 *) (arg0 + 0x44)) == 2)
  {
    func_8002B618(temp_s0, arg0 + 0x98);
  }
  else
  {
    func_8002B618(temp_s0, NULL);
  }
}
