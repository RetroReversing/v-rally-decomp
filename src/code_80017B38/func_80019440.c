#include "common.h"

extern f32 D_8009CEC0[];
void func_800562D0(void *, void *, s32, void *, s32);
void func_8005639C(s32, void *);
void func_80019440(u8 *arg0, void *arg1, s16 *arg2, s32 *arg3, s32 arg4)
{
  void *new_var;
  s32 i;
  s16 *dst;
  if ((*((s16 *) (arg0 + 0x8))) != (-1))
  {
    if ((*((u16 *) ((*((u8 **) (arg0 + 0x18))) + 0x10))) != 0)
    {
      new_var = *((void **) ((*((u8 **) (arg0 + 0x18))) + 0x14));
      func_800562D0(arg1, new_var, *arg3, *((void **) (arg0 + 0x14)), *((u16 *) (arg0 + 0x1C)));
      func_8005639C(arg4, arg0);
      for (i = 0; i < (*((s16 *) (arg0 + 0xA))); i++)
      {
        dst = arg2 + (((*arg3) + i) * 3);
        dst[0] = (s16) (((f32) (*((s16 *) ((*((u8 **) ((*((u8 **) (arg0 + 0x18))) + 0xC))) + (i * 4))))) * D_8009CEC0[0]);
        dst[2] = (s16) (((f32) (*((s16 *) (((*((u8 **) ((*((u8 **) (arg0 + 0x18))) + 0xC))) + (i * 4)) + 2)))) * D_8009CEC0[2]);
        dst[1] = (s16) (((f32) (*((s16 *) ((*((u8 **) (arg0 + 0x10))) + (i * 2))))) * D_8009CEC0[1]);
      }

      *arg3 += *((s16 *) (arg0 + 0xA));
    }
  }
}
