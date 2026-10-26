#include "common.h"

s32 func_8008BD90();
s32 func_8008BDB0();
extern void *D_800A3A34;
void osViSetMode(void *arg0)
{
  void *new_var3;
  void **new_var2;
  char *new_var;
  s32 temp_v0;
  void *temp_a1;
  temp_v0 = func_8008BD90();
  new_var = (char *) D_800A3A34;
  *((void **) (((char *) D_800A3A34) + 8)) = arg0;
  ;
  new_var2 = (void **) (((char *) D_800A3A34) + 8);
  *((s16 *) (new_var + 0)) = 1;
  new_var3 = *new_var2;
  *((s32 *) (new_var + 0xC)) = (s32) (*((s32 *) (((char *) (*new_var2)) + 4)));
  func_8008BDB0(temp_v0, new_var3);
}
