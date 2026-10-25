#include "common.h"

void *func_8007EAA0();
extern void *D_800A14D0;
extern f64 D_800A5550;
void func_800616D8(void *arg0)
{
  void *temp_v0;
  s32 new_var;
  f64 temp_f2;
  temp_v0 = func_8007EAA0(1, 0xC);
  temp_f2 = D_800A5550;
  *((s16 *) (((char *) temp_v0) + 0)) = (s16) (*((s32 *) (((char *) arg0) + 0x90)));
  *((s16 *) (((char *) temp_v0) + 2)) = (s16) (*((s32 *) (((char *) arg0) + 0xDC)));
  *((f32 *) (((char *) temp_v0) + 4)) = (f32) (((f64) (*((s32 *) (((char *) arg0) + 0x128)))) * temp_f2);
  new_var = *((s32 *) (((char *) arg0) + 0x174));
  D_800A14D0 = temp_v0;
  *((s8 *) (((char *) temp_v0) + 8)) = (s8) new_var;
}
