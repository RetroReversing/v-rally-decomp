#include "common.h"

s32 func_80034FF0();
void *func_80040260();
void *func_8004240C();
void func_8003C698();
extern void *D_800C7F84;
extern char *D_800C35A0;
void func_8003C6D8(s32 arg0, s32 arg1, s32 arg2)
{
  s32 new_var;
  char *rec;
  s16 temp_a1;
  s16 temp_a2;
  s32 var_a2;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  s32 *new_var2;
  void *temp_v0;
  void *temp_v1;
  s32 temp_a0;
  u16 flags;
  var_s1 = arg0;
  var_s3 = arg1;
  rec = *((char **) (((char *) D_800C7F84) + 0x178));
  temp_a1 = *((s16 *) (rec + 0x8));
  temp_a2 = *((s16 *) (rec + 0xA));
  var_s0 = temp_a1 + (*((s16 *) (rec + 0xC)));
  var_s2 = temp_a2 + (*((s16 *) (rec + 0xE)));
  switch (*((u16 *) (D_800C35A0 + 0xE)))
  {
    case 1:
      var_s0 = (s32) func_80040260(var_s1, (s16) (var_s0 - 0x26), (s16) (var_s2 - 0x22), 3, func_8003C698, 0);
      temp_a0 = (new_var = func_80034FF0(var_s3 + 0x4C, 0));
      temp_v1 = D_800C7F84;
      *((s32 *) (((char *) var_s0) + 0xA4)) = temp_a0;
      break;

    case 2:
      temp_v0 = func_8004240C(((arg2 - 1) * 2) | 1, temp_a1, temp_a2, arg2);
      var_a2 = 0;
      flags = *((u16 *) (D_800C35A0 + 0x12));
      D_800C7F84 = temp_v0;
      if (!(flags & 1))
    {
      new_var2 = (s32 *) (((char *) temp_v0) + 0xC);
      var_s0 -= 0x10;
      var_a2 = (-((*new_var2) == 1)) & 0x14;
    }
      var_s0 = (s32) func_80040260(var_s1, (s16) ((var_s0 + 0xFFEEU) + var_a2), (s16) (var_s2 - 0x1A), 3, func_8003C698, 0);
      temp_a0 = func_80034FF0(var_s3 + 0x4C, 0);
      temp_v1 = D_800C7F84;
      *((s32 *) (((char *) var_s0) + 0xA4)) = temp_a0;
      *((s16 *) (((char *) var_s0) + 0x98)) = 0x600;
      *((s16 *) (((char *) var_s0) + 0x9A)) = 0x600;
      break;

    default:
      return;

  }

  *((void **) (((char *) var_s0) + 0xA8)) = temp_v1;
}
