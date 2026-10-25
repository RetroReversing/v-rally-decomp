#include "common.h"

void *func_8008EBEC();
void func_8008E500(void *arg0, void *arg1, f32 arg2)
{
  void *temp_a0;
  void *temp_v0;
  s32 new_var;
  if ((*((void **) (((char *) arg1) + 8))) != NULL)
  {
    temp_v0 = func_8008EBEC(arg0, arg1);
    if (temp_v0 != NULL)
    {
      new_var = (s32) ((*((s32 *) (((char *) arg0) + 0x1C))) + (*((s32 *) (((char *) (*((void **) (((char *) arg1) + 8)))) + 0xD8))));
      *((s16 *) (((char *) temp_v0) + 8)) = 7;
      *((f32 *) (((char *) temp_v0) + 0xC)) = arg2;
      *((s32 *) (((char *) temp_v0) + 0)) = 0;
      *((s32 *) (((char *) temp_v0) + 4)) = new_var;
      temp_a0 = *((void **) (((char *) (*((void **) (((char *) arg1) + 8)))) + 0xC));
      (*((s32 (**)(void *, s32, void *)) (((char *) temp_a0) + 8)))(temp_a0, 3, temp_v0);
    }
  }
}
