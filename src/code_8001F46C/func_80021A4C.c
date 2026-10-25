#include "common.h"

extern int D_800C35A0;
extern char D_800C02AE[];
void func_80021A4C(void *arg0)
{
  s32 temp_a1;
  int new_var;
  void *temp_v1;
  temp_a1 = *(*((s32 **) (((char *) arg0) + 0x48)));
  ;
  if (temp_a1 < 4)
  {
    new_var = (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x88)))) + 0x84))) / 9000;
    temp_v1 = D_800C35A0 + ((*((u8 *) (((char *) (D_800C35A0 + temp_a1)) + 0x32))) * 0x28);
    *((u16 *) (((char *) temp_v1) + 0x52)) += new_var;
  }
}
