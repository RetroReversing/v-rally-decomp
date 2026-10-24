#include "common.h"

void *func_80006008();
s32 func_80006014();
s32 func_80006298();
s32 func_800068C0();
s32 func_80006CF8();
s32 func_80007404();
extern char D_800A1798[];
void func_80073320(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  s16 temp_s0;
  s16 temp_s0_2;
  s16 temp_s1;
  s16 temp_s1_2;
  s32 temp_s3;
  void *temp_v0;
  temp_v0 = func_80006008();
  *((s32 *) (((char *) temp_v0) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v0) + 4)) = &D_800A1798;
  func_80006014(arg0, temp_v0 + 8);
  temp_s0 = arg1 - 0x14;
  temp_s3 = func_80006CF8(arg0, 0) & 0xFFFF;
  temp_s1 = arg2 - 3;
  temp_s0_2 = (temp_s0 + arg3) + 0x14;
  temp_s1_2 = temp_s1 + arg4;
  func_800068C0(arg0, temp_s3, temp_s0, temp_s1, -4, (s32) temp_s0, (s32) temp_s1_2, -4, (s32) temp_s0_2, (s32) temp_s1_2, -4, (s32) temp_s0_2, (s32) temp_s1, -4);
  func_80007404(arg0, temp_s3, 0x1E, 0x32, 0x94, 0, 0x1E, 0x32, 0x94, 0, 0x1E, 0x32, 0x94, 0xC8, 0x1E, 0x32, 0x94, 0xC8);
  func_80006298(arg0);
}
