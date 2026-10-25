#include "common.h"

void func_80033C30(void *arg0, void *arg1)
{
  s32 temp_a0;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_v0_2;
  s32 temp_v0_3;
  void *temp_v0;
  void *temp_v1;

  temp_v0 = *((void **) (((char *) arg0) + 0x54));
  temp_v1 = *((void **) (((char *) arg0) + 0x60));
  temp_a2 = *((s32 *) (((char *) temp_v1) + 0x178));
  temp_a3 = *((s32 *) (((char *) temp_v1) + 0x174));
  temp_a0 = *((s32 *) (((char *) temp_v0) + 0x10)) + *((s32 *) (((char *) temp_v0) + 0x14));
  if (temp_a0 >= 0x5DD)
  {
    temp_a3 += (temp_a3 < 0xFA);
    temp_v0_2 = *((u8 *) (((char *) arg1) + 4)) - temp_a3;
    *((u8 *) (((char *) arg1) + 4)) = (u8) (temp_v0_2 & (~temp_v0_2 >> 0x1F));
  }
  else
  {
    temp_a3 -= (temp_a3 >= 6);
  }
  if (temp_a0 < (-0x5DC))
  {
    temp_a2 += (temp_a2 < 0xFA);
    temp_v0_3 = *((u8 *) (((char *) arg1) + 5)) - temp_a2;
    *((u8 *) (((char *) arg1) + 5)) = (u8) (temp_v0_3 & (~temp_v0_3 >> 0x1F));
  }
  else
  {
    temp_a2 -= (temp_a2 >= 6);
  }
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x60)))) + 0x178)) = temp_a2;
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x60)))) + 0x174)) = temp_a3;
}
