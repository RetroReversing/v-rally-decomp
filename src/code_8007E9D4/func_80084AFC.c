#include "common.h"

s32 func_8007F4E4();
s32 func_8007F634();
s32 func_8007F6E0();
extern void *D_800A1B70;
void func_80084AFC(void)
{
  s32 temp_a0;
  s32 temp_s0;
  int temp_a1;
  temp_s0 = func_8007F4E4(4, 0, 8);
  temp_a0 = temp_s0;
  temp_a1 = (*((u8 *) (((char *) D_800A1B70) + 0x39C))) & 0xFE;
  *((u8 *) (((char *) D_800A1B70) + 0x39C)) = temp_a1;
  func_8007F6E0(temp_a0, temp_a1);
  func_8007F634(temp_s0);
}
