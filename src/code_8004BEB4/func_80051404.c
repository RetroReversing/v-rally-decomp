#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
void *func_80051404(char *arg0)
{
  char *new_var;
  void *temp_v1;
  char *temp_a0;
  u8 temp_a1;
  u16 temp_v0;
  u8 temp_a2;
  u8 i;
  temp_a1 = arg0[0x114];
  new_var = *((char **) (D_800C02AE + 0x32F2));
  temp_a0 = arg0 + (temp_a1 * 0x44);
  temp_v0 = *((u16 *) (temp_a0 + 8));
  temp_v1 = *((void **) (*((void **) (D_800AE850 + 0x73F0))));
  temp_a0 = new_var;
  temp_v0 = temp_v0 >> 4;
  temp_a2 = temp_a0[0x1B];
  if (temp_v0 & 1)
  {
    temp_v1 = *((void **) (((char *) temp_v1) + 4));
  }
  i = 0;
  if (temp_a1 != 0)
  {
    temp_a2 = temp_a2;
    do
    {
      temp_v1 = *((void **) (((char *) temp_v1) + 4));
      if (temp_a2 != 0)
      {
        temp_v1 = *((void **) (((char *) temp_v1) + 4));
      }
      i++;
    }
    while (i < temp_a1);
  }
  return temp_v1;
}
