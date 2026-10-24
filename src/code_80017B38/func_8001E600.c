#include "common.h"

extern char D_800C02AE[];
void func_8001E600(void *arg0)
{
  int new_var;
  new_var = 0x5DCE;
  *((s8 *) (((char *) (*((void **) (D_800C02AE + new_var)))) + 0x2E)) = 1;
  *((s8 *) (((char *) (*((void **) (D_800C02AE + new_var)))) + 0x2F)) = (s8) (((s32) (*((s32 *) (((char *) arg0) + 0x90)))) / 2);
}
