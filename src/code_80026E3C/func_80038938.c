#include "common.h"

void *func_8007EAA0();
extern s32 D_8009F640;
void func_80038938(void *arg0)
{
  s32 temp_v0;
  s32 var_a0;
  void **new_var;
  void *temp_a1;
  void *temp_v1;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x1C)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x3C)))) + 0x1C)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 4)) = 1;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x3C)))) + 4)) = 1;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 8)) = 0;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x3C)))) + 8)) = 0;
  new_var = (void **) (((char *) (*((void **) (((char *) arg0) + 0x3C)))) + 0);
  D_8009F640 = 0;
  if ((*new_var) == NULL)
  {
    temp_a1 = func_8007EAA0(1, 0x48);
    var_a0 = 0;
    do
    {
      temp_v0 = var_a0 & 0xFF;
      var_a0 += 1;
      ;
      *((s32 *) (((char *) ((temp_v0 * 0xC) + temp_a1)) + 4)) = 0xFF;
      *((s8 *) (((char *) ((temp_v0 * 0xC) + temp_a1)) + 8)) = 0;
    }
    while (((u32) (var_a0 & 0xFF)) < 6U);
    *((s32 *) (((char *) temp_a1) + 0)) = 1;
    *((s32 *) (((char *) temp_a1) + 0xC)) = 7;
    *((s32 *) (((char *) temp_a1) + 0x18)) = 0x1C;
    *((s32 *) (((char *) temp_a1) + 0x24)) = 2;
    *((s32 *) (((char *) temp_a1) + 0x30)) = 6;
    *((s32 *) (((char *) temp_a1) + 0x3C)) = 0x1D;
    *((void **) (((char *) (*((void **) (((char *) arg0) + 0x3C)))) + 0)) = temp_a1;
    *((void **) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0)) = temp_a1;
  }
}
