#include "common.h"

extern char D_80000308[];
extern char D_800A6EA0[];
extern char D_800A6EA4[];
s32 func_800914E0(void *, void *, s32);
s32 func_8008CFF0(s32 arg0, s32 *arg1)
{
  s32 *var_s0;
  s32 var_s1;
  var_s1 = arg0;
  var_s0 = arg1;
  if (var_s0 == NULL)
  {
    func_800914E0(D_800A6EA0, D_800A6EA4, 0x3D);
  }
  while ((*((vu32 *) 0xA4600010)) & 3)
  {
  }

  *var_s0 = *((s32 *) (((*((u32 *) D_80000308)) | var_s1) | 0xA0000000));
 do { } while (0);
  return 0;
}
