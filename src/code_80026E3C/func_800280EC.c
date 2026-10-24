#include "common.h"

s32 func_80027CDC();
s32 func_80027CFC();
s32 func_800502D4();
extern s32 D_800A1238;
void func_800280EC(void **arg0, s32 arg1)
{
  char *new_var;
  new_var = ((char *) (D_800A1238 + ((*((u8 *) (((char *) (*((void **) (((char *) (*arg0)) + 0x48)))) + 3))) * 0x44))) + 8;
  if ((*((u16 *) new_var)) & 0x10)
  {
    func_80027CDC(func_800502D4(D_800A1238), arg1);
    func_80027CFC(arg1);
  }
}
