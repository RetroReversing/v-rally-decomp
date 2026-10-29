#include "snapshot29_0433f7af8f6d.h"

extern void func_8002FFA4(void *, s32, s32, s32);
void func_800316C4(void *arg0)
{
  s32 temp_a1_2;
  s32 temp_s0;
  s32 temp_s5;
  s32 var_s3;
  char *new_var;
  u8 b14;
  u8 b17;
  s32 var_s4;
  s32 var_s1;
  void *temp_v0;

  temp_v0 = *((void **) (((char *) arg0) + 0x78));
  temp_a1_2 = *((u16 *) (((char *) arg0) + 0x88));
  b14 = *((u8 *) (((char *) temp_v0) + 0x14));
  b17 = *((u8 *) (((char *) temp_v0) + 0x17));
  temp_s5 = ((s32) (b17 - b14)) / ((s32) (temp_a1_2 - 1));
  var_s1 = b14;
  var_s4 = var_s1;
  var_s3 = 0;
  if (temp_a1_2 == 0)
  {
    goto block_3;
  }
  var_s4 = (var_s1 << 2) + var_s1;
  loop_2:
  temp_a1_2 = var_s3 & 0xFFFF;
  func_8002FFA4(arg0, temp_a1_2, (s16) var_s1, ((*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x1C))) + (temp_a1_2 * 0xC)) + 6);
  var_s3 += 1;
  new_var = ((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x1C;
  *((s16 *) (((char *) ((temp_a1_2 * 0xC) + (*((s32 *) new_var)))) + 4)) = (s16) (var_s4 * 2);
  var_s4 += (temp_s5 << 2) + temp_s5;
  if (((u32) (var_s3 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) arg0) + 0x88)))))
  {
    var_s1 += temp_s5;
    goto loop_2;
  }
  block_3:
  return;
}
