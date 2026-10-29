#include "snapshot29_0433f7af8f6d.h"

void *func_8002255C(s32 *, s32);
s32 func_8004240C(s32);
void *func_800801D0(s32, s32);
s32 func_80080440();
extern s32 D_800A0130;
extern s32 D_800C02AE;
void *func_80041FF4(s32 arg0, s32 arg1)
{
  s32 temp_v0;
  char *new_var;
  void *temp_s0;
  int new_var2;
  void *temp_s1;
  temp_v0 = func_8004240C(arg0 & 0xFF);
  new_var = (char *) (&D_800C02AE);
  *((s32 *) (new_var + 0x7CD6)) = temp_v0;
  new_var2 = temp_v0 + 0x28;
  temp_s1 = func_8002255C(&D_800A0130, arg1);
  temp_s0 = func_800801D0(new_var2, 0x1C);
  *((s32 *) (((char *) temp_s0) + 0x10)) = func_80080440();
  *((s32 *) (((char *) temp_s0) + 0x14)) = (s32) (*((s32 *) (((char *) temp_s1) + 0xC)));
  *((s32 *) (((char *) temp_s0) + 0x18)) = (s32) (*((s32 *) (((char *) temp_s1) + 0x10)));
  *((void **) (((char *) temp_s0) + 0xC)) = temp_s1;
  return temp_s0;
}
